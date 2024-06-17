#include "../str/str.h"

typedef struct {
	char token;
	pie_Str value;
} pie_Token;

typedef struct {
	unsigned long len;
	pie_Token* tokens;
} pie_TokenList;
