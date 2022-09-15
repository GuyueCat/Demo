/** $Id$ $DateTime$
 *  @file errcode.h
 *  @brief 根据《DVx事件与出错一览表.xls》来定义应用层使用的错误码.
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
 *函数的出错编号为一个4字节整数：
 *第1字节表示模块编号(module)，见下表，
 *第2字节为模块内子功能编号，由各模块自行负责，
 *第3-4字节为具体的出错编号。
 * MOD_ADMIND(1) | MOD_STREAMD(2)|MOD_EVENTD(3) | MOD_TASKD(4) | MOD_DEVLAYER(5)|
 * MOD_SYSTEM(9) | MOD_KERNEL(10)|MOD_KITS(11)  | MOD_FS(12)   | MOD_VMP(13)    |
 * MOD_COMPS(19) | MOD_DSP(20)   |MOD_ENGINE(21)| MOD_CODEC(22)|
 */

#ifndef _BSRERR_CODE_H
#define _BSRERR_CODE_H

/**
 * @enum
 * 根据《DVx事件与出错一览表.xls》说明来定义主模块的ID
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
 * adminD的所有子模块的定义这些ID除了用来生成错误码外同时还用在使用LIBKIT来打印调试信息时的模块注册
 */
enum
{
    ADMIND_PLAY_ID = 0x1,      /**< 播放 */
    ADMIND_REC_ID  ,           /**< 录像 */
    ADMIND_LIVE_ID ,           /**< 现场 */
    ADMIND_BACK_ID,            /**< 备份 */
    ADMIND_ALM_ID,             /**< 报警 */
    ADMIND_UM_ID,              /**< 用户管理 */
    ADMIND_NET_ID,             /**< 网络 */
    ADMIND_NETLIVE_ID,         /**< 现场AV */
    ADMIND_NETDOWNLOAD_ID,     /**< 资料下载 */
    ADMIND_NETPLAY_ID,         /**< 远程回放 */
    ADMIND_NETUPLOAD_ID,       /**< 网络上传，包括状态上传和事件上传 */
    ADMIND_PARA_ID,            /**< 参数 */
    ADMIND_DEV_ID,             /**< 设备控制 */
    ADMIND_UART_ID,            /**< 串口 */
    ADMIND_DISK_ID,            /**< 磁盘 */
    ADMIND_LOG_ID,             /**< 日志 */
    ADMIND_SEARCH_ID,          /**< 资料检索 */
    ADMIND_PTZ_ID,             /**< 云台操作 */
    ADMIND_STAT_ID,            /**< 状态控制 */
    ADMIND_CARD_ID,            /**< 卡号 */
    ADMIND_FILE_ID,            /**< 文件相关的操作 */
    ADMIND_UMON_ID,            /**< usb monitor */
    ADMIND_UPGRADE_ID,         /**< 系统升级 */
    ADMIND_MAX_ID,
};

/**
 * @enum
 * streamD的所有子模块ID的定义
 */
enum
{
    STREAMD_PLAY_ID = 0x1,  /**< 播放 */
    STREAMD_REC_ID  ,        /**< 录像 */
    STREAMD_LIVE_ID ,        /**< 现场 */
    STREAMD_BACK_ID ,        /**< 备份 */
    STREAMD_ALM_ID  ,        /**< 报警 */
    STREAMD_UM_ID   ,        /**< 用户管理 */
    STREAMD_NET_ID  ,        /**< 网络 */
    STREAMD_PARA_ID ,        /**< 参数 */
    STREAMD_DEV_ID,         /**< 设备控制 */
    STREAMD_UART_ID,        /**< 串口 */
    STREAMD_DISK_ID,        /**< 磁盘 */
    STREAMD_LOG_ID,         /**< 日志 */
    STREAMD_SEARCH_ID,      /**< 资料检索 */
    STREAMD_DOWNLOAD_ID,    /**< 下载 */
    STREAMD_NETLIVE_ID,     /**< 网络现场 */
    STREAMD_NETPLAY_ID,     /**< 远程回放*/
    STREAMD_DISPATCH_ID,     /**< 远程回放*/
    STREAMD_NETFILE_ID,    
    STREAMD_SPEECH_ID,      /**< 双向语音 */
    STREAMD_MAX_ID,
};

enum
{
    EVENTD_MAX_ID = 0,/*暂未使用*/
};

/**
 * @enum
 * taskD的所有子模块ID的定义
 */
enum
{
    TASKD_TIMER_ID = 0x1,    /**< 定时器 */
    TASKD_CTRL_ID ,
    TASKD_STATE_ID,
    TASKD_BSFP,
    TASKD_MAX_ID,
};

/**
 * @enum
 * DevLayer的所有子模块ID的定义
 * */
enum
{
    DEV_GUI_ID = 0x1,    /**< GUI */
    DEV_FP_ID,           /**< 前板 */
    DEV_BSCP_PRO,        /**< 协议 */
    DEV_BSCP_API,        /**< 协议应用 */
    DEV_CFG_ID,
    DEV_MAX_ID,
};

/* 错误码取负数 */
#define GET_ESTART(modId, subModId) (((modId|0x80)<<24)+((subModId)<<16))

/**
 * @enum
 * AdminD 各子模块的错误码的起始值
 */
enum
{
    ADMIND_PLAY_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PLAY_ID),               /**< 播放 */
    ADMIND_REC_ESTART = GET_ESTART(ADMIND_ID, ADMIND_REC_ID),                 /**< 录像 */
    ADMIND_LIVE_ESTART = GET_ESTART(ADMIND_ID, ADMIND_LIVE_ID),               /**< 现场 */
    ADMIND_BACK_ESTART = GET_ESTART(ADMIND_ID, ADMIND_BACK_ID),               /**< 备份 */
    ADMIND_ALM_ESTART = GET_ESTART(ADMIND_ID, ADMIND_ALM_ID),                 /**< 报警 */
    ADMIND_UM_ESTART = GET_ESTART(ADMIND_ID, ADMIND_UM_ID),                 /**< 用户管理 */
    ADMIND_NET_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NET_ID),                 /**< todo:范围太大，将被删除 */
    ADMIND_NETLIVE_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETLIVE_ID),         /**< 现场AV */
    ADMIND_NETDOWNLOAD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETDOWNLOAD_ID), /**< 资料下载 */
    ADMIND_NETPLAY_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETPLAY_ID),         /**< 远程回放 */
    ADMIND_NETUPLOAD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_NETUPLOAD_ID),        /**< 包括状态上传和事件上传 */
    ADMIND_PARA_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PARA_ID),               /**< 参数 */
    ADMIND_DEV_ESTART = GET_ESTART(ADMIND_ID, ADMIND_DEV_ID),                 /**< 设备控制 */
    ADMIND_UART_ESTART = GET_ESTART(ADMIND_ID, ADMIND_UART_ID),               /**< 串口 */
    ADMIND_DISK_ESTART = GET_ESTART(ADMIND_ID, ADMIND_DISK_ID),               /**< 磁盘 */
    ADMIND_LOG_ESTART = GET_ESTART(ADMIND_ID, ADMIND_LOG_ID),                 /**< 日志 */
    ADMIND_SEARCH_ESTART = GET_ESTART(ADMIND_ID, ADMIND_SEARCH_ID),           /**< 资料检索 */
    ADMIND_PTZ_ESTART = GET_ESTART(ADMIND_ID, ADMIND_PTZ_ID),                 /**< 云台操作 */
    ADMIND_STAT_ESTART = GET_ESTART(ADMIND_ID, ADMIND_STAT_ID),               /**< 状态控制 */
    ADMIND_CARD_ESTART = GET_ESTART(ADMIND_ID, ADMIND_CARD_ID),               /**< 卡号 */
    ADMIND_FILE_EPATHNOTEXIST = GET_ESTART(ADMIND_ID, ADMIND_FILE_ID),
};

/**
 * @enum
 * streamD 各子模块的错误码的起始值
 */
enum
{
    STREAMD_PLAY_ESTART = GET_ESTART(STREAMD_ID, STREAMD_PLAY_ID),          /**< 播放 */
    STREAMD_REC_ESTART = GET_ESTART(STREAMD_ID, STREAMD_REC_ID),            /**< 录像 */
    STREAMD_LIVE_ESTART = GET_ESTART(STREAMD_ID, STREAMD_LIVE_ID),          /**< 现场 */
    STREAMD_BACK_ESTART = GET_ESTART(STREAMD_ID, STREAMD_BACK_ID),          /**< 备份 */
    STREAMD_ALM_ESTART = GET_ESTART(STREAMD_ID, STREAMD_ALM_ID),            /**< 报警 */
    STREAMD_NET_ESTART = GET_ESTART(STREAMD_ID, STREAMD_NET_ID),            /**< 网络 */
    STREAMD_PARA_ESTART = GET_ESTART(STREAMD_ID, STREAMD_PARA_ID),          /**< 参数 */
    STREAMD_DEV_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DEV_ID),            /**< 设备控制 */
    STREAMD_UART_ESTART = GET_ESTART(STREAMD_ID, STREAMD_UART_ID),          /**< 串口 */
    STREAMD_DISK_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DISK_ID),          /**< 磁盘 */
    STREAMD_LOG_ESTART = GET_ESTART(STREAMD_ID, STREAMD_LOG_ID),            /**< 日志 */
    STREAMD_SEARCH_ESTART = GET_ESTART(STREAMD_ID, STREAMD_SEARCH_ID),      /**< 资料检索 */
    STREAMD_DOWNLOAD_ESTART = GET_ESTART(STREAMD_ID, STREAMD_DOWNLOAD_ID),  /**< 下载 */
};

/**
 * @enum
 * taskD 各子模块的错误码的起始值
 */
enum
{
    TASKD_TIMER_ESTART = GET_ESTART(TASKD_ID, TASKD_TIMER_ID),    /**< 定时器 */
};

/**
 * @enum
 * DevLayer 各子模块的错误码的起始值
 */
enum
{
    DEV_GUI_ESTART = GET_ESTART(DEV_ID, DEV_GUI_ID),    /**< GUI */
    DEV_FP_ESTART  = GET_ESTART(DEV_ID, DEV_FP_ID),
    DEV_NET_ESTART = GET_ESTART(DEV_ID, DEV_BSCP_API),
    DEV_CFG_ESTART = GET_ESTART(DEV_ID, DEV_CFG_ID),
};

/* 通用的错误码 */
#define    APP_OK                            0
#define    APP_SUCCESS                       0
#define    APP_FAIL                        (-1)

/**
*需要与bscp错误号兼容,错误号参见BSCP.h
*/
#define BSCP_ERR(x) (x)
/**
 * @enum
 * AdminD 各子模块的错误码定义
 */
enum
{
    ADMIND_PLAY_EXXX = ADMIND_PLAY_ESTART,            /**< 播放 */

    ADMIND_REC_EXXX = ADMIND_REC_ESTART,              /**< 录像 */
    ADMIND_REC_EPOINTERNULL,                          /**< 添加或删除链表传入指针为空 */
    ADMIND_REC_EINITRECINFOMEMFAILD,                  /**< 分配记录录像信息内存失败 */
    ADMIND_REC_EPRESTARTRECREQNULL,                   /**< 准备录像获取传入信息失败 */
    ADMIND_REC_EPRESTOPRECREQNULL,                    /**< 停止录像获取传入信息失败 */
    ADMIND_REC_ECHANNELINFOMUTEXFAILD,                /**< 初始化保护通道信息信号量失败 */
    ADMIND_REC_ERECCTRLDEBUGFAILD,/**< 录像监控模块调试信息注册失败 */
    ADMIND_REC_EDATAINMEMINITFAILD,/**< 数据输入模块内存初始化失败 */
    ADMIND_REC_EDATAINTHREADFAILD, /**< 数据输入线程创建失败 */
    ADMIND_REC_ERECORDCTRLCOMDFAILD, /**< 命令错 */
    ADMIND_REC_ESTARTRECORDCOMDFAILD,/**< 录像命令错 */
    ADMIND_REC_ERECORDCONDITIONFAILD,/**< 录像条件不满足 */
    ADMIND_REC_ERECORDINPARAMFAILD, /**< 输入参数错误 */

    ADMIND_LIVE_EINPUTINVALID = ADMIND_LIVE_ESTART + 0x01,            /**< 现场 */
    ADMIND_LIVE_EPOINTERNULL ,
    ADMIND_LIVE_EINVALIDVOSTATE,
    ADMIND_LIVE_EUNSUPPORT ,
    ADMIND_LIVE_EPREIVEWFAILED,
    ADMIND_LIVE_EINPARAM,
    ADMIND_LIVE_EETGREATERTHANBT, /* 开始时间不能大于结束时间 */
    ADMIND_LIVE_EETEQUALTOBT,     /* 开始时间不能等于结束时间 */

    ADMIND_BACK_EXXX = ADMIND_BACK_ESTART,            /**< 备份 */
    ADMIND_BACK_EDISKFULL,							/**< 磁盘已满 */
    ADMIND_BACK_EFILESIZE,							/**< 写入备份文件的数据长度已超过定义的最大长度 */
    ADMIND_BACK_WRFAIL,								/**< 备份数据写入磁盘失败 */
    ADMIND_BACK_CANCELLED,							/**< 用户在备份过程中执行了取消操作 */

    ADMIND_ALM_EXXX = ADMIND_ALM_ESTART,              /**< 报警 */

    ADMIND_UM_EXXX = ADMIND_UM_ESTART,            /**< 用户管理 */
    ADMIND_UM_EAUTHFAILD,                              /**< 权限校验失败*/
    ADMIND_NET_EXXX = ADMIND_NET_ESTART,              /**< 网络,范围太大，将被删除 */

    ADMIND_NETLIVE_EXXX = ADMIND_NETLIVE_ESTART,             /**< 现场AV */

    ADMIND_NETDOWNLOAD_EXXX = ADMIND_NETDOWNLOAD_ESTART,     /**< 资料下载 */

    ADMIND_NETPLAY_EXXX = ADMIND_NETPLAY_ESTART,             /**< 远程回放 */

    ADMIND_NETUPLOAD_EXXX = ADMIND_NETUPLOAD_ESTART,         /**< 网络上传，包括状态上传和事件上传 */
    ADMIND_NETUPLOAD_EINUNINIT = ADMIND_NETUPLOAD_ESTART + 1,
    ADMIND_NETUPLOAD_EINGETNETCFG,
    ADMIND_NETUPLOAD_EINCREATESOCKET,
    ADMIND_NETUPLOAD_EINSOCKET,
    ADMIND_NETUPLOAD_EINSENDTO,
    ADMIND_NETUPLOAD_EINTRANSPORTMANNER,
    ADMIND_NETUPLOAD_EINPAYLOADADDR,
    ADMIND_NETUPLOAD_EINPAYLOADLEN,
    ADMIND_NETUPLOAD_EINCHECKPARAM,

    ADMIND_PARA_EXXX = ADMIND_PARA_ESTART,            /**< 参数 */
    ADMIND_PLAY_ESEARCHFAILD,
    ADMIND_PLAY_ESTARTFAILD,

    ADMIND_DEV_EXXX = ADMIND_DEV_ESTART,             /**< 设备控制 */

    ADMIND_UART_EXXX = ADMIND_UART_ESTART,            /**< 串口 */
    ADMIND_UART_EINITFAIL,/**< 初始化失败 */
    ADMIND_UART_EPORTNOTOPEN,/**< 串口没有打开 */
    ADMIND_UART_EPORTREADFAIL,/**< 读串口失败 */
    ADMIND_UART_EPORTWRITEFAIL,/**< 写串口失败 */
    ADMIND_UART_ELINKTYPENOIMPL,/**< 选定的链路类型没有实现 */
    ADMIND_UART_ESNOOPLINKTYPE,  /**< 选定的捕获（卡号捕获）链路类型错误 */
    ADMIND_UART_ESNOOPPROTOCOL,  /**< 选定的捕获（卡号捕获）协议错误 */
    

    ADMIND_DISK_EXXX = ADMIND_DISK_ESTART,            /**< 磁盘 */

    ADMIND_LOG_EXXX = ADMIND_LOG_ESTART,             /**< 日志 */

    ADMIND_SEARCH_EXXX = ADMIND_SEARCH_ESTART,          /**< 资料检索 */
    ADMIND_SEARCH_EEOF, /**< 到达文件的尾部 */
    ADMIND_SEARCH_EBOF, /**< 到达文件的开头 */
    ADMIND_SEARCH_EINVALIDHANDLE, /**< 无效的句柄 */
    ADMIND_SEARCH_ETEMPNA, /**< Service temporarily unavailable, try later */
    ADMIND_SEARCH_EINVALIDPARAM, /**< Invalid parameter(function call) */
    ADMIND_SEARCH_EPAGESIZETOOBIG, /**< Page size exceeds 50 */
    ADMIND_SEARCH_EFILESYSOPERATIONFAILD, /**< a call to a file system function failed */
    ADMIND_SEARCH_EOPENFAILD,/**< fsEventQueryOpen() failed */
    ADMIND_SEARCH_EFETCHFAILD,/**< fsEventFetch() failed */

    ADMIND_PTZ_EXXX = ADMIND_PTZ_ESTART,             /**< 云台操作 */
    ADMIND_PTZ_EINVALIDCHANNEL, /**< 通道索引超过上/下限 */
    ADMIND_PTZ_EBUSY,         /**< 云台正在运行, 新指令无法执行, 应该先停掉云台当前动作 */
    ADMIND_PTZ_EINVALIDPRESETIDX,/**< 预置位索引超过上/下限 */
    ADMIND_PTZ_EINVALIDPATHIDX,  /**< 巡航路径索引索引超过上/下限 */
    ADMIND_PTZ_EPATHEMPTY,/**< 给定巡航路径内没有Waypoint */
    ADMIND_PTZ_EPATHFULL,/**< 给定巡航路径内Waypoint数目已达最大值 */
    ADMIND_PTZ_EUNSUPPORTEDCMD,
    ADMIND_PTZ_EMODINITFAILED, /**< 模块初始化失败 */
    ADMIND_PTZ_EREINITFORBIDDEN,/**< 模块已经初始化, 不允许再次初始化 */
    ADMIND_PTZ_EUNINIT, /**< 没有初始化 */
    ADMIND_PTZ_EINVALIDDALPARAM, /**< 设备抽象层没有提供需要的参数 */
    ADMIND_PTZ_EPATHOVERFLOW,/**< 路径内的路点超过最大值, 路径无效 */
    ADMIND_PTZ_ECREATETHREADFAILED,
    ADMIND_PTZ_EBSCMDNOIMPL, /**< 底层没有实现该BSky 云台命令 */

    ADMIND_STAT_EXXX = ADMIND_STAT_ESTART,            /**< 状态控制 */

    ADMIND_CARD_EXXX = ADMIND_CARD_ESTART,            /**< 卡号 */
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
 * streamD 各子模块的错误码定义
 */
enum 
{
    STREAMD_PLAY_EXXX = STREAMD_PLAY_ESTART,  /**< 播放 */

    STREAMD_REC_EXXX = STREAMD_REC_ESTART,         /**< 录像 */

    STREAMD_LIVE_EXXX = STREAMD_LIVE_ESTART,        /**< 现场 */
    STREAMD_LIVE_ELIVESWITCHCHANNELFAILD = STREAMD_LIVE_ESTART + 1,

    STREAMD_BACK_EXXX = STREAMD_BACK_ESTART,        /**< 备份 */

    STREAMD_ALM_EXXX = STREAMD_ALM_ESTART,         /**< 报警 */

    STREAMD_NET_EXXX = STREAMD_NET_ESTART,         /**< 网络 */

    STREAMD_PARA_EXXX = STREAMD_PARA_ESTART,        /**< 参数 */

    STREAMD_DEV_EXXX = STREAMD_DEV_ESTART,         /**< 设备控制 */

    STREAMD_UART_EXXX = STREAMD_UART_ESTART,        /**< 串口 */

    STREAMD_DISK_EXXX = STREAMD_DISK_ESTART,        /**< 磁盘 */

    STREAMD_LOG_EXXX = STREAMD_LOG_ESTART,         /**< 日志 */

    STREAMD_SEARCH_EXXX = STREAMD_SEARCH_ESTART,      /**< 资料检索 */

    STREAMD_DOWNLOAD_EXXX = STREAMD_DOWNLOAD_ESTART,    /**< 下载 */
    STREAMD_DOWNLOAD_EOPENFAIL,
    STREAMD_DOWNLOAD_EDISKOPENFAIL,
    STREAMD_DOWNLOAD_EPARAM,
    STREAMD_DOWNLOAD_EFAIL,
};

/**
 * @enum
 * taskD 各子模块的错误码定义
 */
enum
{
    TASKD_TIMER_EXXX = TASKD_TIMER_ESTART,    /**< 定时器 */
    TASKD_TIMER_EUNINIT = TASKD_TIMER_ESTART + 1, /**< timer模块没有初始化 */
    TASKD_TIMER_EFULL,                            /**< 系统timers个数到达极限值, 暂时不能添加新的timer */
    TASKD_TIMER_EELAPSETOOBIG,                    /**< 超时值太大, 参考AT_LIMIT_ELAPSE*/
    TASKD_TIMER_EINVALIDPARAM,                    /**< 无效参数*/
    TASKD_TIMER_ECREATETHREADFAILED,
};
/**
 * @enum
 * DevLayer 各子模块的错误码定义
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
    DEV_CFG_EIPCONFLICT, /**<IP 冲突*/
};


/**@ enum ENetLiveError
 * 网络错误信息
 */
typedef enum
{
    ERR_STREAMD_NET_CONNECT_FAIL      = STREAMD_NET_ESTART,                     /**< 连接失败*/
    ERR_STREAMD_NET_RTP_ERR           = STREAMD_NET_ESTART + BSCP_ERR(0x0001),  /**< RTP申请错误*/
    ERR_STREAMD_NET_DISCONNECT        = STREAMD_NET_ESTART + BSCP_ERR(0x0002),  /**< 网络连接中断*/
    ERR_STREAMD_NET_SOCK_ERR          = STREAMD_NET_ESTART + BSCP_ERR(0x0003),  /**< 创建socket错误*/
    ERR_STREAMD_NET_TICKET_ERR        = STREAMD_NET_ESTART + BSCP_ERR(0x0004),  /**< 流漂错误*/
    ERR_STREAMD_NET_FILE_READ_ERR     = STREAMD_NET_ESTART + BSCP_ERR(0x0005),  /**< 文件读错误*/
    ERR_STREAMD_NET_PARAM_ERR         = STREAMD_NET_ESTART + BSCP_ERR(0x0006),  /**< 参数错误*/    
    ERR_STREAMD_NET_END_OF_FILE       = STREAMD_NET_ESTART + BSCP_ERR(0x0007),  /**< 到达文件结尾*/    
    ERR_STREAMD_NET_STATE             = STREAMD_NET_ESTART + BSCP_ERR(0x0008),  /**< 到达文件结尾*/    
    ERR_STREAMD_NET_FULL_ERR          = STREAMD_NET_ESTART + BSCP_ERR(0x0010),  /**< 流已满*/    
    ERR_STREAMD_NET_INVALID_STREAM_ID = STREAMD_NET_ESTART + BSCP_ERR(0x0011),  /**< 非法流标识*/
    ERR_STREAMD_NET_OPEN_ENCODER      = STREAMD_NET_ESTART + BSCP_ERR(0x0012),  /**< 编码器打开失败*/
    ERR_STREAMD_NET_FILE_OPEN_ERR     = STREAMD_NET_ESTART + BSCP_ERR(0x0013),  /**< 文件打开失败*/
    ERR_STREAMD_CHANNEL_DISABLE_ERR   = STREAMD_NET_ESTART + BSCP_ERR(0x0014),  /**< 通道禁用*/
    
} ENetError;


/**@ enum EUmError
 * 用户和组管理错误信息
 */
typedef enum
{
    ERR_ADMIND_AUTH_PARAM_ERROR          = ADMIND_UM_ESTART + BSCP_ERR(0x0006),    /**<参数错误*/
    ERR_ADMIND_AUTH_USER_NOT_EXIST       = ADMIND_UM_ESTART + BSCP_ERR(0x0201),    /**<用户不存在*/
    ERR_ADMIND_AUTH_DUP_USERNAME         = ADMIND_UM_ESTART + BSCP_ERR(0x0202),    /**<用户重名*/
    ERR_ADMIND_AUTH_USER_UP_LIMIT        = ADMIND_UM_ESTART + BSCP_ERR(0x0203),    /**<用户达到上限*/
    ERR_ADMIND_AUTH_PASSWD_ERROR         = ADMIND_UM_ESTART + BSCP_ERR(0x0204),    /**<用户密码错误*/
    ERR_ADMIND_AUTH_GROUP_UP_LIMIT       = ADMIND_UM_ESTART + BSCP_ERR(0x0205),    /**<用户组达到上限*/
    ERR_ADMIND_AUTH_GROUP_NOT_EXIST      = ADMIND_UM_ESTART + BSCP_ERR(0x0206),    /**<用户组不存在*/
    ERR_ADMIND_AUTH_LOGIN_UP_LIMIT       = ADMIND_UM_ESTART + BSCP_ERR(0x0207),    /**<登录达到上限*/
    ERR_ADMIND_AUTH_CAN_NOT_DEL_ADMIN    = ADMIND_UM_ESTART + BSCP_ERR(0x0208),    /**<不能删除超级管理员*/   
    ERR_ADMIND_AUTH_CAN_NOT_MODIFY_ADMIN = ADMIND_UM_ESTART + BSCP_ERR(0x0209),    /**<不能修改超级管理员信息*/        
    ERR_ADMIND_AUTH_CAN_NOT_DEL_USER      = ADMIND_UM_ESTART + BSCP_ERR(0x020a),    /**<不能删除已登录用户*/    
    ERR_ADMIND_AUTH_USER_GROUP_SAME_NAME = ADMIND_UM_ESTART + BSCP_ERR(0x020b),    /**<用户名不能是用户组名*/
    ERR_ADMIND_AUTH_PRIV_SET_FAIL        = ADMIND_UM_ESTART + BSCP_ERR(0x020c),    /**<权限设置错误*/   
    ERR_ADMIND_AUTH_INVALID_PWD_LEN      = ADMIND_UM_ESTART + BSCP_ERR(0x020d),    /**<密码设置长度错误*/        
    ERR_ADMIND_AUTH_PWD_DIFF             = ADMIND_UM_ESTART + BSCP_ERR(0x020e),    /**<原密码错误*/     
} EUmError;

/**@ enum EDevError
 * 设备抽象层错误号
 */
typedef enum
{
    ERR_DEV_CFG_PARAM_ERROR          = DEV_CFG_ESTART + BSCP_ERR(0x000c),    /**<参数错误*/    
} EDevError;

char* lcsysMod2str(unsigned int error);
char* lcsubMod2str(unsigned int error);
#endif /*_BSRERR_CODE_H*/

