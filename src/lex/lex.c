#include "lex.h"
#include "../base/base.h"
#include <malloc.h>

#define mem \
	if (ret.len == 0) \
		ret.tokens = malloc(sizeof(pie_Token)); \
	else if (pie_ispow2(ret.len)) \
		ret.tokens = relloc(ret.tokens, 2 * ret.len * sizeof(pie_Token))

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
		}
	}

	return ret;
}
