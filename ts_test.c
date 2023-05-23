#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "ts.h"


void _ts_assert_approximate( fp_t y0, fp_t y1, fp_t e )
{
	assert( ( fabs( y0 - y1 ) <= e ) );
}


bool _ts_is_approximate( fp_t y0, fp_t y1, fp_t e )
{
    return ( fabs( y0 - y1 ) <= e );
}


bool ts_test(
	void ( *ts_function )(
        fp_t * const *y, 
	    fp_t const * const *x, 
		uint_t n, 
		ts_constant_t const *c 
    ),
    uint_t ( *ts_offset )( 
        ts_constant_t const *c 
    ),
	fp_t const * const *x,
	fp_t const * const *e,
	uint_t n,
	ts_constant_t const *c,
    ts_parameter_t const *m )
{                                                                       
	uint_t offset = ts_offset( c );
	uint_t y_n = n - offset;
    bool result = true;
                                                               
	fp_t *y[m->y];

    for( uint_t i = 0; i < m->y; i++ )
    {
        fp_t *tmp = malloc( y_n * sizeof( fp_t ) );
        y[i] = tmp;
    }

	ts_function( y, x, n, c );                       

    for( uint_t i = 0; i < m->y; ++i )
    {
    	for( uint_t j = 0; j < y_n; ++j )                                     
	    {
		    // _ts_assert_approximate( y[i][j], e[i][j], TS_TEST_EPSILON ); 
		    result &= _ts_is_approximate( y[i][j], e[i][j], TS_TEST_EPSILON ); 
	    }                                                                     

        free( y[i] );
    }

    return result;
}


#define ANSI_IMPLEMENTATION
#include "../escape/escape.h"


#define _ts_test_print( FUNCTION )                        \
    FUNCTION ?                                            \
        fputs( ANSI_SGR_FG_RGB( 0, 255, 0 ) , stdout ) :  \
        fputs( ANSI_SGR_FG_RGB( 255, 0, 0 ) , stdout );   \
                                                          \
    fputs( #FUNCTION, stdout );                            \
    fputs( "\n", stdout )


void ts_test_all( void )
{
    _ts_test_print( ts_absolute_value_test() );
    _ts_test_print( ts_addition_test() );
    _ts_test_print( ts_average_cumulative_test() );
    _ts_test_print( ts_average_exponential_test() );
    _ts_test_print( ts_ceiling_test() );
}


bool ts_absolute_value_test( void )
{
	fp_t const x0[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
	fp_t const e0[] = {  4,  3,  2,  1, 0, 1, 2, 3, 4 };

	fp_t const * const x[1] = { x0 };
	fp_t const * const e[1] = { e0 };

	return ts_test( 
		ts_absolute_value, 
		ts_absolute_value_offset,
		x,
		e,
		sizeof( x0 ) / sizeof( *x0 ),
		NULL,
		&ts_absolute_value_p
	);
}


bool ts_addition_test( void )
{
	fp_t x0[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
	fp_t x1[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4 };
	fp_t e0[] = { -8, -6, -4, -2, 0, 2, 4, 6, 8 };

	fp_t const * const x[] = { x0, x1 };
	fp_t const * const e[] = { e0 };

	return ts_test( 
		ts_addition, 
		ts_addition_offset,
		x,
		e,
		sizeof( x0 ) / sizeof( *x0 ),
		NULL,
		&ts_addition_p
	);
}


bool ts_average_cumulative_test( void )
{
	fp_t const x0[] = { -10, -9,   -8, -7,   -6, -5,   -4, -3,   -2, -1,    0,  1,    2,  3,    4,  5,    6,  7,    8,  9,   10 };
	fp_t const e0[] = { -10, -9.5, -9, -8.5, -8, -7.5, -7, -6.5, -6, -5.5, -5, -4.5, -4, -3.5, -3, -2.5, -2, -1.5, -1, -0.5, 0  };

	fp_t const * const x[1] = { x0 };
	fp_t const * const e[1] = { e0 };

	return ts_test( 
		ts_average_cumulative, 
		ts_average_cumulative_offset,
		x,
		e,
		sizeof( x0 ) / sizeof( *x0 ),
		NULL,
		&ts_average_cumulative_p
	);
}


bool ts_average_exponential_test( void )
{
	fp_t const x0[] = { -10, -7.5, -5, -2.5, 0, 2.5, 5, 7.5, 10 };
	fp_t const e0[] = { -10, -8.75, -6.875, -4.6875, -2.34375, 0.078125, 2.5390625, 5.01953125, 7.509765625 };

	fp_t const * const x[1] = { x0 };
	fp_t const * const e[1] = { e0 };

	fp_t c = 2;

	return ts_test( 
		ts_average_exponential,
		ts_average_exponential_offset,
		x,
		e,
		sizeof( x0 ) / sizeof( *x0 ),
		&c,
		&ts_average_exponential_p
	);
}


bool ts_ceiling_test( void )
{
	fp_t const x0[] = { -4.4, -3.2, -2.2, -1.1, 0, 1.1, 2.2, 3.3, 4.4 };
	fp_t const e0[] = { -4,   -3,   -2,   -1,   0, 2,   3,   4,   5 };

	fp_t const * const x[1] = { x0 };
	fp_t const * const e[1] = { e0 };

	return ts_test( 
		ts_ceiling, 
		ts_ceiling_offset,
		x,
		e,
		sizeof( x0 ) / sizeof( *x0 ),
		NULL,
		&ts_ceiling_p
	);
}