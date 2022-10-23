#include "Lexer.h"
#include "Char.h"

#include <stdio.h>
#include <stdlib.h>

Lexer *createLexer(const C8 *source) {
  Lexer *lexer = (Lexer *)malloc(sizeof(Lexer));
  lexer->index = -1;
  lexer->point.row = 1;
  lexer->point.col = 1;
  lexer->source = source;
  return lexer;
}

V destroyLexer(Lexer *lexer) {
  free((V *)lexer);
}

const Token *lexerLex(Lexer *lexer) {
  C8 peek = peekLexer(lexer, 1);
  if (charIsWhitespace(peek)) {
    lexerSkipWhitespace(lexer);
  }

  if (charIsAlphabetic(peek)) {
    const C8 *word = lexerRegex(lexer, lexerWordRegex);
  }

  return NULL;
}

const C8 *lexerRegex(Lexer *lexer, B (*regex)(C8)) {
  C8 peek;
  U64 bufSize = 0;
  U64 bufSpace = 2;
  C8 *buf = (C8 *)calloc(bufSpace, sizeof(C8));
  do {
    peek = peekLexer(lexer, 1);
    buf[bufSize] = peek;
    ++bufSize;
    if (bufSize + 1 > bufSpace) {
      bufSpace *= 2;
      buf = (C8 *)realloc(buf, bufSpace * sizeof(C8));
    }
    advanceLexer(lexer);
  } while (regex(peek));
  buf = (C8 *)realloc(buf, bufSize + 1 * sizeof(C8));
  buf[bufSize] = '\0';
  return buf;
}

B lexerWordRegex(C8 c) {
  return charIsAlphabetic(c) || charIsNumeric(c) || c == '_';
}

V lexerSkipWhitespace(Lexer *lexer) {
  C8 c;
  do {
    c = peekLexer(lexer, 1);
    advanceLexer(lexer);
  } while (charIsWhitespace(c));
}

V advanceLexer(Lexer *lexer) {
  ++lexer->index;
  if (peekLexer(lexer, 0) == '\n') {
    ++lexer->point.row;
    lexer->point.col = 0;
  }
  ++lexer->point.col;
}

inline C8 peekLexer(Lexer *lexer, U64 offset) {
  return lexer->source[lexer->index + offset];
}
