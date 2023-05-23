// Inverse Hyperbolic Tangent
//
// tangent_hyperbolic_inverse - atanh
//
// f( x ) = atanh( x )
//        = 0.5 * ln( ( 1 + x ) / ( 1 - x ) )    |x| < 1
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( tangent_hyperbolic_inverse, 1, 1, 0 );


ts_function_define( tangent_hyperbolic_inverse, ts_cast_byte( c, 0, uint_t ) - 1 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = atanh( x[0][i] );
	}
}
