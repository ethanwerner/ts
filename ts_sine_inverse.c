// Inverse Sine
//
// sine_inverse - asin
//
// f( x ) = asin( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( sine_inverse, 1, 1, 0 );


ts_function_define( sine_inverse, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = asin( x[0][i] );
	}
}
