#include <stddef.h>
#include <stdio.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( true_range, 4, 1, 1 );


ts_function_define( true_range, 1 )
{
	for( uint_t i = 1; i < n; ++i )
	{
		y[0][i] = fmax( ( ts_h( x, i ) - ts_l( x, i ) ),
		                fmax( fabs( ts_h( x, i ) - ts_c( x, i - 1 ) ),
						      fabs( ts_l( x, i ) - ts_c( x, i - 1 ) ) ) );
	}
}