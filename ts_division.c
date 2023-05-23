// Division
//
// division - div
//
// f( x_0, x_1 ) = x_0 / x_1
//
// X_n - 2
// Y_n - 1
// C_n - 0


#include "ts.h"


ts_parameter( division, 1, 1, 0 );


ts_function_define( division, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = x[0][i] / x[1][i];
	}
}