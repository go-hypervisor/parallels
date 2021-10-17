///////////////////////////////////////////////////////////////////////////////
///
/// PrlApiVm.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_VM_H__
#define __PARALLELS_API_VM_H__

#ifdef __cplusplus
extern "C" {
#endif

// On windows platform we're taking advantage of the #pack directive
// to ensure internal structures alignment by 1 - on unixes we achive
// the same results by using the __attribute__((packed)) directive
// -> changing alignment
#ifdef _WIN_
    #pragma pack(push, save_api_pack, 1)
#endif

#include "PrlIOStructs.h"
#include "PrlKeys.h"

///////////////////////////////////////////////////////////////////////////////
/// @section Generic API methods for the client
///
/// This section consists of methods that are used for general
/// manipulation of the parallels api library and are not specific
/// to objects in the object hierarchy.
///////////////////////////////////////////////////////////////////////////////

#include "PrlApiVersion.h"


///////////////////////////////////////////////////////////////////////////////
/// @section Server object handling routines and data types.
///////////////////////////////////////////////////////////////////////////////

/* Registers an existing virtual machine with Parallels Service.

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
   strVmDirPath :         An absolute path to the virtual machine
                          directory to register.
   bNonInteractiveMode :  Set to PRL_TRUE to use non\-interactive
                          mode. Set to PRL_FALSE to use
                          interactive mode. In interactive mode,
                          a client may receive questions from the
                          Parallels Service, which it is expected
                          to answer in order for the operation to
                          continue. In non\-interactive mode, the
                          Parallels Service will make decisions
                          on its own.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation, including the return code and a
   handle of type PHT_VIRTUAL_MACHINE containing information
   about the virtual machine that was registered.

   PRL_INVALID_HANDLE if there's not enough memory to
   instantiate the job object.                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_RegisterVm, (
		PRL_HANDLE hServer,
		PRL_CONST_STR strVmDirPath,
		PRL_BOOL bNonInteractiveMode
		) );

/* Registers an existing virtual machine with Parallels Service.

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
   hServer :      A handle of type PHT_SERVER identifying
                  the Parallels Service.
   strVmDirPath : An absolute path the virtual machine
                  directory to register.
   nFlags       : A bitset of flags.
                  Allowed next values:

                  0 - no flags. It's behaviour by default ( as PrlSrv_RegisterVm() )

                  PACF_NON_INTERACTIVE_MODE	  - to use
					 non-interactive mode. In interactive mode,
					 a client may receive questions from the
					 Parallels Service, which it is expected
					 to answer in order for the operation to
					 continue. In non\-interactive mode, the
					 Parallels Service will make decisions
					 on its own.

				  PRVF_REGENERATE_VM_UUID  - to generate new VM identity after registration.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation, including the return code and a
   handle of type PHT_VIRTUAL_MACHINE containing information
   about the virtual machine that was registered.

   PRL_INVALID_HANDLE if there's not enough memory to
   instantiate the job object.                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_RegisterVmEx, (
		PRL_HANDLE hServer,
		PRL_CONST_STR strVmDirPath,
		PRL_UINT32 nFlags
		) );


/* Registers an existing virtual machine with custom Vm UUID.

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
   hServer :      A handle of type PHT_SERVER identifying
                  the Parallels Service.
   strVmDirPath : An absolute path the virtual machine
                  directory to register.
   strVmUuid	: Assign custom Vm uuid
   nFlags       : A bitset of flags.
                  Allowed next values:

                  0 - no flags. It's behaviour by default ( as PrlSrv_RegisterVm() )

                  PACF_NON_INTERACTIVE_MODE	  - to use
					 non-interactive mode. In interactive mode,
					 a client may receive questions from the
					 Parallels Service, which it is expected
					 to answer in order for the operation to
					 continue. In non\-interactive mode, the
					 Parallels Service will make decisions
					 on its own.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation, including the return code and a
   handle of type PHT_VIRTUAL_MACHINE containing information
   about the virtual machine that was registered.

   PRL_INVALID_HANDLE if there's not enough memory to
   instantiate the job object.                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
						   PrlSrv_RegisterVmWithUuid, (
		PRL_HANDLE hServer,
		PRL_CONST_STR strVmDirPath,
		PRL_CONST_STR strVmUuid,
		PRL_UINT32 nFlags
		) );

/*
	Registers an existing virtual machine with specified params.

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
	hServer : A handle of type PHT_SERVER identifying the Parallels Service.
	hParams : A handle of type PHT_VM_REGISTER_PARAMS identifying the registration params.

	Returns
	A handle of type PHT_JOB containing the results of this
	asynchronous operation, including the return code and a
	handle of type PHT_VIRTUAL_MACHINE containing information
	about the virtual machine that was registered.

	PRL_INVALID_HANDLE if there's not enough memory to
	instantiate the job object.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlSrv_RegisterVmWithParams, (
		PRL_HANDLE hServer,
		PRL_HANDLE hParams
		) );

/* Extracts supported guest OSes matrix from remote server (it's more proper
   way instead of using local synch API in case when client and server
   interoperate remotely).

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_GUEST_OSES_MATRIX which will contain complete list
		of supported guest OSes types, versions and defaults.
   Parameters
   hServer :              A handle of type PHT_SERVER identifying
                          the Parallels Service.
   phOsesMatrix :         pointer to the buffer for storing result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.
   PRL_ERR_NO_DATA - no supported OSes data (OSes matrix filling just after
                     login procedure completed). Also this field can be empty
					 in case when remote server is not supported this interface.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlSrv_GetSupportedOses, (
		PRL_HANDLE hServer,
		PRL_HANDLE_PTR phOsesMatrix
		) );


/* Obtains a new handle of type PHT_VIRTUAL_MACHINE. Obtaining a
   new PHT_VIRTUAL_MACHINE handle is the first step when
   creating a virtual machine. The second step is setting the
   virtual machine configuration parameters. The final step is
   calling the PrlVm_Reg function, which will create a new
   virtual machine.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   phVm :     [out] A pointer to a variable that receives the
              handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlSrv_CreateVm, (
					 PRL_HANDLE hServer,
					 PRL_HANDLE_PTR phVm
					 ) );

/* Retrieves a list of virtual machines registered with the
   specified Parallels Service. The information about each virtual machine
   is returned as a handle of type PHT_VIRTUAL_MACHINE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamsCount function to get the
        number of virtual machine in the result set.
     3. Use the PrlResult_GetParamByIndex function in a loop, or
        by passing a specific index, to obtain a handle to each
        virtual machine.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_GetVmList, (
		PRL_HANDLE hServer
		) );

/* Retrieves a list of virtual machines registered with the
   specified Parallels Service. The information about each virtual machine
   is returned as a handle of type PHT_VIRTUAL_MACHINE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamsCount function to get the
        number of virtual machine in the result set.
     3. Use the PrlResult_GetParamByIndex function in a loop, or
        by passing a specific index, to obtain a handle to each
        virtual machine.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   nFlags :   Obsolete.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlSrv_GetVmListEx, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


/* Searches for unregistered virtual machines at the specified
   location(s). The function can be used
   to search for virtual machines that are not currently
   registered with the specified Parallels Service but are otherwise valid
   machines to be registered with it. The virtual machine
   information is returned as a list of PHT_FOUND_VM_INFO
   objects. When the function is executed asynchronously using
   callback functionality, the callback function receives the
   information as an event of type
   PET_DSP_EVT_FOUND_LOST_VM_CONFIG.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamsCount function to get the
        number of virtual machines in the list.
     3. Use the PrlResult_GetParam function to obtain individual
        handles of type PHT_FOUND_VM_INFO.
   Parameters
   hServer :       A handle of type PHT_SERVER identifying the
                   Parallels Service.
   hStringsList :  A handle of type PHT_STRINGS_LIST containing
                   the list of pathnames to search. If the list
                   is empty, all available drives and directories
                   will be included in search scope.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_StartSearchVms, (
		PRL_HANDLE hServer,
		PRL_HANDLE hStringsList
		) );


/* Sends an appliance configuration to the Parallels Service in order to
   install the corresponding appliance from Parallels download service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :       A handle of type PHT_SERVER identifying the
                   Parallels Service.
   hAppCfg :       A handle of type PHT_APPLIANCE_CONFIG identifying the appliance.
   sVmParentPath : Optional. Name and path of the parent directory
                   where the virtual machine appliance should be installed.
                   If this parameter is omitted (null pointer or empty string
                   is passed), the new virtual machine appliance directory
                   will be created in the default directory for this
                   Parallels Service.
   nFlags :        Reserved parameter
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlSrv_InstallAppliance, (
		PRL_HANDLE hServer,
		PRL_HANDLE hAppCfg,
		PRL_CONST_STR sVmParentPath,
		PRL_UINT32 nFlags
		) );


/* Cancels the appliance installation previously started with
   the PrlSrv_InstallAppliance function call.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :       A handle of type PHT_SERVER identifying the
                   Parallels Service.
   hAppCfg :       A handle of type PHT_APPLIANCE_CONFIG identifying the appliance.
                   This must be the same handle instance that was passed
                   to the PrlSrv_InstallAppliance function.
   nFlags :        Reserved parameter
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlSrv_CancelInstallAppliance, (
		PRL_HANDLE hServer,
		PRL_HANDLE hAppCfg,
		PRL_UINT32 nFlags
		) );


/* Stops the appliance installation previously started with
   the PrlSrv_InstallAppliance function call.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :       A handle of type PHT_SERVER identifying the
                   Parallels Service.
   hAppCfg :       A handle of type PHT_APPLIANCE_CONFIG identifying the appliance.
                   This must be the same handle instance that was passed
                   to the PrlSrv_InstallAppliance function.
   nFlags :        Reserved parameter
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlSrv_StopInstallAppliance, (
		PRL_HANDLE hServer,
		PRL_HANDLE hAppCfg,
		PRL_UINT32 nFlags
		) );


/* Creates a bootable ISO-image for unattended Linux installation.
   The following steps describe how to prepare a virtual
   machine for unattended Linux installation:
     1. Create a virtual machine. The machine should have all
        the necessary devices, like hard drive and CD drive.
     2. Insert Linux installation CD-ROM into the drive (or
        mount a disk image).
     3. Execute the PrlVm_CreateUnattendedCd function to
        create a bootable ISO-image.
     4. Set created ISO-image as boot device.
     5. Start the virtual machine. The machine will boot from
        the created ISO-image.
     6. Perform unattended Windows installation as usual.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   		A handle of type PHT_SERVER identifying the
               		Parallels Service.
   nGuestDistroType :   Guest OS version from the (PVS_GUEST_VER_...).
   sPath :		Full path to the OS distribution image or folder.
   sUserName :          User name.
   sPasswd :	        Password.
   sFullUserName :      Full user name.
   sOsDistroPath :      A full path to the OS distribution image or folder.
   sOutImagePath :      A full path to output ISO-image file.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_CreateUnattendedCd, (
		PRL_HANDLE hServer,
		PRL_UINT32 nGuestType,
		PRL_CONST_STR sUserName,
		PRL_CONST_STR sPasswd,
		PRL_CONST_STR sFullUserName,
		PRL_CONST_STR sOsDistroPath,
		PRL_CONST_STR sOutImagePath
		) );




/* Get VM config by given UUID or name.
   Parameters
   hHandle :  A handle of type PHT_SERVER.
   sSearchId : VM UUID or name.
   nFlags  : Search by UUID if nFlags is 0 or PGVC_SEARCH_BY_UUID,
   	by name, if nFlags is PGVC_SEARCH_BY_NAME and search first by uuid,
	then by name if nFlags is PGVC_SEARCH_BY_UUID | PGVC_SEARCH_BY_NAME.
   Returns
   	A handle of type PHT_JOB containing the results of operation. */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
			PrlSrv_GetVmConfig, (
		PRL_HANDLE hServer,
		PRL_CONST_STR sSearchId,
		PRL_UINT32 nFlags
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Supported guest OSes extraction functions set
///////////////////////////////////////////////////////////////////////////////

/* Returns handle of type PHT_OPAQUE_TYPE_LIST which contains supported guest OSes
   types list for current API mode (see PrlApi_InitEx for more info about API mode).

   Parameters
   nHostOsType	   :  type of host system (remote or local) for which supported OSes list
					  should be retrieved. In remote work mode please determine at first
					  remote side host type (please use PrlSrvCfg_GetHostOsType for this).
					  In local work mode PHO_UNKNOWN can be passed - host OS type will be
					  automatically detected by API call in this case.
   phOsesTypesList :  [out] A pointer to a variable that receives
					  the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the
						   list object.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlApi_GetSupportedOsesTypes, (
					PRL_HOST_OS_TYPE nHostOsType,
					PRL_HANDLE_PTR phOsesTypesList
		) );

/* Returns handle of type PHT_OPAQUE_TYPE_LIST which contains supported guest OSes
   list for specified guest OS type at current API mode (see PrlApi_InitEx for more
   info about API mode).

   Parameters
   nHostOsType	   :  type of host system (remote or local) for which supported OSes list
					  should be retrieved. In remote work mode please determine at first
					  remote side host type (please use PrlSrvCfg_GetHostOsType for this).
					  In local work mode PHO_UNKNOWN can be passed - host OS type will be
					  automatically detected by API call in this case.
   nGuestOsType    :  requesting guest OS type. In order to determine list of supported
                      guests types please refer PrlOses.h
   phOsesTypesList :  [out] A pointer to a variable that receives
					  the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer or unknown OS type was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the
						   list object.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlApi_GetSupportedOsesVersions, (
					PRL_HOST_OS_TYPE nHostOsType,
					PRL_UINT8 nGuestOsType,
					PRL_HANDLE_PTR phGuestsList
		) );

/* Returns default guest OS version for specified guest OS type at current API mode
   (see PrlApi_InitEx for more info about API mode).

   Parameters
   nGuestOsType    :  requesting guest OS type. In order to determine list of supported
                      guests types please refer PrlOses.h
   pnOsVersion     :  [out] A pointer to a variable that receives
					  the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer or unknown OS type was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlApi_GetDefaultOsVersion, (
					PRL_UINT8 nGuestOsType,
					PRL_UINT16_PTR pnOsVersion
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Virtual machine OS info
///////////////////////////////////////////////////////////////////////////////

/* The PrlApi_GetRecommendMinVmMem returns recommend minimal
memory size for guest OS defined in the OS version parameter.
Parameters
nOsVersion :      OS version
pnMinMemSize :    [out] A pointer to a variable that receives
the result. Result is the recommend minimal
memory size for guest OS.
Returns
PRL_RESULT. Possible values:

PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL(PARALLELS_API_VER_2,
	PrlApi_GetRecommendMinVmMem, (
	PRL_UINT32 nOsVersion,
	PRL_UINT32_PTR pnMinMemSize
	));


///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the guest OSes matrix object.
///////////////////////////////////////////////////////////////////////////////

/* Returns handle of type PHT_OPAQUE_TYPE_LIST which contains supported guest OSes
   types list retrieved from remote server (see PrlSrv_GetSupportedOses).

   Parameters
   hOsesMatrix	   :  [in] handle of type PHT_GUEST_OSES_MATRIX.
   phOsesTypesList :  [out] A pointer to a variable that receives
					  the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer or invalid handle was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the
						   list object.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlOsesMatrix_GetSupportedOsesTypes, (
					PRL_HANDLE hOsesMatrix,
					PRL_HANDLE_PTR phOsesTypesList
		) );

/* Returns handle of type PHT_OPAQUE_TYPE_LIST which contains supported guest OSes
   list for specified guest OS type retrieved from remote server (see PrlSrv_GetSupportedOses).

   Parameters
   hOsesMatrix	   :  [in] handle of type PHT_GUEST_OSES_MATRIX.
   nGuestOsType    :  [in] requesting guest OS type. In order to determine list of supported
                      guests types please refer PrlOses.h
   phOsesTypesList :  [out] A pointer to a variable that receives
					  the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle, null pointer or unknown OS type was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the
						   list object.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlOsesMatrix_GetSupportedOsesVersions, (
					PRL_HANDLE hOsesMatrix,
					PRL_UINT8 nGuestOsType,
					PRL_HANDLE_PTR phGuestsList
		) );

/* Returns default guest OS version for specified guest OS type retrieved from remote server
   (see PrlSrv_GetSupportedOses).

   Parameters
   hOsesMatrix	   :  [in] handle of type PHT_GUEST_OSES_MATRIX.
   nGuestOsType    :  [in] requesting guest OS type. In order to determine list of supported
                      guests types please refer PrlOses.h
   pnOsVersion     :  [out] A pointer to a variable that receives
					  the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid jandle, null pointer or unknown OS type was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlOsesMatrix_GetDefaultOsVersion, (
					PRL_HANDLE hOsesMatrix,
					PRL_UINT8 nGuestOsType,
					PRL_UINT16_PTR pnOsVersion
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Virtual machine object handling routines and data types
///////////////////////////////////////////////////////////////////////////////

/* Start the specified virtual machine. This function can be
   used to start a stopped or paused virtual machine.

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
   enough memory to instantiate the job object.s
   See Also
   PrlVm_Pause                                                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Start, (
		PRL_HANDLE hVm
		) );

/* Starts the specified virtual machine using the specified mode
   (see the PRL_VM_START_MODE enumeration). Use this function
   instead of the PrlVm_Start function to start the virtual
   machine in a normal or safe mode. Other modes may be added in
   the future.

   If VM is starting in PSM_VM_START_FOR_COMPACT mode then flags
   (third argument) have to be equal PRL_HARD_DISK_IFACE_MASK enum.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or start mode of virtual
   machine.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :         A handle of type PHT_VIRTUAL_MACHINE identifying
                 the virtual machine.
   nStartMode :  Virtual machine start mode.
   nReserved :   This is a reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_StartEx, (
		PRL_HANDLE hVm,
		PRL_UINT32 nStartMode,
		PRL_UINT32 nReserved
		) );

/* Restarts the operating system of the specified virtual
   machine. To get the return code from the PHT_JOB object, use
   the PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or start mode of virtual
   machine.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Restart, (
		PRL_HANDLE hVm
		) );

/* Stop the specified virtual machine. To get the return code
   from the PHT_JOB object, use the PrlJob_GetRetCode function.
   Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :    A handle of type PHT_VIRTUAL_MACHINE identifying the
            virtual machine.
   bGraceful: If graceful shutdown is used, the machine will be properly
	    shutdown by means of Guest tools (if available), or by ACPI request,
	    If shutdown timeout expired the Vm will be forcebly stopped.
            If graceful shutdown is not used, the machine will be
            simply "unplugged"
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Stop, (
		PRL_HANDLE hVm,
		PRL_BOOL bGraceful
		) );

/* Stop the specified virtual machine. To get the return code
   from the PHT_JOB object, use the PrlJob_GetRetCode function.
   Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :	A handle of type PHT_VIRTUAL_MACHINE identifying the
		virtual machine.
   nStopMode:	Virtual machine stop mode, an enumerator from the
		PRL_VM_STOP_MODE enumeration.
   nFlags:	Virtual machine stop option, an enumerator from the
		PRL_VM_STOP_FLAGS enumeration.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */

PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVm_StopEx, (
		PRL_HANDLE hVm,
                PRL_UINT32 nStopMode,
                PRL_UINT32 nFlags
		) );

/* Pauses the specified virtual machine. A paused virtual
   machine can be resumed using the PrlVm_Start function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :    A handle of type PHT_VIRTUAL_MACHINE identifying the
            virtual machine.
   bAcpi :  Specifies if ACPI should be used to pause the virtual
            machine. If set to PRL_FALSE, ACPI will not be used.
            In this case, all processes of the virtual machine
            will simply be stopped. If the parameter is set to
            PRL_TRUE, ACPI will be used to pause the machine.
            With ACPI, the machine will be paused using a method
            supported by the guest operating system (sleep,
            hibernate, etc.). The actual method used depends on
            the type and configuration of the guest OS.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_Start                                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Pause, (
		PRL_HANDLE hVm,
		PRL_BOOL bAcpi
		) );

/* Resets the specified virtual machine. This function is an
   equivalent of PrlVm_Stop and PrlVm_Start functions executed
   in succession. The stop operation will NOT use ACPI, so the
   entire reset operation will resemble the "Reset" button
   pressed on a physical box.

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
   enough memory to instantiate the job object.                */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Reset, (
		PRL_HANDLE hVm
		) );

/* Suspends the specified virtual machine. When a running
   virtual machine is suspended, the state of the virtual
   machine processes is saved into a file on the host and after
   that the machine is stopped. To resume the machine, use the
   PrlVm_Resume function. If, after suspending a machine, you
   don't want to resume it but would like to return to the
   previous state, you may call the PrlVm_DropSuspendedState
   function.

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
   enough memory to instantiate the job object.
   See Also
   PrlVm_Resume

   PrlVm_DropSuspendedState                                       */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Suspend, (
		PRL_HANDLE hVm
		) );

/* Retrieves the virtual machine screen state before it was
   suspending. To get the return code from the PHT_JOB object,
   use the PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_VM_IS_NOT_SUSPENDED - the virtual machine is not in
   the suspended state.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_GetSuspendedScreen, (
		PRL_HANDLE hVm
		) );

/* Resumes a virtual machine that was previously suspended with
   the PrlVm_Suspend call. To get the return code from the
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
   enough memory to instantiate the job object.
   See Also
   PrlVm_Suspend                                                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Resume, (
		PRL_HANDLE hVm
		) );

/* Resets a suspended virtual machine. When a virtual machine is
   suspended with the PrlVm_Suspend call, the current state of
   the virtual machine processes is saved into a temporary file
   on the hard disk, and the virtual machine is stopped. When a
   suspended virtual machine is resumed with the PrlVm_Resume
   call, the data in the temp file is used to restore the state
   of the virtual machine processes. The PrlVm_DropSuspendedState
   function resets a suspended virtual machine by deleting the
   temp file from the drive Once the function successfully
   completes, the virtual machine can no longer be resumed with
   the PrlVm_Resume call. It still can be started normally,
   however.

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
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_DropSuspendedState, (
		PRL_HANDLE hVm
		) );

/* Creates a virtual machine snapshot. To get the return code
   from the PHT_JOB object, use the PrlJob_GetRetCode function.
   Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :        A handle of type PHT_VIRTUAL_MACHINE
                   identifying the virtual machine.
   sName :         Snapshot name.
   sDescription :  Snapshot description.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_DeleteSnapshot

   PrlVm_GetSnapshotsTreeEx

   PrlVm_SwitchToSnapshot

   PrlVm_UpdateSnapshotData                                     */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
					   PrlVm_CreateSnapshot, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sName,
		PRL_CONST_STR sDescription
		) );

/* Retrieves snapshot information for the specified virtual
   machine. Snapshot information is returned as an XML file
   containing the snapshot tree. Some of the important XML
   elements are:

   <b>SavedStateItem</b> -- the root element of the branch
   containing information about an individual snapshot. The
   element has an attribute "guid" containing the snapshot ID.
   The ID is required when performing other operations on a
   snapshot.

   <b>Name</b> -- contains the snapshot name.

   <b>DateTime</b> -- the snapshot creation date and time.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get a snapshot tree from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamAsString function to obtain a
        string value containing the snapshots tree XML data.
   Please note that no parser is provided to traverse the
   returned XML. To use this functionality, you will have to
   parse the returned XML yourself. This function will be
   replaced in the future releases of the Parallels SDK.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   flags : A flags from enum PRL_GET_SNAPSHOT_TREE_FLAGS and PRL_API_COMMAND_FLAGS
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_CreateSnapshot

   PrlVm_DeleteSnapshot

   PrlVm_SwitchToSnapshot

   PrlVm_UpdateSnapshotData                                       */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
					   PrlVm_GetSnapshotsTree, (
		PRL_HANDLE hVm
		) );
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVm_GetSnapshotsTreeEx, (
					  PRL_HANDLE hVm,
					  PRL_UINT32 nFlags
					  ) );

/* Lets to exclusively lock VM for current session. After this
   call just current sesiion be able to operate with locked VM
   until PrlVm_Unlock will be called or current session will be
   closed. If VM was already locked by some another session
   (or the same one) then lock operation will fail.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:
   PRL_ERR_INVALID_ARG - invalid handle was passed.
   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   nReserved : reserved param for further purposes
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Lock, (
		PRL_HANDLE hVm,
		PRL_UINT32 nReserved
		) );

/* Lets to unlock previously locked with PrlVm_Lock call VM.
   Note that just VM lock owner session can unlock VM.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   nReserved : reserved param for further purposes
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Unlock, (
		PRL_HANDLE hVm,
		PRL_UINT32 nReserved
		) );


/* Reverts the specified virtual machine to the specified
   snapshot. To get the return code from the PHT_JOB object, use
   the PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :         A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   sSnapshotUuid :  The ID of a snapshot to revert to. To obtain
                    a list of the available snapshots and their
                    IDs, use the PrlVm_GetSnapshotsTreeEx function.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_CreateSnapshot

   PrlVm_DeleteSnapshot

   PrlVm_GetSnapshotsTreeEx

   PrlVm_UpdateSnapshotData                                       */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
					   PrlVm_SwitchToSnapshot, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sSnapshotUuid
		) );

/* Reverts the specified virtual machine to the specified
   snapshot. To get the return code from the PHT_JOB object, use
   the PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :         A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   sSnapshotUuid :  The ID of a snapshot to revert to. To obtain
                    a list of the available snapshots and their
                    IDs, use the PrlVm_GetSnapshotsTreeEx function.
   nFlags        :  Bitset of flags - from enum PRL_SWITCH_SNAPSHOT_FLAGS
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_CreateSnapshot

   PrlVm_DeleteSnapshot

   PrlVm_GetSnapshotsTreeEx

   PrlVm_UpdateSnapshotData                                       */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                                           PrlVm_SwitchToSnapshotEx, (
                PRL_HANDLE hVm,
                PRL_CONST_STR sSnapshotUuid,
                PRL_UINT32 nFlags
                ) );


/* Deleted the specified virtual machine snapshot. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   sSnapshotUuid :  Snapshot ID. To obtain a snapshot ID use the
                    PrlVm_GetSnapshotsTreeEx function.
   bChild :         Specifies whether snapshots derived from the
                    specified snapshot should be deleted or not.
                    True \- delete child snapshots. False \-
                    don't delete child snapshots.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_CreateSnapshot

   PrlVm_GetSnapshotsTreeEx

   PrlVm_SwitchToSnapshot

   PrlVm_UpdateSnapshotData                                      */

PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
					   PrlVm_DeleteSnapshot, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sSnapshotUuid,
		PRL_BOOL bChild
		) );

/* Modifies the specified virtual machine snapshot name and
   \description. To get the return code from the PHT_JOB object,
   use the PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   handle :           A handle of type PHT_VIRTUAL_MACHINE
                      identifying the virtual machine.
   sSnapshotUuid :    The ID of the snapshot to modify. To obtain
                      a list of the available snapshots and their
                      ID's, use the PrlVm_GetSnapshotsTreeEx
                      function.
   sNewName :         New snapshot name.
   sNewDescription :  New snapshot description.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_CreateSnapshot

   PrlVm_DeleteSnapshot

   PrlVm_GetSnapshotsTreeEx

   PrlVm_SwitchToSnapshot                                         */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_2,
					  PrlVm_UpdateSnapshotData, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sSnapshotUuid,
					  PRL_CONST_STR sNewName,
					  PRL_CONST_STR sNewDescription
					  ) );



/* Clones an existing virtual machine. The function creates an
   exact copy of the specified virtual machine on the same
   host using the specified new name and location. In order to
   perform a clone operation, the original machine must be
   registered with the Parallels Service. A clone can be created as a
   virtual machine or as a template. To create a template, set
   the bCreateTemplate parameter value to PRL_TRUE. The function
   can also be used to create new virtual machines from
   templates. In order to that, the hVm parameter must contain a
   handle to a template, the name and the path parameters must
   be set to desired values, and the bCreateTemplate parameter
   must be set to PRL_FALSE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   new_vm_name :       The name to use for the new virtual
                       machine.
   new_vm_root_path :  Name and path of the directory where the
                       new virtual machine should be created. To
                       create the machine in a default directory,
                       pass an empty string.
   bCreateTemplate :   Specifies whether the clone should be
                       created as a virtual machine or as a
                       template. To create a template, set this
                       parameter value to PRL_TRUE. To create a
                       virtual machine, set it to PRL_FALSE. When
                       creating a virtual machine from a
                       template, set the parameter value to
                       PRL_FALSE.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Clone, (
		PRL_HANDLE hVm,
		PRL_CONST_STR new_vm_name,
		PRL_CONST_STR new_vm_root_path,
		PRL_BOOL bCreateTemplate
		) );

/* Clones an existing virtual machine. The function creates an
   exact copy of the specified virtual machine on the same
   host using the specified new name and location. In order to
   perform a clone operation, the original machine must be
   registered with the Parallels Service. A clone can be created as a
   virtual machine or as a template. To create a template, set
   the nFlags parameter to PACF_CLONEVM_TO_TEMPLATE value. The function
   can also be used to create new virtual machines from
   templates. In order to that, the hVm parameter must contain a
   handle to a template, the name and the path parameters must
   be set to desired values, and the bCreateTemplate parameter
   must be set to PRL_FALSE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   new_vm_name :       The name to use for the new virtual
                       machine.
   new_vm_root_path :  Name and path of the directory where the
                       new virtual machine should be created. To
                       create the machine in a default directory,
                       pass an empty string.
   nFlags :	       Clone flags (PCVF_CLONE_TO_TEMPLATE, PCVF_CHANGE_SID,
                   PCVF_LINKED_CLONE, PCVF_IMPORT_BOOT_CAMP).
				   Also PACF_NON_INTERACTIVE_MODE can be used to specify non
				   interactive session working mode (remote side won't ask
				   questions during operation progress in this case).
				   Please note that clone operation can take
				   it's own exclusive lock of virtual machine (in change SID or
				   linked clone modes) - so VM shouldn't be exclusively locked
				   with PrlVm_Lock call before clone operation performed.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_CloneEx, (
		PRL_HANDLE hVm,
		PRL_CONST_STR new_vm_name,
		PRL_CONST_STR new_vm_root_path,
		PRL_UINT32 nFlags
		) );

/* Clones an existing virtual machine based on given snapshot.
   The function creates an exact copy of the specified virtual machine
   on the same host using the specified new name and location.
   In order to perform a clone operation, the original machine must be
   registered with the Parallels Service. A clone can be created as a
   virtual machine or as a template. To create a template, set
   the nFlags parameter to PACF_CLONEVM_TO_TEMPLATE value. The function
   can also be used to create new virtual machines from
   templates. In order to that, the hVm parameter must contain a
   handle to a template, the name and the path parameters must
   be set to desired values, and the bCreateTemplate parameter
   must be set to PRL_FALSE.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   new_vm_name :       The name to use for the new virtual
                       machine.
   new_vm_root_path :  Name and path of the directory where the
                       new virtual machine should be created. To
                       create the machine in a default directory,
                       pass an empty string.
   snapshot_id :   [optional] Snapshot UUID. If string is empty,
                   then function behaves the same as PrlVm_CloneEx
                   with flag PCVF_LINKED_CLONE.
   nFlags :	       Clone flags (PCVF_CLONE_TO_TEMPLATE, PCVF_CHANGE_SID,
                   PCVF_LINKED_CLONE, PCVF_IMPORT_BOOT_CAMP).
				   Also PACF_NON_INTERACTIVE_MODE can be used to specify non
				   interactive session working mode (remote side won't ask
				   questions during operation progress in this case).
				   Please note that clone operation can take
				   it's own exclusive lock of virtual machine (in change SID or
				   linked clone modes) - so VM shouldn't be exclusively locked
				   with PrlVm_Lock call before clone operation performed.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
						   PrlVm_LinkedClone, (
		PRL_HANDLE hVm,
		PRL_CONST_STR new_vm_name,
		PRL_CONST_STR new_vm_root_path,
		PRL_CONST_STR snapshot_id,
		PRL_UINT32 nFlags
		) );

/* Deletes the specified virtual machine from the host. This
   function un-registers the machine from the Parallels Service
   and deletes all its files. This operation cannot be undone.
   The specified machine must be registered with the Parallels Service. To
   un-register a machine from the Parallels Service without deleting any of
   its file, use the PrlVm_Unreg function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :           A handle of type PHT_VIRTUAL_MACHINE
                   identifying the virtual machine.
   hDevicesList :  A handle of type PHT_STRINGS_LIST containing a
                   list of files (devices) to be deleted from the
                   virtual machine directory. If the list is
                   empty or the parameter contains a null
                   pointer, the entire virtual machine directory
                   will be deleted from the host. If the list
                   contains one or more items, only the specified
                   files will be delete (the rest of the virtual
                   machines files will remain on the host in
                   the original directory).
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Delete, (
		PRL_HANDLE hVm,
		PRL_HANDLE hDevicesList
		) );

/* The PrlVm_GetPackedProblemReport function obtains a Packed problem report
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
string containing path to the report directory.
Parameters
hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
virtual machine.
PRL_UINT32 nFlags - reserved flags parameter
Returns
A handle of type PHT_JOB containing the results of this
asynchronous operation or PRL_INVALID_HANDLE if there's not
enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						  PrlVm_GetPackedProblemReport, (
						  PRL_HANDLE hVm,
						  PRL_UINT32 nFlags
						  ) );


/* Obtains a handle of type PHT_VM_INFO containing the specified
   virtual machine state and access rights information. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParam function to obtain the PHT_VM_INFO
   handle.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_GetState, (
		PRL_HANDLE hVm
		) );


/* Automatically generates a name for a virtual device which
   will be unique within a home directory of the specified
   virtual machine. To get the return code from the PHT_JOB
   object, use the PrlJob_GetRetCode function. Possible value
   are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the home directory information is missing
   in the specified virtual machine object. If this is a new
   virtual machine, try updating the local object by calling the
   PrlVm_RefreshConfig or PrlSrv_GetVmList function.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVM :              A handle of type PHT_VIRTUAL_MACHINE
                      identifying the virtual machine.
   sFilenamePrefix :  A prefix to add to the name. Pass a null
                      pointer to use a default value\: "tmpfile".
                      The name will be generated by adding a
                      number to the prefix (e.g. tmpfile1, tmpfile2,
                      tmpfile3, etc.)
   sFilenameSuffix :  A suffix to add to the name. Pass a null
                      pointer for no suffix.
   sIndexDelimiter :  A character(s) that will be inserted
                      between the prefix and the index (e.g. tmpfile_1,
                      tmpfile_2, tmpfile_3, etc). You can specify
                      a null pointer or an empty string if you
                      don't want to insert any extra characters
                      there.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                         */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_GenerateVmDevFilename, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sFilenamePrefix,
		PRL_CONST_STR sFilenameSuffix,
		PRL_CONST_STR sIndexDelimiter
		) );


/* Obtains a handle of type PHT_VM_TOOLS_INFO containing
   information about the state of the Parallels Tools package in
   a virtual machine.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_GetToolsState, (
		PRL_HANDLE hVm
		) );

/* The PrlVm_RefreshConfig function updates the configuration
   information contained in the specified virtual machine object
   (handle). When you obtain a virtual machine handle that
   refers to an existing virtual machine, it is populated with
   the virtual machine configuration data. When working with
   configuration data, you always work with this local copy.
   Naturally, the configuration can change on the Parallels Service side at
   any time. The PrlVm_RefreshConfig function allows to re-retrieve
   the configuration data from the Parallels Service. The function can be
   used when an event of type PET_DSP_EVT_VM_CONFIG_CHANGED is
   triggered (the event notifies the client that the virtual
   machine configuration has been modified), or on unsuccessful
   PrlVm_Commit operation, or at any time you want to
   synchronize your local virtual machine object with the
   Parallels Service. Please note that the function replaces the local
   data, so if you made any modification to it, the changes will
   be lost.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine. This is the object that will be
          updated.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_RefreshConfig, (
		PRL_HANDLE hVm
		) );

/* Creates a new console session or binds to an existing GUI
   session in a virtual machine. <b>Note</b>: To use this
   function, Parallels Tools must be installed in the target
   virtual machine.

   This function is used when you want to run a program in a
   virtual machine or perform an administrative task that
   require native guest operating system login. Depending on the
   type of the program that you would like to run, the login
   must be performed using one of the following methods:
     * To run a GUI application, call this function passing the
       PRL_CURRENT_GUEST_OS_SESSION constant in the sUserName
       parameter. The reason is the function can only bind to an
       existing GUI session and cannot create a new one. Prior to
       calling this function, a GUI session must already be open in
       a virtual machine (the machine must be running and a user
       must be logged in to it). The user password parameter can be
       blank.
     * To run a console program, the sUserName parameter can
       contain the PRL_PRIVILEGED_GUEST_OS_SESSION constant or a
       valid user name and password. When using
       PRL_PRIVILEGED_GUEST_OS_SESSION, the function will bind to an
       existing session under which Parallels Service is running.
       This session belongs to a privileged user (e.g. root on Linux
       or LocalSystem on Windows), so it can be used to perform
       administrative tasks. When specifying a user name and
       password, a new session will be created in the virtual
       machine.
   On successful login, the function obtains a handle of type
   PHT_VM_GUEST_SESSION (see below for the instructions on how
   to get the handle from the PHT_JOB object). You can use the
   handle functions to run programs in a virtual machine and to
   perform other supported operations. See the
   PHT_VM_GUEST_SESSION handle description for a complete list
   of functions.

   When the session is no longer needed, it should be closed
   using the PrlVmGuest_Logout function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG &#45; invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS &#45; function completed successfully.

   To get the PHT_VM_GUEST_SESSION handle from the returned
   PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain the
        PHT_RESULT handle.
     2. Use the PrlResult_GetParam to obtain the
        PHT_VM_GUEST_SESSION handle.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   sUserName :      User name. This parameter must contain a
                    valid guest OS user name or one of the
                    following constants\:<p />PRL_CURRENT_GUEST_OS_SESSION
                    \-\- binds to an existing GUI session in a
                    virtual machine.<p />PRL_PRIVILEGED_GUEST_OS_SESSION
                    \-\- binds to an existing session under which
                    Parallels Service is running. This session
                    belongs to a privileged user (e.g. root on
                    Linux or LocalSystem on Windows), so it can
                    be used to perform administrative tasks.<p />Note
                    that in order to use the constants above, the
                    current user must be an administrator of the
                    host OS or be the owner of the target virtual
                    machine.
   sUserPassword :  User password. If the sUserName parameter
                    contains one of the constants (see above)
                    then this parameter can contain an empty
                    string.
   nFlags :         A bitset of flags. Must be 0 in the current
                    API implementation.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVmGuest_RunProgram

   PrlVmGuest_Logout                                                       */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_LoginInGuest, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sUserName,
		PRL_CONST_STR sUserPassword,
		PRL_UINT32 nFlags
		) );

/* Starts a VNC server for the specified virtual machine. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer for user
   name was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :        A handle of type PHT_VIRTUAL_MACHINE identifying
                the virtual machine.
   nReserved :  Reserved parameter for future purposes. Must
                contain 0 in the current implementation.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_StopVncServer                                           */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_StartVncServer, (
		PRL_HANDLE hVm,
		PRL_UINT32 nReserved
		) );

/* Stops the VNC server that was previously started for a
   virtual machine. To get the return code from the PHT_JOB
   object, use the PrlJob_GetRetCode function. Possible values
   are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer for user
   name was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :        A handle of type PHT_VIRTUAL_MACHINE identifying
                the virtual machine.
   nReserved :  Reserved parameter for future purposes. Must be 0
                in the current implementation.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_StartVncServer                                           */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_StopVncServer, (
		PRL_HANDLE hVm,
		PRL_UINT32 nReserved
		) );


/* The PrlVm_SetConfig is reserved and does nothing.
   Parameters
   hVm :    A handle of type PHT_VIRTUAL_MACHINE identifying the
            virtual machine.
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_SetConfig, (
		PRL_HANDLE hVm,
		PRL_HANDLE hVmCfg
		) );


/* Obtains a handle of type PHT_VM_CONFIGURATION.
   Parameters
   hVm :      A handle of type PHT_VIRTUAL_MACHINE identifying
              the virtual machine.
   phVmCfg :  [out] A pointer to a variable that receives the
              handle of type PHT_VM_CONFIGURATION.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_GetConfig, (
		PRL_HANDLE hVm,
		PRL_HANDLE_PTR phVmCfg
		) );


/* Obtains a handle of type PHT_SYSTEM_STATISTICS containing the
   virtual machine resource usage information, including CPU(s),
   memory, disk drives, processes, user session, system uptime,
   network packets, etc. To get the return code from the PHT_JOB
   object, use the PrlJob_GetRetCode function. Possible value
   are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParam function to obtain a handle of
   type PHT_SYSTEM_STATISTICS containing the resource usage
   data.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_GetStatistics, (
		PRL_HANDLE hVm
		) );
/* The PrlVm_GetStatisticsEx function is the same as PrlVm_GetStatistics
   function but with the flags
   Parameters
   hVm :    A handle of type PHT_VIRTUAL_MACHINE identifying the
            virtual machine.
   nFlags : Bitset of flags - from enum PRL_API_COMMAND_FLAGS
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						  PrlVm_GetStatisticsEx, (
						  PRL_HANDLE hVm,
						  PRL_UINT32 nFlags
						  ) );

/* Subscribes to receive the specified virtual machine
   performance statistics on a periodic basis. To obtain
   statistics, an event handler (callback function) is required.
   Within the event handler, first check the type of event.
   Events of type PET_DSP_EVT_VM_STATISTICS_UPDATED indicate an
   event containing performance data. To access the statistics
   handle (a handle of type PHT_SYSTEM_STATISTICS), first
   extract the event parameter using PrlEvent_GetParam, then
   convert the result (which will be a handle to an object of
   type PHT_EVENT_PARAMETER) to a handle using
   PrlEvtPrm_ToHandle. The functions that operate on
   PHT_SYSTEM_STATISTICS references can then be used to obtain
   statistics data.

   For the event handler to be called, it is necessary to
   register it with PrlVm_RegEventHandler. When statistics data
   is no longer required, unsubscribe from statistics events
   using PrlVm_UnsubscribeFromGuestStatistics. When events are
   no longer required, unregister the event handler using PrlVm_UnregEventHandler.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_SubscribeToHostStatistics
                                                                                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_SubscribeToGuestStatistics, (
		PRL_HANDLE hVm
		) );

/* Cancels the performance statistics subscription that was
   previously initiated using the
   PrlVm_SubscribeToGuestStatistics function. To get the return
   code from the PHT_JOB object, use the PrlJob_GetRetCode
   function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_UnsubscribeFromGuestStatistics, (
		PRL_HANDLE hVm
		) );

/* Allows to subscribe to periodicaly receive virtual machine
   perfomance statistics. To obtain statistics, an event handler
   (callback function) is required. Within the event handler,
   first check the type of event. Events of type
   PET_DSP_EVT_VM_PERFSTATS indicate an event
   containing statistics data. The perfomace statistics repesented by
   parameters of Event object (a handle of type PHT_EVENT).

   For the event handler to be called, it is necessary to
   register it with PrlSrv_RegEventHandler. When statistics data
   is no longer required, unsubscribe from statistics events
   using PrlVm_UnsubscribeFromHostPerfStats. When events are
   no longer required, unregister the event handler using
   PrlVm_UnregEventHandler.

   If method is called mutliple times, the 'filter'
   value is updated each time on the Parallels Service side.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :      A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   sFilter :  String representing statistics filter,
              use char '*' at the end to get subset of statistic.
              Could be NULL, to get all statistic.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_SubscribeToPerfStats, (
                           PRL_HANDLE hVm, PRL_CONST_STR sFilter
                           ) );

/* Cancels the Parallels Service performance statistics subscription
   that was started using the PrlVm_SubscribeToPerfStats function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :      A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_UnsubscribeFromPerfStats, (
                           PRL_HANDLE hVm
                           ) );

/* Obtains a handle of type PHT_EVENT containing the virtual
   machine performance statistics. To get the return code from
   the PHT_JOB object, use the PrlJob_GetRetCode function.
   Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_EVENT.
   Parameters
   hVm :      A handle of type PHT_VIRTUAL_MACHINE identifying the
              virtual machine.
   sFilter :  String representing statistics filter, use char '*'
              at the end to get subset of statistic. Could be
              NULL, to get all statistic.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_GetPerfStats, (
                           PRL_HANDLE hVm, PRL_CONST_STR sFilter
                           ) );


/* Creates a new virtual machine and registers it with the
   Parallels Service. The steps involved in creating a typical
   virtual machine are:
     1. Obtain a handle to a new virtual machine object using
        the PrlSrv_CreateVm function.
     2. Populate the object with the desired configuration data.
     3. Choose a name for the virtual machine and set it using
        the PrlVmCfg_SetName function.
     4. Create and register the new machine with a Parallels
        Service using the PrlVm_Reg function. This step will create
        the necessary virtual machine files on the host and
        will add the machine to the Parallels Service VM registry. The
        directory containing the virtual machine files will have the
        same name as the name you've chosen for your virtual machine.
        The directory will be created in the default VM root
        directory for this Parallels Service. If you would like to create the
        virtual machine directory in a different location, you may
        specify the desired parent directory name and path.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :                  A handle of type PHT_VIRTUAL_MACHINE
                          identifying the virtual machine.
   sVmParentPath :        Optional. Name and path of the parent
                          directory where the virtual machine
                          directory should be created. If this
                          parameter is omitted (null pointer or
                          empty string is passed), the new
                          virtual machine directory will be
                          created in the default directory for
                          this Parallels Service.
   nFlags :               Flags set which specifies way of
                          virtual machine creation. Use
						  PACF_NON_INTERACTIVE_MODE flag here
						  instead of deprecated bNonInteractiveMode
						  parameter.
						  Other bitset of flags - from enum PRL_CREATE_DISK_IMAGE_FLAGS
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                       */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlVm_RegEx, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sVmParentPath,
		PRL_UINT32 nFlags
		) );
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Reg, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sVmParentPath,
		PRL_BOOL bNonInteractiveMode
		) );

/* Unregisters the specified virtual machine from the Parallels
   Service. This call removes the virtual machine from the
   Parallels Service registry, but does not delete the virtual
   machine files from the hard drive. You can re-register a
   machine with the Parallels Service at any time using the
   PrlSrv_RegisterVm or PrlSrv_RegisterVmEx functions call.

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
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Unreg, (
		PRL_HANDLE hVm
		) );

/* Restores the registered virtual machine. To get the return
   code from the PHT_JOB object, use the PrlJob_GetRetCode
   function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_VIRTUAL_MACHINE.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation, including the return code and a
   handle of type PHT_VIRTUAL_MACHINE containing information
   about the virtual machine that was registered.

   PRL_INVALID_HANDLE if there's not enough memory to
   instantiate the job object.                                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Restore, (
		PRL_HANDLE hVm
		) );

/* The PrlVm_BeginEdit function is used in modifying a virtual
   machine configuration. The PrlVm_BeginEdit and the
   PrlVm_Commit functions are used to detect collisions with
   other clients trying to modify the same virtual machine at
   the same time. The PrlVm_BeginEdit call timestamps the
   beginning of the editing operation. It does not lock the
   machine, so other clients can modify the same machine at the
   same time. When you are done making the changes, you must
   call the PrlVm_Commit function to save them in the virtual
   machine configuration. The function will verify that the
   configuration has not been modified by another client. If a
   collision is detected, your changes will be rejected. To
   ensure that you always work with the most recent
   configuration data, the PrlVm_BeginEdit function reloads it
   when called. If you first modified the data in your program
   and then called the PrlVm_BeginEdit function, your changes
   will be lost.

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
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_BeginEdit, (
		PRL_HANDLE hVm
		) );

/* The PrlVm_Commit function is used in modifying a virtual
   machine configuration. The PrlVm_BeginEdit and the
   PrlVm_Commit functions are used to detect collisions with
   other clients trying to modify the same virtual machine at
   the same time. The PrlVm_BeginEdit call timestamps the
   beginning of the editing operation. It does not lock the
   machine, so other clients can modify the same machine at the
   same time. When you are done making the changes, you must
   call the PrlVm_Commit function to save them in the virtual
   machine configuration. The function will verify that the
   configuration has not been modified by another client. If a
   collision is detected, your changes will be rejected.

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
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_Commit, (
		PRL_HANDLE hVm
		) );

/*  The PrlVm_CommitEx function is the same as PrlVm_Commit function but with the flags
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
		  nFlags : Bitset of flags - from enum PRL_API_COMMAND_FLAGS
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						  PrlVm_CommitEx, (
						  PRL_HANDLE hVm,
						  PRL_UINT32 nFlags
						  ) );


/* Registers an event handler (callback function) with the
   virtual machine. To use the callback functionality, you first
   have to implement a callback function. The callback function
   must have a specific signature (see PRL_METHOD_PTR for the
   prototype). After you register an event handler with a
   virtual machine, the callback function will be called every
   time an event is generated in the machine.

   You can also register an event handler with a Parallels
   Service (instead of a particular virtual machine) using the
   PrlSrv_RegEventHandler function. If you register the event
   handler with the Parallels Service, you will be able to receive events
   from all of the virtual machines registered with that Parallels Service.
   For more information on events and asynchronous functions,
   see the Parallels Virtualization SDK Programmer's Guide.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   handler :   A pointer to the callback function that will
               handle events.
   userData :  A pointer to a user data that will be passed to
               the callback function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_RegEventHandler, (
		PRL_HANDLE hObj,
		PRL_EVENT_HANDLER_PTR handler,
		PRL_VOID_PTR userData
		) );

/* Unregisters an event handler (callback function) that was
   previously registered using the PrlVm_RegEventHandler
   function. Use this function when you no longer want to
   receive event notifications from the virtual machine. The
   values of the handler and userData parameter constitute a
   unique pair which will be used to identify the event handler
   that will be unregistered. Make sure that you supply the same
   values as the ones you used when you registered the handler.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   handler :   A pointer to the callback function. This must be
               the same pointer that was passed to the PrlVm_RegEventHandler
               when the event handler was registered with the
               virtual machine.
   userData :  A pointer to the user data. This must also be the
               same pointer that was passed to the
               PrlVm_RegEventHandler when the event handler was
               registered with the virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_UnregEventHandler, (
		PRL_HANDLE hObj,
		PRL_EVENT_HANDLER_PTR handler,
		PRL_VOID_PTR userData
		) );

/**
The PrlVm_GetQuestions function allows to synchronously receive questions from
a Parallels Service. It can be used as an alternative to asynchronous question
processing through events. You can use this function at any time to check
if a question is awaiting the client response on the Parallels Service side.

Parameters
handle : A handle of type PHT_VIRTUAL_MACHINE.
pQuestionsList :	[out] A handle of type PHT_HANDLES_LIST containing a list of
					available questions.

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG -	non valid PHT_VIRTUAL_MACHINE handle or non valid (NULL) pointer
						to the buffer for storing result was passed.
PRL_ERR_SUCCESS - operation completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_GetQuestions, (
		PRL_HANDLE hVm,
		PRL_HANDLE_PTR pQuestionsList
		) );


/* Creates VM event that bint to current VM.
   Parameters
   handle :         A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   unnamed_param :  buffer for storing result
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   PHT_VIRTUAL_MACHINE handle or non valid (null) pointer to
   buffer was specified PRL_ERR_OUT_OF_MEMORY - not enough
   memory to instantiate VM event object PRL_ERR_SUCCESS -
   operation completed successfully                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_CreateEvent, (
		PRL_HANDLE hVm,
		PRL_HANDLE_PTR phEvent
		) );


/* Creates a disk image in the virtual machine home
   directory for unattended Windows installation. The following
   steps describe how to prepare a virtual machine for
   unattended Windows installation:
     1. Create a virtual machine. The machine should have all
        the necessary devices, like hard drive and CD drive.
     2. Execute the PrlVm_CreateUnattendedDisk function to
        create a disk image.
     3. Insert Windows installation CD-ROM into the drive (or
        mount a disk image).
     4. Start the virtual machine. The machine will boot from
        the CD.
     5. Perform unattended Windows installation as usual.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   nGuestDistroType :  Windows version.
   sUsername :         User name.
   sCompanyName :      Company name.
   sSerialKey :        Serial number.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
						   PrlVm_CreateUnattendedDisk, (
		PRL_HANDLE hVm,
		PRL_GUEST_DISTRO_VERSION_ENUM nGuestDistroType,
		PRL_CONST_STR sUsername,
		PRL_CONST_STR sCompanyName,
		PRL_CONST_STR sSerialKey
		) );

/* Creates a floppy disk image in the virtual machine home
   directory for unattended Windows installation. The following
   steps describe how to prepare a virtual machine for
   unattended Windows installation:
     1. Create a virtual machine. The machine should have all
        the necessary devices, like hard drive and CD drive.
     2. Execute the PrlVm_CreateUnattendedFloppy function to
        create a floppy disk image.
     3. Insert Windows installation CD-ROM into the drive (or
        mount a disk image).
     4. Start the virtual machine. The machine will boot from
        the CD.
     5. Perform unattended Windows installation as usual.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   nGuestDistroType :  Windows version.
   sUsername :         User name.
   sCompanyName :      Company name.
   sSerialKey :        Serial number.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_CreateUnattendedFloppy, (
		PRL_HANDLE hVm,
		PRL_GUEST_DISTRO_VERSION_ENUM nGuestDistroType,
		PRL_CONST_STR sUsername,
		PRL_CONST_STR sCompanyName,
		PRL_CONST_STR sSerialKey
		) );


/* This method lets to initiate sending notifications about
   devices states by VM. Those notifications have to be same as
   notifications after changing a device state
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   Returns
   PRL_HANDLE to job that describing async operation result
   (PRL_INVALID_HANDLE means not enough memory to instantiate
   async job represents object handle). Operation return code
   can be extracted with @ref PrlJob_GetRetCode() call. Possible
   values: PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE
   handle was passed PRL_ERR_UNINITIALIZED - unexpected error:
   uninitialized with the Parallels Service connection or non identified VM
   object                                                         */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_InitiateDevStateNotifications, (
					  PRL_HANDLE hVm
					  ) );

/* Updates access level for the specified virtual machine. By
   default, only the owner of a virtual machine has full access
   to it. All other users are completely unaware of the machine
   (it will not even appear in the list of the available virtual
   machines for them). The owner of the virtual machine can
   change that by setting one of the predefined access levels
   for the machine. Depending on the level of access set by the
   owner, other users will be able to see the machine and to
   perform tasks on it.

   To update the access level, obtain a handle of type
   PHT_ACCESS_RIGHTS, set the desired level using the
   PrlAcl_SetAccessForOthers function, and then call this
   function to apply the changes to the virtual machine. The
   caller must be the owner of the machine to perform this
   operation. The PrlAcl_IsCurrentSessionOwner function can be
   used to determine if the current user is the owner of the
   virtual machine.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_ACCESS_DENIED - current user is not the owner of the
   target virtual machine.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   hAccessRights :  A handle of type PHT_ACCESS_RIGHTS containing
                    the virtual machine access level information.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_UpdateSecurity, (
					  PRL_HANDLE hVm,
					  PRL_HANDLE hAccessRights
					  ) );

/* Validates the specified section of a virtual machine
   configuration. When creating or modifying a virtual machine
   configuration, this function can be used to verify that a
   particular section of the configuration is valid. Use this
   function before sending the virtual machine object containing
   the configuration information to the Parallels Service. If the
   configuration is valid, you can commit the changes. If the
   configuration is not valid, make the necessary modifications
   and retry.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or the specified
   configuration section doesn't exist.

   PRL_ERR_PARSE_VM_CONFIG - error parsing configuration data.

   PRL_ERR_VMCONF_VALIDATION_FAILED - invalid configuration; the
   \description of the problem can be retrieved from from the
   PHT_JOB object (see below).

   PRL_ERR_SUCCESS - specified configuration is valid.

   In the event of validation failure, the PHT_JOB object will
   contain the description of the problem. To get the
   \description:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParamsCount function to obtain the
        \result count.
     3. Use the PrlResult_GetParamByIndex to obtain a handle of
        type PHT_EVENT (if there are multiple results, call the
        function for each one).
     4. Use the PrlEvent_GetErrString function to get the
        validation error description.
   Parameters
   hVm :       A handle of type PHT_VIRTUAL_MACHINE identifying
               the virtual machine.
   nSection :  The section in the virtual machine configuration
               to verify.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_ValidateConfig, (
						PRL_HANDLE hVm,
						PRL_VM_CONFIG_SECTIONS nSection
						) );


/* Authorises current session against encrypted virtual machine.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sPassword :      Password which was used earlier to encrypt
                    virtual machine. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   nFlags :  		Bitset of flags - reserved parameter for
                    further purposes.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
				PrlVm_Authorise, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sPassword,
					  PRL_UINT32 nFlags
					  ) );

/* Changes current password of encrypted virtual machine on new one.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sOldPassword :   Password which was used earlier to encrypt
                    virtual machine. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   sNewPassword :   New setting password. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   nFlags :  		Bitset of flags - reserved parameter for
                    further purposes.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
				PrlVm_ChangePassword, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sOldPassword,
					  PRL_CONST_STR sNewPassword,
					  PRL_UINT32 nFlags
					  ) );

/* Encrypts virtual machine data using specified secret password phrase.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sPassword :      Password to encrypt virtual machine. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   sCipherPluginUuid : Parameter reserved for further purposes - currently 0
                       should be specified.
   nFlags :  		Bitset of flags - flags from enums PRL_ENCRYPTION_FLAGS and PRL_API_COMMAND_FLAGS
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
				PrlVm_Encrypt, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sPassword,
					  PRL_CONST_STR sCipherPluginUuid,
					  PRL_UINT32 nFlags
					  ) );

/* Decrypts earlier encrypted with some secret password phrase
   virtual machine.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sPassword :      Password which was used earlier to encrypt
                    virtual machine. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   nFlags :  		Bitset of flags - flags from enums PRL_ENCRYPTION_FLAGS and PRL_API_COMMAND_FLAGS
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
				PrlVm_Decrypt, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sPassword,
					  PRL_UINT32 nFlags
					  ) );

/* Archive virtual machine data.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   nFlags :  	    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVm_Archive, (
					  PRL_HANDLE hVm,
					  PRL_UINT32 nFlags
					  ) );

/* Unarchive virtual machine data.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   nFlags :  	    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVm_Unarchive, (
					  PRL_HANDLE hVm,
					  PRL_UINT32 nFlags
					  ) );

/* Protects virtual machine using specified secret password phrase.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sProtectionPassword : Password to protect virtual machine. UTF-8 encoded
                    string ending with null (\0) symbol. Can be null (0)
					in case of empty password.
   nFlags :		    Reserved
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
				PrlVm_SetProtection, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sProtectionPassword,
					  PRL_UINT32 nFlags
					  ) );

/* Removes protection from virtual machine.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_MACHINE type)
                         was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine object.
   sProtectionPassword : Password which was used earlier to protect
                    virtual machine. UTF-8 encoded string ending
					with null (\0) symbol. Can be null (0) in case
					of empty password.
   nFlags :		    Reserved
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
				PrlVm_RemoveProtection, (
					  PRL_HANDLE hVm,
					  PRL_CONST_STR sProtectionPassword,
					  PRL_UINT32 nFlags
					  ) );


/* Installs a specified utility in a virtual machine. This
   functions is a part of the Parallels Tools functionality.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_VIRTUAL_MACHINE identifying the
              Parallels Service.
   strId :    A string identifying the utility to install.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_InstallUtility, (
                           PRL_HANDLE hVm,
						   PRL_CONST_STR strId
                           ) );

/* Begin the Parallels Tools installation process. The machine must be
   registered with the Parallels Service to perform this operation.
   Parameters
   handle :  A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   Returns
   PRL_HANDLE to job that describing async operation result
   (PRL_INVALID_HANDLE means not enough memory to instantiate
   async job represents object handle). Operation return code
   can be extracted with @ref PrlJob_GetRetCode() call. Possible
   values: PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE
   handle was passed PRL_ERR_UNINITIALIZED - unexpected error:
   uninitialized with Parallels Service connection or non identified VM
   object                                                         */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_InstallTools, (
					  PRL_HANDLE hVm
					  ) );


/* Obtains the available capabilities of a graceful virtual
   machine shutdown using Parallels Tools. When the Parallels
   Tools package is installed in a virtual machine, a graceful
   shutdown can be performed from the outside. The available
   shutdown capabilities depend on the guest operating system
   and can be obtained using this function.
   Parameters
   hVm :        A handle of type PHT_VIRTUAL_MACHINE identifying
                the virtual machine.
   pCapsMask :  [out] A bitmask containing the supported graceful
                shutdown capabilities. See the
                PRL_GRACEFUL_SHUTDOWN_CAPABILITIES enumeration
                for available options.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_FAILURE - means that for some reason capabilities of
   graceful shutdown tool can't be obtained.

   PRL_ERR_INVALID_ARG - invalid vm handle or null pointer was
   passed.

   PRL_ERR_UNINITIALIZED - Desktop object is not accessible

   PRL_ERR_UNIMPLEMENTED - guest OS shutdown isn't supported

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVm_ToolsGetShutdownCapabilities, (
		PRL_HANDLE					hVm,
		PRL_UINT32_PTR				pCapsMask
	) );


/* Initiates graceful shutdown of the specified virtual machine.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   kind :  Specifies the type of the shutdown.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_ToolsSendShutdown, (
		PRL_HANDLE hVm,
		PRL_GRACEFUL_SHUTDOWN_KIND kind
		) );

/**
@brief Show/Hide task bar in guest.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] uVisibility - values of PRL_TASKBAR_STATES enum
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlVm_ToolsSetTaskBarVisibility, (
				PRL_HANDLE hVm,
				PRL_UINT32 uVisibility ) );

/**
@brief Allow/Forbid guest go to sleep mode by changing power scheme values.

@param[in] A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
@param[in] uAbility - values of PRL_POWER_SCHEME_SLEEP_ABILITY enum
*/
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlVm_ToolsSetPowerSchemeSleepAbility, (
				PRL_HANDLE hVm,
				PRL_UINT32 uAbility ) );

///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the optimization of virtual hard disk
///////////////////////////////////////////////////////////////////////////////

/**
Start process of optimization of virtual hard disk.
The machine should be registered on the server to do that.

Parameters
hVm    :  valid PRL_HANDLE describing the virtual machine
uMask  :  bit mask of really hard disk devices (little endian order).
          See PRL_HARD_DISK_IFACE_MASK enumeration for all bits.
nFlags :  only bit PACF_NON_INTERACTIVE_MODE is used.
          Others bits are reserved

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was passed
PRL_ERR_UNINITIALIZED - unexpected error: uninitialized with server connection or non identified VM object
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_Compact, (
               PRL_HANDLE hVm,
               PRL_UINT32 uMask,
			   PRL_UINT32 nFlags
             ) );

/**
Finishes process of optimization of virtual hard disk.
The machine should be registered on the server to do that.

Parameters
handle : valid PRL_HANDLE describing the virtual machine

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was passed
PRL_ERR_UNINITIALIZED - unexpected error: uninitialized with server connection or non identified VM object
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVm_CancelCompact, (
               PRL_HANDLE hVm
               ) );


/**
Start process conversion of the virtual hard disk(s).
The machine should be registered on the server to do that.

Parameters
hVm    :  valid PRL_HANDLE describing the virtual machine
uMask  :  bit mask of really hard disk devices (little endian order).
          See PRL_HARD_DISK_IFACE_MASK enumeration for all bits.
nFlags :  See PRL_CONVERT_VIRTUAL_DISK enumeration for using bits.

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was passed
PRL_ERR_UNINITIALIZED - unexpected error: uninitialized with server connection or non identified VM object
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVm_ConvertDisks, (
               PRL_HANDLE hVm,
               PRL_UINT32 uMask,
			   PRL_UINT32 nFlags
             ) );


/**
Finishes process of conversion of the virtual hard disk(s).
The machine should be registered on the server to do that.

Parameters
hVm : valid PRL_HANDLE describing the virtual machine
nFlags :  Reserved.

Returns
PRL_HANDLE to job that describing async operation result (PRL_INVALID_HANDLE means not enough memory to
instantiate async job represents object handle). Operation return code can be extracted with @ref PrlJob_GetRetCode()
call. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_VIRTUAL_MACHINE handle was passed
PRL_ERR_UNINITIALIZED - unexpected error: uninitialized with server connection or non identified VM object
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVm_CancelConvertDisks, (
               PRL_HANDLE hVm,
			   PRL_UINT32 nFlags
               ) );


/**
   Generates and assigns a new Windows SID to the specified virtual machine running Windows guest OS.
   This function is useful when cloning or migrating a virtual machine to another host to avoid conflicts.
   Please note that this functionality is applicable to Windows guests only.
   Parallels Tools must be installed in the virtual machine.
   The machine must be stopped before calling this function.

   Parameters
      hVm : A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
      nFlags : Reserved for future use.

   Returns
   A handle of type PHT_JOB containing the results of this asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object. To get the return code from the PHT_JOB object, use the PrlJob_GetRetCode
   function. Possible values are:
      PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
      PRL_ERR_SUCCESS - function completed successfully.
      PRL_ERR_UNINITIALIZED – unknown PHT_VIRTUAL_MACHINE handle or invalid binding to server connection.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVm_ChangeSid, (
               PRL_HANDLE hVm,
			   PRL_UINT32 nFlags
               ) );


/**
   Resets the virtual machine uptime counter (start date and counter itself).

   Parameters
      hVm : A handle of type PHT_VIRTUAL_MACHINE identifying the virtual machine.
      nFlags : Reserved for future use.

   Returns
   A handle of type PHT_JOB containing the results of this asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object. To get the return code from the PHT_JOB object, use the PrlJob_GetRetCode
   function. Possible values are:
      PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
      PRL_ERR_SUCCESS - function completed successfully.
      PRL_ERR_UNINITIALIZED – unknown PHT_VIRTUAL_MACHINE handle or invalid binding to server connection.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_ResetUptime, (
               PRL_HANDLE hVm,
			   PRL_UINT32 nFlags
               ) );


/* Subscribe on TIS database updates.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_TisSubscribe, (
	PRL_HANDLE hObj
	) );

/* Unsubscribe from TIS database updates.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_TisUnsubscribe, (
	PRL_HANDLE hObj
	) );

/* Retrieves a list of identifiers from the Tools Information
   Service database.
   Parameters
   hVm :         A handle of type PHT_VIRTUAL_MACHINE identifying
                 the virtual machine.
   phUidsList :  [out] A handle of type PHT_STRINGS_LIST
                 containing the identifiers.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create
   PHT_STRINGS_LIST object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVm_TisGetRecord                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_TisGetIdentifiers, (
	PRL_HANDLE hVm,
	PRL_HANDLE_PTR phUidsList
	) );

/* Obtains a handle of type PHT_TIS_RECORD containing a record
   from the Tools Information Service database.
   Parameters
   hVm :       A handle of type PHT_VIRTUAL_MACHINE identifying
               the virtual machine.
   sUid :      TIS database record identifier. The list of
               identifiers can be retrieved from the TIS database
               with PrlVm_TisGetIdentifiers.
   phRecord :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create PHT_TIS_RECORD
   object.

   PRL_ERR_TIS_INVALID_UID - specified record not found.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVm_TisGetIdentifiers                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVm_TisGetRecord, (
	PRL_HANDLE hVm,
	PRL_CONST_STR sUid,
	PRL_HANDLE_PTR phRecord
	) );


/* Send input to guest.
   Input object must not be modified from other thread during this operation.

   Parameters
   hVm          : [in] Vm handle. Must be valid.
   hInput	    : [in] Handle of type PHT_UIEMU_INPUT. Must be valid.
   reserved     : [in] Must be 0.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVm_UIEmuSendInput, (
	PRL_HANDLE hVm,
	PRL_HANDLE hInput,
	PRL_UINT32 reserved
	) );

/* Send specified UTF8 text to guest User Input Emulation tool. This will have
   the same affect as user typed specified text from keyboard.

   Parameters
   hObj         : [in] A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   uiEmuVersion : [in] Guest tool version that can be returned by TIS.
                  Can't be 0.
   text         : [in] text to send. Must be UTF8 encoded. Can't be 0.
   textLength   : [in] text length. Can be 0 - in that case text must be
				  zero terminated. Use PrlApi_UIEmuSendTextMaxLength() to get
                  maximum text length for specified version.
   flags        : [in] Flags. Must be 0 now.
   textSent     : [out] On success receives length of text that was actually
                  sent. Can be 0.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - hVm is invalid, uiEmuVersion or text is 0.
   PRL_ERR_VM_TOOL_NOT_AVAILABLE - required OS Integration tool not present.
   PRL_ERR_UNIMPLEMENTED - operation is not supported by current tool version.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVm_UIEmuSendText, (
	PRL_HANDLE hObj,
	PRL_CONST_STR text,
	PRL_UINT32 textLength,
	PRL_UINT32 flags,
	PRL_UINT32_PTR textSent
	) );

/* Send scroll event to User Input Emulation.

   Parameters
   hObj         : [in] A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   scrollUnits  : [in] Scroll units.
   scrollX      : [in] Amount of scroll along X axis.
   scrollY      : [in] Amount of scroll along Y axis.
   flags        : [in] Flags. One of PRL_UIEMU_SCROLL_FLAGS.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - hVm is invalid, uiEmuVersion or text is 0.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_FAILURE - failed to send event.                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVm_UIEmuSendScroll, (
	PRL_HANDLE hObj,
	PRL_UIEMU_SCROLL_UNITS scrollUnits,
	PRL_INT32 scrollX,
	PRL_INT32 scrollY,
	PRL_UINT32 flags
	) );

/* Send mouse click event to User Input Emulation.
   Click mouse button at the specified absolute position.

   Since not all versions of User Input Emulation tool support this request
   and not all guest OS can supply required functionality, use TIS uuid
   TIS_UID_UIEMU_GUEST_CROSS_CLICK
   ("parallels.UserInputEmulation.guest.cross.Click")
   to get status of that feature. If this uuid is in active state in TIS
   database, this function can be used.

   Parameters
   hVm				: [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   posX				: [in] x coordinate within guest screen.
   posY				: [in] y coordinate within guest screen.
   count			: [in] Click count. One of PRL_UIEMU_MOUSE_CLICK.
   button			: [in] Mouse button identifier. See the PRL_MOUSE_BUTTON
						   enumeration for available choices. Don't use
						   PMB_NOBUTTON, because in this case no button to click.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.
   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlVm_UIEmuSendClick, (
		PRL_HANDLE hVm,
		PRL_INT32 posX,
		PRL_INT32 posY,
		PRL_UINT32 count,
		PRL_UINT32 button
		) );

/* Posts "get info on element at specified position" query to guest
   User Input Emulation tool.
   Response will be received via PET_IO_UIEMU_ELEMENT_AT_POS event with
   PRL_UIEMU_ELEMENT_AT_POS structure on board.
   Note, that guest tool will not always reply with
   PET_IO_UIEMU_ELEMENT_AT_POS event. It will reply only when it got some
   information on UI element at specified position.
   Since not all versions of User Input Emulation tool support this request
   and not all guest OS can supply required functionality, use TIS uuid
   "parallels.UserInputEmulation.guest.win.plugin.UIElement" to get status
   of that feature. If this uuid is in active state in TIS database, this
   function can be used.
   Note, that the lowest version of User Input Emulation tool
   (TIS uuid "parallels.UserInputEmulation.guest.win.plugin") that can
   support that request is 1.2 (but it is always enough to check only for
   "parallels.UserInputEmulation.guest.win.plugin.UIElement").

   Parameters
   hVm	        : [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   posX         : [in] x coordinate within guest screen.
   posY         : [in] y coordinate within guest screen.
   queryId      : [in] user-defined value that will be in response.
   queryFlags   : [in] additional options.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVm_UIEmuQueryElementAtPos, (
	PRL_HANDLE hVm,
	PRL_INT32 posX,
	PRL_INT32 posY,
	PRL_INT32 queryId,
	PRL_UINT32 queryFlags
	) );

/* Posts "get info on nearest element at specified position" query to guest
   User Input Emulation tool.
   Response will be received via PET_IO_UIEMU_ELEMENT_AT_POS event with
   PRL_UIEMU_ELEMENT_AT_POS structure on board.
   Guest tool will always reply.
   Since not all versions of User Input Emulation tool support this request
   and not all guest OS can supply required functionality, use TIS uuid
   TIS_UID_UIEMU_GUEST_CROSS_PLUGIN_NEAREST_ELEMENT
   ("parallels.UserInputEmulation.guest.cross.plugin.NearestElement")
   to get status of that feature. If this uuid is in active state in TIS
   database, this function can be used.

   Parameters
   hVm				: [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   queryId			: [in] user-defined value that will be in response.
   posX				: [in] x coordinate within guest screen.
   posY				: [in] y coordinate within guest screen.
   searchDiameter	: [in] diameter of search nearest element area.
   queryFlags		: [in] additional options. One of PRL_QUERY_ELEMENT_FLAGS.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_UIEmuQueryNearestElementAtPos, (
	PRL_HANDLE hVm,
	PRL_INT32 queryId,
	PRL_INT32 posX,
	PRL_INT32 posY,
	PRL_UINT32 searchDiameter,
	PRL_UINT32 queryFlags
	) );

/* Posts "get caret info" query to guest User Input Emulation tool.
   Response will be received via PET_IO_UIEMU_CARET_INFO event with
   PRL_UIEMU_CARET_INFO structure on board.
   Note, that guest tool will not always reply with
   PET_IO_UIEMU_CARET_INFO event. It will reply only when it got some
   information on caret.
   Since not all versions of User Input Emulation tool support this request
   and not all guest OS can supply required functionality, use TIS uuid
   "parallels.UserInputEmulation.guest.cross.plugin.CaretInfo" to get status
   of that feature. If this uuid is in active state in TIS database, this
   function can be used.

   Parameters
   hVm	        : [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   queryId      : [in] user-defined value that will be in response.
   quertFlags   : [in] additional options.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_UIEmuQueryCaretInfo, (
	PRL_HANDLE hVm,
	PRL_INT32 queryId,
	PRL_UINT32 queryFlags
	) );

/* Sends a multimedia key to guest User Input Emulation tool.
   Check "parallels.UserInputEmulation.guest.cross.EdgeSwipes" in TIS to
   detect whether Windows 8 edge swipes are available

   Parameters
   hVm	        : [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   mmkey        : [in] multimedia key id
   flags        : [in] additional options.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_UIEmuSendMultimediaKey, (
	PRL_HANDLE hVm,
	PRL_UIEMU_MMKEY mmkey,
	PRL_UINT32 flags
	) );


/* Sends a gesture event to guest User Input Emulation tool.

   Parameters
   hVm	        : [in] Handle of type PHT_VIRTUAL_MACHINE. Must be valid.
   pGestureEvent: [in] Gesture event description struct

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - memory allocation error during send.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_UIEmuSendGestureEvent, (
	PRL_HANDLE hVm,
	PRL_CONST_UIEMU_GESTURE_EVENT_PTR pGestureEvent
	) );

/* Performs an attempt to authenticate the user through the
   guest OS security database. To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer (empty
   string) for user name was passed.

   PRL_ERR_AUTHENTICATION_FAILED - user authentication failed.

   PRL_ERR_SUCCESS - user authenticated successfully.
   Parameters
   hVm :            A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   sUserName :      User login name.
   sUserPassword :  User password (can be an empty string or NULL
                    if the user doesn't have a password).
   nFlags :         A bitset of flags (should be 0 in the current
                    implementation).
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVm_AuthWithGuestSecurityDb, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sUserName,
		PRL_CONST_STR sUserPassword,
		PRL_UINT32 nFlags
		) );


/* Creates video source object.

   Parameters
   hVm	    : [in] A handle of type PHT_VIRTUAL_MACHINE identifying the Vm.
                   Created video source will be linked to that Vm.
   hCVSrc   : [out] On success receives handle of type PHT_CVSRC.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_UNIMPLEMENTED - if featue is not implemented for specified Vm.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlVm_CreateCVSrc, (
		PRL_HANDLE hVm,
		PRL_HANDLE_PTR hCVSrc
		) );


/* Move bundle of virtual machine or private area of container.
   The function move all content of bundle to specify location.
   This function will move only stopped or suspended Vm.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine or container.
   sNewHomePath :      Target path for Vm bundle
   nFlags :            Flags that specify move type. Not used yet.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVm_Move, (
		PRL_HANDLE hVm,
		PRL_CONST_STR sNewHomePath,
		PRL_UINT32 nFlags
		) );


/* Connect to remote desktop.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   nFlags :  Flags, must be 0.

   Returns
   A handle of type PHT_JOB containing the results of operation.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_5,
						   PrlVm_Connect, (
		PRL_HANDLE hObj,
		PRL_UINT32 nFlags
		) );


/* Disconnect from remote desktop.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVm_Disconnect, (
		PRL_HANDLE hObj
		) );

/* Connect to vm.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE.
   nFlags :  Flags, must be 0.

   Returns
   A handle of type PHT_JOB containing the results of operation.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_6,
               PrlVm_TerminalConnect, (
    PRL_HANDLE hVm,
    PRL_UINT32 nFlags
    ) );


/* Disconnect from vm.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6,
         PrlVm_TerminalDisconnect, (
    PRL_HANDLE hVm
    ) );


/**
@brief Requests clipboard buffer from Vm

@note This call is intended to be asynchronious with
possibility to be synchroneous.
It can be used when it's necessary to wait for Vm answer.

Parameters
@param [in] hVm valid PRL_HANDLE of PHT_VIRTUAL_MACHINE type
@param [in] command that identifies action
@param [in] flags contain session IDs for sender and recipient
@param [in] data is pointer to transferring data
@param [in] size of transferring data

Returns
PRL_RESULT.

Possible values:
PRL_ERR_INVALID_ARG - non valid VM device
PRL_INVALID_HANDLE - invalid handle
or valid handle if success.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
					   PrlVm_SendClipboardRequest, (
					  PRL_HANDLE hVm,
					  PRL_UINT32 command,
					  PRL_UINT32 flags,
					  PRL_CONST_VOID_PTR data,
					  PRL_UINT32 dataSize
					  ) );


///////////////////////////////////////////////////////////////////////////////
/// @section Virtual machine guest OS session operations set
///////////////////////////////////////////////////////////////////////////////

/* Closes a session (or unbinds from a pre-existing session) in
   a virtual machine that was previously opened with the
   PrlVm_LoginInGuest function. To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmGuest :   A handle of type PHT_VM_GUEST_SESSION identifying
                the session.
   nReserved :  Reserved parameter for future purposes. Must
                contain 0 in the current implementation.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlVm_LoginInGuest
                                                                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVmGuest_Logout, (
		PRL_HANDLE hVmGuest,
		PRL_UINT32 nReserved
		) );

/* Executes a program in a virtual machine. Prior to calling
   this function, a handle to a user session in a virtual
   machine must be obtained using the PrlVm_LoginInGuest
   function. Once you obtain a session handle, you can use this
   function to run programs in the virtual machine. Depending on
   the options that were used during login, you will be able to
   run GUI applications and/or console programs. See the
   PrlVm_LoginInGuest function for more info.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_VM_EXEC_PROGRAM_NOT_FOUND - the specified program at
   the specified path was not found.

   PRL_ERR_UNINITIALIZED - file descriptors interface tried to use but
   PrlDevDisplay_ConnectToVm wasn't call.

   PRL_ERR_SUCCESS - program executed successfully.
   Parameters
   hVmGuest :   A handle of type PHT_VM_GUEST_SESSION identifying
                the user session in a virtual machine. The handle
                is obtained using the PrlVm_LoginInGuest
                function.
   sAppName :   An absolute path to the program that you would
                like to execute.
   hArgsList :  A handle of type PHT_STRINGS_LIST specifying the
                list of arguments to pass to the program. Each
                token must be a separate list item.
   hEnvsList :  A handle of type PHT_STRINGS_LIST specifying the
                list of environment variables to add to the
                program execution environment. Each variable must
                be a separate list item in the var_name=var_value
                format.
   nFlags :     Modificators of the program execution. Acceptable
                values\:<p />PFD_STDOUT \- return stdout.<p />PFD_STDERR
                \- return stderr.<p />PFD_ALL \- return both
                stdout and stderr (a blank nFlags parameter
                yields the same result).<p />PRPM_RUN_PROGRAM_AND_RETURN_IMMEDIATELY
                \- run the program and return immediately without
                waiting for the program execution results.
   nStdin :     file descriptor on standard input (PRL_INVALID_FILE_DESCRIPTOR
                should be passed if you don't want to use file descriptors.
				Please note that IO channel between client and VM should be
				established before using file descriptors. Please call
				PrlDevDisplay_ConnectToVm in order to do it).
   nStdout :    file descriptor on standard output (PRL_INVALID_FILE_DESCRIPTOR
                should be passed if you don't want to use file descriptors.
				Please note that IO channel between client and VM should be
				established before using file descriptors. Please call
				PrlDevDisplay_ConnectToVm in order to do it).
   nStderr :    file descriptor on standard errors output (PRL_INVALID_FILE_DESCRIPTOR
                should be passed if you don't want to use file descriptors.
				Please note that IO channel between client and VM should be
				established before using file descriptors. Please call
				PrlDevDisplay_ConnectToVm in order to do it).
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                                      */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVmGuest_RunProgram, (
		PRL_HANDLE hVmGuest,
		PRL_CONST_STR sAppName,
		PRL_HANDLE hArgsList,
		PRL_HANDLE hEnvsList,
		PRL_UINT32 nFlags,
		PRL_FILE_DESC nStdin,
		PRL_FILE_DESC nStdout,
		PRL_FILE_DESC nStderr
		) );

/* Obtains network settings of a guest operating system running
   in a virtual machine. The network settings are obtained using
   a user session in the guest operating system. Prior to
   calling this function, a handle to a user session in the
   virtual machine must be obtained using the PrlVm_LoginInGuest
   function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.
   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the returned PHT_JOB object, use the
   following steps:
     1. Use the PrlJob_GetResult function to obtain a handle of
        type PHT_RESULT.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_SERVER_CONFIG. The handle will contain the guest
        OS network settings.
   Once you obtain the PHT_SERVER_CONFIG handle, you can use the
   following functions to obtain individual network settings of
   the guest OS:

   PrlSrvCfg_GetDnsServers

   PrlSrvCfg_GetHostname

   PrlSrvCfg_GetSearchDomains

   PrlSrvCfg_GetNetAdapter

   PrlSrvCfg_GetDefaultGateway
   Parameters
   hVmGuest :   A handle of type PHT_VM_GUEST_SESSION identifying
                the user session in a virtual machine. The handle
                is obtained using the PrlVm_LoginInGuest
                function.
   nReserved :  Reserved parameter for future purposes. Must be 0
                in the current implementation.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                      */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVmGuest_GetNetworkSettings, (
		PRL_HANDLE hVmGuest,
		PRL_UINT32 nReserved
		) );

/* Allows to change the password of a guest operating system
   user. Prior to calling this function, a handle to a user
   session in a virtual machine must be obtained using the
   PrlVm_LoginInGuest function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmGuest :     A handle of type PHT_VM_GUEST_SESSION
                  identifying the user session in a virtual
                  machine. The handle is obtained using the
                  PrlVm_LoginInGuest function.
   sUserName :    Guest operating system user name. Can be null
                  or empty string when setting the administrator
                  password.
   sUserPasswd :  New password. Can be null when setting an empty
                  password.
   nFlags :       Bitset of flags - from enum PRL_SET_USERPASSWD_FLAGS

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.


   See Also
   PrlVm_LoginInGuest                                             */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVmGuest_SetUserPasswd, (
		PRL_HANDLE hVmGuest,
		PRL_CONST_STR sUserName,
		PRL_CONST_STR sUserPasswd,
		PRL_UINT32 nFlags
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Virtual machine configuration operations set
///////////////////////////////////////////////////////////////////////////////

/* The PrlVmCfg_SetDefaultConfig function selects a default
   configuration for a new virtual machine based on the
   operating system that the virtual machine will be running.
   The default configuration information is obtained from the
   host machine configuration, which is passed to the function as
   a parameter. Using a default configuration for a new virtual
   machine is the simplest and safest way to configure a new
   virtual machine. For the example on how to create a new
   virtual machine using a default configuration, see the
   PrlVm_Reg function.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   hSrvConfig :         A handle of type PHT_SERVER_CONFIG.
   guestOsVersion :     The version of the operating system that
                        the virtual machine will be running. The
                        OS versions can be found in the PrlOses.h
                        \file. The names of the macros are
                        prefixed with PVS_GUEST_VER_ (e.g.
                        PVS_GUEST_VER_MACOS_LEOPARD).
   needCreateDevices :  A flag indicating whether default virtual
                        machine devices should be created or not.
                        Specify PRL_TRUE to create default
                        devices, or PRL_FALSE to skip the device
                        creation.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetDefaultConfig, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSrvConfig,
		PRL_UINT32 guestOsVersion,
		PRL_BOOL needCreateDevices
		) );

/* The PrlVmCfg_SetDefaultConfigEx function selects a default
   configuration for a new virtual machine based on the
   operating system that the virtual machine will be running.
   The default configuration information is obtained from the
   host machine configuration, which is passed to the function as
   a parameter. Using a default configuration for a new virtual
   machine is the simplest and safest way to configure a new
   virtual machine. For the example on how to create a new
   virtual machine using a default configuration, see the
   PrlVm_Reg function.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   hSrvConfig :         A handle of type PHT_SERVER_CONFIG.
   hVmGuestOsInfo :     A handle of type PHT_VM_GURST_OS_INFO with
   hGuestOsVersion :     information of the operating system that
                        the virtual machine will be running.
   needCreateDevices :  A flag indicating whether default virtual
                        machine devices should be created or not.
                        Specify PRL_TRUE to create default
                        devices, or PRL_FALSE to skip the device
                        creation.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				 PrlVmCfg_SetDefaultConfigEx, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSrvConfig,
		PRL_HANDLE hVmGuestOsInfo,
		PRL_BOOL needCreateDevices
		) );

/* The PrlVmCfg_TuneDefaultConfig function intends to tune a just created
   default configuration of a virtual machine according to details of
   operating system that the virtual machine will be running.

   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   hSrvConfig :         A handle of type PHT_SERVER_CONFIG.
   hVmGuestOsInfo :     A handle of type PHT_VM_GUEST_OS_INFO.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				 PrlVmCfg_TuneDefaultConfig, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSrvConfig,
		PRL_HANDLE hVmGuestOsInfo
		) );

/* The PrlVmCfg_GetConfigValidity function returns an error code.
   The error code indicates the status of the config: config doesn't
   exist, parsing error, config can be restored and others errors.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   pnErrCode : [out] A pointer to a variable that receives the
               error code as PRL_RESULT.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetConfigValidity, (
		PRL_HANDLE hVmCfg,
		PRL_RESULT_PTR pnErrCode
		) );

/* The PrlVmCfg_IsConfigInvalid function is used to check the
 * error code of PrlVmCfg_GetConfigValidity function that
 * indicates the invalid status of the config:
 * config doesn't exist, parsing error, invalid server uuid,
 * invalid VM uuid.
 * Parameters
 * nErrCode : The nErrCode value from PrlVmCfg_GetConfigValidity()
 * pbInvalid  : [out] validity sign.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                        PrlVmCfg_IsConfigInvalid, (
                PRL_RESULT nErrCode,
                PRL_BOOL_PTR pbInvalid
                ) );

/* The PrlVmCfg_AddDefaultDevice function automates the task of
   setting devices in a virtual machine. When creating or
   modifying a virtual machine configuration, one must choose if
   a device of a particular type will be a pure virtual device
   or if it will be mapped to a physical device on the host.
   To make a device pure virtual, set the hSrvConfig
   parameter value to PRL_INVALID_HANDLE. To map a virtual
   device to a physical device, obtain an object of type
   PHT_SERVER_CONFIG and pass it to the function using the
   hSrvConfig parameter. If multiple physical devices of the
   specified type exist on the host, the destination physical
   device will be chosen randomly by the function.

   The virtual devices that can be mapped to physical devices
   include floppy disk drives, CD drives, serial and parallel
   ports, and sound devices. The devices that can exist only as
   pure virtual include hard disk drives, network adapters, and
   USB devices. To determine if a device of particular type must
   be added to a virtual machine, use the
   PrlVmCfg_IsDefaultDeviceNeeded function.

   Before calling this function, you must execute the
   PrlVm_BeginEdit function. After the PrlVmCfg_AddDefaultDevice
   function returns, you must call the PrlVm_Commit to save the
   changes in the virtual machine configuration.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   hSrvConfig :  A handle of type PHT_SERVER_CONFIG containing
                 the host machine configuration information. If
                 this parameter is set to PRL_INVALID_HANDLE, the
                 device of the specified type will be configured
                 as pure virtual (i.e. it will not be mapped to a
                 physical device on the host).
   deviceType :  The type of the device to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OPERATION_FAILED - unable to set a device of the
   specified type.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_AddDefaultDevice, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSrvConfig,
		PRL_DEVICE_TYPE deviceType
		) );


/* The PrlVmCfg_AddDefaultDeviceEx function automates the task of
   setting devices in a virtual machine. When creating or
   modifying a virtual machine configuration, one must choose if
   a device of a particular type will be a pure virtual device
   or if it will be mapped to a physical device on the host.
   To make a device pure virtual, set the hSrvConfig
   parameter value to PRL_INVALID_HANDLE. To map a virtual
   device to a physical device, obtain an object of type
   PHT_SERVER_CONFIG and pass it to the function using the
   hSrvConfig parameter. If multiple physical devices of the
   specified type exist on the host, the destination physical
   device will be chosen randomly by the function.

   The virtual devices that can be mapped to physical devices
   include floppy disk drives, CD drives, serial and parallel
   ports, and sound devices. The devices that can exist only as
   pure virtual include hard disk drives, network adapters, and
   USB devices. To determine if a device of particular type must
   be added to a virtual machine, use the
   PrlVmCfg_IsDefaultDeviceNeeded function.

   Before calling this function, you must execute the
   PrlVm_BeginEdit function. After the PrlVmCfg_AddDefaultDeviceEx
   function returns, you must call the PrlVm_Commit to save the
   changes in the virtual machine configuration.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   hSrvConfig :  A handle of type PHT_SERVER_CONFIG containing
                 the host machine configuration information. If
                 this parameter is set to PRL_INVALID_HANDLE, the
                 device of the specified type will be configured
                 as pure virtual (i.e. it will not be mapped to a
                 physical device on the host).
   deviceType :  The type of the device to set.
   phVmDevice :  [out] A pointer to a variable that receives the
                 new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OPERATION_FAILED - unable to set a device of the
   specified type.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_AddDefaultDeviceEx, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSrvConfig,
		PRL_DEVICE_TYPE deviceType,
		PRL_HANDLE_PTR phVmDevice
		) );


/* Determines whether the virtual machine requires a default
   device of the specified type if it's going to run an
   operating system of the specified type. The function accepts
   the target operating system type, version, and a device type
   identifier. Using these parameters, it determines if the
   specified device is required in order for the projected
   virtual machine to run properly. If the device is required,
   you must add it to the virtual machine using the
   PrlVmCfg_AddDefaultDevice function. If the device is not
   required, you don't have to add it (i.e. it will not affect
   the operation of a virtual machine).
   Parameters
   guestOsVersion :  Target OS version. The OS versions are
                     defined in the PrlOses.h file as macros.
                     Look for the macros that are prefixed with
                     PVS_GUEST_VER_ (e.g.
                     PVS_GUEST_VER_MACOS_LEOPARD).
   deviceType :      Device type.
   pbNeeded :        [out] A pointer to a variable that receives
                     the result. PRL_TRUE indicates that the
                     device of specified type is required.
                     PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsDefaultDeviceNeeded, (
		PRL_UINT32 guestOsVersion,
		PRL_DEVICE_TYPE deviceType,
		PRL_BOOL_PTR pbNeeded
		) );

/* The PrlVmCfg_GetDefaultMemSize function returns the default RAM
   size for to the specified OS type and version. When creating
   a virtual machine using a default configuration, the default
   memory size is defined for every supported operating system
   type and version. The default sizes can be retrieved using
   this function. The OS types are defined in the PrlOses.h file
   as macros. Look for the macros that are prefixed with
   PVS_GUEST_TYPE_ (e.g. PVS_GUEST_TYPE_MACOS). The OS versions
   can be found in the same file. The names of the macros are
   prefixed with PVS_GUEST_VER_ (e.g.
   PVS_GUEST_VER_MACOS_LEOPARD).
   Parameters
   guestOsVersion :  Operating system version. See PrlOses.h for
                     type definitions.
   hostRam :         Optional. The amount of memory (RAM)
                     available on the host system. For some
                     operating system, this parameter may be used
                     to calculate the default the RAM size more
                     precisely.
   pnMemSize :       [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDefaultMemSize, (
		PRL_UINT32 guestOsVersion,
		PRL_UINT32 hostRam,
		PRL_UINT32_PTR pnMemSize
		) );

/* The PrlVmCfg_GetDefaultHddSize function returns the default hard
   disk size for to the specified OS type and version. When
   creating a virtual machine using a default configuration, the
   default hard disk is defined for every supported operating
   system type and version. The default HDD sizes can be
   retrieved using this function. The OS types are defined in
   the PrlOses.h file as macros. Look for the macros that are
   prefixed with PVS_GUEST_TYPE_ (e.g. PVS_GUEST_TYPE_MACOS).
   The OS versions can be found in the same file. The names of
   the macros are prefixed with PVS_GUEST_VER_ (e.g.
   PVS_GUEST_VER_MACOS_LEOPARD).
   Parameters
   guestOsVersion :  Operating system version. See PrlOses.h for
                     \version definitions.
   pnHddSize :       [out] A pointer to a variable that receives
                     the hard disk size, in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDefaultHddSize, (
		PRL_UINT32 guestOsVersion,
		PRL_UINT32_PTR pnHddSize
) );

/* The PrlVmCfg_GetDefaultVideoRamSize function returns the
   default video RAM size for the specified OS type and version.
   When creating a virtual machine using a default
   configuration, the default video memory size is defined for
   every supported operating system type and version. The
   default sizes can be retrieved using this function. The OS
   types are defined in the PrlOses.h file as macros. Look for
   the macros that are prefixed with PVS_GUEST_TYPE_ (e.g.
   PVS_GUEST_TYPE_MACOS). The OS versions can be found in the
   same file. The names of the macros are prefixed with
   PVS_GUEST_VER_ (e.g. PVS_GUEST_VER_MACOS_LEOPARD).
   Parameters
   guestOsVersion :       Operating system version. See PrlOses.h
                          for type definitions.
   hSrvConfig :           Optional. The host hardware info object
                          handle (PHT_SERVER_CONFIG type)
                          contains necessary information about
                          host hardware configuration (amount of
                          RAM, host type and etc.). For some
                          operating system, this parameter may be
                          used to calculate the default video RAM
                          size more precisely.
   bIs3DSupportEnabled :  sign which specifies whether 3D support
                          will be enabled at creating VM. 3D
                          support require at least 128 Mb of
                          video RAM in common case.
   pnVideoRamSize :       [out] A pointer to a variable that
                          receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetDefaultVideoRamSize, (
		PRL_UINT32 guestOsVersion,
		PRL_HANDLE hSrvConfig,
		PRL_BOOL bIs3DSupportEnabled,
		PRL_UINT32_PTR pnVideoRamSize
		) );


/* Creates a new virtual device handle of the specified type.
   The names of the virtual device handles are prefixed with
   PHT_VIRTUAL_DEV_ (you may search this documentation for their
   definitions or see the _PRL_HANDLE_TYPE enumeration for a
   complete list of handles). It is the responsibility of the
   user to free the handle when it is no longer needed.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nDeviceType :  The type of the device to create a handle for.
   phVmDevice :   [out] A pointer to a variable that receives the
                  new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_CreateVmDev, (
		PRL_HANDLE hVmCfg,
		PRL_DEVICE_TYPE nDeviceType,
		PRL_HANDLE_PTR phVmDevice
		) );

/* Determines the total number of devices of any type installed
   in the virtual machine.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine configuration.
   vmdev_handles_count :  [out] A pointer to a variable that
                          receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetDevsList                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDevsCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR vmdev_handles_count
		) );

/* Obtains a handles list of all virtual devices in a virtual machine.

   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   phDevsList :    [out] A pointer to a variable that receives
                   the handle. The type of the handles list is PHT_HANDLES_LIST.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle. */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetAllDevices, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phDevsList
		) );

/* Obtains the number of virtual devices of the specified type
   available in the specified virtual machine.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   vmDeviceType :    Device type.
   pnDevicesCount :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetDevByType                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDevsCountByType, (
		PRL_HANDLE hVmCfg,
		PRL_DEVICE_TYPE vmDeviceType,
		PRL_UINT32_PTR pnDevicesCount
		) );

/* Obtains a handle to a virtual device in a virtual machine
   according to the specified device type and index.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   vmDeviceType :  The device type.
   nIndex :        An index identifying the device instance
                   (beginning with 0). To determine the number of
                   the devices of the specified type available in
                   the virtual machine, use the
                   PrlVmCfg_GetDevsCountByType function.
   phDevice :      [out] A pointer to a variable that receives
                   the handle. The type of the handle can be
                   determined using the PrlHandle_GetType
                   function. You should also "know" the handle
                   type based on the device type for which you
                   are obtaining a handle. Search this
                   documentation for topics with PHT_VIRTUAL_DEV_
                   prefix in their names for the list of the
                   available virtual device handles.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetDevsCountByType                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDevByType, (
		PRL_HANDLE hVmCfg,
		PRL_DEVICE_TYPE vmDeviceType,
		PRL_UINT32 nIndex,
		PRL_HANDLE_PTR phDevice
		) );

/* Determines the number of floppy disk drives in a virtual
   machine.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine configuration.
   pnFloppyDisksCount :  [out] A pointer to a variable that
                         receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetFloppyDisksCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnFloppyDisksCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_FLOPPY containing
   information about the specified floppy disk drive in a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the floppy disk drive
               instance (beginning with 0). To get the number of
               floppy disk drives in the virtual machine, use the
               PrlVmCfg_GetFloppyDisksCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetFloppyDisk, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of virtual hard disks in a virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnHardDisksCount :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetHardDisksCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnHardDisksCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_HARD_DISK containing
   the specified virtual hard disk information.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the hard disk instance
               (beginning with 0). To get the number of hard
               disks installed in the virtual machine, use the
               PrlVmCfg_GetHardDisksCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetHardDisk, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of optical disks in the specified
   virtual machine.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine configuration.
   pnOpticalDisksCount :  [out] A pointer to a variable that
                          receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetOpticalDisksCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnOpticalDisksCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_OPTICAL_DISK
   containing information a virtual optical disk in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the optical disk instance
               (beginning with 0). To determine the number of
               optical disks in a virtual machine, use the
               PrlVmCfg_GetOpticalDisksCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetOpticalDisk, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of virtual printer ports in the
   specified virtual machine.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine configuration.
   pnParallelPortsCount :  [out] A pointer to a variable that
                           receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetParallelPortsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnParallelPortsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_PARALLEL_PORT
   containing information about a virtual printer port in the
   specified virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the printer port instance
               (beginning with 0). To determine the number of
               printer ports in a virtual machine, use the
               PrlVmCfg_GetParallelPortsCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetParallelPort, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of serial ports in a virtual machine.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine configuration.
   pnSerialPortsCount :  [out] A pointer to a variable that
                         receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSerialPortsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnSerialPortsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_SERIAL_PORT
   containing information about a serial port in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the serial port instance.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSerialPort, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of sound devices in a virtual machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnSoundDevsCount :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSoundDevsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnSoundDevsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_SOUND containing
   information about a sound device in a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the sound device (beginning
               with 0). To obtain the number of sound devices in
               a virtual machine, use the PrlVmCfg_GetSoundDevsCount
               function.
   phDevice :  [out] A pointer to a variable that receives the
               \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSoundDev, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of USB devices in a virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnUsbDevicesCount :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetUsbDevicesCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnUsbDevicesCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_USB_DEVICE
   containing information about a USB device in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the USB device (beginning
               with 0). To determine the number of USB devices in
               a virtual machine, use the
               PrlVmCfg_GetUsbDevicesCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetUsbDevice, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of network adapters in a virtual
   machine.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine configuration.
   pnNetAdaptersCount :  specifies a pointer to the count of
                         devices
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetNetAdaptersCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnNetAdaptersCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
   containing information about a virtual network adapter in a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   nIndex :    An index identifying the network adapter instance
               (beginning with 0). To determine the number of
               network adapters in the machine, use the
               PrlVmCfg_GetNetAdaptersCount function.
   phDevice :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetNetAdapter, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );


/* Determines the number of generic PCI devices in a virtual
   machine.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
                            configuration.
   pnGenericPciDevsCount :  [out] A pointer to a variable that
                            receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetGenericPciDev                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetGenericPciDevsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnGenericPciDevsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_GENERIC_PCI
   containing information about a generic PCI device in a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nIndex :    An index identifying the generic PCI device
               (beginning with 0). To obtain the number of
               generic PCI devices in a virtual machine, use the
               PrlVmCfg_GetGenericPciDevsCount function.
   phDevice :  [out] A pointer to a variable that receives the
               \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetGenericPciDevsCount                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetGenericPciDev, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );

/* Determines the number of generic SCSI devices in a virtual
   machine.
   Parameters
   hVmCfg :                  A handle of type
                             PHT_VM_CONFIGURATION identifying the
                             virtual machine configuration.
   pnGenericScsiDevsCount :  [out] A pointer to a variable that
                             receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetGenericScsiDev                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetGenericScsiDevsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnGenericScsiDevsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_GENERIC_SCSI
   containing information about a generic SCSI device in a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nIndex :    An index identifying the generic SCSI device
               (beginning with 0). To obtain the number of
               generic SCSI devices in a virtual machine, use the
               PrlVmCfg_GetGenericScsiDevsCount function.
   phDevice :  [out] A pointer to a variable that receives the
               \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetGenericScsiDevsCount                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetGenericScsiDev, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );


/* Determines the number of display devices in a virtual
   machine.
   Parameters
   hVmCfg :                  A handle of type
                             PHT_VM_CONFIGURATION identifying the
                             virtual machine configuration.
   pnGenericScsiDevsCount :  [out] A pointer to a variable that
                             receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetDisplayDev                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetDisplayDevsCount, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32_PTR pnDisplayDevsCount
				 ) );


/* Obtains a handle of type PHT_VIRTUAL_DEV_DISPLAY
   containing information about a display device in a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nIndex :    An index identifying the display device
               (beginning with 0). To obtain the number of
               display devices in a virtual machine, use the
               PrlVmCfg_GetDisplayDevsCount function.
   phDevice :  [out] A pointer to a variable that receives the
               \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetDisplayDevsCount                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetDisplayDev, (
				 PRL_HANDLE hVmCfg,
				 PRL_UINT32 nIndex,
				 PRL_HANDLE_PTR phDevice
				 ) );


/* Determines whether the SmartGuard feature is enabled or not
   in a virtual machine. SmartGuard is feature that allows to
   make automatic snapshots of a virtual machine at predefined
   time intervals. The feature requires Parallels Tools
   installed in a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that SmartGuard is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSmartGuardEnabled                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsSmartGuardEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* <unfinished>

   Enables the SmartGuard feature in a virtual machine.
   SmartGuard is feature that allows to make automatic snapshots
   of a virtual machine at predefined time intervals. The
   feature requires Parallels Tools installed in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable
               SmartGuard. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSmartGuardInterval

   PrlVmCfg_SetSmartGuardMaxSnapshotsCount

   PrlVmCfg_SetSmartGuardNotifyBeforeCreation                    */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetSmartGuardEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Determines whether the user will be notified on automatic
   snapshot creation, a SmartGaurd setting. See
   PrlVmCfg_SetSmartGuardNotifyBeforeCreation for more
   information.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbNotifyBeforeCreation :  [out] A pointer to a variable that
                receives the \result. PRL_TRUE indicates that
				the user will be automatically notified.
				PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSmartGuardNotifyBeforeCreation                     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsSmartGuardNotifyBeforeCreation, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbNotifyBeforeCreation
		) );

/* <unfinished>

   Enables or disables notification of automatic snapshot
   creation, a SmartGuard feature. SmartGuard is a facility that
   allows to make automatic snapshots of a virtual machine at
   predefined time intervals. By default, the snapshots are
   creating transparently to the user. If needed, Parallels
   Service can notify the user that a snapshot is about to be
   created. The user can then choose to proceed with snapshot
   creation or cancel it. This function allows to enabled or
   disable this feature. The notifications are received by the
   client via the PHT_EVENT handle received by a callback
   function. See PHT_EVENT and PrlEvent_CreateAnswerEvent for
   more information and code samples.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bNotifyBeforeCreation :  Action type. Specify PRL_TRUE if you
               want the user to be notified. Specify PRL_FALSE
			   if you want to create snapshots silently.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsSmartGuardNotifyBeforeCreation                      */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetSmartGuardNotifyBeforeCreation, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bNotifyBeforeCreation
		) );


/* Determines the interval at which snapshots are taken by
   SmartGuard. SmartGuard is a facility that allows to make
   automatic snapshots of a virtual machine at predefined time
   intervals. The currently set time interval can be obtained
   using this function.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pnInterval :  [out] A pointer to a variable the receives the
                snapshot creation interval, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSmartGuardInterval                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_GetSmartGuardInterval, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnInterval
		) );

/* <unfinished>

   Sets the time interval at which snapshots are taken by
   SmartGuard. SmartGuard is feature that allows to make
   automatic snapshots of a virtual machine at predefined time
   intervals. This function allows to set the interval at which
   the automatic snapshots are taken.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nInterval :  The time interval to set, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetSmartGuardInterval                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetSmartGuardInterval, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nInterval
		) );


/* Determines the maximum snapshot count, a SmartGuard setting.
   SmartGuard is a facility that allows to make automatic
   snapshots of a virtual machine at predefined time intervals.
   The snapshot count setting specifies how many snapshots taken
   by SmartGuard will be kept on the hard drive (maximum is
   100). As soon as the maximum number is exceeded, the oldest
   snapshot is deleted.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_GetSmartGuardMaxSnapshotsCount, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnMaxSnapshotsCount
		) );

/* <unfinished>

   Sets the maximum snapshot count, a SmartGuard feature.
   SmartGuard is a facility that allows to make automatic
   snapshots of a virtual machine at predefined time intervals.
   The snapshot count setting specifies how many snapshots taken
   by SmartGuard will be kept on the hard drive (maximum is
   100). As soon as the maximum number is exceeded, the oldest
   snapshot is deleted.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   nMaxSnapshotsCount :  Maximum snapshot count to set. The
                         maximum allowable value is 100.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetSmartGuardMaxSnapshotsCount, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nMaxSnapshotsCount
		) );


/* Determines whether the user-defined shared folders are
   enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUserDefinedSharedFoldersEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables user-defined shared folders.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUserDefinedSharedFoldersEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether shared cloud is enabled or disabled.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
		PrlVmCfg_IsSharedCloudEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables shared cloud.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
		PrlVmCfg_SetSharedCloudEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section VM Modality operations
///////////////////////////////////////////////////////////////////////////////

/* Determines the opacity used in modality mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pdOpacity :  [out] A pointer to a variable that receives the
                \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetModalityOpacity, (
                PRL_HANDLE hVmCfg,
                PRL_DOUBLE_PTR pdOpacity
		) );

/* Sets the opacity used in modality mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   dOpacity :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetModalityOpacity, (
               PRL_HANDLE hVmCfg,
               PRL_DOUBLE dOpacity
		) );

/* Determines whether the stay on top in modality mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsModalityStayOnTop, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables stay on top in modality mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetModalityStayOnTop, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the show on all spaces in modality mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsModalityShowOnAllSpaces, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables show on all spaces in modality mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetModalityShowOnAllSpaces, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the capture mouse clicks in modality mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsModalityCaptureMouseClicks, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables capture mouse clicks in modality mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetModalityCaptureMouseClicks, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section VM Fullscreen operations
///////////////////////////////////////////////////////////////////////////////

/* Determines whether the use all displays are enabled or not
   in fullscreen mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsFullscreenUseAllDisplays, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables using all displays in fullscreen mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetFullscreenUseAllDisplays, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the activate spaces on click are enabled or not
   in fullscreen mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsFullscreenActivateSpacesOnClick, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables activating spaces on click in fullscreen mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetFullscreenActivateSpacesOnClick, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the optimeze for games are enabled or not
   in fullscreen mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsFullscreenOptimizeForGames, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables optimizing for games in fullscreen mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetFullscreenOptimizeForGames, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the gamma control are enabled or not
   in fullscreen mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsFullscreenGammaControl, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables gamma control in fullscreen mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetFullscreenGammaControl, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the VM settings is locked for editing.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbLocked :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the settings is
                locked. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsLockedSign, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbLocked
    ) );

/* Return scale view mode used in fullscreen mode.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pnMode :     [out] A pointer to a variable that receives the
                \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetFullscreenScaleViewMode, (
                PRL_HANDLE hVmCfg,
                PRL_SCALE_VIEW_MODE_PTR pnMode
		) );

/* Sets scale view mode for using in fullscreen mode.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nMode :     The scale view mode to set.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetFullscreenScaleViewMode, (
               PRL_HANDLE hVmCfg,
               PRL_SCALE_VIEW_MODE nMode
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section VM Smart Mount operations
///////////////////////////////////////////////////////////////////////////////

/* Determines whether the SmartMount feature is
   enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_IsSmartMountEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the SmartMount feature.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_SetSmartMountEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines whether the SmartMount removable drives is
   enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_IsSmartMountRemovableDrivesEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the SmartMount removable drives.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_SetSmartMountRemovableDrivesEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines whether the SmartMount CD/DVD drives is
   enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_IsSmartMountDVDsEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the SmartMount CD/DVD drives.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_SetSmartMountDVDsEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines whether the SmartMount network shares is
   enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_IsSmartMountNetworkSharesEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the SmartMount network shares.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable
               shared folder. Specify PRL_FALSE to disable them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
		PrlVmCfg_SetSmartMountNetworkSharesEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines whether select boot device should be shown on
   virtual machine startup.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbAllowed :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that select boot device
                will be show. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetAllowSelectBootDevice                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsAllowSelectBootDevice, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbAllowed
		) );


/* Switches on/off select boot device dialog on virtual machine startup.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bAllowed :  Action type. Specify PRL_TRUE to enable
               select boot device dialog. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsAllowSelectBootDevice                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetAllowSelectBootDevice, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bAllowed
		) );

/* \Returns type of the virtual machine BIOS.
   Parameters
   handle :       A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   pnBiosType :   [out] A pointer to a variable that receives the
                  result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				 PrlVmCfg_GetBiosType, (
		PRL_HANDLE hVmCfg,
		PRL_BIOS_TYPE_PTR pnBiosType
		) );

/* Sets BIOS type for the virtual machine.
   Parameters
   handle :      A handle of type PHT_VIRTUAL_MACHINE
                 identifying the virtual machine.
   nBiosType :   Bios type value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				 PrlVmCfg_SetBiosType, (
		PRL_HANDLE hVmCfg,
		PRL_BIOS_TYPE nBiosType
		) );

/* Determines whether the EFI Secure boot feature is enabled in a
   virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the shred
                profile is enabled. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_IsEfiSecureBootEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the EFI Secure boot feature in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable the
               Shared Profile. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetEfiSecureBootEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* \Returns an external boot device system name.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sSysName :           [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnSysNameBufLength : [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_GetExternalBootDevice, (
		PRL_HANDLE hVmCfg,
		PRL_STR sSysName,
		PRL_UINT32_PTR pnSysNameBufLength
		) );

/* Sets an external boot device system name.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewSysName : The name to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetExternalBootDevice, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewSysName
		) );

/* \Returns SMBIOS board identification string.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sBoardId :           [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnSysNameBufLength : [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_GetSmbiosBoardId, (
		PRL_HANDLE hVmCfg,
		PRL_STR sBoardId,
		PRL_UINT32_PTR pnBoardIdBufLength
		) );

/* Sets SMBIOS board identification string
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewBoardId : The board id string to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_SetSmbiosBoardId, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewBoardId
		) );

/* \Returns SMBIOS build version string.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sBoardId :           [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnSysNameBufLength : [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_GetSmbiosBuildVersion, (
		PRL_HANDLE hVmCfg,
		PRL_STR sBuildVer,
		PRL_UINT32_PTR pnBuildVerBufLength
		) );

/* Sets SMBIOS build version string
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewBuildVer : The bios build version string to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_SetSmbiosBuildVersion, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewBuildVer
		) );

/* \Returns SMBIOS serial number string of System Information (Type 1) structure.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sSerialNumber :      [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnSerialNumberBufLength : [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_GetSmbiosSystemSerialNumber, (
		PRL_HANDLE hVmCfg,
		PRL_STR sSerialNumber,
		PRL_UINT32_PTR pnSerialNumberBufLength
		) );

/* Sets SMBIOS serial number string of System Information (Type 1) structure.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewSerialNumber : The bios build version string to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_SetSmbiosSystemSerialNumber, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewSerialNumber
		) );

/* Creates a new handle of type PHT_SHARE and adds it to the
   specified virtual machine list of shares. It is the
   responsibility of the caller to free the handle when it is no
   longer needed.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   phVmShare :  [out] A pointer to a variable that receives the
                new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_CreateShare, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phVmShare
		) );

/* Determines the number of shared folders in a virtual machine.
   A shared folder is a folder in the host OS which is shared
   with a given virtual machine. To obtain its information,
   first determine the number of the available shared folders
   using the PrlVmCfg_GetSharesCount function. Then obtain
   information about an individual folder using the
   PrlVmCfg_GetShare function.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the PrlVm_GetToolsState
   function.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   pnSharesCount :  [out] A pointer to a variable that receives
                    the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSharesCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnSharesCount
		) );

/* Obtains a handle of type PHT_SHARE containing information
   about a shared folder. A shared folder is a folder in the
   host OS which is shared with a given virtual machine. To
   obtain its information, first determine the number of the
   available shared folders using the PrlVmCfg_GetSharesCount
   function. Then iterate through the list using the iteration
   number as the nShareIndex parameter value.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the PrlVm_GetToolsState
   function.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nShareIndex :  An index identifying the shared folder
                  (beginning with 0). To determine the number of
                  shared folders in a virtual machine, use the
                  PrlVmCfg_GetSharesCount function.
   phVmShare :    [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetShare, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nShareIndex,
		PRL_HANDLE_PTR phVmShare
		) );


/* Determines whether the Shared Profile feature is enabled in a
   virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the shred
                profile is enabled. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsSharedProfileEnabled                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsSharedProfileEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the Shared Profile feature in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable the
               Shared Profile. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsSharedProfileEnabled                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetSharedProfileEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the "use desktop in shared profile" feature
   is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUseDesktop, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the "undo-desktop" feature in the shared
   profile.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUseDesktop, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Determines whether "use documents in shared profile" feature
   is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUseDocuments, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set use documents in shared profile enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUseDocuments, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );



/* Determines whether the "used pictures in shared profile"
   feature is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUsePictures, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set use pictures in shared profile enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUsePictures, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );



/* Determines whether the "use music in shared profile" feature
   is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUseMusic, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set use music in shared profile enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUseMusic, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Determines whether the "used downloads in shared profile"
   feature is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
                PrlVmCfg_IsUseDownloads, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set use downloads in shared profile enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
               PrlVmCfg_SetUseDownloads, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Determines whether the "used movies in shared profile"
   feature is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
                PrlVmCfg_IsUseMovies, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set use movies in shared profile enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
               PrlVmCfg_SetUseMovies, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );



/* Determines whether the "Show Windows Applications folder in Dock" feature
   is enabled or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                PrlVmCfg_IsShowWindowsAppInDock, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to set show windows applications folder in Dock enabling sign.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
               PrlVmCfg_SetShowWindowsAppInDock, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the guest applications shared to host or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                PrlVmCfg_IsSharedAppsGuestToHost, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to share the guest applications to host.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
               PrlVmCfg_SetSharedAppsGuestToHost, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the host applications shared to guest or not.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the feature is
                enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                PrlVmCfg_IsSharedAppsHostToGuest, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to share the host applications to guest.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :   Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
               PrlVmCfg_SetSharedAppsHostToGuest, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the "Show Guest Notifications" feature
   is enabled or not.
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
                PrlVmCfg_IsShowGuestNotifications, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to enable or disable the "Show Guest Notifications" feature.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION
                identifying the virtual machine configuration.
   bEnabled :      [in] Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetShowGuestNotifications, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the "Bounce Dock Icon When App Flashes"
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
                PrlVmCfg_IsBounceDockIconWhenAppFlashes, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Lets to enable or disable the "Bounce Dock Icon When App Flashes"
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
               PrlVmCfg_SetBounceDockIconWhenAppFlashes, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether the automatic capture and release of the
   mouse pointer is enabled or not. When this feature is
   enabled, the mouse input is automatically redirected from the
   host OS to the virtual machine and vise versa as soon as the
   mouse pointer is positioned over the host OS or the virtual
   machine desktop. This feature requires Parallels Tools
   installed in a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
                PRL_TRUE indicates that the feature is enabled.
                PRL_FALSE indicates that it is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsAutoCaptureReleaseMouse, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the automatic capture and release of the
   mouse pointer in a virtual machine. When this feature is
   enabled, the mouse input is automatically redirected from the
   host OS to the virtual machine and vise versa as soon as the
   mouse pointer is positioned over the host OS or the virtual
   machine desktop. This feature requires Parallels Tools
   installed in a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable the
               feature or PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetAutoCaptureReleaseMouse, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines disable or enable smart mouse.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSmartMouseEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables smart mouse.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSmartMouseEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable sticky mouse.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsStickyMouseEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables sticky mouse.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetStickyMouseEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable smooth scrolling.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_IsSmoothScrollingEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables smooth scrolling.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_SetSmoothScrollingEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Gets optimize modifiers mode.
   Parameters
   hVm :    A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnMode : [out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetOptimizeModifiersMode, (
		PRL_HANDLE hVm,
		PRL_OPTIMIZE_MODIFIERS_MODE_PTR pnMode
		) );

/* Sets optimize modifiers mode.
   Parameters
   hVm :   A handle of type PHT_VM_CONFIGURATION
           identifying the virtual machine configuration.
   nMode : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetOptimizeModifiersMode, (
		PRL_HANDLE hVm,
		PRL_OPTIMIZE_MODIFIERS_MODE nMode
		) );

/* Determines whether the clipboard sharing feature is enabled
   or disabled in a virtual machine. When clipboard sharing is
   enabled, you can copy and paste text and files from the host
   to a virtual machine or vise versa, or from one virtual
   machine to another. This feature requires Parallels Tools
   installed in a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
                PRL_TRUE indicates that the feature is enabled.
                PRL_FALSE indicates that it is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsShareClipboard, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the clipboard sharing feature. When
   clipboard sharing is enabled, you can copy and paste text and
   files from the host to a virtual machine or vise versa, or
   from one virtual machine to another. This feature requires
   Parallels Tools installed in a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Set to PRL_TRUE to enabled clipboard
               sharing. Set to PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetShareClipboard, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* <unfinished>

   Determines whether the time synchronization feature is
   enabled in a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
                PRL_TRUE indicates that the time synchronization
                is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetTimeSynchronizationEnabled                         */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsTimeSynchronizationEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* <unfinished>

   Enables or disables the time synchronization feature in a
   virtual machine. You can synchronize the time in a virtual
   machine with the time in the host OS. To do so, the time
   synchronization feature must be enabled using the
   PrlVmCfg_SetTimeSynchronizationEnabled function. The time
   will be synchronized at predefined time intervals. To set the
   time interval, use the PrlVmCfg_SetSmartGuardInterval
   function. This feature requires Parallels Tools installed in
   a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetTimeSyncSmartModeEnabled                          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetTimeSynchronizationEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/*
	Determines whether the timezone should be synced during time sync operation
	Parameters
	hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying
			 the virtual machine configuration.
	pbDisabled : A pointer to a variable that receives the result.
				PRL_TRUE indicates that the timezone should not be synced
				PRL_FALSE indicates otherwise
	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer to
	buffer was passed.

	PRL_ERR_SUCCESS - function completed successfully.
	See Also
	PrlVmCfg_SetTimeSynchronizationEnabled                         */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVmCfg_IsSyncTimezoneDisabled, (
				PRL_HANDLE hVmCfg,
				PRL_BOOL_PTR pbDisabled
		) );

/*
	Enables or disables timezone synchronization.
	Parameters
	hVmCfg :	A handle of type PHT_VM_CONFIGURATION identifying
				the virtual machine configuration.
	bDisabled : Setting boolean value.
	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle was passed.

	PRL_ERR_SUCCESS - function completed successfully.
	See Also
	PrlVmCfg_SetTimeSyncSmartModeEnabled                          */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
			   PrlVmCfg_SetSyncTimezoneDisabled, (
			   PRL_HANDLE hVmCfg,
			   PRL_BOOL bDisabled
		) );

/* Determines whether the smart time synchronization is enabled
   in a virtual machine. For more information, see PrlVmCfg_SetTimeSyncSmartModeEnabled.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receive the result.
                PRL_TRUE indicates that the feature is enabled.
                PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsTimeSyncSmartModeEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the smart time-synchronization mode in a
   virtual machine. You can automatically synchronize the time
   in a virtual machine with the time in the OS by using the PrlVmCfg_SetTimeSynchronizationEnabled
   function. That functionality will keep the time in the
   virtual machine in a perfect synch with the time in the host
   OS. You can also set different time zones in the host and the
   guest OS and still synchronize the time. To do so, use the PrlVmCfg_SetTimeSyncSmartModeEnabled
   function. This feature requires Parallels Tools installed in
   a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetTimeSynchronizationEnabled

   PrlVmCfg_SetTimeSyncInterval                                                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetTimeSyncSmartModeEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* <unfinished>

   Obtains the time synchronization interval between the host
   and a guest OS. See PrlVmCfg_SetTimeSynchronizationEnabled
   for more information.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   pnTimeSyncInterval :  [out] A pointer to a variable that
                         receive the time synchronization value,
                         in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetTimeSyncInterval                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_GetTimeSyncInterval, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnTimeSyncInterval
		) );

/* <unfinished>

   Allows to set the time interval at which the time in the
   virtual machine will be synchronized with the time in the
   host OS. Before this function can be used, the time
   synchronization feature must be enabled in the virtual
   machine using the PrlVmCfg_SetTimeSynchronizationEnabled
   function.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine
                        configuration.
   nTimeSyncInterval :  Setting interval in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetTimeSyncInterval                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetTimeSyncInterval, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nTimeSyncInterval
		) );


/* Creates a new handle of type PHT_SCREEN_RESOLUTION and adds
   it to the specified virtual machine resolution list. Use this
   function when you want to add an additional screen resolution
   to the virtual machine. Once you obtain the handle, use its
   functions to set the screen resolution parameters, such as
   width and height. It is the responsibility of the caller to
   free the handle when it is no longer needed.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   phVmScrRes :  [out] A pointer to a variable that receives the
                 new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsScrResEnabled                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_CreateScrRes, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phVmScrRes
		) );

/* Determines the total number of screen resolutions available
   in a virtual machine.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine
                    configuration.
   pnScrResCount :  [out] A pointer to a variable that receives
                    the screen resolution count.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetScrRes                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetScrResCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnScrResCount
		) );

/* Obtains a handle of type PHT_SCREEN_RESOLUTION identifying
   the specified virtual machine screen resolution. Once you
   obtain the handle, you can use its functions to modify the
   screen resolution settings.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   nScrResIndex :  A numeric index identifying the screen
                   resolution (beginning with 0). To determine
                   the number of the available resolutions, use
                   PrlVmCfg_GetScrResCount.
   phVmScrRes :    [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetScrResCount                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetScrRes, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nScrResIndex,
		PRL_HANDLE_PTR phVmScrRes
		) );


/* Creates a new handle of type PHT_BOOT_DEVICE and adds it to
   the specified virtual machine boot device list. It is the
   responsibility of the caller to free the handle when it is no
   longer needed.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   phVmBootDev :  [out] A pointer to a variable that receives the
                  new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_CreateBootDev, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phVmBootDev
		) );

/* Determines the number of devices in the virtual machine boot
   device priority list.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   pnBootDevCount :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetBootDevCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnBootDevCount
		) );

/* Obtains a handle of type PHT_BOOT_DEVICE containing
   information about a specified device from the virtual machine
   boot device priority list. It is the responsibility of the
   called to free the handle when it is no longer needed.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   nBootDevIndex :  An index identifying the device (beginning
                    with 0). To determine the number of the
                    devices in the boot device list, use the
                    PrlVmCfg_GetBootDevCount function.
   phVmBootDev :    [out] A pointer to a variable that receives
                    the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetBootDev, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nBootDevIndex,
		PRL_HANDLE_PTR phVmBootDev
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Virtual machine configuration
///////////////////////////////////////////////////////////////////////////////

/* \Returns the name of the specified virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sVmName :            [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnVmNameBufLength :  [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetName, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmName,
		PRL_UINT32_PTR pnVmNameBufLength
		) );

/* Sets the specified virtual machine name.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewVmName :  The name to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetName, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmName
		) );

/* Obtains the hostname of the specified virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine
                        configuration.
   sVmName :            [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnVmNameBufLength :  [in] The size of the output buffer (in
                        bytes). Set the buffer pointer to null
                        and this parameter's value to zero to
                        receive the required size. [out] The
                        required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The pnVmNameBufLength parameter will contain
   the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetHostname, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmHostname,
		PRL_UINT32_PTR pnVmHostnameBufLength
		) );

/* Sets the specified virtual machine hostname.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewVmName :  The hostname to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetHostname, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmHostname
		) );

/* \Returns the UUID (universally unique ID) of the specified
   virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sVmUuid :            [out] A pointer to a buffer that receives
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
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetUuid, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmUuid,
		PRL_UINT32_PTR pnVmUuidBufLength
		) );

/* Sets the virtual machine UUID (universally unique ID). A UUID
   is assigned to a virtual machine automatically when it is
   created. Before using this function, make sure that you
   understand what UUID is, and that you have a good reason for
   changing it.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewVmUuid :  The UUID to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetUuid, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmUuid
		) );

/* \Returns the UUID (universally unique ID) of the parent
   virtual machine which was used to create current linked cloned
   virtual machine (if last one is linked clone of some virtual machine -
   this value will be empty otherwise).
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sVmUuid :            [out] A pointer to a buffer that receives
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
				 PrlVmCfg_GetLinkedVmUuid, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmUuid,
		PRL_UINT32_PTR pnVmUuidBufLength
		) );

/* \Returns the type of the operating system that the specified
   virtual machine is running. The OS types are defined in the
   PrlOses.h file as macros. Look for the macros that are
   prefixed with PVS_GUEST_TYPE_ (e.g. PVS_GUEST_TYPE_MACOS).
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   pnVmOsType :  [out] A pointer to a variable that receives the
                 OS type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - VM - the OS information is not present in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetOsType, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmOsType
		) );

/* \Returns the version of the operating system that the
   specified virtual machine is running. The OS versions are
   defined in the PrlOses.h file as macros. Look for the macros
   that are prefixed with PVS_GUEST_VER_ (e.g.
   PVS_GUEST_VER_MACOS_LEOPARD).
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   pnVmOsVersion :  [out] A pointer to a variable that receives
                    the OS version.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - VM - the OS information is not present in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetOsVersion, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmOsVersion
		) );

/* Sets the virtual machine guest OS version.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   nVmOsVersion :  The guest OS version to set. The OS versions
                   are defined in the PrlOses.h file as macros.
                   Look for the macros that are prefixed with
                   PVS_GUEST_VER_ (e.g.
                   PVS_GUEST_VER_MACOS_LEOPARD).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetOsVersion, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmOsVersion
		) );

/* \Returns the virtual machine memory (RAM) size, in megabytes.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmRamSize :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetRamSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmRamSize
		) );

/* Sets the virtual machine memory (RAM) size.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   nVmRamSize :  The RAM size to set, in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or zero RAM size was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetRamSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmRamSize
		) );

/* \Determines whether the memory (RAM) auto assignment is enabled in
   the virtual machine.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlVmCfg_IsRamAutoSizeEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Sets the virtual machine memory (RAM) auto assignment mode (enabled or
   disabled).
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   nVmRamSize :  The RAM auto assignment mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or zero RAM size was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlVmCfg_SetRamAutoSizeEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines whether the memory (RAM) hotplug is available in
   the virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pbVmRamHotplugEnabled :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_IsRamHotplugEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmRamHotplugEnabled
		) );

/* Sets the virtual machine memory (RAM) hotplug mode (enabled or
   disabled).
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   bVmRamHotplugEnabled :  The RAM hotplug mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetRamHotplugEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmRamHotplugEnabled
		) );

/* \Returns the video memory size of the specified virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnVmVideoRamSize :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the video memory size information is
   missing in the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetVideoRamSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmVideoRamSize
		) );

/* Sets the virtual machine video memory size.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   nVmVideoRamSize :  The new memory size, in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetVideoRamSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmVideoRamSize
		) );

/* \Returns the video adapter type of the specified virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnVideoAdapterType :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the video memory size information is
   missing in the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_GetVideoAdapterType, (
		PRL_HANDLE hVmCfg,
		PRL_VIDEO_ADAPTER_TYPE_PTR pnVideoAdapterType
		) );

/* Sets the virtual machine video memory size.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   nVideoAdapterType :  The video adapter type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetVideoAdapterType, (
		PRL_HANDLE hVmCfg,
		PRL_VIDEO_ADAPTER_TYPE nVideoAdapterType
		) );

/* \Returns the aperture only video ram capability of the specified virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnVmVideoRamSize :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the aperture only video ram information is
   missing in the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				 PrlVmCfg_IsApertureOnlyCapable, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbApertureOnlyCapable
		) );


/* \Returns the maximal size of the host's memory (RAM) consumption
   by the virtual machine, in megabytes.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnHostMemQuotaMax :  [out] A pointer to a variable that receives
                        the \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_GetHostMemQuotaMax, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnHostMemQuotaMax
		) );

/* Sets the maximal size of the host's memory (RAM) consumption
   by the virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   nHostMemQuotaMax :   The maximal RAM size to set, in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetHostMemQuotaMax, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nHostMemQuotaMax
		) );

/* \Returns the relative priority of the virtual machine in host's
   memory (RAM) distribution mechanism.
   Parameters
   hVmCfg :                  A handle of type PHT_VM_CONFIGURATION
                             identifying the virtual machine
                             configuration.
   pnHostMemQuotaPriority :  [out] A pointer to a variable that
                             receives the \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_GetHostMemQuotaPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnHostMemQuotaPriority
		) );

/* Sets the relative priority of the virtual machine in host's
   memory (RAM) distribution mechanism.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
                           configuration.
   nHostMemQuotaPriority : The priority to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetHostMemQuotaPriority, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nHostMemQuotaPriority
		) );

/* Determines whether the automatic calculation of the host's memory
   (RAM) consumption parameters enabled for the virtual machine.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine configuration.
   pbHostMemAutoQuota :  [out] A pointer to a variable that receives
                         the \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_IsHostMemAutoQuota, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbHostMemAutoQuota
		) );

/* Enables or disables the automatic calculation of the host's memory
   (RAM) consumption parameters for the virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   bHostMemAutoQuota :  The value to set. Specify PRL_TRUE to enable
                        the automatic calculation or PRL_FALSE to
                        disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetHostMemAutoQuota, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bHostMemAutoQuota
		) );


/* Returns the maximum memory limit which can be locked by balloon
   in the virtual machine, in percent of guest RAM.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnMaxBalloonSize :  [out] A pointer to a variable that receives
                        the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the memory information is not available in
   the virtual machine configuration.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_GetMaxBalloonSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnMaxBalloonSize
		) );

/* Sets the maximum memory limit which can be locked by balloon
   in the virtual machine, in percent of guest RAM.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   nMaxBalloonSize :   The maximum balloon size to set, in percent.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
			PrlVmCfg_SetMaxBalloonSize, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nMaxBalloonSize
		) );

/* Determines the number of CPUs in the virtual machine.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   pnVmCpuCount :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetCpuCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmCpuCount
		) );

/* Sets the number of CPUs for the specified virtual machine
   (the CPUs should be present in the machine).
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   nVmCpuCount :  The number to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetCpuCount, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmCpuCount
		) );

/* \Determines whether the CPU count auto assignment is enabled in
   the virtual machine.
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlVmCfg_IsCpuAutoCountEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Sets the virtual machine CPU count auto assignment mode (enabled or
   disabled).
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   nVmRamSize :  The RAM auto assignment mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or zero RAM size was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_8,
				 PrlVmCfg_SetCpuAutoCountEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines the specified virtual machine CPU type (x86 or ARM).
   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   pnVmCpuType :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_GetCpuType, (
		PRL_HANDLE hVmCfg,
		PRL_CPU_TYPE_PTR pnVmCpuType
		) );

/* Sets CPU type (x86 or ARM) for the specified virtual
   machine.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   nVmCpuType :  The CPU mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_9,
				 PrlVmCfg_SetCpuType, (
		PRL_HANDLE hVmCfg,
		PRL_CPU_TYPE nVmCpuType
		) );

/* Returns virtual hardware chipset type number.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
					    identifying the virtual machine configuration.
   pnVal :              [out] A pointer to a variable that receives the result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				 PrlVmCfg_GetChipsetType, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVal
		) );

/* Sets the virtual hardware chipset type number.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   nVal :               Virtual hardware chipset type number.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				PrlVmCfg_SetChipsetType, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVal
		) );

/* Returns virtual hardware chipset version number.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
						identifying the virtual machine configuration.
   pnVal :              [out] A pointer to a variable that receives the result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				 PrlVmCfg_GetChipsetVersion, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVal
		) );

/* Sets the virtual hardware chipset version number.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
						identifying the virtual machine configuration.
   nVal :               Virtual hardware chipset version number.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
 */
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
				PrlVmCfg_SetChipsetVersion, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVal
		) );

/* Determines the virtual machine CPU acceleration level.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnVmCpuAccelLevel :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetCpuAccelLevel, (
		PRL_HANDLE hVmCfg,
		PRL_VM_ACCELERATION_LEVEL_PTR pnVmCpuAccelLevel
		) );

/* Sets CPU acceleration level for the specified virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   nVmCpuAccelLevel :  The CPU acceleration level to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetCpuAccelLevel, (
		PRL_HANDLE hVmCfg,
		PRL_VM_ACCELERATION_LEVEL nVmCpuAccelLevel
		) );

/* Determines whether the x86 virtualization (such as Vt-x) is
   available in the virtual machine CPU.
   Parameters
   handle :             A handle of type PHT_VIRTUAL_MACHINE
                        identifying the virtual machine.
   pbVmCpuVtxEnabled :  A pointer to a variable that receives the
                        \result. PRL_TRUE indicates that the x86
                        virtualization is available. PRL_FALSE
                        indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_NO_DATA - virtual machine configuration does not have
   necessary data.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsCpuVtxEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmCpuVtxEnabled
		) );

/* Determines whether the CPU hotplug is available in the virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pbVmCpuHotplugEnabled :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine object does not contain
   the necessary data.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_IsCpuHotplugEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmCpuHotplugEnabled
		) );

/* Sets CPU hotplug mode (enabled or disabled) for the specified virtual
   machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   bVmCpuHotplugEnabled :  The CPU hotplug mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetCpuHotplugEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmCpuHotplugEnabled
		) );

/* Gets 3D graphical acceleration technology mode
   for the specified virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VIRTUAL_MACHINE
                        identifying the virtual machine.
   pn3DAccelerationMode : A pointer to a variable that receives the
                        \result. See PRL_VIDEO_3D_ACCELERATION enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_Get3DAccelerationMode, (
		PRL_HANDLE hVmCfg,
		PRL_VIDEO_3D_ACCELERATION_PTR pn3DAccelerationMode
		) );

/* Sets 3D graphical acceleration technology mode
   for the specified virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VIRTUAL_MACHINE
                        identifying the virtual machine.
   n3DAccelerationMode : Setting value.
                        See PRL_VIDEO_3D_ACCELERATION enum.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_Set3DAccelerationMode, (
		PRL_HANDLE hVmCfg,
		PRL_VIDEO_3D_ACCELERATION n3DAccelerationMode
		) );

/* Determines disable or enable vertical synchronization
   video mode for the specified virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VIRTUAL_MACHINE
               identifying the virtual machine.
   pbEnabled : A pointer to a variable that receives the
               result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_IsVerticalSynchronizationEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Disables or enables vertical synchronization video mode
   for the specified virtual machine.
   Parameters
   hVmCfg :   A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   bEnabled : Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetVerticalSynchronizationEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines disable or enable high resolution
   video mode for the specified virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VIRTUAL_MACHINE
               identifying the virtual machine.
   pbEnabled : A pointer to a variable that receives the
               result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_IsHighResolutionEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Disables or enables high resolution video mode
   for the specified virtual machine.
   Parameters
   hVmCfg :   A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   bEnabled : Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetHighResolutionEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines disable or enable high resolution
   video mode for the specified virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VIRTUAL_MACHINE
               identifying the virtual machine.
   pbEnabled : A pointer to a variable that receives the
               result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_IsHighResolutionInGuestEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Disables or enables high resolution video mode
   for the specified virtual machine.
   Parameters
   hVmCfg :   A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   bEnabled : Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetHighResolutionInGuestEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines disable or enable native scaling
   video mode for the specified virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VIRTUAL_MACHINE
               identifying the virtual machine.
   pbEnabled : A pointer to a variable that receives the
               result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_IsNativeScalingInGuestEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Disables or enables native scaling video mode
   for the specified virtual machine.
   Parameters
   hVmCfg :   A handle of type PHT_VIRTUAL_MACHINE
              identifying the virtual machine.
   bEnabled : Setting value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetNativeScalingInGuestEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Determines hypervisor type.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pnType : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_GetHypervisorType, (
		PRL_HANDLE hVm,
		PRL_HYPERVISOR_TYPE_PTR pnType
		) );

/* Sets hypervisor type.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_SetHypervisorType, (
		PRL_HANDLE hVm,
		PRL_HYPERVISOR_TYPE nType
		) );

/* Determines disable or enable adaptive hypervisor.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsAdaptiveHypervisorEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables adaptive hypervisor.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetAdaptiveHypervisorEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable Windows logo.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSwitchOffWindowsLogoEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables Windows logo.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSwitchOffWindowsLogoEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable longer battery life.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsLongerBatteryLifeEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables longer battery life.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetLongerBatteryLifeEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable battery status.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsBatteryStatusEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables battery status.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetBatteryStatusEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable nested virtualization.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsNestedVirtualizationEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables nested virtualization.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetNestedVirtualizationEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable PMU virtualization.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsPMUVirtualizationEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables PMU virtualization.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetPMUVirtualizationEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable lock guest on suspend.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsLockGuestOnSuspendEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables shared camera lock guest on suspend.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetLockGuestOnSuspendEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable isolated VM.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsIsolatedVmEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables shared camera isolated VM.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetIsolatedVmEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Sets TPM type for the virtual machine.
   Parameters
   handle :      A handle of type PHT_VIRTUAL_MACHINE
                 identifying the virtual machine.
   nTpmType :   TPM type value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_SetTpmType, (
		PRL_HANDLE hVm,
		PRL_TPM_TYPE nTpmType
		) );

/* \Returns type of the TPM chip emulated by virtual machine.
   Parameters
   handle :       A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   pnTpmType :   [out] A pointer to a variable that receives the
                  result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid PHT_VIRTUAL_MACHINE handle or
   NULL pointer to the output buffer was specified.

   PRL_ERR_SUCCESS - operation completed successfully             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetTpmType, (
                PRL_HANDLE hVmCfg,
				PRL_TPM_TYPE_PTR pnTpmType
		) );

/* \Returns the UUID of the machine hosting the specified virtual
   machine.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine configuration.
   sServerUuid :            [out] A pointer to a buffer that
                            receives the result (a UTF\-8
                            encoded, null\-terminated string).
   pnServerUuidBufLength :  [in] The size of the output buffer
                            (in bytes). Set the buffer pointer to
                            null and this parameter's value to
                            zero to receive the required size.
                            [out] The required output buffer
                            size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetServerUuid, (
		PRL_HANDLE hVmCfg,
		PRL_STR sServerUuid,
		PRL_UINT32_PTR pnServerUuidBufLength
		) );

/* \Returns the hostname of the machine hosting the specified
   virtual machine.
   Parameters
   hVmCfg :                    A handle of type PHT_VM_CONFIGURATION
                               identifying the virtual machine
							   configuration.
   unnamsServerHosted_param :  [out] A pointer to a buffer that
                               receives the result (a UTF\-8
                               encoded, null\-terminated string).
   pnServerHostBufLength :     [in] The size of the output buffer
                               (in bytes). Set the buffer pointer
                               to null and this parameter's value
                               to zero to receive the required
                               size. [out] The required output
                               buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetServerHost, (
		PRL_HANDLE hVmCfg,
		PRL_STR sServerHost,
		PRL_UINT32_PTR pnServerHostBufLength
		) );

/* \Returns the virtual machine home directory name and path.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine configuration.
   sHomePath :            [out] A pointer to a buffer that
                          receives the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnHomePathBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetHomePath, (
		PRL_HANDLE hVmCfg,
		PRL_STR sHomePath,
		PRL_UINT32_PTR pnHomePathBufLength
		) );

/* \Returns the virtual machine files location type.
   Please note that this parameter is runtime and read only.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine configuration.
   pnVmLocation :         [out] A pointer to a buffer that
                          receives the result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetLocation, (
		PRL_HANDLE hVmCfg,
		PRL_VM_LOCATION_PTR pnVmLocation
		) );

/* \Returns the name of the icon file used by the specified
   virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   sVmIcon :            [out] A pointer to a buffer that receives
                        the result (a UTF\-8 encoded,
                        null\-terminated string).
   pnVmIconBufLength :  [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetIcon, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmIcon,
		PRL_UINT32_PTR pnVmIconBufLength
		) );

/* Sets the virtual machine icon.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sNewVmIcon :  The new icon file name.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetIcon, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmIcon
		) );

/* \Returns the specified virtual machine asset id.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   sAssetId :    [out] A pointer to a buffer that
                 receives the result (a UTF\-8
                 encoded, null\-terminated string).
   pnBufLength : [in] The size of the output buffer (in bytes).
                 Set the buffer pointer to null and this parameter's
                 value to zero to receive the required size.
                 [out] The required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_GetAssetId, (
		PRL_HANDLE hVmCfg,
		PRL_STR sAssetId,
		PRL_UINT32_PTR pnBufLength
		) );

/* Sets the virtual machine asset id.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine connfiguration.
   sNewAssetId : The virtual machine asset id to set.
                 The value must be a UTF\-8 encoded,
                 null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetAssetId, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewAssetId
		) );

/* \Returns the specified virtual machine description.
   Parameters
   hVmCfg :                    A handle of type PHT_VM_CONFIGURATION
                               identifying the virtual machine
							   configuration.
   sVmDescription :            [out] A pointer to a buffer that
                               receives the result (a UTF\-8
                               encoded, null\-terminated string).
   pnVmDescriptionBufLength :  [in] The size of the output buffer
                               (in bytes). Set the buffer pointer
                               to null and this parameter's value
                               to zero to receive the required
                               size. [out] The required output
                               buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDescription, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmDescription,
		PRL_UINT32_PTR pnVmDescriptionBufLength
		) );

/* Sets the virtual machine description.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine
						configuration.
   sNewVmDescription :  The virtual machine description to set.
                        The value must be a UTF\-8 encoded,
                        null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetDescription, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmDescription
		) );

/* Determines if the specified virtual machine object contains a
   virtual machine or a template configuration information. If
   the object contains a template configuration, it can be used
   to create new virtual machines from it. See PrlVm_Clone for
   the information on how to create virtual machines from
   templates.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   pbVmIsTemplate :  [out] A pointer to a variable that receives
                     the result. PRL_TRUE indicates that the
                     machine is a template. PBL_FALE indicates
                     otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsTemplate, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmIsTemplate
		) );

/* Allows to modify a regular virtual machine to become a
   template, and vise versa. A template is very similar to a
   regular virtual machine with the major exception being it
   cannot be started. Templates are used to create new virtual
   machines as exact copies of them. To create a virtual machine
   from a template, use the PrlVm_Clone function specifying the
   template as the source.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   bVmIsTemplate :  The value to set. Specify PRL_TRUE to make
                    the virtual machine a template. Specify
                    PRL_FALSE to switch a template to a regular
                    virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetTemplateSign, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmIsTemplate
		) );

/* \Returns the virtual machine custom property information. If
   you have some custom data which relates to a virtual machine
   in some way, you can save it in the virtual machine
   configuration for future retrieval. This can be any data that
   your client application requires. The data is stored in CDATA
   format.
   Parameters
   hVmCfg :                       A handle of type PHT_VM_CONFIGURATION
                                  identifying the virtual machine
								  configuration.
   sVmCustomProperty :            [out] A pointer to a buffer
                                  that receives the result (a
                                  UTF\-8 encoded, null\-terminated
                                  string). The custom property
                                  information is stored in CDATA
                                  format.
   pnVmCustomPropertyBufLength :  [in] The size of the output
                                  buffer (in bytes). Set the
                                  buffer pointer to null and this
                                  parameter's value to zero to
                                  receive the required size.
                                  [out] The required output
                                  buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is too
   small. The parameter that is used to specify the size will
   contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetCustomProperty                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetCustomProperty, (
				PRL_HANDLE hVmCfg,
				PRL_STR sVmCustomProperty,
				PRL_UINT32_PTR pnVmCustomPropertyBufLength
				) );

/* Sets the virtual machine custom property information. If you
   have some custom data, which relates to a virtual machine in
   some way, you can save it in the virtual machine
   configuration for future retrieval. This can be any data that
   your client application requires. The data is stored in CDATA
   format.
   Parameters
   hVmCfg :                A handle of type PHT_VM_CONFIGURATION
                           identifying the virtual machine
						   configuration.
   sNewVmCustomProperty :  A pointer to a buffer containing the
                           custom information. The data must be
                           in CDATA format.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetCustomProperty, (
				PRL_HANDLE hVmCfg,
				PRL_CONST_STR sNewVmCustomProperty
				) );

/* Determines if the specified virtual machine is set to start
   automatically on Parallels Service startup.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   pnVmAutoStart :  [out] A pointer to a variable that receives
                    the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetAutoStart, (
		PRL_HANDLE hVmCfg,
		PRL_VM_AUTOSTART_OPTION_PTR pnVmAutoStart
		) );

/* Allows to sets the automatic startup option for the specified
   virtual machine.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   nVmAutoStart :  The automatic startup option to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetAutoStart, (
		PRL_HANDLE hVmCfg,
		PRL_VM_AUTOSTART_OPTION nVmAutoStart
		) );

/* \Returns the time delay used during the virtual machine
   automatic startup.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying
            the virtual machine configuration.
   pnVmAutoStartDelay :  [out] A pointer to a variable that
                         receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetAutoStartDelay, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32_PTR pnVmAutoStartDelay
		) );

/* Sets the time delay that will be used during the virtual
   machine automatic startup.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   nVmAutoStartDelay :  Time delay to set, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetAutoStartDelay, (
		PRL_HANDLE hVmCfg,
		PRL_UINT32 nVmAutoStartDelay
		) );

/* \Returns the automatic startup login mode for the specified
   virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnVmStartLoginMode :  [out] A pointer to a variable that
                         receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetStartLoginMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_START_LOGIN_MODE_PTR pnVmStartLoginMode
		) );

/* Allows to set the automatic startup login mode for the
   specified virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
         identifying the virtual machine configuration.
   nVmStartLoginMode :  Automatic startup login mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetStartLoginMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_START_LOGIN_MODE nVmStartLoginMode
		) );

/* \Returns the user name used during the specified virtual
   machine automatic startup.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
                                the virtual machine.
   sStartUserLogin :            [out] A pointer to a buffer that
                                receives the result (a UTF\-8
                                encoded, null\-terminated
                                string).
   pnStartUserLoginBufLength :  [in] The size of the output
                                buffer (in bytes). Set the buffer
                                pointer to null and this
                                parameter's value to zero to
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
				 PrlVmCfg_GetStartUserLogin, (
		PRL_HANDLE hVmCfg,
		PRL_STR sStartUserLogin,
		PRL_UINT32_PTR pnStartUserLoginBufLength
		) );

/* Allows to set the automatic startup user login and password
   for the specified virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   sStartUserLogin :  User login. Must be a a UTF\-8 encoded,
                      null\-terminated string.
   sPassword :        User password. Must be a a UTF\-8 encoded,
                      null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetStartUserCreds, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sStartUserLogin,
		PRL_CONST_STR sPassword
		) );

/* Determines the mode of the automatic shutdown for the
   specified virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnVmAutoStop :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetAutoStop, (
		PRL_HANDLE hVmCfg,
		PRL_VM_AUTOSTOP_OPTION_PTR pnVmAutoStop
		) );

/* Allows to set the automatic shutdown mode for the specified
   virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   nVmAutoStop :  Automatic shutdown mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetAutoStop, (
		PRL_HANDLE hVmCfg,
		PRL_VM_AUTOSTOP_OPTION nVmAutoStop
		) );

/* Determines the action on Parallels Application window close for the
   specified virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnActionOnWindowCloase :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetActionOnWindowClose, (
		PRL_HANDLE hVmCfg,
		PRL_VM_ACTION_ON_WINDOW_CLOSE_PTR pnActionOnWindowClose
		) );

/* Allows to set the action on Parallels Application window close for the specified
   virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   nActionOnWindowClose :  Action on Parallels window close to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetActionOnWindowClose, (
		PRL_HANDLE hVmCfg,
		PRL_VM_ACTION_ON_WINDOW_CLOSE nActionOnWindowClose
		) );

/* Gets action on stop mode.
   Parameters
   hVm :    A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   pnMode : [out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetActionOnStopMode, (
		PRL_HANDLE hVm,
		PRL_VM_ACTION_ON_STOP_PTR pnMode
		) );

/* Sets action on stop mode.
   Parameters
   hVm :   A handle of type PHT_VM_CONFIGURATION
           identifying the virtual machine configuration.
   nMode : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetActionOnStopMode, (
		PRL_HANDLE hVm,
		PRL_VM_ACTION_ON_STOP nMode
		) );

/* \Returns the current window mode the specified virtual
   machine is in.
   Parameters
   hVm :             A handle of type PHT_VIRTUAL_MACHINE
                     identifying the virtual machine.
   pnVmWindowMode :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetWindowMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_WINDOW_MODE_PTR pnVmWindowMode
		) );

/* Sets the virtual machine window mode.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   nVmWindowMode :  The window mode to set. See the PRL_VM_WINDOW_MODE
                    enumeration for the list of modes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                  */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetWindowMode, (
		PRL_HANDLE hVmCfg,
		PRL_VM_WINDOW_MODE nVmWindowMode
		) );

/* Determines disable or enable start in detached window.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsStartInDetachedWindowEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables start in detached window.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetStartInDetachedWindowEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );


/* \Returns the date and time when the specified virtual machine
   was last modified. Returned time is a local time (i.e. the time value is already converted to local time zone).
   Parameters
   hVmCfg :                         A handle of type PHT_VM_CONFIGURATION
                                    identifying the virtual machine
									configuration.
   sVmLastModifiedDate :            [out] A pointer to a buffer
                                    that receives the result (a
                                    UTF\-8 encoded,
                                    null\-terminated string). The
                                    date is returned using the "yyyy\-mm\-dd
                                    hh\:mi\:ss" format.
   pnVmLastModifiedDateBufLength :  [in] The size of the output
                                    buffer (in bytes). Set the
                                    buffer pointer to null and
                                    this parameter's value to
                                    zero to receive the required
                                    size. [out] The required
                                    \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetLastModifiedDate, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmLastModifiedDate,
		PRL_UINT32_PTR pnVmLastModifiedDateBufLength
		) );

/* \Returns the name of the user who last modified the specified
   virtual machine.
   Parameters
   hVmCfg :                         A handle of type PHT_VM_CONFIGURATION
                                    identifying the virtual machine
									configuration.
   sVmLastModifierName :            [out] A pointer to a buffer
                                    that receives the result (a
                                    UTF\-8 encoded,
                                    null\-terminated string).
   pnVmLastModifierNameBufLength :  [in] The size of the output
                                    buffer (in bytes). Set the
                                    buffer pointer to null and
                                    this parameter's value to
                                    zero to receive the required
                                    size. [out] The required
                                    \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetLastModifierName, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmLastModifierName,
		PRL_UINT32_PTR pnVmLastModifierNameBufLength
		) );

/* \Returns the date and time when uptime counter calculation was started for the specified virtual machine.
   Returned time is a local time (i.e. the time value is already converted to local time zone).
   Parameters
   hVmCfg :                         A handle of type PHT_VM_CONFIGURATION
                                    identifying the virtual machine
									configuration.
   sVmUptimeStartDate :             [out] A pointer to a buffer
                                    that receives the result (a
                                    UTF\-8 encoded,
                                    null\-terminated string). The
                                    date is returned using the "yyyy\-mm\-dd
                                    hh\:mi\:ss" format.
   pnVmUptimeStartDateBufLength :   [in] The size of the output
                                    buffer (in bytes). Set the
                                    buffer pointer to null and
                                    this parameter's value to
                                    zero to receive the required
                                    size. [out] The required
                                    \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See also PrlVmCfg_GetUptime                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetUptimeStartDate, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmUptimeStartDate,
		PRL_UINT32_PTR pnVmUptimeStartDateBufLength
		) );

/* \Returns the virtual machine uptime in seconds since some datetime (see PrlVmCfg_GetUptimeStartDate).
   Parameters
   hVmCfg :                         A handle of type PHT_VM_CONFIGURATION
                                    identifying the virtual machine
									configuration.
   pnVmUptime :                     [out] The buffer for storing result.

   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See also PrlVmCfg_GetUptimeStartDate PrlStat_GetOsUptime     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetUptime, (
		PRL_HANDLE hVmCfg,
		PRL_UINT64_PTR pnVmUptime
		) );

/* Obtains a handle of type PHT_ACCESS_RIGHTS.
   Parameters
   hVmCfg :   A handle of type PHT_VM_CONFIGURATION
              identifying the virtual machine configuration.
   phVmAcl :  [out] A pointer to a variable that receives the
              handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetAccessRights, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phVmAcl
		) );

/* Determines if guest sharing is enabled (the guest OS disk
   drives are visible in the host OS).

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                   A handle of type PHT_VM_CONFIGURATION
                              identifying the virtual machine
							  configuration.
   pbVmGuestSharingEnabled :  [out] A pointer to a variable that
                              receives the result. PRL_TRUE
                              indicates that guest sharing is
                              enabled. PRL_FALSE indicates
                              otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsGuestSharingEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmGuestSharingEnabled
		) );

/* Enables the guest sharing feature. If guest sharing is
   enabled, the guest OS disk drives will be accessible in the
   host OS. If, in addition, the auto-mount feature is turned
   on, the guest OS disk drives will appear as icons on the host
   desktop. If sharing is enabled but auto-mount is not, you
   will not see the drives in the host OS but Smart Select
   feature will still work.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                  A handle of type PHT_VM_CONFIGURATION
                             identifying the virtual machine
                             configuration.
   bVmGuestSharingEnabled :  The value to set. Specify PRL_TRUE
                             to enable guest sharing. Specify
                             PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetGuestSharingEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmGuestSharingEnabled
		) );

/* Determines if host shared folders are mounted automatically
   in a given virtual machine. If shares are mounted
   automatically, then shared folders will be mapped and appear
   in the guest OS on startup.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                     A handle of type PHT_VM_CONFIGURATION
                                identifying the virtual machine
								configuration.
   pbVmGuestSharingAutoMount :  [out] A pointer to a variable
                                that receives the result.
                                PRL_TRUE indicates that shares
                                are mounted automatically.
                                PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsGuestSharingAutoMount, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmGuestSharingAutoMount
		) );

/* Sets the guest OS sharing auto-mount option. If guest sharing
   is enabled (see PrlVmCfg_SetGuestSharingEnabled) and auto-mount
   is turned on, the guest OS disk drives will appear as icons
   on the host desktop. If sharing is enabled but auto-mount is
   not, you will not see the drives in the host OS but Smart
   Select feature will still work.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                    A handle of type PHT_VM_CONFIGURATION
                               identifying the virtual machine
							   configuration.
   bVmGuestSharingAutoMount :  Auto\-mount option to set. Specify
                               PRL_TRUE to enable sharing
                               auto\-mount. Specify PRL_FALSE to
                               disable auto\-mount.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetGuestSharingAutoMount, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmGuestSharingAutoMount
		) );

/* Determines if guest OS cloud drives sharing auto-mount option is enabled
   or not. Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   pbEnable : [out] A pointer to a variable that receives the result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_IsGuestSharingAutoMountCloudDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnable
		) );

/* Sets the guest OS cloud drives sharing auto-mount option.
   Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetGuestSharingAutoMountCloudDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnable
		) );

/* Determines if guest OS network drives sharing auto-mount option is enabled
   or not. Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   pbEnable : [out] A pointer to a variable that receives the result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_IsGuestSharingAutoMountNetworkDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnable
		) );

/* Sets the guest OS network drives sharing auto-mount option.
   Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetGuestSharingAutoMountNetworkDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnable
		) );

/* Determines if guest OS removable drives sharing auto-mount option is enabled
   or not. Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   pbEnable : [out] A pointer to a variable that receives the result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_IsGuestSharingAutoMountRemovableDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnable
		) );

/* Sets the guest OS removable drives sharing auto-mount option.
   Parallels Tools must be installed to use this feature.

   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying the virtual
			machin configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
				 PrlVmCfg_SetGuestSharingAutoMountRemovableDrives, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnable
		) );

/* Determines if the virtual disks in a virtual machine will be
   added to Spotlight search subsystem (OS X feature).
   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                           A handle of type
                                      PHT_VM_CONFIGURATION
                                      identifying the virtual
                                      machine configuration.
   pbVmGuestSharingEnableSpotlight :  [out] A pointer to a
                                      variable that receives the
                                      \result. PRL_TRUE indicates
                                      that virtual disks are
                                      added to Spotlight search
                                      subsystem. PRL_FALSE
                                      indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsGuestSharingEnableSpotlight, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmGuestSharingEnableSpotlight
		) );

/* Sets the VM virtual disks added to Spotlight search subsystem sign.
   If guest sharing is enabled (see PrlVmCfg_SetGuestSharingEnabled) and
   Spotlight enable sign is turned on, the search through Spotlight subsystem
   will be using VM virtual hardisks too.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                    A handle of type PHT_VM_CONFIGURATION
                               identifying the virtual machine
							   configuration.
   bVmGuestSharingEnableSpotlight :  Enable Spotlight option to set. Specify
                               PRL_TRUE to enable using virtual harddisks
                               at Spotlight search subsystem. Specify PRL_FALSE to
                               disable virtual hard disks from Spotlight.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetGuestSharingEnableSpotlight, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmGuestSharingEnableSpotlight
		) );

/* Determines if host sharing is enabled (host shared folders
   are visible in the guest OS). Parallels Tools must be
   installed to use this feature. To obtain the Parallels Tools
   status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                  A handle of type
                             PHT_VM_CONFIGURATION identifying the
                             virtual machine configuration.
   pbVmHostSharingEnabled :  [out] A pointer to a variable that
                             receives the result. PRL_TRUE
                             indicates that sharing is enabled.
                             PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsHostSharingEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmHostSharingEnabled
		) );

/* Enables host sharing for the specified virtual machine. When
   host sharing is enabled, the host OS shared folders will be
   visible in the guest OS. To use the host sharing feature, the
   shared folders must be set up first using the functionality
   provided by the PHT_SHARE object.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   bVmHostSharingEnabled :  The value to set. Specify PRL_TRUE to
                            enable sharing. Specify PRL_FALSE to
                            disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetHostSharingEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmHostSharingEnabled
		) );

/* Determines whether the Virtual Links feature is enabled in a
   virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the shred
                profile is enabled. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                PrlVmCfg_IsVirtualLinksEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the Virtual Links feature in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  The value to set. Specify PRL_TRUE to enable the
               Shared Profile. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsVirtualLinksEnabled                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetVirtualLinksEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );

/* Determines whether all host disks will be present at guest OS
   as shares. Parallels Tools must be installed to use this
   feature. To obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine
                          configuration.
   pbShareAllHostDisks :  [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that all host disks will be. shared
                          into guest OS. PRL_FALSE indicates
                          otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsShareAllHostDisks, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbShareAllHostDisks
		) );

/* Enables sharing of all host disks for the specified virtual machine.
   When this sign switched on all host disks will be shared into guest
   OS. Note that host sharing should be switched on to enable this
   functionality.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   bShareAllHostDisks    :  The value to set. Specify PRL_TRUE to
                            share all host disks to guest OS.
							Specify PRL_FALSE to not share them.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetShareAllHostDisks, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bShareAllHostDisks
		) );


/* Determines whether the host user home directory will be
   available in the guest OS as a share. Parallels Tools must be
   installed to use this feature. To obtain the Parallels Tools
   status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   pbShareUserHomeDir :  [out] A pointer to a variable that
                         receives the result. PRL_TRUE indicates
                         that host user home directory will be
                         shared with the guest OS. PRL_FALSE
                         indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsShareUserHomeDir, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbShareUserHomeDir
		) );

/* Enables or disables sharing of the host user home directory
   in the specified virtual machine. When this feature is
   enabled, the host user home directory will be shared in the
   virtual machine. Note that host sharing should be enabled to
   use this functionality. Parallels Tools must be installed to
   use this feature. To obtain the Parallels Tools status, use
   the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine
                        configuration.
   bShareUserHomeDir :  The value to set. Specify PRL_TRUE to
                        share the host user home directory.
                        Specify PRL_FALSE not to share it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetShareUserHomeDir, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bShareUserHomeDir
		) );


/* Determines whether host disks shared with the guest Windows
   OS will be mapped to drive letters. Parallels Tools must be
   installed to use this feature. To obtain the Parallels Tools
   status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                       A handle of type
                                  PHT_VM_CONFIGURATION
                                  identifying the virtual machine
                                  configuration.
   pbMapSharedFoldersOnLetters :  [out] A pointer to a variable
                                  that receives the result.
                                  PRL_TRUE indicates that host
                                  disks will be mapped to drive
                                  letters. PRL_FALSE indicates
                                  otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsMapSharedFoldersOnLetters, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbMapSharedFoldersOnLetters
		) );

/* Enables mapping of shared host disks on drive letters for the specified virtual machine.
   When this sign switched on host disks shared into guest Windows OS will be maped on
   correspond drive letters. Note that host sharing should be switched on to enable this
   functionality.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   bMapSharedFoldersOnLetters    :  The value to set. Specify PRL_TRUE to
                            map shared host disks on drive letters.
							Specify PRL_FALSE to not share it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetMapSharedFoldersOnLetters, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bMapSharedFoldersOnLetters
		) );


/* Determines if Windows task bar is displayed when the virtual
   machine runs in coherence mode. Parallels Tools must be
   installed to use this feature. To obtain the Parallels Tools
   status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine
					  configuration.
   pbVmShowTaskBar :  [out] A pointer to a variable that receives
                      the result. PRL_TRUE indicates that the
                      option is enabled. PRL_FALSE indicates
                      otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsShowTaskBar, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmShowTaskBar
		) );

/* Allows to show or hide the Windows task bar when the virtual
   machine is running in coherence mode. Parallels Tools must be
   installed to use this feature. To obtain the Parallels Tools
   status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   bVmShowTaskBar :  The value to set. Specify PRL_TRUE to enable
                     the option. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetShowTaskBar, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmShowTaskBar
		) );

/* Determines the guest OS window behavior in coherence mode.
   When a virtual machine is running in coherence mode, you can
   make the dock stay always below the virtual machine window.
   If the window is moved below the dock, the portion of it that
   crossed that boundary will be cut (will not be redrawn). In
   order to do that, call this function passing PRL_TRUE in the
   bVmExcludeDock parameter. If the parameter is set to
   PRL_FALSE, the virtual machine window will be able to move
   below the dock.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   pbVmExcludeDock :  [out] A pointer to a variable that receives
                      the result. PRL_TRUE indicates that dock is
                      excluded. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsExcludeDock, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmExcludeDock
		) );

/* Sets the exclude dock option. When a virtual machine is
   running in coherence mode, you can make the dock stay always
   below the virtual machine window. If the window is moved
   below the dock, the portion of it that crossed that boundary
   will be cut (will not be redrawn). In order to do that, call
   this function passing PRL_TRUE in the bVmExcludeDock
   parameter. If the parameter is set to PRL_FALSE, the virtual
   machine window will be able to move below the dock.

   Parallels Tools must be installed to use this feature. To
   obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   bVmExcludeDock :  The value to set. Specify PRL_TRUE to
                     exclude the dock. Specify PRL_FALSE to
                     include the dock.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetExcludeDock, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmExcludeDock
		) );

/* Determines if the specified virtual machine uses a
   multi-display mode.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine
					   configuration.
   pbVmMultiDisplay :  [out] A pointer to a variable that
                       receives the result. PRL_TRUE indicates
                       multi\-display. PRL_FALSE indicates
                       otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsMultiDisplay, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmMultiDisplay
		) );

/* Sets the virtual machine multi-display option.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   bVmMultiDisplay :  The value to set. Specify PRL_TRUE to
                      enable the multi\-display option. Specify
                      PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetMultiDisplay, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmMultiDisplay
		) );

/* Determines if the VM pauses automatically when it becomes idle (i.e. when
   no applications is running in the VM)
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine
					   configuration.
   pbVmPauseWhenIdle :  [out] A pointer to a variable that
                       receives the result. PRL_TRUE indicates
                       that VM will be paused when it becomes idle.
					   PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_IsPauseWhenIdle, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmPauseWhenIdle
		) );

/* Sets the virtual machine "Pause Idle VM" option.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   bVmPauseWhenIdle :  The value to set. Specify PRL_TRUE to
                      enable autopause when the VM becomes idle.
					  Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetPauseWhenIdle, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmPauseWhenIdle
		) );

/* Determines disable or enable Windows systray in Mac menu.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsWinSystrayInMacMenuEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables Windows systray in Mac menu.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetWinSystrayInMacMenuEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable switching to full
   screen on demand.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSwitchToFullscreenOnDemandEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables switching to full
   screen on demand.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSwitchToFullscreenOnDemandEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines if additional screen resolution support is enabled
   in a virtual machine.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pbVmScrResEnabled :  [out] A pointer to a variable that
                        receives the result. PRL_TRUE indicates
                        that the feature is enabled. PRL_FALSE
                        indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsScrResEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmScrResEnabled
		) );

/* Enables or disables the additional screen resolution support
   in a virtual machine.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine
                       configuration.
   bVmScrResEnabled :  Action type. Specify PRL_TRUE to enable
                       the additional screen resolution support.
                       Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsScrResEnabled                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetScrResEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmScrResEnabled
		) );

/* Determines if disk cache write-back is enabled in the
   specified virtual machine.
   Parameters
   hVmCfg :                  A handle of type
                             PHT_VM_CONFIGURATION identifying the
                             virtual machine configuration.
   pbVmDiskCacheWriteBack :  [out] A pointer to a variable that
                             receives the result. PRL_TRUE
                             indicates that cache write\-back is
                             enabled. PRL_FALSE indicates
                             otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetDiskCacheWriteBack                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsDiskCacheWriteBack, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmDiskCacheWriteBack
		) );

/* Sets the virtual machine disk cache write-back option.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   bVmDiskCacheWriteBack :  The disk cache write\-back option to
                            set. Specify PRL_TRUE to enable the
                            disk cache write\-back. Specify
                            PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetDiskCacheWriteBack, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmDiskCacheWriteBack
		) );

/* Determines wether the virtual machine OS resolution is in
   full screen mode.
   Parameters
   hVmCfg :                  A handle of type
                             PHT_VM_CONFIGURATION identifying the
                             virtual machine configuration.
   pbVmOsResInFullScrMode :  [out] A pointer to a variable that
                             receives the result. PRL_TRUE
                             indicates full screen mode.
                             PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsOsResInFullScrMode, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmOsResInFullScrMode
		) );

/* Sets the virtual machine OS resolution in full screen mode
   option.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   bVmOsResInFullScrMode :  The value to set. Specify PRL_TRUE to
                            enable the option. Specify PRL_FALSE
                            to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetOsResInFullScrMode, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmOsResInFullScrMode
		) );

/* <unfinished>

   Determines whether the Parallels application (such as
   Parallels Desktop) will be automatically closed on the
   virtual machine shutdown.
   Parameters
   handle :                  A handle of type PHT_VIRTUAL_MACHINE
                             identifying the virtual machine.
   pbVmCloseAppOnShutdown :  [out] A pointer to a variable that
                             receives the result. PLR_TRUE
                             indicates that applications will be
                             closed. PRL_FALSE indicates
                             otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - operation successfully completed.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_IsCloseAppOnShutdown, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbVmCloseAppOnShutdown
		) );

/* Allows to specify whether the Parallels application (such
   Parallels Desktop) will be closed on the virtual machine
   shutdown.
   Parameters
   hVmCfg :                 A handle of type PHT_VIRTUAL_MACHINE
                            identifying the virtual machine.
   bVmCloseAppOnShutdown :  Action type. Specify PRL_TRUE to
                            close the application. Specify
                            PRL_FALSE to keep it running.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsCloseAppOnShutdown                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetCloseAppOnShutdown, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bVmCloseAppOnShutdown
		) );

/* <unfinished>

   \Returns the virtual machine system flags.
   Parameters
   hVmCfg :                    A handle of type
                               PHT_VM_CONFIGURATION identifying
                               the virtual machine configuration.
   sVmSystemFlags :            [out] A pointer to a buffer that
                               receives the result (a UTF\-8
                               encoded, null\-terminated string).
   pnVmSystemFlagsBufLength :  [in] The size of the output buffer
                               (in bytes). Set the buffer pointer
                               to null and this parameter's value
                               to zero to receive the required
                               size. [out] The required output
                               buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetSystemFlags, (
		PRL_HANDLE hVmCfg,
		PRL_STR sVmSystemFlags,
		PRL_UINT32_PTR pnVmSystemFlagsBufLength
		) );

/* Sets the virtual machine system flags.
   Parameters
   handle :         A handle of type PHT_VIRTUAL_MACHINE
                    identifying the virtual machine.
   unnamed_param :  New virtual machine system flags, a UTF\-8
                    encoded null terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetSystemFlags, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNewVmSystemFlags
		) );

/* Determines whether the APIC is enabled or disabled during the
   virtual machine runtime.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine
                    configuration.
   pbDisableAPIC :  [out] A pointer to a variable that receives
                    the result. PRL_TRUE indicates that the APIC
                    is disabled. PBL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsDisableAPIC, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbDisableAPIC
		) );

/* Allows to specify whether the virtual machine should be using
   APIC during runtime.
   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   bDisableAPIC :  The value to set. Specify PRL_TRUE to enable
                   the APIC. Specify PRL_FALSE disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsDisableAPIC                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetDisableAPICSign, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bDisableAPIC
		) );

/* Determines the current undo-disks mode for the specified
   virtual machine.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine
                      configuration.
   pnUndoDisksMode :  [out] A pointer to a variable that receives
                      the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetUndoDisksMode, (
		PRL_HANDLE hVmCfg,
		PRL_UNDO_DISKS_MODE_PTR pnUndoDisksMode
		) );


/* Sets the undo-disks mode for the virtual machine.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine
                     configuration.
   nUndoDisksMode :  The undo disks mode option to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetUndoDisksMode, (
		PRL_HANDLE hVmCfg,
		PRL_UNDO_DISKS_MODE nUndoDisksMode
		) );

/* Determines the current dock mode for the specified virtual
   machine. Parallels Tools must be installed to use this
   feature. To obtain the Parallels Tools status, use the
   PrlVm_GetToolsState function.
   Parameters
   hVmCfg :             A handle of type PHT_VM_CONFIGURATION
                        identifying the virtual machine configuration.
   pnVmAppInDockMode :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetAppInDockMode, (
		PRL_HANDLE hVmCfg,
		PRL_APP_IN_DOCK_MODE_PTR pnVmAppInDockMode
		) );

/* Sets the dock mode for the applications (see
   PRL_APP_IN_DOCK_MODE for available options). Parallels Tools
   must be installed to use this feature. To obtain the
   Parallels Tools status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   nVmAppInDockMode :  The applications in dock mode option to
                       set. See the PRL_APP_IN_DOCK_MODE
                       enumeration for the list of options.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetAppInDockMode, (
		PRL_HANDLE hVmCfg,
		PRL_APP_IN_DOCK_MODE nVmAppInDockMode
		) );

/* \Returns foreground processes priority for the specified
   virtual machine.
   Parameters
   hVmCfg :                  A handle of type PHT_VM_CONFIGURATION
                             identifying the virtual machine configuration.
   pnVmForegroundPriority :  [out] A pointer to a variable that
                             receives the result
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetForegroundPriority, (
		PRL_HANDLE hVmCfg,
		PRL_VM_PRIORITY_PTR pnVmForegroundPriority
		) );

/* Sets the virtual machine foreground processes priority.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
							configuration.
   nVmForegroundPriority :  The priority level to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetForegroundPriority, (
		PRL_HANDLE hVmCfg,
		PRL_VM_PRIORITY nVmForegroundPriority
		) );

/* Determines the specified virtual machine background process
   priority type.
   Parameters
   hVmCfg :                  A handle of type PHT_VM_CONFIGURATION
                             identifying the virtual machine
							 configuration.
   pnVmBackgroundPriority :  [out] A pointer to a variable that
                             receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetBackgroundPriority, (
		PRL_HANDLE hVmCfg,
		PRL_VM_PRIORITY_PTR pnVmBackgroundPriority
		) );

/* Sets the virtual machine background processes priority.
   Parameters
   hVmCfg :                 A handle of type PHT_VM_CONFIGURATION
                            identifying the virtual machine
                            configuration.
   nVmBackgroundPriority :  The priority level to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetBackgroundPriority, (
		PRL_HANDLE hVmCfg,
		PRL_VM_PRIORITY nVmBackgroundPriority
		) );

/* \Returns the virtual machine dock icon type. This
   functionality is part of the Parallels Tools package. See
   PHT_VM_TOOLS_INFO.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   pnVmDockIconType :  [out] A pointer to a variable that
                       receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_GetDockIconType, (
		PRL_HANDLE hVmCfg,
		PRL_DOCK_ICON_TYPE_PTR pnVmDockIconType
		) );

/* Sets the virtual machine dock icon type. Parallels Tools must
   be installed to use this feature. To obtain the Parallels
   Tools status, use the PrlVm_GetToolsState function.
   Parameters
   hVmCfg :           A handle of type PHT_VM_CONFIGURATION
                      identifying the virtual machine configuration.
   nVmDockIconType :  The icon type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmCfg_SetDockIconType, (
		PRL_HANDLE hVmCfg,
		PRL_DOCK_ICON_TYPE nVmDockIconType
		) );

/* Determines whether the use default answers mechanism active for
   the virtual machine.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION identifying
                          the virtual machine configuration.
   pbUseDefaultAnswers :  [out] A pointer to a variable that receives the
                          \result. PRL_TRUE indicates that mehanism is
                          active. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetUseDefaultAnswers                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsUseDefaultAnswers, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbUseDefaultAnswers
		) );

/* Enables the use default answers mechanism in a virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable
               mechanism. In this case system won't passing questions
			   from virtual machine to client side and answering on
			   them automatically. Specify PRL_FALSE to disable
			   mechanism and processing virtual machine questions
			   explicitly.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsUseDefaultAnswers                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetUseDefaultAnswers, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bUseDefaultAnswers
		) );

/* Obtains the list of globally defined search domains that will
   be assigned to a virtual machine on the guest operating
   system side.
   Parameters
   hVmCfg:               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual machine
                          configuration.
   phSearchDomainsList :  [out] A pointer to the PHT_STRINGS_LIST
                          handle containing the list of search
                          domains.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate the
   string list object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSearchDomains				*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_GetSearchDomains, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phSearchDomainsList
		) );

/* Allows to manually set the global search domain list that
   will be assigned to the virtual machine.
   \Note: For these changes to take effect, Parallels Tools must
   be installed in a target virtual machine.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmCfg:              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   hSearchDomainsList :  A handle of type PHT_STRINGS_LIST
                         containing the list of search domains to
                         be applied to the global network
                         settings of the virtual machine
                         operating system. Can be
                         PRL_INVALID_HANDLE if it's necessary to
                         specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetSearchDomains				*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetSearchDomains, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hSearchDomainsList
		) );

/* Obtains the list of of globally defined DNS servers which is assigned to a
   virtual machine.
   Parameters
   hVmCfg:              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   phDnsServersList:  [out] A pointer to the PHT_STRINGS_LIST
                       handle that receives the list of DNS
                       servers.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate strings
   list object.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetDnsServers, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE_PTR phDnsServersList
		) );

/* Allows to manually assign DNS servers
   a virtual machine. <b>Note</b>: For these changes to take
   effect, Parallels Tools must be installed in the target virtual
   machine, and its network adapter settings should be configured
   to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmCfg:              A handle of type PHT_VM_CONFIGURATION
                         identifying the virtual machine
                         configuration.
   hDnsServersList:  A handle of type PHT_STRINGS_LIST
                      containing the list of DNS servers to be
                      assigned to the network adapter. Can be
                      PRL_INVALID_HANDLE if it's necessary to
                      specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_SetDnsServers, (
		PRL_HANDLE hVmCfg,
		PRL_HANDLE hDnsServersList
		) );

/* Allows to specify whether a virtual machine should be automatically
   configured for IP addrs.
   In comparison with PrlVmDevNet_SetAutoApply(), dns servers
   and searchdomains settings will be skipped.
   Note: for changes to take effect, Parallels Tools must be
   installed in a target virtual machine.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmCfg :              A handle of type
                         PHT_VM_CONFIGURATION identifying
                         the virtual network adapter.
   bAutoApplyIpOnly :    Specify PRL_TRUE to configure the
                         adapter automatically. Specified
                         PRL_FALSE to configure the network
                         settings manually in a virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                             PrlVmCfg_SetAutoApplyIpOnly, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bAutoApplyIpOnly
               ) );

/* Determines if the Guest configured to automatically apply IP addrs network
   settings inside guest.
   Parameters
   hVmCfg :               A handle of type PHT_VM_CONFIGURATION
                          identifying the virtual network
                          adapter.
   pbAutoApplyIpOnly : [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that the adapter is configured to automatically
                          apply network settings. PRL_FALSE indicates
                          otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                  */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                                PrlVmCfg_IsAutoApplyIpOnly, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL_PTR pbAutoApplyIpOnly
               ) );


/* Obtains a handles list of operations with virtual machine which required administrator confirmation

Parameters

   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   phConfirmList : [out] A pointer to a variable that receives
                   the handle. The type of the handle is PHT_OPAQUE_TYPE_LIST.
				   ( values in list consist in enum PRL_ALLOWED_VM_COMMAND )
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle.
   See Also
      PrlSrv_DisableConfirmationMode()
	  PrlSrv_EnableConfirmationMode()
      PrlSrv_IsConfirmationModeEnabled()
      PrlVmCfg_GetConfirmationsList()
      PrlVmCfg_SetConfirmationsList()
      PrlDispCfg_GetConfirmationsList()
      PrlDispCfg_SetConfirmationsList()
*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlVmCfg_GetConfirmationsList, (
				PRL_HANDLE hVmCfg,
				PRL_HANDLE_PTR phConfirmList
				) );

/* Determines a list of operations with virtual machine which required administrator confirmation

Parameters

   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   hConfirmList :  A handle of type is PHT_OPAQUE_TYPE_LIST
                   contains new list of operations( values in enum PRL_ALLOWED_VM_COMMAND )
				   that required administrator's confirmation.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle.
   See Also
      PrlSrv_DisableConfirmationMode()
	  PrlSrv_EnableConfirmationMode()
      PrlSrv_IsConfirmationModeEnabled()
      PrlVmCfg_GetConfirmationsList()
      PrlVmCfg_SetConfirmationsList()
      PrlDispCfg_GetConfirmationsList()
      PrlDispCfg_SetConfirmationsList()
*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlVmCfg_SetConfirmationsList, (
				PRL_HANDLE hVmCfg,
				PRL_HANDLE hConfirmList
				) );

/* Obtains a handles list of operations with virtual machine which require custom password

Parameters

   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   phList : [out] A pointer to a variable that receives
                   the handle. The type of the handle is PHT_OPAQUE_TYPE_LIST.
           ( values in list consist in enum PRL_ALLOWED_VM_COMMAND )
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle.
   See Also
     PrlVmCfg_SetPasswordProtectedOperationsList()
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
        PrlVmCfg_GetPasswordProtectedOperationsList, (
        PRL_HANDLE hVmCfg,
        PRL_HANDLE_PTR phList
        ) );

/* Determines a list of operations with virtual machine which require custom password

Parameters

   Parameters
   hVmCfg :        A handle of type PHT_VM_CONFIGURATION
                   identifying the virtual machine configuration.
   hList :  A handle of type is PHT_OPAQUE_TYPE_LIST
                   contains new list of operations( values in enum PRL_ALLOWED_VM_COMMAND )
           that require custom password.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound

   PRL_ERR_SUCCESS - function completed successfully.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a handle.
   See Also
     PrlVmCfg_GetPasswordProtectedOperationsList()
*/
PRL_METHOD_DECL( PARALLELS_API_VER_6_1,
        PrlVmCfg_SetPasswordProtectedOperationsList, (
        PRL_HANDLE hVmCfg,
        PRL_HANDLE hList
        ) );

/* Determines whether the Automatic HDD compress feature is enabled
   or not in a virtual machine. Automatic HDD compress is feature
   that allows to make automatic compacting of a virtual machine disks
   at predefined time intervals. The feature recommends Parallels Tools
   installed in a virtual machine.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that Automatic HDD compress
				is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetAutoCompressEnabled                               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_IsAutoCompressEnabled, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEnabled
		) );


/* Enables the Automatic HDD compress feature in a virtual machine.
   Automatic HDD compress is feature that allows to make automatic
   compress of a virtual machine disks at predefined time intervals.
   The feature recommends Parallels Tools installed in a virtual
   machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable
               Automatic HDD compress. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetAutoCompressdInterval
   PrlVmCfg_SetFreeDiskSpaceRatio                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetAutoCompressEnabled, (
               PRL_HANDLE hVmCfg,
               PRL_BOOL bEnabled
		) );


/* Determines the interval at which compacting virtual disks
   are doing by Automatic HDD compress. Automatic HDD compress
   is a facility that allows to make automatic compress of a virtual
   machine disks at predefined time intervals. The currently set
   time interval can be obtained using this function.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pnInterval :  [out] A pointer to a variable the receives the
                 automatic compress interval, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetAutoCompressInterval                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_GetAutoCompressInterval, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnInterval
		) );


/* Sets the time interval at which compacting virtual disks
   are doing by Automatic HDD compress. Automatic HDD compress
   is feature that allows to make automatic compress of a virtual
   machine disks at predefined time intervals. This function
   allows to set the interval at which the automatic compress
   are taken.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nInterval :  The time interval to set, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetAutoCompressInterval                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetAutoCompressInterval, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nInterval
		) );


/* Determines the free disk space ratio at which compacting virtual
   disks are doing by Automatic HDD compress. Automatic HDD compress
   is a facility that allows to make automatic compress of a virtual
   machine disks at predefined space ratio. The currently set
   space ratio can be obtained using this function.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pdFreeDiskSpaceRatio :  [out] A pointer to a variable the receives
                 the automatic compress space ratio, in percents.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetFreeDiskSpaceRatio                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
                PrlVmCfg_GetFreeDiskSpaceRatio, (
                PRL_HANDLE hVmCfg,
                PRL_DOUBLE_PTR pdFreeDiskSpaceRatio
		) );


/* Sets the time free disk space ratio at which compacting virtual
   disks are doing by Automatic HDD compress. Automatic HDD compress
   is feature that allows to make automatic compress of a virtual
   machine disks at predefined space ratio. This function allows to
   set the space ratio at which the automatic compress are taken.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   dFreeDiskSpaceRatio :  The space ratio to set, in percents.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetFreeDiskSpaceRatio                                */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
               PrlVmCfg_SetFreeDiskSpaceRatio, (
               PRL_HANDLE hVmCfg,
               PRL_DOUBLE dFreeDiskSpaceRatio
		) );

/*
   Enables or disables the Parallels Tools AutoUpdate feature for a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable the
               AutoUpdate feature. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_IsToolsAutoUpdateEnabled, (
		 PRL_HANDLE hVmCfg,
		 PRL_BOOL_PTR pbEnabled
		) );

/*
   Enables or disables the Parallels Tools AutoUpdate feature for a
   virtual machine.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Action type. Specify PRL_TRUE to enable the
               AutoUpdate feature. Specify PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmCfg_SetToolsAutoUpdateEnabled, (
		 PRL_HANDLE hVmCfg,
		 PRL_BOOL bEnabled
		) );

/* Obtains a handle of type PHT_VM_INFO containing the specified
   virtual machine state and access rights information.
   Possible values are:

   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION
               identifying the virtual machine configuration.
   phVmInfo :  [out] A pointer to a variable that receives the
               handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate object

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmCfg_GetVmInfo, (
				 PRL_HANDLE hVmCfg,
				 PRL_HANDLE_PTR phVmInfo
				 ) );

/* \Returns locale for unattended installation.
   Parameters
   hVmCfg :			   A handle of type PHT_VM_CONFIGURATION
					   identifying the virtual machine
					   configuration.
   sLocale :           [out] A pointer to a buffer that receives
					   the result (a UTF\-8 encoded,
					   null\-terminated string).
   pnLocaleBufLength : [in] The size of the output buffer (in
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

PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_GetUnattendedInstallLocale, (
		PRL_HANDLE hVmCfg,
		PRL_STR sLocale,
		PRL_UINT32_PTR pnLocaleBufLength
		) );

/* Sets locale for unattended installation.
   Parameters
   hVmCfg :   A handle of type PHT_VM_CONFIGURATION
              identifying the virtual machine
              configuration.
   sLocale :  The locale to set. The value
              must be a a UTF\-8 encoded,
              null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetUnattendedInstallLocale, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sLocale
		) );

/* \Returns edition for unattended installation.
   Parameters
   hVmCfg :			    A handle of type PHT_VM_CONFIGURATION
					    identifying the virtual machine
					    configuration.
   sEdition :           [out] A pointer to a buffer that receives
					    the result (a UTF\-8 encoded,
					    null\-terminated string).
   pnEditionBufLength : [in] The size of the output buffer (in
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

PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_GetUnattendedInstallEdition, (
		PRL_HANDLE hVmCfg,
		PRL_STR sEdition,
		PRL_UINT32_PTR pnEditionBufLength
		) );

/* Sets edition for unattended installation.
   Parameters
   hVmCfg :   A handle of type PHT_VM_CONFIGURATION
              identifying the virtual machine
              configuration.
   sEdition : The locale to set. The value
              must be a a UTF\-8 encoded,
              null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmCfg_SetUnattendedInstallEdition, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sEdition
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Virtual Machine encryption functionality
///////////////////////////////////////////////////////////////////////////////

/* Determines whether the virtual machine is in encrypted state
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEncrypted :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that virtual machine is
                encrypted. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSmartGuardEnabled                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
                PrlVmCfg_IsEncrypted, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbEncrypted
		) );


/* Determines whether the virtual machine is in protected state
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbProtected :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that virtual machine is
                protected. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                PrlVmCfg_IsProtected, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbProtected
		) );

/* Determines whether the virtual machine is in archived state
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbArchived : [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that virtual machine is
                archived. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
                PrlVmCfg_IsArchived, (
                PRL_HANDLE hVmCfg,
                PRL_BOOL_PTR pbArchived
		) );

/* Gets use host printers option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   pbUse :	[out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlVmCfg_IsUseHostPrinters, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbUse
		) );

/* Sets use host printers option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   bUse :	If this parameter is set to PRL_TRUE then VM uses host
			printers. Otherwise VM uses virtual parallel port
			devices as printers.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlVmCfg_SetUseHostPrinters, (
		PRL_HANDLE hVm,
		PRL_BOOL bUse
		) );

/* Gets synchronization default printer option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   pbSync :	[out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlVmCfg_IsSyncDefaultPrinter, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbSync
		) );

/* Sets synchronization default printer option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   bSync :	If this parameter is set to PRL_TRUE then VM synchronizes
			default printer with host one.
			Otherwise VM does not synchronize it.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlVmCfg_SetSyncDefaultPrinter, (
		PRL_HANDLE hVm,
		PRL_BOOL bSync
		) );

/* Gets show host printer UI option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   pbShow :	[out] A pointer to a variable that receives the
			\result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_IsShowHostPrinterUI, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbShow
		) );

/* Sets synchronization default printer option.
   Parameters
   hVm :	A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine
			configuration.
   bSync :	If this parameter is set to PRL_TRUE then VM will
			show host printer UI before actual printing.
			Otherwise VM does not show host printer UI.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmCfg_SetShowHostPrinterUI, (
		PRL_HANDLE hVm,
		PRL_BOOL bShow
		) );

/* Determines disable or enable shared camera.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSharedCameraEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables shared camera.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSharedCameraEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable bluetooth camera.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSharedBluetoothEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables bluetooth camera.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSharedBluetoothEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Determines disable or enable shared smart card readers.
	Parameters
	hVm :	  A handle of type PHT_VM_CONFIGURATION
			identifying the virtual machine configuration.
	pbEnable : [out] A pointer to a variable that receives the result.

	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

	PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
			PrlVmCfg_IsSharedSmartCardEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Disables or enables shared smart card readers.
	Parameters
	hVm :	 A handle of type PHT_VM_CONFIGURATION identifying the virtual machine configuration.
	bEnable : [in] Setting value.

	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

	PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
			PrlVmCfg_SetSharedSmartCardEnabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );

/* Gets support status USB 3.0.
   Parameters
   hVm :	  A handle of type PHT_VM_CONFIGURATION
			  identifying the virtual machine
			  configuration.
   pbEnable : [out] A pointer to a variable that receives the
			  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsSupportUsb30Enabled, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR pbEnable
		) );

/* Sets support status USB 3.0.
   Parameters
   hVm :	 A handle of type PHT_VM_CONFIGURATION
			 identifying the virtual machine
			 configuration.
   bEnable : [in] Setting value.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetSupportUsb30Enabled, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnable
		) );


/* Sets expiration date.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   sExpirationDate :   Date and time in "yyyy\-mm\-dd hh\:mm\:ss" format.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetExpirationDate, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sExpirationDate
		) );

/* Gets expiration date.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   sExpirationDate :   Date and time in "yyyy\-mm\-dd hh\:mm\:ss" format.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetExpirationDate, (
		PRL_HANDLE hVmCfg,
		PRL_STR sExpirationDateBuf,
		PRL_UINT32_PTR pnExpirationDateBufLength
		) );

/* Sets expiration date enabled/disabled.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   bEnabled :          Set restriction enabled or disabled.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetExpirationDateEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );

/* Gets expiration date status.
   Parameters
   hVmCfg :            A handle of type PHT_VM_CONFIGURATION
                       identifying the virtual machine configuration.
   bEnabled :          Set restriction enabled or disabled.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_IsExpirationDateEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR bEnabled
		) );

/* Gets the time interval to check on expiration date.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pnInterval : [out] A pointer to a variable the receives the
                time interval, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                PrlVmCfg_GetExpirationTimeCheckInterval, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnInterval
		) );


/* Sets the time interval to check on expiration date.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   nInterval : The time interval to set, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
               PrlVmCfg_SetExpirationTimeCheckInterval, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nInterval
		) );


/* Gets the offline time of working with virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying
            the virtual machine configuration.
   pnTime : [out] A pointer to a variable the receives the
            time interval, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
                PrlVmCfg_GetExpirationOfflineTimeToLive, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnTime
		) );


/* Sets the offline time of working with virtual machine.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION identifying
            the virtual machine configuration.
   nTime  : The time interval to set, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
               PrlVmCfg_SetExpirationOfflineTimeToLive, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nTime
		) );


/* Gets expiration note.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION
                     identifying the virtual machine configuration.
   sNote :           [out] A pointer to a buffer that receives
                     the result (a UTF\-8 encoded,
                     null\-terminated string).
   pnNoteBufLength : [in] The size of the output buffer (in
                     bytes). Set the buffer pointer to null
                     and this parameter's value to zero to
                     receive the required size. [out] The
                     required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetExpirationNote, (
		PRL_HANDLE hVmCfg,
		PRL_STR sNote,
		PRL_UINT32_PTR pnNoteBufLength
		) );


/* Sets expiration note.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   sNote :  The note to set. The value must be a a UTF\-8
            encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetExpirationNote, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sNote
		) );


/* Gets trusted time server.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION
                    identifying the virtual machine configuration.
   sUrl  :          [out] A pointer to a buffer that receives
                    the result (a UTF\-8 encoded,
                    null\-terminated string).
   pnUrlBufLength : [in] The size of the output buffer (in
                    bytes). Set the buffer pointer to null
                    and this parameter's value to zero to
                    receive the required size. [out] The
                    required output buffer size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_GetExpirationTrustedTimeServer, (
		PRL_HANDLE hVmCfg,
		PRL_STR sUrl,
		PRL_UINT32_PTR pnUrlBufLength
		) );


/* Sets trusted time server.
   Parameters
   hVmCfg : A handle of type PHT_VM_CONFIGURATION
            identifying the virtual machine configuration.
   sUrl :   The URL to set. The value must be a a UTF\-8
            encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
			PrlVmCfg_SetExpirationTrustedTimeServer, (
		PRL_HANDLE hVmCfg,
		PRL_CONST_STR sUrl
		) );


/* Get current VM profile.  Use PrlVmCfg_IsCustomProfile to
   detect if settings were modified after profile application.

   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   pnVmProfile : [out] A predefined settings profile.
                 See the PRL_VIRTUAL_MACHINE_PROFILE enumeration
                 for available options.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.			*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlVmCfg_GetProfile, (
					  PRL_HANDLE hVm,
					  PRL_VIRTUAL_MACHINE_PROFILE_PTR pnVmProfile
					  ) );


/* Determines were settings modified after profile was applied
   or not.

   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION
                 identifying the virtual machine configuration.
   pbCustom :    [out] A pointer to variable that indicates that
                 settings were modified after profile was applied.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.			*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlVmCfg_IsCustomProfile, (
					  PRL_HANDLE hVm,
					  PRL_BOOL_PTR pbCustom
					  ) );


/* Set one of predefined VM profiles.

   Parameters
   hVmCfg :       A handle of type PHT_VM_CONFIGURATION
                  identifying the virtual machine configuration.
   hSrvConfig :   A handle of type PHT_SERVER_CONFIG.
   nVmProfile :   [in] A predefined settings profile.
                  See the PRL_VIRTUAL_MACHINE_PROFILE enumeration
                  for available options.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.			*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				PrlVmCfg_SetProfile, (
					  PRL_HANDLE hVmCfg,
					  PRL_HANDLE hSrvConfig,
					  PRL_VIRTUAL_MACHINE_PROFILE nVmProfile
					  ) );


/* Determines whether the VM name and guest hostname synchronization feature is
   enabled in a virtual machine. Feature is available for Linux guests only.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
                PRL_TRUE indicates that the time synchronization
                is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSyncVmHostnameEnabled */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVmCfg_IsSyncVmHostnameEnabled, (
					PRL_HANDLE hVmCfg,
					PRL_BOOL_PTR pbEnabled
				) );


/* Enables or disables VM name and guest hostname synchronization feature in a
   virtual machine. You can synchronize hostname of the guest OS with the name
   of the virtual machine it is running on. Feature is available for Linux
   guests only.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVmCfg_SetSyncVmHostnameEnabled, (
					PRL_HANDLE hVmCfg,
					PRL_BOOL bEnabled
				) );

/* Determines whether synchronization public SSH keys from host with guest
   is enabled. Only Linux guests are supported at the moment.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
                PRL_TRUE indicates that the SSH keys synchronization
                is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetSyncSshIdsEnabled */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVmCfg_IsSyncSshIdsEnabled, (
					PRL_HANDLE hVmCfg,
					PRL_BOOL_PTR pbEnabled
				) );


/* Enables or disables synchronization set of public SSH keys from host with
   the respective set in SSH's authorised_keys file in guest. Only Linux
   guests are supported at the moment.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				PrlVmCfg_SetSyncSshIdsEnabled, (
					PRL_HANDLE hVmCfg,
					PRL_BOOL bEnabled
				) );

/* Determines whether "one finger swipe from edges" gesture enabled.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
   the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receives the result.
   PRL_TRUE indicates that the gesture is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetGestureSwipeFromEdgesEnabled */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmCfg_IsGestureSwipeFromEdgesEnabled, (
			PRL_HANDLE hVmCfg,
			PRL_BOOL_PTR pbEnabled
			) );


/* Enables or disables "one finger swipe from edges" gesture.
   Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
   the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmCfg_SetGestureSwipeFromEdgesEnabled, (
			PRL_HANDLE hVmCfg,
			PRL_BOOL bEnabled
			) );


/* Returns the resource quota value.
   Parameters
   hVmCfg :          A handle of type PHT_VM_CONFIGURATION identifying
                     the virtual machine configuration.
   pnResourceQuota : [out] A pointer to a variable the receives the
                     automatic compress interval, in seconds.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_SetResourceQuota                                */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
                PrlVmCfg_GetResourceQuota, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnResourceQuota
		) );


/* Sets the resource quota value.
   Parameters
   hVmCfg :         A handle of type PHT_VM_CONFIGURATION identifying
                    the virtual machine configuration.
   nResourceQuota : The resource quota value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_GetResourceQuota                                */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
               PrlVmCfg_SetResourceQuota, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nResourceQuota
		) );

/* Returns the travel mode enter condition.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pnCondition : [out] A pointer to a variable the receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetTravelModeEnterCondition, (
                PRL_HANDLE hVmCfg,
                PRL_BATTERY_ENTER_CONDITION_PTR pnCondition
		) );


/* Sets the travel mode enter condition.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   nCondition : The enter condition.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetTravelModeEnterCondition, (
               PRL_HANDLE hVmCfg,
               PRL_BATTERY_ENTER_CONDITION nCondition
		) );

/* Returns the travel mode enter battery threshold (percentage).
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pnThreshold : [out] A pointer to a variable the receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetTravelModeEnterThreshold, (
                PRL_HANDLE hVmCfg,
                PRL_UINT32_PTR pnThreshold
		) );


/* Sets the travel mode enter battery threshold (percentage).
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   nThreshold : The battery threshold (percentage).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetTravelModeEnterThreshold, (
               PRL_HANDLE hVmCfg,
               PRL_UINT32 nThreshold
		) );

/* Returns the travel mode quit condition.
   Parameters
   hVmCfg :      A handle of type PHT_VM_CONFIGURATION identifying
                 the virtual machine configuration.
   pnCondition : [out] A pointer to a variable the receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
                PrlVmCfg_GetTravelModeQuitCondition, (
                PRL_HANDLE hVmCfg,
                PRL_BATTERY_QUIT_CONDITION_PTR pnCondition
		) );


/* Sets the travel mode quit condition.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   nCondition : The quit condition.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
               PrlVmCfg_SetTravelModeQuitCondition, (
               PRL_HANDLE hVmCfg,
               PRL_BATTERY_QUIT_CONDITION nCondition
		) );

/* Determines whether share host location with VM is enabled.
	Parameters
	hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
				the virtual machine configuration.
	pbEnabled :  A pointer to a variable that receives the result.
				PRL_TRUE indicates that the sharing is enabled. PRL_FALSE indicates otherwise.

	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer to buffer was passed.

	PRL_ERR_SUCCESS - function completed successfully.

	See Also
	PrlVmCfg_SetShareHostLocationEnabled */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmCfg_IsShareHostLocationEnabled, (
			PRL_HANDLE hVmCfg,
			PRL_BOOL_PTR pbEnabled
			) );


/* Enables or disables share host location with VM.
	 Parameters
	 hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
				 the virtual machine configuration.
	 bEnabled :  Setting boolean value.

	 Returns
	 PRL_RESULT. Possible values:

	 PRL_ERR_INVALID_ARG - invalid handle was passed.

	 PRL_ERR_SUCCESS - function completed successfully.
	 */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmCfg_SetShareHostLocationEnabled, (
			PRL_HANDLE hVmCfg,
			PRL_BOOL bEnabled
			) );

///////////////////////////////////////////////////////////////////////////////
/// @section VM develop options
///////////////////////////////////////////////////////////////////////////////

/* Determines whether the "Show developer tools" option is enabled
   in a virtual machine. For more information, see PrlVmCfg_SetShowDevToolsEnabled.
   Parameters
   hVmCfg :     A handle of type PHT_VM_CONFIGURATION identifying
                the virtual machine configuration.
   pbEnabled :  A pointer to a variable that receive the result.
                PRL_TRUE indicates that the feature is enabled.
                PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer to
   buffer was passed.

   PRL_ERR_SUCCESS - function completed successfully.                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
			PrlVmCfg_IsShowDevToolsEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the "Show developer tools" option in a
   virtual machine.	 Parameters
   hVmCfg :    A handle of type PHT_VM_CONFIGURATION identifying
               the virtual machine configuration.
   bEnabled :  Setting boolean value.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmCfg_IsShowDevToolsEnabled                                                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
			PrlVmCfg_SetShowDevToolsEnabled, (
		PRL_HANDLE hVmCfg,
		PRL_BOOL bEnabled
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Virtual Machine Device object handling routines and data types
///////////////////////////////////////////////////////////////////////////////

/* Creates a new virtual device handle not bound to any virtual
   machine. It is necessary to call PrlHandle_Free after the
   handle usage.
   Parameters
   nDeviceType :  The type of handle to create.
   phVmDevice :   [out] A pointer to a variable that receives the
                  handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_Create, (
		PRL_DEVICE_TYPE nDeviceType,
		PRL_HANDLE_PTR phVmDevice
		) );

/* The PrlVmDev_Connect function allows to connect virtual
   devices while the virtual machine is running. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :  A handle identifying the virtual device.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVmDev_Connect, (
		PRL_HANDLE hVmDev
		) );

/* Allows to disconnect a device while the virtual machine is
   running. To get the return code from the PHT_JOB object, use
   the PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :  A handle identifying the virtual device.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVmDev_Disconnect, (
		PRL_HANDLE hVmDev
		) );

/* Physically creates a virtual device image on the host. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :               A handle identifying the virtual
                          device.
   bRecreateIsAllowed :   Specifies wether the existing image
                          should be replaced. If set to PRL_TRUE,
                          the existing image will be replaced. If
                          set to PRL_FALSE, the operation will be
                          aborted if image already exists.
   bNonInteractiveMode :  Specifies wether the operation should
                          be carried out in interactive mode
                          (where the Parallels Service may ask
                          questions and the client will have to
                          send answers). If set to PRL_TRUE,
                          non\-interactive mode will be used (the
                          Parallels Service will make decisions
                          on its own). If set to PRL_FALSE,
                          interactive mode will be used.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlVmDev_CreateImage, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bRecreateIsAllowed,
		PRL_BOOL bNonInteractiveMode
		) );

/* Copies a virtual device image to another custom location.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :        A handle identifying the virtual device.
   sNewImageName : New image short name.
   sTargetPath :   New custom location.
   nFlags :        Reserved
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
						   PrlVmDev_CopyImage, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewImageName,
		PRL_CONST_STR sTargetPath,
		PRL_UINT32 nFlags
		) );

/* Resize a virtual device image. To get
   the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :		A handle identifying the virtual device.

   nNewSize :		Specifies a new image size in Mbytes.

   nFlags :		bitset of (PRIF_DISK_INFO, PRIF_RESIZE_LAST_PARTITION).
                Also PACF_NON_INTERACTIVE_MODE can be used in order to
				specify non interactive session working mode (remote
				side won't ask questions during operation progress in
				this case).

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlVmDev_ResizeImage, (
		PRL_HANDLE hVmDev,
		PRL_UINT32 nNewSize,
		PRL_UINT32 nFlags
		) );

/* \Returns an index identifying the virtual device.
   Parameters
   hVmDev :   A handle identifying the virtual device. This can
              be one of the following\: PHT_VIRTUAL_DEV_FLOPPY,
              PHT_VIRTUAL_DEV_HARD_DISK,
              PHT_VIRTUAL_DEV_OPTICAL_DISK,
              PHT_VIRTUAL_DEV_PARALLEL_PORT,
              PHT_VIRTUAL_DEV_SERIAL_PORT,
              PHT_VIRTUAL_DEV_NET_ADAPTER.
   pnIndex :  [out] A pointer to a variable that receives the
              \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetIndex, (
		PRL_HANDLE hVmDev,
		PRL_UINT32_PTR pnIndex
		) );

/* Sets an index identifying the virtual device.
   Parameters
   hVmDev :  A handle identifying the virtual device. This can be
             one of the following\: PHT_VIRTUAL_DEV_FLOPPY,
             PHT_VIRTUAL_DEV_HARD_DISK,
             PHT_VIRTUAL_DEV_OPTICAL_DISK,
             PHT_VIRTUAL_DEV_PARALLEL_PORT,
             PHT_VIRTUAL_DEV_SERIAL_PORT,
             PHT_VIRTUAL_DEV_NET_ADAPTER.
   nIndex :  The new index.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetIndex, (
		PRL_HANDLE hVmDev,
		PRL_UINT32 nIndex
		) );

/* Removes the specified virtual device handle from
   the parent virtual machine list.
   Parameters
   hVmDev :  A handle identifying the virtual device.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_Remove, (
		PRL_HANDLE hVmDev
		) );

/* \Returns the type of the specified device.
   Parameters
   hVmDev :        A handle identifying the virtual device.
   pnDeviceType :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetType, (
		PRL_HANDLE hVmDev,
		PRL_DEVICE_TYPE_PTR pnDeviceType
		) );

/**
Checks if the specified virtual device is connected.

Parameters
hVmDev : A handle identifying the virtual device.
pbConnected : [out] A pointer to a variable that receives the
                \result.

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - invalid device handle or non valid (NULL) pointer to storing result,
or handle of already removed VM device was passed.
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_IsConnected, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbConnected
		) );

/* Connects the specified virtual device.
   Parameters
   hVmDev :      A handle identifying the virtual device.
   bConnected :  Value to set. PRL_TRUE to connect the device.
                 PRL_FALSE to disconnect it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetConnected, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bConnected
		) );

/* Determines if the specified device is enabled.
   Parameters
   hVmDev :     A handle identifying the virtual device.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_IsEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables the specified virtual device..
   Parameters
   hVmDev :    A handle identifying the virtual device.
   bEnabled :  Specify PRL_TRUE to enable the device. Specified
               PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetEnabled, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bEnabled
		) );

/* Determines if the specified virtual device is a remote
   device.
   Parameters
   hVmDev :    A handle identifying the virtual device.
   pbRemote :  [out] A pointer to a variable that receives the
               \result. PRL_TRUE indicates that this is a remote
               device. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_IsRemote, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbRemote
		) );

/* Changes the "remote" flag for the specified device.
   Parameters
   hVmDev :   A handle identifying the virtual device.
   bRemote :  Specify PRL_TRUE to make the device appear as
              remote. Specify PRL_FALSE to make the device appear
              as local.
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   virtual device handle or handle of already removed VM device
   was passed PRL_ERR_SUCCESS - operation completed successfully  */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetRemote, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bRemote
		) );

/* \Returns the virtual device emulation type. Emulation types
   are defined in the PRL_VM_DEV_EMULATION_TYPE enumeration. The
   following describes emulation types used for different types
   of virtual devices:
     * PHT_VIRTUAL_DEV_FLOPPY: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_HARD_DISK: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_OPTICAL_DISK: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_SERIAL_PORT: PDT_USE_REAL_DEVICE,
       PDT_USE_OUTPUT_FILE, PDT_USE_OTHER (for socket mode).
     * PHT_VIRTUAL_DEV_PARALLEL_PORT: PDT_USE_REAL_DEVICE,
       PDT_USE_OUTPUT_FILE, PDT_USE_OTHER (for printer mode).
     * PHT_VIRTUAL_DEV_NET_ADAPTER: PDT_USE_REAL_DEVICE
       (host-only network), PDT_USE_IMAGE_FILE (shared network),
       PDT_USE_OUTPUT_FILE (bridget ethernet)
     * PHT_VIRTUAL_DEV_SOUND: PDT_USE_REAL_DEVICE (AC'97),
       PDT_USE_IMAGE_FILE (Creative).
     * PHT_VIRTUAL_DEV_USB_DEVICE: PDT_USE_REAL_DEVICE
   Parameters
   hVmDev :          A handle identifying the virtual device.
   pnEmulatedType :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetEmulatedType, (
		PRL_HANDLE hVmDev,
		PRL_VM_DEV_EMULATION_TYPE_PTR pnEmulatedType
		) );

/* Sets the specified virtual device emulation type. Emulation
   types are defined in the PRL_VM_DEV_EMULATION_TYPE
   enumeration. The following describes emulation types used for
   different types of virtual devices:
     * PHT_VIRTUAL_DEV_FLOPPY: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_HARD_DISK: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_OPTICAL_DISK: PDT_USE_REAL_DEVICE,
       PDT_USE_IMAGE_FILE.
     * PHT_VIRTUAL_DEV_SERIAL_PORT: PDT_USE_REAL_DEVICE,
       PDT_USE_OUTPUT_FILE, PDT_USE_OTHER (for socket mode).
     * PHT_VIRTUAL_DEV_PARALLEL_PORT: PDT_USE_REAL_DEVICE,
       PDT_USE_OUTPUT_FILE, PDT_USE_OTHER (for printer mode).
     * PHT_VIRTUAL_DEV_NET_ADAPTER: PDT_USE_REAL_DEVICE (host
       only network), PDT_USE_IMAGE_FILE (shared network).
       PDT_USE_OUTPUT_FILE (bridget ethernet)
     * PHT_VIRTUAL_DEV_SOUND: PDT_USE_REAL_DEVICE (AC'97),
       PDT_USE_IMAGE_FILE (Creative).
     * PHT_VIRTUAL_DEV_USB_DEVICE: PDT_USE_REAL_DEVICE
   Parameters
   hVmDev :         A handle identifying the virtual device.
   nEmulatedType :  The emulation type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetEmulatedType, (
		PRL_HANDLE hVmDev,
		PRL_VM_DEV_EMULATION_TYPE nEmulatedType
		) );

/* \Returns virtual device image path.
   Parameters
   hVmDev :                A handle identifying the virtual
                           device. This can be one of the
                           following\: PHT_VIRTUAL_DEV_FLOPPY,
                           PHT_VIRTUAL_DEV_HARD_DISK,
                           PHT_VIRTUAL_DEV_OPTICAL_DISK.
   sImagePath :            [out] A pointer to a buffer that
                           receives the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnImagePathBufLength :  [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetImagePath, (
		PRL_HANDLE hVmDev,
		PRL_STR sImagePath,
		PRL_UINT32_PTR pnImagePathBufLength
		) );

/* Sets the virtual device image path.
   Parameters
   hVmDev :         A handle identifying the virtual device. This
                    can be one of the following\:
                    PHT_VIRTUAL_DEV_FLOPPY,
                    PHT_VIRTUAL_DEV_HARD_DISK,
                    PHT_VIRTUAL_DEV_OPTICAL_DISK.
   sNewImagePath :  The image path to set. The value must be a
                    UTF\-8 encoded, null\-terminated string
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetImagePath, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewImagePath
		) );

/* \Returns the virtual device system name.
   Parameters
   hVmDev :              A handle identifying the virtual device.
   sSysName :            [out] A pointer to a buffer that
                         receives the result (a UTF\-8 encoded,
                         null\-terminated string).
   pnSysNameBufLength :  [in] The size of the output buffer (in
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
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetSysName, (
		PRL_HANDLE hVmDev,
		PRL_STR sSysName,
		PRL_UINT32_PTR pnSysNameBufLength
		) );

/* Sets virtual device system name.
   Parameters
   hVmDev :       A handle identifying the virtual device.
   sNewSysName :  The new system name to set. The value must be a
                  UTF\-8 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetSysName, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewSysName
		) );

/* \Returns the virtual device user friendly name.
   Parameters
   hVmDev :                   A handle identifying the virtual
                              device.
   sFriendlyName :            [out] A pointer to a buffer that
                              receives the result (a UTF\-8
                              encoded, null\-terminated string).
   pnFriendlyNameBufLength :  [in] The size of the output buffer
                              (in bytes). Set the buffer pointer
                              to null and this parameter's value
                              to zero to receive the required
                              size. [out] The required output
                              buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetFriendlyName, (
		PRL_HANDLE hVmDev,
		PRL_STR sFriendlyName,
		PRL_UINT32_PTR pnFriendlyNameBufLength
		) );

/* Sets virtual device user-friendly name.
   Parameters
   hVmDev :            A handle identifying the virtual device.
   sNewFriendlyName :  The user\-friendly name to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetFriendlyName, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewFriendlyName
		) );

/* \Returns the description of a specified virtual device.
   Parameters
   hVmDev :                  A handle identifying the virtual
                             device.
   sDescription :            [out] A pointer to a buffer that
                             receives the result (a UTF\-8
                             encoded, null\-terminated string).
   pnDescriptionBufLength :  [in] The size of the output buffer
                             (in bytes). Set the buffer pointer
                             to null and this parameter's value
                             to zero to receive the required
                             size. [out] The required output
                             buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The pnDescriptionBufLength parameter will
   contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDev_SetDescription                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDev_GetDescription, (
		PRL_HANDLE hVmDev,
		PRL_STR sDescription,
		PRL_UINT32_PTR pnDescriptionBufLength
		) );

/* Sets the description for a specified virtual device.
   Parameters
   hVmDev :           A handle identifying the virtual device.
   sNewDescription :  The new description to set. The value must
                      be a UTF\-8 encoded, null\-terminated
                      string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDev_GetDescription                                       */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDev_SetDescription, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewDescription
		) );

/* \Returns the virtual device interface type (IDE or SCSI).
   Parameters
   hVmDev :       A handle identifying the virtual device. This
                  can be one of the following\:
                  PHT_VIRTUAL_DEV_HARD_DISK,
                  PHT_VIRTUAL_DEV_OPTICAL_DISK.
   pnIfaceType :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetIfaceType, (
		PRL_HANDLE hVmDev,
		PRL_MASS_STORAGE_INTERFACE_TYPE_PTR pnIfaceType
		) );

/* Sets the virtual device interface type (IDE or SCSI).
   Parameters
   hVmDev :      A handle identifying the virtual device. This
                 can be one of the following\:
                 PHT_VIRTUAL_DEV_HARD_DISK,
                 PHT_VIRTUAL_DEV_OPTICAL_DISK,
				 PHT_VIRTUAL_DEV_GENERIC_SCSI.
   nIfaceType :  The interface type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or PMS_IDE_DEVICE for PHT_VIRTUAL_DEV_GENERIC_SCSI handle type was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetIfaceType, (
		PRL_HANDLE hVmDev,
		PRL_MASS_STORAGE_INTERFACE_TYPE nIfaceType
		) );

/* \Returns the virtual device subtype.
   Parameters
   hVmDev :       A handle identifying the virtual device. This
                  can be one of the following\:
                  PHT_VIRTUAL_DEV_HARD_DISK,
                  PHT_VIRTUAL_DEV_OPTICAL_DISK.
   pnSubType :  [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmDev_GetSubType, (
		PRL_HANDLE hVmDev,
		PRL_CLUSTERED_DEVICE_SUBTYPE_PTR pnSubType
		) );

/* Sets the virtual device subtype.
   Parameters
   hVmDev :      A handle identifying the virtual device. This
                 can be one of the following\:
                 PHT_VIRTUAL_DEV_HARD_DISK,
                 PHT_VIRTUAL_DEV_OPTICAL_DISK,
				 PHT_VIRTUAL_DEV_GENERIC_SCSI.
   nSubType :  The subtype to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmDev_SetSubType, (
		PRL_HANDLE hVmDev,
		PRL_CLUSTERED_DEVICE_SUBTYPE nSubType
		) );

/* \Returns the virtual device stack index (position at the
   controller (IDE or SCSI) bus).
   Parameters
   hVmDev :        A handle identifying the virtual device. This
                   can be one of the following\:
                   PHT_VIRTUAL_DEV_HARD_DISK,
                   PHT_VIRTUAL_DEV_OPTICAL_DISK,
				   PHT_VIRTUAL_DEV_GENERIC_SCSI,
				   PHT_VIRTUAL_DEV_GENERIC_PCI.
   pnStackIndex :  [out] A pointer to a variable that receives
                   the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetStackIndex, (
		PRL_HANDLE hVmDev,
		PRL_UINT32_PTR pnStackIndex
		) );

/* Sets the virtual device stack index (position at the IDE or
   SCSI controller bus).
   Parameters
   hVmDev :       A handle identifying the virtual device. This
                  can be one of the following\:
                  PHT_VIRTUAL_DEV_HARD_DISK,
                  PHT_VIRTUAL_DEV_OPTICAL_DISK,
				  PHT_VIRTUAL_DEV_GENERIC_SCSI,
				  PHT_VIRTUAL_DEV_GENERIC_PCI.
   nStackIndex :  A new index to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type
   was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetStackIndex, (
		PRL_HANDLE hVmDev,
		PRL_UINT32 nStackIndex
		) );

/* Automatically generates and assigns a stack index to a
   virtual device (a corresponding device interface, IDE or
   SCSI, has to be set in advance).
   Parameters
   hVmDev :  A handle identifying the virtual device. This can be
             one of the following\: PHT_VIRTUAL_DEV_HARD_DISK,
             PHT_VIRTUAL_DEV_OPTICAL_DISK, PHT_VIRTUAL_DEV_GENERIC_SCSI
			 or PHT_VIRTUAL_DEV_GENERIC_PCI.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type
   was passed.

   PRL_ERR_NO_MORE_FREE_INTERFACE_SLOTS - there are no free
   slots left.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetDefaultStackIndex, (
		PRL_HANDLE hVmDev
		) );

/* \Returns the virtual device output file.
   Parameters
   hVmDev :                 A handle identifying the virtual
                            device. This can be one of the
                            following\:
                            PHT_VIRTUAL_DEV_PARALLEL_PORT,
                            PHT_VIRTUAL_DEV_SERIAL_PORT.
   sOutputFile :            [out] A pointer to a buffer that
                            receives the result (a UTF\-8
                            encoded, null\-terminated string).
   pnOutputFileBufLength :  [in] The size of the output buffer
                            (in bytes). Set the buffer pointer to
                            null and this parameter's value to
                            zero to receive the required size.
                            [out] The required output buffer
                            size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_GetOutputFile, (
		PRL_HANDLE hVmDev,
		PRL_STR sOutputFile,
		PRL_UINT32_PTR pnOutputFileBufLength
		) );

/* Sets the virtual device output file.
   Parameters
   hVmDev :          A handle identifying the virtual device.
                     This can be one of the following\:
                     PHT_VIRTUAL_DEV_PARALLEL_PORT,
                     PHT_VIRTUAL_DEV_SERIAL_PORT.
   sNewOutputFile :  Name and path of the new output file.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type,
   or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetOutputFile, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewOutputFile
		) );

/* Determines if the passthrough mode is enabled for the
   specified mass storage device.
   Parameters
   hVmDev :         A handle identifying the device. This can be
                    one of the following\:
                    PHT_VIRTUAL_DEV_OPTICAL_DISK,
                    PHT_VIRTUAL_DEV_HARD_DISK.
   pbPassthrough :  [out] A pointer to a variable that receives
                    the result. PRL_TRUE indicates that the
                    passthrough mode is enabled. PRL_FALSE
                    indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_IsPassthrough, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbPassthrough
		) );

/* Enables the passthrough mode for the specified mass storage
   device (optical ot hard disk).
   Parameters
   hVmDev :        A handle identifying the device. This can be
                   one of the following\:
                   PHT_VIRTUAL_DEV_OPTICAL_DISK,
                   PHT_VIRTUAL_DEV_HARD_DISK.
   bPassthrough :  Specify PRL_TRUE to enable the passthrough
                   mode. Specify PRL_FALSE to disab;e it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or invalid handle type
   was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDev_SetPassthrough, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bPassthrough
		) );


/* \Returns the hard disk type. A virtual hard disk can be one
   of two types: expanding or fixed. The size of an expanding
   hard disk is expanded dynamically up to a predefined limit.
   The size of a fixed hard disk is set to the specified value
   at the time of creation.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pnDiskType :  [out] Pointer to a variable that receives the
                 disk type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_SetDiskType                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_GetDiskType, (
		PRL_HANDLE hVmDev,
		PRL_HARD_DISK_INTERNAL_FORMAT_PTR pnDiskType
		) );

/* Sets the type of the specified virtual hard disk. A virtual
   hard disk can be one of the two types: expanding or
   fixed-size. The size of an expanding hard disk is expanded
   dynamically up to a predefined limit. The size of a
   fixed-size hard disk is set to the specified value at the
   time of creation. The function can be used with both new and
   existing virtual hard disks.
   Parameters
   hVmDev :     A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                identifying the virtual hard disk.
   nDiskType :  The hard disk type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetDiskType                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_SetDiskType, (
		PRL_HANDLE hVmDev,
		PRL_HARD_DISK_INTERNAL_FORMAT nDiskType
		) );

/* Determines if the virtual hard disk is split into multiple
   files. When adding a virtual hard disk to a virtual machine,
   you have an option of splitting the disk into multiple files.
   By using this function, you can determine whether this
   options was used or not.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pbSplitted :  [out] Pointer to a variable that receives the
                 \result. PRL_TRUE indicates that the disk is
                 split into multiple files. PRL_FALSE indicates
                 that a single file is used.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_SetSplitted                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_IsSplitted, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbSplitted
		) );

/* Allows to specify whether the hard disk should be split into
   multiple files or if a single file should be used.
   Parameters
   hVmDev :     A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                identifying the virtual hard disk.
   bSplitted :  Hard disk file option. Specify PRL_TRUE to split
                the disk into multiple files. Specify PRL_FALSE
                to use a single file.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_IsSplitted                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_SetSplitted, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bSplitted
		) );

/* \Returns the hard disk size.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pnDiskSize :  [out] Pointer to a variable that receives the
                 hard disk size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_SetDiskSize                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_GetDiskSize, (
		PRL_HANDLE hVmDev,
		PRL_UINT32_PTR pnDiskSize
		) );

/* Sets the size of the specified virtual hard disk. Use this
   function when adding a new virtual hard disk or when
   modifying the size of an existing disk.
   Parameters
   hVmDev :     A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                identifying the virtual hard disk.
   nDiskSize :  The new size in megabytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetDiskSize                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_SetDiskSize, (
		PRL_HANDLE hVmDev,
		PRL_UINT32 nDiskSize
		) );

/* \Returns the size of the occupied space on the hard disk.
   Parameters
   hVmDev :        A valid handle of type
                   PHT_VIRTUAL_DEV_HARD_DISK identifying the
                   virtual hard disk.
   pnOnDiskSize :  [out] Pointer to a variable that receives the
                   size. The size is specified in bytes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevHd_GetSizeOnDisk, (
		PRL_HANDLE hVmDev,
		PRL_UINT32_PTR pnOnDiskSize
		) );

/* Assigns a boot camp partition to the specified virtual hard
   disk. When creating a virtual machine based on a boot camp
   partition, this function must be used to obtain a handle of
   type PHT_VIRTUAL_DEV_HD_PARTITION. The handle can then be
   used to set the system name of the boot camp partition that
   you would like to use.
   Parameters
   hVmDev :       A valid handle of type
                  PHT_VIRTUAL_DEV_HARD_DISK identifying the
                  virtual hard disk.
   phPartition :  [out] A pointer to a variable that receives a
                  handle of type PHT_VIRTUAL_DEV_HD_PARTITION
                  containing the new partition information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHd_AddPartition, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE_PTR phPartition
		) );

/* Determines the number of partitions on the virtual hard disk.
   Parameters
   hVmDev :             A valid handle of type
                        PHT_VIRTUAL_DEV_HARD_DISK identifying the
                        virtual hard disk.
   pnPartitionsCount :  [out] A pointer to a variable that
                        receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetPartition                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHd_GetPartitionsCount, (
		 PRL_HANDLE hVmDev,
		 PRL_UINT32_PTR pnPartitionsCount
		 ) );

/* Obtains a handle of type PHT_VIRTUAL_DEV_HD_PARTITION
   containing information about the specified partition of the
   virtual hard disk.
   Parameters
   hVmDev :       A valid handle of type
                  PHT_VIRTUAL_DEV_HARD_DISK identifying the
                  virtual hard disk.
   nIndex :       An index identifying the partition instance
                  (beginning with 0). To get the number of
                  partitions of the virtual hard disk, use the
                  PrlVmDevHd_GetPartitionsCount function.
   phPartition :  [out] A pointer to a variable that receives the
                  handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed, or device index out of bound.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_GetPartitionsCount                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHd_GetPartition, (
		 PRL_HANDLE hVmDev,
		 PRL_UINT32 nIndex,
		 PRL_HANDLE_PTR phPartition
		 ) );

/* Lets to setup password for virtual hard disk device in case if last
   one is encrypted (this password uses then at calls PrlVmDevHd_CheckPassword
   and PrlVm_Commit)
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   sPasswd :     [in] Setting password - an UTF-8 encoded string with null
                 \0 symbol at the end. In case to specify an empty password
		 just pass 0 or "".
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_CheckPassword
   PrlVm_Commit                                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevHd_SetPassword, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sPassword
		) );

/* Returns sign whether virtual hard disk device is encrypted. You can use
   PrlVmDev_UpdateInfo call in order to request information about virtual
   hard disk device remotely.
   Parameters
   hVmDev :      A valid handle of type PHT_VIRTUAL_DEV_HARD_DISK
                 identifying the virtual hard disk.
   pbIsEncrypted : [out] buffer to retrieve result.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHd_CheckPassword
   PrlVmDev_UpdateInfo
   PrlVm_Commit                                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevHd_IsEncrypted, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbIsEncrypted
		) );

/* Checks whether specified for encrypted virtual hard disk
   password matched to the current one.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - can be returned in follow cases:
                         invalid handle (NULL or not of
                         PHT_VIRTUAL_DEV_HARD_DISK type)
                         was passed; virtual hard disk
                         device object isn't bound to any
                         VM object (was created with
                         PrlVmDev_Create call for example);
                         PrlVmDevHd_SetPassword wasn't called
                         before this call - nothing to check
                         then.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVmDev :         A handle of type PHT_VIRTUAL_DEV_HARD_DISK
                    identifying the virtual hard disk object.
   nFlags :  		Bitset of flags - reserved parameter for
                    further purposes.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_3,
				PrlVmDevHd_CheckPassword, (
					  PRL_HANDLE hVmDev,
					  PRL_UINT32 nFlags
					  ) );


/* \Returns the virtual hard disk online compact mode.
   Parameters
   hVmDev :  A handle identifying the virtual hard disk.
   pnMode :  [out] A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				 PrlVmDevHd_GetOnlineCompactMode, (
		PRL_HANDLE hVmDev,
		PRL_ONLINE_COMPACT_MODE_PTR pnMode
		) );

/* Sets the virtual hard disk online compact mode.
   Parameters
   hVmDev :  A handle identifying the virtual hard disk.
   nMode  :  The mode to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
				 PrlVmDevHd_SetOnlineCompactMode, (
		PRL_HANDLE hVmDev,
		PRL_ONLINE_COMPACT_MODE nMode
		) );

/* Removes the specified partition handle from the virtual hard
   disk list.
   Parameters
   hPartition :  A handle identifying the partition.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHdPart_Remove, (
		PRL_HANDLE hPartition
		) );

/* \Returns the system name of the specified disk partition.
   Parameters
   hPartition :          A handle of type
                         PHT_VIRTUAL_DEV_HD_PARTITION identifying
                         the disk partition.
   sSysName :            [out] A pointer to a buffer that
                         receives the name (a UTF\-8 encoded,
                         null\-terminated string).
   pnSysNameBufLength :  [in] The size of the output buffer (in
                         bytes). Set the buffer pointer to null
                         and this value to zero to receive the
                         required size. [out] The required output
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
   PrlVmDevHdPart_SetSysName                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHdPart_GetSysName, (
		PRL_HANDLE hPartition,
		PRL_STR	sSysName,
		PRL_UINT32_PTR pnSysNameBufLength
		) );

/* Sets system name for the specified disk partition.
   Parameters
   hPartition :  A handle of type PHT_VIRTUAL_DEV_HD_PARTITION
                 identifying the disk partition.
   sSysName :    A system name to set for the partition.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevHdPart_GetSysName                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevHdPart_SetSysName, (
		PRL_HANDLE hPartition,
		PRL_CONST_STR sSysName
		) );

/* \Returns the index of the adapter to which the specified
   virtual adapter is bound. In a bridged networking mode, a
   network adapter inside a virtual machine is bound to an
   adapter on the host. This function allows to retrieve the
   index of the adapter from the host.
   Parameters
   hVmDev :   A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
              identifying the virtual network adapter.
   pnIndex :  [out] A pointer to a variable that receives the
              index. A returned value of \-1 (negative one)
              indicates that the virtual network adapter is bound
              to the default adapter on the host.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetBoundAdapterIndex                               */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_GetBoundAdapterIndex, (
		PRL_HANDLE hVmDev,
		PRL_INT32_PTR pnIndex
		) );

/* Sets the index of the adapter to which the specified virtual
   adapter should be bound. In a bridged networking mode, a
   network adapter inside a virtual machine is bound to an
   adapter on the host. This function allows to set the index of
   the adapter from the host.
   Parameters
   hVmDev :  A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
             identifying the virtual network adapter.
   nIndex :  The index of the adapter to which the specified
             virtual adapter should be bound. If you would like
             to bind the virtual adapter to the default adapter,
             specify \-1 (negative one).
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   net VM device handle or handle of already removed net VM
   device was passed PRL_ERR_SUCCESS - operation successfully
   completed
   See Also
   PrlVmDevNet_GetBoundAdapterIndex                              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_SetBoundAdapterIndex, (
		PRL_HANDLE hVmDev,
		PRL_INT32 nIndex
		) );

/* \Returns the name of the adapter to which the specified
   virtual adapter is bound. In a bridged networking mode, a
   network adapter inside a virtual machine is bound to an
   adapter on the host. This function allows to retrieve the
   name of the adapter from the host.
   Parameters
   hVmDev :                       A handle of type
                                  PHT_VIRTUAL_DEV_NET_ADAPTER
                                  identifying the virtual network
                                  adapter.
   sBoundAdapterName :            [out] Pointer to a buffer that
                                  receives the physical adapter
                                  name (a UTF\-8 encoded,
                                  null\-terminated string).
   pnBoundAdapterNameBufLength :  [in] The size of the output
                                  buffer (in bytes). Set the
                                  buffer pointer to null and this
                                  value to zero to receive the
                                  required size. [out] The
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
   PrlVmDevNet_SetBoundAdapterName                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_GetBoundAdapterName, (
		PRL_HANDLE hVmDev,
		PRL_STR sBoundAdapterName,
		PRL_UINT32_PTR pnBoundAdapterNameBufLength
		) );

/* Sets the name of the network adapter to which a virtual
   network adapter inside a virtual machine will bind. In a
   bridged networking mode, a network adapter inside a virtual
   machine is bound to an adapter on the host. This function
   allows to set the name of the adapter to bind to.
   Parameters
   hVmDev :                A handle of type
                           PHT_VIRTUAL_DEV_NET_ADAPTER
                           identifying the virtual network
                           adapter.
   sNewBoundAdapterName :  The name of the adapter to bind to.
                           The adapter must exist on the host. To
                           get the names of the available
                           adapters from the host, use the
                           PrlSrvCfg_GetNetAdapter function.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetBoundAdapterName                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_SetBoundAdapterName, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewBoundAdapterName
		) );

/* \Returns the MAC address of a virtual network adapter inside
   a virtual machine (in Parallels format XXXXXXXXXXXX).
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sMacAddress :            [out] Pointer to a buffer that
                            receives the MAC address (a UTF\-8
                            encoded, null\-terminated string).
   pnMacAddressBufLength :  [in] The size of the output buffer
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
   PrlVmDevNet_GetMacAddressCanonical,
   PrlVmDevNet_SetMacAddress                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_GetMacAddress, (
		PRL_HANDLE hVmDev,
		PRL_STR sMacAddress,
		PRL_UINT32_PTR pnMacAddressBufLength
		) );

/* \Returns the MAC address of a virtual network adapter inside
   a virtual machine (in human-friendly format xx:xx:xx:xx:xx:xx).
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sMacAddress :            [out] Pointer to a buffer that
                            receives the MAC address (a UTF\-8
                            encoded, null\-terminated string).
   pnMacAddressBufLength :  [in] The size of the output buffer
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
   PrlVmDevNet_SetMacAddress                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVmDevNet_GetMacAddressCanonical, (
		PRL_HANDLE hVmDev,
		PRL_STR sMacAddress,
		PRL_UINT32_PTR pnMacAddressBufLength
		) );


/* Allows to manually set MAC address to a network adapter
   inside a virtual machine. Use this function if you would like
   to set a specific MAC address to an adapter. To generate an
   address and to set it to an adapter automatically, use the
   PrlVmDevNet_GenerateMacAddr function.
   Parameters
   hVmDev :          A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
                     identifying the virtual network adapter.
   sNewMacAddress :  The new MAC address. The specified string
                     must be encoded using UTF\-8 and must be
                     terminated with a binary zero character. The
                     MAC address value cannot contain any
                     delimiters. The following is an example of a
                     valid MAC address\: "001731EE6FBC".
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetMacAddress                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_SetMacAddress, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewMacAddress
		) );

/* Generates a unique MAC address for a virtual network adapter
   on a virtual machine. The function will generate a new MAC
   address and will automatically assign it to the adapter. The
   function does not return the address to the caller. To
   retrieve the address, use the PrlVmDevNet_GetMacAddress
   function.
   Parameters
   hVmDev :  A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
             identifying the network adapter.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevNet_GenerateMacAddr, (
		PRL_HANDLE hVmDev
		) );

/* Determines if the specified network adapter is configured
   to automatically apply network settings inside guest.
   Parameters
   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
                          identifying the virtual network
                          adapter.
   pbAutoApply :  [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that the adapter is configured to automatically
                          apply network settings. PRL_FALSE indicates
                          otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_IsAutoApply, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbAutoApply
		) );

/* Allows to specify whether a network adapter in a virtual
   machine should be automatically configured. Note:
   For these changes to take effect, Parallels Tools must be
   installed in a target virtual machine.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   bAutoApply :  Specify PRL_TRUE to configure the
                         adapter automatically. Specified
                         PRL_FALSE to configure the network
                         settings manually in a virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetAutoApply, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bAutoApply
		) );

/* Obtains a list of IP addresses in the address/subnet_mask
   format which is assigned to a virtual network adapter on
   virtual machine startup.

   \Returns the list of pairs "IP address/Subnet mask" which
   will be applied to the network adapter on the guest OS side
   (on guest start or immediately on config commit if guest
   already working and Parallels tools with necessary
   functionality are installed). The result will be returned as
   list of strings (PHT_STRINGS_LIST type) of pairs "IP
   address/Subnet mask".
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   phNetAddressesList :  [out] A pointer to the PHT_STRINGS_LIST
                         handle containing the IP addresses.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate strings
   list object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetNetAddresses                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_GetNetAddresses, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE_PTR phNetAddressesList
		) );

/* Allows to manually set IP addresses/Subnet masks to a network
   adapter in a virtual machine. <b>Note</b>: For these changes
   to take effect, Parallels Tools must be installed in the target
   virtual machine, and its network adapter settings should be
   configured to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :             A handle of type
                        PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                        the virtual network adapter.
   hNetAddressesList :  A handle of type PHT_STRINGS_LIST
                        containing the list of "IP address/Subnet
                        mask" pairs to be applied to the network
                        adapter. Can be PRL_INVALID_HANDLE if
                        it's necessary to specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAutoApply					*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetNetAddresses, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE hNetAddressesList
		) );


/* Obtains the list of DNS servers which is assigned to a
   virtual network adapter on virtual machine startup.
   Parameters
   hVmDev :            A handle of type
                       PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                       the virtual network adapter.
   phDnsServersList :  [out] A pointer to the PHT_STRINGS_LIST
                       handle that receives the list of DNS
                       servers.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate strings
   list object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetDnsServers                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_GetDnsServers, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE_PTR phDnsServersList
		) );

/* Allows to manually assign DNS servers to a network adapter in
   a virtual machine. <b>Note</b>: For these changes to take
   effect, Parallels Tools must be installed in the target virtual
   machine, and its network adapter settings should be configured
   to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :           A handle of type
                      PHT_VIRTUAL_DEV_NET_ADAPTER identifying the
                      virtual network adapter.
   hDnsServersList :  A handle of type PHT_STRINGS_LIST
                      containing the list of DNS servers to be
                      assigned to the network adapter. Can be
                      PRL_INVALID_HANDLE if it's necessary to
                      specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAutoApply					*/
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetDnsServers, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE hDnsServersList
		) );


/* Obtains a lists of search domains which are assigned to a
   virtual network adapter on virtual machine startup.
   Parameters
   hVmDev :               A handle of type
                          PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                          the virtual network adapter.
   phSearchDomainsList :  [out] A pointer to the PHT_STRINGS_LIST
                          handle containing the results.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to allocate strings
   list object.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetSearchDomains                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_GetSearchDomains, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE_PTR phSearchDomainsList
		) );

/* Allows to manually assign search domains to a network adapter
   in a virtual machine. <b>Note</b>: For these changes to take
   effect, Parallels Tools must be installed in the target virtual
   machine, and its network adapter settings should be configured
   to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   hSearchDomainsList :  A handle of type PHT_STRINGS_LIST
                         containing the list of search domains to
                         be assigned to the network adapter. Can
                         be PRL_INVALID_HANDLE iif it's necessary
                         to specify an empty list.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network
   adapter specified.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAutoApply                            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetSearchDomains, (
		PRL_HANDLE hVmDev,
		PRL_HANDLE hSearchDomainsList
		) );


/* Determines if the specified network adapter is configured
   through DHCP on the guest OS side.
   Parameters
   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
                          identifying the virtual network
                          adapter.
   pbConfigureWithDhcp :  [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that the adapter is configured through
                          DHCP. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_IsConfigureWithDhcp, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbConfigureWithDhcp
		) );

/* Allows to specify whether a network adapter in a virtual
   machine should be configured through DHCP or manually. Note:
   For these changes to take effect, Parallels Tools must be
   installed in the target virtual machine, and its network adapter
   settings should be configured to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   bConfigureWithDhcp :  Specify PRL_TRUE to configure the
                         adapter through DHCP. Specified
                         PRL_FALSE to configure the network
                         settings manually.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAutoApply				            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetConfigureWithDhcp, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bConfigureWithDhcp
		) );


/* Determines if the specified network adapter is configured
   through DHCP (IPv6) on the guest OS side.
   Parameters
   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
                          identifying the virtual network
                          adapter.
   pbConfigureWithDhcp :  [out] A pointer to a variable that
                          receives the result. PRL_TRUE indicates
                          that the adapter is configured through
                          DHCP. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                  */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_IsConfigureWithDhcpIPv6, (
		PRL_HANDLE hVmDev,
		PRL_BOOL_PTR pbConfigureWithDhcp
		) );

/* Allows to specify whether a network adapter in a virtual
   machine should be configured through DHCP (IPv6) or manually. Note:
   For these changes to take effect, Parallels Tools must be
   installed in the target virtual machine, and its network adapter
   settings should be configured to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   bConfigureWithDhcp :  Specify PRL_TRUE to configure the
                         adapter through DHCP. Specified
                         PRL_FALSE to configure the network
                         settings manually.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAutoApply				            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_SetConfigureWithDhcpIPv6, (
		PRL_HANDLE hVmDev,
		PRL_BOOL bConfigureWithDhcp
		) );


/* Obtains the default gateway assigned to a virtual network
   adapter in a virtual machine.
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sDefaultGateway :        [out] A pointer to a buffer that
                            receives the default gateway address
                            (a UTF\-8 encoded, null\-terminated
                            string).
   pnDefaultGatewayBufLength :  [in] The size of the output buffer
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
   PrlVmDevNet_SetDefaultGateway                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_GetDefaultGateway, (
		PRL_HANDLE hVmDev,
		PRL_STR sDefaultGateway,
		PRL_UINT32_PTR pnDefaultGatewayBufLength
		) );

/* Allows to manually set the default gateway address for a
   network adapter in a virtual machine. <b>Note</b>: For these
   changes to take effect, Parallels Tools must be installed in
   the target virtual machine, and its network adapter settings
   should be configured to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   sNewDefaultGateway :  The new default gateway address. The
                         specified string must be encoded using
                         UTF\-8 and must be terminated with the
                         binary zero character.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetDefaultGateway
   PrlVmDevNet_SetAutoApply                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmDevNet_SetDefaultGateway, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewDefaultGateway
		) );


/* Obtains the default gateway (IPv6) assigned to a virtual network
   adapter in a virtual machine.
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sDefaultGateway :        [out] A pointer to a buffer that
                            receives the default gateway address
                            (a UTF\-8 encoded, null\-terminated
                            string).
   pnDefaultGatewayBufLength :  [in] The size of the output buffer
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
   PrlVmDevNet_SetDefaultGateway                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_GetDefaultGatewayIPv6, (
		PRL_HANDLE hVmDev,
		PRL_STR sDefaultGateway,
		PRL_UINT32_PTR pnDefaultGatewayBufLength
		) );

/* Allows to manually set the default gateway address (IPv6) for a
   network adapter in a virtual machine. <b>Note</b>: For these
   changes to take effect, Parallels Tools must be installed in
   the target virtual machine, and its network adapter settings
   should be configured to change automatically.

   If the changes are applied to a stopped virtual machine, they
   will take effect the next time the machine is started. If the
   changes are applied to a running virtual machine, they will
   take effect on configuration changes commit.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   sNewDefaultGateway :  The new default gateway address. The
                         specified string must be encoded using
                         UTF\-8 and must be terminated with the
                         binary zero character.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetDefaultGateway
   PrlVmDevNet_SetAutoApply                                 */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmDevNet_SetDefaultGatewayIPv6, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewDefaultGateway
		) );




	/* Determines if the specified network adapter is configured
	   to filter net packages and send packages only from its own MAC address.

	   Parameters
	   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
				  identifying the virtual network
				  adapter.
	   pbPktFilterPreventMacSpoof :  [out] A pointer to a variable that
				  receives the result. PRL_TRUE indicates that adapter
				  is allowed to send packages only from its own MAC address.
				  PRL_FALSE indicates  otherwise.
	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.                  */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlVmDevNet_IsPktFilterPreventMacSpoof, (
			PRL_HANDLE hVmDev,
			PRL_BOOL_PTR pbPktFilterPreventMacSpoof
			) );

	/* Allows to specify whether a network adapter in a virtual
	   machine should filter packets through MAC address spoofing.

	   Parameters
	   hVmDev :              A handle of type
				 PHT_VIRTUAL_DEV_NET_ADAPTER identifying
				 the virtual network adapter.
	   bPktFilterPreventMacSpoof :  Specify PRL_TRUE to send packages
				 only from its own MAC address. Specify
				 PRL_FALSE to turn off filtration.

	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.            */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlVmDevNet_SetPktFilterPreventMacSpoof, (
			PRL_HANDLE hVmDev,
			PRL_BOOL bPktFilterPreventMacSpoof
			) );

	/* Determines if the specified network adapter is configured
	   to receive packets sent not to VM.

	   Parameters
	   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
				  identifying the virtual network
				  adapter.
	   pbPktFilterPreventPromisc :  [out] A pointer to a variable that
				  receives the result. PRL_TRUE indicates
				  that adapter is confured to prevent to
				  to receive packets sent not to VM.
				  PRL_FALSE indicates  otherwise.
	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.                  */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_IsPktFilterPreventPromisc , (
			PRL_HANDLE hVmDev,
			PRL_BOOL_PTR pbPktFilterPreventPromisc
			) ) ;

	/* Allows to specify whether a network adapter in a virtual
	   machine should receive packets sent not to VM.

	   Parameters
	   hVmDev :              A handle of type
				 PHT_VIRTUAL_DEV_NET_ADAPTER identifying
				 the virtual network adapter.
	   bPktFilterPreventPromisc :  Specify PRL_TRUE to prevent VM to receive
				 packets that were sent not to VM. Specify
				 PRL_FALSE to switch off filtration.

	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.            */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_SetPktFilterPreventPromisc, (
			PRL_HANDLE hVmDev,
			PRL_BOOL bPktFilterPreventPromisc
			) );

	/* Determines if the specified network adapter is configured
	   to filter net packages and send packages only from IP addresses in the
	   adapter NetAdrresses list.

	   Parameters
	   hVmDev :               A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
				  identifying the virtual network
				  adapter.
	   pbPktFilterPreventMacSpoof :  [out] A pointer to a variable that
				  receives the result. PRL_TRUE indicates that adapter
				  is allowed to send packages only from IP addresses in the
				  adapter NetAdrresses list.
				  PRL_FALSE indicates  otherwise.
	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.                  */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_IsPktFilterPreventIpSpoof, (
			PRL_HANDLE hVmDev,
			PRL_BOOL_PTR pbPktFilterPreventIpSpoof
			) );

	/* Allows to specify whether a network adapter in a virtual
	   machine should perform the filtration by IP addresses.

	   Parameters
	   hVmDev :              A handle of type
				 PHT_VIRTUAL_DEV_NET_ADAPTER identifying
				 the virtual network adapter.
	   bPktFilterPreventMacSpoof :  Specify PRL_TRUE to send packages
				 only from addresses in the adapter NetAdrresses
				 list. Specify PRL_FALSE to switch off filtration.

	   Returns
	   PRL_RESULT. Possible values:

	   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	   passed.

	   PRL_ERR_SUCCESS - function completed successfully.            */
	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_SetPktFilterPreventIpSpoof, (
			PRL_HANDLE hVmDev,
			PRL_BOOL bPktFilterPreventIpSpoof
			) );

/* Obtain  the adapter type assigned to a virtual network adapter.

   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   pnAdapterType :	    [out] A pointer to a buffer that
                            receives the adapter type
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_SetAdapterType                                  */

	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_GetAdapterType, (
			PRL_HANDLE hVmDev,
			PRL_VM_NET_ADAPTER_TYPE_PTR pnAdapterType
			) );


/* Allows to manually assign adapter type to a network adapter.

   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_NET_ADAPTER identifying
                         the virtual network adapter.
   nAdapterType :	 The new network adapter type.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevNet_GetAdapterType                                   */

	PRL_METHOD_DECL( PARALLELS_API_VER_3,
					  PrlVmDevNet_SetAdapterType, (
			PRL_HANDLE hVmDev,
			PRL_VM_NET_ADAPTER_TYPE nAdapterType
			) );

/* Obtains the custom host adapter name.
   Parameters
   hVmDev :                 A handle of type
                            PHT_VIRTUAL_DEV_NET_ADAPTER
                            identifying the virtual network
                            adapter.
   sHostInterfaceName :     [out] A pointer to a buffer that
                            receives the name
                            (a UTF\-8 encoded, null\-terminated
                            string).
   pnDefaultGatewayBufLength :  [in] The size of the output buffer
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

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
		PrlVmDevNet_GetHostInterfaceName, (
			PRL_HANDLE hVmDev,
			PRL_STR sHostInterfaceName,
			PRL_UINT32_PTR pnHostInterfaceNameBufLength
			) );

/* Sets the custom host adapter name in a bridged networking mode,
   (autogenerated if not set)
   hVmDev :  A handle of type PHT_VIRTUAL_DEV_NET_ADAPTER
             identifying the virtual network adapter.
   sNewHostInterfaceName : Host interface name.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.     */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
		PrlVmDevNet_SetHostInterfaceName, (
			PRL_HANDLE hVmDev,
			PRL_CONST_STR sNewHostInterfaceName
			) );


/* Obtains USB controller autoconnect device option.
   Parameters
   hVmDev :               A handle of type
                          PHT_VIRTUAL_DEV_USB_DEVICE identifying
                          the USB device.
   pnAutoconnectOption :  [out] A pointer to a variable that
                          receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevUsb_SetAutoconnectOption                              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevUsb_GetAutoconnectOption, (
		PRL_HANDLE hVmDev,
		PRL_USB_DEVICE_AUTO_CONNECT_OPTION_PTR pnAutoconnectOption
		) );

/* Sets USB controller autoconnect device option.
   Parameters
   hVmDev :              A handle of type
                         PHT_VIRTUAL_DEV_USB_DEVICE identifying
                         the USB device.
   nAutoconnectOption :  Autoconnect option to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevUsb_GetAutoconnectOption                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevUsb_SetAutoconnectOption, (
		PRL_HANDLE hVmDev,
		PRL_USB_DEVICE_AUTO_CONNECT_OPTION nAutoconnectOption
		) );

/* \Returns the virtual sound device emulation type. Emulation
	types are defined in the PRL_VM_DEV_EMULATION_TYPE
	enumeration.
	PDT_USE_INTEL_HDA_SOUND (Intel HDA),
	PDT_USE_AC97_SOUND (AC'97),
	PDT_USE_CREATIVE_SB16_SOUND (Creative).
	Parameters
	hVmDev :          A handle identifying the virtual device.
	pnEmulatedType :  [out] A pointer to a variable that receives
					  the result.
	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	passed.

	PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmDevSound_GetAdvancedType, (
		PRL_HANDLE hVmDev,
		PRL_VM_DEV_EMULATION_TYPE_PTR pnnAdvancedTypeType
		) );

/* Sets the specified virtual sound device emulation type. Emulation
	types are defined in the PRL_VM_DEV_EMULATION_TYPE
	enumeration.
	PDT_USE_INTEL_HDA_SOUND (Intel HDA),
	PDT_USE_AC97_SOUND (AC'97),
	PDT_USE_CREATIVE_SB16_SOUND (Creative).
	Parameters
	hVmDev :         A handle identifying the virtual device.
	nEmulatedType :  The emulation type to set.
					Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer was
	passed.

	PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlVmDevSound_SetAdvancedType, (
		PRL_HANDLE hVmDev,
		PRL_VM_DEV_EMULATION_TYPE nAdvancedType
		) );

/* \Returns output device string for the specified sound device.
   Parameters
   hVmDev :                A handle of type PHT_VIRTUAL_DEV_SOUND
                           identifying the sound device.
   sOutputDev :            [out] A pointer to a buffer that
                           receives the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnOutputDevBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSound_SetOutputDev                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSound_GetOutputDev, (
		PRL_HANDLE hVmDev,
		PRL_STR sOutputDev,
		PRL_UINT32_PTR pnOutputDevBufLength
		) );

/* Sets output device string for the specified sound device.
   Parameters
   hVmDev :         A handle of type PHT_VIRTUAL_DEV_SOUND
                    identifying the sound device.
   sNewOutputDev :  \Output device string to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSound_GetOutputDev                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSound_SetOutputDev, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewOutputDev
		) );

/* \Returns mixer device string for the specified sound device.
   Parameters
   hVmDev :               A handle of type PHT_VIRTUAL_DEV_SOUND
                          identifying the sound device.
   sMixerDev :            [out] A pointer to a buffer that
                          receives the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnMixerDevBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSound_SetMixerDev                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSound_GetMixerDev, (
		PRL_HANDLE hVmDev,
		PRL_STR sMixerDev,
		PRL_UINT32_PTR pnMixerDevBufLength
		) );

/* Sets mixer device string for the specified sound device.
   Parameters
   hVmDev :        A handle of type PHT_VIRTUAL_DEV_SOUND
                   identifying the sound device.
   sNewMixerDev :  Mixer device string to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSound_GetMixerDev                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSound_SetMixerDev, (
		PRL_HANDLE hVmDev,
		PRL_CONST_STR sNewMixerDev
		) );

/* \Returns the socket mode of a virtual serial port. Use this
   function to get the socket mode when the emulation type of
   the port is "socket". To get the port's emulation type, use
   the PrlVmDev_GetEmulatedType function.
   Parameters
   hVmDev :        A handle of type PHT_VIRTUAL_DEV_SERIAL_PORT
                   identifying the serial port.
   pnSocketMode :  [out] Pointer to a variable that receives the
                   socket mode.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSerial_SetSocketMode                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSerial_GetSocketMode, (
		PRL_HANDLE hVmDev,
		PRL_SERIAL_PORT_SOCKET_OPERATION_MODE_PTR pnSocketMode
		) );

/* Sets the socket mode for a virtual serial port. Use this
   function to set the socket mode when the emulation type of
   the port is "socket". To get the port's emulation type, use
   the PrlVmDev_GetEmulatedType function.
   Parameters
   hVmDev :       A handle of type PHT_VIRTUAL_DEV_SERIAL_PORT
                  identifying the serial port.
   nSocketMode :  The socket mode emulation type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVmDevSerial_GetSocketMode                                */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmDevSerial_SetSocketMode, (
		PRL_HANDLE hVmDev,
		PRL_SERIAL_PORT_SOCKET_OPERATION_MODE nSocketMode
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section VM shared folders operations
///////////////////////////////////////////////////////////////////////////////

/* Removes the share from the virtual machine configuration.
   Once a share is removed from the virtual machine
   configuration, the folder cannot be accessed from the guest
   OS. Just like any other virtual machine configuration
   modification, this operation must be performed within the
   PrlVm_BeginEdit / PrlVm_Commit block.
   Parameters
   hVmShare :  A handle of type PHT_SHARE identifying the shared
               folder.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_Remove, (
		PRL_HANDLE hVmShare
		) );

/* \Returns the shared folder name (as it appears in the guest
   OS).
   Parameters
   hVmShare :              A handle of type PHT_SHARE identifying
                           the shared folder.
   sShareName :            [out] A pointer to a buffer that
                           receives the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnShareNameBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_SetName                                               */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_GetName, (
		PRL_HANDLE hVmShare,
		PRL_STR sShareName,
		PRL_UINT32_PTR pnShareNameBufLength
		) );

/* Sets the share name (as it will appear in the guest OS).
   Parameters
   hVmShare :       A handle of type PHT_SHARE identifying the
                    shared folder.
   sNewShareName :  The user\-defined share name (must be a a
                    UTF\-8 encoded, null\-terminated string).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_GetName                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_SetName, (
		PRL_HANDLE hVmShare,
		PRL_CONST_STR sNewShareName
		) );

/* \Returns the shared folder path.
   Parameters
   hVmShare :              A handle of type PHT_SHARE identifying
                           the shared folder.
   sSharePath :            [out] A pointer to a buffer that
                           receives the result (a UTF\-8 encoded,
                           null\-terminated string).
   pnSharePathBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_SetPath                                               */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_GetPath, (
		PRL_HANDLE hVmShare,
		PRL_STR sSharePath,
		PRL_UINT32_PTR pnSharePathBufLength
		) );

/* Sets the shared folder path.
   Parameters
   hVmShare :       A handle of type PHT_SHARE identifying the
                    shared folder.
   sNewSharePath :  A string containing an absolute path to the
                    folder on the host that you would like to
                    share with the guest OS ( must be a UTF\-8
                    encoded, null\-terminated string).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_GetPath                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_SetPath, (
		PRL_HANDLE hVmShare,
		PRL_CONST_STR sNewSharePath
		) );

/* \Returns the shared folder description.
   Parameters
   hVmShare :                     A handle of type PHT_SHARE
                                  identifying the shared folder.
   sShareDescription :            [out] A pointer to a buffer
                                  that receives the result (a
                                  UTF\-8 encoded, null\-terminated
                                  string).
   pnShareDescriptionBufLength :  [in] The size of the output
                                  buffer (in bytes). Set the
                                  buffer pointer to null and this
                                  parameter's value to zero to
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
   PrlShare_SetDescription                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_GetDescription, (
		PRL_HANDLE hVmShare,
		PRL_STR sShareDescription,
		PRL_UINT32_PTR pnShareDescriptionBufLength
		) );

/* Sets the shared folder description.
   Parameters
   hVmShare :              A handle of type PHT_SHARE identifying
                           the shared folder.
   sNewShareDescription :  A user\-defined share description
                           (must be a UTF\-8 encoded,
                           null\-terminated string).
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_GetDescription                                        */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_SetDescription, (
		PRL_HANDLE hVmShare,
		PRL_CONST_STR sNewShareDescription
		) );

/* Determines whether the share is enabled or not.
   Parameters
   hVmShare :   A handle of type PHT_SHARE identifying the shared
                folder.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the share is
                enabled. PRL_FALSE indicates that it is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_SetEnabled                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_IsEnabled, (
		PRL_HANDLE hVmShare,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables the specified share.
   Parameters
   hVmShare :  A handle of type PHT_SHARE identifying the shared
               folder.
   bEnabled :  Specify PRL_TRUE to enable the share. Specified
               PRL_FALSE to disable it. If a share is disabled,
               it cannot be accessed from the guest OS.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_IsEnabled                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_SetEnabled, (
		PRL_HANDLE hVmShare,
		PRL_BOOL bEnabled
		) );

/* Determines if the share is read-only.
   Parameters
   hVmShare :    A handle of type PHT_SHARE identifying the
                 shared folder.
   pbReadOnly :  [out] A pointer to a variable that receives the
                 \result. PRL_TRUE indicates that the share is
                 read\-only (files can be read and copied but not
                 modified). PRL_FALSE indicates that the folder
                 contents can be modified.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_SetReadOnly                                           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_IsReadOnly, (
		PRL_HANDLE hVmShare,
		PRL_BOOL_PTR pbReadOnly
		) );

/* Makes the specified shared folder read-only.
   Parameters
   hVmShare :   A handle of type PHT_SHARE identifying the shared
                folder.
   bReadOnly :  Specify PRL_TRUE to make the share read\-only.
                Specify PRL_FALSE to make the share editable.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlShare_IsReadOnly                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlShare_SetReadOnly, (
		PRL_HANDLE hVmShare,
		PRL_BOOL bReadOnly
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section VM screen resolutions operations
///////////////////////////////////////////////////////////////////////////////

/* Removes the specified screen resolution from the virtual
   machine.
   Parameters
   handle :  A handle of type PHT_SCREEN_RESOLUTION identifying
             the screen resolution.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_Remove, (
		PRL_HANDLE hVmScrRes
		) );

/* Determines whether the screen resolution is enabled or not.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION
                identifying the screen resolution.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the screen
                resolution is enabled. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_IsEnabled, (
		PRL_HANDLE hVmScrRes,
		PRL_BOOL_PTR pbEnabled
		) );

/* Enables or disables the specified screen resolution.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION identifying
                the screen resolution.
   bEnabled :   Action type. Set to PRL_TRUE to enable the
                resolution. Set to PRL_FALSE to disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_SetEnabled, (
		PRL_HANDLE hVmScrRes,
		PRL_BOOL bEnabled
		) );

/* \Returns width of the specified screen resolution.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION
                identifying the screen resolution.
   pnWidth :    [out] A pointer to a variable that receives the
                screen resolution width, in pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_GetWidth, (
		PRL_HANDLE hVmScrRes,
		PRL_UINT32_PTR pnWidth
		) );

/* Modifies the specified screen resolution width.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION
                identifying the screen resolution.
   nWidth :     The screen resolution width to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_SetWidth, (
		PRL_HANDLE hVmScrRes,
		PRL_UINT32 nWidth
		) );

/* \Returns the height of the specified screen resolution.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION
                identifying the screen resolution.
   pnHeight :   [out] A pointer to a variable that receives the
                screen resolution height, in pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_GetHeight, (
		PRL_HANDLE hVmScrRes,
		PRL_UINT32_PTR pnHeight
		) );

/* Modifies the specified screen resolution height.
   Parameters
   hVmScrRes :  A handle of type PHT_SCREEN_RESOLUTION identifying
                the screen resolution.
   nHeight :    The screen resolution height to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlScrRes_SetHeight, (
		PRL_HANDLE hVmScrRes,
		PRL_UINT32 nHeight
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section VM boot devices operations
///////////////////////////////////////////////////////////////////////////////

/* Removes the boot device from the boot priority list. This
   function permanently removes a devices from the list. If you
   would like to temporarily disable a device, use the
   PrlBootDev_SetInUse function. To add a device back to the
   list, use PrlVmCfg_CreateBootDev and then call the necessary
   functions of the PHT_BOOT_DEVICE handle to set the necessary
   properties.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or the device has been
   removed from the boot list.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_Remove, (
		PRL_HANDLE hVmBootDev
		) );

/* \Returns the boot device type. Device type is a property
   that, together with device index, is used to uniquely
   identify a device in the virtual machine boot list. The
   supported device types are defined in the PRL_DEVICE_TYPE
   enumeration.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   pnDevType :   [out] A pointer to a variable that receives the
                 device type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_SetType                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_GetType, (
		PRL_HANDLE hVmBootDev,
		PRL_DEVICE_TYPE_PTR pnDevType
		) );

/* Sets the boot device type. Use this function when adding a
   device to the boot device priority list. Device type is a
   property that, together with device index, is used to
   uniquely identify a device in a virtual machine boot list.
   When adding a device to the boot priority list, these
   properties must be set correctly or the device will not be
   recognized. The supported device types are defined in the
   PRL_DEVICE_TYPE enumeration.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   nDevType :    The device type to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or the device has been
   removed from the boot list.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_GetType                                             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_SetType, (
		PRL_HANDLE hVmBootDev,
		PRL_DEVICE_TYPE nDevType
		) );

/* Obtains the boot device index. Device index is a property
   that, together with device type, is used to uniquely identify
   a device in the boot priority list of a virtual machine. The
   index should be the same index the device has in the main
   virtual machine configuration, which is determined using the
   PrlVmDev_GetIndex function.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   pnDevIndex :  [out] A pointer to a variable that receives the
                 device index.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_SetIndex                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_GetIndex, (
		PRL_HANDLE hVmBootDev,
		PRL_UINT32_PTR pnDevIndex
		) );

/* Sets the boot device index. Device index is a property that,
   together with device type, is used to uniquely identify a
   device in the virtual machine boot priority list. The index
   must be the same index the device has in the main virtual
   machine configuration or it will not be recognized during the
   boot procedure. To obtain a virtual device index from the
   virtual machine configuration, use the PrlVmDev_GetIndex
   function.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   nDevIndex :   The index of the device of interest as it exists
                 in the virtual machine configuration.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or the device has been
   removed from the boot list.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_GetIndex                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_SetIndex, (
		PRL_HANDLE hVmBootDev,
		PRL_UINT32 nDevIndex
		) );

/* Obtains the boot device sequence index. The boot device
   sequence index starts with 0. When a virtual machine is
   powered on, it will first try to boot from the boot device
   that has a sequence index of 0. If it cannot boot from the
   device, it will try to boot from the device with sequence
   index 1, and so forth.
   Parameters
   hVmBootDev :       A handle of type PHT_BOOT_DEVICE
                      identifying the boot device.
   pnSequenceIndex :  [out] A pointer to a variable that receives
                      the device sequence index.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_SetSequenceIndex                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_GetSequenceIndex, (
		PRL_HANDLE hVmBootDev,
		PRL_UINT32_PTR pnSequenceIndex
		) );

/* Assigns a sequence index to a boot device in the boot
   priority list. The boot device sequence index starts with 0.
   When a virtual machine is powered on, it will first try to
   boot from the boot device that has a sequence index of 0. If
   it cannot boot from the device, it will try to boot from the
   device with sequence index 1, and so forth.

   If you are changing a sequence index for an existing device,
   this is the only function that you have to call. If you are
   adding a new boot device to the list, you will have to set
   all the other properties, including the device index, type,
   and enabled/disabled flag. Please note that each device in
   the boot priority list must have a unique sequence index, so
   if you are modifying a sequence index for an existing device
   or assigning an index to a new device, you will have to make
   sure that no two devices have the same index.
   Parameters
   hVmBootDev :      A handle of type PHT_BOOT_DEVICE identifying
                     the boot device.
   nSequenceIndex :  The boot sequence index to set for the
                     device. The value of 0 (zero) is the highest
                     boot priority and indicates the first device
                     to boot from. The value of 1 (one) indicates
                     the second device to boot from, and so
                     forth.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or the device has been
   removed from the boot list.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_GetSequenceIndex                                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_SetSequenceIndex, (
		PRL_HANDLE hVmBootDev,
		PRL_UINT32 nSequenceIndex
		) );

/* Determines whether the boot device is enabled or disabled. A
   boot device can be either enabled or disabled. If a device is
   disabled, it is ignored during the boot operation. To change
   the status of a device, use the PrlBootDev_SetInUse function.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   pbInUse :     [out] Pointer to a variable that receives the
                 \result PRL_TRUE indicates that the device is
                 enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_SetInUse                                            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_IsInUse, (
		PRL_HANDLE hVmBootDev,
		PRL_BOOL_PTR pbInUse
		) );

/* Enables or disables the boot device. A boot device can be
   enabled or disabled without being removed from the boot
   device priority list. If the device is disabled, it is
   ignored during the boot operation. To obtain the current
   status of a device, use the PrlBootDev_IsInUse function. To
   permanently remove a device from the list, use the
   PrlBootDev_Remove function.
   Parameters
   hVmBootDev :  A handle of type PHT_BOOT_DEVICE identifying the
                 boot device.
   bInUse :      A boolean value specifying the action type.
                 PRL_TRUE enables a device, PRL_FALSE disables
                 it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or the device has been
   removed from the boot list.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlBootDev_IsInUse

   PrlBootDev_Remove                                              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlBootDev_SetInUse, (
		PRL_HANDLE hVmBootDev,
		PRL_BOOL bInUse
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the virtual machine device (mouse)
///////////////////////////////////////////////////////////////////////////////

/* Sends absolute or relative mouse event with specified
   parameters within the virtual machine display coordinate grid.
   Absolute event can only be sent if Parallels Tools package is
   installed in the target virtual machine and if Sliding Mouse
   feature is enabled. To find out if Sliding Mouse is enabled,
   use the PrlDevDisplay_IsSlidingMouseEnabled function.
   Parameters
   hObj :     A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   mouse :    Mouse event parameters.
   size :     Parameters structure size.
   absolute : Whether event location is absolute.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlDevMouse_Event, (
		PRL_HANDLE hObj,
		const PRL_IO_MOUSE_EVENT_EX4 * mouse,
		PRL_UINT32 size,
		PRL_BOOL absolute
		) );

/* Moves a mouse pointer to the specified absolute position
   within the virtual machine display coordinate grid and sends
   a mouse event (presses or releases the specified button).
   This function can only be used if Parallels Tools package is
   installed in the target virtual machine and if Sliding Mouse
   feature is enabled. To find out if Sliding Mouse is enabled,
   use the PrlDevDisplay_IsSlidingMouseEnabled function.
   Parameters
   hVm :      A handle of type of PHT_VIRTUAL_MACHINE identifying
              the machine.
   x :        X coordinate to move the mouse pointer to.
   y :        Y coordinate to move the mouse pointer to.
   z :        Z coordinate to mouse pointer to (scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevMouse_SetPos, (
		PRL_HANDLE hVm,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_UINT32 buttons
		) );

/* Moves a mouse pointer to a relative position and sends a
   mouse event (presses or releases the specified button). This
   function can only be used if Parallels Tools are NOT
   installed in the target virtual machine. The position to
   which you want to move the pointer is always calculated
   relatively to the center of the screen (as if the center had
   coordinates X=0; Y=0). When a virtual machine powers up, the
   cursor in it is automatically positioned at the center of the
   screen. To move the cursor to the desired absolute
   coordinates within the virtual machine screen coordinate
   grid, calculate the offset of the destination point
   relatively to the center of the virtual machine screen and
   pass those values to this function as X and Y coordinates.
   Use positive values when moving the cursor right or down, use
   negative values when moving the cursor left or up.
   Parameters
   hVm :      A handle of type of PHT_VIRTUAL_MACHINE identifying
              the machine.
   x :        X coordinate offset.
   y :        Y coordinate offset.
   z :        Z coordinate offset (scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevMouse_Move, (
		PRL_HANDLE hVm,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_UINT32 buttons
		) );

/* Moves a mouse pointer to the specified absolute position
   within the virtual machine display coordinate grid and sends
   a mouse event (presses or releases the specified button).
   This function can only be used if Parallels Tools package is
   installed in the target virtual machine and if Sliding Mouse
   feature is enabled. To find out if Sliding Mouse is enabled,
   use the PrlDevDisplay_IsSlidingMouseEnabled function.
   Parameters
   hObj :     A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   x :        X coordinate to move the mouse pointer to.
   y :        Y coordinate to move the mouse pointer to.
   z :        Z coordinate to mouse pointer to (scroll).
   w :        W coordinate to mouse pointer to (h-scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlDevMouse_SetPosEx, (
		PRL_HANDLE hObj,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_INT32 w,
		PRL_UINT32 buttons
		) );

/* Moves a mouse pointer to a relative position and sends a
   mouse event (presses or releases the specified button). This
   function can only be used if Parallels Tools are NOT
   installed in the target virtual machine. The position to
   which you want to move the pointer is always calculated
   relatively to the center of the screen (as if the center had
   coordinates X=0; Y=0). When a virtual machine powers up, the
   cursor in it is automatically positioned at the center of the
   screen. To move the cursor to the desired absolute
   coordinates within the virtual machine screen coordinate
   grid, calculate the offset of the destination point
   relatively to the center of the virtual machine screen and
   pass those values to this function as X and Y coordinates.
   Use positive values when moving the cursor right or down, use
   negative values when moving the cursor left or up.
   Parameters
   hVm :      A handle of type of PHT_VIRTUAL_MACHINE identifying
              the machine.
   x :        X coordinate offset.
   y :        Y coordinate offset.
   z :        Z coordinate offset (scroll).
   w :        W coordinate offset (h-scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlDevMouse_MoveEx, (
		PRL_HANDLE hVm,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_INT32 w,
		PRL_UINT32 buttons
		) );

/* Moves a mouse pointer to the specified absolute position
   within the virtual machine display coordinate grid and sends
   a mouse event (presses or releases the specified button).
   This function can only be used if Parallels Tools package is
   installed in the target virtual machine and if Sliding Mouse
   feature is enabled. To find out if Sliding Mouse is enabled,
   use the PrlDevDisplay_IsSlidingMouseEnabled function.
   Parameters
   hObj :     A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   x :        X coordinate to move the mouse pointer to.
   y :        Y coordinate to move the mouse pointer to.
   z :        Z coordinate to mouse pointer to (scroll).
   w :        W coordinate to mouse pointer to (h-scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_HANDLE. Handle on sending operation */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlDevMouse_AsyncSetPos, (
		PRL_HANDLE hObj,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_INT32 w,
		PRL_UINT32 buttons
		) );

/* Moves a mouse pointer to a relative position and sends a
   mouse event (presses or releases the specified button). This
   function can only be used if Parallels Tools are NOT
   installed in the target virtual machine. The position to
   which you want to move the pointer is always calculated
   relatively to the center of the screen (as if the center had
   coordinates X=0; Y=0). When a virtual machine powers up, the
   cursor in it is automatically positioned at the center of the
   screen. To move the cursor to the desired absolute
   coordinates within the virtual machine screen coordinate
   grid, calculate the offset of the destination point
   relatively to the center of the virtual machine screen and
   pass those values to this function as X and Y coordinates.
   Use positive values when moving the cursor right or down, use
   negative values when moving the cursor left or up.
   Parameters
   hVm :      A handle of type of PHT_VIRTUAL_MACHINE identifying
              the machine.
   x :        X coordinate offset.
   y :        Y coordinate offset.
   z :        Z coordinate offset (scroll).
   w :        W coordinate offset (h-scroll).
   buttons :  Mouse button identifier. See the PRL_MOUSE_BUTTON
              enumeration for available choices. The values can
              be combined using the binary OR operator |. To
              press a button, specify the value identifying the
              button. To release a button, specify PMB_NOBUTTON.
              To move the mouse pointer without pressing any
              buttons, specify PMB_NOBUTTON.
   Returns
   PRL_HANDLE. Handle on sending operation */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlDevMouse_AsyncMove, (
		PRL_HANDLE hVm,
		PRL_INT32 x,
		PRL_INT32 y,
		PRL_INT32 z,
		PRL_INT32 w,
		PRL_UINT32 buttons
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the virtual machine device (keyboard)
///////////////////////////////////////////////////////////////////////////////

/* Sends a keyboard key event to a virtual machine. To send a
   single key-pressed event, first call this function passing
   the desired key code and PKE_PRESS as the event type. Then
   call the function again passing the same key code and
   PKE_RELEASE as the event type. To send a key combination
   event, first call the function passing the code of the first
   key (usually a modifier key, such as Ctrl, Shift, Alt) and
   PKE_PRESS as the event type. Then call the function passing
   the code of the second key with PKE_PRESS. Continue with
   other keys (if more than two). Then call the function in
   reverse order for each key passing PKE_RELEASE as the event
   type.
   Parameters
   hVm :  A handle of type of PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   key :  Key code. See the PrlKeys.h file for the list of the
          available key codes.
   ev :   Event type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevKeyboard_SendKeyEvent, (
		PRL_HANDLE hVm,
		PRL_UINT32 key,
		PRL_KEY_EVENT ev
		) );

/* Sends a keyboard key event to a virtual machine. To send a
   single key-pressed event, first call this function passing
   the desired key code and PKE_PRESS as the event type. Then
   call the function again passing the same key code and
   PKE_RELEASE as the event type. To send a key combination
   event, first call the function passing the code of the first
   key (usually a modifier key, such as Ctrl, Shift, Alt) and
   PKE_PRESS as the event type. Then call the function passing
   the code of the second key with PKE_PRESS. Continue with
   other keys (if more than two). Then call the function in
   reverse order for each key passing PKE_RELEASE as the event
   type.
   Parameters
   hVm :  A handle of type of PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   key :  Key code. See the PrlKeys.h file for the list of the
          available key codes.
   ev :   Event type.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDevKeyboard_SendKeyEventEx, (
		PRL_HANDLE		hVm,
		PRL_KEY	key,
		PRL_KEY_EVENT	ev
		) );

/* Sends a keyboard key pressed and released to a virtual machine.
   Parameters
   hVm :  A handle of type of PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   key :  Key code. See the PrlKeys.h file for the list of the
          available key codes.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDevKeyboard_SendKeyPressedAndReleased, (
		PRL_HANDLE		hVm,
		PRL_KEY	key
		) );

/* Sends a keyboard optimization mode to a virtual machine.
	Parameters
	hVm :  A handle of type of PHT_VIRTUAL_MACHINE identifying the virtual machine.
	mode :  optimization mode, see PRL_OPTIMIZE_MODIFIERS_MODE for possible modes.
	Returns
	PRL_RESULT. Possible values:

	PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

	PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				PrlDevKeyboard_SendOptimizationMode, (
		PRL_HANDLE hVm,
		PRL_OPTIMIZE_MODIFIERS_MODE mode
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the virtual machine device (display)
///////////////////////////////////////////////////////////////////////////////

/* Connects to a virtual machine to begin a remote desktop
   access session. This function must be called before any other
   function calls related to the remote desktop access
   functionality.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   type :  Codec type to be used during the remote desktop screen
           capture. If server supports display encodings
		   (use #PrlSrv_GetDisplayEncodingList)
		   your can use encoding type (PRL_IO_DISPLAY_ENCODING.encodingType)
		   instead of PRL_DISPLAY_CODEC_TYPE enum.
		   Note:
		   use this call to receive supported server display encodings:
             PrlSrv_GetDisplayEncodingList
		   also you can receive or change display encoding at runtime:
             PrlDevDisplay_SetDisplayEncoding
             PrlDevDisplay_GetDisplayEncoding
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlDevDisplay_ConnectToVm, (
		PRL_HANDLE hObj,
		PRL_DISPLAY_CODEC_TYPE type
		) );

/* Connects to a virtual machine to begin a remote desktop
   access session. This function must be called before any other
   function calls related to the remote desktop access
   functionality.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   pEnc :  Codec type to be used during the remote desktop screen
           capture. If server supports display encodings
		   (use #PrlSrv_GetDisplayEncodingList)
		   your can use pointer to encoder.
		   Note:
		   use this call to receive supported server display encodings:
             PrlSrv_GetDisplayEncodingList
		   also you can receive or change display encoding at runtime:
             PrlDevDisplay_SetDisplayEncoding
             PrlDevDisplay_GetDisplayEncoding
   format : Conversion format of inner display screen buffer. If conversion
            format is not supported by SDK error will be returned
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation
   PRL_INVALID_HANDLE if there's not enough memory to instantiate the job object
   PRL_ERR_DISPLAY_FORMAT_NOT_SUPPORTED if specified format is not supported
 */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_4,
						   PrlDevDisplay_ConnectToVmEx, (
		PRL_HANDLE hObj,
		const PRL_IO_DISPLAY_ENCODING_PTR pEnc,
		PRL_DISPLAY_BUFFER_FORMAT format
		) );


/* Closes the virtual machine connection that was previously
   established using the PrlDevDisplay_ConnectToVm function
   call.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_DisconnectFromVm, (
		PRL_HANDLE hObj
		) );

/* \Sets display encoding for specified Vm.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   pEnc :  Encoding description. Use #PrlSrv_GetDisplayEncodingList
          to have a list of supported encodings.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - specified encoding exists, request has been successfully
   sent to server. Encoding will be changed in few moments.

   PRL_ERR_DISPLAY_ENCODINGS_NOT_SUPPORTED - display encodings are not supported
   on server, connection is local or remote connection does not exist anymore.

   PRL_ERR_FAILURE - sending operation of encoding request has been failed.

   PRL_ERR_INVALID_ARG - pEnc pointer is wrong or hVm does not exist.*/
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDevDisplay_SetDisplayEncoding, (
		PRL_HANDLE hObj,
		const PRL_IO_DISPLAY_ENCODING_PTR pEnc
		) );

/* \Gets current encoding of specified Vm.
   Parameters
   hObj :     A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   pOutEnc :  Encoding description as out parameter.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - out parameter has been filled with current display encoding.

   PRL_ERR_DISPLAY_ENCODINGS_NOT_SUPPORTED - display encodings are not supported
   on server, connection is local or remote connection does not exist anymore.

   PRL_ERR_INVALID_ARG - pOutEnc pointer is wrong or hVm does not exist.*/
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlDevDisplay_GetDisplayEncoding, (
		PRL_HANDLE hObj,
		PRL_IO_DISPLAY_ENCODING_PTR pOutEnc
		) );


/* \Returns the contents of the screen buffer of the primary
   display. Please note that the primary screen buffer can be
   refreshed at any time from inside the virtual machine. To
   prevent incomplete or corrupt data, use the
   PrlDevDisplay_LockForRead function to temporarily suspend
   refreshing of the screen on the virtual machine side. The
   screen data is always returned as 32-bit RGBA with the alpha
   channel containing the value of 0.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   buffer :    [out] A pointer to a buffer that receives the
               data. The screen data is always returned as 32\-bit
               RGBA with the alpha channel containing the value
               of 0.
   lineSize :  Line size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.              */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_GetScreenBuffer, (
		PRL_HANDLE hObj,
		PRL_UINT32_PTR_PTR buffer,
		PRL_INT32_PTR lineSize
		) );


/* Locks the primary screen buffer disallowing any updates to
   the data it contains. When you obtain a screen capture, you
   should call this function first to prevent all further
   updates to the screen buffer. This is done in order to
   minimize the local machine resource usage, to speed up the
   screen buffer read operations, and to prevent possible data
   loss. To obtain the data from the buffer, use the
   PrlDevDisplay_GetScreenBuffer function. When you are done
   reading the data, call the PrlDevDisplay_Unlock to remove the
   lock.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_LockForRead, (
		PRL_HANDLE hObj
		) );

/* Unlocks the virtual machine screen buffer that was previously
   locked with the PrlDevDisplay_LockForRead function call.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_Unlock, (
		PRL_HANDLE hObj
		) );

/* Determines if Sliding Mouse feature is enabled in the
   specified virtual machine. Sliding Mouse is a feature that
   comes with Parallels Tools package. If Sliding Mouse is
   enabled, the mouse cursor can "slide" from the virtual
   machine desktop to the host OS desktop without pressing any
   of the special keys on the keyboard. This function is used
   when writing remote desktop applications with graphical user
   interfaces. For more information, see the Mouse Control
   section in this chapter.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   flag :  [out] A pointer to a variable that receives the
           \result. PRL_TRUE indicates that sliding mouse is
           enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_IsSlidingMouseEnabled, (
		PRL_HANDLE hObj,
		PRL_BOOL_PTR flag
		) );


/* \Returns the primary display screen size of the specified
   virtual machine.
   Parameters
   hObj :  A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   size :  [out] A pointer to a structure containing the screen
           size properties.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_GetScreenSize, (
		PRL_HANDLE hObj,
		PRL_IO_SCREEN_SIZE_PTR size
		) );


/* Determines whether Dynamic Resolution feature is available in
   the specified virtual machine. Dynamic Resolution is a
   feature that comes with the Parallels Tools package. It
   provides facilities for adjusting the guest OS screen
   resolution on the fly. Use this function to determine whether
   the Dynamic Resolution feature is installed and running. If
   the feature is available, you can use the
   PrlDevDisplay_SendScreenSizeEvent function to
   programmatically adjust the guest OS screen resolution.
   Parameters
   hVm :     A handle of type PHT_VIRTUAL_MACHINE identifying the
             virtual machine.
   status :  [out] A pointer to a variable that receives the
             \result. PRL_TRUE indicates that Dynamic Resolution
             is enabled. PRL_FALSE indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlDevDisplay_GetDynResToolStatus, (
		PRL_HANDLE hVm,
		PRL_BOOL_PTR status
		) );

/* The PrlDevDisplay_NeedCursorData function allows to obtain
   cursor data from the virtual machine. The function sends a
   request to the virtual machine and immediately returns. The
   data is received as a PHT_EVENT handle via callback.
   Parameters
   hVm :  A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_NeedCursorData, (
					  PRL_HANDLE hVm
					  ) );

/* Sends a request to a virtual machine to adjust the screen
   resolution of the guest OS to specified values. The guest OS
   can accept or reject the new resolution depending on
   compatibility factors. The function does not provide
   information on whether the new resolution was accepted or
   not. The PRL_ERR_SECCESS return code means that the function
   didn't fail but it doesn't mean that the screen resolution
   was actually changed. To verify the results of the operation,
   you can capture the guest OS screen before and after
   executing this function and compare the results. You can use
   this function only if the Parallels Tools package is
   installed in the target virtual machine and if the Dynamic
   Resolution feature is turned on. To determine the status of
   the Dynamic Resolution feature, use the PrlDevDisplay_GetDynResToolStatus
   function.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   size :  The new screen resolution parameters.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.                        */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_SendScreenSizeEvent, (
		PRL_HANDLE hVm,
		const PRL_IO_SCREEN_SIZE_PTR size
		) );

/* Sends a request to a virtual machine to set guest display
   configuration to specified values. The guest OS can accept or
   reject the new resolution depending on compatibility factors.
   The function does not provide information on whether the new
   resolution was accepted or not. The PRL_ERR_SECCESS return code
   means that the function didn't fail but it doesn't mean that the
   screen resolution was actually changed. To verify the results
   of the operation, you can capture the guest OS screen before
   and after executing this function and compare the results.
   You can use this function only if the Parallels Tools package
   is installed in the target virtual machine and if the Dynamic
   Resolution feature is turned on. To determine the status of
   the Dynamic Resolution feature, use the
   PrlDevDisplay_GetDynResToolStatus function.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   size :  Array of display configurations for all guest displays
           that will be enabled.
   nCount: Count of displays in array.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevDisplay_SetConfiguration, (
		PRL_HANDLE hVm,
		const PRL_IO_DISPLAY_SCREEN_SIZE_PTR displays,
		PRL_INT32 nCount
		) );


/* Sends a request to a virtual machine to set guest DPI display
   configuration to specified values. The guest OS can accept or
   reject the new resolution depending on compatibility factors.
   The function does not provide information on whether the new
   resolution was accepted or not. The PRL_ERR_SECCESS return code
   means that the function didn't fail but it doesn't mean that the
   screen resolution was actually changed. To verify the results
   of the operation, you can capture the guest OS screen before
   and after executing this function and compare the results.
   You can use this function only if the Parallels Tools package
   is installed in the target virtual machine and if the Dynamic
   Resolution feature is turned on. To determine the status of
   the Dynamic Resolution feature, use the
   PrlDevDisplay_GetDynResToolStatus function.
   Parameters
   hVm :   A handle of type PHT_VIRTUAL_MACHINE identifying the
           virtual machine.
   displays :  Array of DPI display configurations for all guest displays
           that will be enabled.
   nCount: Count of displays in array.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlDevDisplay_SetDpiConfiguration, (
		PRL_HANDLE hVm,
		const PRL_IO_DPI_DISPLAY_SCREEN_SIZE_PTR displays,
		PRL_INT32 nCount
		) );


/* Sends a request to capture the specified screen region of the
   specified virtual machine on a periodic basis. The screen
   data is received as an event via callback every time the
   specified screen region data is modified. This function is
   used when an efficient optimization of the screen update on
   the client side is needed.
   Parameters
   hObj :   A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   pRect :  \Parameters of the screen region to capture. If
            negative rectangle is passed, cancellation request
            will be send.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_SendCaptureScreenRequest, (
		PRL_HANDLE hObj,
		const PRL_IO_SCREEN_REGION_PTR pRect
		) );


/* Captures a screen area of a remote virtual machine desktop,
   scales is down to the specified size, and puts it into a
   buffer. For local connections, the capture works almost
   instantly. For remote connections, the data must be
   transferred over network to the client machine, so it may
   take some time.

   To obtain a pointer to a buffer containing the image, use the
   PrlJob_GetDataPtr function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the screen area to capture, in
                  pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlDevDisplay_SyncCaptureScaledScreenRegionToBuffer            */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlDevDisplay_AsyncCaptureScaledScreenRegionToBuffer, (
		PRL_HANDLE hVm,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a remote virtual machine desktop,
   scales is down to the specified size, and puts it into a
   buffer which is then returned to the client. For local
   connections, the capture works almost instantly. For remote
   connections, the data must be transferred over network to the
   client machine, so it may take some time. This synchronous
   function is an equivalent of the asynchronous function
   PrlDevDisplay_AsyncCaptureScaledScreenRegionToBuffer. You can
   use either function in your programs depending on your
   application needs.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   buff :         [out] A pointer to a buffer containing the
                  screen data. The buffer must be freed with
                  PrlBuffer_Free when no longer needed.
   buffSize :     The size of the buffer received in the buff
                  parameter (above).
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the area to capture, in pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDevDisplay_AsyncCaptureScaledScreenRegionToBuffer           */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_SyncCaptureScaledScreenRegionToBuffer, (
		PRL_HANDLE hVm,
		PRL_VOID_PTR_PTR buff,
		PRL_UINT32_PTR buffSize,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a remote virtual machine desktop
   and saves it to a file on the client machine. For local
   connections, the capture works almost instantly. For remote
   connections, the data must be transferred over network to the
   client machine, so it may take some time.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :       A handle of type PHT_VIRTUAL_MACHINE identifying
               the virtual machine.
   fileName :  Name and path of the file to save the image to.
   format :    Image format to use.
   quality :   Image quality factor. Must be in the range from 0
               to 100, or \-1. Specify 0 to use the highest data
               compression, 100 for no compression, and \-1 for
               default.
   x :         The X coordinate of the upper-left corner of the
               screen area to capture.
   y :         The Y coordinate of the upper-left corner of the
               screen area to capture.
   width :     The width of the screen area to capture, in
               pixels.
   height :    The height of the screen area to capture, in
               pixels.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlDevDisplay_SyncCaptureScreenRegionToFile                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlDevDisplay_AsyncCaptureScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height
		) );

/* Captures a screen area of a remote virtual machine desktop
   and saves it to a file on the client machine. For local
   connections, the capture works almost instantly. For remote
   connections, the data must be transferred over network to the
   client machine, so it may take some time. This synchronous
   function is an equivalent of the asynchronous function
   PrlDevDisplay_AsyncCaptureScreenRegionToFile. You can use
   either function in your programs depending on your
   application needs.
   Parameters
   hVm :       A handle of type PHT_VIRTUAL_MACHINE identifying
               the virtual machine.
   fileName :  Name and path of the file to save the image to.
   format :    Image format to use.
   quality :   Image quality factor. Must be in the range from 0
               to 100, or \-1. Specify 0 to use the highest data
               compression, 100 for no compression, and \-1 for
               default.
   x :         The X coordinate of the upper-left corner of the area
               to capture.
   y :         The Y coordinate of the upper-left corner of the area
               to capture.
   width :     The width of the area to capture, in pixels.
   height :    The height of the area to capture, in pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDevDisplay_AsyncCaptureScreenRegionToFile                      */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_SyncCaptureScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height
		) );

/* Captures a screen area of a remote virtual machine desktop,
   scales is down to the specified size, and saves it to a file
   on the client machine. For local connections, the capture
   works almost instantly. For remote connections, the data must
   be transferred over network to the client machine, so it may
   take some time.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   fileName :     Name and path of the file to save the image to.
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the screen area to capture, in
                  pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlDevDisplay_SyncCaptureScreenRegionToFile                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlDevDisplay_AsyncCaptureScaledScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a remote virtual machine desktop,
   scales is down to the specified size, and saves it to a file
   on the client machine. For local connections, the capture
   works almost instantly. For remote connections, the data must
   be transferred over network to the client machine, so it may
   take some time. This synchronous function is an equivalent of
   the asynchronous function
   PrlDevDisplay_AsyncCaptureScreenRegionToFile. You can use
   either function in your programs depending on your
   application needs.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   fileName :     Name and path of the file to save the image to.
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the area to capture.
   width :        The width of the area to capture, in pixels.
   height :       The height of the area to capture, in pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlDevDisplay_AsyncCaptureScreenRegionToFile                   */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					 PrlDevDisplay_SyncCaptureScaledScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Returns available displays count of a
remote virtual machine desktop. Parallells Tools must
be installed for retreive real displays count.
Parameters
hVm :			A handle of type PHT_VIRTUAL_MACHINE
identifying the virtual machine.
pDisplaysCount:	Refrence to variable that will receive
available display count. 0  will be returned if information
about displays is not available or Parallels Tools is
not started.
Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - invalid handle or null pointer was
passed.
PRL_ERR_UNINITIALIZED - the library was not initialized.
PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					PrlDevDisplay_GetAvailableDisplaysCount, (
		PRL_HANDLE hVm,
		PRL_UINT32_PTR pDisplaysCount
	 ) );


PRL_SRV_METHOD_DECL( PARALLELS_API_VER_3,
					 PrlDevDisplay_SetScreenSurface, (
		PRL_HANDLE hVm,
		PRL_UINT32 n1,
		PRL_UINT32 n2,
		PRL_UINT32 n3,
		PRL_INT32  n4,
		PRL_INT32  n5,
		PRL_UINT32 n6,
		PRL_UINT32 n7
		) );


/* \Returns the contents of the screen buffer of the secondary
   display. Please note that the primary screen buffer can be
   refreshed at any time from inside the virtual machine. To
   prevent incomplete or corrupt data, use the
   PrlDevDisplay_LockForRead function to temporarily suspend
   refreshing of the screen on the virtual machine side. The
   screen data is always returned as 32-bit RGBA with the alpha
   channel containing the value of 0.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   display :   Display ID (0 for primary display, 1, 2, etc.)
   buffer :    [out] A pointer to a buffer that receives the
               screen data. The screen data is always returned as
               32\-bit RGBA with the alpha channel containing the
               value of 0.
   lineSize :  [out] Line size.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
                                                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDevSecondaryDisplay_GetScreenBuffer, (
		PRL_HANDLE hObj,
		PRL_UINT32 display,
		PRL_UINT32_PTR_PTR buffer,
		PRL_INT32_PTR lineSize
		) );

/* \Returns the contents of the screen buffer of the secondary
   display and mapping handle on Windows host (on Unix host
   hMapping parameter will be always equal to buffer).
   Please note that the primary screen buffer can be
   refreshed at any time from inside the virtual machine. To
   prevent incomplete or corrupt data, use the
   PrlDevDisplay_LockForRead function to temporarily suspend
   refreshing of the screen on the virtual machine side. The
   screen data is always returned as 32-bit RGBA with the alpha
   channel containing the value of 0.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   display :   Display ID (0 for primary display, 1, 2, etc.)
   buffer :    [out] A pointer to a buffer that receives the
               screen data. The screen data is always returned as
               32\-bit RGBA with the alpha channel containing the
               value of 0.
   screenSize: [out] Screen size.
   hMapping :  [out] Windows: a handle on screen memory mapping.
               Unix: ignored.
   mapOffset:  [out] Windows: an offset of screen buffer in mapping
               for specified display. Unix: ignored.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
                                                                  */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDevSecondaryDisplay_GetScreenBufferEx, (
		PRL_HANDLE hObj,
		PRL_UINT32 display,
		PRL_UINT32_PTR_PTR buffer,
		PRL_IO_DISPLAY_SCREEN_SIZE_PTR screenSize,
		PRL_VOID_PTR_PTR hMapping,
		PRL_UINT64_PTR mapOffset
		) );


/* \Returns format of internal screen buffer.
   Parameters
   hObj :      A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   display :   Display ID (0 for primary display, 1, 2, etc.)
   format :    [out] A pointer that receives inner screen buffer
               format
*/

PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlDevSecondaryDisplay_GetScreenBufferFormat, (
		PRL_HANDLE hObj,
		PRL_UINT32 display,
		PRL_DISPLAY_BUFFER_FORMAT_PTR format
		) );


/* \Returns the primary display screen size of the specified
   virtual machine.
   Parameters
   hObj :     A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   display :  Display ID (0 for primary display, 1, 2, 3, etc.)
   size :     [out] A pointer to a structure containing the
              screen size properties.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlDevSecondaryDisplay_GetScreenSize, (
		PRL_HANDLE hObj,
		PRL_UINT32 display,
		PRL_IO_DISPLAY_SCREEN_SIZE_PTR size
		) );


/* Sends a request to capture the specified screen region of the
   secondary display of the specified virtual machine on a
   periodic basis. The screen data is received as an event via
   callback every time the specified screen region data is
   modified. This function is used when an efficient
   optimization of the screen update on the client side is
   needed.
   Parameters
   hObj :   A handle of type PHT_VIRTUAL_MACHINE or PHT_DESKTOP_CONTROL.
   pRect :  \Parameters of the screen region to capture. If
            negative rectangle is passed, cancellation request
            will be send.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevSecondaryDisplay_SendCaptureScreenRequest, (
		PRL_HANDLE hObj,
		const PRL_IO_DISPLAY_SCREEN_REGION_PTR pRect
		) );


/* Captures a screen area of a secondary display of a remote
   virtual machine, scales is down to the specified size, and
   puts it into a buffer. For local connections, the capture
   works almost instantly. For remote connections, the data must
   be transferred over network to the client machine, so it may
   take some time.

   To obtain a pointer to a buffer containing the image, use the
   PrlJob_GetDataPtr function.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   display :      Display ID (0 for primary display, 1, 2, etc.)
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the screen area to capture, in
                  pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlDevSecondaryDisplay_SyncCaptureScaledScreenRegionToBuffer   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlDevSecondaryDisplay_AsyncCaptureScaledScreenRegionToBuffer, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a secondary display of a remote
   virtual machine desktop, scales is down to the specified
   size, and puts it into a buffer which is then returned to the
   client. For local connections, the capture works almost
   instantly. For remote connections, the data must be
   transferred over network to the client machine, so it may
   take some time.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   display :      Display ID (0 for primary display, 1, 2, 3,
                  etc.)
   buff :         [out] A pointer to a buffer containing the
                  screen data. The buffer must be freed with
                  PrlBuffer_Free when no longer needed.
   buffSize :     The size of the buffer received in the buff
                  parameter (above).
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the area to capture, in pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevSecondaryDisplay_SyncCaptureScaledScreenRegionToBuffer, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_VOID_PTR_PTR buff,
		PRL_UINT32_PTR buffSize,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a secondary display of a remote
   virtual machine, scales is down to the specified size, and
   saves it to a file on the client machine. For local
   connections, the capture works almost instantly. For remote
   connections, the data must be transferred over network to the
   client machine, so it may take some time.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible value are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   display :      Display ID (0 for primary display, 1, 2, etc.)
   fileName :     Name and path of the file to save the image to.
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the screen area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the screen area to capture.
   width :        The width of the screen area to capture, in
                  pixels.
   height :       The height of the screen area to capture, in
                  pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, in pixels.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlDevSecondaryDisplay_SyncCaptureScaledScreenRegionToFile     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlDevSecondaryDisplay_AsyncCaptureScaledScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


/* Captures a screen area of a remote virtual machine desktop,
   scales is down to the specified size, and saves it to a file
   on the client machine. For local connections, the capture
   works almost instantly. For remote connections, the data must
   be transferred over network to the client machine, so it may
   take some time.
   Parameters
   hVm :          A handle of type PHT_VIRTUAL_MACHINE
                  identifying the virtual machine.
   display :      Display ID (0 for primary display, 1, 2, 3,
                  etc.)
   fileName :     Name and path of the file to save the image to.
   format :       Image format to use.
   quality :      Image quality factor. Must be in the range from
                  0 to 100, or \-1. Specify 0 to use the highest
                  data compression, 100 for no compression, and
                  \-1 for default.
   x :            The X coordinate of the upper-left corner of
                  the area to capture.
   y :            The Y coordinate of the upper-left corner of
                  the area to capture.
   width :        The width of the area to capture, in pixels.
   height :       The height of the area to capture, in pixels.
   scaleWidth :   The width of the scaled down image, in pixels.
   scaleHeight :  The height of the scaled down image, pixels
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlDevSecondaryDisplay_SyncCaptureScaledScreenRegionToFile, (
		PRL_HANDLE hVm,
		PRL_UINT32 display,
		PRL_CONST_STR fileName,
		PRL_IMAGE_FORMAT format,
		PRL_INT32 quality,
		PRL_UINT32 x,
		PRL_UINT32 y,
		PRL_UINT32 width,
		PRL_UINT32 height,
		PRL_UINT32 scaleWidth,
		PRL_UINT32 scaleHeight
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Parallels Remote Audio functions
///////////////////////////////////////////////////////////////////////////////

/* \Starts audio stream from client to Vm.
If client is not connected to vm with #PrlDevDisplay_ConnectToVm call
error will be returned, otherwise start request will be sent, PRL_ERR_SUCCESS
returned and event #PET_IO_AUDIO_STREAM_STARTED with operation status code should
be handled.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Type	: Value from PRL_AUDIO_STREAM_TYPE enumeration selecting play or recording
			  stream type
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio input stream start request has been sent.

   PRL_ERR_FAILURE - send of input start request to Vm has been failed.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect or some pointer is invalid.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm.
   #PrlDevDisplay_ConnectToVm wasn't called.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on the server. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					PrlDevAudio_StartStream, (
		PRL_HANDLE hVm,
		PRL_AUDIO_STREAM_TYPE Type
		) );

/* \Stops audio stream.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Type	: Value from PRL_AUDIO_STREAM_TYPE enumeration selecting play or recording
			  stream type
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio input stream was stopped.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm or audio
   input stream was never started.

   PRL_ERR_AUDIO_ENCODINGS_NOT_SUPPORTED - audio encodings are not supported
   on the server. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					PrlDevAudio_StopStream, (
		PRL_HANDLE hVm,
		PRL_AUDIO_STREAM_TYPE Type
		) );

/* \Set state of the audio switcher.
If client is not connected to vm with #PrlDevDisplay_ConnectToVm call
error will be returned, otherwise start request will be sent, PRL_ERR_SUCCESS
returned.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   bEnabled : new state of switcher as boolean. PRL_TRUE means enabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio input stream start request has been sent.

   PRL_ERR_FAILURE - send of input start request to Vm has been failed.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect or some pointer is invalid.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm.
   #PrlDevDisplay_ConnectToVm wasn't called. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					PrlDevAudio_SetSwitcherState, (
		PRL_HANDLE hVm,
		PRL_BOOL bEnabled
		) );

/* \Get state of the audio switcher from host.
If client is not connected to vm with #PrlDevDisplay_ConnectToVm call
error will be returned, otherwise start request will be sent, PRL_ERR_SUCCESS
returned and event #PET_IO_CLI_GET_AUDIO_SWITCH_SETTINGS_RESPONSE with
operation status code should be handled.
   Parameters
   hVm  : A handle of type PHT_VIRTUAL_MACHINE identifying the
          virtual machine.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_SUCCESS - audio input stream start request has been sent.

   PRL_ERR_FAILURE - send of input start request to Vm has been failed.

   PRL_ERR_INVALID_ARG - Vm handle is incorrect or some pointer is invalid.

   PRL_ERR_UNINITIALIZED - there is no any valid connection to Vm.
   #PrlDevDisplay_ConnectToVm wasn't called. */
PRL_SRV_METHOD_DECL( PARALLELS_API_VER_5,
					PrlDevAudio_GetSwitcherState, (
		PRL_HANDLE hVm
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Parallels Tools Utility functions
///////////////////////////////////////////////////////////////////////////////

/* \Returns the Parallels Tools package state information.
   Parameters
   handle :         A handle of type PHT_VM_TOOLS_INFO.
   pVmToolsState :  [out] A pointer to a variable that receives
                    the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the Parallels Tools package state
   information is not available.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmToolsInfo_GetState, (
		PRL_HANDLE handle,
		PRL_VM_TOOLS_STATE_PTR pVmToolsState
		) );

/* \Returns version information of the Parallels Tools package
   installed in a given virtual machine. Before calling this
   function, make sure that the Parallels Tools package is
   installed in the virtual machine by calling the
   PrlVmToolsInfo_GetState function.
   Parameters
   handle :           A handle of type PHT_VM_TOOLS_INFO.
   sName :            [out] A pointer to a buffer that receives
                      the version information (a UTF\-8 encoded,
                      null\-terminated string).
   pnNameBufLength :  [in] The size of the output buffer (in
                      bytes). Set the buffer pointer to null and
                      this parameter's value to zero to receive
                      the required size. [out] The required
                      \output buffer size.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_NO_DATA - the Parallels Tools package version
   information is not available.

   PRL_ERR_SUCCESS - function completed successfully.            */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmToolsInfo_GetVersion, (
				PRL_HANDLE handle,
				PRL_STR sName,
				PRL_UINT32_PTR pnNameBufLength
				) );


///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the virtual machine info processing
///////////////////////////////////////////////////////////////////////////////

/* \Returns the virtual machine state information.
   Parameters
   handle :    A handle of type PHT_VM_INFO.
   pVmState :  [out] A pointer to a variable that receives the
               virtual machine state information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the virtual machine state information is
   not available.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmInfo_GetState, (
		PRL_HANDLE handle,
		VIRTUAL_MACHINE_STATE_PTR pVmState
		) );

/* \Returns the virtual machine addition state information.
Parameters
handle :    A handle of type PHT_VM_INFO.
pVmState :  [out] A pointer to a variable that receives the
virtual machine addition state information.
Returns
PRL_RESULT. Possible values:

PRL_ERR_INVALID_ARG - invalid handle or null pointer was
passed.

PRL_ERR_NO_DATA - the virtual machine state information is
not available.

PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				PrlVmInfo_GetAdditionState, (
				PRL_HANDLE handle,
				VIRTUAL_MACHINE_ADDITION_STATE_PTR pVmState
				) );

/* Obtains a handle of type PHT_ACCESS_RIGHTS.
   Parameters
   hVmInfo :  A handle of type PHT_VM_INFO.
   phVmAcl :  [out] A pointer to a variable that receives the
              handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create PHT_ACCESS_RIGHTS
   object.

   PRL_ERR_NO_DATA - the virtual machine access rights
   information is not available.

   PRL_ERR_SUCCESS - function completed successfully.                    */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmInfo_GetAccessRights, (
		PRL_HANDLE hVmInfo,
		PRL_HANDLE_PTR phVmAcl
		) );


/* Determines if the specified virtual machine is invalid. A
   virtual machine can be reported as invalid by the function if
   its configuration has been corrupted, it's been removed from
   the virtual machine, and for other similar reasons.
   Parameters
   handle :        A handle of type PHT_VM_INFO.
   pVmIsInvalid :  [out] A pointer to a variable that receives
                   \result. PRL_TRUE \- the virtual machine is
                   invalid. PRL_FALSE \- the virtual machine is
                   fully operational.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the status of the virtual machine cannot be
   determined.

   RL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlVmInfo_IsInvalid, (
				PRL_HANDLE handle,
				PRL_BOOL_PTR pbIsInvalid
				) );


/* Determines if the specified virtual machine is invalid. A
   virtual machine can be reported as invalid by the function if
   its configuration has been corrupted, it's been removed from
   the virtual machine, and for other similar reasons.
   Parameters
   handle :        A handle of type PHT_VM_INFO.
   pVmIsInvalid :  [out] A pointer to a variable that receives
                   \result. PRL_TRUE \- the virtual machine is
                   invalid. PRL_FALSE \- the virtual machine is
                   fully operational.

   pVmInvalidReason:  [out] A pointer to a variable that receives
					reason of invalidity as error code.

   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the status of the virtual machine cannot be
   determined.

   RL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlVmInfo_IsInvalidEx, (
				PRL_HANDLE handle,
				PRL_BOOL_PTR pbIsInvalid,
				PRL_RESULT_PTR pnInvalidReason
				) );

/* Determines if the specified virtual machine is waiting for answer
   on self question.
   Parameters
   handle :            A handle of type PHT_VM_INFO.
   pbIsVmWaitingForAnswer :  [out] A pointer to a variable that receives
                       \result. PRL_TRUE \- the virtual machine is
                       waiting for answer. PRL_FALSE \- the virtual
					   machine is working normal.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the status of the virtual machine cannot be
   determined.

   RL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmInfo_IsVmWaitingForAnswer, (
				 PRL_HANDLE handle,
				 PRL_BOOL_PTR pbIsVmWaitingForAnswer
				) );


/* Determines whether a VNC server is running for the specified
   virtual machine.
   Parameters
   handle :                A handle of type PHT_VM_INFO.
   pbIsVncServerStarted :  [out] A pointer to a variable that
                           receives the result. PRL_TRUE
                           indicates that a VNC server is
                           running. PRL_FALSE indicates
                           otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - the VNC server state information is not
   available.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlVm_StartVncServer

   PrlVm_StopVncServer                                          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVmInfo_IsVncServerStarted, (
		PRL_HANDLE handle,
		PRL_BOOL_PTR pbIsVncServerStarted
		) );

/* Get VM process id.
   Parameters
   handle :                A handle of type PHT_VM_INFO.
   ppid :                  [out] A pointer to a variable that receives the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_NO_DATA - process id not available.

   PRL_ERR_SUCCESS - function completed successfully. */
PRL_METHOD_DECL( PARALLELS_API_VER_7,
				 PrlVmInfo_GetVmProcessId, (
		PRL_HANDLE handle,
		PRL_UINT32_PTR ppid
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for search virtual machines info processing
///////////////////////////////////////////////////////////////////////////////

/* Extracts the virtual machine name form the container.
   Parameters
   handle :           A handle of type PHT_FOUND_VM_INFO
                      identifying the container.
   sName :            [out] A pointer to a buffer that receives
                      the name. Pass a null pointer to determine
                      the required buffer size.
   pnNameBufLength :  [in] The size of the buffer used to receive
                      the output data (in bytes). [out] The
                      required buffer size if the buffer
                      parameter contains a null pointer or if the
                      specified buffer size is not large enough.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter used to specify the size will
   contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlFoundVmInfo_GetName, (
				PRL_HANDLE handle,
				PRL_STR sName,
				PRL_UINT32_PTR pnNameBufLength
				) );

/* Determines if the virtual machine has an old configuration.
   Parameters
   handle :        A handle of type PHT_FOUND_VM_INFO identifying
                   the container.
   pbOldVersion :  [out] A pointer to a variable that receives
                   the result. A value of "true" indicates that
                   the machine has an old configuration.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlFoundVmInfo_IsOldConfig, (
				PRL_HANDLE handle,
				PRL_BOOL_PTR pbOldVersion
				) );

/* Extracts the virtual machine's OS version from the container.
   Parameters
   handle :       A handle of type PHT_FOUND_VM_INFO identifying
                  the container.
   pnOSVersion :  [out] A pointer to a variable that receives the
                  OS version.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlFoundVmInfo_GetOSVersion, (
				PRL_HANDLE handle,
				PRL_UINT32_PTR pnOSVersion
				) );

/* Extracts the virtual machine configuration path from the
   container.
   Parameters
   handle :           A handle of type PHT_FOUND_VM_INFO
                      identifying the container.
   sPath :            [out] A pointer to a buffer that receives
                      the path. Pass a null pointer to determine
                      the required buffer size.
   pnPathBufLength :  [in] The size of the buffer used to receive
                      the output data (in bytes). [out] The
                      required buffer size if the buffer
                      parameter contains a null pointer or if the
                      specified buffer size is not large enough.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle.

   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter used to specify the size will
   contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlFoundVmInfo_GetConfigPath, (
				PRL_HANDLE handle,
				PRL_STR sPath,
				PRL_UINT32_PTR pnPathBufLength
				) );

/* Determines of the specified virtual machine is a template.
   Parameters
   handle :        A handle of type PHT_FOUND_VM_INFO identifying
                   the container.
   pbIsTemplate :  [out] A pointer to a variable that receives
                   the result. PRL_TRUE indicates that the
                   virtual machine is a template. PRL_TRUE
                   indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */

PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlFoundVmInfo_IsTemplate, (
				PRL_HANDLE handle,
				PRL_BOOL_PTR pbIsTemplate
				) );


///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the access rights list info processing
///////////////////////////////////////////////////////////////////////////////

/* Determines if the current user is authorized to perform a
   specified task on a virtual machine.
   Parameters
   hAcl :         A handle of type PHT_ACCESS_RIGHTS containing
                  the access rights information for a virtual
                  machine.
   nPermission :  Task type.
   pbAllowed :    [out] A pointer to a variable that receives the
                  \result. PRL_TRUE indicates that the user is
                  allowed to perform the task. PRL_FALSE
                  indicates otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlAcl_IsAllowed, (
		PRL_HANDLE hAcl,
		PRL_ALLOWED_VM_COMMAND nPermission,
		PRL_BOOL_PTR pbAllowed
		) );


/* Obtains the virtual machine access rights information. The
   function determines whether other users besides the owner can
   view, run, or have full access to a virtual machine.
   Parameters
   hAcl :               A handle of type PHT_ACCESS_RIGHTS
                        containing the access rights information
                        for a virtual machine.
   pnAccessForOthers :  [out] A pointer to a variable that
                        receives the virtual machine access level
                        information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlAcl_SetAccessForOthers                                      */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlAcl_GetAccessForOthers, (
		PRL_HANDLE hAcl,
		PRL_VM_ACCESS_FOR_OTHERS_PTR pnAccessForOthers
		) );


/* Sets access rights on a virtual machine. The owner of a
   virtual machine can use this function to grant or deny access
   rights for the virtual machine to other users. The access
   rights will be applied to all users. The call will only
   update the local copy of the PHT_ACCESS_RIGHTS object passed
   to the function (you will have to properly obtain the object
   prior to calling this function). To apply the changes to the
   virtual machine, call the PrlVm_UpdateSecurity function after
   making this calls and pass the same PHT_ACCESS_RIGHTS handle
   to it.
   Parameters
   hAcl :              A handle of type PHT_ACCESS_RIGHTS
                       containing the access rights information
                       for a virtual machine.
   nAccessForOthers :  The access rights to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlAcl_GetAccessForOthers                                     */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlAcl_SetAccessForOthers, (
		PRL_HANDLE hAcl,
		PRL_VM_ACCESS_FOR_OTHERS nAccessForOthers
		) );


/* Determines the virtual machine owner name.
   Parameters
   hAcl :                  A handle of type PHT_ACCESS_RIGHTS
                           containing the access rights
                           information for a virtual machine.
   sOwnerNameBuf :         [out] A pointer to a buffer that
                           receives the virtual machine owner
                           name (a UTF\-8 encoded,
                           null\-terminated string).
   pnOwnerNameBufLength :  [in] The size of the output buffer (in
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

   PRL_ERR_SUCCESS - function completed successfully.
   See Also
   PrlAcl_IsCurrentSessionOwner                                   */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlAcl_GetOwnerName, (
				PRL_HANDLE hAcl,
				PRL_STR sOwnerNameBuf,
				PRL_UINT32_PTR pnOwnerNameBufLength
				) );


/* Determines if the current user is the owner of the specified
   virtual machine.
   Parameters
   hAcl :       A handle of type PHT_ACCESS_RIGHTS containing the
                access rights information for a virtual machine.
   pbIsOwner :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the user is the
                owner of the virtual machine. PRL_FALSE indicates
                otherwise.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlAcl_IsCurrentSessionOwner, (
		PRL_HANDLE hAcl,
		PRL_BOOL_PTR pbIsOwner
		) );


/////////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the Parallels appliance configuration object.
/////////////////////////////////////////////////////////////////////////////////


/* Creates a new handle of type PHT_APPLIANCE_CONFIG. The handle
   is necessary to create and configure an appliance download configuration.
   If you would like to create a new appliance download configuration,
   use this function to create the handle first and then use the handle
   functions to configure the appliance info.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   phAppCfg :  [out] A pointer to a variable that receives the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlAppliance_Create, (
		PRL_HANDLE_PTR phAppCfg
		) );


////////////////////////////////////////////////////////////////////////////////
/// @section Tools Information Service (TIS) support
////////////////////////////////////////////////////////////////////////////////


/**
Returns uid associated with specified TIS database record.

Value returns in UTF-8 encoding. Null char ('\0') adding to the end of string.

Parameters
hRecord : [in] handle to TIS database record
sUid : [out] buffer for storing result (can be NULL in case when method
			 calling in view to determine necessary buffer size - see below)
pnUidLength : [in,out] size of specified buffer (on the output this param
					   will be has length of really stored value include
					   last '\0' char; also 0 value can be specified to
					   variable in view to determine necessary buffer
					   size for complete string value extraction)

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_TIS_RECORD handle or non valid (NULL)
					  pointer to the buffer (in case if buffer size not 0
					  - see above) or non valid (NULL) pointer to the
					  buffer size was specified
PRL_ERR_BUFFER_OVERRUN - not enough buffer size to completely storing string,
						 output buffer will contain string stripped to
						 specified buffer size, and requierd buffer size is
						 returned
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetUid, (
	PRL_HANDLE hRecord,
	PRL_STR sUid,
	PRL_UINT32_PTR pnUidLength
	) );

/**
Returns name associated with specified TIS database record.

Value returns in UTF-8 encoding. Null char ('\0') adding to the end of string.

Parameters
hRecord : [in] handle to TIS database record
sName : [out] buffer for storing result (can be NULL in case when method
			  calling in view to determine necessary buffer size - see below)
pnNameLength : [in,out] size of specified buffer (on the output this param
					    will be has length of really stored value include
					    last '\0' char; also 0 value can be specified to
					    variable in view to determine necessary buffer
					    size for complete string value extraction)

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_TIS_RECORD handle or non valid (NULL)
					  pointer to the buffer (in case if buffer size not 0
					  - see above) or non valid (NULL) pointer to the
					  buffer size was specified
PRL_ERR_BUFFER_OVERRUN - not enough buffer size to completely storing string,
						 output buffer will contain string stripped to
						 specified buffer size, and requierd buffer size is
						 returned
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetName, (
	PRL_HANDLE hRecord,
	PRL_STR sName,
	PRL_UINT32_PTR pnNameLength
	) );

/**
Returns fixed size info associated with specified TIS database record

Parameters:
hRecord : [in] handle to TIS database record
pInfo : [out] buffer to receive info value

Returns:
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - when hRecord is invalid handle or pInfo
					  is invalid pointer
PRL_ERR_UNINITIALIZED - when Desktop object is not accessible
PRL_ERR_SUCCESS
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetInfo, (
	PRL_HANDLE hRecord,
	PRL_TIS_RECORD_INFO_PTR pInfo
	) );

/**
Returns text associated with specified TIS database record.

Value returns in UTF-8 encoding. Null char ('\0') adding to the end of string.

Parameters
hRecord : [in] handle to TIS database record
sText : [out] buffer for storing result (can be NULL in case when method
			  calling in view to determine necessary buffer size - see below)
pnTextLength : [in,out] size of specified buffer (on the output this param
					    will be has length of really stored value include
					    last '\0' char; also 0 value can be specified to
					    variable in view to determine necessary buffer
					    size for complete string value extraction)

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_TIS_RECORD handle or non valid (NULL)
					  pointer to the buffer (in case if buffer size not 0
					  - see above) or non valid (NULL) pointer to the
					  buffer size was specified
PRL_ERR_BUFFER_OVERRUN - not enough buffer size to completely storing string,
						 output buffer will contain string stripped to
						 specified buffer size, and requierd buffer size is
						 returned
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetText, (
	PRL_HANDLE hRecord,
	PRL_STR sText,
	PRL_UINT32_PTR pnTextLength
	) );

/* \Returns data associated with specified TIS database record.
   Parameters
   hRecord :     [in] handle to TIS database record
   bData :       [out] buffer for storing result (can be NULL in
                 case when method calling in view to determine
                 necessary buffer size \- see below)
   pnDataSize :  [in,out] size of specified buffer (on the output
                 this param will be has length of really stored
                 value) also 0 value can be specified to variable
                 in view to determine necessary buffer size for
                 complete string value extraction)
   Returns
   PRL_RESULT. Possible values: PRL_ERR_INVALID_ARG - non valid
   PHT_TIS_RECORD handle or non valid (NULL) pointer to the
   buffer (in case if buffer size not 0
     * see above) or non valid (NULL) pointer to the
   buffer size was specified PRL_ERR_BUFFER_OVERRUN - not enough
   buffer size to completely storing data, output buffer will
   contain data stripped to specified buffer size, and requierd
   buffer size is returned PRL_ERR_SUCCESS - operation
   completed successfully                                         */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetData, (
	PRL_HANDLE hRecord,
	PRL_VOID_PTR bData,
	PRL_UINT32_PTR pnDataSize
	) );

/**
Returns time associated with specified TIS database record
in "yyyy-mm-dd hh:mi:ss" format.
Returned time is a local time (i.e. returning time value was already converted to local time zone).
Value returns in UTF-8 encoding.
Null char ('\0') adding to the end of string.

Parameters
hRecord : [in] handle to TIS database record
sTime : [out] buffer for storing result (can be NULL in case when method
			  calling in view to determine necessary buffer size - see below).
pnTimeLength : [in,out] size of specified buffer (on the output this param
					    will be has length of really stored value include
					    last '\0' char; also 0 value can be specified to
					    variable in view to determine necessary buffer
					    size for complete string value extraction)

Returns
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - non valid PHT_TIS_RECORD handle or non valid (NULL)
					  pointer to the buffer (in case if buffer size not 0
					  - see above) or non valid (NULL) pointer to the
					  buffer size was specified
PRL_ERR_BUFFER_OVERRUN - not enough buffer size to completely storing string,
						 output buffer will contain string stripped to
						 specified buffer size, and requierd buffer size is
						 returned
PRL_ERR_SUCCESS - operation completed successfully
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetTime, (
	PRL_HANDLE hRecord,
	PRL_STR sTime,
	PRL_UINT32_PTR pnTimeLength
	) );

/**
Returns state of specified TIS database record

Parameters:
hRecord : [in] handle to TIS database record
pState : [out] buffer to receive state value

Returns:
PRL_RESULT. Possible values:
PRL_ERR_INVALID_ARG - when hRecord is invalid handle or pState
					  is invalid pointer
PRL_ERR_UNINITIALIZED - when Desktop object is not accessible
PRL_ERR_UNEXPECTED - when record is broken and its state can't be determined
PRL_ERR_SUCCESS
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlTisRecord_GetState, (
	PRL_HANDLE hRecord,
	PRL_TIS_RECORD_STATE_PTR pState
	) );


////////////////////////////////////////////////////////////////////////////////
/// @section User Input Emulation (UIEmu) support
////////////////////////////////////////////////////////////////////////////////

/* Creates input object. To add input to created object call any of
   PrlUIEmuInput_AddXXX() functions. To send input to guest call
   PrlVm_UIEmuSendInput() function. Created input object must be explicitly
   disposed with PrlHandle_Free().
   Access to input object is not synchronized. Only one thread at a time can
   modify it. While one thread modifies input object, other threads can not
   access it (modify or send it). However, it is safe to send input
   object from different threads at the same time.

   Parameters
   hInput	    : [out] On success receives handle of type PHT_UIEMU_INPUT.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - hInput is NULL.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlUIEmuInput_Create, (
	PRL_HANDLE_PTR hInput
	) );

/* Add virtual keys to input object.
   Input object must not be accessed from other thread during this operation.

   Parameters
   hInput	    : [in] Handle of type PHT_UIEMU_INPUT. Must be valid.
   vkeys        : [in] Virtual keys sequence.
   count        : [in] Count of virtual keys in vkeys sequence. Must be 1 or
                       greater.
   repeat       : [in] Sequence repeat count. Must be 1 or greater.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlUIEmuInput_AddVKeys, (
	PRL_HANDLE hInput,
	PRL_CONST_UIEMU_VKEY_PTR vkeys,
	PRL_UINT32 count,
	PRL_UINT32 repeat
	) );

/* Add text to input object.
   Input object must not be accessed from other thread during this operation.

   Parameters
   hInput	    : [in] Handle of type PHT_UIEMU_INPUT. Must be valid.
   text         : [in] Text (UTF-8 encoded).
   length       : [in] Text length. Can be 0.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_3,
				 PrlUIEmuInput_AddText, (
	PRL_HANDLE hInput,
	PRL_CONST_STR text,
	PRL_UINT32 length
	) );


///////////////////////////////////////////////////////////////////////////////
/// @section VM data statistic functionality.
///////////////////////////////////////////////////////////////////////////////

/* Obtains a handle of type PHT_SYSTEM_STATISTICS_VM_DATA
   containing the specified system VM data statistic.
   Parameters
   hStat :         A handle of type PHT_SYSTEM_STATISTICS.
   phVmDataStat :  [out] A pointer to a variable that receives
                   the handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlStat_GetVmDataStat, (
		PRL_HANDLE hStat,
		PRL_HANDLE_PTR phVmDataStat
		) );

/* \Returns VM data segment capacity in bytes.
   Parameters
   hVmDataStat :  A handle of type PHT_SYSTEM_STATISTICS_VM_DATA
                  identifying the system process.
   nSegment :     Segment id defined in PRL_DATA_STATISTIC_SEGMENTS enum.
   pnCapacity :   [out] A pointer to a variable that receives the
                  \result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_NO_DATA - no data for given segment.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
				 PrlStatVmData_GetSegmentCapacity, (
				PRL_HANDLE hVmDataStat,
				PRL_DATA_STATISTIC_SEGMENTS nSegment,
				PRL_UINT64_PTR pnCapacity
				) );


////////////////////////////////////////////////////////////////////////////////
/// @section Captured Video Source
////////////////////////////////////////////////////////////////////////////////

/* Set source name.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.
   sLocalizedName : [in] Source localized name (UTF-8 encoded).

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_SetLocalizedName, (
		PRL_HANDLE hCVSrc,
		PRL_CONST_STR sLocalizedName
		) );

/* Set source unique id.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.
   sUniqueId : [in] Source unique id (UTF-8 encoded).

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_SetUniqueId, (
		PRL_HANDLE hCVSrc,
		PRL_CONST_STR sUniqueId
		) );

/* Connects source to Vm.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_CVSRC_IO_ERROR - failed to send connect request.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_Connect, (
		PRL_HANDLE hCVSrc
		) );

/* Disconnects source from Vm.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_Disconnect, (
		PRL_HANDLE hCVSrc
		) );

/* Open channel to supply frames to Vm. Must be called after receiving
   PET_IO_CVSRC_OPEN event.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_CVSRC_NO_OPEN_REQUEST - no pending open request from Vm.
   PRL_ERR_CVSRC_NO_CHANNEL - failed to establish IO channel for source.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_Open, (
		PRL_HANDLE hCVSrc
		) );

/* Close channel previously opened with PrlCVSrc_Open().

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_Close, (
		PRL_HANDLE hCVSrc
		) );

/* Returns current mode obtained after call to PrlCVSrc_Open().

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.
   pOpenMode: [out] Receives current mode.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_GetOpenMode, (
		PRL_HANDLE hCVSrc,
		PRL_CVSRC_OPEN_MODE_PTR pOpenMode
		) );

/* Locks access to frame buffer.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_LockBuffer, (
		PRL_HANDLE hCVSrc
		) );

/* Unlocks access to frame buffer and submits changes to Vm.

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_UnlockBuffer, (
		PRL_HANDLE hCVSrc
		) );

/* Returns frame buffer pointer and size. Source IO channel must be opened with
   PrlCVSrc_Open() and buffer must be locked with PrlCVSrc_LockBuffer().

   Parameters
   hCVSrc   : [in] A handle of type PHT_CVSRC identifying the source.
   pPtr     : [out] Will receive pointer on frame buffer.
   uSize    : [out] Will receive size of frame buffer(in bytes).

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlCVSrc_GetBuffer, (
		PRL_HANDLE hCVSrc,
		PRL_VOID_PTR_PTR pPtr,
		PRL_UINT32_PTR uSize
		) );

/*
	Creates VM registration parameters object handle.
	VM registration parameters intented to be used to customize VM registration on server.

	Parameters
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VM_REGISTER_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets VM registration parameter VM bundle dir path.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_GetVmDirPath, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets VM registration parameter VM bundle dir path.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_SetVmDirPath, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Gets VM registration parameter VM uuid.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_GetVmUuid, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets VM registration parameter VM uuid.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_SetVmUuid, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Gets VM registration parameter VM new name.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_GetVmName, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets VM registration parameter VM new name.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_SetVmName, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Gets VM registration parameter flags.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	pV :			[out] A pointer to a variable that receives flags.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_GetFlags, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets VM registration parameter flags.

	Parameters
	hParams :		[in] A handle of type PHT_VM_REGISTER_PARAMS identifying the parameters object.
	v :				[in] flags value.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_7_1,
			PrlVmRegisterParams_SetFlags, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );


/*
   The function packs a virtual machine bundle, transforming it into a single file in-place.
   Packed virtual machine represents as a lightweight and compressed version of
   the specified virtual machine. In order to perform this operation,
   the original machine must be stopped.

   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   nFlags :            Reserved parameter.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_8,
               PrlVm_Pack, (
    PRL_HANDLE hVm,
    PRL_UINT32 nFlags
    ) );

/*
   The function unpacks a packed virtual machine file, transforming it into
   a virtual machine bundle.
   Parameters
   hServer :    A handle of type PHT_SERVER identifying the
                Parallels Service.
   nFlags :     Reserved parameter.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_8,
         PrlVm_Unpack, (
           PRL_HANDLE hVm,
           PRL_UINT32 nFlags
           ) );

/*
   The function gets a virtual machine network settings
   available without Parallels Tools installed inside.

   Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   nFlags :            Reserved parameter.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                   */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_8,
               PrlVm_GetNetworkSettings, (
    PRL_HANDLE hVm,
    PRL_UINT32 nFlags
    ) );


/*
	Creates guest os info object handle.
	VM guest os info can be used after creating default VM configuration to customize it

	Parameters
	phParams :		[out] A pointer to a variable that receives the new handle of type PHT_VM_GUEST_OS_INFO

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets guest OsVersion.
	Use constants with prefix PVS_GUEST_VER_*** from Include/PrlOses.h

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetOsVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest OsVersion.
	Use constants with prefix PVS_GUEST_VER_*** from Include/PrlOses.h

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetOsVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest architecture.
	It is a mask with values PVS_GUEST_ARCH_*** from Include/PrlOses.h

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetArch, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest architecture.
	It is a mask with values PVS_GUEST_ARCH_*** from Include/PrlOses.h

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetArch, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest MajorVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetMajorVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest MajorVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetMajorVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest MinorVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetMinorVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest MinorVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetMinorVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest PatchVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetPatchVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest PatchVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetPatchVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest BuildVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pV :			[out] A pointer to a variable that receives data.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetBuildVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets guest BuildVersion.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	v :				[in] a value to be set.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetBuildVersion, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets guest BuildAsString.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Inu§§valid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_GetBuildAsString, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets guest BuildAsString.

	Parameters
	hParams :		[in] A handle of type PHT_VM_GUEST_OS_INFO identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlVmGuestOsInfo_SetBuildAsString, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Performs estimations for converting 3rd-party VM to Parallels virtual machine with specified params.

	To get the return code from the PHT_JOB object, use the
	PrlJob_GetRetCode function. Possible values are:

	PRL_ERR_INVALID_ARG - invalid handle was passed.

	PRL_ERR_SUCCESS - function completed successfully.

	To get the results from the PHT_JOB object:
	1. Use the PrlJob_GetResult function to obtain a handle to
	the PHT_RESULT object.
	2. Use the PrlResult_GetParam function to obtain a handle
	of type PHT_THIRD_PARTY_VM_CONVERT_RESULT.
	Parameters
	hServer : A handle of type PHT_SERVER identifying the Parallels Service.
	hParams : A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the params.

	Returns
	A handle of type PHT_JOB containing the results of this
	asynchronous operation, including the return code and a
	handle of type PHT_THIRD_PARTY_VM_CONVERT_RESULT containing information
	about the estimated result.

	PRL_INVALID_HANDLE if there's not enough memory to
	instantiate the job object.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlSrv_EstimateConvertThirdPartyVm, (
		PRL_HANDLE hServer,
		PRL_HANDLE hParams
		) );

/*
	Performs 3rd-party VM convertion to Parallels virtual machine with specified params.

	To get the return code from the PHT_JOB object, use the
	PrlJob_GetRetCode function. Possible values are:

	PRL_ERR_INVALID_ARG - invalid handle was passed.

	PRL_ERR_SUCCESS - function completed successfully.

	To get the results from the PHT_JOB object:
	1. Use the PrlJob_GetResult function to obtain a handle to
	the PHT_RESULT object.
	2. Use the PrlResult_GetParam function to obtain a handle
	of type PHT_THIRD_PARTY_VM_CONVERT_RESULT.
	Parameters
	hServer : A handle of type PHT_SERVER identifying the Parallels Service.
	hParams : A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the params.

	Returns
	A handle of type PHT_JOB containing the results of this
	asynchronous operation, including the return code and a
	handle of type PHT_THIRD_PARTY_VM_CONVERT_RESULT containing information
	about the convertion result.

	PRL_INVALID_HANDLE if there's not enough memory to
	instantiate the job object.
*/
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlSrv_ConvertThirdPartyVm, (
		PRL_HANDLE hServer,
		PRL_HANDLE hParams
		) );

/*
	Creates 3rd-party VM convertion parameters object handle.
	VM convertion parameters intented to be used to customize 3rd-party VM convertion to Parallels virtual machine.

	Parameters
	phParams : [out] A pointer to a variable that receives the new handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_Create, (
		PRL_HANDLE_PTR phParams
		) );

/*
	Gets 3rd-party VM convertion parameters source VM path.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_GetSourcePath, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets 3rd-party VM convertion parameters source VM path.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_SetSourcePath, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Gets 3rd-party VM convertion parameters resulting VM destination path.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_GetDestinationPath, (
		PRL_HANDLE hParams,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Sets 3rd-party VM convertion parameters resulting VM destination path

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	pStr :			[in] The value to set. The value must be a a UTF\-8 encoded, null\-terminated string.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_SetDestinationPath, (
		PRL_HANDLE hParams,
		PRL_CONST_STR pStr
		) );

/*
	Gets 3rd-party VM convertion parameters flags.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	pV :			[out] A pointer to a variable that receives flags.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_GetFlags, (
		PRL_HANDLE hParams,
		PRL_UINT32_PTR pV
		) );

/*
	Sets 3rd-party VM convertion parameters flags.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_PARAMS identifying the parameters object.
	v :				[in] flags value.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertParams_SetFlags, (
		PRL_HANDLE hParams,
		PRL_UINT32 v
		) );

/*
	Gets 3rd-party VM convertion resulting VM disk space required.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_RESULT identifying the parameters object.
	pV :			[out] A pointer to a variable that receives flags.

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertResult_GetRequiredDiskSpace, (
		PRL_HANDLE hResult,
		PRL_UINT64_PTR pV
		) );

/*
	Gets 3rd-party VM convertion resulting VM path.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_RESULT identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertResult_GetResultPath, (
		PRL_HANDLE hResult,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Gets 3rd-party VM convertion resulting VM uuid.

	Parameters
	hParams :		[in] A handle of type PHT_THIRD_PARTY_VM_CONVERT_RESULT identifying the parameters object.
	pStr :			[out] A pointer to a buffer that receives the result (a UTF\-8 encoded, null\-terminated string).
	pSz :			[in] The size of the output buffer (in bytes). Set the buffer pointer to null
					and this parameter's value to zero to receive the required size.
					[out] The required output buffer size.
	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not large enough.
	The parameter that is used to specify the size will contain the required size.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertResult_GetVmUuid, (
		PRL_HANDLE hResult,
		PRL_STR pStr,
		PRL_UINT32_PTR pSz
		) );

/*
	Obtains a handle of type PHT_VM_GUEST_OS_INFO
	containing the specified VM OS info.

	Parameters
	phParams : [out] A pointer to a variable that receives the new handle of type PHT_VM_GUEST_OS_INFO

	Returns
	PRL_RESULT. Possible values are:

	PRL_ERR_INVALID_ARG - Invalid handle or null pointer was passed.
	PRL_ERR_OUT_OF_MEMORY - Not enough memory to create an object.
	PRL_ERR_SUCCESS - Function completed successfully.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_9_0,
			PrlThirdPartyVmConvertResult_GetVmGuestOsInfo, (
		PRL_HANDLE hResult,
		PRL_HANDLE_PTR phHandle
		) );


/*
  Obtains a total snapshots size of a particular vm

  Clients receive the specified virtual machine
  size of snapshots in bytes on a periodic basis. To obtain
  the size, an event handler (callback function) is required.
  Within the event handler, first check the type of event.
  Events of type PET_DSP_EVT_GET_VM_SNAPSHOTS_SIZE_CHANGED indicate an
  event containing the size of snapshots. To access the size, first
  extract the event parameter using PrlEvent_GetParam, then
  convert the result (which will be a UInt64) using PrlEvtPrm_ToUint64.

  Parameters
   hVm :               A handle of type PHT_VIRTUAL_MACHINE
                       identifying the virtual machine.
   nFlags :            Reserved parameter.

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
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_9_0,
      PrlVm_GetTotalSnapshotsSize, (
    PRL_HANDLE hVm,
    PRL_UINT32 nFlags
    ) );

#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_VM_H__
