// Square Root
//
// square_root - sqrt
//
// f( x ) = √x
//        = x^( 1 / 2 )
//
// X_n - 1
// Y_n - 1
// C_n - 0
//
//


#include <tgmath.h>
#include "ts.h"


ts_parameter( root_square, 1, 1, 0 );


ts_function_define( root_square, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = sqrt( x[0][i] );
	}
}
