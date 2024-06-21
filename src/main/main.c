#include "../pie.h"

#include <stdio.h>

int main()
{
  pie_TokenList l = pie_parse(":: /= ^ ! {]");
  printf("%lu\n", l.len);
  return 0;
}
