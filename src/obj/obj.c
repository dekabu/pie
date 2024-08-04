#include <string.h>
#include "obj.h"

extern pie_OBJ pie_CurrentObj;
extern pie_NAMESPACE pie_CurrentNamespace;

int pie_find(pie_STR name)
{
	register unsigned i;
	pie_NAMESPACE     nmsp = pie_CurrentNamespace;

	while (1) {
		for (i = 0; i < nmsp.len; ++i)
			if (nmsp.names[i].name.len == name.len && !strncmp(nmsp.names[i].name.ptr, name.ptr, name.len)) {
				pie_CurrentObj = nmsp.names[i].obj;
				return 1;
			}
		if (!nmsp.parent)
			return 0;
		else
			nmsp = *nmsp.parent;
	}
}
