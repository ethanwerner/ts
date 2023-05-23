// Summation
//
// summation - sum
//
// Calculates the sum of the past k values
//
// y_i = sum_{j=i-k+1}^{i}[x_j]
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( summation, 1, 1, 1 );


ts_function_define( summation, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );
	assert( k != 0 );
	
	uint_t xi = 0;
	uint_t yi = 1;

	y[0][0] = 0;

	for( ; xi < k; xi++ )
	{
		y[0][0] += x[0][xi];
	}

	for( ; xi < n; xi++, yi++ )
	{
		y[0][yi] = x[0][xi] + y[0][yi - 1] - x[0][xi - k];
	}
}
