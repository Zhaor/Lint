#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strStr (char *source, char *dest);

int
main ()
{
  char *source = "source";
  char *dest = "target";

  printf ("source string: %s\n", source);
  printf ("dest string: %s\n", dest);
  printf ("Duplicate Posion: %d\n", strStr (source, dest));
  return (EXIT_SUCCESS);
}

int
strStr (char *source, char *dest)
{ 
  int i_dest, i_source, i_tmp;
  int l_source = strlen (source) + 1;
  int l_dest = strlen (dest) + 1;
  i_source = 0;
  
  // Handle Exception
  if ((l_source == 1) && (l_dest == 1))
    return 0;
 
  else if
     ((l_source >= 1) && (l_dest == 1))
    return l_source;

  else if
     ((l_source == 1) && (l_dest >= 1))
    return -1;

  // Find Duplicate
  while (i_source <= l_source)
  {
    i_tmp = i_source;
    i_dest = 0;

    while (source[i_tmp] == dest[i_dest])
    { 
      //source: ...abxdefg\0
      //dest:   ....bx\0
      if (source[i_tmp + 1] != '\0' &&  dest[i_dest + 1] == '\0')
        return (i_source);

      //source: ...ax\0
      //dest:   ...axcdef\0
      else if (source[i_tmp + 1] == '\0' && dest[i_dest + 1] == '\0')
        return -1;

      //source: ...abcdefx\0
      //dest:   ......defx\0
      if (source[i_tmp + 1] == '\0' &&  dest[i_dest + 1] == '\0')
        return (i_source);

      //source: ...axc\0
      //dest:   ...axcdef\0
      else
      {
        i_tmp++;
        i_dest++;
      }
    }
    i_source++;
  }
}
