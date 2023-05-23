// Decimal Logarithm
//
// logarithm_decimal - logd, ld
//
// f( x ) = log_10( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( logarithm_decimal, 1, 1, 0 );


ts_function_define( logarithm_decimal, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = log10( x[0][i] );
	}
}