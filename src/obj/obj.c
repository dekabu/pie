#include "obj.h"
#include <string.h>

extern pie_Obj pie_CurrentObj;

int pie_FindObj(pie_Namespace ns, char* s)
{
	register unsigned i;

	for (i = 0; i < ns.len; ++i)
		if (!strcmp(s, ns.names[i].name)) {
			pie_CurrentObj = ns.names[i].obj;
			return 1;
		}
	return 0;
}
