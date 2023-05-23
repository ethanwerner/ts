#include <assert.h>
#include <stddef.h>
#include "ts.h"


ts_parameter( average_weighted_series, 1, 1, 1 );


ts_function_define( average_weighted_series, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

    uint_t b[k];   // "circle" buffer
    uint_t bi = 0;

	fp_t sum = 0;

	while( xi < k )
	{
        b[bi] = x[0][xi] * x[1][xi];
		sum += b[bi];

		++xi;
		bi = _ts_circle_increment( bi, k );
	}

	y[0][yi - 1] = sum / k;
	uint_t tmp;

	while( xi < n )
	{
		tmp = b[bi];
		b[bi] = x[0][xi] * x[1][xi];

		y[0][yi] = y[0][yi - 1] + ( b[bi] - tmp ) / k;

		++xi;
		++yi;
		bi = _ts_circle_increment( bi, k );
	}
}