#pragma once
#ifndef _LEXER_
#define _LEXER_

#include "Core.h"
#include "Token.h"

typedef struct Lexer {
  U64 index;
  Point point;
  const C8 *source;
} Lexer;

Lexer *createLexer(const C8 *source);
V destroyLexer(Lexer *lexer);

const Token *lexerLex(Lexer *lexer);

// PRIVATE

const C8 *lexerRegex(Lexer *lexer, B (*regex)(C8));
B lexerWordRegex(C8 c);

V lexerSkipWhitespace(Lexer *lexer);

V advanceLexer(Lexer *lexer);
inline C8 peekLexer(Lexer *lexer, U64 offset);

B charIsWhitespace(C8 c);

#endif
