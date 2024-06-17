#include "../pie.h"

#include <stdio.h>

int main()
{
  pie_TokenList l = pie_parse(":: /= ^ ! {]");
  printf("%lu", l.len);
  return 0;
}
