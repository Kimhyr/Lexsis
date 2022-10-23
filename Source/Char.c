#include "Char.h"

B charIsWhitespace(C8 c) {
  return c == ' ' || (c >= '\t' && c <= '\r');
}

B charIsAlphabetic(C8 c) {
  return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

B charIsNumeric(C8 c) {
  return c >= '0' && c <= '9';
}
