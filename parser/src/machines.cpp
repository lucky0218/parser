#include "funcs.h"
#include "globals.h"
#include <string>

using namespace std;

void print();
void init_state(int &);
int automata0(string &, int);
int automata1(string &, int);
int automata2(string &, int);
int automata3(string &, int);
int automata4(string &, int);
int automata5(string &, int);
int automata6(string &, int);

int (*autoptr[])(string &, int) = {automata0, automata1, automata2, automata3, automata4, automata5, automata6};

void deal(string &s) {
    if (s == "") return;
    result.clear();
    string buf = "";
    for (int i = 0; i < s.size(); i++) {
        // find separator,then pops buf and itself
        if (is_separator(s[i])) {
            judge(buf);
            result.push_back({SEPARATOR, s.substr(i, 1)});
            buf = "";
        } else {
            buf += s[i];
        }
    }
    judge(buf);
    print();
}

void judge(string &s) {
    if (s == "") return;
    // if s is keyword
    if (keyword_map.find(s) != keyword_map.end()) {
        result.push_back({KEYWORD, s});
        return;
    }
    // otherwise
    int state = 0;
    init_state(state);

    char ch;
    for (int i = 0; i < s.size(); i++) {
        ch = s[i];
        // first, narrow down the possibity by checking the first character
        if (1) {
            // check if it's identifier
            if (is_letter(ch) || ch == '_') {
                int nxt = (*autoptr[IDENTIFIER])(s, i);
                i = nxt;
                goto set_and_nxt;
            }

            // check if it's string literal
            if (ch == '\"') {
                int nxt = (*autoptr[STRING_LITERAL])(s, i);
                i = nxt;
                goto set_and_nxt;
            }

            // check if it's operator
            if (is_operator_starter(ch)) {
                int nxt = (*autoptr[OPERATOR])(s, i);
                i = nxt;
                goto set_and_nxt;
            }

            // check if it's number literal
            if (is_digit(ch)) {
                int nxt = (*autoptr[NUMBER_LITERAL])(s, i);
                i = nxt;
                goto set_and_nxt;
            }
        }

        // for (int j = 3; j < TOKEN_TYPE_COUNT; j++) {
        //     if (state & (1 << j)) {
        //         state &= (*autoptr[j])(s[i]);
        //     }
        // }
    set_and_nxt:;
    }
    // result.push_back({UNKNOWN, s});
}

void init_state(int &s) {
    for (int i = 3; i < TOKEN_TYPE_COUNT; i++) {
        s |= (1 << i);
    }
}
void print() {
    for (auto cur : result) {
        cout << token_types_list[cur.type] << " " << cur.value << endl;
    }
}

int automata0(string &s, int st) {
    return -888;
}
int automata1(string &s, int st) {
    return -888;
}
int automata2(string &s, int st) {
    return -888;
}

//
/// implementation of identifier state machine
//
int automata3(string &s, int st) {

    int i = st;
    for (i = st + 1; i <= s.size(); i++) {
        if (i == s.size()) goto finish3;
        if (!is_identifier_symbol(s[i])){
            goto finish3;
        }
    }
finish3:
    if (keyword_map.find(s.substr(st, i - st)) != keyword_map.end())
        result.push_back({KEYWORD, s.substr(st, i - st)});
    else
        result.push_back({IDENTIFIER, s.substr(st, i - st)});
    return (i - 1);
}
//
/// implementation of string literal state machine
//
int automata4(string &s, int st) {
    cout << "in string literal: " << st << endl;
    if (st + 1 >= s.size()) {
        result.push_back({UNKNOWN, s.substr(st, 1)});
        return st;
    }
    for (int i = st + 1; i < s.size(); i++) {
        char c = s[i];
        if (c == '\"') {
            result.push_back({STRING_LITERAL, s.substr(st, i - st + 1)});
            return i;
        }
        if (c == '\n' || i == s.size() - 1) {
            result.push_back({UNKNOWN, s.substr(st, i - st + 1)});
            return i;
        }
    }
}
//
/// implementation of operator state machine
//
int automata6(string &s, int st) {
    // rest length is 1, return
    if (st + 1 >= s.size()) {
        result.push_back({OPERATOR, s.substr(st, 1)});
        return st;
    }
    // try to match operator with length 2
    string cur = s.substr(st, 2);
    if (operator_map.find(cur) != operator_map.end()) {
        result.push_back({OPERATOR, cur});
        return st + 1;
    } else {
        result.push_back({OPERATOR, s.substr(st, 1)});
        return st;
    }
}
//
/// implementation of number literal state machine
//
int automata5(string &s, int st) {
    auto is_acceptable_state = [=](int state) {
        return (state == 1 || state == 3 || state == 7);
    };
    int state = 1, i = 0;
    for (i = st + 1; i <= s.size(); i++) {
        if (i == s.size()) goto finish;
        switch (state) {
            case 1:
                if (s[i] == '.')
                    state = 2;
                else if (is_digit(s[i]))
                    state = 1;
                else if (s[i] == 'E' || s[i] == 'e')
                    state = 5;
                else
                    goto finish;
                break;
            case 2:
                if (is_digit(s[i]))
                    state = 3;
                else
                    goto finish;
                break;
            case 3:
                if (is_digit(s[i]))
                    state = 3;
                else if (s[i] == 'E' || s[i] == 'e')
                    state = 5;
                else
                    goto finish;
                break;
            case 5:
                if (s[i] == '+' || s[i] == '-')
                    state = 6;
                else if (is_digit(s[i]))
                    state = 7;
                else
                    goto finish;
                break;
            case 6:
                if (is_digit(s[i]))
                    state = 7;
                else
                    goto finish;
                break;
            case 7:
                if (is_digit(s[i]))
                    state = 7;
                else
                    goto finish;
                break;
            default:
                goto finish;
        }
    }
finish:
    if (is_acceptable_state(state)) {
        result.push_back({NUMBER_LITERAL, s.substr(st, i - st)});
        return i - 1;
    } else {
        result.push_back({UNKNOWN, s.substr(st, i - st)});
        return i - 1;
    }
}