// Inverse Hyperbolic Cosecant
//
// cosecant_hyperbolic_inverse - acsch
//
// f( x ) = acsch( x )
//        = ln( ( 1 / x ) + √( ( 1 / x^2 ) + 1 ) )    x ≠ 0
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cosecant_hyperbolic_inverse, 1, 1, 0 );


ts_function_define( cosecant_hyperbolic_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = asinh( _ts_reciporical( x[0][i] ) );
	}
}
