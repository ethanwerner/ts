// Binary Logarithm
//
// logarithm_binary - logb, lb
//
// f( x ) = log_2( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( logarithm_binary, 1, 1, 0 );


ts_function_define( logarithm_binary, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = log2( x[0][i] );
	}
}