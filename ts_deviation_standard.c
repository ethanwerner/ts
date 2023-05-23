// Moving Standard Deviation
//
// standard_deviation - sd
//
// Inputs:    1
// Outputs:   1
// Constants: 0

// TODO:
//   - Convert to using static array for x2

#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( deviation_standard, 1, 1, 1 );


ts_function_define( deviation_standard, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t mean = 0;     // Mean
	fp_t mean2 = 0;    // Mean of squares

	for( ; xi < k; ++xi )
	{
		mean += x[0][xi];
		mean2 += _ts_square( x[0][xi] );
	}

    mean /= k;
	mean2 /= k;

    fp_t rk = _ts_reciporical( k );

	for( ; yi < n; ++xi, ++yi )
	{
		mean = mean + ( x[0][xi] - x[0][xi - k] ) * rk;
		mean2 = mean2 + ( _ts_square( x[0][xi] ) - _ts_square( x[0][xi - k] ) ) * rk;

		y[0][yi] = sqrt( mean2 - _ts_square( mean ) );
	}
}