// Hyperbolic Tangent
//
// tangent_hyperbolic - tanh
//
// f( x ) = tanh( x )
//        = sinh( x ) / cosh( x )
//        = ( e^2x - 1 ) / ( e^2x + 1 )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( tangent_hyperbolic, 1, 1, 0 );


ts_function_define( tangent_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = tanh( x[0][i] );
	}
}
