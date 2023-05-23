// Logarithm
//
// logarithm - log
//
// f( x ) = log_b( x )
//
// X_n - 1
// Y_n - 1
// C_n - 1
//
// c[0] = b


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( logarithm, 1, 1, 1 );


ts_function_define( logarithm, 0 )
{
	assert( c != NULL );

	fp_t b = ts_cast_byte( c, 0, fp_t );
	assert( b != 0 );
	
    b = _ts_reciporical( log( b ) );

	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = log( x[0][i] ) * b;
	}
}