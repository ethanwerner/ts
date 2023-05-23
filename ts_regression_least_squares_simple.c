// Simple Least Squares Moving Linear Regression
//
// regression_linear_simple_least_squares - slrls
//
//        ((k * sum_{i=0}^{n}[x_i * y_i]) - (sum_{i=0}^{n}[x_i] * sum_{i=0}^{n}[y_i]))
//   β = ────────────────────────────────────────────────────────────────────────
//                 ((k * sum_{i=0}^{n}[x_i^2]) - (sum_{i=0}^{n}[x_i^2])^2)
//
//   α = E(y) - β * E(x)
//     = μ_y - β * μ_x
//
//          ( E( xy ) - E( μ_x ) * E( μ_y ) )
//   r_xy = ────────────────────────────────────────────────────────────────────────
//          ((E(x^2) - E(x)^2) - (E(y^2) - E(y)^2))^(1 / 2)
//
//   y = α + βx
//
// Inputs:    2
// Outputs:   3
// Constants: 0


#include <assert.h>
#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( regression_linear_least_squares, 2, 3, 1 );


ts_function_define( regression_linear_least_squares, ts_cast_byte( c, 0, uint_t ) )
{
	assert( c != NULL );
	
	uint_t k = ts_cast_byte( c, 0, uint_t );
	assert( k != 0 );
	
	uint_t xi = 0;
	uint_t yi = 0;
	uint_t ki = 0;

    // Current sums of the past k values
    fp_t sum_x = 0;
	fp_t sum_x2 = 0;
	fp_t sum_y = 0;
	fp_t sum_y2 = 0;
	fp_t sum_xy = 0;

	fp_t var_x, var_y, cov_xy;

	for( ; xi < k; xi++, ki++ )
	{
	    sum_x += x[0][xi];
	    sum_x2 += _ts_square( x[0][xi] );

	    sum_y += x[1][xi];
   	    sum_y2 += _ts_square( x[1][xi] );

		sum_xy += x[0][xi] * x[1][xi];
	}

    // Calculate the  component of the r_xy denominator
    //   Var(x) = E(x^2) - E(x)^2

	for( ; xi < n; ++xi, ++yi )
	{
		sum_xy = sum_xy + ( k * x[0][xi] ) - sum_y;
		sum_y = sum_y + x[0][xi] - x[0][xi - k];
		sum_y2 = sum_y2 + ( _ts_square( x[0][xi] ) - _ts_square( x[0][xi - k] ) );

        var_y = _ts_sum_to_variance( sum_y2, sum_y, k );
        var_x = _ts_sum_to_variance( sum_x2, sum_x, k );
        cov_xy = _ts_sum_to_covariance( sum_xy, sum_x, sum_y, k );

		y[0][yi] = cov_xy / var_x;
		y[1][yi] = ( sum_y / k ) - ( y[0][yi] * sum_x / k );
		y[2][yi] = cov_xy / sqrt( var_x * var_y );
	}
}
