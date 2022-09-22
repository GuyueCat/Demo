#ifndef CDD_Hella_E2E_P5_H
#define CDD_Hella_E2E_P5_H

#include "type.h"

/*E2E Process Status*/
#define AUTOMATIC
#define E2E_APPL_DATA
#define E2E_E_INPUTERR_NULL  0x13u /**< Error: At least one pointer parameter is NULL    */
#define E2E_E_INPUTERR_WRONG 0x17u /**< Error: At least one input parameter is erroneous, e.g. out of range    */
#define E2E_E_INTERR         0x19u /**< Error: An internal library error has occurred    */
#define E2E_E_WRONGSTATE     0x1Au /**< Error: Function executed in wrong state */
#define E2E_E_OK             0x00u /**< Function completed successfully       */
#define CRC_APPL_DATA
#define CRC_PRIVATE_CODE
#define CRC_CODE
#define CRC_CONST
#define CRC_INITIAL_VALUE16         (0xFFFFu)
#define CRC_LOCAL static
#define CRC_POLYNOMIAL_16           (0x1021u)
#define TRUE   1u
#define FALSE  0u

/*SDH Process Status*/
#define SDH_STATUS_SUCCESS          0x00u
#define SDH_STATUS_INVALID_MSGID    0x10u
#define SDH_STATUS_ERR_SEQUENCE     0x20u
#define SDH_STATUS_ERR_MSGMISSING   0x30u
#define SDH_STATUS_ERR_INVALICYC    0x40u

typedef enum {
    E2E_P05STATUS_OK = 0x00,
    E2E_P05STATUS_NONEWDATA = 0x01,
    E2E_P05STATUS_ERROR = 0x07,
    E2E_P05STATUS_REPEATED = 0x08,
    E2E_P05STATUS_OKSOMELOST = 0x20,
    E2E_P05STATUS_WRONGSEQUENCE = 0x40
} E2E_P05CheckStatusType;

typedef union
{
    uint32 flag; /**< @brief Standard identifier.*/
    struct 
    {
        uint32 HeaderRcvFlg: 1;
        uint32 TrailerRcvFlg: 1;
        uint32 Reserve:    3;
        uint32 DataRcvCnt: 8;
        uint32 Crc: 16;
    } B;
} SRR_DataRcvFlg;

typedef enum
{
	SRR_Data_CheckSts_Init,
	SRR_Data_CheckSts_Failed,
	SRR_Data_CheckSts_Pending,
	SRR_Data_CheckSts_Passed,
	SRR_Data_CheckSts_Reserved
}SRR_Data_CheckSts;

typedef enum
{
	SRR_Frame_Header,
	SRR_Frame_Data,
	SRR_Frame_Trailer
}SRR_Frame_Type;

typedef uint8 Std_ReturnType;
typedef P2CONST(uint8, AUTOMATIC, CRC_APPL_DATA) Crc_DataRefType;
static SRR_DataRcvFlg SRR_DataRcvFlg_E2E;
static SRR_Data_CheckSts SRR_Data_CheckSts_E2E;

Std_ReturnType E2E_P05ProtectInit(void);
Std_ReturnType E2E_P05ProtectCheck_Header(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,uint32 Length,SRR_Frame_Type FrameType);
Std_ReturnType E2E_P05ProtectCheck_Data(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, uint32 Length,SRR_Frame_Type FrameType,uint8 Data_Multiplexor);
Std_ReturnType E2E_P05ProtectCheck_Trailer(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr,uint32 Length,SRR_Frame_Type FrameType);
FUNC(uint16, CRC_CODE) Crc_CalculateCRC16(Crc_DataRefType Crc_DataPtr,uint32 Crc_Length,uint16 Crc_StartValue16,boolean Crc_IsFirstCall);
uint16 E2E_P05ComputeCRC(P2CONST(uint8, AUTOMATIC, E2E_APPL_DATA) DataPtr, SRR_Frame_Type FrameType, uint32 Length,uint16 StartValue);
CRC_LOCAL FUNC(uint16, CRC_PRIVATE_CODE) Crc_CalculateCRC16Runtime(uint32 Crc_Length,Crc_DataRefType Crc_DataPtr,uint16 Crc_Value);

#endif /* _TEMPLATE_H_ */
