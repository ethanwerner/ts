// Natural Logarithm
//
// logarithm_natural - logn, ln
//
// f( x ) = log_e( x )
//        = ln( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( logarithm_natural, 1, 1, 0 );


ts_function_define( logarithm_natural, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = log( x[0][i] );
	}
}