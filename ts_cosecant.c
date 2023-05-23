// Cosecant
//
// cosecant - csc
//
// f( x ) = csc( x ) = 1 / sin( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cosecant, 1, 1, 0 );


ts_function_define( cosecant, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( sin( x[0][i] ) );
	}
}