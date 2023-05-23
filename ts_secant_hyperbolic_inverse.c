// Inverse Hyperbolic Secant
//
// secant_hyperbolic_inverse - asech
//
// f( x ) = asech( x )
//        = ln( ( 1 / x ) + √( ( 1 / x^2 ) - 1 ) )    0 < x ≤ 1
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( secant_hyperbolic_inverse, 1, 1, 0 );


ts_function_define( secant_hyperbolic_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = acosh( _ts_reciporical( x[0][i] ) );
	}
}
