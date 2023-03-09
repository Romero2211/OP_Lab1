#define _CRT_SECURE_NO_WARNINGS

#include "brackets.h"
#include "CountDigit.h"
#include "process.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int set_mode(int argc, char** argv) {
    if (argc != 3) return -1;

    std::string flag{ argv[1] },
        mode{ argv[2] };

    if (flag != "-mode") return -1;

    if (mode == "FilePointer") return 1;
    if (mode == "FileStream") return 2;

    return -1;
}

int main(int argc, char* argv[]) {

    string input_file, output_file;

    int mode = set_mode(argc, argv);

    if (mode == -1) {
        cout << "Invalid mode specified." << endl;
        return 1;
    }

    cout << "Enter filename to read from: ";
    cin >> input_file;

    if (ask_user_to_add_text_to_file(input_file)) {
        cout << "Text added to file \"" << input_file << "\"." << endl;
    }

    cout << "Enter filename to write to: ";
    cin >> output_file;

    // Вибір режиму
    if (mode == 1) {
        process_input_file_with_pointer(input_file, output_file);
    }
    else if (mode == 2) {
        process_input_file_with_streams(input_file, output_file);
    }

    display_file_contents(input_file);
    display_file_contents(output_file);

    return 0;
}




