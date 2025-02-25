#ifndef PIE_BASE
#define PIE_BASE

struct _pie_SettingsStruct {
	unsigned color: 1;
};
typedef struct _pie_SettingsStruct pie_SettingsStruct;

int pie_isPow2(int x);

#endif
