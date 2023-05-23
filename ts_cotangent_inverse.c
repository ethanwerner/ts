// Inverse Cotangent
//
// cotangent_inverse - acot
//
// f( x ) = acot( x )
//        = atan( 1 / x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cotangent_inverse, 1, 1, 0 );


ts_function_define( cotangent_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = atan( _ts_reciporical( x[0][i] ) );
	}
}