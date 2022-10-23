#pragma once
#ifndef _TOKEN_
#define _TOKEN_

#include "Core.h"

typedef enum TokenKind {
  ERROR_TOKEN_KIND,
  IDENTIFIER_TOKEN_KIND,
  LITERAL_TOKEN_KIND,
  KEYWORD_TOKEN_KIND,
  OPERATOR_TOKEN_KIND,
  PUNCTUATOR_TOKEN_KIND,
} TokenKind;

typedef struct Point {
  U64 row;
  U64 col;
} Point;

typedef enum LiteralTokenKind {
  CHAR_LITERAL_TOKEN_KIND,
  STRING_LITERAL_TOKEN_KIND,
  INT_LITERAL_TOKEN_KIND,
  FLOAT_LITERAL_TOKEN_KIND,
} LiteralTokenKind;

typedef struct LiteralToken {
  const LiteralTokenKind kind;
  const C8 *value;
} LiteralToken;

typedef enum KeywordToken {
  // Declarations
  STRUCTURE_KEYWORD_TOKEN,
  PROPERTY_KEYWORD_TOKEN,
  OPERATOR_KEYWORD_TOKEN,
  PROCEDURE_KEYWORD_TOKEN,
  DATUM_KEYWORD_TOKEN,

  // Procedures
  RETURN_KEYWORD_TOKEN,
  LOOP_KEYWORD_TOKEN,
} KeywordToken;

typedef enum OperatorToken {
  // Unaries
  QUESTION_OPERATOR_TOKEN = '?',
  EXCLAIM_OPERATOR_TOKEN = '!',
  POUND_OPERATOR_TOKEN = '#',

  // Binaries
  COLON_OPERATOR_TOKEN = ':',
  DCOLON_OPERATOR_TOKEN, // ::
  PLUS_OPERATOR_TOKEN = '+',
  EQUAL_OPERATOR_TOKEN = '=',
  LESS_OPERATOR_TOKEN = '<',
} OperatorToken;

typedef enum PunctuatorToken {
  // Delimiters
  OPAREN_PUNCTUATOR_TOKEN = '(',
  CPAREN_PUNCTUATOR_TOKEN = ')',
  OBRACE_PUNCTUATOR_TOKEN = '{',
  CBRACE_PUNCTUATOR_TOKEN = '}',
  OBRACK_PUNCTUATOR_TOKEN = '[',
  CBRACK_PUNCTUATOR_TOKEN = ']',
  OANGLE_PUNCTUATOR_TOKEN = '<',
  CANGLE_PUNCTUATOR_TOKEN = '>',
  PIPE_PUNCTUATOR_TOKEN = '|',
  APOST_PUNCTUATOR_TOKEN = '\'',
  QUOTE_PUNCTUATOR_TOKEN = '"',

  // Separators
  DOT_PUNCTUATOR_TOKEN = '.',
  DDOT_PUNCTUATOR_TOKEN, // ..
  COMMA_PUNCTUATOR_TOKEN = ',',
  SEMICOLON_PUNCTUATOR_TOKEN = ';',
  FARROW_PUNCTUATOR_TOKEN, // =>
} PunctuatorToken;

typedef struct Token {
  Point start;
  Point end;
  union {
    const C8 *error;
    const C8 *identifier;
    LiteralToken literal;
    KeywordToken keyword;
    OperatorToken operator;
    PunctuatorToken punctuator;
  } value;
} Token;

B keywordTokenIsProcedure(const KeywordToken token);
B keywordTokenIsDeclaration(const KeywordToken token);

B operatorTokenIsUnary(const OperatorToken token);
B operatorTokenIsBinary(const OperatorToken token);

B punctuatorTokenIsDelimiter(const PunctuatorToken token);
B punctuatorTokenIsSeparator(const PunctuatorToken token);

#endif
