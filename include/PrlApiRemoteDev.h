///////////////////////////////////////////////////////////////////////////////
///
/// PrlApiRemoteDev.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_REMOTE_DEV_H__
#define __PARALLELS_API_REMOTE_DEV_H__

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
/// @section Remote devices support
///////////////////////////////////////////////////////////////////////////////

/**
This callback will be called when API requires remote device to be
created on the client side. Callee must create remote device and fill
ppRemoteDevice with pointer to device.

Parameters
hVMHandle : [in] Handle of the VM that wants to create remote device
device_type : [in] Type of the device
nIndex : [in] Index of the device
createCtx : [in] Pointer to the context that was registered together with callback
ppRemoteDevice : [out] pointer to the byffer to fill with created device pointer.

Returns
PRL_RESULT. Possible values
PRL_ERR_SUCCESS - device was successfully created
other values means some error of operation
*/
typedef PRL_METHOD_PTR( PREMOTE_DEVICE_CREATE_HANDLER ) (
		PRL_HANDLE hVMHandle,
		PRL_DEVICE_TYPE device_type,
		PRL_UINT32 nIndex,
		PRL_VOID_PTR createCtx,
		PRL_VOID_PTR_PTR ppRemoteDevice
		);

/**
This callback will be called when API requires specified remote device to be
destroyed.

Parameters
pRemoteDevice : [in] Pointer to the remote device created by REMOTE_DEVICE_CREATE_HANDLER

Returns
Returned value is ignored. Device must be destroyed unconditionally.
*/
typedef PRL_METHOD_PTR( PREMOTE_DEVICE_DESTROY_HANDLER ) (
		PRL_VOID_PTR pRemoteDevice
		);

/**
This callback will be called when API receives command to the remote device

Parameters
pRemoteDevice : [in] Pointer to the remote device created by REMOTE_DEVICE_CREATE_HANDLER
hCommand : [in] Handle to the remote device command

Returns
Returned value is ignored. Device must release handle to the command unconditionally.
*/
typedef PRL_METHOD_PTR( PREMOTE_DEVICE_COMMAND_HANDLER ) (
		PRL_VOID_PTR pRemoteDevice,
		PRL_HANDLE hCommand
		);

/**
Registers remote devices of specified type

Parameters
device_type : [in] Type of the devices to register as capable to be remote
pCreateHandler : [in] Function that creates remote device instances
createCtx : [in] Context to pass to the REMOTE_DEVICE_CREATE_HANDLER
pDestroyHandler : [in] Function that destroys device instance
pCommandHandler : [in] Function that handles commands to the remote device

Returns
PRL_ERR_SUCCESS - device was registered. Other values means some error
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_RegisterRemoteDevice, (
		PRL_DEVICE_TYPE device_type,
		PREMOTE_DEVICE_CREATE_HANDLER pCreateHandler,
		PRL_VOID_PTR createCtx,
		PREMOTE_DEVICE_DESTROY_HANDLER pDestroyHandler,
		PREMOTE_DEVICE_COMMAND_HANDLER pCommandHandler
	) );

/**
Unregisters remote device. This function will delete any registration
done for the device type.

Parameters
device_type : type of the device to unregister,

Returns
PRL_ERR_SUCCESS - device was unregistered. Other values means some error
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_UnregisterRemoteDevice, (
		PRL_DEVICE_TYPE device_type
	) );

/**
Obtains current registration of the remote devices of specified type

Parameters
device_type : [in] Type of the devices to register as capable to be remote
ppCreateHandler : [out] Function that creates remote device instances
pCreateCtx : [out] Context to pass to the REMOTE_DEVICE_CREATE_HANDLER
ppDestroyHandler : [out] Function that destroys device instance
ppCommandHandler : [out] Function that handles commands to the remote device

Returns
PRL_ERR_SUCCESS - parameters were obtained. Other values means error
*/
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_GetRemoteDeviceRegistration, (
		PRL_DEVICE_TYPE device_type,
		PREMOTE_DEVICE_CREATE_HANDLER* ppCreateHandler,
		PRL_VOID_PTR* pCreateCtx,
		PREMOTE_DEVICE_DESTROY_HANDLER* ppDestroyHandler,
		PREMOTE_DEVICE_COMMAND_HANDLER* ppCommandHandler
	) );


///////////////////////////////////////////////////////////////////////////////
/// @section Remote devices commands
///////////////////////////////////////////////////////////////////////////////


/* \ \
   Parameters
   hVm :       _nt_
   hCommand :  _nt_ */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
					   PrlApi_SendRemoteCommand, (
		PRL_HANDLE	hVm,
		PRL_HANDLE	hCommand
				) );

/* \ \
   Parameters
   hCommand :  _nt_
   pType :     _nt_ */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_GetRemoteCommandTarget, (
		PRL_HANDLE			hCommand,
		PRL_DEVICE_TYPE_PTR	pType
		)  );

/* \ \
   Parameters
   hCommand :  _nt_
   pIndex :    _nt_ */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_GetRemoteCommandIndex, (
		PRL_HANDLE		hCommand,
		PRL_UINT32_PTR	pIndex
		) );

/* \ \
   Parameters
   hCommand :  _nt_
   pCode :     _nt_ */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_GetRemoteCommandCode, (
		PRL_HANDLE		hCommand,
		PRL_UINT16_PTR	pCode
		) );

/* \ \
   Parameters
   hCommand :  _nt_
   pBuffer :   _nt_ */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_GetRemoteCommandBuffer, (
		PRL_HANDLE					hCommand,
		PRL_IO_GENERIC_BUFFER_PTR	pBuffer
		) );

/* \ \
   Parameters
   uTargetType :   _nt_
   uTargetIndex :  _nt_
   uCommandCode :  _nt_
   pData :         _nt_
   uDataSize :     _nt_
   phCommand :     _nt_ */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlApi_CreateRemoteCommand, (
		PRL_DEVICE_TYPE	uTargetType,
		PRL_UINT32		uTargetIndex,
		PRL_UINT16		uCommandCode,
		PRL_VOID_PTR	pData,
		PRL_SIZE		uDataSize,
		PRL_HANDLE_PTR	phCommand
		) );


#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_REMOTE_DEV_H__
