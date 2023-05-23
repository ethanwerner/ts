// Weighted Moving Average
//
// average_weighted - wma
//
// Weighted mean of previous k data points
//
// y[t] = SUM[ i = t, t - k]( x[t] *  (  ) )
//
// Inputs:    1
// Outputs:   1
// Constants: 1


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average_weighted, 1, 1, 1 );


ts_function_define( average_weighted, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t ); 
	
	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t sum = 0;
	fp_t wsum = 0;

	for( ; xi < k; ++xi )
	{
		sum += x[0][xi];
		wsum += x[0][xi] * ( xi + 1 );
	}

	fp_t rtri = 1.0 / _ts_triangle_number( k );

	y[0][yi - 1] = wsum * rtri;

	for( ; xi < n; ++xi, ++yi )
	{
		wsum = wsum + ( k * x[0][xi] ) - sum;
		sum = sum + x[0][xi] - x[0][xi - k];
		y[0][yi] = wsum * rtri;
	}
}