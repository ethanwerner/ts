// Moving Mean Deviation
//
// mean_deviation - md
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( deviation_average, 1, 1, 1 );


ts_function_define( deviation_average, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t mean = 0;

	for( ; xi < k; ++xi )
	{
		mean += x[0][xi];
	}

    fp_t rk = _ts_reciporical( k );
	mean = rk * mean;
    fp_t sum;

	// TODO look into single pass variation
	for( ; yi < n; ++xi, ++yi )
	{
		mean = mean + ( x[0][xi] - x[0][xi - k] ) * rk;
        sum = 0;

        for( uint_t i = xi - k + 1; i <= xi; i++ )
        {
            fp_t tmp = x[0][i] - mean;
            sum += fabs( tmp );
        }

        y[0][yi] = sum * rk;
	}
}