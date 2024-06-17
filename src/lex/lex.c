#include "lex.h"
#include "../base/base.h"
#include <malloc.h>

#define mem \
	if (ret.len == 0) \
		ret.tokens = malloc(sizeof(pie_Token)); \
	else if (pie_ispow2(ret.len)) \
		ret.tokens = realloc(ret.tokens, 2 * ret.len * sizeof(pie_Token))

#define add(t) { \
	mem; \
	ret.tokens[ret.len++].token = t; \
}

pie_TokenList pie_parse(char* s)
{
	register unsigned long i;
	register char c;
	pie_TokenList ret = {0};

	i = 0;
	while ((c = s[i])) {
		switch (c) {
			case ' ':
				++i;
				break;
			case '.':
				switch (s[++i]) {
					case '.':
						if (s[++i] == '.') {
							add(pie_token_ellipses)
							++i;
						}
						else
							add(pie_token_double_dot)
						break;
					case '=':
						add(pie_token_dot_equal)
						++i;
						break;
					default:
						add(pie_token_dot)
						break;
				}
				break;
			case ',':
				add(pie_token_comma)
				++i;
				break;
		}
	}

	return ret;
}

#undef mem
#undef add
