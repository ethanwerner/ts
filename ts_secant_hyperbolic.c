// Hyperbolic Secant
//
// secant_hyperbolic - sech
//
// f( x ) = sech( x )
//        = 1 / cosh( x )
//        = 2 / ( e^x + e^( -x ) )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( secant_hyperbolic, 1, 1, 0 );


ts_function_define( secant_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( cosh( x[0][i] ) );
	}
}
