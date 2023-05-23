// Inverse Hyperbolic Sine
//
// sine_hyperbolic_inverse - asinh
//
// f( x ) = asinh( x )
//        = ln( x + √( x^2 + 1 ) )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( sine_hyperbolic_inverse, 1, 1, 0 );


ts_function_define( sine_hyperbolic_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = asinh( x[0][i] );
	}
}
