////////////////////////////////////////////////////////////////////////////////
///
/// PrlApiManager.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
////////////////////////////////////////////////////////////////////////////////
#if defined(PRL_NO_MANAGER) && !defined(__PARALLELS_API_MANAGER_H__)
#define __PARALLELS_API_MANAGER_H__
#endif

#ifndef __PARALLELS_API_MANAGER_H__
#define __PARALLELS_API_MANAGER_H__

#include "PrlTypes.h"
#include "PrlApiVersion.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Do authentication on proxy server and returns list of registered hosts
   on this proxy.

   PRL_ERR_INVALID_ARG - null pointer was passed.

   Parameters
   account :	 Parallels account.
   accountPass : Parallels account password.
   cliInfo :     Additional client information.
   timeout :     Timeout in milliseconds. The authenticate operation will
                 stop once this limit is reached.
   handler :     Optional. A pointer to a user callback function
                 (event handler) that will be called when operation become
                 complete.
   userData :    Optional. A pointer to a user data that will be
                 passed to the optional callback function.
   Returns
   If authentication has been successfully passed, a handle of type PHT_JOB
   will contain a set of registered hosts on proxy or PRL_ERR_INVALID_HANDLE
   if there's not enough memory to instantiate the job object. */
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_3,
                       PrlSrv_GetRegisteredHostsOnProxy, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
				PRL_PROXY_CLIENT_INFO_PTR cliInfo,
				PRL_UINT32 timeout,
				PRL_EVENT_HANDLER_PTR handler,
				PRL_VOID_PTR userData
                ) );

/* Sign user certificate on manager CA .

   PRL_ERR_INVALID_ARG - null pointer was passed.

   Parameters
   account :	  Parallels account.
   accountPass :  Parallels account password.
   hostUuid       Parallels host UUID.
   cliInfo :      Additional client information.
   signingRequest Certifiate signing request.
   timeout :      Timeout in milliseconds. The authenticate operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called when operation become
                  complete.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags          Optional. Reserved for future needs.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   To get the results from the PHT_JOB object:
    1. Use the PrlJob_GetResult function to obtain a handle to
       the PHT_RESULT object.
    2. Use the PrlResult_GetParamByIndexAsString function to obtain a string
       containing user signed certificate from first param.

     See Also PrlSrv_CreateCredentials.....................*/

PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_SignCertificate, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_CONST_STR hostUuid,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR signingRequest,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Sign user certificate on manager CA. Alternative form of PrlApi_SignCertificate method with
   authorization via Manager's token.

   PRL_ERR_INVALID_ARG - null pointer was passed.

   Parameters
   managerToken : Parallels Manager token.
   hostUuid       Parallels host UUID.
   cliInfo :      Additional client information.
   signingRequest Certifiate signing request.
   timeout :      Timeout in milliseconds. The authenticate operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called when operation become
                  complete.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags          Optional. Reserved for future needs.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   To get the results from the PHT_JOB object:
    1. Use the PrlJob_GetResult function to obtain a handle to
       the PHT_RESULT object.
    2. Use the PrlResult_GetParamByIndexAsString function to obtain a string
       containing user signed certificate from first param.

     See Also PrlSrv_CreateCredentials.....................*/

PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_SignCertificateEx, (
                PRL_CONST_STR managerToken,
                PRL_CONST_STR hostUuid,
                const PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR signingRequest,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to put arbitrary data to the cloud user storage.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   dataKey :      A key identifying the data in the user storage.
   dataVersion :  Version of data (aka revision).
   data :         Pointer to the buffer containing the data.
   dataSize :     Size of the data.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_PutUserData, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR dataKey,
				PRL_INT32 dataVersion,
				PRL_VOID_PTR data,
				PRL_UINT32 dataSize,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to get arbitrary data from the cloud user storage.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   regExp :       A regular expression which matches to correspond required data
                  identifiers.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   To get the results from the PHT_JOB object use PrlJob_GetDataPtr. Result will be represented
   as a set of PRL_PROXY_USER_DATA structures.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_GetUserData, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR regExp,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to get arbitrary data keys from the cloud user storage.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   To get the results from the PHT_JOB object use PrlJob_GetDataPtr. Result will be represented
   as a set of PRL_PROXY_DATA_KEY structures.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_GetUserKeys, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to remove arbitrary data from the cloud user storage.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   dataKey :      A key identifying the data in the user storage.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side (no such key for example)
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_RemoveUserData, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR dataKey,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to put arbitrary icon to the cloud user storage.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   iconData :     Pointer to the buffer containing the icon data.
   dataSize :     Size of the data.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_PutIcon, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
				PRL_VOID_PTR iconData,
				PRL_UINT32 dataSize,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Calculates hash for specified icon data which can be used later in PrlApi_ValidateInCache.

   Parameters
   iconData :        Pointer to the buffer containing the icon data.
   iconDataSize :    Size of the data.
   pCalculatedHash : Buffer to calculated hash. Null terminated UTF8 string. Use
                     PrlBuffer_Free call in order to free memory allocated for
					 hash buffer.

   Returns
   PRL_RESULT. Possible values:
       PRL_ERR_SUCCESS - operation completed successfully
	   PRL_ERR_INVALID_ARG - wrong pointer or data size was provided
	   PRL_ERR_OUT_OF_MEMORY - not enough memory to complete operation
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlApi_CalcIconHash, (
		PRL_VOID_PTR iconData,
		PRL_UINT32 iconDataSize,
		PRL_VOID_PTR_PTR pCalculatedHash
		) );

/* Allows to check whether the specified icon hashes are present in the cache.
   Returns hashes that are not present in the cache.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   hHashesList :  list of icons hashes (object of type PHT_STRINGS_LIST)
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object. Use PrlJob_GetResult
   method to retrieve result with icons hashes which are not present
   in cache. Use PrlResult_GetParamsCount to determine how many hashes
   in result. Use PrlResult_GetParamByIndexAsString to retrieve each
   hash from result.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
	   PRL_ERR_INVALID_ARG - wrong parameter was passed
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side (no such key for example)
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_ValidateInCache, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_HANDLE hHandlesList,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Allows to sign for postponed notification about desired host registration on Manager.

   Parameters
   account :      Parallels account ID.
   accountPass :  Parallels account password.
   cliInfo :      Additional client information (e.g. alternative manager URL).
                  Can be null for default settings.
   hostUuid :     Desired host UUID.
   deviceToken :  Specific mobile device token which will be used by Manager for push notification.
   timeout :      Timeout in milliseconds. The authentication operation will
                  stop once this limit is reached.
   handler :      Optional. A pointer to a user callback function
                  (event handler) that will be called on operation completion.
   userData :     Optional. A pointer to a user data that will be
                  passed to the optional callback function.
   flags :        Optional. Reserved for future needs.

   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.

   Possible return codes:
       PRL_ERR_SUCCESS - operation completed successfully
       PRL_ERR_XMLRPC_INVALID_CREDENTIALS - wrong user credentials were provided
       PRL_ERR_XMLRPC_LIMITS_EXHAUSTED - remote server is busy for now - analogue of EAGAIN
       PRL_ERR_XMLRPC_INTERNAL_ERROR - error occurred during XML RPC interoperation
	   PRL_ERR_FAILURE - operation failed on remote side
*/
PRL_ASYNC_METHOD_DECL( PARALLELS_API_VER_5,
                       PrlApi_SubscribeOnRegistration, (
                PRL_CONST_STR account,
                PRL_CONST_STR accountPass,
                PRL_PROXY_CLIENT_INFO_PTR cliInfo,
                PRL_CONST_STR hostUuid,
				PRL_CONST_STR deviceToken,
                PRL_UINT32 timeout,
                PRL_EVENT_HANDLER_PTR handler,
                PRL_VOID_PTR userData,
                PRL_UINT32 flags
                ) );

/* Turn on/off print logging messages on console

   PRL_ERR_SUCCESS - function completed successfully.           */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
					 PrlApi_SwitchConsoleLogging, (
		PRL_BOOL bSwitchOn
		) );

/* Sets the revocation date time for SSL certificates, used in trusted channel connection.
   Parameters
   hServer :        A handle of type PHT_SERVER identifying the Parallels Service.
   nTimeStampUTC :  Certificate revocation date and time, represented by the number of seconds
                    that have passed since 1970-01-01T00:00:00, Coordinated Universal Time (UTC).

   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_SUCCESS - operation completed successfully

   PRL_ERR_INVALID_ARG - invalid handle.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlSrv_SetCertificateRevocationDateTime, (
			PRL_HANDLE hServer,
			PRL_UINT64 nTimeStampUTC
		) );

/* Sets the current trusted time, that will be used for SSL certificate check.
   Parameters
   hServer :        A handle of type PHT_SERVER identifying the Parallels Service.
   nTimeStampUTC :  Global date and time, represented by the number of seconds
                    that have passed since 1970-01-01T00:00:00, Coordinated Universal Time (UTC).

   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_SUCCESS - operation completed successfully

   PRL_ERR_INVALID_ARG - invalid handle.
*/
PRL_METHOD_DECL( PARALLELS_API_VER_5,
					 PrlSrv_SetGlobalDateTime, (
			PRL_HANDLE hServer,
			PRL_UINT64 nTimeStampUTC
		) );

/* Creates Desktop Control object.

   Parameters
   hVm	    : [in] A handle of type PHT_SERVER. Created object will control
                   desktop of specified server.
   hDeskCtl : [out] On success receives handle of type PHT_DESKTOP_CONTROL.

   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_UNINITIALIZED - SDK was not properly initialized.
   PRL_ERR_INVALID_ARG - specified arguments are invalid.
   PRL_ERR_OUT_OF_MEMORY - not enough memory.
   PRL_ERR_SUCCESS - function completed successfully.                         */
PRL_METHOD_DECL( PARALLELS_API_VER_4,
			PrlSrv_CreateDesktopControl, (
		PRL_HANDLE hSrv,
		PRL_HANDLE_PTR hDeskCtl
		) );

/* Obtains a list of handles of type PHT_EVENT containing
   in its parameters information about all registered host users.
   Note: this function is used by iPhone proxy only.
   To get the return code from the PHT_JOB object,
   use the PrlJob_GetRetCode function.
   Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParamByIndex function to obtain a handle
   of type PHT_EVENT containing an individual user
   information.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_GetAllHostUsers, (
		PRL_HANDLE hServer
		) );


#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_MANAGER_H__

