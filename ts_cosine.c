// Cosine
//
// cosine - cos
//
// f( x ) = cos( x )
//
// X_n - 1
// Y_n - 1
// C_n - 0


#include <tgmath.h>
#include "ts.h"


ts_parameter( cosine, 1, 1, 0 );


ts_function_define( cosine, 0 )
{
	for( uint_t i = 0; i < n; ++i )
	{
		y[0][i] = cos( x[0][i] );
	}
}