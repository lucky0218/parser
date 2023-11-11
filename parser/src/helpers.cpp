#include "constants.h"
#include "funcs.h"
#include "classes.h"



bool is_definite_separator(char c) {
    return c == ' ' || c == '\n' || c=='\t';
}
bool is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}
bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}
bool is_identifier_symbol(char c) {
    return is_letter(c) || is_digit(c) || c == '_';
}
bool is_separator(char c) {
    return separator_map.find(c) != separator_map.end();
}
bool is_operator_starter(char c) {
    return operator_starter_map.find(c) != operator_starter_map.end();
}