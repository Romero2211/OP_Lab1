#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>


#ifndef PROCESS_H
#define PROCESS_H

using namespace std;

string process_line(const string& line);

void process_input_file_with_streams(string input_file_name, string output_file_name);

void process_input_file_with_pointer(string input_file_name, string output_file_name);

bool ask_user_to_add_text_to_file(string file_name);

void display_file_contents(string file_name);

#endif