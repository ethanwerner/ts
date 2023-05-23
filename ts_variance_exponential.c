// Exponential Variance
//
// variance_exponential
//
// Inputs:    1
// Outputs:   1
// Constants: 0

// TODO:
//   - TS_PAD


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( variance_exponential, 1, 1, 1 );


ts_function_define( variance_exponential, 0 )
{
	assert( c != NULL );

	fp_t a = ts_cast_byte( c, 0, fp_t );
	assert( a != 0 );

	y[0][0] = x[0][0];

	fp_t delta;
	fp_t ema;

	for( uint_t i = 1; i < n; ++i )
	{
		delta = x[0][i] - ema;
		ema = ema + a * delta;
		y[0][i] = ( 1 - a ) * ( y[0][i - 1] + a * _ts_square( delta ) );
	}
}