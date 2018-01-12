#include <mkdio.h>
#include <stdio.h>
#include <string.h>

#include "markdown.h"

Markdown::Markdown() : ApplicationHelper()
{ }


QString Markdown::html(const char* input)
{
  int newSize = strlen(input)*2;
  char* buffer = (char*)calloc(strlen(input)*2, sizeof(char));
  FILE* outFile = fmemopen(buffer, newSize, "w");
  
  MMIOT* inFile = mkd_string(input, strlen(input), MKD_NOSTYLE);
  markdown(inFile, outFile, MKD_NOSTYLE);
  QString output(buffer);
  
  // cleanup
  mkd_cleanup(inFile);
  fclose(outFile);
  free(buffer);
  
  return output;
}