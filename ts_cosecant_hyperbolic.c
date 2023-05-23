// Hyperbolic Cosecant
//
// cosecant_hyperbolic - csch
//
// f( x ) = csch( x )
//        = 1 / sinh( x )
//        = 2 / ( e^x - e^( -x ) )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cosecant_hyperbolic, 1, 1, 0 );


ts_function_define( cosecant_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( sinh( x[0][i] ) );
	}
}