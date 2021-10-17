///////////////////////////////////////////////////////////////////////////////
///
/// PrlErrors.h
///
/// This file is the part of parallels public sdk library
///
///
/// Copyright (c) Parallels International GmbH.
/// All rights reserved.
/// http://www.parallels.com
///
///////////////////////////////////////////////////////////////////////////////

#ifndef __PARALLELS_API_ERRORS_H__
#define __PARALLELS_API_ERRORS_H__

#ifdef __cplusplus
extern "C" {
#endif

// Declare PRL_RESULT
#include "PrlTypes.h"

/**
 * Success and failure result codes
 */
#define PRL_SUCCEEDED( err )	( ( PRL_RESULT )( err ) >= 0 )
#define PRL_FAILED( err )	( ( PRL_RESULT )( err ) < 0 )


/**
 * Declaration of the error value goes here
 */
#define PRL_RESULT_DECLARE_ERROR( err ) ( (PRL_RESULT) (0x80000000 + 0x##err) )
#define PRL_RESULT_DECLARE_SUCCESS( err ) ( (PRL_RESULT) (err) )

/**
 * Actual errors values are kept in the externally-generated header
 */
#include "PrlErrorsValues.h"

/**
 * Actual events values are kept in the externally-generated header
 */
#include "PrlEventsValues.h"


/**
 * Success license state
 */
#define PRL_LICENSE_IS_VALID(x)	\
	( (PRL_RESULT) ( ( (x) == PRL_ERR_LICENSE_VALID ) || \
		( (x) == PRL_ERR_LICENSE_GRACED ) ) )

#define PRL_LICENSE_IS_EXPIRED( x )	\
	( ( (x) == PRL_ERR_LICENSE_EXPIRED ) || \
	 	( (x) == PRL_ERR_LIC_GET_TRIAL_EXPIRED ) || \
	 	( (x) == PRL_ERR_LICENSE_SUBSCR_EXPIRED ) || \
		( (x) == PRL_ERR_LICENSE_VOLUME_EXPIRED ) || \
		( (x) == PRL_ERR_VZLICENSE_KA_LICENSE_EXPIRED ) )

#ifdef __cplusplus
}
#endif

#endif // __PARALLELS_API_ERRORS_H__
