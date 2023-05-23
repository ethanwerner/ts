// Addition
//
// addition - add
//
// y[t] = x[0][t] + x[1][t]
//
// X_n - 2
// Y_n - 1
// C_n - 0


#include <stddef.h>
#include <stdio.h>
#include "ts.h"


ts_parameter( addition, 2, 1, 0 );


ts_function_define( addition, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = x[0][i] + x[1][i];
	}
}