extern "C" {
  #include <mkdio.h>
}


#include <cstdio>
#include <cstring>

#include "markdown.h"

Markdown::Markdown() : ApplicationHelper()
{ }


QString Markdown::html(const char* input)
{
  int newSize = strlen(input)*23;
  char* buffer = (char*)calloc(strlen(input)*3, sizeof(char));
  FILE* outFile = fmemopen(buffer, newSize, "wr");
  
  MMIOT* inFile = mkd_string(input, strlen(input), 0);
  markdown(inFile, outFile, 0);
  
   char c;
   c = fgetc(outFile);
   while (c != EOF) {
     c = fgetc(outFile);
   }
  
  
  QString output(buffer);
  
  // cleanup
  mkd_cleanup(inFile);
  fclose(outFile);
  free(buffer);
  
  return output;
}