#ifndef PIE_BASE
#define PIE_BASE

typedef struct {
	unsigned color: 1;
	unsigned ansi:  1;
} pie_SETTINGS;

int pie_isPow2(unsigned long x);

#endif
