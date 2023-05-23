// Exponential
//
// exponential - exp
//
// f( x ) = b^x
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


ts_parameter( exponential, 1, 1, 1 );


ts_function_define( exponential, 0 )
{
	assert( c != NULL );

	fp_t b = ts_cast_byte( c, 0, uint_t );

	assert( b != 0 );

	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = pow( b, x[0][i] );
	}
}