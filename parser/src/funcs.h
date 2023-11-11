#pragma once
#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <string>


void init(); // initialization

void delete_comments(std::string &s);
void deal(std::string&);
void judge(std::string& );


bool is_definite_separator(char );
bool is_letter(char );
bool is_digit(char );
bool is_identifier_symbol(char );
bool is_separator(char );
bool is_operator_starter(char );

#endif
