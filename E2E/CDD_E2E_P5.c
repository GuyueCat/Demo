#include "CDD_E2E_P5.h"
#include "Crc.h"
#include "type.h"
#include "stdio.h"


Std_ReturnType E2E_P05ProtectInit(void)
{
	Std_ReturnType ret = E2E_E_OK;
	SRR_DataRcvFlg_E2E.flag = 0;
	SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Init;
	return ret;
}

FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(Crc_DataRefType Crc_DataPtr,uint32 Crc_Length,uint16 Crc_StartValue16,boolean Crc_IsFirstCall)
{
  uint16 Crc_Value;
  /* Set initial value depending on whether it's the first call or a subsequent call */
  if (Crc_IsFirstCall == TRUE)
  {
    Crc_Value = CRC_INITIAL_VALUE16;
  }
  else
  {
    Crc_Value = Crc_StartValue16;
  }
  Crc_Value = Crc_CalculateCRC16Runtime(Crc_Length, Crc_DataPtr, Crc_Value);                                           
  return Crc_Value;
}


uint16 E2E_P05ComputeCRC(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, SRR_Frame_Type FrameType, uint32 Length,uint16 StartValue)
{  
	uint16 crc;
	if(FrameType==SRR_Frame_Header)
	{
		crc = Crc_CalculateCRC16(DataPtr,Length,0xFFFFU,TRUE);
	}
	else
	{
		crc = Crc_CalculateCRC16(DataPtr,Length,StartValue,FALSE);
	}
	return crc;
}


CRC_LOCAL FUNC(uint16, CRC_PRIVATE_CODE) Crc_CalculateCRC16Runtime(uint32 Crc_Length,Crc_DataRefType Crc_DataPtr,uint16 Crc_Value)
{
  uint32 Crc_DataPtrAddr;
  uint16 Crc_CalcValue;
  uint8 Crc_LoopCounter;
  Crc_CalcValue = Crc_Value;

  /* Perform CRC calculation for each byte in Crc_DataPtr */
  for (Crc_DataPtrAddr = 0; Crc_DataPtrAddr < Crc_Length; Crc_DataPtrAddr++)
  {
    /* XOR next byte of Crc_DataPtr with current CRC value. This is equivalent to calculating CRC value of 
       concatenated bytes */
    Crc_CalcValue ^= ((uint16)Crc_DataPtr[Crc_DataPtrAddr] << 8u);

    /* Perform modulo-2 division, a bit at a time */
    for (Crc_LoopCounter = 0u; Crc_LoopCounter < 8u; Crc_LoopCounter++)
    {
      /* If MSB is 1, CRC value is XORed with polynomial */
      if ((Crc_CalcValue & (uint16)0x8000u) > 0u)
      {
        Crc_CalcValue = ( (uint16)(Crc_CalcValue << 1u) ) ^ CRC_POLYNOMIAL_16;
      }
      else
      {
        Crc_CalcValue <<= 1u;
      }
    }
  }
  return Crc_CalcValue;
}


Std_ReturnType E2E_P05ProtectCheck_Header(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint32 Length, SRR_Frame_Type FrameType)
{ 
	Std_ReturnType ret = E2E_E_OK;
	SRR_DataRcvFlg_E2E.flag=0;
	SRR_DataRcvFlg_E2E.B.HeaderRcvFlg = 1u;
	SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Pending;
	SRR_DataRcvFlg_E2E.B.Crc = (uint16)E2E_P05ComputeCRC(DataPtr, SRR_Frame_Header, Length,0xFFFFU);
    printf("E2E_P05ProtectCheck_Header:%x\n\n",SRR_DataRcvFlg_E2E.B.Crc);
	return ret;
}


Std_ReturnType E2E_P05ProtectCheck_Data(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint32 Length, SRR_Frame_Type FrameType, uint8 Data_Multiplexor)
{
	Std_ReturnType ret = E2E_E_OK;
	if(SRR_Data_CheckSts_E2E == SRR_Data_CheckSts_Pending)
	{
		if(SRR_DataRcvFlg_E2E.B.HeaderRcvFlg != 1u)
		{
			SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
		}
		else
		{
			if((SRR_DataRcvFlg_E2E.B.DataRcvCnt!= 0u)&&(Data_Multiplexor!=(SRR_DataRcvFlg_E2E.B.DataRcvCnt+1u)))
			{
				SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
			}
			else
			{
				SRR_DataRcvFlg_E2E.B.Crc = (uint16)E2E_P05ComputeCRC(DataPtr, SRR_Frame_Data, Length,SRR_DataRcvFlg_E2E.B.Crc);
				SRR_DataRcvFlg_E2E.B.DataRcvCnt = Data_Multiplexor;
				printf("E2E_P05ProtectCheck_Data[%d]:%x\n\n",Data_Multiplexor,SRR_DataRcvFlg_E2E.B.Crc);
			}
		}
	}
	return ret;
}

Std_ReturnType E2E_P05ProtectCheck_Trailer(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint32 Length, SRR_Frame_Type FrameType)
{
	static Std_ReturnType ret = E2E_E_OK;
	uint16 RcvCrc = DataPtr[3]<<8u|DataPtr[2];
	static uint8 RRR_State_Counter=0;
	static boolean RRR_State_IsFirstRcv=TRUE;
	printf("E2E_P05ProtectCheck_Trailer:%x ?= RcvCrc:%x\n",SRR_DataRcvFlg_E2E.B.Crc,RcvCrc);
	SRR_DataRcvFlg_E2E.B.TrailerRcvFlg=1;
	if(SRR_Data_CheckSts_E2E == SRR_Data_CheckSts_Pending)
	{
		if(SRR_DataRcvFlg_E2E.B.HeaderRcvFlg != 1u)
		{
			SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
			printf("SRR_Data_CheckSts_Failed\n");
		}
		else
		{
			if((SRR_DataRcvFlg_E2E.B.Crc!=RcvCrc))
			{
				SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
				ret = E2E_P05STATUS_ERROR;
				printf("E2E_P05STATUS_ERROR\n");
			}
			else
			{
				if(RRR_State_IsFirstRcv!=TRUE)//RRR_State_Counter-DataPtr[0])
				{
					if((RRR_State_Counter>DataPtr[0])&&(RRR_State_Counter!=0xFFU))
					{
						SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
						ret = E2E_P05STATUS_WRONGSEQUENCE;
						printf("E2E_P05STATUS_WRONGSEQUENCE\n");
					}
					else if(RRR_State_Counter==DataPtr[0])
					{
						SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
						ret = E2E_P05STATUS_REPEATED;
						printf("E2E_P05STATUS_REPEATED\n");
					}
					else if((RRR_State_Counter+1)!=DataPtr[0])
					{
						SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Failed;
						ret = E2E_P05STATUS_OKSOMELOST;
						printf("E2E_P05STATUS_OKSOMELOST\n");
					}
					else
					{
						SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Passed;
						ret = E2E_P05STATUS_OK;
						printf("E2E_P05STATUS_OK\n");
					}
				}
				else
				{
					RRR_State_IsFirstRcv=FALSE;
					SRR_Data_CheckSts_E2E = SRR_Data_CheckSts_Passed;
					ret = E2E_P05STATUS_OK;
					printf("E2E_P05STATUS_OK\n");
				}
				
				
			}
		}
	}
	RRR_State_Counter=DataPtr[0];
	return ret;
}
