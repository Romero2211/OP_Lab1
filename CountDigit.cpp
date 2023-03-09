#define _CRT_SECURE_NO_WARNINGS

#include "CountDigit.h"

using namespace std;

int count_words_with_digit(const string& str)
{
    int count = 0;
    regex word_regex("\\w+");
    smatch match;
    string::const_iterator search_start(str.cbegin());
    while (regex_search(search_start, str.cend(), match, word_regex)) {
        if (any_of(match[0].first, match[0].second, ::isdigit)) {
            count++;
        }
        search_start = match[0].second;
    }
    return count;
}