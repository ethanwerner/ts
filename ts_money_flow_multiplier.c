#include "ts.h"


ts_parameter( money_flow_multiplier, 5, 1, 0 );

// ( ( c - l ) - ( h - c ) ) / ( h - l )
ts_function_define( money_flow_multiplier, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		// ( )
		y[0][i] = ( ( x[3][i] - x[1][i] ) - ( x[0][i] - x[2][i] ) ) / ( x[0][i] - x[1][i] );
	}
}
