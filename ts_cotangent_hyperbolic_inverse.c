// Inverse Hyperbolic Cotangent
//
// cottangent_hyperbolic_inverse - acoth
//
// f( x ) = acoth( x )
//        = 0.5 * ln( ( x + 1 ) / ( x - 1 ) )    |x| > 1
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cotangent_hyperbolic_inverse, 1, 1, 0 );


ts_function_define( cotangent_hyperbolic_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = atanh( _ts_reciporical( x[0][i]  ) );
	}
}