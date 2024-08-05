#include <stdio.h>
#include <string.h>
#include "config.h"
#include "base/base.h"
#include "obj/obj.h"
#include "init/init.h"

pie_SETTINGS pie_Settings = {
	PIE_COLOR,
	PIE_ANSI
};

pie_OBJ pie_CurrentObj;

const pie_OBJ pie_True  = {pie_bool_t, {1}};
const pie_OBJ pie_False = {pie_bool_t, {0}};
const pie_OBJ pie_Null  = {pie_null_t};

pie_NAMESPACE pie_GlobalNamespace, pie_CurrentNamespace;

int main(int argc, char* argv[])
{
	register int i, j;
	unsigned     break_for;
	char*        str;

	for (i = 1; i < argc; ++i) {
		break_for = 0;
		str = argv[i];
		for (j = 0; j < strlen(str); ++j)
			if (str[j] == '=') {
				str[j] = 0;
				if (!strcmp(str, "--color")) {
					str += j + 1;
					if (!strcmp(str, "on"))
						pie_Settings.color = 1;
					else if (!strcmp(str, "off"))
						pie_Settings.color = 0;
					else {
						fprintf(stderr, "Error: unknown value '%s' for '--color'\nTry 'on' or 'off'.\n", str);
						return 1;
					}
				}
				else {
					fprintf(stderr, "Error: unknown option '%s'\nTry 'pie --help' for more info.\n", str);
					return 1;
				}
				break_for = 1;
			}

		if (break_for)
			break;

		if (!strcmp(str, "--color"))
			pie_Settings.color = 1;
		else if (!strcmp(str, "--ansi"))
			pie_Settings.ansi = 1;
		else if (!strcmp(str, "--version")) {
			printf("0.1.0b\n");
			return 0;
		}
		else {
			fprintf(stderr, "Error: unknown option '%s'\nTry 'pie --help' for more info.\n", str);
			return 1;
		}
	}

	pie_init();
	pie_exit(0);
}
