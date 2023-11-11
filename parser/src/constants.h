#pragma once
#ifndef CONSTANTS_H
#define CONSTANTS_H


#include <map>
#include <string>

#define MAX_INDENTIFIER_LENGTH 64
#define MAX_LITERAL_LENGTH 256
#define MAX_KEYWORD_LENGTH 16
#define KEYWORD_COUNT 30
#define TOKEN_TYPE_COUNT 7
#define SEPARATOR_COUNT 8
#define OPERATOR_STARTER_COUNT 12
#define OPERATOR_COUNT 25

typedef enum {
    // Reserved words
    UNKNOWN,KEYWORD,SEPARATOR,IDENTIFIER,STRING_LITERAL,NUMBER_LITERAL,OPERATOR
} token_type;

// int, long, double, return, if, else, while, for, break, continue, void, struct, signed,
// typedef, enum, switch, case, default, goto, const, static, extern, sizeof, register, union, do, signed, char, short, float
const std::string keyowrd_list[]={
    "int","long","double","return","if","else","while","for","break","continue","void","struct","do","float","short",
    "typedef","enum","switch","case","default","goto","const","static","extern","sizeof","register","union","signed","unsigned","char"
};

//  "<" and ">" to be added
const char const separator_list[]={
    ';',',','(',')','{','}','[',']'
};

// "?" and ":" to be added
const char const operator_starter_list[]={
    '+','-','*','/','%','&','|','^','~','!','=','.'
};
// many to be added
// ! don't forget to update corresponding map
const char* const operator_list[]={
    "<=",">=","==","+=","-=","*=","/=","%=","&=","|=","^=","~=",
    "!=","+","-","*","/","%","&","|","^","~","!","=","."
};



const char* const token_types_list[]={
    "UNKNOWN","KEYWORD","SEPARATOR","IDENTIFIER","STRING_LITERAL","NUMBER_LITERAL","OPERATOR"
};



const std::map<std::string,char> keyword_map={
    {"int",0},{"long",1},{"double",2},{"return",3},{"if",4},{"else",5},{"while",6},{"for",7},{"break",8},{"continue",9},
    {"void",10},{"struct",11},{"do",12},{"float",13},{"short",14},{"typedef",15},{"enum",16},
    {"switch",17},{"case",18},{"default",19},{"goto",20},{"const",21},{"static",22},{"extern",23},
    {"sizeof",24},{"register",25},{"union",26},{"signed",27},{"unsigned",28},{"char",29}
};
const std::map<char,char> separator_map={
    {';',0},{',',1},{'(',2},{')',3},{'{',4},{'}',5},{'[',6},{']',7}
};
const std::map<char,char> operator_starter_map={
    {'+',0},{'-',1},{'*',2},{'/',3},{'%',4},{'&',5},{'|',6},{'^',7},{'~',8},{'!',9},{'=',10},{'.',11}
};
const std::map<std::string,char> operator_map={
    {"<=",0},{">=",1},{"==",2},{"+=",3},{"-=",4},{"*=",5},{"/=",6},{"%=",7},{"&=",8},{"|=",9},{"^=",10},{"~=",11},
    {"!=",12},{"+",13},{"-",14},{"*",15},{"/",16},{"%",17},{"&",18},{"|",19},{"^",20},{"~",21},{"!",22},{"=",23},{".",24}
};



#endif // DEBUG
