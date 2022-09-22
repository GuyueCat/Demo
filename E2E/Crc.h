/**** Protection against multiple inclusion **************************************************************************/
#if !defined CRC_H
# define CRC_H

# define CRC_VENDOR_ID                     (30u)
# define CRC_MODULE_ID                     (201u)
# define CRC_INSTANCE_ID                   (0u)
# define CRC_AR_RELEASE_MAJOR_VERSION      (4u)
# define CRC_AR_RELEASE_MINOR_VERSION      (0u)
# define CRC_AR_RELEASE_REVISON_VERSION    (3u)
# define CRC_SW_MAJOR_VERSION              (6u)
# define CRC_SW_MINOR_VERSION              (0u)
# define CRC_SW_PATCH_VERSION              (1u)

/***** Protection against multiple inclusion *****/
# define CRC_CFG_H
/* This is not the sub-package version but a compatibility version, which will only be updated if a change in the 
   generator (i.e. generated files) affects the implementation sub-package */
# define CRC_CFG_MAJOR_VERSION	(3u) 
# define CRC_CFG_MINOR_VERSION	(1u) 

/***** Supported CRC Calculation modes *****/

/* CRC 8 */
# define CRC_8_RUNTIME           (0u)
# define CRC_8_TABLE             (1u)
# define CRC_8_HARDWARE          (2u)

/* CRC 8H2F */
# define CRC_8H2F_RUNTIME        (0u)
# define CRC_8H2F_TABLE          (1u)
# define CRC_8H2F_HARDWARE       (2u)

/* CRC 16 */
# define CRC_16_RUNTIME          (0u)
# define CRC_16_TABLE            (1u)
# define CRC_16_HARDWARE         (2u)
# define CRC_16_TABLE_4          (3u)
# define CRC_16_TABLE_8          (4u)

/* CRC 32 */
# define CRC_32_RUNTIME          (0u)
# define CRC_32_TABLE            (1u)
# define CRC_32_HARDWARE         (2u)

/* CRC 32P4 */
# define CRC_32P4_RUNTIME        (0u)
# define CRC_32P4_TABLE          (1u)
# define CRC_32P4_HARDWARE       (2u)
# define CRC_32P4_TABLE_4        (3u)
# define CRC_32P4_TABLE_8        (4u)

/* CRC 64 */
# define CRC_64_RUNTIME          (0u)
# define CRC_64_TABLE            (1u)
# define CRC_64_HARDWARE         (2u)
# define CRC_64_TABLE_4          (3u)
# define CRC_64_TABLE_8          (4u)
        
/***** CRC Calculation configuration *****/

# define CRC_8_MODE              (CRC_8_RUNTIME)
# define CRC_8H2F_MODE           (CRC_8H2F_RUNTIME)
# define CRC_16_MODE             (CRC_16_RUNTIME)
# define CRC_32_MODE             (CRC_32_RUNTIME)
# define CRC_32P4_MODE           (CRC_32P4_RUNTIME)
# define CRC_64_MODE             (CRC_64_RUNTIME)


/***** Optional API function *****/
# define CRC_VERSION_INFO_API    (STD_ON)
#endif
