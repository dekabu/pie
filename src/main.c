#include "pie.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[])
{
	register int i, j;
	char SKIP = 0;
	char *s;
	char *name = argv[0];
	struct pie_settings pie_Settings = {
		1 // color = true
	};

	for (i = 1; i < argc; ++i) {
		s = argv[i];
		if (s[0] == '-') {
			s += 1;
			if (s[0] == '-') {
				s += 1;
				for (j = 0; j < strlen(s); ++j)
					if (s[j] == '=') {
						s[j] = '\0';
						if (!strcmp(s, "color")) {
							s += j + 1;
							if (!strcmp(s, "on"))
								pie_Settings.color = 1;
							else if (!strcmp(s, "off"))
								pie_Settings.color = 0;
							else {
								fprintf(stderr, "Error: invalid value \'%s\' for --color\n"
										"Try \'on\' or \'off\'.\n", s);
								pie_exit(2);
							}
						}
						else {
							fprintf(stderr, "Error: invalid option \'--%s\'\n"
									"Try %s --help for more info.\n", s, name);
							pie_exit(1);
						}
						SKIP = 1;
						break;
					}
				if (SKIP)
					break;
				if (!strcmp(s, "version")) {
					printf("%i.%i.%i\n", PIE_VERSION_MAJOR, PIE_VERSION_MINOR, PIE_VERSION_PATCH);
					pie_exit(0);
				}
				else if (!strcmp(s, "color"))
					pie_Settings.color = 1;
				else if (!strcmp(s, "nocolor"))
					pie_Settings.color = 0;
				else {
					fprintf(stderr, "Error: invalid option \'--%s\'\n"
							"Try %s --help for more info.\n", s, name);
					pie_exit(1);
				}
			}
		}
	}

	pie_init();
	pie_exit(0);
}
