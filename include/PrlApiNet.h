///////////////////////////////////////////////////////////////////////////////
///
/// PrlApiNet.h
///
/// This file is the part of parallels public SDK library.
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_NET_H__
#define __PARALLELS_API_NET_H__

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

/* Obtains a list of handles of type PHT_VIRTUAL_NETWORK
   containing information about all existing virtual networks.
   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the results from the PHT_JOB object:

   Use the PrlJob_GetResult function to obtain a handle to the
   PHT_RESULT object.

   Use the PrlResult_GetParamByIndex function to obtain a handle
   of type PHT_VIRTUAL_NETWORK containing the information about
   a virtual network.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the
              Parallels Service.
   nFlags :   Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_GetVirtualNetworkList, (
		PRL_HANDLE hServer,
		PRL_UINT32 nFlags
		) );


/* Adds a new virtual network to the Parallels Service
   configuration. To create a new virtual network, first create
   a handle of type PHT_VIRTUAL_NETWORK, configure the network
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
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virtual network to add to the Parallels
               Service configuration.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_GetVirtualNetworkList

   PrlSrv_DeleteVirtualNetwork

   PrlSrv_UpdateVirtualNetwork                                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_AddVirtualNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hVirtNet,
		PRL_UINT32 nFlags
		) );


/* Updates parameters of an existing virtual network. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying a
               virtual network.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_AddVirtualNetwork

   PrlSrv_GetVirtualNetworkList

   PrlSrv_DeleteVirtualNetwork                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_UpdateVirtualNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hVirtNet,
		PRL_UINT32 nFlags
		) );


/* Removes an existing virtual network from the Parallels
   Service configuration. To get the return code from the
   PHT_JOB object, use the PrlJob_GetRetCode function. Possible
   values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :   A handle of type PHT_SERVER identifying the
               Parallels Service.
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying a
               virtual network.
   nFlags :    Reserved parameter.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.
   See Also
   PrlSrv_AddVirtualNetwork

   PrlSrv_GetVirtualNetworkList

   PrlSrv_UpdateVirtualNetwork                                    */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_2,
						   PrlSrv_DeleteVirtualNetwork, (
		PRL_HANDLE hServer,
		PRL_HANDLE hVirtNet,
		PRL_UINT32 nFlags
		) );


/* Starts the Parallels network service. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_NetServiceStart, (
		PRL_HANDLE hServer
		) );

/* Stops the Parallels network service. To get the return
   code from the PHT_JOB object, use the PrlJob_GetRetCode
   function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   unnamed_param :  A handle of type PHT_SERVER identifying the
                    Parallels Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                  */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_NetServiceStop, (
		PRL_HANDLE hServer
		) );

/* Restarts the Parallels network service. To get the
   return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_NetServiceRestart, (
		PRL_HANDLE hServer
		) );

/* Restores the default settings of the Parallels network
   service.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_NetServiceRestoreDefaults, (
		PRL_HANDLE hServer
		) );

/* \Returns an object of type PHT_NET_SERVICE_STATUS containing
   the Parallels network service status information.

   To get the return code from the PHT_JOB object, use the
   PrlJob_GetRetCode function. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.

   To get the result from the PHT_JOB object:
     1. Use the PrlJob_GetResult function to obtain a handle to
        the PHT_RESULT object.
     2. Use the PrlResult_GetParam function to obtain a handle
        of type PHT_NET_SERVICE_STATUS containing the NET service
        status.
   Parameters
   hServer :  A handle of type PHT_SERVER identifying the Parallels
              Service.
   Returns
   A handle of type PHT_JOB containing the results of this
   asynchronous operation or PRL_INVALID_HANDLE if there's not
   enough memory to instantiate the job object.                     */
PRL_ASYNC_SRV_METHOD_DECL( PARALLELS_API_VER_1,
						   PrlSrv_GetNetServiceStatus, (
		PRL_HANDLE hServer
		) );




///////////////////////////////////////////////////////////////////////////////
/// @section Virtual Network operations
///////////////////////////////////////////////////////////////////////////////

/* Creates a new handle of type PHT_VIRTUAL_NETWORK. The handle
   is necessary to create and configure a virtual network. If
   you would like to create a new virtual network, use this
   function to create the handle first and then use the handle
   functions to configure the network. If you would like to
   modify the configuration of an existing virtual network, use
   the PrlSrv_GetVirtualNetworkList function to obtain a handle
   to the virtual network of interest.

   It is the responsibility of the caller to free the handle
   with the PrlHandle_Free call when it is no longer needed.
   Parameters
   phVirtNet :  [out] A pointer to a variable that receives the
                handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a virtual
   network object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_Create, (
		PRL_HANDLE_PTR phVirtNet
		) );

/* \Returns the ID of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sNetworkId :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnNetworkIdBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetNetworkId, (
		PRL_HANDLE hVirtNet,
		PRL_STR sNetworkId,
		PRL_UINT32_PTR pnNetworkIdBufLength
		) );

/* Sets the specified virtual network ID.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sNetworkId :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetNetworkId, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sNetworkId
		) );

/* \Returns the description of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sDescription :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnDescriptionBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetDescription, (
		PRL_HANDLE hVirtNet,
		PRL_STR sDescription,
		PRL_UINT32_PTR pnDescriptionBufLength
		) );

/* Sets the specified virtual network description.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sDescription :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetDescription, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sDescription
		) );

/* \Returns the virtual network type. Network types
   are defined in the PRL_NET_VIRTUAL_NETWORK_TYPE enumeration.
   The following describes network types are used:
     * PVN_BRIDGED_ETHERNET
     * PVN_HOST_ONLY
   Parameters
   hVirtNet :        A handle of type PHT_VIRTUAL_NETWORK
                     identifying the virtual network.
   pnNetworkType :   [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetNetworkType, (
		PRL_HANDLE hVirtNet,
		PRL_NET_VIRTUAL_NETWORK_TYPE_PTR pnNetworkType
		) );

/* Sets the specified virtual network type. Network types
   are defined in the PRL_NET_VIRTUAL_NETWORK_TYPE enumeration.
   The following describes network types are used:
     * PVN_BRIDGED_ETHERNET
     * PVN_HOST_ONLY
   Parameters
   hVirtNet :      A handle of type PHT_VIRTUAL_NETWORK
                   identifying the virtual network.
   nNetworkType :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetNetworkType, (
		PRL_HANDLE hVirtNet,
		PRL_NET_VIRTUAL_NETWORK_TYPE nNetworkType
		) );

/* \Returns the bound card MAC address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sBoundCardMac :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnBoundCardMacBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetBoundCardMac, (
		PRL_HANDLE hVirtNet,
		PRL_STR sBoundCardMac,
		PRL_UINT32_PTR pnBoundCardMacBufLength
		) );

/* Sets the specified virtual network bound card MAC address.
   MAC address gets by PrlSrvCfgNet_GetMacAddress functions
   for given network adapter.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sBoundCardMac :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetBoundCardMac, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sBoundCardMac
		) );

/* \Returns the name of the network adapter in the specified
   virtual network.
   Parameters
   hVirtNet :                A handle of type PHT_VIRTUAL_NETWORK
                             identifying the virtual network.
   sAdapterName :            [out] A pointer to a buffer that
                             receives the result (a UTF\-8
                             encoded, null\-terminated string).
   pnAdapterNameBufLength :  [in] The size of the output buffer
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
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetAdapterName, (
		PRL_HANDLE hVirtNet,
		PRL_STR sAdapterName,
		PRL_UINT32_PTR pnAdapterNameBufLength
		) );

/* Sets the specified virtual network adapter name.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sAdapterName : The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetAdapterName, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sAdapterName
		) );

/* \Returns a numeric index assigned to the network adapter in
   the specified virtual network. Special values for this parameter
   in PRL_ADAPTER_INDEX enum.
   Parameters
   hVirtNet :        A handle of type PHT_VIRTUAL_NETWORK
                     identifying the virtual network.
   pnAdapterIndex :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetAdapterIndex, (
		PRL_HANDLE hVirtNet,
		PRL_UINT32_PTR pnAdapterIndex
		) );

/* Sets the specified adapter index. Special values for this parameter
   in PRL_ADAPTER_INDEX enum.
   Parameters
   hVirtNet :       A handle of type PHT_VIRTUAL_NETWORK
                    identifying the virtual network.
   nAdapterIndex :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetAdapterIndex, (
		PRL_HANDLE hVirtNet,
		PRL_UINT32 nAdapterIndex
		) );

/* \Returns the host IP address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sHostIPAddress :       [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnHostIPAddressBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetHostIPAddress, (
		PRL_HANDLE hVirtNet,
		PRL_STR sHostIPAddress,
		PRL_UINT32_PTR pnHostIPAddressBufLength
		) );

/* Sets the specified virtual network host IP address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sHostIPAddress :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetHostIPAddress, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sHostIPAddress
		) );

/* \Returns the host IPv6 address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sHostIPAddress :       [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnHostIPAddressBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetHostIP6Address, (
		PRL_HANDLE hVirtNet,
		PRL_STR sHostIPAddress,
		PRL_UINT32_PTR pnHostIPAddressBufLength
		) );

/* Sets the specified virtual network host IPv6 address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sHostIPAddress :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetHostIP6Address, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sHostIPAddress
		) );

/* \Returns the DCHP IP address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sDhcpIPAddress :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnDhcpIPAddressBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetDhcpIPAddress, (
		PRL_HANDLE hVirtNet,
		PRL_STR sDhcpIPAddress,
		PRL_UINT32_PTR pnDhcpIPAddressBufLength
		) );

/* Sets the specified virtual network DHCP IP address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sDhcpIPAddress :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetDhcpIPAddress, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sDhcpIPAddress
		) );

/* \Returns the DCHP IPv6 address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sDhcpIPAddress :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnDhcpIPAddressBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetDhcpIP6Address, (
		PRL_HANDLE hVirtNet,
		PRL_STR sDhcpIPAddress,
		PRL_UINT32_PTR pnDhcpIPAddressBufLength
		) );

/* Sets the specified virtual network DHCP IPv6 address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sDhcpIPAddress :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetDhcpIP6Address, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sDhcpIPAddress
		) );

/* \Returns the IP net mask of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPNetMask :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPNetMaskBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIPNetMask, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPNetMask,
		PRL_UINT32_PTR pnIPNetMaskBufLength
		) );

/* Sets the specified virtual network IP net mask.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPNetMask :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetIPNetMask, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPNetMask
		) );

/* \Returns the IPv6 net mask of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPNetMask :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPNetMaskBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIP6NetMask, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPNetMask,
		PRL_UINT32_PTR pnIPNetMaskBufLength
		) );

/* Sets the specified virtual network IPv6 net mask.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPNetMask :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetIP6NetMask, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPNetMask
		) );

/* \Returns the VLAN tag of the specified virtual network. Since
   the same physical adapter can be used at several virtual
   networks pair <VLAN tag, MAC address> can identify adapter.
   Parameters
   hVirtNet :            A handle of type PHT_VIRTUAL_NETWORK
                         identifying the virtual network.
   pnVlanTag   :         [out] The buffer for storing result.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetVlanTag, (
		PRL_HANDLE hVirtNet,
		PRL_UINT16_PTR pnVlanTag
		) );

/* \Sets the VLAN tag for the specified virtual network. Since
   the same physical adapter can be used at several virtual
   networks pair <VLAN tag, MAC address> can identify adapter.
   Parameters
   hVirtNet :            A handle of type PHT_VIRTUAL_NETWORK
                         identifying the virtual network.
   nVlanTag   :          [in] Setting value.
   Returns
   PRL_RESULT. Possible values are:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetVlanTag, (
		PRL_HANDLE hVirtNet,
		PRL_UINT16 nVlanTag
		) );

/* \Returns the DHCP start IP address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPScopeStart :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPScopeStartBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIPScopeStart, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPScopeStart,
		PRL_UINT32_PTR pnIPScopeStartBufLength
		) );

/* Sets the specified virtual network DHCP start IP address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPScopeStart :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetIPScopeStart, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPScopeStart
		) );

/* \Returns the DHCP end IP address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPScopeEnd :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPScopeEndBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIPScopeEnd, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPScopeEnd,
		PRL_UINT32_PTR pnIPScopeEndBufLength
		) );

/* Sets the specified virtual network DHCP end IP address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPScopeEnd :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetIPScopeEnd, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPScopeEnd
		) );

/* \Returns the DHCP start IPv6 address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPScopeStart :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPScopeStartBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIP6ScopeStart, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPScopeStart,
		PRL_UINT32_PTR pnIPScopeStartBufLength
		) );

/* Sets the specified virtual network DHCP start IPv6 address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPScopeStart :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetIP6ScopeStart, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPScopeStart
		) );

/* \Returns the DHCP end IPv6 address of the specified virtual network.
   Parameters
   hVirtNet :             A handle of type PHT_VIRTUAL_NETWORK
                          identifying the virtual network.
   sIPScopeEnd :           [out] A pointer to a buffer that receives
                          the result (a UTF\-8 encoded,
                          null\-terminated string).
   pnIPScopeEndBufLength : [in] The size of the output buffer (in
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
				 PrlVirtNet_GetIP6ScopeEnd, (
		PRL_HANDLE hVirtNet,
		PRL_STR sIPScopeEnd,
		PRL_UINT32_PTR pnIPScopeEndBufLength
		) );

/* Sets the specified virtual network DHCP end IPv6 address.
   Parameters
   hVirtNet :     A handle of type PHT_VIRTUAL_NETWORK
                  identifying the virtual network.
   sIPScopeEnd :   The value to set. The value must be a a UTF\-8
                  encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetIP6ScopeEnd, (
		PRL_HANDLE hVirtNet,
		PRL_CONST_STR sIPScopeEnd
		) );

/* Determines whether the specified virtual network is
   enabled or disabled.
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the \result.
                PRL_TRUE indicates that the virtual network is enabled.
                PRL_FALSE indicates that the virtual network is disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_IsEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virtual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the virtual network.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );

/* Determines whether the specified virtual network adapter is
   enabled or disabled.
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the adapter is
                enabled. PRL_FALSE indicates that the adapter is
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_IsAdapterEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   adapter.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virtual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the adapter.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetAdapterEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );

/* Determines whether the specified virtual network DHCP server is
   enabled or disabled.
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the DHCP server is
                enabled. PRL_FALSE indicates that the DHCP server is
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_IsDHCPServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   DHCP server.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the DHCP server.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetDHCPServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );

/* Determines whether the specified virtual network DHCPv6 server is
   enabled or disabled.
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the DHCP server is
                enabled. PRL_FALSE indicates that the DHCP server is
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_IsDHCP6ServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   DHCPv6 server.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the DHCP server.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetDHCP6ServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );


/* Determines whether the specified virtual network can assign IP v6 address
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the host can assign IPv6 address.
                PRL_FALSE indicates that can't
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_IsHostAssignIP6, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   assign IP v6 address.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable host to assign IP v6.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlVirtNet_SetHostAssignIP6, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );

/* Determines whether the specified virtual network NAT server is
   enabled or disabled.
   Parameters
   hVirtNet :   A handle of type PHT_VIRTUAL_NETWORK identifying
                the virtual network.
   pbEnabled :  [out] A pointer to a variable that receives the
                \result. PRL_TRUE indicates that the NAT server is
                enabled. PRL_FALSE indicates that the NAT server is
                disabled.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_IsNATServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL_PTR pbEnabled
		) );

/* Allows to enable or disable a specified virtual network
   NAT server.
   Parameters
   hVirtNet :  A handle of type PHT_VIRTUAL_NETWORK identifying
               the virual network.
   bEnabled :  A boolean value indicating the type of action to
               perform. PRL_TRUE will enable the NAT server.
               PRL_FALSE will disable it.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle was passed.

   PRL_ERR_SUCCESS - function completed successfully.          */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetNATServerEnabled, (
		PRL_HANDLE hVirtNet,
		PRL_BOOL bEnabled
		) );

/* \Returns the port forward entries list.
   Parameters
   hVirtNet :        A handle of type PHT_VIRTUAL_NETWORK
                     identifying the virtual network.
   nPortFwdType :    A port forward type ( PRL_PORT_FORWARDING_TYPE
                     enumeration ).
   phPortFwdList :   [out] A pointer to a variable that receives the
                     new handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the list
   or a port forward handle object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetPortForwardList, (
		PRL_HANDLE hVirtNet,
		PRL_PORT_FORWARDING_TYPE nPortFwdType,
		PRL_HANDLE_PTR phPortFwdList
		) );

/* \Sets the port forward entries list.
   Parameters
   hVirtNet :        A handle of type PHT_VIRTUAL_NETWORK
                     identifying the virtual network.
   nPortFwdType :    A port forward type ( PRL_PORT_FORWARDING_TYPE
                     enumeration ).
   hPortFwdList :    The list of PHT_PORT_FORWARDING handles.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a port
   forward entry object.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_SetPortForwardList, (
		PRL_HANDLE hVirtNet,
		PRL_PORT_FORWARDING_TYPE nPortFwdType,
		PRL_HANDLE hPortFwdList
		) );

/* \Obtains physical adapter info which bound to the virtual network object.
   This method provided for convenience in order do not create own algorithm
   of bound to the virtual network physical adapter information.
   Parameters
   hVirtNet :        A handle of type PHT_VIRTUAL_NETWORK
                     identifying the virtual network.
   hSrvConfig :	     A handle of type PHT_SERVER_CONFIG which provides
                     host hardware information.
   phNetAdapter :   [out] A pointer to a variable that receives the
                     new handle of PHT_HW_NET_ADAPTER object.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle of virtual network object or invalid
                         handle of host hardware info or null pointer was passed.

   PRL_ERR_NETWORK_ADAPTER_NOT_FOUND - correspond network adapter is absent at
                                       provided host

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create the object of network
                           adapter.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlVirtNet_GetBoundAdapterInfo, (
		PRL_HANDLE hVirtNet,
		PRL_HANDLE hSrvConfig,
		PRL_HANDLE_PTR phNetAdapter
		) );


///////////////////////////////////////////////////////////////////////////////
/// @section Port Forwarding operations
///////////////////////////////////////////////////////////////////////////////

/* Creates a new handle of type PHT_PORT_FORWARDING. It is the
   responsibility of the user to free the handle when it is no
   longer needed.
   Parameters
   phPortFwd :  [out] A pointer to a variable that receives the new
                handle.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_OUT_OF_MEMORY - not enough memory to create a port
   forward handle object.

   PRL_ERR_SUCCESS - function completed successfully.               */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_Create, (
		PRL_HANDLE_PTR phPortFwd
		) );

/* \Returns the rule name of the specified port forward entry.
   Parameters
   hPortFwd :            A handle of type PHT_PORT_FORWARDING
                         identifying the port forwarding.
   sRuleName :  [out] A pointer to a buffer that receives
                         the result (a UTF\-8 encoded,
                         null\-terminated string).
   pnRuleNameBufLength : [in] The size of the output buffer (in
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
				 PrlPortFwd_GetRuleName, (
		PRL_HANDLE hPortFwd,
		PRL_STR sRuleName,
		PRL_UINT32_PTR pnRuleNameBufLength
		) );

/* Sets the specified port forward entry rule name.
   Parameters
   hPortFwd :    A handle of type PHT_PORT_FORWARDING
                 identifying the port forwarding.
   sRuleName : The value to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlPortFwd_SetRuleName, (
		PRL_HANDLE hPortFwd,
		PRL_CONST_STR sRuleName
		) );

/* \Returns the incoming port.
   Parameters
   hPortFwd :        A handle of type PHT_PORT_FORWARDING
                     identifying the port forwarding.
   pnIncomingPort :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_GetIncomingPort, (
		PRL_HANDLE hPortFwd,
		PRL_UINT16_PTR pnIncomingPort
		) );

/* Sets the specified incoming port.
   Parameters
   hPortFwd :      A handle of type PHT_PORT_FORWARDING
                   identifying the port forwarding.
   nIncomingPort :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_SetIncomingPort, (
		PRL_HANDLE hPortFwd,
		PRL_UINT16 nIncomingPort
		) );

/* \Returns the redirect IP address of the specified port forward entry.
   Parameters
   hPortFwd :            A handle of type PHT_PORT_FORWARDING
                         identifying the port forwarding.
   sRedirectIPAddress :  [out] A pointer to a buffer that receives
                         the result (a UTF\-8 encoded,
                         null\-terminated string).
   pnRedirectIPAddressBufLength : [in] The size of the output buffer (in
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
				 PrlPortFwd_GetRedirectIPAddress, (
		PRL_HANDLE hPortFwd,
		PRL_STR sRedirectIPAddress,
		PRL_UINT32_PTR pnRedirectIPAddressBufLength
		) );

/* Sets the specified port forwardi entry redirect IP address.
   Parameters
   hPortFwd :           A handle of type PHT_PORT_FORWARDING
                        identifying the port forwarding.
   sRedirectIPAddress : The value to set. The value must be a a UTF\-8
                        encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_SetRedirectIPAddress, (
		PRL_HANDLE hPortFwd,
		PRL_CONST_STR sRedirectIPAddress
		) );

/* \Returns the redirect port.
   Parameters
   hPortFwd :        A handle of type PHT_PORT_FORWARDING
                     identifying the port forwarding.
   pnRedirectPort :  [out] A pointer to a variable that receives
                     the result.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_GetRedirectPort, (
		PRL_HANDLE hPortFwd,
		PRL_UINT16_PTR pnRedirectPort
		) );

/* Sets the specified redirect port.
   Parameters
   hPortFwd :      A handle of type PHT_PORT_FORWARDING
                   identifying the port forwarding.
   nRedirectPort :  The value to set.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.            */
PRL_METHOD_DECL( PARALLELS_API_VER_2,
				 PrlPortFwd_SetRedirectPort, (
		PRL_HANDLE hPortFwd,
		PRL_UINT16 nRedirectPort
		) );

/* \Returns the redirect virtual machine identifier
   of the specified port forward entry.
   Parameters
   hPortFwd :            A handle of type PHT_PORT_FORWARDING
                         identifying the port forwarding.
   sRedirectVm :  [out] A pointer to a buffer that receives
                         the result (a UTF\-8 encoded,
                         null\-terminated string).
   pnRedirectVmBufLength : [in] The size of the output buffer (in
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
				 PrlPortFwd_GetRedirectVm, (
		PRL_HANDLE hPortFwd,
		PRL_STR sRedirectVm,
		PRL_UINT32_PTR pnRedirectVmBufLength
		) );

/* Sets the specified port forward entry virtual machine identifier.
   Parameters
   hPortFwd :    A handle of type PHT_PORT_FORWARDING
                 identifying the port forwarding.
   sRedirectVm : The value to set. The value must be a a UTF\-8
                 encoded, null\-terminated string.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_5,
				 PrlPortFwd_SetRedirectVm, (
		PRL_HANDLE hPortFwd,
		PRL_CONST_STR sRedirectVm
		) );

///////////////////////////////////////////////////////////////////////////////
/// @section Functions specific for the Parallels Net service processing
///////////////////////////////////////////////////////////////////////////////

/* \Returns the Parallels Service network status information.
   Parameters
   handle :       A handle of type PHT_NET_SERVICE_STATUS.
   pnNetStatus :  [out] A pointer to a variable that receives the
                  status information.
   Returns
   PRL_RESULT. Possible values:

   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.             */
PRL_METHOD_DECL( PARALLELS_API_VER_1,
				 PrlNetSvc_GetStatus, (
		PRL_HANDLE handle,
		PRL_SERVICE_STATUS_ENUM_PTR pnNetStatus
		) );

#ifdef _WIN_
    #pragma pack(pop, save_api_pack)
#endif

#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_NET_H__
