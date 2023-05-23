// Crossover
//
// crossover - crossover
//
//       ⎧ -1 if x0_i < x1_i and x0_i-1 > x1_i-1
// y_i = ⎨ 0 if x = 0
//       ⎩ 1 if x0_i > x1_i and x0_i-1 < x1_i-1
//
// Inputs:    2
// Outputs:   1
// Constants: 0


#include "ts.h"


ts_parameter( crossover, 2, 1, 0 );


ts_function_define( crossover, 0 )
{
	uint_t xi;
	uint_t yi;

	xi = 1;
	yi = 0;

	for( ; xi < n; xi++, yi++ )
	{
		if( x[0][xi] > x[1][xi] && x[0][xi - 1] <= x[1][xi] )
			y[0][yi] = 1;

		else if( x[0][xi] > x[1][xi] && x[0][xi - 1] <= x[1][xi] )
			y[0][yi] = -1;

		else
			y[0][yi] = 0;
	}
}