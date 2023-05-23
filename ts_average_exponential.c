// Exponential Moving Average
//
// average_exponential - ema
//
// Weighted moving average with exponentially decreasing weights determined by
// the constant c
//
// y[0] = x[0]
// y[t] = a * x[t] + ( 1 - a ) * EMA[t - 1]
// a = 1 / k;
//
// Inputs:    1
// Outputs:   1
// Constants: 1


#include <assert.h>
#include <stdarg.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average_exponential, 1, 1, 1 );


ts_function_define( average_exponential, 0 )
{
	assert( c != NULL );
	
	fp_t k = ts_cast_byte( c, 0, fp_t );

	assert( k != 0 );

	fp_t a = 1 / k;

	y[0][0] = x[0][0];

	for( uint_t i = 1; i < n; ++i )
	{
		y[0][i] = y[0][i - 1] + a * ( x[0][i] - y[0][i - 1] );
	}
}