// Hyperbolic Sine
//
// sine_hyperbolic - sinh
//
// f( x ) = sinh( x )
//        = 0.5 * ( e^x - e^( -x ) )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( sine_hyperbolic, 1, 1, 0 );


ts_function_define( sine_hyperbolic, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = sinh( x[0][i] );
	}
}
