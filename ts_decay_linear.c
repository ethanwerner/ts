// Linear Decay
//
// decay_linear -  decay
//
// Propogates the maximum values of a function into the future for at most k periods
//
// y_i = max( x_i, y_i-1 - k )
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( decay_linear, 1, 1, 0 );


ts_function_define( decay_linear, ts_cast_byte( c, 0, uint_t ) )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

    uint_t xi = 1;
    uint_t yi = 1;

	fp_t decay = x[0][0];
    y[0][0] = x[0][0];

    fp_t r = decay / k;

	for( ; xi < k; xi++ )
	{
	    y[0][0] -= r;

	    if( x[0][xi] > y[0][0] )
	    {
	        y[0][0] = x[0][xi];
	        r = x[0][xi] / k;
	    }
	    else
	    {
            y[0][0] = fmax( y[0][0], 0 );
        }
	}

	for( ; xi < n; xi++, yi++ )
	{
	    y[0][yi] = y[0][yi -1] - r;

	    if( x[0][xi] > y[0][yi] )
	    {
	        y[0][yi] = x[0][xi];
	        r = x[0][xi] / k;
	    }
	    else
	    {
            y[0][yi] = fmax( y[0][0], 0 );
        }
	}
}
