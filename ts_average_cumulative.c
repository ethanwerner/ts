// Cumulative Moving Average
//
// average_cumulative - cma
//
// Average of all data to the current point
//
//   y[t] = ( 1 / k ) * SUM[ t = 1, k ]( x[t] )
//
// Inputs:    1
// Outputs:   1
// Constants: 0


#include <stddef.h>
#include "ts.h"


ts_parameter( average_cumulative, 1, 1, 0 );


ts_function_define( average_cumulative, 0 )
{
	fp_t sum = 0;

	for( uint_t i = 0; i < n; ++i )
	{
		sum += x[0][i];
		y[0][i] = sum / ( i + 1 );
	}
}