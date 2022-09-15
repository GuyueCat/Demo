/** $Id$ $DateTime$
 *  @file errcode.h
 *  @brief ���ݡ�DVx�¼������һ����.xls��������Ӧ�ò�ʹ�õĴ�����.
 *  @version 0.0.1
 *  @since 0.0.1
 *  @author winson
 *  @date 2009-06-10    create for dvx
 */
/******************************************************************************
*@note
    Copyright 2007, BeiJing Bluestar Corporation, Limited
                   ALL RIGHTS RESERVED
Permission is hereby granted to licensees of BeiJing Bluestar, Inc. products
to use or abstract this computer program for the sole purpose of implementing
a product based on BeiJing Bluestar, Inc. products. No other rights to
reproduce, use, or disseminate this computer program,whether in part or in
whole, are granted. BeiJing Bluestar, Inc. makes no representation or
warranties with respect to the performance of this computer program, and
specifically disclaims any responsibility for any damages, special or
consequential, connected with the use of this program.
For details, see http://www.bstar.com.cn/
*******************************************************************************/

/**
 *@note
 *�����ĳ�����Ϊһ��4�ֽ�������
 *��1�ֽڱ�ʾģ����(module)�����±�
 *��2�ֽ�Ϊģ�����ӹ��ܱ�ţ��ɸ�ģ�����и���
 *��3-4�ֽ�Ϊ����ĳ����š�
 * MOD_ADMIND(1) | MOD_STREAMD(2)|MOD_EVENTD(3) | MOD_TASKD(4) | MOD_DEVLAYER(5)|
 * MOD_SYSTEM(9) | MOD_KERNEL(10)|MOD_KITS(11)  | MOD_FS(12)   | MOD_VMP(13)    |
 * MOD_COMPS(19) | MOD_DSP(20)   |MOD_ENGINE(21)| MOD_CODEC(22)|
 */

#ifndef _BSRERR_CODE_H
#define _BSRERR_CODE_H

/**
 * @enum
 * ���ݡ�DVx�¼������һ����.xls��˵����������ģ���ID
 */
enum
{
    ADMIND_ID  = 0x1,
    STREAMD_ID = 0x2,
    EVENTD_ID  = 0x3,
    TASKD_ID   = 0x4,
    DEV_ID     = 0x5,
    SYSTEM_ID  = 0x9,
    KERNEL_ID  = 0xa,
    KITS_ID    = 0xb,
    VMFS_ID    = 0xc,
    VMP_ID     = 0xd,
    COMPS_ID   = 0x13,
    DSP_ID     = 0x14,
    ENGINE_ID  = 0x15,
    CODEC_ID   = 0x16,
    APP_MAX_SYS_MOD,
};

/**
 * @enum
 * adminD��������ģ��Ķ�����ЩID�����������ɴ�������ͬʱ������ʹ��LIBKIT����ӡ������Ϣʱ��ģ��ע��
 */
enum
{
    ADMIND_PLAY_ID = 0x1,      /**< ���� */
    ADMIND_REC_ID  ,           /**< ¼�� */
    ADMIND_LIVE_ID ,           /**< �ֳ� */
    ADMIND_BACK_ID,            /**< ���� */
    ADMIND_ALM_ID,             /**< ���� */
    ADMIND_UM_ID,              /**< �û����� */
    ADMIND_NET_ID,             /**< ���� */
    ADMIND_NETLIVE_ID,         /**< �ֳ�AV */
    ADMIND_NETDOWNLOAD_ID,     /**< �������� */
    ADMIND_NETPLAY_ID,         /**< Զ�̻ط� */
    ADMIND_NETUPLOAD_ID,       /**< �����ϴ�������״̬�ϴ����¼��ϴ� */
    ADMIND_PARA_ID,            /**< ���� */
    ADMIND_DEV_ID,             /**< �豸���� */
    ADMIND_UART_ID,            /**< ���� */
    ADMIND_DISK_ID,            /**< ���� */
    ADMIND_LOG_ID,             /**< ��־ */
    ADMIND_SEARCH_ID,          /**< ���ϼ��� */
    ADMIND_PTZ_ID,             /**< ��̨���� */
    ADMIND_STAT_ID,            /**< ״̬���� */
    ADMIND_CARD_ID,            /**< ���� */
    ADMIND_FILE_ID,            /**< �ļ���صĲ��� */
    ADMIND_UMON_ID,            /**< usb monitor */
    ADMIND_UPGRADE_ID,         /**< ϵͳ���� */
    ADMIND_MAX_ID,
};

/**
 * @enum
 * streamD��������ģ��ID�Ķ���
 */
enum
{
    STREAMD_PLAY_ID = 0x1,  /**< ���� */
    STREAMD_REC_ID  ,        /**< ¼�� */
    STREAMD_LIVE_ID ,        /**< �ֳ� */
    STREAMD_BACK_ID ,        /**< ���� */
    STREAMD_ALM_ID  ,        /**< ���� */
    STREAMD_UM_ID   ,        /**< �û����� */
    STREAMD_NET_ID  ,        /**< ���� */
    STREAMD_PARA_ID ,        /**< ���� */
    STREAMD_DEV_ID,         /**< �豸���� */
    STREAMD_UART_ID,        /**< ���� */
    STREAMD_DISK_ID,        /**< ���� */
    STREAMD_LOG_ID,         /**< ��־ */
    STREAMD_SEARCH_ID,      /**< ���ϼ��� */
    STREAMD_DOWNLOAD_ID,    /**< ���� */
    STREAMD_NETLIVE_ID,     /**< �����ֳ� */
    STREAMD_NETPLAY_ID,     /**< Զ�̻ط�*/
    STREAMD_DISPATCH_ID,     /**< Զ�̻ط�*/
    STREAMD_NETFILE_ID,    
    STREAMD_SPEECH_ID,      /**< ˫������ */
    STREAMD_MAX_ID,
};

enum
{
    EVENTD_MAX_ID = 0,/*��δʹ��*/
};

/**
 * @enum
 * taskD��������ģ��ID�Ķ���
 */
enum
{
    TASKD_TIMER_ID = 0x1,    /**< ��ʱ�� */
    TASKD_CTRL_ID ,
    TASKD_STATE_ID,
    TASKD_BSFP,
    TASKD_MAX_ID,
};

/**
 * @enum
 * DevLayer��������ģ��ID�Ķ���
 * */
enum
{
    DEV_GUI_ID = 0x1,    /**< GUI */
    DEV_FP_ID,           /**< ǰ�� */
    DEV_BSCP_PRO,        /**< Э�� */
    DEV_BSCP_API,        /**< Э��Ӧ�� */
    DEV_CFG_ID,
    DEV_MAX_ID,
};

/* ������ȡ���� */
#define GET_ESTART(modId, subModId) (((modId|0x80)<<24)+((subModId)<<16))

/**
 * @enum
 * AdminD ����ģ��Ĵ��������ʼֵ
 */
enum
{
    ADMIND_PLAY_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PLAY_ID),               /**< ���� */
    ADMIND_REC_ESTART = GET_ESTART(ADMIND_ID, ADMIND_REC_ID),                 /**< ¼�� */
    ADMIND_LIVE_ESTART = GET_ESTART(ADMIND_ID, ADMIND_LIVE_ID),               /**< �ֳ� */
    ADMIND_BACK_ESTART = GET_ESTART(ADMIND_ID, ADMIND_BACK_ID),               /**< ���� */
    ADMIND_ALM_ESTART = GET_ESTART(ADMIND_ID, ADMIND_ALM_ID),                 /**< ���� */
    ADMIND_UM_ESTART = GET_ESTART(ADMIND_ID, ADMIND_UM_ID),                 /**< �û����� */
    ADMIND_NET_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NET_ID),                 /**< todo:��Χ̫�󣬽���ɾ�� */
    ADMIND_NETLIVE_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETLIVE_ID),         /**< �ֳ�AV */
    ADMIND_NETDOWNLOAD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETDOWNLOAD_ID), /**< �������� */
    ADMIND_NETPLAY_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETPLAY_ID),         /**< Զ�̻ط� */
    ADMIND_NETUPLOAD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETUPLOAD_ID),        /**< ����״̬�ϴ����¼��ϴ� */
    ADMIND_PARA_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PARA_ID),               /**< ���� */
    ADMIND_DEV_ESTART = GET_ESTART(ADMIND_ID, ADMIND_DEV_ID),                 /**< �豸���� */
    ADMIND_UART_ESTART = GET_ESTART(ADMIND_ID, ADMIND_UART_ID),               /**< ���� */
    ADMIND_DISK_ESTART = GET_ESTART(ADMIND_ID, ADMIND_DISK_ID),               /**< ���� */
    ADMIND_LOG_ESTART = GET_ESTART(ADMIND_ID, ADMIND_LOG_ID),                 /**< ��־ */
    ADMIND_SEARCH_ESTART = GET_ESTART(ADMIND_ID, ADMIND_SEARCH_ID),           /**< ���ϼ��� */
    ADMIND_PTZ_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PTZ_ID),                 /**< ��̨���� */
    ADMIND_STAT_ESTART = GET_ESTART(ADMIND_ID, ADMIND_STAT_ID),               /**< ״̬���� */
    ADMIND_CARD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_CARD_ID),               /**< ���� */
    ADMIND_FILE_EPATHNOTEXIST = GET_ESTART(ADMIND_ID, ADMIND_FILE_ID),
};

/**
 * @enum
 * streamD ����ģ��Ĵ��������ʼֵ
 */
enum
{
    STREAMD_PLAY_ESTART = GET_ESTART(STREAMD_ID, STREAMD_PLAY_ID),          /**< ���� */
    STREAMD_REC_ESTART = GET_ESTART(STREAMD_ID, STREAMD_REC_ID),            /**< ¼�� */
    STREAMD_LIVE_ESTART = GET_ESTART(STREAMD_ID, STREAMD_LIVE_ID),          /**< �ֳ� */
    STREAMD_BACK_ESTART = GET_ESTART(STREAMD_ID, STREAMD_BACK_ID),          /**< ���� */
    STREAMD_ALM_ESTART = GET_ESTART(STREAMD_ID, STREAMD_ALM_ID),            /**< ���� */
    STREAMD_NET_ESTART = GET_ESTART(STREAMD_ID, STREAMD_NET_ID),            /**< ���� */
    STREAMD_PARA_ESTART = GET_ESTART(STREAMD_ID, STREAMD_PARA_ID),          /**< ���� */
    STREAMD_DEV_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DEV_ID),            /**< �豸���� */
    STREAMD_UART_ESTART = GET_ESTART(STREAMD_ID, STREAMD_UART_ID),          /**< ���� */
    STREAMD_DISK_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DISK_ID),          /**< ���� */
    STREAMD_LOG_ESTART = GET_ESTART(STREAMD_ID, STREAMD_LOG_ID),            /**< ��־ */
    STREAMD_SEARCH_ESTART = GET_ESTART(STREAMD_ID, STREAMD_SEARCH_ID),      /**< ���ϼ��� */
    STREAMD_DOWNLOAD_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DOWNLOAD_ID),  /**< ���� */
};

/**
 * @enum
 * taskD ����ģ��Ĵ��������ʼֵ
 */
enum
{
    TASKD_TIMER_ESTART = GET_ESTART(TASKD_ID, TASKD_TIMER_ID),    /**< ��ʱ�� */
};

/**
 * @enum
 * DevLayer ����ģ��Ĵ��������ʼֵ
 */
enum
{
    DEV_GUI_ESTART = GET_ESTART(DEV_ID, DEV_GUI_ID),    /**< GUI */
    DEV_FP_ESTART  = GET_ESTART(DEV_ID, DEV_FP_ID),
    DEV_NET_ESTART = GET_ESTART(DEV_ID, DEV_BSCP_API),
    DEV_CFG_ESTART = GET_ESTART(DEV_ID, DEV_CFG_ID),
};

/* ͨ�õĴ����� */
#define    APP_OK                            0
#define    APP_SUCCESS                       0
#define    APP_FAIL                        (-1)

/**
*��Ҫ��bscp����ż���,����Ųμ�BSCP.h
*/
#define BSCP_ERR(x) (x)
/**
 * @enum
 * AdminD ����ģ��Ĵ����붨��
 */
enum
{
    ADMIND_PLAY_EXXX = ADMIND_PLAY_ESTART,            /**< ���� */

    ADMIND_REC_EXXX = ADMIND_REC_ESTART,              /**< ¼�� */
    ADMIND_REC_EPOINTERNULL,                          /**< ��ӻ�ɾ��������ָ��Ϊ�� */
    ADMIND_REC_EINITRECINFOMEMFAILD,                  /**< �����¼¼����Ϣ�ڴ�ʧ�� */
    ADMIND_REC_EPRESTARTRECREQNULL,                   /**< ׼��¼���ȡ������Ϣʧ�� */
    ADMIND_REC_EPRESTOPRECREQNULL,                    /**< ֹͣ¼���ȡ������Ϣʧ�� */
    ADMIND_REC_ECHANNELINFOMUTEXFAILD,                /**< ��ʼ������ͨ����Ϣ�ź���ʧ�� */
    ADMIND_REC_ERECCTRLDEBUGFAILD,/**< ¼����ģ�������Ϣע��ʧ�� */
    ADMIND_REC_EDATAINMEMINITFAILD,/**< ��������ģ���ڴ��ʼ��ʧ�� */
    ADMIND_REC_EDATAINTHREADFAILD, /**< ���������̴߳���ʧ�� */
    ADMIND_REC_ERECORDCTRLCOMDFAILD, /**< ����� */
    ADMIND_REC_ESTARTRECORDCOMDFAILD,/**< ¼������� */
    ADMIND_REC_ERECORDCONDITIONFAILD,/**< ¼������������ */
    ADMIND_REC_ERECORDINPARAMFAILD, /**< ����������� */

    ADMIND_LIVE_EINPUTINVALID = ADMIND_LIVE_ESTART + 0x01,            /**< �ֳ� */
    ADMIND_LIVE_EPOINTERNULL ,
    ADMIND_LIVE_EINVALIDVOSTATE,
    ADMIND_LIVE_EUNSUPPORT ,
    ADMIND_LIVE_EPREIVEWFAILED,
    ADMIND_LIVE_EINPARAM,
    ADMIND_LIVE_EETGREATERTHANBT, /* ��ʼʱ�䲻�ܴ��ڽ���ʱ�� */
    ADMIND_LIVE_EETEQUALTOBT,     /* ��ʼʱ�䲻�ܵ��ڽ���ʱ�� */

    ADMIND_BACK_EXXX = ADMIND_BACK_ESTART,            /**< ���� */
    ADMIND_BACK_EDISKFULL,							/**< �������� */
    ADMIND_BACK_EFILESIZE,							/**< д�뱸���ļ������ݳ����ѳ����������󳤶� */
    ADMIND_BACK_WRFAIL,								/**< ��������д�����ʧ�� */
    ADMIND_BACK_CANCELLED,							/**< �û��ڱ��ݹ�����ִ����ȡ������ */

    ADMIND_ALM_EXXX = ADMIND_ALM_ESTART,              /**< ���� */

    ADMIND_UM_EXXX = ADMIND_UM_ESTART,            /**< �û����� */
    ADMIND_UM_EAUTHFAILD,                              /**< Ȩ��У��ʧ��*/
    ADMIND_NET_EXXX = ADMIND_NET_ESTART,              /**< ����,��Χ̫�󣬽���ɾ�� */

    ADMIND_NETLIVE_EXXX = ADMIND_NETLIVE_ESTART,             /**< �ֳ�AV */

    ADMIND_NETDOWNLOAD_EXXX = ADMIND_NETDOWNLOAD_ESTART,     /**< �������� */

    ADMIND_NETPLAY_EXXX = ADMIND_NETPLAY_ESTART,             /**< Զ�̻ط� */

    ADMIND_NETUPLOAD_EXXX = ADMIND_NETUPLOAD_ESTART,         /**< �����ϴ�������״̬�ϴ����¼��ϴ� */
    ADMIND_NETUPLOAD_EINUNINIT = ADMIND_NETUPLOAD_ESTART + 1,
    ADMIND_NETUPLOAD_EINGETNETCFG,
    ADMIND_NETUPLOAD_EINCREATESOCKET,
    ADMIND_NETUPLOAD_EINSOCKET,
    ADMIND_NETUPLOAD_EINSENDTO,
    ADMIND_NETUPLOAD_EINTRANSPORTMANNER,
    ADMIND_NETUPLOAD_EINPAYLOADADDR,
    ADMIND_NETUPLOAD_EINPAYLOADLEN,
    ADMIND_NETUPLOAD_EINCHECKPARAM,

    ADMIND_PARA_EXXX = ADMIND_PARA_ESTART,            /**< ���� */
    ADMIND_PLAY_ESEARCHFAILD,
    ADMIND_PLAY_ESTARTFAILD,

    ADMIND_DEV_EXXX = ADMIND_DEV_ESTART,             /**< �豸���� */

    ADMIND_UART_EXXX = ADMIND_UART_ESTART,            /**< ���� */
    ADMIND_UART_EINITFAIL,/**< ��ʼ��ʧ�� */
    ADMIND_UART_EPORTNOTOPEN,/**< ����û�д� */
    ADMIND_UART_EPORTREADFAIL,/**< ������ʧ�� */
    ADMIND_UART_EPORTWRITEFAIL,/**< д����ʧ�� */
    ADMIND_UART_ELINKTYPENOIMPL,/**< ѡ������·����û��ʵ�� */
    ADMIND_UART_ESNOOPLINKTYPE,  /**< ѡ���Ĳ��񣨿��Ų�����·���ʹ��� */
    ADMIND_UART_ESNOOPPROTOCOL,  /**< ѡ���Ĳ��񣨿��Ų���Э����� */
    

    ADMIND_DISK_EXXX = ADMIND_DISK_ESTART,            /**< ���� */

    ADMIND_LOG_EXXX = ADMIND_LOG_ESTART,             /**< ��־ */

    ADMIND_SEARCH_EXXX = ADMIND_SEARCH_ESTART,          /**< ���ϼ��� */
    ADMIND_SEARCH_EEOF, /**< �����ļ���β�� */
    ADMIND_SEARCH_EBOF, /**< �����ļ��Ŀ�ͷ */
    ADMIND_SEARCH_EINVALIDHANDLE, /**< ��Ч�ľ�� */
    ADMIND_SEARCH_ETEMPNA, /**< Service temporarily unavailable, try later */
    ADMIND_SEARCH_EINVALIDPARAM, /**< Invalid parameter(function call) */
    ADMIND_SEARCH_EPAGESIZETOOBIG, /**< Page size exceeds 50 */
    ADMIND_SEARCH_EFILESYSOPERATIONFAILD, /**< a call to a file system function failed */
    ADMIND_SEARCH_EOPENFAILD,/**< fsEventQueryOpen() failed */
    ADMIND_SEARCH_EFETCHFAILD,/**< fsEventFetch() failed */

    ADMIND_PTZ_EXXX = ADMIND_PTZ_ESTART,             /**< ��̨���� */
    ADMIND_PTZ_EINVALIDCHANNEL, /**< ͨ������������/���� */
    ADMIND_PTZ_EBUSY,         /**< ��̨��������, ��ָ���޷�ִ��, Ӧ����ͣ����̨��ǰ���� */
    ADMIND_PTZ_EINVALIDPRESETIDX,/**< Ԥ��λ����������/���� */
    ADMIND_PTZ_EINVALIDPATHIDX,  /**< Ѳ��·����������������/���� */
    ADMIND_PTZ_EPATHEMPTY,/**< ����Ѳ��·����û��Waypoint */
    ADMIND_PTZ_EPATHFULL,/**< ����Ѳ��·����Waypoint��Ŀ�Ѵ����ֵ */
    ADMIND_PTZ_EUNSUPPORTEDCMD,
    ADMIND_PTZ_EMODINITFAILED, /**< ģ���ʼ��ʧ�� */
    ADMIND_PTZ_EREINITFORBIDDEN,/**< ģ���Ѿ���ʼ��, �������ٴγ�ʼ�� */
    ADMIND_PTZ_EUNINIT, /**< û�г�ʼ�� */
    ADMIND_PTZ_EINVALIDDALPARAM, /**< �豸�����û���ṩ��Ҫ�Ĳ��� */
    ADMIND_PTZ_EPATHOVERFLOW,/**< ·���ڵ�·�㳬�����ֵ, ·����Ч */
    ADMIND_PTZ_ECREATETHREADFAILED,
    ADMIND_PTZ_EBSCMDNOIMPL, /**< �ײ�û��ʵ�ָ�BSky ��̨���� */

    ADMIND_STAT_EXXX = ADMIND_STAT_ESTART,            /**< ״̬���� */

    ADMIND_CARD_EXXX = ADMIND_CARD_ESTART,            /**< ���� */
    ADMIND_CARD_EINLIBNAME = ADMIND_CARD_ESTART + 1,
    ADMIND_CARD_EINPARAM,
    ADMIND_CARD_EINSOCKET,
    ADMIND_CARD_EINBIND,
    ADMIND_CARD_EINDLOPEN,
    ADMIND_CARD_EINDLSYM,
    ADMIND_CARD_EINPTHREADCREAT,
};
/**
 * @enum
 * streamD ����ģ��Ĵ����붨��
 */
enum 
{
    STREAMD_PLAY_EXXX = STREAMD_PLAY_ESTART,  /**< ���� */

    STREAMD_REC_EXXX = STREAMD_REC_ESTART,         /**< ¼�� */

    STREAMD_LIVE_EXXX = STREAMD_LIVE_ESTART,        /**< �ֳ� */
    STREAMD_LIVE_ELIVESWITCHCHANNELFAILD = STREAMD_LIVE_ESTART + 1,

    STREAMD_BACK_EXXX = STREAMD_BACK_ESTART,        /**< ���� */

    STREAMD_ALM_EXXX = STREAMD_ALM_ESTART,         /**< ���� */

    STREAMD_NET_EXXX = STREAMD_NET_ESTART,         /**< ���� */

    STREAMD_PARA_EXXX = STREAMD_PARA_ESTART,        /**< ���� */

    STREAMD_DEV_EXXX = STREAMD_DEV_ESTART,         /**< �豸���� */

    STREAMD_UART_EXXX = STREAMD_UART_ESTART,        /**< ���� */

    STREAMD_DISK_EXXX = STREAMD_DISK_ESTART,        /**< ���� */

    STREAMD_LOG_EXXX = STREAMD_LOG_ESTART,         /**< ��־ */

    STREAMD_SEARCH_EXXX = STREAMD_SEARCH_ESTART,      /**< ���ϼ��� */

    STREAMD_DOWNLOAD_EXXX = STREAMD_DOWNLOAD_ESTART,    /**< ���� */
    STREAMD_DOWNLOAD_EOPENFAIL,
    STREAMD_DOWNLOAD_EDISKOPENFAIL,
    STREAMD_DOWNLOAD_EPARAM,
    STREAMD_DOWNLOAD_EFAIL,
};

/**
 * @enum
 * taskD ����ģ��Ĵ����붨��
 */
enum
{
    TASKD_TIMER_EXXX = TASKD_TIMER_ESTART,    /**< ��ʱ�� */
    TASKD_TIMER_EUNINIT = TASKD_TIMER_ESTART + 1, /**< timerģ��û�г�ʼ�� */
    TASKD_TIMER_EFULL,                            /**< ϵͳtimers�������Ｋ��ֵ, ��ʱ��������µ�timer */
    TASKD_TIMER_EELAPSETOOBIG,                    /**< ��ʱֵ̫��, �ο�AT_LIMIT_ELAPSE*/
    TASKD_TIMER_EINVALIDPARAM,                    /**< ��Ч����*/
    TASKD_TIMER_ECREATETHREADFAILED,
};
/**
 * @enum
 * DevLayer ����ģ��Ĵ����붨��
 */
enum
{
    DEV_GUI_EXXX = DEV_GUI_ESTART,    /**< GUI */

    DEV_FP_EXXX = DEV_FP_ESTART,

    DEV_NET_EXXX = DEV_NET_ESTART,
    DEV_NET_ECREATESRVFAILED = DEV_NET_ESTART + 1,
    DEV_NET_ESOCKINITFAILED,
    DEV_NET_ECMDUNSUPPORT,
    DEV_NET_EMSGINVALID,
    DEV_NET_ELOGINFAILD,
    DEV_NET_EREADFAILD,
    DEV_NET_EWRITEFAILD,
    DEV_NET_ESTARTRECORDFAILD,
    DEV_NET_ESTOPRECORDFAILD,
    DEV_NET_ELOGOUTFAILD,
    DEV_NET_EPLAYSTARTFAILD,
    DEV_NET_EPLAYSTOPFAILD,
    DEV_NET_EACTIONAUTHFAIL,
    DEV_NET_ESTREAMFAIL,
    
    DEV_CFG_DATA_FULL = DEV_CFG_ESTART + 1,
    DEV_CFG_EIPCONFLICT, /**<IP ��ͻ*/
};


/**@ enum ENetLiveError
 * ���������Ϣ
 */
typedef enum
{
    ERR_STREAMD_NET_CONNECT_FAIL      = STREAMD_NET_ESTART,                     /**< ����ʧ��*/
    ERR_STREAMD_NET_RTP_ERR           = STREAMD_NET_ESTART + BSCP_ERR(0x0001),  /**< RTP�������*/
    ERR_STREAMD_NET_DISCONNECT        = STREAMD_NET_ESTART + BSCP_ERR(0x0002),  /**< ���������ж�*/
    ERR_STREAMD_NET_SOCK_ERR          = STREAMD_NET_ESTART + BSCP_ERR(0x0003),  /**< ����socket����*/
    ERR_STREAMD_NET_TICKET_ERR        = STREAMD_NET_ESTART + BSCP_ERR(0x0004),  /**< ��Ư����*/
    ERR_STREAMD_NET_FILE_READ_ERR     = STREAMD_NET_ESTART + BSCP_ERR(0x0005),  /**< �ļ�������*/
    ERR_STREAMD_NET_PARAM_ERR         = STREAMD_NET_ESTART + BSCP_ERR(0x0006),  /**< ��������*/    
    ERR_STREAMD_NET_END_OF_FILE       = STREAMD_NET_ESTART + BSCP_ERR(0x0007),  /**< �����ļ���β*/    
    ERR_STREAMD_NET_STATE             = STREAMD_NET_ESTART + BSCP_ERR(0x0008),  /**< �����ļ���β*/    
    ERR_STREAMD_NET_FULL_ERR          = STREAMD_NET_ESTART + BSCP_ERR(0x0010),  /**< ������*/    
    ERR_STREAMD_NET_INVALID_STREAM_ID = STREAMD_NET_ESTART + BSCP_ERR(0x0011),  /**< �Ƿ�����ʶ*/
    ERR_STREAMD_NET_OPEN_ENCODER      = STREAMD_NET_ESTART + BSCP_ERR(0x0012),  /**< ��������ʧ��*/
    ERR_STREAMD_NET_FILE_OPEN_ERR     = STREAMD_NET_ESTART + BSCP_ERR(0x0013),  /**< �ļ���ʧ��*/
    ERR_STREAMD_CHANNEL_DISABLE_ERR   = STREAMD_NET_ESTART + BSCP_ERR(0x0014),  /**< ͨ������*/
    
} ENetError;


/**@ enum EUmError
 * �û�������������Ϣ
 */
typedef enum
{
    ERR_ADMIND_AUTH_PARAM_ERROR          = ADMIND_UM_ESTART + BSCP_ERR(0x0006),    /**<��������*/
    ERR_ADMIND_AUTH_USER_NOT_EXIST       = ADMIND_UM_ESTART + BSCP_ERR(0x0201),    /**<�û�������*/
    ERR_ADMIND_AUTH_DUP_USERNAME         = ADMIND_UM_ESTART + BSCP_ERR(0x0202),    /**<�û�����*/
    ERR_ADMIND_AUTH_USER_UP_LIMIT        = ADMIND_UM_ESTART + BSCP_ERR(0x0203),    /**<�û��ﵽ����*/
    ERR_ADMIND_AUTH_PASSWD_ERROR         = ADMIND_UM_ESTART + BSCP_ERR(0x0204),    /**<�û��������*/
    ERR_ADMIND_AUTH_GROUP_UP_LIMIT       = ADMIND_UM_ESTART + BSCP_ERR(0x0205),    /**<�û���ﵽ����*/
    ERR_ADMIND_AUTH_GROUP_NOT_EXIST      = ADMIND_UM_ESTART + BSCP_ERR(0x0206),    /**<�û��鲻����*/
    ERR_ADMIND_AUTH_LOGIN_UP_LIMIT       = ADMIND_UM_ESTART + BSCP_ERR(0x0207),    /**<��¼�ﵽ����*/
    ERR_ADMIND_AUTH_CAN_NOT_DEL_ADMIN    = ADMIND_UM_ESTART + BSCP_ERR(0x0208),    /**<����ɾ����������Ա*/   
    ERR_ADMIND_AUTH_CAN_NOT_MODIFY_ADMIN = ADMIND_UM_ESTART + BSCP_ERR(0x0209),    /**<�����޸ĳ�������Ա��Ϣ*/        
    ERR_ADMIND_AUTH_CAN_NOT_DEL_USER      = ADMIND_UM_ESTART + BSCP_ERR(0x020a),    /**<����ɾ���ѵ�¼�û�*/    
    ERR_ADMIND_AUTH_USER_GROUP_SAME_NAME = ADMIND_UM_ESTART + BSCP_ERR(0x020b),    /**<�û����������û�����*/
    ERR_ADMIND_AUTH_PRIV_SET_FAIL        = ADMIND_UM_ESTART + BSCP_ERR(0x020c),    /**<Ȩ�����ô���*/   
    ERR_ADMIND_AUTH_INVALID_PWD_LEN      = ADMIND_UM_ESTART + BSCP_ERR(0x020d),    /**<�������ó��ȴ���*/        
    ERR_ADMIND_AUTH_PWD_DIFF             = ADMIND_UM_ESTART + BSCP_ERR(0x020e),    /**<ԭ�������*/     
} EUmError;

/**@ enum EDevError
 * �豸���������
 */
typedef enum
{
    ERR_DEV_CFG_PARAM_ERROR          = DEV_CFG_ESTART + BSCP_ERR(0x000c),    /**<��������*/    
} EDevError;

char* lcsysMod2str(unsigned int error);
char* lcsubMod2str(unsigned int error);
#endif /*_BSRERR_CODE_H*/

