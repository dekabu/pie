#ifndef PIE_OBJ
#define PIE_OBJ

enum pie_types {
	pie_null_t,
	pie_bool_t,
	pie_int_t,
	pie_str_t
};

struct _pie_Obj;
typedef struct _pie_Obj pie_Obj;

struct _pie_Func {
	unsigned  argc;
	pie_Obj  *argv;	
};
typedef struct _pie_Func pie_Func;

union _pie_ObjValue {
	unsigned b: 1;
	pie_Func f;
};
typedef union _pie_ObjValue pie_ObjValue;

struct _pie_Obj {
	char         type;
	pie_ObjValue value;
};

struct _pie_Name {
	char    *name;
	pie_Obj  obj;
};
typedef struct _pie_Name pie_Name;

struct _pie_Namespace {
	struct _pie_Namespace *parent;
	unsigned               len;
	pie_Name              *names;
};
typedef struct _pie_Namespace pie_Namespace;

int pie_FindObj(pie_Namespace ns, char* s);

#endif
