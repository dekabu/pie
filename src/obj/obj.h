#ifndef PIE_OBJ
#define PIE_OBJ

#include "../lex/lex.h"

typedef union {
	
} pie_Value;

typedef struct {
	char type;
	pie_Value value;
} pie_Obj;

pie_Obj pie_tree(pie_TokenList);

#endif 
