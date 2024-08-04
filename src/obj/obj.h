#ifndef PIE_OBJ
#define PIE_OBJ

enum pie_Types {
	pie_null_t,
	pie_bool_t,
	pie_str_t
};

/* Строки: длина + указатель */
typedef struct {
	unsigned  len;
	char     *ptr;
} pie_STR;

struct _pie_OBJ;

typedef struct {
	unsigned         argc;
	struct _pie_OBJ *argv;
} pie_FUN;

typedef union {
	unsigned b: 1;
	pie_STR  s;
	pie_FUN  f;
} pie_VALUE;

typedef struct _pie_OBJ {
	unsigned     type;
	pie_VALUE value;
} pie_OBJ;

typedef struct {
	pie_STR name;
	pie_OBJ obj;
} pie_NAME;

typedef struct _pie_NAMESPACE {
	unsigned               len;
	pie_NAME              *names;
	struct _pie_NAMESPACE *parent;
} pie_NAMESPACE;

int pie_find(pie_STR name);

#endif
