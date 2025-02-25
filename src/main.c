#include "pie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

pie_SettingsStruct pie_Settings = {
	1 // color
};

const pie_Obj pie_Null  = {pie_null_t};
const pie_Obj pie_True  = {pie_bool_t, 1};
const pie_Obj pie_False = {pie_bool_t, 0};

pie_Obj pie_CurrentObj;

#define PIE_GLOBALNAMESPACE_LEN 3
pie_Namespace pie_GlobalNamespace;
pie_Namespace pie_CurrentNamespace;

void pie_init();
void pie_exit(int code);

int main(int argc, char* argv[])
{
	register int i, j;
	char *s;
	char SKIP;

	for (i = 0; i < argc; ++i) {
		s = argv[i];
		if (!strlen(s))
			argv[i] = 0;
		else {
			if (s[0] == '-') {
				s += 1;
				if (s[0] == '-') {
					s += 1;
					SKIP = 0;
					for (j = 0; j < strlen(s); ++j)
						if (s[j] == '=') {
							s[j] = 0;
							if (!strcmp(s, "color")) {
								s += j + 1;
								if (!strcmp(s, "on"))
									pie_Settings.color = 1;
								else if (!strcmp(s, "off"))
									pie_Settings.color = 0;
								else {
									fprintf(stderr, "Error: invalid value '%s' for --color\n"
											"Try 'on' or 'off'.\n", s);
									pie_exit(2);
								}
							}
							else {
								fprintf(stderr, "Error: unknown option '--%s'\n"
										"Try '%s --help' for more info.\n", s, argv[0]);
								pie_exit(1);
							}
							SKIP = 1;
						}
					if (SKIP)
						continue;
					if (!strcmp(s, "version")) {
						printf("%i.%i.%i\n", PIE_VERSION_MAJOR, PIE_VERSION_MINOR, PIE_VERSION_PATCH);
						pie_exit(0);
					}
					else if (!strcmp(s, "color"))
						pie_Settings.color = 1;
					else if (!strcmp(s, "nocolor"))
						pie_Settings.color = 0;
					else {
						fprintf(stderr, "Error: unknown option '--%s'\n"
								"Try '%s --help' for more info.\n", s, argv[0]);
						pie_exit(1);
					}
				}
				else {

				}
				argv[i] = 0;
			}
		}
	}

	pie_init();

	printf("%s\n", pie_GlobalNamespace.names[2].name);

	pie_exit(0);
}

void pie_init()
{
	unsigned size = PIE_GLOBALNAMESPACE_LEN * sizeof(pie_Name);

	pie_Name names[PIE_GLOBALNAMESPACE_LEN] = {
		{"null", pie_Null},
		{"true", pie_True},
		{"false", pie_False}
	};

	pie_GlobalNamespace.parent = 0;
	pie_GlobalNamespace.len    = PIE_GLOBALNAMESPACE_LEN;
	pie_GlobalNamespace.names  = malloc(size);

	memcpy(pie_GlobalNamespace.names, names, size); 

	pie_CurrentNamespace = pie_GlobalNamespace;
}

void pie_exit(int code)
{
	exit(code);
}
