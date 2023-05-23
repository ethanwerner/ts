// Triple Exponential Moving Average
//
// average_exponential_triple - tema
//
// Inputs:    1
// Outputs:   1
// Constants: 1


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average_exponential_triple, 1, 1, 1 );


ts_function_define( average_exponential_triple, 0 )
{
	assert( c != NULL );

	fp_t a = ts_cast_byte( c, 0, fp_t );

    assert( a != 0 );

	fp_t ema1 = x[0][0];
	fp_t ema2 = x[0][0];
	fp_t ema3 = x[0][0];

	y[0][0] = x[0][0];

	for( uint_t i = 1; i < n; ++i )
	{
    	ema1 = ema1 + a * ( x[0][i] - ema1 );
    	ema2 = ema2 + a * ( ema1 - ema2 );
    	ema3 = ema3 + a * ( ema2 - ema3 );

		y[0][i] = 3 * ema1 - 3 * ema2 + ema3;
	}
}