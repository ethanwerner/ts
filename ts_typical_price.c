#include "ts.h"


ts_parameter( typical_price, 5, 1, 0 );


ts_function_define( typical_price, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = ( x[1][i] + x[2][i] + x[3][i] ) / 3;
	}
}
