#include <string.h>
#include "ts.h"


ts_parameter( none, 1, 1, 0 );


ts_function_define( none, 0 )
{
	memcpy( y[0], x[0], sizeof( fp_t ) * n );
}