// Minimum
//
// minimum -  min
//
// Finds the minimum value in the past k data points
//
// Inputs:    1
// Outputs:   1
// Constants: 0

// TODO:
// - Test the shit out of this thing


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( minimum, 1, 1, 1 );


ts_function_define( minimum, ts_cast_byte( c, 0, uint_t) - 1 )
{
	assert( c != NULL );
	
	uint_t k = ts_cast_byte( c, 0, uint_t );
	assert( k != 0 );

	uint_t xi = k - 1;
	uint_t xj = 0;
	uint_t yi = 0;

	for( ; xi < n; xi++, xj++, yi++ )
	{
		y[0][yi] = x[0][xj++];

		for( uint_t i = xj; i <= xi; i++ )
		{
			if( x[0][i] < y[0][yi] )
			{
				y[0][yi] = x[0][i];
			}
		}
	}
}