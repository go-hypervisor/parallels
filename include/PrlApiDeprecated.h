///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlApiDeprecated.h
///
/// This file is the part of parallels public SDK library.
///
/// Methods declared in this file are deprecated. If it possible do not use it
/// in your code.
///
/// @author sandro
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////
#if defined(PRL_NO_DEPRECATED) && !defined(__PARALLELS_API_DEPRECATED_H__)
#define __PARALLELS_API_DEPRECATED_H__
#endif //defined(PRL_NO_DEPRECATED)

#ifndef __PARALLELS_API_DEPRECATED_H__
#define __PARALLELS_API_DEPRECATED_H__


#include "PrlIOStructs.h"

#include "PrlApiDeprCore.h"
#include "PrlDisk.h"

typedef enum _PRL_CPU_FEATURES_EX
{
	PCFE_FEATURES = 0,
	PCFE_EXT_FEATURES = 1,
	PCFE_EXT_00000007_EBX = 2,
	PCFE_EXT_80000001_ECX = 3,
	PCFE_EXT_80000001_EDX = 4,
	PCFE_EXT_80000007_EDX = 5,
	PCFE_EXT_80000008_EAX = 6,
	PCFE_EXT_0000000D_EAX = 7,
	PCFE_EXT_00000006_EAX = 8,

	PCFE_MAX // have to be the last.
} PRL_CPU_FEATURES_EX;

typedef struct _PRL_CPU_FEATURES_MASK
{
	// @brief mask of processor features
	PRL_UINT32 nFEATURES_MASK;
	// @brief mask of extended processor features
	PRL_UINT32 nEXT_FEATURES_MASK;
	// @brief 00000007 ebx mask
	PRL_UINT32 nEXT_00000007_EBX_MASK;
	// @brief 80000001 ecx mask
	PRL_UINT32 nEXT_80000001_ECX_MASK;
	// @brief 80000001 edx mask
	PRL_UINT32 nEXT_80000001_EDX_MASK;
	// @brief 80000007 edx mask
	PRL_UINT32 nEXT_80000007_EDX_MASK;
	// @brief 80000008 eax
	PRL_UINT32 nEXT_80000008_EAX;
	// @brief 0000000D eax
	PRL_UINT32 nEXT_0000000D_EAX_MASK;
	// @brief 00000006 eax
	PRL_UINT32 nEXT_00000006_EAX_MASK;
	// @brief masks is valid
	PRL_UINT32 bIsValid;
} __attribute__((packed)) PRL_CPU_FEATURES_MASK ;
typedef PRL_CPU_FEATURES_MASK* PRL_CPU_FEATURES_MASK_PTR;
typedef const PRL_CPU_FEATURES_MASK* PRL_CONST_CPU_FEATURES_MASK_PTR;

typedef struct _PRL_CPU_FEATURES
{
	// @brief processor features
	PRL_UINT32 nFEATURES;
	// @brief extended processor features
	PRL_UINT32 nEXT_FEATURES;
	// @brief 00000007 ebx
	PRL_UINT32 nEXT_00000007_EBX;
	// @brief 80000001 ecx
	PRL_UINT32 nEXT_80000001_ECX;
	// @brief 80000001 edx
	PRL_UINT32 nEXT_80000001_EDX;
	// @brief 80000007 edx
	PRL_UINT32 nEXT_80000007_EDX;
	// @brief 80000008 eax
	PRL_UINT32 nEXT_80000008_EAX;
	// @brief 0000000D eax
	PRL_UINT32 nEXT_0000000D_EAX;
	// @brief 00000006 eax
	PRL_UINT32 nEXT_00000006_EAX;
} __attribute__((packed)) PRL_CPU_FEATURES ;
typedef PRL_CPU_FEATURES* PRL_CPU_FEATURES_PTR;

typedef enum _PRL_IOLIMIT_TYPE
{
	PRL_IOLIMIT_BS  = 1,
} PRL_IOLIMIT_TYPE;

typedef struct _PRL_IOLIMIT_DATA
{
	PRL_UINT32 value;
	PRL_IOLIMIT_TYPE type;
} __attribute__((packed)) PRL_IOLIMIT_DATA ;
typedef PRL_IOLIMIT_DATA* PRL_IOLIMIT_DATA_PTR;
typedef const PRL_IOLIMIT_DATA* PRL_CONST_IOLIMIT_DATA_PTR;

typedef enum _PRL_CPULIMIT_TYPE
{
	PRL_CPULIMIT_PERCENTS100= 1, // cpulimit 0-100%
	PRL_CPULIMIT_MHZ        = 2,
	PRL_CPULIMIT_PERCENTS   = 3, // cpulimit 0-100 * nCpu%
	PRL_CPULIMIT_PERCENTS_TO_MHZ= 4, // The limit in % convert to Mhz
} PRL_CPULIMIT_TYPE;

typedef struct _PRL_CPULIMIT_DATA
{
	PRL_UINT32 value;
	PRL_CPULIMIT_TYPE type;
} __attribute__((packed)) PRL_CPULIMIT_DATA ;
typedef PRL_CPULIMIT_DATA* PRL_CPULIMIT_DATA_PTR;
typedef const PRL_CPULIMIT_DATA* PRL_CONST_CPULIMIT_DATA_PTR;

/**
 * Firewall policy
 */
typedef enum _PRL_FIREWALL_POLICY
{
	PFP_ACCEPT		= 0,
	PFP_DENY		= 1,
} PRL_FIREWALL_POLICY;
typedef PRL_FIREWALL_POLICY* PRL_FIREWALL_POLICY_PTR;

/**
 * Firewall direction
 */
typedef enum _PRL_FIREWALL_DIRECTION
{
	PFD_INCOMING		= 0,
	PFD_OUTGOING		= 1,
} PRL_FIREWALL_DIRECTION;
typedef PRL_FIREWALL_DIRECTION* PRL_FIREWALL_DIRECTION_PTR;

typedef enum _PRL_CT_RESOURCE
{
	PCR_KMEMSIZE	= 1,
	PCR_LOCKEDPAGES	= 2,
	PCR_PRIVVMPAGES	= 3,
	PCR_SHMPAGES	= 4,
	PCR_NUMPROC	= 5,
	PCR_PHYSPAGES	= 6,
	PCR_VMGUARPAGES	= 7,
	PCR_OOMGUARPAGES= 8,
	PCR_NUMTCPSOCK	= 9,
	PCR_NUMFLOCK	= 10,
	PCR_NUMPTY	= 11,
	PCR_NUMSIGINFO	= 12,
	PCR_TCPSNDBUF	= 13,
	PCR_TCPRCVBUF	= 14,
	PCR_OTHERSOCKBUF= 15,
	PCR_DGRAMRCVBUF	= 16,
	PCR_NUMOTHERSOCK= 17,
	PCR_DCACHESIZE	= 18,
	PCR_NUMFILE	= 19,
	PCR_NUMIPTENT	= 20,
	PCR_SWAPPAGES	= 21,

	PCR_QUOTAUGIDLIMIT = 22,

	PCR_LAST	= PCR_QUOTAUGIDLIMIT,

} PRL_CT_RESOURCE;

/**
 * Container templates types
 */
typedef enum _PRL_CT_TEMPLATE_TYPE
{
	PCT_TYPE_EZ_OS = 0,
	PCT_TYPE_EZ_APP = 1,
} PRL_CT_TEMPLATE_TYPE;
typedef PRL_CT_TEMPLATE_TYPE* PRL_CT_TEMPLATE_TYPE_PTR;


/**
 * Netfilter modes list
 */
typedef enum _PRL_NETFILTER_MODE
{
	PCNM_NOT_SET	= 0,
	PCNM_DISABLED	= 1,
	PCNM_STATELESS	= 2,
	PCNM_STATEFUL	= 3,
	PCNM_FULL		= 4,
} PRL_NETFILTER_MODE;
typedef PRL_NETFILTER_MODE* PRL_NETFILTER_MODE_PTR;

/* VM backup functionality flags set
   Type Parameters
   PBSL_LOW_SECURITY
   PBSL_NORMAL_SECURITY
   PBSL_HIGH_SECURITY
   PBT_FULL		: full backup
   PBT_INCREMENTAL	: incremental backup
   PBT_DIFFERENTAL	: differental backup
   PBT_RESTORE_TO_COPY	: change Vm name/uuid/MAC address on restore
   PBT_UNCOMPRESSED	: uncompressed backup
   PBT_VM		: for virtual mashines
   PBT_CT		: for containers
   PBT_BACKUP_ID: get information about a certain backup
   PBT_CHAIN	: get information about the whole backup chain for a certain backup
*/
typedef enum _PRL_VM_BACKUP_FLAGS
{
	PBSL_LOW_SECURITY	  = PSL_LOW_SECURITY,
	PBSL_NORMAL_SECURITY  = PACF_NORMAL_SECURITY,
	PBSL_HIGH_SECURITY	  = PACF_HIGH_SECURITY,
	PBT_FULL		      = 1<<(PACF_MAX+1),
	PBT_INCREMENTAL		  = 1<<(PACF_MAX+2),
	PBT_DIFFERENTIAL		  = 1<<(PACF_MAX+3),
	PBT_RESTORE_TO_COPY	= 1<<(PACF_MAX+4),
	PBT_IGNORE_NOT_EXISTS	= 1<<(PACF_MAX+5),
	PBT_UNCOMPRESSED	= 1<<(PACF_MAX+6),
	PBT_VM			= 1<<(PACF_MAX+7),
	PBT_CT			= 1<<(PACF_MAX+8),
	PBT_BACKUP_ID	= 1<<(PACF_MAX+9),
	PBT_CHAIN		= 1<<(PACF_MAX+10),
} PRL_VM_BACKUP_FLAGS;

typedef enum _PRL_VM_TYPE
{
	PVT_VM		= 0,
	PVT_CT		= 1,
} PRL_VM_TYPE;
typedef PRL_VM_TYPE* PRL_VM_TYPE_PTR;

typedef struct _PRL_GET_VM_CONFIG_PARAM_DATA
{
	int reserved;
	PRL_CONST_STR sConfigSample;
	PRL_UINT32 nOsVersion;
} __attribute__((packed)) PRL_GET_VM_CONFIG_PARAM_DATA ;
typedef const PRL_GET_VM_CONFIG_PARAM_DATA* PRL_CONST_GET_VM_CONFIG_PARAM_DATA_PTR;


/**
 * Client can use this method to understand where it executed: on HostOS or on GuestOS (inside VM ).
 *
 * @param bool result: 1 - on GuestOS (inside VM) / 0 - on HostOS
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid (NULL) pointer to result
 * PRL_ERR_SUCCESS					- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_IsGuestOs, (
					 PRL_BOOL_PTR result
					 ) );

/**
 * Client can use this method to set user profile XML representation to user profile SDK object
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_USER_PROFILE handle or non valid (NULL) pointer to user profile XML
 * representation string was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlUsrCfg_FromString, (
		PRL_HANDLE hUsrCfg,
		PRL_CONST_STR sUsrCfg
		) );


/**
 * Client can use this method to get user profile XML representation string from user profile SDK object
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_DISP_CONFIG handle or non valid (NULL) pointer to storing result was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlUsrCfg_ToString, (
		PRL_HANDLE hUsrCfg,
		PRL_VOID_PTR_PTR pUsrCfg
		) );

/**
 * Add information about proxy and credentials to access to the specifid
 * proxy server.
 * Parameters
 *  hUserProfile :        A handle of type PHT_USER_PROFILE
 *                        identifying the user.
 *  sProxyHost :          proxy IP or host name (a UTF\-8 encoded,
 *                        null\-terminated string).
 *  nProxyPort :          proxy port
 *  sProxyUserLogin :     username to authenticate on proxy server
 *                        (a UTF\-8 encoded, null\-terminated string).
 *  sProxyUserPasswd :    password to authenticate on proxy server
 *                        (a UTF\-8 encoded, null\-terminated string).
 *  nReserved :           Reserved for future use. Should be 0.
 * Returns
 * PRL_RESULT. Possible values:
 *
 * PRL_ERR_INVALID_ARG - invalid handle or null pointer was
 * passed.
 *
 * PRL_ERR_SUCCESS - function completed successfully.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlUsrCfg_AddProxy, (
		PRL_HANDLE hUserProfile,
		PRL_CONST_STR sProxyHost,
		PRL_UINT32 nProxyPort,
		PRL_CONST_STR sProxyUserLogin,
		PRL_CONST_STR sProxyUserPasswd,
		PRL_INT32 nReserved
		) );

/**
 * Client can use this method to set dispatcher configuration to dispatcher config handle
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_DISP_CONFIG handle or non valid (NULL) pointer to disp config XML
 * representation string was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_FromString, (
		PRL_HANDLE hDispCfg,
		PRL_CONST_STR sDispCfg
		) );


/**
 * Client can use this method to get dispatcher configuration from disp config handle as XML string
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_DISP_CONFIG handle or non valid (NULL) pointer to storing result was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_ToString, (
		PRL_HANDLE hDispCfg,
		PRL_VOID_PTR_PTR pDispCfg
		) );

/**
 * Client can use this method to set VM configuration to VM handle
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_VIRTUAL_MACHINE handle or non valid (NULL) pointer to VM XML
 * representation string was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_FromString, (
		PRL_HANDLE hVm,
		PRL_CONST_STR vm_config
		) );


/**
 * Client can use this method to get VM configuration from VM handle as XML string
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_VIRTUAL_MACHINE handle or non valid (NULL) pointer to storing result was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_ToString, (
		PRL_HANDLE hVm,
		PRL_VOID_PTR_PTR vm_config
		) );

/**
 * This method initializing VM device from XML string.
 * This is temporary method that must be removed at Release stage.
 *
 * @param valid PRL_HANDLE describing the VM device
 * @param XML string representation of VM device
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid virtual device handle or non valid (NULL) pointer to specifying device string
 * representation or non valid virtual device XML representation
 * or handle of already removed VM device was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_FromString, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sXml
		) );


/**
 * This method returns XML string representation of VM device.
 * This is temporary method that must be removed at Release stage.
 *
 * @param valid PRL_HANDLE describing the VM device
 * @param XML string representation of VM device
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid virtual device handle or non valid (NULL) pointer to storing result
 * or handle of already removed VM device was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_ToString, (
		PRL_HANDLE hVmDev,
		PRL_VOID_PTR_PTR sXml
		) );


/**
* Gets VM device information from server .
*
* @param valid PRL_HANDLE describing the VM device
* @param pointer to storing result
* @return PRL_RESULT. Possible values:
* PRL_ERR_INVALID_ARG				- non valid virtual device handle
* PRL_ERR_UNINITIALIZED				- unexpected error: uninitialized with server connection or not bint to VM
* virtual device object
* PRL_ERR_SUCCESS						- operation successfully completed
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVmDev_UpdateInfo, (
				PRL_HANDLE hServer,
				PRL_HANDLE hVmInputDev
				) );

/**
 * Get param token by index
 *
 * @param valid PRL_HANDLE
 * @param index of parameter
 * @param pointer to a command specific object that contains parameter value
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_RESULT handle or non valid (NULL) pointer for storing result or non valid
 * index was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlResult_GetParamToken, (
				 PRL_HANDLE hResult,
				 PRL_UINT32 index,
				 PRL_VOID_PTR_PTR data_ptr
				 ) );


/**
 * Get error description. Returns XML representation of error which must be parsed by CVmEvent instance.
 * String buffer allocating by strdup() so method caller must call free() for received result after it usage.
 * This method must be eliminated in Release stage.
 *
 * @param valid PRL_HANDLE describing result
 * @param pointer for getting result
 * @return PRL_ERR_SUCCESS if the method succeeds
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlResult_GetError, (
				 PRL_HANDLE hResult,
				 PRL_VOID_PTR_PTR data_ptr
				 ) );


/**
 * Client can use this method to set license XML representation to license SDK object
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML license string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_LICENSE handle or non valid (NULL) pointer to license XML
 * representation string was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlLic_FromString, (
		PRL_HANDLE hLicense,
		PRL_CONST_STR sLic
		) );

/**
 * Client can use this method to get license XML representation string from License SDK object
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE
 * @param XML license representation  string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_LICENSE handle or non valid (NULL) pointer to storing result was passed
 * PRL_ERR_SUCCESS						- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlLic_ToString, (
					 PRL_HANDLE hLicense,
					 PRL_VOID_PTR_PTR pLicStr
					 ) );


/**
 * Creates a new handle of type PHT_PHT_LICENSE.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlLic_Create, (
					 PRL_HANDLE_PTR phLic
					 ) );

/**
* Client can use this method to get LoginResponse XML representation string from LoginResponse SDK object
* This method must be eliminated at Release stage
*
* @param valid PRL_HANDLE
* @param XML LoginResponse representation  string
* @return PRL_RESULT. Possible values:
* PRL_ERR_INVALID_ARG				- non valid PHT_LOGIN_RESPONSE handle or non valid (NULL) pointer to storing result was passed
* PRL_ERR_SUCCESS						- operation successfully completed
*/

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlLoginResponse_ToString, (
	PRL_HANDLE hLoginResp,
	PRL_VOID_PTR_PTR pLoginRespStr
	) );



/**
* This is no longer supported. Use PrlDevDisplay_IsSlidingMouseEnabled()
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVm_GetVirtDevInfo, (
		PRL_HANDLE hVm,
		PRL_UINT32 nFlags
		) );

/**
* This is no longer supported. Use PrlDevDisplay_IsSlidingMouseEnabled()
*/
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmVirtDevInfo_GetUsbMouseState, (
		PRL_HANDLE handle,
		PRL_VOID_PTR pVmUsbMouseState
		) );


/**
Update any tools section in VM config

Parameters
handle : valid PRL_HANDLE describing the virtual machine

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
* @param valid PRL_HANDLE
* @param XML subsection of Tools section in VmConfiguration
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was passed
PRL_ERR_UNINITIALIZED - unexpected error: uninitialized with server connection or non identified VM object
*/
PRL_ASYNC_SRV_METHOD_DECL(  PARALLELS_API_VER_2,
							PrlVm_UpdateToolsSection, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sToolsSection
					  ) );


/**
 * Client can use this method to set response XML representation (@see CProtoCommandDspWsResponse) to result handle
 * This method must be eliminated at Release stage
 *
 * @param valid PRL_HANDLE of PHT_RESULT type
 * @param XML configuration string
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG				- non valid PHT_RESULT handle or non valid (NULL) pointer to XML representation string (or XML representation
 *									  in wrong format - expecting correct CVmEvent representation contains CProtoCommandDspWsResponse proto command
 *									  class data) was passed
 * PRL_ERR_SUCCESS					- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlResult_FromString, (
		PRL_HANDLE hResult,
		PRL_CONST_STR sResult
		) );

/**
 * Get "Restrict Editing" status for specified VM config
 *
 * @param valid PRL_HANDLE
 * @param restriction state
 *
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG           - non valid handle was specified
 * PRL_ERR_SUCCESS               - operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_IsEditRestricted, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbRestricted
		) );

/**
 * Set "Restrict Editing" password for specified VM config
 *
 * @param valid PRL_HANDLE
 * @param current password, NULL if VM is not restricted
 * @param new password, NULL to remove restriction
 *
 * @return PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG           - non valid handle was specified or current
 *                                 password was specified for not restricted VM
 * PRL_ERR_ACCESS_TO_VM_DENIED   - wrong current password is used
 * PRL_ERR_SUCCESS               - operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetEditRestriction, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sOldPass,
		PRL_CONST_STR sNewPass
		) );

/**
Sets Virtual Machine CPU VTx support enabling sign.

Parameters
handle : valid PRL_HANDLE describing the virtual machine
unnamed_param : setting CPU VTx support enabling sign

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was specified
PRL_ERR_SUCCESS - operation successfully completed
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_SetCpuVtxEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bVmCpuVtxEnabled
		) );


/**
@brief	(PrlApi deprecated) command that intended for
		sending any tools information from client to host.

		All information should be stored in the buffer.
		This procedure just transferring the buffer no matter
		what kind of information is in it.

Parameters
@param [in] hVm		- valid PRL_HANDLE of PHT_VIRTUAL_MACHINE type - handle of VM where the command must be sent
@param [in] command	- number that identifies protocol (sender-receiver pair)
@param [in] data	- pointer to the transferring data buffer
@param [in] dataSize- size of the transferring data

Returns
PRL_RESULT.

Possible values:
PRL_ERR_INVALID_ARG - non valid VM device
PRL_INVALID_HANDLE - invalid handle
PRL_UNINITIALIZED
PRL_ERR_FAILURE
or PRL_ERR_SUCCESS if success.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVm_SendToolsGeneralCommand, (
	PRL_HANDLE			hVm,
	PRL_UINT32			command,
	PRL_CONST_VOID_PTR	data,
	PRL_UINT32			dataSize
	)) ;


/**
Performs begin start hard disks conversions to the server side. it can be catched with async result
processing callback (@see PrlSrv_RegEventHandler).

Parameters
handle : valid PRL_HANDLE of PHT_SERVER type
handle : valid PRL_HANDLE of PHT_STRINGS_LIST type with list of hard disks paths

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_SERVER handle	or non valid PHT_STRINGS_LIST handle was passed
PRL_ERR_SUCCESS - task was started successfully
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_StartConvertHdd, (
					  PRL_HANDLE hServer,
					  PRL_HANDLE hStringsList
					  ) );

/**
Performs retrieving dispatcher runtime information command to server.

Parameters
handle : valid PRL_HANDLE of PHT_SERVER type

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_SERVER handle was passed
PRL_ERR_ACCESS_TOKEN_INVALID - current user session seems to be not valid to perform SMC command
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_SmcGetRuntimeInfo, (
		PRL_HANDLE hServer
		) );


/* Generates VM answer event on some VM question.
   Parameters
   handle :         A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   unnamed_param :  buffer for storing result answer code
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   PHT_VIRTUAL_MACHINE handle or non valid (null) pointer to
   buffer was specified PRL_ERR_OUT_OF_MEMORY - not enough
   memory to instantiate VM event object PRL_ERR_SUCCESS -
   operation successfully completed                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_CreateAnswerEvent, (
		PRL_HANDLE hVm,
		PRL_HANDLE_PTR phEvent,
		PRL_RESULT nAnswer
		) );

// [TIS support] --------------------------------------------------------------

/**
Returns handle on TIS emitter associated with specified uid

Parameters:
hVm : [in] handle to VM
sUid : [in] string with identifier
phRecord : [out] handle on TIS emitter

TIS emitter can notify about changes of associated record.

Returns:
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - when hVm is bad handle or sUid or phRecord is
					  bad pointers
PRL_ERR_UNINITIALIZED - when Desktop object is not accessible
PRL_ERR_OUT_OF_MEMORY - when failed to allocate handle
PRL_ERR_SUCCESS
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_TisGetEmitter, (
	PRL_HANDLE hVm,
	PRL_CONST_STR sUid,
	PRL_HANDLE_PTR phEmitter
	) );

/**
Type of callback associated with some record.

Parameters:
pCallbackArg : [in] some user-defined callback argument
hRecord : [in] handle on PHT_TIS_RECORD that contains associated record or 0.
			   This handle must be closed in the callback if not 0!
uFields : [in] bit-mask of PRL_TIS_RECORD_FIELD values.
			   If PTIS_RECORD_REMOVED bit is set, record was removed.
			   If PTIS_RECORD_CLEARED bit is set, record was removed because of
			   entire TIS database was erased (cleared).
			   PTIS_RECORD_CLEARED can be set only with PTIS_RECORD_REMOVED.
*/
typedef PRL_METHOD_PTR( PRL_TIS_RECORD_CALLBACK_PTR ) (
		PRL_VOID_PTR pCallbackArg,
		PRL_HANDLE hRecord,
		PRL_UINT32 uFields
		);

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisEmitter_GetUid, (
	PRL_HANDLE hEmitter,
	PRL_STR sUid,
	PRL_UINT32_PTR pnUidLength
	) );

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisEmitter_RegCallback, (
	PRL_HANDLE hEmitter,
	PRL_TIS_RECORD_CALLBACK_PTR fCallback,
	PRL_VOID_PTR pCallbackArg
	) );

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisEmitter_UnregCallback, (
	PRL_HANDLE hEmitter,
	PRL_TIS_RECORD_CALLBACK_PTR fCallback,
	PRL_VOID_PTR pCallbackArg
	) );

// [/TIS support] --------------------------------------------------------------

// [Vm-Client toolgate support] ---

/**
 * Registers the tool in SDK. When a corresponding part for this tool on
 * vm becomes available, callback function will be called.
 * @param hVm[in] - handle of vm object
 * @param pToolDesc[in] - additional input parameters, see PRL_VMCTG_TOOL_DESC
 * @param phTool[out] - receives handle of registered tool on success,
 *		unchanged on failure
 * @return
 *		PRL_ERR_SUCCESS, if the tool has been registered.
 *		PRL_ERR_FAILURE, if a tool with the same ID is already registered
 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVm_RegisterTool, (
		PRL_HANDLE hVm,
		PRL_VMCTG_TOOL_DESC_PTR pToolDesc,
		PRL_HANDLE_PTR phTool
		) );

/**
@brief Just empty recycle bin in guest.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlVm_ToolsEmptyRecycleBin, (
				PRL_HANDLE hVm ) );


/**
@brief Show recycle bin in guest.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					PrlVm_ToolsShowRecycleBin, (
					PRL_HANDLE hVm ) );

/**
@brief Open file browser in guest

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlVm_ToolsOpenFileBrowser, (
				PRL_HANDLE hVm ) );

/*
@brief Show/Hide desktop.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlVm_ToolsWindowsShellToggleDesktop , (
				PRL_HANDLE hVm ) );

/*
@brief Relocate guest task bar.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] bCoherenceOn - TRUE if vm in coherence state
@param[in] bRelocateTaskBar - TRUE if relocate taskbar is enabled
@param[in] uDockEdge - where host dock is placed
@param[in] uEdgeMask - where we can place task bar (important for multi-display support)
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlVm_ToolsMoveTaskBar , (
				PRL_HANDLE	hVm,
				PRL_BOOL	bCoherenceOn,
				PRL_BOOL	bRelocateTaskBar,
				PRL_UINT32	uDockEdge,
				PRL_WINDOW_EDGE_MASK	uEdgeMask ) );

/*
@brief Notifies guest tools about new coherence state

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] bCoherenceMode - true if coherence mode, false otherwise
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					PrlVm_ToolsNotifyCoherenceState , (
					PRL_HANDLE	hVm,
					PRL_BOOL	bCoherenceMode ) );

/*
@brief Enable/Disable screen saver in guest. This routine is obsolete. Use PrlVm_ToolsNotifyCoherenceState instead.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] bEnabled - true if enabled, false if disabled.
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					PrlVm_ToolsChangeScreenSaverState , (
					PRL_HANDLE	hVm,
					PRL_BOOL	bEnabled ) );

/*
@brief Adjust working area to exclude mac dock from it.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] bIsOn - if true then adjusting is on, if false then restore previous settings
@param[in] uDockEdge - value that specifies an edge of the screen
@param[in] uDockLeft - the x-coordinate of the upper-left corner of the dock rectangle relative to guest monitor
@param[in] uDockTop - the y-coordinate of the upper-left corner of the dock rectangle relative to guest monitor
@param[in] uDockRight - the x-coordinate of the lower-right corner of the dock rectangle relative to guest monitor
@param[in] uDockBottom - the y-coordinate of the lower-right corner of the dock rectangle relative to guest monitor
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					PrlVm_ToolsAdjustWorkingArea , (
					PRL_HANDLE	hVm,
					PRL_BOOL	bIsOn,
					PRL_UINT32	uDockEdge,
					PRL_INT32	iDockLeft,
					PRL_INT32	iDockTop,
					PRL_INT32	iDockRight,
					PRL_INT32	iDockBottom ) );


/*
@brief Adjust working area by set guest display indents
@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine
@param[in] Array of	indents for guest displays
@param[in] Count of indents in array. If 0 then all indents will be removed
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					PrlVm_ToolsSetIndents , (
					PRL_HANDLE hVm,
					const PRL_IO_TOOLS_DISPLAY_INDENT_PTR indents,
					PRL_INT32 nCount) );


/* Sets CoreGraphics surface for fast server-side display
   updates. This function applies to OS X local clients
   only.
   Parameters
   hVm :        A handle of type PHT_VIRTUAL_MACHINE
                identifying the virtual machine.
   display :    Display ID.
   windowId :   Window ID.
   surfaceId :  Surface ID.
   scrollX :    X coordinate value.
   scrollY :    Y coordinate value.
   width :      Width.
   height :     Height.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevDisplay_SyncSetScreenSurface, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_UINT32 windowId,
		PRL_UINT32 surfaceId,
		PRL_INT32 scrollX,
		PRL_INT32 scrollY,
		PRL_UINT32 width,
		PRL_UINT32 height
		) );

/* Request CoreAnimation context for fast server-side display updates.
   This function applies to mac local clients only.
   Parameters
   hVm :        A handle of type PHT_VIRTUAL_MACHINE
                identifying the virtual machine.
   display :    Display ID.
   ctxScale:    Context scale. Pass 0 to destroy context.
   ctxWidth:    Context width (unscaled).
   ctxHeight:   Context height (unscaled).
   colorspaceDisplayID: host CGDirectDisplayID to take colorspace from. Pass 0 to use sRGB colorspace.
   contextID:   Resulting context ID.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlDevDisplay_SyncRequestScreenContext, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_DOUBLE ctxScale,
		PRL_UINT32 ctxWidth,
		PRL_UINT32 ctxHeight,
		PRL_UINT32 colorspaceDisplayID,
		PRL_UINT32 *contextID
		) );

/* \Returns the VNC mode of the specified virtual machine.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   pnVmRemoteDisplayMode :  [out] A pointer to a variable that
                            receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetVNCMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_REMOTE_DISPLAY_MODE_PTR pnVmRemoteDisplayMode
		) );

/* Sets the virtual machine VNC mode.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
						   configuration.
   nVmRemoteDisplayMode :  The VNC mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetVNCMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_REMOTE_DISPLAY_MODE nVmRemoteDisplayMode
		) );
/* \Returns the VNC password for the specified virtual machine.
   Parameters
   hVmCfg :                              A handle of type PHT_VM_CONFIGURATION
                                         identifying the virtual machine
										 configuration.
   sVmRemoteDisplayPassword :            [out] A pointer to a
                                         buffer that receives the
                                         \result (a UTF\-8
                                         encoded, null\-terminated
                                         string).
   pnVmRemoteDisplayPasswordBufLength :  [in] The size of the
                                         \output buffer (in
                                         bytes). Set the buffer
                                         pointer to null and this
                                         parameter's value to
                                         zero to receive the
                                         required size. [out] The
                                         required output buffer
                                         size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetVNCPassword, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmRemoteDisplayPassword,
		PRL_UINT32_PTR pnVmRemoteDisplayPasswordBufLength
		) );
/* Sets the virtual machine VNC password.
   Parameters
   hVmCfg :                       A handle of type PHT_VM_CONFIGURATION
                                  identifying the virtual machine
								  configuration.
   sNewVmRemoteDisplayPassword :  The VNC password to set. The
                                  value must be a UTF\-8 encoded,
                                  null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetVNCPassword, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmRemoteDisplayPassword
		) );
/* \Returns the VNC hostname of the specified virtual machine.
   Parameters
   hVmCfg :                              A handle of type PHT_VM_CONFIGURATION
                                         identifying the virtual machine
										 configuration.
   sVmRemoteDisplayHostName :            [out] A pointer to a
                                         buffer that receives the
                                         \result (a UTF\-8
                                         encoded, null\-terminated
                                         string).
   pnVmRemoteDisplayHostNameBufLength :  [in] The size of the
                                         \output buffer (in
                                         bytes). Set the buffer
                                         pointer to null and this
                                         parameter's value to
                                         zero to receive the
                                         required size. [out] The
                                         required output buffer
                                         size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetVNCHostName, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmRemoteDisplayHostName,
		PRL_UINT32_PTR pnVmRemoteDisplayHostNameBufLength
		) );
/* Sets the virtual machine VNC host name.
   Parameters
   hVmCfg :                       A handle of type PHT_VM_CONFIGURATION
                                  identifying the virtual machine
								  configuration.
   sNewVmRemoteDisplayHostName :  The new VNC host name. The
                                  value must be a a UTF\-8
                                  encoded, null\-terminated
                                  string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetVNCHostName, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmRemoteDisplayHostName
		) );
/* \Returns the VNC port number for the specified virtual
   machine.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   pnVmRemoteDisplayPort :  [out] A pointer to a variable that
                            receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetVNCPortNumber, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmRemoteDisplayPort
		) );
/* Sets the virtual machine VNC port number.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
						   configuration.
   nVmRemoteDisplayPort :  The port number to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetVNCPortNumber, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmRemoteDisplayPort
		) );

/* \Returns the default VNC host name for the Parallels Service.
   Parameters
   hDispConfig :          A handle of type PHT_DISP_CONFIG.
   sHostName :            [out] Pointer to a buffer that receives
                          the VNC host name (a UTF\-8 encoded,
                          null\-terminated string).
   pnHostNameBufLength :  [in] The size of the output buffer (in
                          bytes). Set the buffer pointer to null
                          and this value to zero to receive the
                          required size. [out] The required
                          \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_GetDefaultVNCHostName, (
		PRL_HANDLE hDispConfig,
		PRL_STR sHostName,
		PRL_UINT32_PTR pnHostNameBufLength
		) );

/* Sets the base VNC host name.
   Parameters
   hDispConfig :   A handle of type PHT_DISP_CONFIG.
   sNewHostName :  The new VNC host name. The value must be UTF\-8
                   encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_SetDefaultVNCHostName, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sNewHostName
		) );

/* Obtains the currently set base VNC port number.
   Parameters
   hDispConfig :  A handle of type PHT_DISP_CONFIG.
   pnPort :       [out] A pointer to a variable that receives the
                  port number.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_GetVNCBasePort, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32_PTR pnPort
		) );

/* Sets the base VNC port number.
   Parameters
   hDispConfig :  A handle of type PHT_DISP_CONFIG.
   nPort :        Port number to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_SetVNCBasePort, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32 nPort
		) );

/**
 * @brief Enable or disable console image updates. This function
 *        applies to OS X local clients only.
 *
 * @param[in] hVm - A handle of type PHT_VIRTUAL_MACHINE
 *                  identifying the virtual machine.
 * @param[in] display - Display ID.
 * @param[in] bEnable - true to enable screen updates, false to disable.
 *
 * @return
 *		PRL_ERR_SUCCESS, if the function completed successfully.
 *		PRL_ERR_INVALID_ARG, if invalid handle or null pointer was passed.
 *		PRL_ERR_UNINITIALIZED, if API is not initialized
 *		PRL_ERR_FAILURE, if operation was failed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlDevDisplay_AsyncEnableUpdates, (
		PRL_HANDLE hVM,
		PRL_UINT32 display,
		PRL_BOOL bEnable
		) );

/* Change Mouse Cursor state to indicate cursor modes
   supported by client.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   VmMouseState : A combination of PRL_VM_MOUSE_CURSOR_STATE flags
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_UNINITIALIZED - when API is not initialized
   PRL_ERR_FAILURE - when failed to send command to VM
   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlDevDisplay_SetMouseCursorState, (
		PRL_HANDLE hVm,
		PRL_UINT32 VmMouseCursorState
		) );

/**
 * Sends a block of data to the corresponding part of this tool on vm.
 * Data block is not copied, this function waits until the data is written to the channel.
 * @param hTool[in] - handle of previously registered tool
 * @param pData[in] - pointer to the block of data
 * @param uSize[in] - size of data in bytes
 * @return
 *		PRL_ERR_INVALID_ARG - if hTool is not valid sdk object or it is not
 *		a tool object.
 *		PRL_ERR_INVALID_HANDLE - if hTool was a tool object, but it doesn't exist anymore
 *		PRL_ERR_FAILURE - there is no connection with vm
 *		PRL_ERR_SUCCESS - the block of data is written to an internal socket
 */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlTool_SendData, (
		PRL_HANDLE hTool,
		PRL_CONST_VOID_PTR pData,
		PRL_UINT32 uSize
		) );

/**
 * Sends a block of data to the corresponding part of this tool on vm asynchronously.
 * To send data block asynchronously this function copies data blakc or frees data block after send by it self,
 * depending on uFlags parameter. This function adds data block to write queue and returns immidiately.
 * @param hTool[in] - handle of previously registered tool
 * @param pData[in] - pointer to the block of data
 * @param uSize[in] - size of data in bytes
 * @param uFlags[in] - see PRL_TOOL_SEND_DATA_FLAGS
 * @return
 *		PRL_ERR_INVALID_ARG - if hTool is not valid sdk object or it is not
 *		a tool object.
 *		PRL_ERR_INVALID_HANDLE - if hTool was a tool object, but it doesn't exist anymore
 *		PRL_ERR_FAILURE - there is no connection with vm
 *		PRL_ERR_SUCCESS - the block of data is written to an internal socket
 */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_6,
					PrlTool_SendDataAsync, (
		PRL_HANDLE hTool,
		PRL_CONST_VOID_PTR pData,
		PRL_UINT32 uSize,
		PRL_UINT32 uFlags
		) );

/**
 * Allocates a buffer with specified size.
 * This memory buffer is intented to be used with tool API functions.
 * @param pBuffer[out] - ptr to the allocated buffer
 * @param uSize[in] - size of the buffer
 * @return
 *		PRL_ERR_SUCCESS - buffer has been allocated
 *		PRL_ERR_INVALID_ARG - if specified size is zero
 *		PRL_ERR_OUT_OF_MEMORY - if memory allocation failed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
					PrlTool_AllocBuffer, (
		PRL_VOID_PTR_PTR pBuffer,
		PRL_UINT32 uSize
		) );

/**
 * Releases a buffer, given us by our callback function
 * @param pBuffer[in] - ptr to the buffer to be released
 * @return
 *		PRL_ERR_SUCCESS - buffer has been released
 *		PRL_ERR_FAILURE - no such buffer allocated by sdk
 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlTool_FreeBuffer, (
		PRL_VOID_PTR pBuffer
		) );

/**
 * Unregisters previously registered tool. Callback function will not be
 * called since this fuction successfully returns. After this fucntion
 * succeeds, hTool must not be used.
 *
 * @param hTool[in] - handle of previously registered tool
 * @return
 *		PRL_ERR_INVALID_ARG - hTool is not valid tool object
 *		PRL_ERR_SUCCESS - the tool successfully unregistered
 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlTool_Unregister, (
		PRL_HANDLE hTool
		) );

// [/Vm-Client toolgate support] ---


/**
* Client can use this method to set port forwarding configuration
* This method must be eliminated at Release stage
*
* @param valid PRL_HANDLE
* @param XML configuration string
* @return PRL_RESULT. Possible values:
* PRL_ERR_INVALID_ARG				- non valid PHT_DISP_NET_ADAPTER handle or non valid (NULL) pointer to config XML
* representation string was passed
* PRL_ERR_SUCCESS						- operation successfully completed
*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispNet_PortForwardingFromString, (
				PRL_HANDLE hDispNet,
				PRL_CONST_STR sPortForwarding
				) );

/**
* Client can use this method to get port forwarding configuration configuration as XML string
* This method must be eliminated at Release stage
*
* @param valid PRL_HANDLE
* @param XML configuration string
* @return PRL_RESULT. Possible values:
* PRL_ERR_INVALID_ARG				- non valid PHT_DISP_NET_ADAPTER handle or non valid (NULL) pointer to storing result was passed
* PRL_ERR_SUCCESS						- operation successfully completed
*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispNet_PortForwardingToString, (
				PRL_HANDLE hDispNet,
				PRL_VOID_PTR_PTR pPortForwarding
				) );


/* Parameters
   phConfig :  [out] pointer to storing new client hardware
               configuration handle
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   (NULL) pointer for storing result was passed
   PRL_ERR_OUT_OF_MEMORY - not enough memory to create server
   object PRL_ERR_SUCCESS - operation successfully completed    */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlUsr_GetClientConfig, (
		PRL_HANDLE_PTR phConfig
		) );


/* Stands by all guests with generic PCI devices.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_PrepareForHibernate, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


/* Performs to wake up generic PCI devices after host resume.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_AfterHostResume, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Parallels Service net adapters operations
///////////////////////////////////////////////////////////////////////////////

/* Removes the specified virtual network adapter object from
   memory. This function does not delete the adapter from the
   Parallels Service configuration. Use this function if you
   would like to cancel the changes that you've made to the
   object properties so far. The function must be called before
   calling the PrlSrv_AddNetAdapter or the
   PrlSrv_UpdateNetAdapter function (the calls that update the
   Parallels Service configuration and make the changes permanent). To
   delete an existing adapter from the configuration, use the
   PrlSrv_DeleteNetAdapter function.
   Parameters
   hDispNet :  A handle of type PHT_DISP_NET_ADAPTER identifying
               the network adapter.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_Remove, (
		PRL_HANDLE hDispNet
		) );

/* Determines whether the specified virtual network adapter is
   enabled or disabled.
   Parameters
   hDispNet :   A handle of type PHT_DISP_NET_ADAPTER identifying
                the network adapter.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the adapter is
                enabled. PRL_FALSE indicates that the adapter is
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetEnabled                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_IsEnabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   adapter.
   Parameters
   hDispNet :  A handle of type PHT_DISP_NET_ADAPTER identifying
               the network adapter.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the adapter.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_IsEnabled                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetEnabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL bEnabled
		) );

/* Determines whether the specified virtual network adapter is
   hidden.
   Parameters
   hDispNet :   A handle of type PHT_DISP_NET_ADAPTER identifying
                the network adapter.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the adapter is
                hidden.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetEnabled                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispNet_IsHidden, (
		PRL_HANDLE hDispNet,
		PRL_BOOL_PTR pbHidden
		) );

/* Allows to hide or show a specified virtual network adapter at system
   preferences.
   Parameters
   hDispNet :  A handle of type PHT_DISP_NET_ADAPTER identifying
               the network adapter.
   bHidden :  A boolean value indicating the type of action to
               perform. PRL_TRUE will hide the adapter.
               PRL_FALSE will show it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_IsHidden                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispNet_SetHidden, (
		PRL_HANDLE hDispNet,
		PRL_BOOL bHidden
		) );

/* Determines if DHCP scope is enabled for the specified virtual
   network adapter.
   Parameters
   hDispNet :       A handle of type PHT_DISP_NET_ADAPTER
                    identifying the network adapter.
   pbDhcpEnabled :  [out] A pointer to a variable that receives
                    the result. PRL_TRUE indicates that the DHCP
                    scope is enabled, PRL_FALSE indicates that it
                    is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcpEnabled                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_IsDhcpEnabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL_PTR pbDhcpEnabled
		) );

/* Allows to enable or disable the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :      A handle of type PHT_DISP_NET_ADAPTER
                   identifying the network adapter.
   bDhcpEnabled :  Specifies the action to perform. PRL_TRUE
                   enables the DHCP scope. PRL_FALSE disables it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_IsDhcpEnabled                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetDhcpEnabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL bDhcpEnabled
		) );

/* \Returns the virtual network adapter network type (host-only
   or shared).
   Parameters
   hDispNet :       A handle of type PHT_DISP_NET_ADAPTER
                    identifying the network adapter.
   pnNetworkType :  [out] A pointer to a variable that receives
                    the network type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetNetworkType                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetNetworkType, (
		PRL_HANDLE hDispNet,
		PRL_NET_ADAPTER_EMULATED_TYPE_PTR pnNetworkType
		) );

/* Allows to set a network type for the specified virtual
   network adapter.
   Parameters
   hDispNet :      A handle of type PHT_DISP_NET_ADAPTER
                   identifying the network adapter.
   nNetworkType :  A network type to set. NOTE\: You can only use
                   PNA_HOST_ONLY and PNA_SHARED types here. You
                   CANNOT use the PNA_BRIDGED_ETHERNET type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetNetworkType                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetNetworkType, (
		PRL_HANDLE hDispNet,
		PRL_NET_ADAPTER_EMULATED_TYPE nNetworkType
		) );

/* \Returns the name of the specified virtual network adapter.
   Parameters
   hDispNet :                A handle of type
                             PHT_DISP_NET_ADAPTER identifying the
                             network adapter.
   sDispNetName :            [out] A pointer to a buffer that
                             receives the name (a UTF\-8 encoded,
                             null\-terminated string).
   pnDispNetNameBufLength :  [in] The size of the output buffer
                             (in bytes). Set the buffer pointer
                             to null and this value to zero to
                             receive the required size. [out] The
                             required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetName                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetName, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetName,
		PRL_UINT32_PTR pnDispNetNameBufLength
		) );

/* Sets the specified virtual network adapter name.
   Parameters
   hDispNet :         A handle of type PHT_DISP_NET_ADAPTER
                      identifying the network adapter.
   sNewDispNetName :  A name to set. The value must be a UTF\-8
                      encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetName                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetName, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetName
		) );

/* \Returns the specified virtual network adapter UUID.
   Parameters
   hDispNet :                A handle of type
                             PHT_DISP_NET_ADAPTER identifying the
                             network adapter.
   sDispNetUuid :            [out] A pointer to a buffer that
                             receives the UUID (a UTF\-8 encoded,
                             null\-terminated string).
   pnDispNetUuidBufLength :  [in] The size of the output buffer
                             (in bytes). Set the buffer pointer
                             to null and this value to zero to
                             receive the required size. [out]
                             The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetUuid, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetUuid,
		PRL_UINT32_PTR pnDispNetUuidBufLength
		) );

/* \Returns the name of the physical network adapter to which
   the specified virtual network adapter is bound.
   Parameters
   hDispNet :                   A handle of type
                                PHT_DISP_NET_ADAPTER identifying
                                the network adapter.
   sDispNetSysName :            [out] A pointer to a buffer that
                                receives the name (a UTF\-8
                                encoded, null\-terminated
                                string).
   pnDispNetSysNameBufLength :  [in] The size of the output
                                buffer (in bytes). Set the buffer
                                pointer to null and this value to
                                zero to receive the required
                                size. [out] The required output
                                buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetSysName                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetSysName, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetSysName,
		PRL_UINT32_PTR pnDispNetSysNameBufLength
		) );

/* Sets the specified virtual network adapter system name.
   Parameters
   hDispNet :            A handle of type PHT_DISP_NET_ADAPTER
                         identifying the network adapter.
   sNewDispNetSysName :  A system name to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetSysName                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetSysName, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetSysName
		) );

/* \Returns the index identifying the specified adapter on the
   Parallels Service.
   Parameters
   hDispNet :  A handle of type PHT_DISP_NET_ADAPTER identifying
               the network adapter.
   pnIndex :   [out] A pointer to a variable that receives the
               index.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetIndex                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetIndex, (
		PRL_HANDLE hDispNet,
		PRL_UINT32_PTR pnIndex
		) );

/* Sets the specified virtual network adapter index (from 0 to
   5). Use this function to set a unique number for a virtual
   network adapter for easy identification in your client
   applications.
   Parameters
   hDispNet :  A handle of type PHT_DISP_NET_ADAPTER identifying
               the network adapter.
   nIndex :    An index to set. The value cannot be less then 0
               and greater than 5.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetIndex                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetIndex, (
		PRL_HANDLE hDispNet,
		PRL_UINT32 nIndex
		) );

/* \Returns the start IP address of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                            A handle of type
                                         PHT_DISP_NET_ADAPTER
                                         identifying the network
                                         adapter.
   sDispNetDhcpScopeStartIp :            [out] A pointer to a
                                         buffer that receives the
                                         IP address (a UTF\-8
                                         encoded, null\-terminated
                                         string).
   pnDispNetDhcpScopeStartIpBufLength :  [in] The size of the
                                         \output buffer (in
                                         bytes). Set the buffer
                                         pointer to null and this
                                         value to zero to receive
                                         the required size. [out]
                                         The required output
                                         buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcpScopeStartIp                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetDhcpScopeStartIp, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeStartIp,
		PRL_UINT32_PTR pnDispNetDhcpScopeStartIpBufLength
		) );

/* Sets the start IP address of the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                     A handle of type
                                  PHT_DISP_NET_ADAPTER
                                  identifying the network
                                  adapter.
   sNewDispNetDhcpScopeStartIp :  The IP address. The value must
                                  be a UTF\-8 encoded,
                                  null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcpScopeStartIp                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetDhcpScopeStartIp, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeStartIp
		) );

/* \Returns the end IP address of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                          A handle of type
                                       PHT_DISP_NET_ADAPTER
                                       identifying the network
                                       adapter.
   sDispNetDhcpScopeEndIp :            [out] A pointer to a buffer
                                       that receives the IP
                                       address (a UTF\-8 encoded,
                                       null\-terminated string).
   pnDispNetDhcpScopeEndIpBufLength :  [in] The size of the output
                                       buffer (in bytes). Set the
                                       buffer pointer to null and
                                       this value to zero to
                                       receive the required size.
                                       [out] The required output
                                       buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcpScopeEndIp                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetDhcpScopeEndIp, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeEndIp,
		PRL_UINT32_PTR pnDispNetDhcpScopeEndIpBufLength
		) );

/* Sets the end IP address of the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                   A handle of type
                                PHT_DISP_NET_ADAPTER identifying
                                the network adapter.
   sNewDispNetDhcpScopeEndIp :  The IP address. The value must be
                                a UTF\-8 encoded, null\-terminated
                                string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcpScopeEndIp                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetDhcpScopeEndIp, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeEndIp
		) );

/* \Returns the subnet mask of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                         A handle of type
                                      PHT_DISP_NET_ADAPTER
                                      identifying the network
                                      adapter.
   sDispNetDhcpScopeMask :            [out] A pointer to a buffer
                                      that receives the subnet
                                      mask (a UTF\-8 encoded,
                                      null\-terminated string).
   pnDispNetDhcpScopeMaskBufLength :  [in] The size of the output
                                      buffer (in bytes). Set the
                                      buffer pointer to null and
                                      this value to zero to
                                      receive the required size.
                                      [out] The required output
                                      buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcpScopeMask                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_GetDhcpScopeMask, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeMask,
		PRL_UINT32_PTR pnDispNetDhcpScopeMaskBufLength
		) );

/* Sets the subnet mask of the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                  A handle of type
                               PHT_DISP_NET_ADAPTER identifying
                               the network adapter.
   sNewDispNetDhcpScopeMask :  The subnet mask. The value must be
                               a UTF\-8 encoded, null\-terminated
                               string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcpScopeMask                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispNet_SetDhcpScopeMask, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeMask
		) );


/* ============== IPV6 ==============  */

/* Determines if DHCP6 scope is enabled for the specified virtual
   network adapter.
   Parameters
   hDispNet :       A handle of type PHT_DISP_NET_ADAPTER
                    identifying the network adapter.
   pbDhcpEnabled :  [out] A pointer to a variable that receives
                    the result. PRL_TRUE indicates that the DHCP
                    scope is enabled, PRL_FALSE indicates that it
                    is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcpEnabled                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_IsDhcp6Enabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL_PTR pbDhcpEnabled
		) );

/* Allows to enable or disable the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :      A handle of type PHT_DISP_NET_ADAPTER
                   identifying the network adapter.
   bDhcpEnabled :  Specifies the action to perform. PRL_TRUE
                   enables the DHCP scope. PRL_FALSE disables it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_IsDhcpEnabled                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_SetDhcp6Enabled, (
		PRL_HANDLE hDispNet,
		PRL_BOOL bDhcpEnabled
		) );


/* \Returns the start IP address of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                            A handle of type
                                         PHT_DISP_NET_ADAPTER
                                         identifying the network
                                         adapter.
   sDispNetDhcpScopeStartIp :            [out] A pointer to a
                                         buffer that receives the
                                         IP6 address (a UTF\-8
                                         encoded, null\-terminated
                                         string).
   pnDispNetDhcpScopeStartIpBufLength :  [in] The size of the
                                         \output buffer (in
                                         bytes). Set the buffer
                                         pointer to null and this
                                         value to zero to receive
                                         the required size. [out]
                                         The required output
                                         buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcp6ScopeStartIp                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_GetDhcp6ScopeStartIp, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeStartIp,
		PRL_UINT32_PTR pnDispNetDhcpScopeStartIpBufLength
		) );

/* Sets the start IP address of the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                     A handle of type
                                  PHT_DISP_NET_ADAPTER
                                  identifying the network
                                  adapter.
   sNewDispNetDhcpScopeStartIp :  The IP6 address. The value must
                                  be a UTF\-8 encoded,
                                  null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcpScopeStartIp                                */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_SetDhcp6ScopeStartIp, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeStartIp
		) );

/* \Returns the end IP address of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                          A handle of type
                                       PHT_DISP_NET_ADAPTER
                                       identifying the network
                                       adapter.
   sDispNetDhcpScopeEndIp :            [out] A pointer to a buffer
                                       that receives the IP6
                                       address (a UTF\-8 encoded,
                                       null\-terminated string).
   pnDispNetDhcpScopeEndIpBufLength :  [in] The size of the output
                                       buffer (in bytes). Set the
                                       buffer pointer to null and
                                       this value to zero to
                                       receive the required size.
                                       [out] The required output
                                       buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcp6ScopeEndIp                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_GetDhcp6ScopeEndIp, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeEndIp,
		PRL_UINT32_PTR pnDispNetDhcpScopeEndIpBufLength
		) );

/* Sets the end IP address of the DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                   A handle of type
                                PHT_DISP_NET_ADAPTER identifying
                                the network adapter.
   sNewDispNetDhcpScopeEndIp :  The IP6 address. The value must be
                                a UTF\-8 encoded, null\-terminated
                                string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcp6ScopeEndIp                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_SetDhcp6ScopeEndIp, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeEndIp
		) );

/* \Returns the subnet mask of DHCP scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                         A handle of type
                                      PHT_DISP_NET_ADAPTER
                                      identifying the network
                                      adapter.
   sDispNetDhcpScopeMask :            [out] A pointer to a buffer
                                      that receives the subnet
                                      mask (a UTF\-8 encoded,
                                      null\-terminated string).
   pnDispNetDhcpScopeMaskBufLength :  [in] The size of the output
                                      buffer (in bytes). Set the
                                      buffer pointer to null and
                                      this value to zero to
                                      receive the required size.
                                      [out] The required output
                                      buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_SetDhcp6ScopeMask                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_GetDhcp6ScopeMask, (
		PRL_HANDLE hDispNet,
		PRL_STR sDispNetDhcpScopeMask,
		PRL_UINT32_PTR pnDispNetDhcpScopeMaskBufLength
		) );

/* Sets the subnet mask of the DHCP6 scope for the specified
   virtual network adapter.
   Parameters
   hDispNet :                  A handle of type
                               PHT_DISP_NET_ADAPTER identifying
                               the network adapter.
   sNewDispNetDhcpScopeMask :  The subnet mask. The value must be
                               a UTF\-8 encoded, null\-terminated
                               string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispNet_GetDhcp6ScopeMask                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispNet_SetDhcp6ScopeMask, (
		PRL_HANDLE hDispNet,
		PRL_CONST_STR sNewDispNetDhcpScopeMask
		) );

/* Adds a new virtual network adapter to the specified Parallels
   Service. To get the return code from the PHT_JOB object, use
   the PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :      A handle of type PHT_SERVER identifying the
                  Parallels Service.
   hNetAdapter :  A handle of type PHT_DISP_NET_ADAPTER containing
                  the new adapter information. For the details on
                  how to create the handle and how to set the
                  adapter properties, see PHT_DISP_CONFIG.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_AddNetAdapter, (
		PRL_HANDLE hServer,
		PRL_HANDLE hNetAdapter
		) );

/* Removes a virtual network adapter from the Parallels Service
   configuration. See PHT_DISP_CONFIG and PHT_DISP_NET_ADAPTER
   for more information about Parallels Service preferences and
   virtual network adapters.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid server handle was passed or
   adapter index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   nIndex :   An index of the virtual network adapter to remove.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_DeleteNetAdapter, (
		PRL_HANDLE hServer,
		PRL_UINT32 nIndex
		) );

/* Updates an existing virtual network adapter in the specified
   Parallels Service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :      A handle of type PHT_SERVER identifying the
                  Parallels Service.
   hNetAdapter :  A handle of PHT_DISP_NET_ADAPTER containing the
                  new adapter information.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_UpdateNetAdapter, (
		PRL_HANDLE hServer,
		PRL_HANDLE hNetAdapter
		) );


/* Private function to store value by specified keys on server

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :[in] A handle of type PHT_SERVER identifying the
             Parallels Service.
   sKey	   :[in] Key to access to value
   sValue  :[in] Value to store
   nFlags  :[in] Reserved parameter.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_StoreValueByKey, (
		PRL_HANDLE hServer,
		PRL_CONST_STR sKey,
		PRL_CONST_STR sValue,
		PRL_UINT32 nFlags
		) );

/* Private function to store value by specified keys on server

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :[in] A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   sKey	   :[in] Key to access to value
   sValue  :[in] Value to store
   nFlags  :[in] Reserved parameter.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_StoreValueByKey, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sKey,
		PRL_CONST_STR sValue,
		PRL_UINT32 nFlags
		) );

/* Creates a new virtual network adapter object and adds it to
   the network adapters list. This function merely creates a new
   virtual network adapter object in the local memory. To add a
   network adapter to the Parallels Service, populate the
   necessary network adapter properties using functions from the
   PHT_DISP_NET_ADAPTER group and then call PrlSrv_AddNetAdapter
   to add the adapter to the Parallels Service configuration.
   Parameters
   hDispConfig :  A handle of type PHT_DISP_CONFIG.
   phDispNet :    [out] A pointer to a new handle of type
                  PHT_DISP_NET_ADAPTER.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_CreateDispNet, (
		PRL_HANDLE hDispConfig,
		PRL_HANDLE_PTR phDispNet
		) );

/* Determines the total number of the virtual network adapters
   in the Parallels Service configuration.
   Parameters
   hDispCfg :        A handle of type PHT_DISP_CONFIG.
   pnDispNetCount :  [out] A pointer to a variable that receives
                     the total adapter count.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_GetDispNetCount, (
		PRL_HANDLE hDispCfg,
		PRL_UINT32_PTR pnDispNetCount
		) );

/* Obtains information about a virtual network adapter from the
   Parallels Service configuration. Parallels Service can have
   multiple network adapters, each identified by a numeric index
   starting with 0 and up. Use PrlDispCfg_GetDispNetCount to
   determine the total adapter count and then obtain each
   adapter information by calling this function in a loop,
   passing an index counter in each iteration.
   Parameters
   hDispCfg :       A handle of type PHT_DISP_CONFIG.
   nDispNetIndex :  An index identifying the adapter in the
                    adapter list starting with 0 and up. To
                    obtain the total number of the available
                    adapters, use the PrlDispCfg_GetDispNetCount
                    function.
   phDispNet :      [out] A pointer to a handle of type
                    PHT_DISP_NET_ADAPTER. On function return, the
                    object will contain the specified net adapter
                    information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_GetDispNet, (
		PRL_HANDLE hDispCfg,
		PRL_UINT32 nDispNetIndex,
		PRL_HANDLE_PTR phDispNet
		) );

/**
@brief Sends Parallels Tools utility command

Parameters
unnamed_param :[in] hVm Handle to VM
unnamed_param :[in] command Command identifier
unnamed_param :[in] flags Set of 32 bit-flags that can be used to control command
behavior
unnamed_param :[in] data Pointer on data that must be sent with command. Can be 0
when <i>dataSize</i> is 0.
unnamed_param :[in] dataSize Size of data (in bytes) pointed by data pointer

Returns
PRL_RESULT. Possible values:
- PRL_ERR_INVALID_ARG - when on of the passed arguments is invalid
- PRL_ERR_UNINITIALIZED - when API is not initialized
- PRL_ERR_FAILURE - when failed to send command to VM
- PRL_ERR_SUCCESS - when everything is ok and the sun is shining bright =)
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTools_SendUtilityCommand, (
		PRL_HANDLE hVm,
		PRL_UINT32 command,
		PRL_UINT32 flags,
		PRL_CONST_VOID_PTR data,
		PRL_UINT32 dataSize
		) );


/* Allows to send data to the Shared Internet Application tool.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   data :  A pointer to a buffer containing the data.
   size :  The data buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevSIA_SendSIAData, (
		PRL_HANDLE hVm,
		PRL_CONST_UINT32_PTR data,
		PRL_UINT32 size
		) );

/* Set path to log location for SDK library module.
   If sLogPath is NULL or empty string - default
   client log path will be set.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlApi_SetLogPath, (
		PRL_CONST_STR sLogPath
		) );

/* \Returns a pointer to a buffer containing handles to the
   virtual devices installed in a virtual machine. To determine
   the number of virtual devices installed in a virtual machine
   (so that you can allocate the output buffer memory
   dynamically), use the PrlVmCfg_GetDevsCount function. You can
   also allocate the memory statically if you wish. When
   iterating through the returned array, the handle type
   (essentially the device type) in each iteration can be
   determined using the PrlHandle_GetType function. You can
   search this documentation for topics with PHT_VIRTUAL_DEV_
   prefix in their names for the list of the available virtual
   device handles. It is the responsibility of the caller to
   free the memory when the handles are no longer needed.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine configuration.
   vmdev_handles :        [out] A pointer to a variable that
                          receives the data.
   vmdev_handles_count :  [in] The number of handles that can be
                          placed into the output buffer. [out]
                          The actual number of handles returned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle, null pointer, or
   invalid number of handles.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough to fit all of the available devices.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a device
   object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDevsList, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR vmdev_handles,
		PRL_UINT32_PTR vmdev_handles_count
		) );

/* \Sends Client statistic data to server.
Parameters
hServer		:			[in] Server handle.
sStatistics :           [in] Pointer to a buffer which contains statistic data
(a UTF\-8 encoded, null\-terminated string).
PRL_UINT32 nFlags - reserved parameter
Returns
PRL_RESULT. Possible values are:

PRL_ERR_INVALID_ARG - null pointer was
passed.

PRL_ERR_SUCCESS - function completed successfully.             */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
				PrlSrv_SendClientStatistics, (
				PRL_HANDLE hServer,
				PRL_CONST_STR sStatistics,
				PRL_UINT32 nFlags
				) );

typedef enum _PRL_USB_LIST_VERSION
{
	ULV_VER0 = 0,
	ULV_VER1 = 1,
	ULV_VER_END = ULV_VER1,
} PRL_USB_LIST_VERSION;

/* Updates internal Parallels client USB associations list.
list to update has format UsbFriendlyName:USB_LIST_DIVIDER:UsbId

To get the return code from the PHT_JOB object, use the
PrlJob_GetRetCode function. Possible values are:

PRL_ERR_INVALID_ARG - invalid handle was passed.

PRL_ERR_SUCCESS - function completed successfully.

Parameters
hServer :       A handle of type PHT_SERVER identifying the
Parallels Service.
hStringsList :  A handle of type PHT_STRINGS_LIST containing
the USB associations list.
PRL_UINT32 nListVersion - version of list on client
PRL_UINT32 nFlags - reserved parameter
Returns
A handle of type PHT_JOB containing the results of this
asynchronous operation or PRL_INVALID_HANDLE if there's not
enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						  PrlSrv_UpdateUsbDevicesAssociationsList, (
						  PRL_HANDLE hServer,
						  PRL_HANDLE hStringsList,
						  PRL_UINT32 nListVersion,
						  PRL_UINT32 nFlags
						  ) );


///////////////////////////////////////////////////////////////////////////////
/// @section Parallels Compressor Utility functions
///////////////////////////////////////////////////////////////////////////////

/* Initiates the Compressor process. The virtual machine must be
   registered with Parallels Service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_RunCompressor, (
		PRL_HANDLE hVm
		) );

/* Cancels the running Compressor operation that was started
   with PrlVm_RunCompressor. To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_CancelCompressor, (
		PRL_HANDLE hVm
		) );


PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					   PrlVm_InternalCommand, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sCmdName,
		PRL_HANDLE hArgsList
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Traffic Accounting/Shaping operations
///////////////////////////////////////////////////////////////////////////////
/* Shaping configuration changed, apply new configuration to all running VMs.
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :           A handle of type PHT_SERVER identifying the
                       Parallels Service.
   nFlags :            Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetNetworkClassesList

*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					PrlSrv_RestartNetworkShaping, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* Update the list of network shaping entries represents the
   network shaping  configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :		A handle of type PHT_SERVER identifying the
			Parallels Service.
   hNetworkShapingList: A handle of type PHT_HANDLE_LIST contains the
                        list of handles of type PHT_NETWORK_SHAPING

   nFlags :		Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetNetworkShapingList
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_UpdateNetworkShapingList, (
		PRL_HANDLE hServer,
		PRL_HANDLE hNetworkShapingList,
		PRL_UINT32 nFlags
		) );

/* Obtains a list of network shaping entries
   represents the network shaping configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParam function to obtain a handle
   of type PHT_HANDLES_LIST  containing the list of the handles of type
   PHT_NETWORK_SHAPING
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_GetNetworkShapingList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* Update network class classes configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :		A handle of type PHT_SERVER identifying the
			Parallels Service.
   hNetworkClassList :	A handle of type PHT_HANDLES_LIST contains the
			list of handles of type PHT_NETWORK_CLASS
   nFlags :		Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetNetworkClassesList
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_UpdateNetworkClassesList, (
		PRL_HANDLE hServer,
		PRL_HANDLE hNetworkClassesList,
		PRL_UINT32 nFlags
		) );

/* Obtains a list of handles of type PHT_HANDLES_LIST
   containing the list of handles of type PHT_NETWORK_CLASS.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParam function to obtain a handle
   of type PHT_HANDLES_LIST
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_GetNetworkClassesList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


/* Update the network shaping configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :		A handle of type PHT_SERVER identifying the
			Parallels Service.
   hNetworkShapingConfig: A handle of type PHT_NETWORK_SHAPING_CONFIG.
   nFlags :		Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetNetworkShapingConfig
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_UpdateNetworkShapingConfig, (
		PRL_HANDLE hServer,
		PRL_HANDLE hNetworkShapingConfig,
		PRL_UINT32 nFlags
		) );

/* Obtains the network shaping configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParam function to obtain a handle
   of type PHT_NETWORK_SHAPING_CONFIG
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_GetNetworkShapingConfig, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* Creates a new handle of type PHT_NETWORK_CLASS. The handle
   is necessary to configure network accounting configuration
   If you would like to manage network classes configuration,
   use this function to create the handle first and then use the
   handle functions to configure the Network class.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   nClassId:		Network class id.
   phNetworkClass :	[out] A pointer to a variable that receives the
                        handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkClass_Create, (
		PRL_UINT32 nClassId,
		PRL_HANDLE_PTR phNetworkClass
		) );

/* \Returns the network class id.
   Parameters
   hNetworkClass:	A handle of type PHT_NETWORK_CLASS
			identifying the network class entry.
   pnClassId:		[out] A pointer to a buffer that receives
                        the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkClass_GetClassId, (
		PRL_HANDLE hNetworkClass,
		PRL_UINT32_PTR pnClassId
		) );

/* \Sets the network class id.
   Parameters
   hNetworkClass:	A handle of type PHT_NETWORK_CLASS
			identifying the network class entry.
   nClassId:		Class id
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkClass_SetClassId, (
		PRL_HANDLE hNetworkClass,
		PRL_UINT32 nClassId
		) );


/* \Returns the list of networks for specified network class entry.
   Parameters
   hNetworkClass:	A handle of type PHT_NETWORK_CLASS
			identifying the network class entry.
   phNetworkList:	[out] A pointer to a handle of type PHT_STRINGS_LIST
			that receives the list of networks
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkClass_GetNetworkList, (
		PRL_HANDLE hNetworkClass,
		PRL_HANDLE_PTR phNetworkList
		) );

/* \Sets the list of networks for specified network class entry.
   Parameters
   hNetworkClass:	A handle of type PHT_NETWORK_CLASS
			identifying the network class entry.
   hNetworkList:	A handle of type PHT_STRINGS_LIST
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkClass_SetNetworkList, (
		PRL_HANDLE hNetworkClass,
		PRL_HANDLE hNetworkList
		) );


/* Creates a new handle of type PHT_NETWORK_SHAPING. The handle
   is necessary to configure network shaping configuration.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   nClassId:		Network class id
   nTotalRate:		Specifies bound rate for network class
   phNetworkShapingEntry:[out] A pointer to a variable that receives the
                        handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_Create, (
		PRL_UINT32 nClassId,
		PRL_UINT32 nTotalRate,
		PRL_HANDLE_PTR phNetworkShapingEntry
		) );

/* \Returns the network class id.
   Parameters
   pNetworkShapingEntry:A handle of type PHT_NETWORK_SHAPING
			identifying the network shaping entry.
   pnClassId:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_GetClassId, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32_PTR pnClassId
		) );

/* \Sets the network class id for specified shaping entry.
   Parameters
   pNetworkShapingEntry:A handle of type PHT_NETWORK_SHAPING
			identifying the network shaping entry.
   nClassId:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_SetClassId, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32 nClassId
		) );


/* \Returns the total rate for specified shaping entry.
   Parameters
   pNetworkShapingEntry:A handle of type PHT_NETWORK_SHAPING
			identifying the network shaping entry.
   pnTotalRate:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_GetTotalRate, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32_PTR pnTotalRate
		) );

/* Sets the total rate for specified shaping entry.
   Parameters
   hNetworkShapingEntry: A handle of type PHT_NETWORK_SHAPING
			identifying the shaping entry.
   nTotalRate:		The network total rate in Kbits.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_SetTotalRate, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32 nTotalRate
		) );


/* Sets the specified network device.
   Parameters
   hNetworkShapingEntry: A handle of type PHT_NETWORK_SHAPING
			identifying the shaping entry.
   sDev:		The network device.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_SetDevice, (

		PRL_HANDLE hNetworkShapingEntry,
		PRL_CONST_STR sDev
		) );

/* \Returns the network device for specified shaping entry.
   Parameters
   pNetworkShapingEntry:A handle of type PHT_NETWORK_SHAPING
			identifying the network shaping entry.
   sDev:		[out] A pointer to a buffer that receives
			the result.
   pnBufLength:		[in] The size of the output buffer (in
			bytes). Set the buffer pointer to null
			and this parameter's value to zero to
			receive the required size. [out] The
			required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_GetDevice, (

		PRL_HANDLE hNetworkShapingEntry,
		PRL_STR sDev,
		PRL_UINT32_PTR pnBufLength
		) );

/* Sets the default network guaranteed rate.
   Parameters
   hNetworkShapingEntry: A handle of type PHT_NERWORK_SHAPING
			identifying the shaping entry.
   sRate:		The network rate in Kbits.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_SetRate, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32 nRate
		) );

/* \Returns the default rate for specified shaping entry.
   Parameters
   pNetworkShapingEntry:A handle of type PHT_NETWORK_SHAPING
			identifying the network shaping entry.
   pnRate:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkShapingEntry_GetRate, (

		PRL_HANDLE pNetworkShapingEntry,
		PRL_UINT32_PTR pnRate
		) );


/* Determines whether the network shaping is enabled or disabled.
   Parameters
   hConfig :      A valid handle of type PHT_NETWORK_SHAPING_CONFIG
                  identifying the adapter.
   pbEnabled :    [out] A pointer to a variable that receives the
                  \return value. PRL_TRUE indicates that the
                  network shaping is enabled. PRL_FALSE indicates
                  otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_IsEnabled, (
		PRL_HANDLE hConfig,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable the network shaping.
   Parameters
   hConfig  :  A handle of type PHT_NETWORK_SHAPING_CONFIG.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the network shaping.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_SetEnabled, (
		PRL_HANDLE hConfig,
		PRL_BOOL bEnabled
		) );

/* Obtains a list of network shaping entries
   represents the network shaping configuration.
   Parameters
   hConfig :  A valid handle of type PHT_NETWORK_SHAPING_CONFIG
              identifying the adapter.
   hList:     A pointer to a handle of type PHT_HANDLE_LIST which
              contains the list of handles of type PHT_NETWORK_SHAPING
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_GetNetworkShapingList, (
		PRL_HANDLE hConfig,
		PRL_HANDLE_PTR phList
		) );

/* Update the list of network shaping entries represents the
   network shaping  configuration.
   Parameters
   hConfig :  A valid handle of type PHT_NETWORK_SHAPING_CONFIG
              identifying the adapter.
   hList:     A handle of type PHT_HANDLE_LIST contains the
              list of handles of type PHT_NETWORK_SHAPING
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_SetNetworkShapingList, (
		PRL_HANDLE hConfig,
		PRL_HANDLE hList
		) );


/* Obtains a list of network shaping bandwidth entries
   represents the network shaping configuration.
   Parameters
   hConfig :  A valid handle of type PHT_NETWORK_SHAPING_CONFIG
              identifying the adapter.
   hList:     A pointer to a handle of type PHT_HANDLE_LIST which
              contains the list of handles of type PHT_NETWORK_SHAPING
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_GetNetworkDeviceBandwidthList, (
		PRL_HANDLE hConfig,
		PRL_HANDLE_PTR phList
		) );

/* Update the list of network device bandwidth represents the
   network shaping configuration.
   Parameters
   hConfig :  A valid handle of type PHT_NETWORK_SHAPING_CONFIG
              identifying the adapter.
   hList:     A handle of type PHT_HANDLE_LIST contains the
              list of handles of type PHT_NETWORK_SHAPING
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlNetworkShapingConfig_SetNetworkDeviceBandwidthList, (
		PRL_HANDLE hConfig,
		PRL_HANDLE hList
		) );


/* Creates a new handle of type PHT_NETWORK_SHAPING_BANDWIDTH. The handle
   is necessary to configure network shaping configuration.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   sDev:		network device name.
   nBandwidth:		Network device bandwidth
   phDeviceEntryN:[out] A pointer to a variable that receives the
                        handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */

PRL_METHOD_DECL(PARALLELS_API_VER_3,
			PrlNetworkShapingBandwidthEntry_Create, (
		PRL_CONST_STR sDev,
		PRL_UINT32 nBandwidth,
		PRL_HANDLE_PTR phDeviceEntry
		) );


/* \Sets the network device name for specified shaping entry.
   Parameters
   hDeviceEntry:	A handle of type PHT_NETWORK_SHAPING_BANDWIDTH
			identifying the network shaping entry.
   sDev:		network device name
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL(PARALLELS_API_VER_3,
			PrlNetworkShapingBandwidthEntry_SetDevice, (
		PRL_HANDLE hDeviceEntry,
		PRL_CONST_STR sDev
		) );


/* \Returns the network device name for specified shaping entry.
   Parameters
   hDeviceEntry:	A handle of type PHT_NETWORK_SHAPING_BANDWIDTH
			identifying the network shaping entry.
   sDev:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL(PARALLELS_API_VER_3,
			PrlNetworkShapingBandwidthEntry_GetDevice, (
		PRL_HANDLE hDeviceEntry,
		PRL_STR sDev,
		PRL_UINT32_PTR pnBufLength
		) );


/* \Sets the network device bandwidth for specified shaping entry.
   Parameters
   hDeviceEntry:	A handle of type PHT_NETWORK_SHAPING_BANDWIDTH
			identifying the network shaping entry.
   nBandwidth:		Network device bandwidth
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL(PARALLELS_API_VER_3,
			PrlNetworkShapingBandwidthEntry_SetBandwidth, (
		PRL_HANDLE hDeviceEntry,
		PRL_UINT32 nBandwidth
		) );


/* \Returns the network device bandwidth for specified shaping entry.
   Parameters
   hDeviceEntry:	A handle of type PHT_NETWORK_SHAPING_BANDWIDTH
			identifying the network shaping entry.
   pnBandwidth:		[out] A pointer to a buffer that receives
			the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL(PARALLELS_API_VER_3,
			PrlNetworkShapingBandwidthEntry_GetBandwidth, (
		PRL_HANDLE hDeviceEntry,
		PRL_UINT32_PTR pnBandwidth
		) );


/* Creates a new handle of type PHT_NETWORK_RATE. The handle
   is necessary to configure Vm output bandwidth.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   nClassId:		Network class id
   nRate:		Specifies bound rate for network class
   phNetwork:		[out] A pointer to a variable that receives the
                        handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkRate_Create, (
		PRL_UINT32 nClassId,
		PRL_UINT32 nRate,
		PRL_HANDLE_PTR phNetworkRate
		) );


/* \Returns the network rate entry class id.
   Parameters
   hNetworkRate:	A handle of type PHT_NETWORK_RATE
			identifying the network rate entry.
   pnClassId:		[out] A pointer to a buffer that receives
                        the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkRate_GetClassId, (
		PRL_HANDLE hNetworkRate,
		PRL_UINT32_PTR pnClassId
		) );


/* \Returns the network rate entry Rate value.
   Parameters
   hNetworkRate:	A handle of type PHT_NETWORK_RATE
			identifying the network rate entry.
   pnRate:		[out] A pointer to a buffer that receives
                        the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlNetworkRate_GetRate, (
		PRL_HANDLE hNetworkRate,
		PRL_UINT32_PTR pnRate
		) );

/* Add the specified rates list to the Vm configuration.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmCfg :		A handle of type PHT_VM_CONFIGURATION identifying
			the virtual machine configuration.
   phNetworkRateList:	A handle of type PHT_HANDLES_LIST contains the
			list of handle sof type PHT_NETWORK_RATE.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlVmCfg_SetNetworkRateList, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hNetworkRateList
		) );

/* Obtains the list of shaping rated
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   phNetworkRateList:	[out] A pointer to the PHT_HANDLES_LIST
			handle containing the list of handle sof type
			PHT_NETWORK_RATE.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate the object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSearchDomains                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlVmCfg_GetNetworkRateList, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phNetworkRateList
		) );

/* Determines whether the ratebound is enabled or not.
   Parameters
   hVmCfg :		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   pbEnabled :		[out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						 PrlVmCfg_IsRateBound, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
                ) );

/* Sets the ratebound flag.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   bEnabled:		If this parameter is set to PRL_TRUE then Vm output bandwidth
			specified by rate will be bandwidth limit and guarantee.
			Otherwise rate sets Vm output bandwidth guarantee for traffic and
			limit is set by TOTALRATE in the network shaping Configuratio,.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						 PrlVmCfg_SetRateBound, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL bEnabled
                ) );

/* Sets the specified virtual machine default gateway.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
                           configuration.
   sNewVmDefaultGateway :  The default gateway to set. The value
                           must be a a UTF\-8 encoded,
                           null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetDefaultGateway, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmDefaultGateway
		) );


/* Sets the specified virtual machine default gateway (IPv6).
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
                           configuration.
   sNewVmDefaultGateway :  The default gateway to set. The value
                           must be a a UTF\-8 encoded,
                           null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetDefaultGatewayIPv6, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmDefaultGateway
		) );


/* \Returns the default gateway of the specified virtual
   machine.
   Parameters
   hVmCfg :						 A handle of type PHT_VM_CONFIGURATION
								 identifying the virtual machine
								 configuration.
   sVmDefaultGateway :           [out] A pointer to a buffer that receives
								 the result (a UTF\-8 encoded,
								 null\-terminated string).
   pnVmDefaultGatewayBufLength : [in] The size of the output buffer (in
								 bytes). Set the buffer pointer to null
								 and this parameter's value to zero to
								 receive the required size. [out] The
								 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetDefaultGateway, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmDefaultGateway,
		PRL_UINT32_PTR pnVmDefaultGatewayBufLength
		) );

/* \Returns the default gateway (IPv6) of the specified virtual
   machine.
   Parameters
   hVmCfg :						 A handle of type PHT_VM_CONFIGURATION
								 identifying the virtual machine
								 configuration.
   sVmDefaultGateway :           [out] A pointer to a buffer that receives
								 the result (a UTF\-8 encoded,
								 null\-terminated string).
   pnVmDefaultGatewayBufLength : [in] The size of the output buffer (in
								 bytes). Set the buffer pointer to null
								 and this parameter's value to zero to
								 receive the required size. [out] The
								 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetDefaultGatewayIPv6, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmDefaultGateway,
		PRL_UINT32_PTR pnVmDefaultGatewayBufLength
		) );


/* \Returns the hard disk block size.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pnnBytes :    [out] Pointer to a variable that receives the
                 hard disk size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_SetDiskSize                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlVmDevHd_GetBlockSize, (
		PRL_HANDLE hVmDev,
		PRL_UINT32_PTR pnBytes
		) );

/* Sets the block size of the specified virtual hard disk. Use this
   function when adding a new virtual hard disk or when
   modifying the size of an existing disk.
   Parameters
   hVmDev :     A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                identifying the virtual hard disk.
   nBytes:      The new size in bytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetDiskSize                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlVmDevHd_SetBlockSize, (
		PRL_HANDLE hVmDev,
		PRL_UINT32 nBytes
		) );

/* Determines whether the 3D graphical acceleration technology is
   available in the virtual machine video.
   Parameters
   handle :             A handle of type PHT_VIRTUAL_MACHINE
                        identifying the virtual machine.
   pbVm3DAccelerationEnabled :  A pointer to a variable that receives the
                        \result. PRL_TRUE indicates that the 3D
                        acceleration is available. PRL_FALSE
                        indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_Is3DAccelerationEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVm3DAccelerationEnabled
		) );

/* Sets 3D graphical acceleration technology mode (enabled or disabled)
   for the specified virtual machine.
   Parameters
   handle :             A handle of type PHT_VIRTUAL_MACHINE
                        identifying the virtual machine.
   bVm3DAccelerationEnabled :  Setting value. Perform PRL_TRUE
                               to enable the 3D acceleration.
                               Perform PRL_FALSE to disable last one.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_Set3DAccelerationEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVm3DAccelerationEnabled
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Parallels HA processing.
///////////////////////////////////////////////////////////////////////////////

/* \Start HA service by service name
   Parameters
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
                                 PrlSrv_StartClusterService, (
                PRL_HANDLE hServer,
                PRL_CONST_STR sServiceName,
                PRL_UINT32 nFlags
                ) );

/* \Stop HA service by service name
   Parameters
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
                                 PrlSrv_StopClusterService, (
                PRL_HANDLE hServer,
                PRL_CONST_STR sServiceName,
                PRL_UINT32 nFlags
                ) );


/* Allows to activate/deactivate cluster mode.
   Parameters
   hDispConfig :     A handle of type PHT_DISP_CONFIG.
   bClusterMode :    To activate cluster mode, set this
                     parameter to PRL_TRUE.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                        PrlDispCfg_SetClusterMode, (
                PRL_HANDLE hDispConfig,
                PRL_BOOL bClusterMode
                ) );

/* Determines whether Parallels product operates in cluster mode.
   Parameters
   hDispConfig :      A handle of type PHT_DISP_CONFIG.
   pbClusterMode :    [out] A pointer to a variable that receives
                      the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                        PrlDispCfg_IsClusterMode, (
                PRL_HANDLE hDispConfig,
                PRL_BOOL_PTR pbClusterMode
                ) );

/* Set proxy manager URL string.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sNewURL :  Proxy manager URL string. Pass empty string
			  to set default URL.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_CANT_CHANGE_PROXY_MANAGER_URL - proxy is not disabled.

   PRL_ERR_CANT_CHANGE_PROXY_MANAGER_URL_BY_NON_PRIVILEGED_USER -
   only privileged user can change this setting (Win - administrator, Mac,Lin - root).

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_SetProxyManagerURL, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sNewURL
		) );

/* Get proxy manager URL string.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sURL :  [out] A pointer to a buffer that receives the result.
   pnURLBufLength: [in] The size of the output buffer (in
                   bytes). Set the buffer pointer to null
                   and this parameter's value to zero to
                   receive the required size. [out] The
                   required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_GetProxyManagerURL, (
		PRL_HANDLE hDispConfig,
		PRL_STR sURL,
		PRL_UINT32_PTR pnURLBufLength
		) );

/* Get mobile host id.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sHostId :  [out] A pointer to a buffer that receives the result.
   pnHostIdBufLength: [in] The size of the output buffer (in
                   bytes). Set the buffer pointer to null
                   and this parameter's value to zero to
                   receive the required size. [out] The
                   required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_GetHostId, (
		PRL_HANDLE hDispConfig,
		PRL_STR sHostId,
		PRL_UINT32_PTR pnHostIdBufLength
		) );

/* Set user-defined mobile host id.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sHostId :  host id value. Pass an empty string to reset
			  host id to hardware id.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_SetHostId, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sHostId
		) );


/* Requests a server to send a problem report on behalf of the given VM (its log
   is supposed to be attached to the report too) with possibility
   to append also the problem report assemblied at the client's side.

   The report should be created as follows:
    1) with PrlApi_CreateProblemReport call
    2) filled with PrlReport_Assembly

   Similar calls are PrlApi_SendProblemReport and PrlApi_SendPackedProblemReport,
   PrlReport_Send, PrlSrv_SendProblemReport

   Async response should normally contain report id.

   Parameters:
   hVm - handle of type PHT_VM
   hProblemReport - the report assemblied at the client's side
   nFlags - flags associated with the operation (see PRL_PROBLEM_REPORT_FLAGS)

    Returns:
    PRL_HANDLE - handle to the job generated					*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                 PrlVm_SendProblemReport, (
        PRL_HANDLE hVm,
        PRL_HANDLE hProblemReport,
        PRL_UINT32 nFlags
        ) );

/* The PrlApi_SendProblemReport lets to send previously extracted
   with PrlSrv_GetProblemReport or PrlVm_GetProblemReport calls
   problem report to the Parallels support server.
   Parameters
   sProblemReport :  problem report string representation (expected
					 null terminated string in UTF-8 encoding)
   bUseProxy	  :  sign specifies whether proxy settings should be used. Either
					 system proxy settings can be automatically by API call retrieved
					 and used or custom settings can be specified by follow params
					 (note that custom values override correspond system settings)
   sProxyHost      : [optional] if using proxy this param lets to specify
                     proxy server host address/name (can be null or empty)
   nProxyPort      : [optional] if using proxy this param lets to specify
                     proxy server port (should be 0 in order to specify to use system
					 settings)
   sProxyUserLogin : [optional] if using proxy this param lets to specify
					 user login if last one not specified at system proxy
					 settings or need to be overridden (can be null or empty)
   sProxyUserPasswd : [optional] if using proxy this param lets to specify
					  user password if last one not specified at system proxy
					  settings (can be null or empty)
   nProblemSendTimeout : timeout in milliseconds which specifies maximal awaiting
						 problem report send time (0 value not limiting problem
						 report send operation at all)
   nReserved		: [unused] reserved parameter for further purposes
   handler			: [optional] A pointer to a user callback function
			          (event handler) that will be called every time a
                      problem report sending progress changed or job completed.
   pUserData        : [optional] A pointer to a user data that will be
                      passed to the optional callback function.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */

PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlApi_SendProblemReport, (
		PRL_CONST_STR sProblemReport,
		PRL_BOOL bUseProxy,
		PRL_CONST_STR sProxyHost,
		PRL_UINT32 nProxyPort,
		PRL_CONST_STR sProxyUserLogin,
		PRL_CONST_STR sProxyUserPasswd,
		PRL_UINT32 nProblemSendTimeout,
		PRL_UINT32 nReserved,
		PRL_EVENT_HANDLER_PTR handler,
		PRL_VOID_PTR pUserData
		) );

/* The PrlReport_Send function is provided for convenience. It allows submitting a previously
   generated problem report to the Parallels support server. The report could be generated using
   the PrlSrv_GetPackedProblemReport (PrlSrv_GetProblemReport) or
   PrlVm_GetProblemReport (PrlVm_GetPackedProblemReport) functions, or created and assembled using
   PrlApi_CreateProblemReport/PrlReport_Assembly functions.

   Parameters
   hProblemReport   : A handle of type PHT_PROBLEM_REPORT containing report data.

   bUseProxy        : Specifies whether proxy should be used. The call can obtain and
                      use the system proxy settings or you can specify your own settings.
                      Note that custom values override system settings.

   sProxyHost       : [optional] If using proxy, this parameter allows to specify the proxy server
                      host address/name (can be null or empty).

   nProxyPort       : [optional] If using proxy, this parameter allows to specify the proxy server
                      port (to use the system setting, set this parameter to 0).

   sProxyUserLogin  : [optional] If using proxy, this parameter allows to specify user login if it’s
                      not set in the system settings (can be null or empty).

   sProxyUserPasswd : [optional] If using proxy, this parameter allows to specify the user password
                      if it’s not specified in the system settings.

   nProblemSendTimeout : Timeout in milliseconds. Can be set to 0 for unlimited timeout.

   nReserved        : [unused] Reserved parameter for future use.

   handler          : [optional] A pointer to a user callback function (event handler) that will be called
                      every time a problem report sending progress is updated or when the job is completed.

   pUserData        : [optional] A pointer to a user data that will be passed to the optional callback function.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG  invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS  function completed successfully.            */

PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_3,
					PrlReport_Send, (
		PRL_HANDLE hProblemReport,
		PRL_BOOL bUseProxy,
		PRL_CONST_STR sProxyHost,
		PRL_UINT32 nProxyPort,
		PRL_CONST_STR sProxyUserLogin,
		PRL_CONST_STR sProxyUserPasswd,
		PRL_UINT32 nProblemSendTimeout,
		PRL_UINT32 nReserved,
		PRL_EVENT_HANDLER_PTR handler,
		PRL_VOID_PTR pUserData
		) );

/* Allows to receive a problem report from the Parallels Service
   in the event of a virtual machine operation failure.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get a report from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamAsString function to obtain a
        string value containing the report.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						PrlSrv_GetProblemReport, (
		PRL_HANDLE hServer
		) );

/* The PrlVm_GetProblemReport function obtains a problem report
   on abnormal virtual machine termination. If a virtual machine
   stops running abnormally, you call this function to obtain a
   report from the Parallels Service describing the problem.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParamAsString function to obtain a
   string containing the report.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					PrlVm_GetProblemReport, (
		PRL_HANDLE hVm
		) );

/* Creates and returns a handle of type PHT_PROBLEM_REPORT,
   which is used to obtain and manage Parallels problem reports.

   Parameters
   nReportScheme : [in] the type of report that will be generated (XML based or new packed form).
   phProblemReport :  [out] A pointer to a variable that receives the handle.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer or unknown report scheme was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the problem report object.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlApi_CreateProblemReport, (
		PRL_PROBLEM_REPORT_SCHEME nReportScheme,
		PRL_HANDLE_PTR phProblemReport
		) );

/* Set web portal domain.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sWebPortalDomain :  Web portal domain string. Pass empty string
			  to set default value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_CANT_CHANGE_WEB_PORTAL_DOMAIN - proxy is not disabled.

   PRL_ERR_CANT_CHANGE_WEB_PORTAL_DOMAIN_BY_NON_PRIVILEGED_USER -
   only privileged user can change this setting (Win - administrator, Mac,Lin - root).

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_SetWebPortalDomain, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sWebPortalDomain
		) );

/* Get web portal domain.
   Parameters
   hHandle :  A handle of type PHT_DISP_CONFIG.
   sURL :  [out] A pointer to a buffer that receives the result.
   pnURLBufLength: [in] The size of the output buffer (in
                   bytes). Set the buffer pointer to null
                   and this parameter's value to zero to
                   receive the required size. [out] The
                   required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or string was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_GetWebPortalDomain, (
		PRL_HANDLE hDispConfig,
		PRL_STR sWebPortalDomain,
		PRL_UINT32_PTR pnWebPortalDomainBufLength
		) );

/**
This callback will be called when audio output data chunk has been received,
this audio chunk must be handled as quick as possible.
Do not store or free Vm handle or audio data pointer in your handler, this
callback must work in absolutely synchronous context.

Parameters
hVm       : [in] Vm handle
createCtx : [in] Pointer to the context that was registered together with callback
audioData : [in] Audio data

Returns
PRL_RESULT. Possible values
PRL_ERR_SUCCESS - data was successfully handled
other values means some error of operation
*/
typedef PRL_METHOD_PTR( PRL_AUDIO_OUTPUT_DATA_HANDLER ) (
		PRL_HANDLE hVm,
		PRL_VOID_PTR createCtx,
		const PRL_IO_AUDIO_DATA_PTR audioData
		);

/* \Sets audio output encoding for specified Vm.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   pEnc :  Encoding description. Use #PrlSrv_GetAudioEncodingList
          to have a list of supported encodings.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - specified encoding exists, request has been successfully
   sent to server. Encoding will be changed in few moments.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on server, connection is local or remote connection does not exist anymore.

   PRL_ERR_FAILURE - sending operation of encoding request has been failed.

   PRL_ERR_INVALID_ARG - pEnc pointer is wrong or hVm does not exist.*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_4,
					PrlDevAudio_SetOutputEncoding, (
		PRL_HANDLE hVm,
		const PRL_IO_AUDIO_ENCODING_PTR pEnc
		) );

/* \Gets current audio output encoding of specified Vm. Pass pOutEnc as NULL
to receive audio output encoding structure size in pInOutSz param.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   pInOutSz : In context - size of allocated memory for audio encoding;
              Out context - real size of audio encoding structure
   pOutEnc  : Encoding description as out parameter.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - out parameter has been filled with current audio output encoding.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on server, connection is local or remote connection does not exist anymore.

   PRL_ERR_INVALID_ARG - pInOutSz pointer is wrong, hVm does not exist or
pInOutSz value is too small. */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlDevAudio_GetOutputEncoding, (
		PRL_HANDLE hVm,
		PRL_UINT32_PTR pInOutSz,
		PRL_IO_AUDIO_ENCODING_PTR pOutEnc
		) );

/* \Starts audio output stream from Vm to client.
If client is not connected to vm with #PrlDevDisplay_ConnectToVm call
error will be returned, otherwise start request will be sent, PRL_ERR_SUCCESS
returned and event #PET_IO_AUDIO_STREAM_STARTED with operation status code should
be handled.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   pEnc : Audio encoding structure which should be filled correctly.
   cb   : Audio data callback, which should handle audio data as quick as possible
   cbCtx : Audio data callback context which will be passed to callback
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio output stream start request has been sent.

   PRL_ERR_FAILURE - send of output start request to Vm has been failed.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect or some pointer is invalid.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm.
   #PrlDevDisplay_ConnectToVm wasn't called.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on the server. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_4,
					PrlDevAudio_StartOutputStream, (
		PRL_HANDLE hVm,
		const PRL_IO_AUDIO_ENCODING_PTR pEnc,
		PRL_AUDIO_OUTPUT_DATA_HANDLER cb,
		PRL_VOID_PTR cbCtx
		) );

/* \Stops audio output stream.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio output stream was stopped.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm or audio
   output stream was never started.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on the server. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_4,
					PrlDevAudio_StopOutputStream, (
		PRL_HANDLE hVm
		) );

/* \Returns currently supported audio output encodings both by server and client.
If audio encodings are not supported on server
connection is local or remote connection does not exist:
PRL_ERR_FAILURE will be returned, PRL_ERR_SUCCESS otherwise.
Parameters
hServer :   A handle of type PHT_SERVER identifying
the Parallels Service.
pEncsOut :  Audio encodings structure which is filled
by this call.

Returns
PRL_RESULT. Possible values:

PRL_ERR_SUCCESS - out list has been filled with supported audio encodings.

PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
on server, connection is local or remote connection does not exist anymore.

PRL_ERR_INVALID_ARG - pEncsOut pointer is wrong or hVm does
not exist.*/
PRL_METHOD_DECL(PARALLELS_API_VER_4,
	PrlSrv_GetAudioOutputEncodingList, (
	PRL_HANDLE hSrv,
	PRL_IO_AUDIO_ENCODING_LIST_PTR pEncsOut
	));

/* To get the CPU features masks from dispatcher config
   hDispConfig :		A handle of type PHT_DISP_CONFIG.
   pMasks:			[out] A pointer to masks of processor features
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispCfg_SetCpuFeaturesMask	*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_GetCpuFeaturesMask, (
		PRL_HANDLE hDispConfig,
		PRL_CPU_FEATURES_MASK_PTR pMasks
		) );

/* Allows to set the CPU features masks. This masks will save at dispatcher config
   and will use on VM start.
   Parameters
   hDispConfig :		A handle of type PHT_DISP_CONFIG.
   pMasks:			[in] A pointer to masks of processor features
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispCfg_GetCpuFeaturesMask */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_SetCpuFeaturesMask, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_CPU_FEATURES_MASK_PTR pMasks
		) );

/* To get the CPU features from server
   hSrvConfig :			A handle of type PRL_HANDLE.
   pMasks:			[out] A pointer structure with processor features set
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlSrvCfg_GetCpuFeatures, (
		PRL_HANDLE hSrvConfig,
		PRL_CPU_FEATURES_PTR pCpuFeatures
		) );

/* Determines whether the feature service headless mode is enabled.
   Parameters
   hDispConfig: A handle of type PHT_DISP_CONFIG.
   pbEnabled: [out] A pointer to a variable that receives the result.
   PRL_TRUE indicates that the service headless mode is enabled.
   PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed. */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				 PrlDispCfg_IsHeadlessModeEnabled, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the feature service headless mode.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   bEnabled   :              [in] Action type. Specify PRL_TRUE to enable.
                             Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				 PrlDispCfg_SetHeadlessModeEnabled, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL bEnabled
		) );

/* Get internal license request parameters.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   pFlags   :                [out] A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
				 PrlDispCfg_GetLicenseRequestFlags, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32_PTR pFlags
		) );

/* Setup internal license request parameters.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   nFlags   :                [in] Internal flags.
                             Specify 0 to provide default behaviour.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
				 PrlDispCfg_SetLicenseRequestFlags, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32 nFlags
		) );


/* Determines whether the speaker is enabled or disabled during the
   virtual machine runtime.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine
                      configuration.
   pbDisableSpeaker : [out] A pointer to a variable that receives
                      the result. PRL_TRUE indicates that the speaker
                      is disabled. PBL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_IsDisableSpeaker, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbDisableSpeaker
		) );

/* Allows to specify whether the virtual machine should be using
   speaker during runtime.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   bDisableSpeaker : The value to set. Specify PRL_TRUE to enable
                     the speaker. Specify PRL_FALSE disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsDisableSpeaker                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetDisableSpeakerSign, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bDisableSpeaker
		) );

/* Resend the specified job. If an asynchronous operation was
   not completed because of full send queue (PRL_ERR_SDK_TRY_AGAIN),
   you may resend it by calling this function.
   The call does not destroy the job object.
   Parameters
   hJob :  A handle of type PHT_JOB identifying the job.
   Returns
   PRL_HANDLE to the resending job.

   PRL_INVALID_HANDLE - not enough memory to instantiate
   asynchronous operation.

   The results are retrieved using the PrlJob_GetRetCode
   function. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_JOB handle was passed.

   PRL_ERR_UNINITIALIZED - job instance was not bound to Parallels Service
   connection.                                                  */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_6,
					   PrlJob_Resend, (
		PRL_HANDLE hJob
		) );

/* \Returns the minimal size of the host's memory (RAM) consumption
   by the virtual machine, in megabytes.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnHostMemQuotaMin :  [out] A pointer to a variable that receives
                        the \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_GetHostMemQuotaMin, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnHostMemQuotaMin
		) );

/* Sets the minimal size of the host's memory (RAM) consumption
   by the virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   nHostMemQuotaMin :   The minimal RAM size to set, in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetHostMemQuotaMin, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nHostMemQuotaMin
		) );

/* Determines whether the lock in screen mode sign is set or not
   in a virtual machine configuration. Lock in screen mode is feature
   of Parallels Player product that allows to mandatory apply full
   screen mode for Parallels GUI until guest OS started and go to
   the windowed mode just after guest OS will be stopped.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbValue :    [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetLockInFullScreenMode                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsLockInFullScreenMode, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbValue
		) );

/* <unfinished>

   Enables or disables the lock in screen mode feature
   in a virtual machine configuration. Lock in screen mode is feature
   of Parallels Player product that allows to mandatory apply full
   screen mode for Parallels GUI until guest OS started and go to
   the windowed mode just after guest OS will be stopped.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bValue :    Action type. Specify PRL_TRUE to enable
               feature. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsLockInFullScreenMode                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetLockInFullScreenMode, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bValue
		) );

/* <unfinished>

   Determines whether the offline management feature is enabled
   for a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that offline
                management is available. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetOfflineManagementEnabled                           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
			PrlVmCfg_IsOfflineManagementEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* <unfinished>

   Enables or disables the offline management feature for a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable the
               offline management feature. Specify PRL_FALSE to
               disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetOfflineManagementEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Add/Updates parameters of an offline management service.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hOffmgmtService :  A handle of type PHT_OFFLINE_SERVICE identifying a
               offline management service
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_DeleteOfflineService

   PrlSrv_GetOfflineServicesList
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_UpdateOfflineService, (
		PRL_HANDLE hServer,
		PRL_HANDLE hOffmgmtService,
		PRL_UINT32 nFlags
		) );

/* Removes an existing offline service configuration.
   To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hOffmgmtService :  A handle of type PHT_OFFLINE_SERVICE identifying a
               offline management service

   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_DeleteOfflineService

   PrlSrv_GetOfflineServicesList
*/

PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_DeleteOfflineService, (
		PRL_HANDLE hServer,
		PRL_HANDLE hOffmgmtService,
		PRL_UINT32 nFlags
		) );

/* Obtains a list of handles of type PHT_OFFLINE_SERVICE
   containing information about all existing services.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParamByIndex function to obtain a handle
   of type PHT_OFFLINE_SERVICE containing the information about
   an individual offline service.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						PrlSrv_GetOfflineServicesList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


/* Creates a new handle of type PHT_OFFLINE_SRVICE. The handle
   is necessary to configure offline services. If
   you would like to manage offline service configuration, use this
   function to create the handle first and then use the handle
   functions to configure the offline services.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   phOffmgmtService :  [out] A pointer to a variable that receives the
                       handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_Create, (
		PRL_HANDLE_PTR phOffmgmtService
		) );

/* \Returns the name of the specified offline service.
   Parameters
   hOffmgmtService:       A handle of type PHT_OFFLINE_SERVICE
                          identifying the offline service.
   sname      :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnNameBufLength:       [in] The size of the output buffer (in
                          bytes). Set the buffer pointer to null
                          and this parameter's value to zero to
                          receive the required size. [out] The
                          required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_GetName, (
		PRL_HANDLE hOffmgmtService,
		PRL_STR sName,
		PRL_UINT32_PTR pnNameBufLength
		) );

/* Sets the specified offline service name.
   Parameters
   hOffmgmtService :   A handle of type PHT_OFFLINE_SERVICE
                  identifying the offline service.
   sName:         The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_SetName, (
		PRL_HANDLE hOffmgmtService,
		PRL_CONST_STR sName
		) );

/* \Returns the port of the specified offline service.
   Parameters
   hOffmgmtService:       A handle of type PHT_OFFLINE_SERVICE
                          identifying the offline service.
   sname      :           [out] A pointer to a buffer that receives
                          the result
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_GetPort, (
		PRL_HANDLE hOffmgmtService,
		PRL_UINT32_PTR pnPort
		) );
/* Sets the specified offline service port.
   Parameters
   hOffmgmtService :   A handle of type PHT_OFFLINE_SERVICE
                  identifying the offline service.
   nPort:         The value to set.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_SetPort, (
		PRL_HANDLE hOffmgmtService,
		PRL_UINT32 nPort
		) );

/* \Returns the type of the flag of the specified offline service used by default.
   Parameters
   hOffmgmtService:       A handle of type PHT_OFFLINE_SERVICE
                          identifying the offline service.
   sname      :           [out] A pointer to a buffer that receives
                          the result
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_IsUsedByDefault, (
		PRL_HANDLE hOffmgmtService,
		PRL_BOOL_PTR pbDefault
		) );

/* Sets the default flag type for the specified offline service.
   Parameters
   hOffmgmtService :   A handle of type PHT_OFFLINE_SERVICE
                      identifying the offline service.
   bDefault:          The value to set.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */


PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlOffmgmtService_SetUsedByDefault, (
		PRL_HANDLE hOffmgmtService,
		PRL_BOOL bDefault
		) );

/* <unfinished>

   Obtains the list of services available in the virtual machine
   offline management.
   Parameters
   hVmDev :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
                            configuration.
   phOfflineServicesList :  [out] A pointer to the
                            PHT_STRINGS_LIST handle containing
                            the list of offline services.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate the
   string list object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetOfflineManagementEnabled

   PrlVmCfg_SetOfflineServices                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetOfflineServices, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phOfflineServicesList
		) );

/* <unfinished>

   Allows to manually set offline services that will be
   available in the virtual machine offline management.
   Parameters
   hVmDev :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
                           configuration.
   hOfflineServicesList :  A handle of type PHT_STRINGS_LIST
                           containing the list of offline
                           services. Specify PRL_INVALID_HANDLE
                           to assign the default list of
                           services.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual machine
   specified.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetOfflineServices                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetOfflineServices, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hOfflineServicesList
		) );

/* Determines whether the High Availability feature is enabled
   or not for a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that High Availability
				is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetHighAvailabilityEnabled                           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_IsHighAvailabilityEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/*
   Enables or disables the High Availability feature for a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable the
               High Availability feature. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsHighAvailabilityEnabled                            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetHighAvailabilityEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines the priority of the virtual machine in the High Availability
   Cluster.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pnPriority :  [out] A pointer to a variable the receives
                 the priority value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetHighAvailabilityPriority                          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_GetHighAvailabilityPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnPriority
		) );

/* Sets the priority of the virtual machine in the High Availability
   Cluster.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nPriority :  The priority value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetHighAvailabilityPriority                         */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetHighAvailabilityPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nPriority
		) );

/* To get the CPU features from server
   hSrvConfig :			A handle of type PRL_HANDLE.
   pMasks:			[out] A pointer structure with processor features set
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlSrvCfg_GetCpuFeatures, (
		PRL_HANDLE hSrvConfig,
		PRL_CPU_FEATURES_PTR pCpuFeatures
		) );

/* Allows to get the CPU features from server.
   Parameters
   hSrvConfig     :  A handle of type PHT_SERVER_CONFIG.
   phCpuFeatures  :  A pointer to a variable that receives a handle of type PHT_CPU_FEATURES.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to instantiate new object.

   PRL_ERR_SUCCESS - function completed successfully.*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlSrvCfg_GetCpuFeaturesEx, (
		PRL_HANDLE hSrvConfig,
		PRL_HANDLE_PTR phCpuFeatures
		) );

/* Allows to get the CPU features masking capabilities from server
   Parameters
   hSrvConfig     :  A handle of type PHT_SERVER_CONFIG.
   phCpuFeatures  :  A pointer to a variable that receives a handle of type PHT_CPU_FEATURES.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to instantiate new object.

   PRL_ERR_SUCCESS - function completed successfully.*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlSrvCfg_GetCpuFeaturesMaskingCapabilities, (
		PRL_HANDLE hSrvConfig,
		PRL_HANDLE_PTR phCpuFeatures
		) );

/* Allows to get the CPU features masks from dispatcher config.
   hDispConfig   :  A handle of type PHT_DISP_CONFIG.
   phCpuFeatures :  A pointer to a variable that receives a handle of type PHT_CPU_FEATURES.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to instantiate new object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispCfg_SetCpuFeaturesMaskEx */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_GetCpuFeaturesMaskEx, (
		PRL_HANDLE hDispConfig,
		PRL_HANDLE_PTR phCpuFeatures
		) );

/* Allows to set the CPU features masks. This masks will be saved at dispatcher config
   and will be used on VM start.
   Parameters
   hDispConfig  :  A handle of type PHT_DISP_CONFIG.
   hCpuFeatures :  A handle of type PHT_CPU_FEATURES.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDispCfg_GetCpuFeaturesMaskEx */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlDispCfg_SetCpuFeaturesMaskEx, (
		PRL_HANDLE hDispConfig,
		PRL_HANDLE hCpuFeatures
		) );

/* Creates a new handle of type PHT_CPU_FEATURES.
   Parameters
   phCpuFeatures :  [out] A pointer to a variable that receives
                    the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the
   handle.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlCpuFeatures_Create, (
		PRL_HANDLE_PTR phCpuFeatures
		) );

/* Returns value of the specific cpu feature.
   Parameters
   hCpuFeatures :  A handle of type PHT_CPU_FEATURES.
   nId          :  Id of specific feature.
   pnValue      :  Pointer for storing result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer or invalid feature id was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlCpuFeatures_SetValue */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlCpuFeatures_GetValue, (
		PRL_HANDLE hCpuFeatures,
		PRL_CPU_FEATURES_EX nId,
		PRL_UINT32_PTR pnValue
		) );

/* Sets value of the specific feature.
   Parameters
   hCpuFeatures :  A handle of type PHT_CPU_FEATURES.
   nId          :  Id of specific feature.
   nValue       :  Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid feature id was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlCpuFeatures_GetValue */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlCpuFeatures_SetValue, (
		PRL_HANDLE hCpuFeatures,
		PRL_CPU_FEATURES_EX nId,
		PRL_UINT32 nValue
		) );

/* Sets the specified virtual machine I/O priority.
   Priority range is [PRL_IOPRIO_MIN - PRL_IOPRIO_MAX]. The greater priority is,
   the more time for I/O  activity Vm has. By default each Vm has priority of
   IO_PRIO_DEFAULT.

   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   nVmIoPriority :         io priority 0-7.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetIoPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmIoPriority
		) );

/* Determines the specified virtual machine I/O priority.

   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmIoPriority : [out] A pointer to a variable that receives the
                  result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetIoPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmIoPriority
		) );

/* Sets limit of I/O usage for the virtual machine in Bytes/s.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pVmIoLimit	       A I/O limit data of PRL_IOLIMIT_DATA type
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetIoLimit, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_IOLIMIT_DATA_PTR pVmIoLimit
		) );

/* Determines the specified virtual machine I/O limit.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmIoLimit :  [out] A pointer to a variable that receives the
                  result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetIoLimit, (
		PRL_HANDLE hVmCfg,
		PRL_IOLIMIT_DATA_PTR pVmIoLimit
		) );

/* Sets the specified virtual machine IOPS limit.

   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   nVmIopsLimit        IOPS limit.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */

PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlVmCfg_SetIopsLimit, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmIopsLimit
		) );

/* Determines the specified virtual machine IOPS limit.

   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmIopsLimit : [out] A pointer to a variable that receives the
                  result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlVmCfg_GetIopsLimit, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmIopsLimit
		) );

/* Sets the CPU usage limit (in percent) for a virtual machine.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nVmCpuLimit :  CPU usage limit from the range of 0\-100%.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCpuLimit                                          */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetCpuLimit, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmCpuLimit
		) );

/* Determines the CPU usage limit of a virtual machine, in
   percent.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   pnVmCpuLimit :  [out] A pointer to a variable that receives
                   CPU usage limit, in percent.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCpuLimit                                           */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetCpuLimit, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR nVmCpuLimit
		) );

/* Sets limit of CPU usage for the virtual machine in Mhz.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   cpulimit	       A cpulimit data of PRL_CPULIMIT_DATA type
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetCpuLimitEx, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_CPULIMIT_DATA_PTR pVmCpuLimit
		) );

/* Determines the specified virtual machine CPU limit.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmCpuLimit : [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetCpuLimitEx, (
		PRL_HANDLE hVmCfg,
		PRL_CPULIMIT_DATA_PTR pVmCpuLimit
		) );

/* Sets the CPU affinity for a virtual machine.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   sMask:	CPU affinity mask is represented by an cpu number or
		cpu range separated by the comma. (0,2,3-10)
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCpuLimit                                          */

PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetCpuMask, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sMask
		) );

/* \Returns the specified virtual machine CPU affinity mask
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sMask:		[out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnVmUuidBufLength :  [in] The size of the output buffer (in
                        bytes). Set the buffer pointer to null
                        and this parameter's value to zero to
                        receive the required size. [out] The
                        required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetCpuMask, (
		PRL_HANDLE hVmCfg,
		PRL_STR sMask,
		PRL_UINT32_PTR pnMaskBufLength
		) );

/* Sets the number of CPU units that will be allocated to a
   virtual machine. Each virtual machine on the same host can be
   allocated a number of CPU units from the range of 8 to
   \500000. The larger the number is, the more CPU time the
   virtual machine will get.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nVmCpuUnits :  The number of CPU units to allocate.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCpuUnits                                          */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetCpuUnits, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmCpuUnits
		) );

/* Determines the number of CPU units allocated to a virtual
   machine.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   pnVmCpuUnits :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCpuUnits                                           */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetCpuUnits, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR nVmCpuUnits
		) );

/* Gets state switched on or off of the adapter firewall.
   Parameters
   hVmDev    : A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER identifying
               the virtual network adapter.
   pbEnabled : [out] A pointer to a buffer that
               receives the adapter firewall state.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmDevNet_IsFirewallEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbEnabled
		) );


/* Sets state switched on or off of the adapter firewall.
   Parameters
   hVmDev    : A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER identifying
               the virtual network adapter.
   bEnabled  : The adapter firewall state.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmDevNet_SetFirewallEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bEnabled
		) );

/* Gets an adapter firewall default policy. Policy values are defined
   in the PRL_FIREWALL_POLICY enumeration.
   Parameters
   hVmDev    : A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER identifying
               the virtual network adapter.
   nDirection: Direction of a firewall - to/from the virtual network adapter
   pnPolicy : [out] A pointer to a buffer that receives
              the adapter firewall default policy.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmDevNet_GetFirewallDefaultPolicy, (
		PRL_HANDLE hVmDev,
		PRL_FIREWALL_DIRECTION nDirection,
		PRL_FIREWALL_POLICY_PTR pnPolicy
		) );


/* Sets an adapter firewall default policy. Policy values are defined
   in the PRL_FIREWALL_POLICY enumeration.
   Parameters
   hVmDev    : A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER identifying
               the virtual network adapter.
   nDirection: Direction of a firewall - to/from the virtual network adapter
   nPolicy   : An adapter firewall default policy.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmDevNet_SetFirewallDefaultPolicy, (
		PRL_HANDLE hVmDev,
		PRL_FIREWALL_DIRECTION nDirection,
		PRL_FIREWALL_POLICY nPolicy
		) );

/* \Returns the firewall rule entries list.
   Parameters
   hVmDev :     A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
                identifying the virtual network adapter.
   nDirection : Direction of a firewall - to/from the virtual network adapter
   phRuleList : [out] A pointer to a variable that receives the
                new handle of PHT_HANDLES_LIST type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the list
   or a port forward handle object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_GetFirewallRuleList, (
		PRL_HANDLE hVmDev,
		PRL_FIREWALL_DIRECTION nDirection,
		PRL_HANDLE_PTR phRuleList
		) );


/* \Sets the firewall rule entries list.
   Parameters
   hVmDev :    A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
               identifying the virtual network adapter.
   nDirection: Direction of a firewall - to/from the virtual network adapter
   hRuleList : The list of PHT_FIREWALL_RULE handles.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a port
   forward entry object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_SetFirewallRuleList, (
		PRL_HANDLE hVmDev,
		PRL_FIREWALL_DIRECTION nDirection,
		PRL_HANDLE hRuleList
		) );

/* Creates a new handle of type PHT_FIREWALL_RULE. It is the
   responsibility of the user to free the handle when it is no
   longer needed.
   Parameters
   phRule : [out] A pointer to a variable that receives the new handle.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a port
   forward handle object.

   PRL_ERR_SUCCESS - function completed successfully.               */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_Create, (
		PRL_HANDLE_PTR phRule
		) );

/* \Returns the local port.
   Parameters
   hRule :   A handle of type PHT_FIREWALL_RULE
             identifying the firewall rule.
   pnPort :  [out] A pointer to a variable that receives
             the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_GetLocalPort, (
		PRL_HANDLE hRule,
		PRL_UINT32_PTR pnPort
		) );

/* Sets the specified local port.
   Parameters
   hRule :  A handle of type PHT_FIREWALL_RULE
            identifying the firewall rule.
   nPort :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_SetLocalPort, (
		PRL_HANDLE hRule,
		PRL_UINT32 nPort
		) );

/* \Returns the remote port.
   Parameters
   hRule :   A handle of type PHT_FIREWALL_RULE
             identifying the firewall rule.
   pnPort :  [out] A pointer to a variable that receives
             the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_GetRemotePort, (
		PRL_HANDLE hRule,
		PRL_UINT32_PTR pnPort
		) );

/* Sets the specified remote port.
   Parameters
   hRule :  A handle of type PHT_FIREWALL_RULE
            identifying the firewall rule.
   nPort :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_SetRemotePort, (
		PRL_HANDLE hRule,
		PRL_UINT32 nPort
		) );

/* \Returns the protocol of the specified firewall rule entry.
   Parameters
   hRule :       A handle of type PHT_FIREWALL_RULE
                 identifying the firewall rule.
   sProtocol :   [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_GetProtocol, (
		PRL_HANDLE hRule,
		PRL_STR sProtocol,
		PRL_UINT32_PTR pnBufLength
		) );

/* Sets the specified firewall rule entry protocol.
   Parameters
   hRule :     A handle of type PHT_FIREWALL_RULE
               identifying the firewall rule.
   sProtocol : The value to set. The value must be a a UTF\-8
               encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_SetProtocol, (
		PRL_HANDLE hRule,
		PRL_CONST_STR sProtocol
		) );

/* \Returns the local address of the specified firewall rule entry.
   Parameters
   hRule :       A handle of type PHT_FIREWALL_RULE
                 identifying the firewall rule.
   sAddr :       [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_GetLocalNetAddress, (
		PRL_HANDLE hRule,
		PRL_STR sAddr,
		PRL_UINT32_PTR pnBufLength
		) );

/* Sets the specified firewall rule entry local address.
   Parameters
   hRule : A handle of type PHT_FIREWALL_RULE
           identifying the firewall rule.
   sAddr : The value to set. The value must be a a UTF\-8
           encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_SetLocalNetAddress, (
		PRL_HANDLE hRule,
		PRL_CONST_STR sAddr
		) );

/* \Returns the remote address of the specified firewall rule entry.
   Parameters
   hRule :       A handle of type PHT_FIREWALL_RULE
                 identifying the firewall rule.
   sAddr :       [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_GetRemoteNetAddress, (
		PRL_HANDLE hRule,
		PRL_STR sAddr,
		PRL_UINT32_PTR pnBufLength
		) );

/* Sets the specified firewall rule entry remote address.
   Parameters
   hRule : A handle of type PHT_FIREWALL_RULE
           identifying the firewall rule.
   sAddr : The value to set. The value must be a a UTF\-8
           encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlFirewallRule_SetRemoteNetAddress, (
		PRL_HANDLE hRule,
		PRL_CONST_STR sAddr
		) );

/* Sets barrier and limit for various user beancounters.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   nResourceIdThe	resource id (Only PCR_SWAPPAGES supported for now).
   nBarrirerThe		resource barrier.
   nLimit		The resource limit

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetResource, (
		PRL_HANDLE hVmCfg,
		PRL_CT_RESOURCE nResourceId,
		PRL_UINT64 nBarrirer,
		PRL_UINT64 nLimit
		) );

/* \Returns beancounters barrier and limit for specified resource id.
   were created on.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   nResourceId		The resource id (Only PCR_SWAPPAGES supported for now).
   pnBarrirer		[out]The resource barrier.
   pnLimit		[out]The resource limit
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.
   PRL_ERR_PARAM_NOT_FOUND - resource not found.
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetResource, (
		PRL_HANDLE hVmCfg,
		PRL_CT_RESOURCE nResourceId,
		PRL_UINT64_PTR pnBarrirer,
		PRL_UINT64_PTR pnLimit
		) );

/* \Returns name of the Container's template.
   Parameters
   hTemplate :            A handle of type PHT_CT_TEMPLATE.
   sName      :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnNameBufLength:       [in] The size of the output buffer (in
                          bytes). Set the buffer pointer to null
                          and this parameter's value to zero to
                          receive the required size. [out] The
                          required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetName, (
		PRL_HANDLE hTemplate,
		PRL_STR sName,
		PRL_UINT32_PTR pnNameLength
		) );

/* \Returns the type of the specified template.
   Parameters
   hTemplate :   A handle of type PHT_CT_TEMPLATE.
   pnType :      [out] A pointer to a variable that receives the
                 type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetType, (
		PRL_HANDLE hTemplate,
		PRL_CT_TEMPLATE_TYPE_PTR pType
		) );

/* \Returns description of the Container's template.
   Parameters
   hTemplate :             A handle of type PHT_CT_TEMPLATE.
   sDescription:           [out] A pointer to a buffer that receives
                           the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnDescriptionBufLength: [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetDescription, (
		PRL_HANDLE hTemplate,
		PRL_STR sDescription,
		PRL_UINT32_PTR pnDescriptionLength
		) );

/* \Returns version of the Container's template.
   Parameters
   hTemplate :             A handle of type PHT_CT_TEMPLATE.
   sVersion:               [out] A pointer to a buffer that receives
                           the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnVersionBufLength:     [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetVersion, (
		PRL_HANDLE hTemplate,
		PRL_STR sVersion,
		PRL_UINT32_PTR pnVersionLength
		) );

/* \Returns the type of the operating system for which the specified
   template is. The OS types are defined in the PrlOses.h file as
   macros. Look for the macros that are prefixed with
   PVS_GUEST_TYPE_ (e.g. PVS_GUEST_TYPE_LINUX).
   Parameters
   hTemplate :   A handle of type PHT_CT_TEMPLATE.
   pnOsType :    [out] A pointer to a variable that receives the
                 OS type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the OS information is not present in
   the template configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetOsType, (
		PRL_HANDLE hTemplate,
		PRL_UINT32_PTR pnOsType
		) );

/* \Returns the version of the operating system for which the
   specified template is running. The OS versions are
   defined in the PrlOses.h file as macros. Look for the macros
   that are prefixed with PVS_GUEST_VER_ (e.g.
   PVS_GUEST_VER_LIN_REDHAT).
   Parameters
   hTemplate :      A handle of type PHT_CT_TEMPLATE.
   pnOsVersion :    [out] A pointer to a variable that receives
                    the OS version.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the OS information is not present in
   the template configuration.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetOsVersion, (
		PRL_HANDLE hTemplate,
		PRL_UINT32_PTR pnOsVersion
		) );

/* \Returns the version of the operating system template for which the
   specified application template is.
   Parameters
   hTemplate :             A handle of type PHT_CT_TEMPLATE.
   sOsTemplate:            [out] A pointer to a buffer that receives
                           the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnOsTemplateLength:     [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlCtTemplate_GetOsTemplate, (
		PRL_HANDLE hTemplate,
		PRL_STR sOsTemplate,
		PRL_UINT32_PTR pnOsTemplateLength
		) );

/* Determines the specified template CPU mode (32 bit or
   64 bit).
   Parameters
   hTemplate:     A handle of type PHT_CT_TEMPLATE.
   pnCpuMode :    [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the template object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_GetCpuMode, (
		PRL_HANDLE hTemplate,
		PRL_CPU_MODE_PTR pnCpuMode
		) );

/* Determines whether the template cached.
   Makes sense only for operating system templates.
   Parameters
   hTemplate:     A handle of type PHT_CT_TEMPLATE.
   pbCached :     [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the template object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlCtTemplate_IsCached, (
		PRL_HANDLE hTemplate,
		PRL_BOOL_PTR pbCached
		) );

/* Retrieves a list of Containers templates registered with the
   specified Parallels Service. The information about each template
   is returned as a handle of type PHT_CT_TEMPLATE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamsCount function to get the
        number of templates in the result set.
     3. Use the PrlResult_GetParamByIndex function in a loop, or
        by passing a specific index, to obtain a handle to each
        template.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			   PrlSrv_GetCtTemplateList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* Removes the specified Containers template.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   Parameters
   hServer    : A handle of type PHT_SERVER identifying the Parallels
                Service.
   sName      : Name of template to be removed.
   sOsTmplName: Name of OS template for which this application template is.
                Should be filled for application templates.
   nFlags     : Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_RemoveCtTemplate, (
		PRL_HANDLE hServer,
		PRL_CONST_STR sName,
		PRL_CONST_STR sOsTmplName,
		PRL_UINT32 nFlags
		) );

/* Copy the specified Containers template to the specified server.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   Parameters
   hSrv       : A handle of type PHT_SERVER identifying the Parallels
                Service.
   sName      : Name of template to be removed.
   sOsTmplName: Name of OS template for which this application template is.
                Should be filled for application templates.
   sTargetServerHostname : target server hostname
   nTargetServerPort     : target server port
   sTargetServerSessionUuid: target server session uuid
   nFlags     : Command flags.
   nReservedFlags : Reserved command flags.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_CopyCtTemplate, (
		PRL_HANDLE hSrv,
		PRL_CONST_STR sName,
		PRL_CONST_STR sOsTmplName,
		PRL_CONST_STR sTargetServerHostname,
		PRL_UINT32 nTargetServerPort,
		PRL_CONST_STR sTargetServerSessionUuid,
		PRL_UINT32 nFlags,
		PRL_UINT32 nReservedFlags
		) );

/* \Returns the list of application templates installed for the specified
   Container. This option acceptable for Virtual Machine of PVT_CT only.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   phAppList:		[out] A pointer to a variable that receives the
			PHT_STRINGS_LIST handle containing the list of
			application templates.
   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a string object.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_GetAppTemplateList, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phAppList
		) );

/* Specify application templates list which will be used in the specified
   Parallels Virtuozzo Container.
   This option acceptable for Virtual Machine of PVT_CT only.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   hAppList:		A handle of type PHT_STRINGS_LIST
			that specifies the list of application templates
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetAppTemplateList, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hAppList
		) );

/* Specify the Virtual Machine Operation System template name
   which will be used to create new Parallels Virtuozzo Container.
   This option acceptable for Virtual Machine of PVT_CT only.
   sOsTemplate		ostemplate name.
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlVmCfg_SetOsTemplate, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sOsTemplate
		) );

/* \Returns Operation System template name the Parallels Virtuozzo Container
   sOsTemplate:		[out] A pointer to a buffer that receives
			the result.
   pnBufLength:		[in] The size of the output buffer (in
			bytes). Set the buffer pointer to null
			and this parameter's value to zero to
			receive the required size. [out] The
			required output buffer size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						PrlVmCfg_GetOsTemplate, (
		PRL_HANDLE hVmCfg,
		PRL_STR sOsTemplate,
		PRL_UINT32_PTR pnBufLength
		) );

/* Returns a capabilities mask specified inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnCapMask :    [out] A pointer to a bitmask containing the supported
                  capabilities.  For available options see
                  the PRL_CT_CAPMASK enumeration and
                  CAPDEFAULTMASK defined in PrlEnums.h as macros.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetCapabilitiesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnCapMask
		) );

/* Sets a capabilities inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nCapMask :     [in] A bitmask containing the supported
                  capabilities.  For available options see
                  the PRL_CT_CAPMASK enumeration and
                  CAPDEFAULTMASK defined in PrlEnums.h as macros.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetCapabilitiesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nCapMask
		) );

/* Returns a features mask specified inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnOn :         [out] A pointer to a bitmask containing the enabled
                  features. For available options see
                  the PRL_CT_FEATURES enumeration.
   pnOff :        [out] A pointer to a bitmask containing the disabled
                  features. For available options see
                  the PRL_CT_FEATURES enumeration.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetFeaturesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnOn,
		PRL_UINT32_PTR pnOff
		) );

/* Sets a features inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nOn:           [in] A bitmask of enabled features.
                  For available options see
                  the PRL_CT_FEATURES enumeration
   nOff:          [in] A bitmask of disabled features.
                  For available options see
                  the PRL_CT_FEATURES enumeration

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetFeaturesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nOn,
		PRL_UINT32 nOff
		) );

/* Returns a features mask specified inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnOn :         [out] A pointer to a bitmask containing the enabled
                  features. For available options see
                  the PRL_CT_FEATURES enumeration.
   pnOff :        [out] A pointer to a bitmask containing the disabled
                  features. For available options see
                  the PRL_CT_FEATURES enumeration.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetFeaturesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnOn,
		PRL_UINT32_PTR pnOff
		) );

/* Sets a features inside the CT.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nOn:           [in] A bitmask of enabled features.
                  For available options see
                  the PRL_CT_FEATURES enumeration
   nOff:          [in] A bitmask of disabled features.
                  For available options see
                  the PRL_CT_FEATURES enumeration

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetCapabilitiesMask                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetFeaturesMask, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nOn,
		PRL_UINT32 nOff
		) );

/* Returns netfilter mode specified inside the CT.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnMode  : [out] A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetNetfilterMode                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetNetfilterMode, (
		PRL_HANDLE hVmCfg,
		PRL_NETFILTER_MODE_PTR pnMode
		) );

/* Allows to set netfilter mode inside the CT.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   nMode  : [in] The netfilter mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetNetfilterMode                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetNetfilterMode, (
		PRL_HANDLE hVmCfg,
		PRL_NETFILTER_MODE nMode
		) );

/* Returns the auto compress flag of the specified virtual hard disk.
   (for Virtuozzo Container only)
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pbEnabled :   [out] A pointer to a variable that
                 receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_IsAutoCompressEnabled,		*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmDevHd_IsAutoCompressEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbEnabled
		) );

/* Sets the auto compress sign flag of the specified virtual hard disk.
   (for Virtuozzo Container only)
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   bEnabled :    Specify PRL_FALSE to disable auto compress

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetMountPoint				*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmDevHd_SetAutoCompressEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bEnabled
		) );

/* Sets the mount point of the specified virtual hard disk.
   (for Virtuozzo Container only)
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   sMountPoint : Mount point path

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetMountPoint                            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlVmDevHd_SetMountPoint, (
               PRL_HANDLE hVmDev,
               PRL_CONST_STR sMountPoint
               ) );

/* Returns the mount point of the specified virtual hard disk.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   sMountPoint :            [out] A pointer to a buffer that
                            receives the result (a UTF\-8
                            encoded, null\-terminated string).
   pnMountPointBufLength :  [in] The size of the output buffer
                            (in bytes). Set the buffer pointer to
                            null and this parameter's value to
                            zero to receive the required size.
                            [out] The required output buffer
                            size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_SetMountPoint,           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlVmDevHd_GetMountPoint, (
               PRL_HANDLE hVmDev,
               PRL_STR sMountPoint,
               PRL_UINT32_PTR pnMountPointBufLength
               ) );

/* Adds a new private network to the Parallels Service
   configuration. To create a new private network, first create
   a handle of type PHT_IPPRIV_NET, configure the network
   using the handle's functions, and then call this function to
   add the network to the Parallels Service configuration.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hPrivNet :  A handle of type PHT_IPPRIV_NET identifying
               the private network to add to the Parallels
               Service configuration.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetIPPrivateNetworkList

   PrlSrv_DeleteIPPrivateNetwork

   PrlSrv_UpdateIPPrivateNetwork                                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_AddIPPrivateNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hPrivNet,
		PRL_UINT32 nFlags
		) );

/* Removes an existing private network from the Parallels
   Service configuration. To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hPrivNet :  A handle of type PHT_IPPRIV_NET identifying a
               private network.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_AddIPPrivateNetwork

   PrlSrv_GetIPPrivateNetworkList

   PrlSrv_UpdateIPPrivateNetwork                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_RemoveIPPrivateNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hPrivNet,
		PRL_UINT32 nFlags
		) );

/* Updates parameters of an existing private network. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hPrivNet :  A handle of type PHT_IPPRIV_NET identifying a
               private network.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_AddIPPrivateNetwork

   PrlSrv_GetIPPrivateNetworksList

   PrlSrv_DeleteIPPrivateNetwork                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_UpdateIPPrivateNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hPrivNet,
		PRL_UINT32 nFlags
		) );

/* Obtains a list of handles of type PHT_IPPRIV_NET
   containing information about all existing private networks.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParamByIndex function to obtain a handle
   of type PHT_IPPRIV_NET containing the information about
   a private network.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlSrv_GetIPPrivateNetworksList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* Creates a new handle of type PHT_IPPRIV_NET. The handle
   is necessary to create and configure an IP private network. If
   you would like to create a new IP private network, use this
   function to create the handle first and then use the handle
   functions to configure the network. If you would like to
   modify the configuration of an existing network, use
   the PrlSrv_GetIPPrivateNetworksList function to obtain a handle
   to the private network of interest.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   phPrivNet :  [out] A pointer to a variable that receives the
                handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_Create, (
		PRL_HANDLE_PTR phPrivNet
		) );

/* \Returns the name of the specified private network.
   Parameters
   hPrivNet :             A handle of type PHT_IPPRIV_NET
                          identifying the private network.
   sName    :             [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnNameBufLength :      [in] The size of the output buffer (in
                          bytes). Set the buffer pointer to null
                          and this parameter's value to zero to
                          receive the required size. [out] The
                          required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_GetName, (
		PRL_HANDLE hPrivNet,
		PRL_STR sName,
		PRL_UINT32_PTR pnNameBufLength
		) );

/* Sets the specified private network ID.
   Parameters
   hPrivNet :     A handle of type PHT_IPPRIV_NET
                  identifying the private network.
   sNetworkId :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_SetName, (
		PRL_HANDLE hPrivNet,
		PRL_CONST_STR sName
		) );

/* Allows to set IP addresses/Subnet masks to a private network.
   Parameters
   hPrivNet :           A handle of type PHT_IPPRIV_NET identifying
                        the private network.
   hNetAddressesList :  A handle of type PHT_STRINGS_LIST
                        containing the list of "IP address/Subnet
                        mask" pairs to be applied to the network
                        adapter. Can be PRL_INVALID_HANDLE if
                        it's necessary to specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_SetNetAddresses, (
		PRL_HANDLE hPrivNet,
		PRL_HANDLE NetAddresses
		) );

/* Obtains a list of IP addresses in the address/subnet_mask
   format which is assigned to a private network.

   \Returns the list of pairs "IP address/Subnet mask" which
   is applied to the private network. The result will be returned
   as list of strings (PHT_STRINGS_LIST type) of pairs "IP
   address/Subnet mask".
   Parameters
   hPrivNet :            A handle of type PHT_IPPRIV_NET identifying
                         the private network.
   phNetAddressesList :  [out] A pointer to the PHT_STRINGS_LIST
                         handle containing the IP addresses.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate strings
   list object.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_GetNetAddresses, (
		PRL_HANDLE hPrivNet,
		PRL_HANDLE_PTR pNetAddresses
		) );

/* Determines the mode (global or not) of the specified private network.
   Parameters
   hPrivNet :     A handle of type PHT_IPPRIV_NET
                  identifying the private network.
   pbGlobal :     [out] A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_IsGlobal, (
		PRL_HANDLE hPrivNet,
		PRL_BOOL_PTR pbGlobal
		) );

/* Sets the mode (global or not) of the specified private network.
   Parameters
   hPrivNet :     A handle of type PHT_IPPRIV_NET
                  identifying the private network.
   bGlobal :      The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlIPPrivNet_SetGlobal, (
		PRL_HANDLE hPrivNet,
		PRL_BOOL bGlobal
		) );

/*
   Return custom storage URL.

   Parameters
   hVmDev :         A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                    identifying the virtual hard disk.
   sURL :           [out] A pointer to a buffer that receives the result (a UTF\-8 encoded,
                    null\-terminated string).
   pnURLBufLength : [in] The size of the output buffer (in bytes). Set the buffer pointer to null
                    and this parameter's value to zero to receive the required size.
                    [out] The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.

   See Also
   PrlVmDevHd_SetStorageURL                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmDevHd_GetStorageURL, (
		PRL_HANDLE hVmDev,
		PRL_STR sURL,
		PRL_UINT32_PTR pnURLBufLength
		));

/*
   Set custom storage URL.

   A storage URL is required when actual data of a virtual hard disk is
   accessed using some external tool or protocol. For example, a VM disk
   backup, which resides on a remote server, could be attached as a data
   source using the following storage URL:
   "backup://backup_server/backup_UUID/disk_number".
   Here, instead of reading data from the locally stored disk image, a VM will
   connect to the "backup_server" and read data from the "backup_UUID/disk_number"
   backup.

   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   sURL   :     [in] Storage URL - an UTF-8 encoded string with null '\0' symbol at the end.
                The following URL types are supported:
                "backup://backup_server/backup_UUID/disk_number" - use disk backup,
                identified by "backup_UUID/disk_number" from server "backup_server".
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   See Also
   PrlVmDevHd_GetStorageURL                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmDevHd_SetStorageURL, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sURL
		));

/* Backup an existing virtual machine to backup server.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Note: errors are the same as for VmMigrate activity

   Parameters
   hSourceServer :     A handle of type PHT_SERVER
                       identifying the source Parallels Service.
   sVmUuid :           A virtual machine uuid
   sTargetHost:        The name of the target host machine.
   nTargetPort:        The port number on the target host.
   sTargetSessionId:   The target Parallels Service session ID.
   sDescription:       The backup description.
   backup_flags :      Flags that specify backup type and etc. Acceptable flags:
   PBT_FULL		: full backup
   PBT_INCREMENTAL	: incremental backup
   PBT_DIFFERENTIAL	: differental backup
   PBT_UNCOMPRESSED	: uncompressed backup (by default fast zip compression used)
                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved flags.
   force_operation :   Specifies to process VM backup action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_CreateVmBackup, (
		PRL_HANDLE hSourceServer,
		PRL_CONST_STR sVmUuid,
		PRL_CONST_STR sTargetHost,
		PRL_UINT32 nTargetPort,
		PRL_CONST_STR sTargetSessionId,
		PRL_CONST_STR strDescription,
		PRL_UINT32 backup_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Get backups tree from backup server.

   Some of the important XML elements are:

   \<VmItem\> - root element of a branch containing
   information about a virtual machine. This element, in turn, may contain
   a set of elements describing full backups of this virtual machine.

   \<BackupItem\> - root element of a branch containing
   information about a full backup. This element, in turn, may contain a set
   of elements describing incremental backups of this full backup.

   \<PartialBackupItem\> - root element of a branch containing
   information about an incremental backup.

   \<Id\> - the backup ID. The ID is required when performing other
   operations on a backup.

   \<DateTime\> - the backup creation date and time.

   \<Type> - backup type {'f' - full, 'i' - incremental}

   \<Size> Backup size in bytes

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_INVALID_PARAM - invalid combination of backup_flags was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get a backup tree from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamAsString function to obtain a
        string value containing the backup tree XML data.
   Please note that no parser is provided to traverse the
   returned XML. To use this functionality, you will have to
   parse the returned XML yourself.

   Parameters
   hSourceServer :     A handle of type PHT_SERVER
                       identifying the source Parallels Service.
   sUuid :             A virtual machine or a backup ID. If it is empty,
                       the tree will be built for backups of all virtual machines.
                       When PBT_BACKUP_ID or PBT_CHAIN flag is specified in
                       the backup_flags argument, then the value of this argument
                       is treated as a backup ID, otherwise - as a virtual machine UUID.
   sTargetHost:        The name of the target host machine.
   nTargetPort:        The port number on the target host.
   sTargetSessionId:   The target Parallels Service session ID.
   backup_flags :      Flags that specify backup type and etc. Acceptable flags:
   	   	   	   	   	   PBT_VM - include only virtual machine backups (used by default
   	   	   	   	   	   if PBT_VM and PBT_CT flags are not specified)
   	   	   	   	   	   PBT_CT - include only container backups
                       PBT_BACKUP_ID - get information about the backup, which identifier is
                       specified in sUuid parameter. Note that if an identifier of an
                       incremental backup is passed in the sUuid parameter, then
                       the output tree would also contain the corresponding full backup element.
                       PBT_CHAIN - get information about the whole backup chain, which
                       is dependent on the backup identifier, specified in sUuid parameter.
                       Note that if an identifier of an incremental backup is passed in
                       the sUuid parameter, then the output tree would also contain
                       the corresponding full backup element.

                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved flags.
   force_operation :   Specifies to process VM backup action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_GetBackupTree, (
		PRL_HANDLE hSourceServer,
		PRL_CONST_STR sUuid,
		PRL_CONST_STR sTargetHost,
		PRL_UINT32 nTargetPort,
		PRL_CONST_STR sTargetSessionId,
		PRL_UINT32 backup_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Restore backup of the virtual machine from backup server.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Note: errors are the same as for VmMigrate activity

   Parameters
   hSourceServer :     A handle of type PHT_SERVER
                       identifying the source Parallels Service.
   sVmUuid :           A virtual machine uuid
   sBackupUuid :       A backup uuid
   sTargetHost:        The name of the target host machine.
   nTargetPort:        The port number on the target host.
   sTargetSessionId:   The target Parallels Service session ID.
   sTargetVmHomePath : Home directory of the target virtual machine.
   restore_flags :     Flags that specify restore type and etc. Acceptable flags:
   PBT_RESTORE_TO_COPY	: change Vm name/uuid/MAC address on restore
                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved flags.
   force_operation :   Specifies to process VM backup action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_RestoreVmBackup, (
		PRL_HANDLE hSourceServer,
		PRL_CONST_STR sVmUuid,
		PRL_CONST_STR sBackupUuid,
		PRL_CONST_STR sTargetHost,
		PRL_UINT32 nTargetPort,
		PRL_CONST_STR sTargetSessionId,
		PRL_CONST_STR sTargetVmHomePath,
		PRL_CONST_STR sTargetVmName,
		PRL_UINT32 restore_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Remove backup of the virtual machine from backup server.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Note: errors are the same as for VmMigrate activity

   Parameters
   hSourceServer :     A handle of type PHT_SERVER
                       identifying the source Parallels Service.
   sVmUuid :           A virtual machine uuid
   sBackupUuid :       A backup uuid
   sTargetHost:        The name of the target host machine.
   nTargetPort:        The port number on the target host.
   sTargetSessionId:   The target Parallels Service session ID.
   remove_flags :      Flags that specify remove type and etc. Acceptable flags:
                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved flags.
   force_operation :   Specifies to process VM backup action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_RemoveVmBackup, (
		PRL_HANDLE hSourceServer,
		PRL_CONST_STR sVmUuid,
		PRL_CONST_STR sBackupUuid,
		PRL_CONST_STR sTargetHost,
		PRL_UINT32 nTargetPort,
		PRL_CONST_STR sTargetSessionId,
		PRL_UINT32 remove_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* \Returns the UUID (universally unique ID) of the created backup
   Parameters
   hBackupResult :         A handle of type PHT_BACKUP_RESULT
                           identifying the information about created backup.
   sBackupUuid :           [out] A pointer to a buffer that receives
                     	   the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnBackupUuidBufLength : [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlBackupResult_GetBackupUuid, (
		PRL_HANDLE hBackupResult,
		PRL_STR sBackupUuid,
		PRL_UINT32_PTR pnBackupUuidBufLength
		) );

/* \Returns the default backup server host name or IP address.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sBackupServer :           [out] Pointer to a buffer that receives
                             the backup server host name or IP address
							 (a UTF\-8 encoded, null\-terminated string).
   pnBackupServerBufLength : [in] The size of the output buffer (in
                             bytes). Set the buffer pointer to null
                             and this value to zero to receive the
                             required size. [out] The required
                             \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_GetDefaultBackupServer, (
		PRL_HANDLE hDispConfig,
		PRL_STR sBackupServer,
		PRL_UINT32_PTR pnBackupServerBufLength
		) );


/* \Sets the default backup server host name or IP address.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sBackupServer :           [in] The backup server host name or IP address
							 (a UTF\-8 encoded, null\-terminated string).
							 Can be null or empty in case when an empty
							 value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_SetDefaultBackupServer, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sBackupServer
		) );

/* \Returns the backup temporary directory.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sBackupTmpDir :           [out] Pointer to a buffer that receives
                             the backup temporary directory
							 (a UTF\-8 encoded, null\-terminated string).
   pnBackupTmpDirBufLength : [in] The size of the output buffer (in
                             bytes). Set the buffer pointer to null
                             and this value to zero to receive the
                             required size. [out] The required
                             \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDispCfg_GetBackupTmpDir, (
		PRL_HANDLE hDispConfig,
		PRL_STR sBackupTmpDir,
		PRL_UINT32_PTR pnBackupTmpDirBufLength
		) );

/* \Sets the backup temporary directory.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sBackupTmpDir :           [in] The backup temporary directory
							 (a UTF\-8 encoded, null\-terminated string).
							 Can be null or empty in case when an empty
							 value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlDispCfg_SetBackupTmpDir, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sBackupTmpDir
		) );

/* \Returns the backup user login.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sUserLogin :			     [out] Pointer to a buffer that receives
                             the backup user login
							 (a UTF\-8 encoded, null\-terminated string).
   pnUserLoginBufLength :    [in] The size of the output buffer (in
                             bytes). Set the buffer pointer to null
                             and this value to zero to receive the
                             required size. [out] The required
                             \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_GetBackupUserLogin, (
		PRL_HANDLE hDispConfig,
		PRL_STR sUserLogin,
		PRL_UINT32_PTR pnUserLoginBufLength
		) );


/* \Sets the backup user login.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sUserLogin :              [in] The backup user login
							 (a UTF\-8 encoded, null\-terminated string).
							 Can be null or empty in case when an empty
							 value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_SetBackupUserLogin, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sUserLogin
		) );


/* \Sets the backup user password.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   sUserPassword :           [in] The backup user password
							 (a UTF\-8 encoded, null\-terminated string).
							 Can be null or empty in case when an empty
							 value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_SetBackupUserPassword, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sUserPassword
		) );


/* \Returns the backup user password enabling sign.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   pbUserPasswordEnabled :	 [out] Pointer to a buffer that receives
                             the backup user password enabling sign
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_IsBackupUserPasswordEnabled, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL_PTR pbUserPasswordEnabled
		) );


/* \Sets the backup user password.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   bUserPasswordEnabled :    [in] The backup user password enabling sign
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_SetBackupUserPasswordEnabled, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL bUserPasswordEnabled
		) );


/* \Returns PATH to the default backup directory.
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   sBackupDirectory :           [out] Pointer to a buffer that receives
                                PATH to the backup directory
                                (a UTF\-8 encoded, null\-terminated string).
   pnBackupDirectoryBufLength : [in] The size of the output buffer (in
                                bytes). Set the buffer pointer to null
                                and this value to zero to receive the
                                required size. [out] The required
                                \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_GetDefaultBackupDirectory, (
		PRL_HANDLE hDispConfig,
		PRL_STR sBackupDirectory,
		PRL_UINT32_PTR pnBackupDirectoryBufLength
		) );

/* \Sets PATH to the default backup directory.
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   sBackupDirectory :           [in] PATH to the backup directory
                                (a UTF\-8 encoded, null\-terminated string).
								Can be null or empty in case when
								an empty value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDispCfg_SetDefaultBackupDirectory, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sBackupDirectory
		) );

/* Get backup timeout in seconds.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   pnTimeout  :              [out] A pointer to a buffer that receives
                             the result
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				PrlDispCfg_GetBackupTimeout, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32_PTR pnBackupTimeout
		) );

/* Set backup timeout in seconds.
   Parameters
   hDispConfig :             A handle of type PHT_DISP_CONFIG.
   nTimeout   :              [in] timeout in seconds
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				PrlDispCfg_SetBackupTimeout, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32 nTimeout
		) );

/* Migrates an existing virtual machine to another host. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   hTargetServer :     A handle of type PHT_SERVER identifying
                       the target Parallels Service.
   target_home_path :  Target VM home path (i.e. where VM will be
                       placed on target system). Empty string
                       accounts as default VM directory path
   migration_flags :   Flags that specify migration type and etc.
                       Acceptable flags\: PVMT_COLD_MIGRATION,
                       PVMT_WARM_MIGRATION, PVMT_HOT_MIGRATION,
                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY,
                       PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved parameter for further purposes
   force_operation :   Specifies to process VM migration action
                       without asking any additional questions
                       from the Parallels Service side
                       (non\-interactive clients should use this
                       option).
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Migrate, (
		PRL_HANDLE hVm,
		PRL_HANDLE hTargetServer,
		PRL_CONST_STR target_home_path,
		PRL_UINT32 migration_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Migrates an existing virtual machine to another host.
   This is an extended version of PrlVm_Migrate function that allows to
   initiate VM migration process without active connection to target
   Parallels Service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   target_host :       The name of the target host machine.
   target_port :       The port number on the target host.
   target_session_id : The target Parallels Service session ID. This ID can be
                       retrieved with PrlLoginResponse_GetSessionUuid from the
					   response of the login request.
   target_home_path :  Target VM home path (i.e. where VM will be
                       placed on target system). Empty string accounts
					   as default VM directory path
   migration_flags :   Flags that specify migration type and etc. Acceptable flags:
                       PVMT_COLD_MIGRATION, PVMT_WARM_MIGRATION, PVMT_HOT_MIGRATION,
					   PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved parameter for further purposes
   force_operation :   Specifies to process VM migration action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_MigrateEx, (
		PRL_HANDLE hVm,
		PRL_CONST_STR target_host,
		PRL_UINT32 target_port,
		PRL_CONST_STR target_session_id,
		PRL_CONST_STR target_home_path,
		PRL_UINT32 migration_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Migrates an existing virtual machine to another host. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   hTargetServer :     A handle of type PHT_SERVER identifying
                       the target Parallels Service.
   target_name :       Target VM name (i.e. what name will be
                       given to VM on target system). Specify empty
                       string to preserve VM name from source system.
   target_home_path :  Target VM home path (i.e. where VM will be
                       placed on target system). Empty string
                       accounts as default VM directory path
   migration_flags :   Flags that specify migration type and etc.
                       Acceptable flags\: PVMT_COLD_MIGRATION,
                       PVMT_WARM_MIGRATION, PVMT_HOT_MIGRATION,
                       PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY,
                       PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved parameter for further purposes
   force_operation :   Specifies to process VM migration action
                       without asking any additional questions
                       from the Parallels Service side
                       (non\-interactive clients should use this
                       option).
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_MigrateWithRename, (
		PRL_HANDLE hVm,
		PRL_HANDLE hTargetServer,
		PRL_CONST_STR target_name,
		PRL_CONST_STR target_home_path,
		PRL_UINT32 migration_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Migrates an existing virtual machine to another host.
   This is an extended version of PrlVm_MigrateWithRename function that allows to
   initiate VM migration process without active connection to target
   Parallels Service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   target_host :       The name of the target host machine.
   target_port :       The port number on the target host.
   target_session_id : The target Parallels Service session ID. This ID can be
                       retrieved with PrlLoginResponse_GetSessionUuid from the
					   response of the login request.
   target_home_path :  Target VM home path (i.e. where VM will be
                       placed on target system). Empty string accounts
					   as default VM directory path
   migration_flags :   Flags that specify migration type and etc. Acceptable flags:
                       PVMT_COLD_MIGRATION, PVMT_WARM_MIGRATION, PVMT_HOT_MIGRATION,
					   PVMSL_LOW_SECURITY, PVMSL_NORMAL_SECURITY, PVMSL_HIGH_SECURITY
   reserved_flags :    Reserved parameter for further purposes
   force_operation :   Specifies to process VM migration action without asking
                       any additional questions from the Parallels Service side
                       (non-interactive clients should use this option).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_MigrateWithRenameEx, (
		PRL_HANDLE hVm,
		PRL_CONST_STR target_host,
		PRL_UINT32 target_port,
		PRL_CONST_STR target_session_id,
		PRL_CONST_STR target_name,
		PRL_CONST_STR target_home_path,
		PRL_UINT32 migration_flags,
		PRL_UINT32 reserved_flags,
		PRL_BOOL force_operation
		) );

/* Cancels the migration operation that was started with
   PrlVm_Migrate or PrlVm_MigrateEx. To get the return code from
   the PHT_JOB object, use the PrlJob_GetRetCode function.
   Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_MigrateCancel, (
		PRL_HANDLE hVm
		) );

/* \Returns the Container id of the specified
   virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnEnvId:		[out] Container id
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                                 PrlVmCfg_GetEnvId, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnEnvId
                ) );

/* Specify the Virtual Machine type on create action.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   nType		Virtuam Machine type.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						 PrlVmCfg_SetVmType, (
                PRL_HANDLE hVmCfg,
		PRL_VM_TYPE nType
                ) );

/* Get the Virtual Machine type.
   Parameters
   hVmCfg:		A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   pnType :		[out] A pointer to a variable that receives the
			\result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						 PrlVmCfg_GetVmType, (
                PRL_HANDLE hVmCfg,
		PRL_VM_TYPE_PTR pnType
                ) );

/* Obtains path of the directory in which new Container
   are created by default.
   Parameters
   hDispConfig :              A handle of type PHT_DISP_CONFIG.
   sDefaultDir :              [out] A pointer to a buffer that
                              receives the directory name (a
                              UTF\-8 encoded, null\-terminated
                              string).
   pnDefaultDirBufLength :    [in] The size of the output buffer
                              (in bytes). Set the buffer pointer
                              to null and this value to zero to
                              receive the required size. [out]
                              The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDispCfg_GetDefaultCtDir, (
		PRL_HANDLE hDispConfig,
		PRL_STR sDefaultDir,
		PRL_UINT32_PTR pnDefaultDirBufLength
		) );

/* Mount the specified virtual machine Virtual Disks.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   sMntPath: not used
   nFlags: Mount flags of type PRL_MOUNT_VIRTUAL_DISK
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVm_Mount, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sMntPath,
		PRL_UINT32 nFlags
		) );

/* Unmount the specified virtual machine Virtual Disks.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
*/

PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVm_Umount, (
		PRL_HANDLE hVm,
		PRL_UINT32 nFlags
		) );

/* Obtains the virtual network ID assigned to a virtual network
   adapter in a virtual machine.
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sVirtualNetworkId :      [out] A pointer to a buffer that
                            receives the virtual network ID
                            (a UTF\-8 encoded, null\-terminated
                            string).
   pnVirtNetIdBufLength :   [in] The size of the output buffer
                            (in bytes). Set the buffer pointer to
                            null and this value to zero to
                            receive the required size. [out] The
                            required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetVirtualNetworkId                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_GetVirtualNetworkId, (
		PRL_HANDLE hVmDev,
		PRL_STR sVirtualNetworkId,
		PRL_UINT32_PTR pnVirtualNetworkIdBufLength
		) );

/* Allows to set the virtual network ID for a network adapter in
   a virtual machine.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   sNewVirtualNetworkId :  The new virtual network ID. The
                         specified string must be encoded using
                         UTF\-8 and must be terminated with the
                         binary zero character. Can be null or empty
						 in order to drop virtual network ID device
						 field.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetVirtualNetworkId                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetVirtualNetworkId, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewVirtualNetworkId
		) );

/* Obtains a new handle of type PHT_VIRTUAL_MACHINE. Obtaining a
   new PHT_VIRTUAL_MACHINE handle is the first step when
   creating a virtual machine. The second step is setting the
   virtual machine configuration parameters. The final step is
   calling the PrlVm_Reg function, which will create a new
   virtual machine.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_VIRTUAL_MACHINE.

   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   pParam :   Pointer to the PRL_GET_VM_CONFIG_PARAM_DATA structure.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					PrlSrv_GetDefaultVmConfig, (
		PRL_HANDLE hServer,
		PRL_CONST_GET_VM_CONFIG_PARAM_DATA_PTR pParam,
		PRL_UINT32 nFlags
		) );

/* Specify the Configuration sample file
   Parameters
   hVmCfg:              A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine
                       configuration.
   ConfigSample         Configurationsample name name.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                                                PrlVmCfg_ApplyConfigSample, (
                PRL_HANDLE hVmCfg,
                PRL_CONST_STR sConfigSample
                ) );

/* Determines whether EFI boot is switched on.
   Parameters
   handle :       A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   pbEfiEnabled : A pointer to a variable that receives the
                  \result. PRL_TRUE indicates that the EFI boot is switched on.
                  PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_IsEfiEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEfiEnabled
		) );

/* Sets EFI boot for the virtual machine.
   for the specified virtual machine.
   Parameters
   handle :      A handle of type PHT_VIRTUAL_MACHINE
                 identifying the virtual machine.
   bEfiEnabled : Setting value. Perform PRL_TRUE
                 to switch on EFI boot.
                 Perform PRL_FALSE to switch off last one.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetEfiEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEfiEnabled
		) );

/* Online activation of installed Parallels license.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.
   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
   1. Use the PrlJob_GetResult function to obtain a handle to
   the PHT_RESULT object.
   2. Use the PrlResult_GetParam function to obtain a handle
   of type PHT_LICENSE containing the license information.

   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   nFlags:     Flags

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
							PrlSrv_ActivateInstalledLicenseOnline, (
							PRL_HANDLE hServer,
							PRL_UINT32 nFlags
							) );

/* Offline activation of installed Parallels license.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.
   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
   1. Use the PrlJob_GetResult function to obtain a handle to
   the PHT_RESULT object.

   2. Use the PrlResult_GetParam function to obtain a handle
   of type PHT_LICENSE containing the license information.

   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   sConfirmationId: A string with confirmation ID which is necessary to offline activation
   nFlags:     Flags

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
							PrlSrv_ActivateInstalledLicenseOffline, (
							PRL_HANDLE hServer,
							PRL_CONST_STR sConfirmationId,
							PRL_UINT32 nFlags
							) );

/* \Returns the license user name.
   Parameters
   hLicense :             A handle of type PHT_LICENSE
                          identifying the license.
   sUserName :            [out] A pointer to a buffer that
                          receives the user name (a UTF\-8
                          encoded, null\-terminated string).
   pnUserNameBufLength :  [in] The size of the output buffer (in
                          bytes). Set the buffer pointer to null
                          and this parameter's value to zero to
                          receive the required size. [out]
                          The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_NO_DATA - the specified license object does not
   contain license data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlLic_GetUserName, (
		PRL_HANDLE hLicense,
		PRL_STR sUserName,
		PRL_UINT32_PTR pnUserNameBufLength
		) );

/* \Returns the name of the company to which this license was
   issued.
   Parameters
   hLicense :                A handle of type PHT_LICENSE
                             identifying the license.
   sCompanyName :            [out] A pointer to a buffer that
                             receives the name (a UTF\-8 encoded,
                             null\-terminated string).
   pnCompanyNameBufLength :  [in] The size of the output buffer
                             (in bytes). Set the buffer pointer
                             to null and this value to zero to
                             receive the required size. [out]
                             The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_NO_DATA - the specified license object does not
   contain license data.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlLic_GetCompanyName, (
		PRL_HANDLE hLicense,
		PRL_STR sCompanyName,
		PRL_UINT32_PTR pnCompanyNameBufLength
		) );

/* \Returns default encryption plugin Id.
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   sDefaultPluginId :           [out] Pointer to a buffer that receives
                                default encryption plugin Id
                                (a UTF\-8 encoded, null\-terminated string).
								It is empty string for default Parallels encryption plugin

   pnDefaultPluginIdBufLength : [in] The size of the output buffer (in
                                bytes). Set the buffer pointer to null
                                and this value to zero to receive the
                                required size. [out] The required
                                \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispCfg_GetDefaultEncryptionPluginId, (
		PRL_HANDLE hDispConfig,
		PRL_STR sDefaultPluginId,
		PRL_UINT32_PTR pnDefaultPluginIdBufLength
		) );

/* \Sets default encryption plugin Id.
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   sDefaultPluginId :           [in] default encryption plugin Id
                                (a UTF\-8 encoded, null\-terminated string).
								Can be null or empty in case when
								an empty value should be assigned.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDispCfg_SetDefaultEncryptionPluginId, (
		PRL_HANDLE hDispConfig,
		PRL_CONST_STR sDefaultPluginId
		) );


/* Gets plugin list with plugin info entries.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   sClassId : [optional] Class GUID in text format.
   nFlags :   Reserved parameter
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlSrv_GetPluginsList, (
		PRL_HANDLE hServer,
		PRL_CONST_STR sClassId,
		PRL_UINT32 nFlags
		) );

/* Refreshes states of installed parallels plugins.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :       A handle of type PHT_SERVER identifying the
                   Parallels Service.
   nFlags :        Reserved parameter
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlSrv_RefreshPlugins, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );

/* \Returns the vendor of the plugin.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sVendor     : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetVendor, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sVendor,
		PRL_UINT32_PTR pnBufLength
		) );

/* \Returns copyright of the plugin.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sCopyright  : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetCopyright, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sCopyright,
		PRL_UINT32_PTR pnBufLength
		) );

/* \Returns short description about the plugin.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sDescr      : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetShortDescription, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sDescr,
		PRL_UINT32_PTR pnBufLength
		) );

/* \Returns long description about the plugin.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sDescr      : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetLongDescription, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sDescr,
		PRL_UINT32_PTR pnBufLength
		) );

/* \Returns the version of the plugin.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sVersion     : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
				 Format version is "Major.Minor.Build".
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetVersion, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sVersion,
		PRL_UINT32_PTR pnBufLength
		) );

/* \Returns identificator of the plugin in GUID format.
   Parameters
   hPluginInfo : A handle of type PHT_PLUGIN_INFO
                 identifying the plugin info.
   sId       : [out] A pointer to a buffer that receives
                 the result (a UTF\-8 encoded,
                 null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in
                 bytes). Set the buffer pointer to null
                 and this parameter's value to zero to
                 receive the required size. [out] The
                 required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no information about this field.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlPluginInfo_GetId, (
		PRL_HANDLE hPluginInfo,
		PRL_STR sId,
		PRL_UINT32_PTR pnBufLength
		) );


/* This function used to get default block size of disk
   Returns:
   Default block size in sectors.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_GetDefaultBlockSize, (
		PRL_UINT32_PTR Size
				) );

/* This function used to get splitted disk part size
   Returns:
   Default block size in sectors.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_GetSplitPartSize, (
		PRL_UINT64_PTR Size
				) );

/* Commits unfinished state operation (interrupted).
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the virtual disk.
   pCallback :   A pointer to a callback function or NULL
                 pointer. If the parameter contains a valid
                 pointer to the callback, the function will be
                 called asynchronously. If it contains a NULL
                 pointer, the function will be called
                 synchronously.
   pParameter :  A pointer to a buffer containing user\defined
                 data to pass to the callback function.
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                               PrlDisk_CommitUnfinishedOp, (
               // Disk handle
               const PRL_HANDLE Handle,
               // Callback
               const PRL_STATES_CALLBACK pCallback,
               // Parameter to callback
               PRL_VOID_PTR pParameter) );

/* This function used to change the key of the encrypted disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Key :			 Pointer to the raw key data
   Length :		 Key length
   NewKey :		 Pointer to the raw new key data
   NewLength :		 New key length
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_ChangeKey, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length,
		// Pointer to the new key
		PRL_UINT8_PTR NewKey,
		// New key length
		PRL_UINT32 NewLength) );

/* This function used to encrypt whole disk
   Parameters
   Handle :      A handle of type PHT_VIRTUAL_DISK identifying
                 the source virtual disk.
   Engine :		 Encryption engine used to encrypt VM
   Key :			 Pointer to the raw key data
   Length :		 Key length
   pDiskCallback :  A pointer to a callback function or NULL
                    pointer. If the parameter contains a valid
                    pointer to the callback, the function will be
                    called asynchronously. If it contains a NULL
                    pointer, the function will be called
                    synchronously.
   pParameter :     A pointer to a buffer containing user\-defined
                    data to pass to the callback function.
   Returns
   PRL_RESULT error code.                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				PrlDisk_Encrypt, (
		// Disk handle
		const PRL_HANDLE Handle,
		// Engine
		PRL_GUID_PTR Engine,
		// Pointer to the key
		PRL_UINT8_PTR Key,
		// Key length
		PRL_UINT32 Length,
		// Callback
		const PRL_DISK_CALLBACK pDiskCallback,
		// Parameter for the callback
		PRL_VOID_PTR pParameter) );


/* Determines whether the plugins enabled or not
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   pbIsPluginsAllowed :        [out] Pointer to a variable that receives the result.
                PRL_TRUE indicates that the plugins support is allowed
                PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlDispCfg_ArePluginsEnabled, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL_PTR pbIsPluginsAllowed
		) );

/* Enable or disable the plugins support
   Parameters
   hDispConfig :                A handle of type PHT_DISP_CONFIG.
   bEnablePluginsSupport :     [in] A value to set.
                               Use PRL_TRUE to enable, PRL_FALSE to disable plugins support.

   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlDispCfg_EnablePlugins, (
		PRL_HANDLE hDispConfig,
		PRL_BOOL bEnablePluginsSupport
		) );

PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlDispCfg_GetOverallMemLimit, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32_PTR pnPercentage
		) );

PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlDispCfg_SetOverallMemLimit, (
		PRL_HANDLE hDispConfig,
		PRL_UINT32 nPercentage
		) );

/* Determines whether the "Add Installed Application to Launchpad"
   feature is enabled or not.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying
			the virtual machine configuration.
   pbEnabled : [out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				PrlVmCfg_IsAddInstalledAppsToLaunchpad, (
				PRL_HANDLE hVmCfg,
				PRL_BOOL_PTR pbEnabled
		) );

/* Lets to enable or disable the "Add Installed Application to Launchpad"
   feature.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
				identifying the virtual machine configuration.
   bEnabled :      [in] Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			   PrlVmCfg_SetAddInstalledAppsToLaunchpad, (
			   PRL_HANDLE hVmCfg,
			   PRL_BOOL bEnabled
		) );


/**
 * Fill a handle of type PHT_SERVER_CONFIG with the host configuration information from string.
 * For a testing purpose only
 *
 * Parameters
 * pSrvConfig : A handle of type PHT_SERVER_CONFIG containing the host configuration information.
 * sSrvConfig : XML configuration string
 *
 * Returns
 * PRL_RESULT. Possible values:
 * PRL_ERR_INVALID_ARG - non valid PHT_SERVER_CONFIG handle or non valid (NULL) pointer to host config XML
 * representation string was passed
 * PRL_ERR_SUCCESS 	- operation successfully completed
 */
PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlSrvConfig_FromString, (
		PRL_HANDLE hSrvConfig,
		PRL_CONST_STR sSrvConfig
		) );

/* Determines if Windows task bar relocation feature is enabled
   in a virtual machine when it runs in the coherence mode.
   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine
                          configuration.
   pbVmRelocateTaskBar :  [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that the feature is enabled. PRL_FALSE
                          indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsRelocateTaskBar, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmRelocateTaskBar
		) );

/* Allows to enable or disable the Windows task bar relocation
   feature. Parallels Tools must be installed to use this
   feature. To obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
						 configuration.
   bVmRelocateTaskBar :  The value to set. Specify PRL_TRUE to
                         enable the option. Specify PRL_FALSE to
                         disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetRelocateTaskBar, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmRelocateTaskBar
		) );

/* Determines if a "Coherence Button" for the specified virtual machine should be shown
   when a user points to a Windows Start button
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine
					   configuration.
   pbVmCoherenceButtonVisibility :  [out] A pointer to a variable that
                       receives the result. PRL_TRUE indicates
                       that Coherence Button appears. PRL_FALSE indicates
                       otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetCoherenceButtonVisibility, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmCoherenceButtonVisibility
		) );

/* Sets the virtual machine "Coherence Button visibility" option.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   bVmCoherenceButtonVisibility :  The value to set. Specify PRL_TRUE to
                      show Coherence Button when a user points to a
					  Windows Start button. Specify
                      PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetCoherenceButtonVisibility, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmCoherenceButtonVisibility
		) );

/* Determines disable or enable switching off aero.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSwitchOffAeroEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables switching off aero.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSwitchOffAeroEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable hiding minimized windows.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsHideMinimizedWindowsEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables hiding minimized windows.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - no longer supported.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetHideMinimizedWindowsEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Registers an existing 3rd party virtual machine with Parallels Service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:
	 1. Use the PrlJob_GetResult function to obtain a handle to
		the PHT_RESULT object.
	 2. Use the PrlResult_GetParam function to obtain a handle
		of type PHT_VIRTUAL_MACHINE.
   Parameters
   hServer :              A handle of type PHT_SERVER identifying
						  the Parallels Service.
   strVmConfigPath :      [required] An absolute path to the virtual
						  machine configuration file (*.vmx for
						  example)
   strVmRootDirPath :     [optional] An absolute path to the virtual machine
						  root directory where virtual machine home directory
						  will be created.
   nFlags :               Flags bitset:
			0			- Default behavior
			PR3F_ALLOW_UNKNOWN_OS
						- to allow undetectable OS
			PR3F_FORCE
						- to skip errors when possible and force registration

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation, including the return code and a
   handle of type PHT_VIRTUAL_MACHINE containing information
   about the virtual machine that was registered.

   PRL_INVALID_HANDLE if there's not enough memory to
   instantiate the job object.                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_Register3rdPartyVm, (
		PRL_HANDLE hServer,
		PRL_CONST_STR strVmConfigPath,
		PRL_CONST_STR strVmRootDirPath,
		PRL_UINT32 nFlags
		) );

/* Determines the specified virtual machine CPU mode (32 bit or
   64 bit).
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmCpuMode :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetCpuMode, (
		PRL_HANDLE hVmCfg,
		PRL_CPU_MODE_PTR pnVmCpuMode
		) );

/* Sets CPU mode (32 bit or 64 bit) for the specified virtual
   machine.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   nVmCpuMode :  The CPU mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OBSOLETE_CALL_IS_NOT_SUPPORTED_ANYMORE - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetCpuMode, (
		PRL_HANDLE hVmCfg,
		PRL_CPU_MODE nVmCpuMode
		) );

/* Determines the CPU mode (32 bit or 64 bit) on the host.
   Parameters
   hSrvConfig :  A handle of type PHT_SERVER_CONFIG.
   pnCpuMode :   [out] A pointer to a variable that receives the
                 \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlSrvCfg_GetCpuMode, (
		PRL_HANDLE hSrvConfig,
		PRL_CPU_MODE_PTR pnCpuMode
		) );

#endif//__PARALLELS_API_DEPRECATED_H__
