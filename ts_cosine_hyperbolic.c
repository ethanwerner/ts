// Hyperbolic Cosine
//
// cosine_hyperbolic - cosh
//
// f( x ) = cosh( x )
//        = 0.5 * ( e^x + e^( -x ) )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cosine_hyperbolic, 1, 1, 0 );


ts_function_define( cosine_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = cosh( x[0][i] );
	}
}