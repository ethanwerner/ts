// Ceiling
//
// ceiling - ceil
//
// f( x ) = ⌈ x ⌉
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <stddef.h>
#include <tgmath.h>
#include "ts.h"


ts_parameter( ceiling, 1, 1, 0 );


ts_function_define( ceiling, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = ceil( x[0][i] );
	}
}