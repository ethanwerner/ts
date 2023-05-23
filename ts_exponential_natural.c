// Natural Exponential
//
// exponential_natural - expn
//
// f( x ) = e^x
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( exponential_natural, 1, 1, 0 );


ts_function_define( exponential_natural, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = exp( x[0][i] );
	}
}