// Variance
//
// variance - smv
//
// Calculates the moving variance
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( variance, 1, 1, 1 );


ts_function_define( variance, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );
	
	uint_t k = ts_cast_byte( c, 0, uint_t );
	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t sum = 0;  // Sum of terms
	fp_t sum2 = 0; // Sum of squared terms
	fp_t mean;     // Mean
	fp_t mean2;    // Mean of squares

	for( ; xi < k; ++xi )
	{
		sum += x[0][xi];
		sum2 += _ts_square( x[0][xi] );

		mean = sum / ( xi + 1 );
		mean2 = sum2 / ( xi + 1 );
	}

    fp_t rk = _ts_reciporical( k );

	for( ; xi < n; ++xi, ++yi )
	{
		mean = mean + ( x[0][xi] - x[0][xi - k] ) * rk;
		mean2 = mean2 + ( _ts_square( x[0][xi] ) - _ts_square( x[0][xi - k] ) ) * rk;

		y[0][yi] = mean2 - _ts_square( mean );
	}
}