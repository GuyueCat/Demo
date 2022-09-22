/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef unsigned char         boolean;       /*        TRUE .. FALSE           */
typedef signed char           sint8;         /*        -128 .. +127            */
typedef unsigned char         uint8;         /*           0 .. 255             */
typedef signed short          sint16;        /*      -32768 .. +32767          */
typedef unsigned short        uint16;        /*           0 .. 65535           */
typedef signed long           sint32;        /* -2147483648 .. +2147483647     */
typedef unsigned long         uint32;        /*           0 .. 4294967295      */
#if defined(__TASKING__)  /* valid for Tasking */
# if (__STDC_VERSION__ >= 199901L) /* ISO-C version is C99 or higher*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
# endif
#else /* valid for GNU and Diab*/
#define PLATFORM_SUPPORT_SINT64_UINT64
typedef signed    long long  sint64;   /* -9223372036854775808 .. 9223372036854775807      */
typedef unsigned  long long  uint64;   /*                    0 .. 18446744073709551615     */
#endif
typedef float                 float32;
typedef double                float64;

typedef uint8 PduIdType;   /**< /ActiveEcuC/EcuC/EcucPduCollection[0:PduIdTypeEnum] */
typedef uint16 PduLengthType;   /**< /ActiveEcuC/EcuC/EcucPduCollection[0:PduLengthTypeEnum] */

/***** define function API function *****/
#define FUNC(rettype, memclass) rettype memclass
#define P2CONST(ptrtype, memclass, ptrclass) const memclass ptrtype ptrclass *


































