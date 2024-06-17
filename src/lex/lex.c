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
			case ':':
				switch (s[++i]) {
					case ':':
						add(pie_token_double_colon)
						++i;
						break;
					case '=':
						add(pie_token_colon_equal)
						++i;
						break;
					default:
						add(pie_token_colon)
						break;
				}
				break;
			case ';':
				add(pie_token_semicolon)
				++i;
				break;
			case '(':
				add(pie_token_open_parenthese)
				++i;
				break;
			case ')':
				add(pie_token_close_parenthese)
				++i;
				break; 
			case '[':
				add(pie_token_open_bracket)
				++i;
				break;
			case ']':
				add(pie_token_close_bracket)
				++i;
				break;
			case '{':
				add(pie_token_open_brace)
				++i;
				break;
			case '}':
				add(pie_token_close_brace)
				++i;
				break;
			case '+':
				switch (s[++i]) {
					case '+':
						add(pie_token_double_plus)
						++i;
						break;
					case '=':
						add(pie_token_plus_equal)
						++i;
						break;
					default:
						add(pie_token_plus)
							break;
				}
				break;
			case '-':
				switch (s[++i]) {
					case '-':
						add(pie_token_double_minus)
						++i;
						break;
					case '=':
						add(pie_token_minus_equal)
						++i;
						break;
					default:
						add(pie_token_minus)
							break;
				}
				break;
			case '*':
				if (s[++i] == '=') {
					add(pie_token_multiplication_equal)
					++i;
				}
				else
					add(pie_token_multiplication)
				break;
			case '/':
				if (s[++i] == '=') {
					add(pie_token_division_equal)
					++i;
				}
				else
					add(pie_token_division)
				break;
			case '^':
				if (s[++i] == '=') {
					add(pie_token_power_equal)
					++i;
				}
				else
					add(pie_token_power)
				break;
			case '!':
				add(pie_token_factorial)
				++i;
				break;
		}
	}

	return ret;
}

#undef mem
#undef add
