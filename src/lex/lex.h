#ifndef PIE_LEX
#define PIE_LEX

enum pie_tokens {
	pie_token_dot,                   /* .    */
	pie_token_double_dot,            /* ..   */
	pie_token_ellipsis,              /* ...  */
	pie_token_dot_equals,            /* .=   */
	pie_token_comma,                 /* ,    */
	pie_token_colon,                 /* :    */
	pie_token_double_colon,          /* ::   */
	pie_token_colon_equals,          /* :=   */
	pie_token_semicolon,             /* ;    */
	pie_token_open_parenthesis,      /* (    */
	pie_token_close_parenthesis,     /* )    */
	pie_token_open_bracket,          /* [    */
	pie_token_close_bracket,         /* ]    */
	pie_token_open_brace,            /* {    */
	pie_token_close_brace,           /* }    */
	pie_token_plus,                  /* +    */
	pie_token_double_plus,           /* ++   */
	pie_token_plus_equals,           /* +=   */
	pie_token_minus,                 /* -    */
	pie_token_double_minus,          /* --   */
	pie_token_minus_equals,          /* -=   */
	pie_token_multiplication,        /* *    */
	pie_token_double_multiplication, /* **   */
	pie_token_multiplication_equals, /* *=   */
	pie_token_division,              /* /    */
	pie_token_division_equals,       /* /=   */
	pie_token_mod,                   /* mod  */
	pie_token_mod_equals,            /* mod= */
	pie_token_div,                   /* div  */
	pie_token_div_equals,            /* div= */
	pie_token_pow,                   /* ^    */
	pie_token_pow_equals,            /* ^=   */
	pie_token_factorial,             /* !    */
	pie_token_integer,               /* 123  */
	pie_token_float,                 /* 1.2  */
	pie_token_string,                /* "St" */
	pie_token_word,                  /* _A1  */
};

union _pie_TokenValue {
	char* s;
	char* s2[2];
};
typedef union _pie_TokenValue pie_TokenValue;

struct _pie_Token {
	char           token;
	pie_TokenValue value;
};
typedef struct _pie_Token pie_Token;

struct _pie_TokenStr {
	unsigned   level;
	unsigned   len;
	pie_Token *tokens;
};
typedef struct _pie_TokenStr pie_TokenStr;

struct _pie_TokenMatrix {
	unsigned      len;
	pie_TokenStr *lines;
};
typedef struct _pie_TokenMatrix pie_TokenMatrix;

#endif
