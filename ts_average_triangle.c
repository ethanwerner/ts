// Triangular Moving Average
//
// average_triangle - tma
//
// A moving average of moving averages
//
// y[i] = 
// 
// Inputs:    1
// Outputs:   1
// Constants: 1
//
// 012345678901234567890123456789
// ---------01234567890123456
// ------------------0


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average_triangle, 1, 1, 1 );


ts_function_define( average_triangle, 2 * ( ts_cast_byte( c, 0, uint_t ) - 1 ) )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	fp_t rk2 = _ts_reciporical( _ts_square( k ) );
	uint_t xi = 0;
	uint_t yi = 0;

	fp_t xsum[k];
	uint_t xsumi = 0;

	fp_t sum_of_xsum = 0;

    xsum[0] = 0;

	for( ; xi < k; xi++ )
	{
		xsum[xsumi] += x[0][xi];
	}

    sum_of_xsum = xsum[xsumi];
    xsumi++;

	for( ; xi < 2 * k - 1; xi++ )
	{
	    xsum[xsumi] = xsum[xsumi - 1] + x[0][xi] - x[0][xi - k];
	    sum_of_xsum += xsum[xsumi];
   		xsumi++;
	}

	y[0][yi++] = sum_of_xsum * rk2;

	for( ; xi < n; ++xi, ++yi )
	{
	    if( xsumi == k )
	    {
	        xsumi = 0;
       	    sum_of_xsum -= xsum[xsumi];
	        xsum[xsumi] = xsum[k - 1] + x[0][xi] - x[0][xi - k];
	    }
	    else
	    {
    	    sum_of_xsum -= xsum[xsumi];
	        xsum[xsumi] = xsum[xsumi - 1] + x[0][xi] - x[0][xi - k];
	    }

        sum_of_xsum += xsum[xsumi];
		y[0][yi] = sum_of_xsum * rk2;

		xsumi++;
	}
}