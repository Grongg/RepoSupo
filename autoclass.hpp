#ifndef AUTOCLASS_H_
# define AUTOCLASS_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <fstream>

using namespace std;

void dispAttr();
void menu(string className);
void headerfilegenerator (std::string className, std::vector<std::string> attributs);
void sourcefilegenerator ( std::string className, std::vector<std::string> attributs);
void mainfilegenerator( std::string className);
void makefilegenerator (std::string className);

#endif