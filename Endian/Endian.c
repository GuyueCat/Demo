/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *  文件编码格式为gb2312,cp936  
 *  $Id$ $DateTime$
 *  @file Endian.c
 *  @brief 大小端字节序处理
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author melvyn<chris.guyue@gmail.com>
 *  @date 2022-07-06    create
 *
 *  \details  1- 数据的 Startbit、Length[bit]、以及数据位代表的含义要根据DBC文件来判断
 *            2- 可以参考 DBC 文件中 Layout 的数据流
 *            3- 如果选择的是小端字节序，可以根据 CANoe 上传递出的值进行判断
 *                
 *********************************************************************************************************************/

#include <stdio.h>

typedef unsigned char         boolean;       /*        TRUE .. FALSE           */
typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */
typedef signed char           sint8_least;   /* At least 7 bit + 1 bit sign    */
typedef unsigned char         uint8_least;   /* At least 8 bit                 */
typedef signed short          sint16_least;  /* At least 15 bit + 1 bit sign   */
typedef unsigned short        uint16_least;  /* At least 16 bit                */
typedef signed long           sint32_least;  /* At least 31 bit + 1 bit sign   */
typedef unsigned long         uint32_least;  /* At least 32 bit                */
typedef float                 float32;

typedef enum
{
  SignalEndianness_Little,
  SignalEndianness_Big
} SignalEndianness;

typedef enum
{
  SignalType_sint8,
  SignalType_boolean,
  SignalType_uint8,
  SignalType_sint16,
  SignalType_uint16,
  SignalType_sint32,
  SignalType_uint32
} SignalType;

static uint32 Read32BitData(const uint8* DataPtr,uint16 bitPosition, uint16 bitSize, SignalEndianness endian, SignalType signalType)
{
    /* Unaligned data and/or endian-ness conversion*/
    uint32 ReturnData = 0;
    if(endian == SignalEndianness_Big)
    {
      /* uint32 lsbIndex = (((uint32)bitPosition ^ 0x7u) + (uint32)bitSize - 1u) ^ 7u; */ /* calculate lsb bit index. This could be moved to generator*/
      uint32 lsbIndex =  bitPosition; /*Lsb Index could be taken from start bit in dbc files ,the Calculation above is not needed*/
      sint32 s_lsbIndex = ((sint32)lsbIndex/8) -3;
      const uint8 *ReturnDataPtr = &DataPtr [s_lsbIndex]; /* calculate big endian ptr to data*/
      uint8 bitShift = (uint8)(lsbIndex % 8u);
      for(uint8 i = 0; i < 4u; i++)
      {
        ReturnData = (ReturnData << 8) | ReturnDataPtr[i];
      }
      ReturnData >>= bitShift;
      if((32u - (uint16)bitShift) < bitSize)
      {
        ReturnData |= (uint32)ReturnDataPtr[-1] << (32u - bitShift);
      }
    } else if (endian == SignalEndianness_Little)
    {
      uint32 lsbIndex = bitPosition;
      const uint8 *ReturnDataPtr = &DataPtr[(bitPosition/(uint16)8)];
      uint8 bitShift = (uint8)(lsbIndex%(uint32)8);
      uint8 bitmask;
      for(sint8 i = 3; i >= 0; i--)
      {
        ReturnData = (ReturnData << 8) | ReturnDataPtr[i];
      }
      ReturnData >>= bitShift;

      if((32u - (uint16)bitShift) < bitSize)
      {
        bitmask = 0xFFu >> (8u-bitShift);
        /*  polyspace<RTE: OVFL : Low : No action planned > It is verified that left shift operation would never lead to overflow. */
        ReturnData |= (((uint32)ReturnDataPtr[4])&bitmask) << (32u - bitShift);
      }
    }
    /*polyspace:end<RTE: UNR : Not a defect: No action planned > Defensive code. Protects software against unexpected behaviour for invalid data. */
    else
    {
        /*Do Nothing*/
    }

    uint32 mask = 0xFFFFFFFFUL >> (32u - bitSize); /* calculate mask for SigVal */
    ReturnData &= mask; /* clear bit out of range */
    uint32 signmask = ~(mask >> 1u);

    if((signalType == SignalType_sint8)||(signalType == SignalType_sint16) ||(signalType == SignalType_sint32))
    {
        if((uint32)0 < (ReturnData & signmask))
        {
          ReturnData |= signmask; /* add sign bits */
        }
        /* sign extended data can be written as uint*/
    }

    return ReturnData;
}

static float32 GetMin(float32 x, float32 y)
{
  /* GetMin from x y*/
  return (x < y) ? x : y;
}

static float32 GetMax(float32 x, float32 y)
{
   /* GetMax from x y*/
   return (x > y) ? x : y;
}

float32 ConvertToPhysicalValue(float32 value, float32 factor, float32 offset, float32 minValue, float32 maxValue)
{
  float32 result = (value * factor) + offset;

  // As in a DBC file, when both the upper and lower bound are equal to 0, we do not take them into account.
  if ((minValue != (float32)0) || (maxValue != (float32)0))
  {
    // Take into account the upper and lower bounds.
    result = GetMin(result, maxValue);
    result = GetMax(minValue, result);
  }

  return result;
}

int main(){
    uint8 arr[] ={0x02, 0x01, 0x48, 0xc0, 0x97, 0xdf, 0x83, 0x98};
    /* 如果转换成小端字节序，他的格式应该是：98 83 df 97 c0 48 01 02
     * 本次数据的定义是按照2个byte来转换的。
     * 小端字节序的特点是：低位字节放在低位地址，高位字节放在高位地址。
     * 根据上面的格式，右边是低位地址，即 02，左边是高位地址，即 98
     */
    uint32 Multiplexor = Read32BitData((const uint8* )&arr[0],  0,  8, SignalEndianness_Little,SignalType_uint16);
    uint32 Id_S2       = Read32BitData((const uint8* )&arr[0],  8, 10, SignalEndianness_Little,SignalType_uint16);
    uint32 ObjInit     = Read32BitData((const uint8* )&arr[0], 18,  1, SignalEndianness_Little,SignalType_uint16);
    uint32 ObjMeasured = Read32BitData((const uint8* )&arr[0], 19,  1, SignalEndianness_Little,SignalType_uint16);
    uint32 Little_XPos = Read32BitData((const uint8* )&arr[0], 20, 16, SignalEndianness_Little,SignalType_uint16);
    uint32 Big_XPos    = Read32BitData((const uint8* )&arr[0], 20, 16, SignalEndianness_Big,SignalType_uint16);
    uint32 YPos        = Read32BitData((const uint8* )&arr[0], 36, 15, SignalEndianness_Little,SignalType_uint16);
    uint32 XVelocity   = Read32BitData((const uint8* )&arr[0], 51, 14, SignalEndianness_Little,SignalType_uint16);
    uint32 YVelocity   = Read32BitData((const uint8* )&arr[0], 65, 14, SignalEndianness_Little,SignalType_uint16);

    printf("Little_XPos=%x,float(Little_XPos)=%f \n" ,Little_XPos, (float32)Little_XPos);
    printf("Big_XPos=%x,float(Big_XPos)=%f \n" ,Big_XPos, (float32)Big_XPos);           

    float32 P_XPos = ConvertToPhysicalValue((float32)Little_XPos , (float32) 0.01,(float32)-250.0,(float32)-250.0, (float32) 250.0);
    printf("P_XPos=%f \n" , (float32)P_XPos);

}