#define _CRT_SECURE_NO_WARNINGS

#include "brackets.h"

using namespace std;

bool check_brackets_balance(string str)
{
    int count = 0;
    for (char c : str) {
        if (c == '{') {
            count++;
        }
        else if (c == '}') {
            count--;
        }
        if (count < 0) {
            return false;
        }
    }
    return (count == 0);
}

// Видалення зайвих дужок
string remove_unnecessary_parentheses(const string& str) {
    string result = "";
    bool seen_open = false;
    bool seen_close = false;
    for (char c : str) {
        if (c == '{') {
            if (!seen_open) {
                seen_open = true;
                result += c;
            }
        }
        else if (c == '}') {
            if (seen_open && !seen_close) {
                seen_close = true;
                result += c;
            }
        }
        else {
            result += c;
        }
    }
    if (seen_open && !seen_close) {
        result.pop_back();
    }
    if (seen_close && !seen_open) {
        result = "{" + result;
    }
    return result;
}
