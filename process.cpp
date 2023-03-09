#define _CRT_SECURE_NO_WARNINGS

#include "process.h"
#include "brackets.h"
#include "CountDigit.h"

using namespace std;

string process_line(const string& line) {
    string result = line;
    regex fragment_regex("\\{.*?\\}");
    smatch match;
    string::const_iterator search_start(line.cbegin());
    while (regex_search(search_start, line.cend(), match, fragment_regex)) {
        string fragment = match.str();
        int count = count_words_with_digit(fragment);
        result.replace(result.find(fragment), fragment.length(), to_string(count) + "-" + fragment);
        search_start = match[0].second;
    }
    result = remove_unnecessary_parentheses(result);
    return result;
}

// Function to process the input file using FileStream
void process_input_file_with_streams(string input_file_name, string output_file_name)
{
    ifstream input_file(input_file_name);
    ofstream output_file(output_file_name);
    if (input_file.is_open() && output_file.is_open()) {
        string line;
        while (getline(input_file, line)) {
            if (!check_brackets_balance(line)) {
                string processed_line = process_line(line);
                output_file << processed_line << endl;
            }
            else {
                output_file << line << endl;
            }
        }
        input_file.close();
        output_file.close();
    }
    else {
        cout << "Unable to open files." << endl;
    }
}

// Function to process the input file using a FilePointer
void process_input_file_with_pointer(string input_file_name, string output_file_name) {
    FILE* input_file = fopen(input_file_name.c_str(), "r");
    FILE* output_file = fopen(output_file_name.c_str(), "w");

    if (input_file != NULL && output_file != NULL) {
        char buffer[1024];
        int index = 0;
        char c;

        while ((c = fgetc(input_file)) != EOF) {
            if (c == '\n') {
                buffer[index] = '\0';
                string line(buffer);
                index = 0;

                if (!check_brackets_balance(line)) {
                    string processed_line = process_line(line);
                    fprintf(output_file, "%s\n", processed_line.c_str());
                }
                else {
                    fprintf(output_file, "%s\n", line.c_str());
                }
            }
            else {
                buffer[index] = c;
                index++;
            }
        }
        fclose(input_file);
        fclose(output_file);
    }
    else {
        cout << "Unable to open files." << endl;
    }
}

bool ask_user_to_add_text_to_file(string file_name) {
    char response;
    cout << "Do you want to add text to the file \"" << file_name << "\"? (y/n): ";
    cin >> response;
    if (response == 'y' || response == 'Y') {
        ofstream file(file_name, ios_base::app); // Відкриття файлу в режимі append
        if (file.is_open()) {
            string text;
            cout << "Enter text to add to the file (press ESC to finish):\n";
            cin.ignore(); // Ігнорувати будь-який символ нового рядка.
            while (true) {
                getline(cin, text);
                if (text.empty() || text[0] == 27) { // ESC
                    break;
                }
                file << text << endl;
            }
            file.close();
            return true;
        }
        else {
            cout << "Unable to open file \"" << file_name << "\" for writing." << endl;
            return false;
        }
    }
    else {
        return false;
    }
}

void display_file_contents(string file_name)
{
    ifstream file(file_name);
    if (file.is_open()) {
        cout <<"\n" << "Contents of " << file_name << ":" << "\n" << endl;
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout <<"\n" << "Unable to open file \"" << file_name << "\"." << endl;
    }
}