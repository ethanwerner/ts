// Inverse Tangent
//
// tangent_inverse - atan
//
// f( x ) = atan( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( tangent_inverse, 1, 1, 0 );


ts_function_define( tangent_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = atan( x[0][i] );
	}
}
