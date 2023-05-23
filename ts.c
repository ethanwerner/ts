#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "ts.h"


fp_t * ts_fill( fp_t *x, uint_t n, fp_t x0, fp_t x1 )
{
	fp_t step = ( x1 - x0 ) / ( n - 1 );

	if( x0 == 0.0 && x1 == 0.0 )
	{
		memset(x, 0, sizeof( fp_t ) * n );
	}

	else
	{
		for( uint_t i = 0; i < n; i++ )
		{
			x[i] = x0 + ( i * step );
		}
	}

	return x;
}


void ts_print( fp_t *x, uint_t n )
{
    fputc('[', stdout);

    uint_t i;
    for( i = 0; i < n - 1; i++ )
    {
        fprintf(stdout, "%f,", x[i]);
    }

    fprintf(stdout, "%f]", x[i]);
}


void ts_pretty_print( fp_t const * const *x, uint_t m, uint_t n )
{
    if( m > 1 )
    {
        for( uint_t i = 0; i < n; i++ )
        {
            uint_t j = 0;
            for( ; j < m; j++ )
            {
                fprintf( stdout, "%f  ", x[i][j] );
            }

            fputs( "\n", stdout );
        }
    }
    else
    {
        for( uint_t i = 0; i < n; i++ )
        {
            fprintf( stdout, "%f\n", x[0][i] );
        }
    }
}


fp_t _ts_square( fp_t x )
{
    return x * x;
}


fp_t _ts_reciporical( fp_t x )
{
    return 1.0 / x;
}


fp_t _ts_square_pyramidal_number( fp_t x )
{
    return ( x * ( x + 1 ) * ( 2 * x + 1 ) ) / 6;
}


fp_t _ts_triangle_number( fp_t x )
{
    return ( ( x ) * ( ( x ) + 1 ) ) * 0.5;
}


fp_t _ts_sum_to_covariance( fp_t sum_xy, fp_t sum_x, fp_t sum_y, uint_t k )
{
    return ( sum_xy - ( sum_x * sum_y / k ) ) / k;
}


fp_t _ts_sum_to_variance( fp_t sum_x2, fp_t sum_x, uint_t k )
{
    return _ts_sum_to_covariance( sum_x2, sum_x, sum_x, k );
}


uint_t _ts_circle_increment( uint_t i, uint_t k )
{
    return ( i + 1 ) % k;
}


// ts_constant_t * ts_constant_init( uint_t n, ... )
// {
//     va_list args;
//     va_start( args, n );

//     for( uint_t i = 0; i < n; i++ )
//     {

//     }
// }