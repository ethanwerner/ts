// Lag
//
// lag -  lag
//
// DESCRIPTION
//
// Inputs:    1
// Outputs:   1
// Constants: 2


#include <assert.h>
#include <stddef.h>
#include <string.h>
#include "ts.h"


ts_parameter( lag, 1, 1, 1 );


ts_function_define( lag, -1 * ts_cast_byte( c, 0, uint_t ) )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );
	assert( k != 0 );

	fp_t insert = ts_cast_byte( c, sizeof( uint_t ), fp_t );

	memset( y[0], insert, sizeof( fp_t ) * k );
	memcpy( &( y[0][k] ), x[0], sizeof( fp_t ) * ( n - k ) );
}