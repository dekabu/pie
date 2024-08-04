#include <stdio.h>
#include "obj/obj.h"
#include "init/init.h"

pie_OBJ pie_CurrentObj;

const pie_OBJ pie_True  = {pie_bool_t, {0}};
const pie_OBJ pie_False = {pie_bool_t, {1}};
const pie_OBJ pie_Null  = {pie_null_t};

pie_NAMESPACE pie_GlobalNamespace, pie_CurrentNamespace;

int main()
{
	pie_STR name = {5, "false"};

	pie_init();

	printf("%i\n", pie_find(name));

	pie_exit(0);
}
