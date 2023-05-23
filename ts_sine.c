// Sine
//
// sine - sin
//
// f( x ) = sin( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( sine, 1, 1, 0 );


ts_function_define( sine, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = sin( x[0][i] );
	}
}
