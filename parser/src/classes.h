#pragma once
#ifndef CLASSES_H
#define CLASSES_H
#include "constants.h"
#include <string>

class return_type {
  public:
    token_type type;
    std::string value;
    
    return_type(token_type type, std::string value){
        this->type = type;
        this->value = value;
    }
};

class position{
  public:
    int line,column;

    position(int x,int y){
        line=x;
        column=y;
    }
};

#endif