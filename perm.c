#include <stdio.h>


void swap(char *a, char *b)
{
  char tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;
}

char *sort(char *arg)
{
  int i;
  i = 0;

  while (arg[i] && arg[i + 1])
  {
    if (arg[i] > arg[i + 1])
    {
      swap(&arg[i], &arg[i + 1]);
      i = 0;
    }
    else
      i++;
  }
  return arg;
}

void perm(char *arg, int len, int d)
{
  int i = len;
  if (d == len)
  {
    puts(arg);
    return;
  }
  while (i <= d)
  {
    swap(&arg[len], &arg[i]);
    perm(arg, len + 1, d);
    swap(&arg[len], &arg[i]);
    i++;
  }
}

int main(int ac, char **av)
{
  if (ac == 2)
  {
    char *sorted = sort(av[1]);
    //printf("%s", sorted);
    int i = -1;
    while (sorted[++i])
         ;
    perm(sorted, 0, i - 1);
  }
}
