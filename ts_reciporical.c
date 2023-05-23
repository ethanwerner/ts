// Reciporical
//
// reciporical - rec
//
// f( x ) = 1 / x
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include "ts.h"


ts_parameter( reciporical, 1, 1, 0 );


ts_function_define( reciporical, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = _ts_reciporical( x[0][i] );
	}
}
