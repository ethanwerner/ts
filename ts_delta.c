// Delta
//
// delta - delta
//
// Calculates the delta between the current value and the value k samples ago
//
// y_i = x_i - x_i-k
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( delta, 1, 1, 1 );


ts_function_define( delta, ts_cast_byte( c, 0, uint_t ) )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = k;
	uint_t yi = 0;

	for( ; xi < n; xi++, yi++ )
	{
		y[0][yi] = x[0][xi] - x[0][xi - k];
	}
}
