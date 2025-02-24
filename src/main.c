#include "pie.h"
#include <stdio.h>
#include <string.h>

struct pie_settings pie_Settings = {
	1 // color
};

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
	pie_exit(0);
}
