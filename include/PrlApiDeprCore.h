///////////////////////////////////////////////////////////////////////////////
///
/// @file PrlApiDeprCore.h
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
#ifndef __PARALLELS_API_DEPR_CORE_H__
#define __PARALLELS_API_DEPR_CORE_H__


#include "PrlIOStructs.h"

/* Set a major version of a server part which uses SDK API.
   It uses to make properly links in error messages.
   Note: It works wrong when SDK connects to servers with different versions
   Parameters
      nMajorVersion: [in] Major version of a server part.
      nFlags: [unused] reserved parameter for further purposes
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_API_WASNT_INITIALIZED - when SDK is not initialized
   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
			PrlApi_SetMainServerVersion, (
		PRL_UINT32 nMajorVersion,
		PRL_UINT32 nFlags
		) );

/* Get a major version of server part of product which uses SDK API.
   It uses to make proper links in error messages.
   Note: It works wrong when SDK connects to servers with different versions
   Parameters
      pnMajorVersion: [in][out] A pointer to a variable that recieves the result
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_INVALID_ARG - invalid handle or null pointer was
   passed.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
			PrlApi_GetMainServerVersion, (
		PRL_UINT32_PTR pnMajorVersion
		) );

/* Get a name of product which uses SDK API.
   Parameters
      sProductName :    [out] A pointer to a buffer that
                           receives the result (a UTF\-8 encoded,
                           null\-terminated string).
      pnErrStringBufLength :  [in] The size of the output buffer (in
                           bytes). Set the buffer pointer to null
                           and this parameter's value to zero to
                           receive the required size. [out] The
                           required output buffer size.
   Returns
   PRL_RESULT. Possible values:
   PRL_ERR_BUFFER_OVERRUN - the size of the output buffer is not
   large enough. The parameter that is used to specify the size
   will contain the required size.

   PRL_ERR_SUCCESS - function completed successfully.       */
PRL_METHOD_DECL( PARALLELS_API_VER_6,
			PrlApi_GetProductName, (
 		PRL_STR sProductName,
		PRL_UINT32_PTR pnErrStringBufLength
		) );

#endif//__PARALLELS_API_DEPR_CORE_H__
