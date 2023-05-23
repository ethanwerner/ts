// Nth Root
//
// n_root - nrt
//
// f( x ) = x^( 1 / n )
//
// X_n - 1
// Y_n - 1
// C_n - 1
//
// c[0] = n


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( root, 1, 1, 1 );


ts_function_define( root, 0 )
{
	assert( c != NULL );

	fp_t r = ts_cast_byte( c, 0, fp_t );

	assert( r != 0 );

	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = pow( x[0][i], _ts_reciporical( r ) );
	}
}
