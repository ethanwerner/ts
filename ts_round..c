// Round
//
// round - round
//
// f( x ) = ⌊ x + 0.5 ⌋
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( round, 1, 1, 0 );


ts_function_define( round, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = round( x[0][i] );
	}
}
