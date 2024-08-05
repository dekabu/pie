#ifndef PIE_LEX
#define PIE_LEX

enum pie_Tokens {
	pie_token_dot,                      /* .    */
	pie_token_double_dot,               /* ..   */
	pie_token_ellipses,                 /* ...  */
	pie_token_dot_assignment,           /* .=   */
	pie_token_comma,                    /* ,    */
	pie_token_colon,                    /* :    */
	pie_token_double_colon,             /* ::   */
	pie_token_colon_assigment,          /* :=   */
	pie_token_semicolon,                /* ;    */
	pie_token_open_parenthesis,         /* (    */
	pie_token_closed_parenthesis,       /* )    */
	pie_token_open_bracket,             /* [    */
	pie_token_closed_bracket,           /* ]    */
	pie_token_open_brace,               /* {    */
	pie_token_closed_brace,             /* }    */
	pie_token_plus,                     /* +    */
	pie_token_double_plus,              /* ++   */
	pie_token_plus_assigment,           /* +=   */
	pie_token_minus,                    /* -    */
	pie_token_double_minus,             /* --   */
	pie_token_minus_assigment,          /* -=   */
	pie_token_multiplication,           /* *    */
	pie_token_multiplication_assigment, /* *=   */
	pie_token_division,                 /* /    */
	pie_token_division_assigment,       /* /=   */
	pie_token_mod,                      /* mod  */
	pie_token_mod_assigment,            /* mod= */
	pie_token_div,                      /* div  */
	pie_token_div_assigment,            /* div= */
	pie_token_power,                    /* ^    */
	pie_token_power_assigment,          /* ^=   */
	pie_token_factorial,                /* !    */
};

#endif
