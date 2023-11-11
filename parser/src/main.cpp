#include "funcs.h"
#include "constants.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    //
    ///init
    //

    freopen("./test.in", "r", stdin);
    //
    /// read from file
    //
    string str;
    while(char c=getchar()){
        if (c==EOF) break;
        str += c;
    }

    delete_comments(str);
    cout << str;

    //
    /// main loop
    //
    int state = 0;
    string buf="";
    for (int i=0;i<str.size();i++){
        // multithreading in the future
        if (state == 0){
            if (is_definite_separator(str[i])) goto nxt;
            buf+=str[i];
            state=1;
            goto nxt;
        }
        if (state == 1){
            if(is_definite_separator(str[i])){
                deal(buf);
                buf="";
                state=0;
                goto nxt;
            }
            buf+=str[i];
            goto nxt;
        }

    nxt:;
    }
    deal(buf);
    return 0;
}