#include <cstdarg>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void reset() {
    return;
}
template <typename T, typename... Types>
void reset(T bo, Types... b) {
    *bo = false;
    reset(b...);
}

//
/// implement a function to delete comments (considering " // /* */ )
/// note that: '\n' will always be kept
//
void delete_comments(string &s) {
    bool in_quote = false;
    bool in_oneline_comment = false;
    bool in_multiline_comment = false;
    string res = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '\n'){
            res+=s[i];
            reset(&in_oneline_comment); // '\n' reset oneline and quote states. 
            continue;
        }
        if (!in_multiline_comment && !in_oneline_comment) {
            bool add = true;
            if (s[i] == '\"') in_quote = !in_quote;
            if (i + 1 < s.size() && s[i] == '/' && s[i + 1] == '/' && !in_quote) {
                in_oneline_comment = true;
                i++;
                add = false;
            }
            if (i + 1 < s.size() && s[i] == '/' && s[i + 1] == '*' && !in_quote) {
                in_multiline_comment = true;
                i++;
                add = false;
            }
            if (add) res += s[i];
            continue;
        }
        if (in_oneline_comment) {
            // do nothing
            continue;
        }
        if (in_multiline_comment) {
            // cancel multiline comment
            if (s[i] == '*' && i + 1 < s.size() && s[i + 1] == '/') {
                in_multiline_comment = false;
                i++;
            }
            continue;
        }
        
    }
    s = res;
}
