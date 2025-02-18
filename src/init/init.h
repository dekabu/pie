#ifndef PIE_INIT
#define PIE_INIT

struct pie_settings {
	unsigned color: 1;
};

void pie_init();

void pie_exit(int code);

#endif
