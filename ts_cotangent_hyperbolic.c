// Hyperbolic Cotangent
//
// cotangent_hyperbolic - coth
//
// f( x ) = coth( x )
//        = 1 / tanh( x )
//        = cosh( x ) / sinh( x )
//        = ( e^2x + 1 ) / ( e^2x - 1 )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cotangent_hyperbolic, 1, 1, 0 );


ts_function_define( cotangent_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( tanh( x[0][i] ) );
	}
}