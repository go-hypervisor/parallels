///////////////////////////////////////////////////////////////////////////////
///
/// PrlCommandsFlags.h
///
/// This file is the part of parallels public sdk library
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_COMMANDS_FLAGS_H__
#define __PARALLELS_API_COMMANDS_FLAGS_H__

/* Security level enumeration. Defines levels of security that
   can be used in client/server communications.
   Type Parameters
   PSL_LOW_SECURITY :     Plain TCP/IP (no encryption).
   PSL_NORMAL_SECURITY :  Most important data is sent and
                          received using SSL over TCP/IP (user
                          credentials during login, guest OS
                          clipboard, etc.) Other data is sent and
                          receive using plain TCP/IP with no
                          encryption.
   PSL_HIGH_SECURITY :    All of the data is sent and received
                          using SSL.                              */
typedef enum _PRL_SECURITY_LEVEL
{
	PSL_LOW_SECURITY    = 0,
	PSL_NORMAL_SECURITY = 1<<0,
	PSL_HIGH_SECURITY   = 1<<1

} PRL_SECURITY_LEVEL;
typedef PRL_SECURITY_LEVEL* PRL_SECURITY_LEVEL_PTR;

/*
 Common operations flags set. Please do not override values
*/
typedef enum _PRL_API_COMMAND_FLAGS
{
	/* Client connection security mode */
	PACF_NORMAL_SECURITY               = PSL_NORMAL_SECURITY,
	PACF_HIGH_SECURITY                 = PSL_HIGH_SECURITY,
	/* Session interactive mode */
	PACF_NON_INTERACTIVE_MODE          = 1<<2,
	/* Cancel long-term operation by session disconnect */
	PACF_CANCEL_TASK_ON_END_SESSION = 1<<3,
	/**
	 * Interval from here to PACF_LAST reserved for further
	 * purposes. Please do not override this interval values
	 * with own flags
	 */
	PACF_MAX                           = 10,
	PACF_LAST                          = 1<<PACF_MAX
} PRL_API_COMMAND_FLAGS;
typedef PRL_API_COMMAND_FLAGS* PRL_API_COMMAND_FLAGS_PTR;

/* PrlSrv_RegisterVmEx command flags set */
typedef enum _PRL_REGISTER_VM_FLAGS
{
	PRVF_REGENERATE_VM_UUID			= 1<<(PACF_MAX+1),
	PRVF_KEEP_OTHERS_PERMISSIONS	= 1<<(PACF_MAX+2),
	PRCF_FORCE						= 1<<(PACF_MAX+3),
	PRVF_REGENERATE_SRC_VM_UUID		= 1<<(PACF_MAX+4),
	PRVF_IGNORE_HA_CLUSTER_OBSOLETE = 1<<(PACF_MAX+5),
	PRCF_UNREG_PRESERVE			= 1<<(PACF_MAX+6),
	PRCF_DELAY_APPLYING_RESTRICTIONS	= 1<<(PACF_MAX+7),
} PRL_REGISTER_VM_FLAGS;
typedef PRL_REGISTER_VM_FLAGS* PRL_REGISTER_VM_FLAGS_PTR;

/* PrlVm_Pack/PrlVm_Unpack commands flags set */
typedef enum _PRL_PACKING_VM_FLAGS
{
	PPVF_RESERVED_1		= 1<<(PACF_MAX+1) // Must be 0
} PRL_PACKING_VM_FLAGS;
typedef PRL_PACKING_VM_FLAGS* PRL_PACKING_VM_FLAGS_PTR;

/* PrlVm_CloneEx command flags set */
/*
	PCVF_DETACH_EXTERNAL_VIRTUAL_HDD
		- to remove link to Virtual Hdd which located outside of VM.pvm directory from cloned vm configuration.
*/
typedef enum _PRL_CLONE_VM_FLAGS
{
	PCVF_CLONE_TO_TEMPLATE	 = 1<<(PACF_MAX+1),
	PCVF_CHANGE_SID		     = 1<<(PACF_MAX+2),
	PCVF_LINKED_CLONE        = 1<<(PACF_MAX+3),
	PCVF_IMPORT_BOOT_CAMP    = 1<<(PACF_MAX+4),
	PCVF_DETACH_EXTERNAL_VIRTUAL_HDD    = 1<<(PACF_MAX+5),
	PCVF_REGENERATE_SRC_VM_UUID	= 1<<(PACF_MAX+6),
	PCVF_FULL_CLONE_FROM_LINKED	= 1<<(PACF_MAX+7),
	PCVF_ESTIMATE_DISK_SPACE = 1<<(PACF_MAX+8),
} PRL_CLONE_VM_FLAGS;
typedef PRL_CLONE_VM_FLAGS* PRL_CLONE_VM_FLAGS_PTR;

/* PrlThirdPartyVmConvertParams_SetFlags/PrlThirdPartyVmConvertParams_GetFlags command flags set */
typedef enum _PRL_REGISTER_3PARTY_VM_FLAGS
{
	PR3F_ALLOW_UNKNOWN_OS	= 1<<(PACF_MAX+1),
	PR3F_CREATE_SHADOW_VM_OBSOLETE	= 1<<(PACF_MAX+2),
	PR3F_FORCE				= 1<<(PACF_MAX+3),
	PR3F_STAND_ALONE_DISK	= 1<<(PACF_MAX+4),
} PRL_REGISTER_3PARTY_VM_FLAGS;
typedef PRL_REGISTER_3PARTY_VM_FLAGS* PRL_REGISTER_3PARTY_VM_FLAGS_PTR;

/* PrlVmDev_ResizeImage command flags set */
typedef enum _PRL_RESIZE_IMAGE_FLAGS
{
	PRIF_RESIZE_LAST_PARTITION	= 1<<(PACF_MAX+1),
	PRIF_DISK_INFO		        = 1<<(PACF_MAX+2),
	PRIF_RESIZE_OFFLINE		= 1<<(PACF_MAX+3),
} PRL_RESIZE_IMAGE_FLAGS;
typedef PRL_RESIZE_IMAGE_FLAGS* PRL_RESIZE_IMAGE_FLAGS_PTR;

/* App execution result extraction moderators:
    PFD_STDOUT      : request stdout of executed in guest OS app
    PFD_STDERR      : request stderr of executed in guest OS app
*/
typedef enum _PRL_VM_EXEC_APP_FILE_DESCRIPTOR
{
	PFD_STDOUT				= 1<<(PACF_MAX+1),
	PFD_STDERR				= 1<<(PACF_MAX+2),
	PFD_STDIN				= 1<<(PACF_MAX+3),
	PFD_ALL					= (PFD_STDOUT | PFD_STDERR | PFD_STDIN)
} PRL_VM_EXEC_APP_FILE_DESCRIPTOR;
typedef PRL_VM_EXEC_APP_FILE_DESCRIPTOR* PRL_VM_EXEC_APP_FILE_DESCRIPTOR_PTR;

/* Run app in guest modes:
    PRPM_RUN_PROGRAM_AND_RETURN_IMMEDIATELY  : just run program in guest OS and do not wait result
    PRPM_RUN_PROGRAM_IN_SHELL  : run program via shell and in shell environment
    PRPM_RUN_PROGRAM_ENTER  : run shell in guest
*/
typedef enum _PRL_VM_EXEC_RUN_PROGRAM_MODES
{
	PRPM_RUN_PROGRAM_AND_RETURN_IMMEDIATELY		= 1<<(PACF_MAX+4),
	PRPM_RUN_PROGRAM_IN_SHELL			        = 1<<(PACF_MAX+5),
	PRPM_RUN_PROGRAM_ENTER				        = 1<<(PACF_MAX+6),
	PRPM_RUN_AS_CURRENT_USER			        = 1<<(PACF_MAX+7),
	PRPM_RUN_CONVERT_HOST_PATHS			        = 1<<(PACF_MAX+8),
} PRL_VM_EXEC_RUN_PROGRAM_MODES;
typedef PRL_VM_EXEC_RUN_PROGRAM_MODES* PRL_VM_EXEC_RUN_PROGRAM_MODES_PTR;

/* VM start mode:
    PSM_VM_START             : start VM
	PSM_VM_SAFE_START        : start VM in the safe mode
	PSM_VM_START_FOR_COMPACT : start VM only for compacting disk operation
*/
typedef enum _PRL_VM_START_MODE
{
	PSM_VM_START				= 1<<(PACF_MAX+1),
	PSM_VM_SAFE_START			= 1<<(PACF_MAX+2),
	PSM_VM_START_FOR_COMPACT	= 1<<(PACF_MAX+3),
	// PSM_VM_START_LAST_ITEM has to be equal the last mode
	PSM_VM_START_LAST_ITEM	= PSM_VM_START_FOR_COMPACT,
} PRL_VM_START_MODE;
typedef PRL_VM_START_MODE* PRL_VM_START_MODE_PTR;

/* VM normal-mode start flags
*/
typedef enum _PRL_VM_NORMAL_START_FLAGS
{
//	PNSF_VM_START_IGNORE_HA_CLUSTER          = 1<<(PACF_MAX+1), This flag is unused
	PNSF_VM_START_WAIT			= 1<<(PACF_MAX+2),
} PRL_VM_NORMAL_START_FLAGS;
typedef PRL_VM_NORMAL_START_FLAGS* PRL_VM_NORMAL_START_FLAGS_PTR;

/* Compact mode:
    PCM_COMPACT_WITH_HARD_DISKS_INFO : show question before compacting with size disks info
    PCM_HARD_DISKS_INFO              : just get disk info
	PCM_FULL_CLEAN_UP_VM             : compact all disks and delete all unneccessary files
	PCM_COMPACT_SHUTDOWN_VM          : shutdown running vm (w/o questions) before compact and start it after finish
*/
typedef enum _PRL_COMPACT_MODE
{
	PCM_COMPACT_WITH_HARD_DISKS_INFO	= 1 << (PACF_MAX+1),
	PCM_HARD_DISKS_INFO					= 1 << (PACF_MAX+2),
	PCM_FULL_CLEAN_UP_VM				= 1 << (PACF_MAX+3),
	PCM_COMPACT_SHUTDOWN_VM				= 1 << (PACF_MAX+4),
	PCM_COMPACT_RECLAIMED_FILES_ONLY	= 1 << (PACF_MAX+5),
} PRL_COMPACT_MODE;
typedef PRL_COMPACT_MODE* PRL_COMPACT_MODE_PTR;

/* Encryption operations:
Uses for PrlVm_Encrypt() / PrlVm_Decrypt operations
*/
typedef enum _PRL_ENCRYPTION_FLAGS
{
	PEF_CHECK_PRECONDITIONS_ONLY	= 1 << (PACF_MAX+1),
} PRL_ENCRYPTION_FLAGS;
typedef PRL_ENCRYPTION_FLAGS* PRL_ENCRYPTION_FLAGS_PTR;

/**
* Parallels Tools Utility command flags
*/
typedef enum _PRL_TOOLS_UTILITY_COMMAND_FLAG
{
       ///     @brief Flag is useless now, but placed here to show how and where it
       /// must be
       PTU_FLG_ZERO            = (1 << 0)
}
PRL_TOOLS_UTILITY_COMMAND_FLAG;
typedef PRL_TOOLS_UTILITY_COMMAND_FLAG* PRL_TOOLS_UTILITY_COMMAND_FLAG_PTR;

/** Parallels problem report flags functionality:
 *  PPRF_ADD_CLIENT_PART : specifies to add client information to problem report
 *  PPRF_ADD_SERVER_PART : specifies to add server information to problem report
 *  PPRF_DO_NOT_CREATE_HOST_SCREENSHOT : specifies do not create and add host screenshot to generating problem report
 *  PPRF_DETAILED_PROBLEM_REPORT : specifies to use detailed problem report as if VerboseLogEnabled flag was set
 */
typedef enum _PRL_PROBLEM_REPORT_FLAGS
{
	PPRF_ADD_CLIENT_PART				= 1 << (PACF_MAX+1),
	PPRF_ADD_SERVER_PART				= 1 << (PACF_MAX+2),
	PPRF_DO_NOT_CREATE_HOST_SCREENSHOT	= 1 << (PACF_MAX+3),
	PPRF_DO_NOT_CREATE_VM_SCREENSHOT    = 1 << (PACF_MAX+4),
	PPRF_DETAILED_PROBLEM_REPORT        = 1 << (PACF_MAX+5),
} PRL_PROBLEM_REPORT_FLAGS;
typedef PRL_PROBLEM_REPORT_FLAGS* PRL_PROBLEM_REPORT_FLAGS_PTR;

/** Parallels API initialization flags:
	* PrlApi_InitEx command flags set
	*  PAIF_USE_GRAPHIC_MODE : specifies create SDK session which has access to the graphic mode
 */
typedef enum _PRL_API_INIT_FLAGS
{
	PAIF_USE_GRAPHIC_MODE				=	1 << (PACF_MAX+1),
	PAIF_INIT_AS_APPSTORE_CLIENT		=	1 << (PACF_MAX+2), /* obsolete */
} PRL_API_INIT_FLAGS;
typedef PRL_API_INIT_FLAGS* PRL_API_INIT_FLAGS_PTR;

/* Virtual machine shutdown options.
 * PSF_FORCE : forcibly stop the virtual machine if shutdown timed out.
 * PSF_NOFORCE : do nothing if the virtual machine shutdown timed out.
 */
typedef enum _PRL_VM_STOP_FLAGS
{
        PSF_FORCE               = 1<<(PACF_MAX+1),
        PSF_NOFORCE             = 1<<(PACF_MAX+2),
} PRL_VM_STOP_FLAGS;

/* Install appliance options
 * PIAF_CANCEL : cancel appliance installation
 * PIAF_FORCE : do not cancel installation and begin a new one
 *              if the previous installation became corrupted outside.
 * PIAF_STOP : temporary stop appliance downloading
 */
typedef enum _PRL_INSTALL_APPLIANCE_FLAGS
{
	PIAF_CANCEL			= 1<<(PACF_MAX+1),
	PIAF_FORCE			= 1<<(PACF_MAX+2),
	PIAF_STOP			= 1<<(PACF_MAX+3),
} PRL_INSTALL_APPLIANCE_FLAGS;

/* Convert virtual disk
 * PCVD_CANCEL : cancel disk conversion
 * PCVD_TO_PLAIN_DISK : convert disk from expanding to plain disk
 * PCVD_TO_EXPANDING_DISK : convert disk from plain to expanding disk
 * PCVD_TO_SPLIT_DISK : convert disk from non-split to split disk
 * PCVD_TO_NON_SPLIT_DISK : convert disk from split to non-split disk
 * PCVD_MERGE_ALL_SNAPSHOTS : merge all disk snapshots
 */
typedef enum _PRL_CONVERT_VIRTUAL_DISK
{
	PCVD_CANCEL					= 1<<(PACF_MAX+1),
	PCVD_TO_PLAIN_DISK			= 1<<(PACF_MAX+2),
	PCVD_TO_EXPANDING_DISK		= 1<<(PACF_MAX+3),
	PCVD_TO_SPLIT_DISK			= 1<<(PACF_MAX+4),
	PCVD_TO_NON_SPLIT_DISK		= 1<<(PACF_MAX+5),
	PCVD_MERGE_ALL_SNAPSHOTS	= 1<<(PACF_MAX+6),
} PRL_CONVERT_VIRTUAL_DISK;

/**
 * Flags which determines peer client while login to dispatcher
 * and while attach to vm.
 * PCF_ORIGINAL_CLIENT and PCF_LIGHTWEIGHT_CLIENT are mutually exclusive.
 */
typedef enum _PRL_IO_CLIENT_FLAGS
{
	PCF_ORIGINAL_CLIENT    = 1<<(PACF_MAX+1), /** Client with all features */
	PCF_LIGHTWEIGHT_CLIENT = 1<<(PACF_MAX+2), /** Lightweight client (iPhone/iPad) which
												  does not subscribe on heavy packages */
	PCF_TRUSTED_CHANNEL    = 1<<(PACF_MAX+3), /** Login over trusted channel
 												  (no need in username/password)*/
	PCF_TERMINAL_CLIENT    = 1<<(PACF_MAX+4), /** Use terminal channel for connections */

} PRL_IO_CLIENT_FLAGS;

/* Store value by specified keys on server options.
 * PSV_CALC_BOOT_CAMP : calculate VM size with Boot Camp disks
 */
typedef enum _PRL_VM_STORE_VALUE_FLAGS
{
	PSV_CALC_BOOT_CAMP_SIZE		= 1<<(PACF_MAX+1),
} PRL_VM_STORE_VALUE_FLAGS;

/**
 * iSCSI storage management flags
 */
typedef enum _PRL_ISCSI_STORAGE_CMD_FLAGS
{
	PISCSI_STORAGE_CREATE		= 1<<(PACF_MAX+1), /** To create storage on register */
	PISCSI_STORAGE_REMOVE		= 1<<(PACF_MAX+2), /** To remove storage on unregister */
	PISCSI_STORAGE_MOUNT_RDONLY	= 1<<(PACF_MAX+3), /** To mount storage by read-only */
	PISCSI_STORAGE_REMOUNT		= 1<<(PACF_MAX+4), /** To remount storage */
	PISCSI_STORAGE_MOUNT		= 1<<(PACF_MAX+5), /** To mount storage on register */

} PRL_ISCSI_STORAGE_CMD_FLAGS;

/**
 * iSCSI storage filesystem type
 */
typedef enum _PRL_ISCSI_STORAGE_FSTYPE_FLAGS
{
	PISCSI_STORAGE_EXT3    = 1<<(PACF_MAX+1),
	PISCSI_STORAGE_EXT4    = 1<<(PACF_MAX+2),
	PISCSI_STORAGE_NTFS    = 1<<(PACF_MAX+3),

} PRL_ISCSI_STORAGE_FSTYPE_FLAGS;

/**
* PrlVm_GetSnapshotsTreeEx flags
*/
typedef enum _PRL_GET_SNAPSHOT_TREE_FLAGS
{
	PGST_FULL_SIZE_SCREENSHOTS   = 1<<(PACF_MAX+1), /* return screenshots in full size */
	PGST_WITHOUT_SCREENSHOTS   = 1<<(PACF_MAX+2), /* fast way to request snapshots tree */
} PRL_GET_SNAPSHOT_TREE_FLAGS;

/* VM snapshot creation flags set
   Type Parameters
   PCSF_DISK_ONLY - to snapshot hdd's only for running Vm
   PCSF_BACKUP - create snapshot for backup
*/
typedef enum _PRL_CREATE_SNAPSHOT_FLAGS
{
	PCSF_DISK_ONLY		= 1 << (PACF_MAX+1), // internal flag
	PCSF_BACKUP		= 1 << (PACF_MAX+2), // internal flag
} PRL_CREATE_SNAPSHOT_FLAGS;

/**
* PrlVm_SwitchSnapshotEx flags
*/
typedef enum _PRL_SWITCH_SNAPSHOT_FLAGS
{
	PSSF_SKIP_RESUME	= 1<<(PACF_MAX+1), /* skip resume stage for Vm in the
						    * running/paused state in the snapshot
						    */
} PRL_SWITCH_SNAPSHOT_FLAGS;

/**
* PrlVm_DeleteSnapshotEx flags
   PDSF_BACKUP - delete snapshot for backup
*/
typedef enum _PRL_DELETE_SNAPSHOT_FLAGS
{
	PDSF_SKIP_SPACE_CHECK   = 1<<(PACF_MAX+1), /* skip space check */
	PDSF_BACKUP		= 1 << (PACF_MAX+2), // internal flag
} PRL_DELETE_SNAPSHOT_FLAGS;

/**
* PrlVm_CommitEx flags
*/
typedef enum _PRL_VM_COMMIT_FLAGS
{
	PVCF_DESTROY_HDD_BUNDLE		= 1<<(PACF_MAX+1), /* specifies to destroy HDD bundle
							physically on hard disk remove operation */
	PVCF_WAIT_FOR_APPLY		= 1<<(PACF_MAX+2), /* wait for apply */
	PEVF_WAIT_FOR_APPLY		= PVCF_WAIT_FOR_APPLY, /* to provide compatibility */
	PVCF_DESTROY_HDD_BUNDLE_FORCE	= 1<<(PACF_MAX+3), /* destroy HDD bundle physically even if
							used in snapshots */
	PVCF_DETACH_HDD_BUNDLE		= 1<<(PACF_MAX+4),
	PVCF_RENAME_EXT_DISKS		= 1<<(PACF_MAX+5),
} PRL_VM_COMMIT_FLAGS;

/**
* Create image flags
*/
typedef enum _PRL_CREATE_DISK_IMAGE_FLAGS
{
	PCDIF_CREATE_FROM_LION_RECOVERY_PARTITION	= 1<<(PACF_MAX+1),	// create from lion recovery
} PRL_CREATE_DISK_IMAGE_FLAGS;
typedef PRL_CREATE_DISK_IMAGE_FLAGS* PRL_CREATE_DISK_IMAGE_FLAGS_PTR;

/**
* PrlVm_RegEx flags
*/
typedef enum _PRL_REGISTER_NEW_VM
{
	PRNVM_CREATE_FROM_LION_RECOVERY_PARTITION	= PCDIF_CREATE_FROM_LION_RECOVERY_PARTITION,
	PRNVM_ALLOW_TO_AUTO_DECREASE_HDD_SIZE		= 1<<(PACF_MAX+2),
} PRL_REGISTER_NEW_VM;
typedef PRL_REGISTER_NEW_VM* PRL_REGISTER_NEW_VM_PTR;

/* List operations:
Uses for PrlSrv_GetVmListEx operation
*/
typedef enum _PRL_GET_VM_LIST_FLAGS
{
	PGVLF_GET_ONLY_VM_OBSOLETE = 1 << (PACF_MAX+1),
	PGVLF_GET_ONLY_CT_OBSOLETE = 1 << (PACF_MAX+2),
	PGVLF_GET_ONLY_IDENTITY_INFO	= 1 << (PACF_MAX+3),
	PGVLF_GET_STATE_INFO		= 1 << (PACF_MAX+4),
} PRL_GET_VM_LIST_FLAGS;
typedef PRL_GET_VM_LIST_FLAGS* PRL_GET_VM_LIST_FLAGS_PTR;

/* Find VM operations:
*/
typedef enum _PRL_GET_VM_CONFIG_FLAGS
{
	PGVC_SEARCH_BY_UUID = 1 << (PACF_MAX+1),
	PGVC_SEARCH_BY_NAME = 1 << (PACF_MAX+2),
} PRL_GET_VM_CONFIG_FLAGS;
typedef PRL_GET_VM_CONFIG_FLAGS* PRL_GET_VM_CONFIG_FLAGS_PTR;

/* Update/Install license operations:
Uses for PrlSrv_UpdateLicenseEx operation
*/
typedef enum _PRL_UPDATE_LICENSE_FLAGS
{
	PUPLF_PROLONGATE_LICENSE = 1 << (PACF_MAX+1),
	PUPLF_KICK_TO_UDPATE_CURR_FILE_LICENSE = PUPLF_PROLONGATE_LICENSE, /* obsolete */
	PUPLF_ACTIVATE_PERMANENT_LICENSE_ONLINE = 1 << (PACF_MAX+2), /* obsolete since PD14 */
	PUPLF_ACTIVATE_PERMANENT_LICENSE_OFFLINE = 1 << (PACF_MAX+3), /* obsolete since PD15 */
	PUPLF_CHECK_KEY_ONLY										 = 1 << (PACF_MAX+4),
	PUPLF_DRY_RUN														 = PUPLF_CHECK_KEY_ONLY,
	PUPLF_DEACTIVATE_CURRENT_LICENSE         = 1 << (PACF_MAX+5),
	PUPLF_ACTIVATE_PRECACHED_KEY             = 1 << (PACF_MAX+6),
	PUPLF_STORE_PRECACHED_KEY                = 1 << (PACF_MAX+7),
	PUPLF_REMOVE_PRECACHED_KEY               = 1 << (PACF_MAX+8),
	PUPLF_DEACTIVATE_CURRENT_LICENSE_OFFLINE_ALLOWED = 1 << (PACF_MAX+9),
	PUPLF_CHECK_KEY_ONLY_VOLUME							 = 1 << (PACF_MAX+10),
	PUPLF_REGISTER_CURRENT_LICENSE					 = 1 << (PACF_MAX+11),
	PUPLF_ACTIVATE_TRIAL_LICENSE					 = 1 << (PACF_MAX+12),
	PUPLF_ACTIVATE_PERMANENT_LICENSE_ONLINE_IMMEDIATELY = 1 << (PACF_MAX+13), /* obsolete since PD14 */
	PUPLF_FORCE_ACTIVATE_UK = 1 << (PACF_MAX+14),
	PUPLF_CHECK_PERMANENT_LICENSE = 1 << (PACF_MAX+15),
	PUPLF_AUTO_ACTIVATE_BY_CODE = 1 << (PACF_MAX+16),
	PUPLF_INSTALL_LICENSE_OFFLINE = 1 << (PACF_MAX+17),

} PRL_UPDATE_LICENSE_FLAGS;
typedef PRL_UPDATE_LICENSE_FLAGS* PRL_UPDATE_LICENSE_FLAGS_PTR;

/**
* PrlSrv_ShutdownEx flags
*/
typedef enum _PRL_SRV_SHUTDOWN_FLAGS
{
	PSHF_FORCE_SHUTDOWN	= 1<<(PACF_MAX+1),	/* Allow shutdown with active users sessions and running vms */
	PSHF_DONT_WAIT_TO_COMPLETE = 1<<(PACF_MAX+2),	/* Send response immediately when shutdown started */
	PSHF_SUSPEND_VM_TO_PRAM_OBSOLETE = 1<<(PACF_MAX+3),
} PRL_SRV_SHUTDOWN_FLAGS;
typedef PRL_SRV_SHUTDOWN_FLAGS* PRL_SRV_SHUTDOWN_FLAGS_PTR;

/**
* PrlVmGuest_SetUserPasswd flags
*/
typedef enum _PRL_SET_USERPASSWD_FLAGS
{
	PSPF_PASSWD_CRYPTED	= 1 <<(PACF_MAX+1)		/* passwords are encrypted */
} PRL_SET_USERPASSWD_FLAGS;
typedef PRL_SET_USERPASSWD_FLAGS* PRL_SET_USERPASSWD_FLAGS_PTR;

/*
 PrlVm_GetStatisticsEx flags
*/
typedef enum _PRL_VM_STATISTICS_FLAGS
{
	PVMSF_HOST_DISK_SPACE_USAGE_ONLY		= 1 << (PACF_MAX+1),
	PVMSF_GUEST_OS_INFORMATION_ONLY			= 1 << (PACF_MAX+2),
} PRL_VM_STATISTICS_FLAGS;
typedef PRL_VM_STATISTICS_FLAGS* PRL_VM_STATISTICS_FLAGS_PTR;

/*
 * PrlSrv_LoginLocal flags
 */
typedef enum _PRL_LOGIN_LOCAL_FLAGS
{
	PLLF_LOGIN_WITH_DELAYED_CONNECTION		= 1 << (PACF_MAX+1),
} PRL_LOGIN_LOCAL_FLAGS;
typedef PRL_LOGIN_LOCAL_FLAGS* PRL_LOGIN_LOCAL_FLAGS_PTR;

/*
 * PrlDispCfg_SetProxyConnectionCreds flags
 */
typedef enum _PRL_SET_PROXY_CONNECTION_FLAGS
{
	PSPCF_DO_NOT_CLEAN_CREDS		= 1 << (PACF_MAX+1),
	PSPCF_REUSE_AVAILABLE_CREDS		= 1 << (PACF_MAX+2),
	PSPCF_CLEANUP_CREDS				= 1 << (PACF_MAX+3),
	PSPCF_USE_DEPLOY_ID				= 1 << (PACF_MAX+4),
	PSPCF_REGISTER_HOST_ONLY		= 1 << (PACF_MAX+5),
	PSPCF_USE_FACEBOOK_TOKEN		= 1 << (PACF_MAX+6),
	PSPCF_USE_GOOGLE_TOKEN			= 1 << (PACF_MAX+7),
	PSPCF_USE_APPLE_TOKEN			= 1 << (PACF_MAX+8),
} PRL_SET_PROXY_CONNECTION_FLAGS;
typedef PRL_SET_PROXY_CONNECTION_FLAGS* PRL_SET_PROXY_CONNECTION_FLAGS_PTR;

/*
 * PrlTool_SendDataAsync flags
 */
typedef enum _PRL_TOOL_SEND_DATA_FLAGS
{
	PTLSDF_FREE_DATA_BUFF			= 1 << (PACF_MAX+1), /* Do not make data buffer copy, free buffer after send.
														    Passed buffer must be allocated via PrlTool_AllocBuffer. */
} PRL_TOOL_SEND_DATA_FLAGS;
typedef PRL_TOOL_SEND_DATA_FLAGS* PRL_TOOL_SEND_DATA_FLAGS_PTR;

#endif // __PARALLELS_API_COMMANDS_FLAGS_H__
