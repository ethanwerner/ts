// Cube Root
//
// cube_root - cbrt
//
// f( x ) = ∛x
//        = x^( 1 / 3 )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( root_cube, 1, 1, 0 );


ts_function_define( root_cube, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = cbrt( x[0][i] );
	}
}
