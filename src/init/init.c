#include <stdlib.h>
#include "../obj/obj.h"
#include "init.h"

extern pie_NAMESPACE pie_GlobalNamespace, pie_CurrentNamespace;

extern const pie_OBJ pie_True, pie_False, pie_Null;

void pie_init()
{
	pie_GlobalNamespace.len = 3;

	pie_GlobalNamespace.names = malloc(3 * sizeof(pie_NAME));

	pie_GlobalNamespace.names[0].name.len = 4;
	pie_GlobalNamespace.names[0].name.ptr = "true";
	pie_GlobalNamespace.names[0].obj      = pie_True;

	pie_GlobalNamespace.names[1].name.len = 5;
	pie_GlobalNamespace.names[1].name.ptr = "false";
	pie_GlobalNamespace.names[1].obj      = pie_False;

	pie_GlobalNamespace.names[2].name.len = 4;
	pie_GlobalNamespace.names[2].name.ptr = "null";
	pie_GlobalNamespace.names[2].obj      = pie_Null;

	pie_GlobalNamespace.parent = 0;

	pie_CurrentNamespace = pie_GlobalNamespace;
}

void pie_exit(int status)
{
	exit(status);
}
