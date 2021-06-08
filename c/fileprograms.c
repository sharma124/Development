#include <stdio.h>

int main()
{
  int fd, wfd;
  FILE *fptr1, *fptr2;
  char ch;

  fptr1 = fopen ("my.txt", "r");
  fptr2 = fopen ("output.txt", "w");

  while (1)
  {
    ch = fgetc(fptr1);

    if (ch == EOF)
    {
      break;
    }
    else if (ch != 10)
    {
      fputc(ch, fptr2);
    }
    else
    {
      ch = 13;
      fputc(ch, fptr2);
      ch = 10;
      fputc(ch, fptr2);
    }
  }  

  fclose (fptr1);
  fclose(fptr2);
  return 0;
}
