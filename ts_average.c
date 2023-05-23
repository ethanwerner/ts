// Simple Moving Average
//
// average_simple - sma
//
// Unweighted mean of previous k data points
//
// SMA_k = ( 1 / k ) * SUM[ i = 1, k ] x_i
//
// Initial Values
//
//   Cumulative moving average to n = k
//
// Succesive Value
//
//   SMA_n = x_n-1 + ( 1 / n )( x_n - x_n-1 )
//
// Inputs:    1
// Outputs:   1
// Constants: 1


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average, 1, 1, 1 );


ts_function_define( average, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t sum = 0;

	for( ; xi < k; ++xi )
	{
		sum += x[0][xi];
	}

	y[0][yi - 1] = sum / k;

	for( ; xi < n; ++xi, ++yi )
	{
		y[0][yi] = y[0][yi - 1] + ( x[0][xi] - x[0][xi - k] ) / k;
	}
}