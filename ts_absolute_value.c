// Absolute Value
//
// absolute_value - abs
//
// y[t] = abs( x[t] )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <stddef.h>
#include <stdio.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( absolute_value, 1, 1, 0 );


ts_function_define( absolute_value, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = fabs( x[0][i] );
	}
}