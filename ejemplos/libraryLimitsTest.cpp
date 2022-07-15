#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>

using namespace std;

int main()
{
  time_t t;
  struct tm *tm;
  char hoy[100];
  t=time(NULL);
  tm=localtime(&t);
  strftime(fechayhora, 100, "%d%m%Y", tm);
  string fecha(fechayhora);
  return fecha;
}
