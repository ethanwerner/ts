// Exponential Decay
//
// decay_exponential -  edecay
//
// DESCRIPTION
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( decay_exponential, 1, 1, 1 );


ts_function_define( decay_exponential, ts_cast_byte( c, 0, uint_t ) )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
    uint_t yi = 1;

	fp_t a = ( fp_t ) 1.0 - _ts_reciporical( k );

	for( ; xi < k; xi++ )
	{
		y[0][0] = fmax( x[0][xi], y[0][0] * a );
	}

	for( ; xi < n; xi++, yi++ )
	{
		y[0][yi] = fmax( x[0][xi], y[0][yi - 1] * a );
	}
}