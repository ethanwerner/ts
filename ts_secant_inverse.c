// Inverse Secant
//
// secant_inverse - asec
//
// f( x ) = asec( x )
//        = acos( 1 / x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( secant_inverse, 1, 1, 0 );


ts_function_define( secant_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = acos( _ts_reciporical( x[0][i] ) );
	}
}
