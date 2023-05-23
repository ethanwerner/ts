#include <stddef.h>
#include "ts.h"
#include "assert.h"


ts_parameter( relative_strength, 1, 1, 0 );

static inline void relative_strength( fp_t *u, fp_t *d, fp_t const *x ) {
	if( x[0] > x[-1] )
	{
		*u = x[0] - x[-1];
		*d = 0;
	}
	else 
	{
		*u = 0;
		*d = x[-1] - x[0];
	}
}

ts_function_define( relative_strength, ts_cast_byte( c, 0, uint_t ) - 1 )
{
 	assert( c != NULL );

	uint_t k = ts_cast_byte( c, 0, uint_t );

	assert( k != 0 );

	uint_t xi = 0;
	uint_t yi = 0;

	fp_t sum_d, sum_u;
	fp_t u[k];
	fp_t d[k];
	uint_t ki = 0;

	for( ; xi < k; ++xi )
	{
		relative_strength( &u[ki], &d[ki], &x[0][xi] );
		
		sum_d += d[ki];
		sum_u += u[ki];
		++ki;
	}

	y[0][yi] = sum_u / sum_d;

	fp_t tmp_u, tmp_d;

	for( ; xi < n; ++xi, ++yi )
	{
		relative_strength( &tmp_u, &tmp_d, &x[0][xi] );
		sum_d += tmp_d - d[ki];
		sum_u += tmp_u - u[ki];
		d[ki] = tmp_d;
		u[ki] = tmp_u;

		y[0][yi] = sum_u / sum_d;
	}
}
