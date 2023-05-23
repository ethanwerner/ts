// Cotangent
//
// cotangent - cot
//
// f( x ) = cot( x ) = 1 / tan( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cotangent, 1, 1, 0 );


ts_function_define( cotangent, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( tan( x[0][i] ) );
	}
}