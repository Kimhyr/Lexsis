#include <string.h>
#include <stdio.h>

#include "Core.h"
#include "Lexer.h"

I32 main(const I32 argc, const C8 **argv) {
  if (argc <= 1) {
    printf("Source path is not given.\n");
    return 1;
  }
  FILE *f = fopen(argv[1], "r");
  if (f == NULL) {
    printf("Failed to read file.\n");
    return 1;
  }
  C8 c;
  C8 src[1028] = "";
  while ((c = fgetc(f)) != EOF) {
    printf("%c", c);
    strncat(src, &c, 1);
  }
  printf("\n");
  Lexer *lexer = createLexer(src);
  destroyLexer(lexer);
  return 0;
}
