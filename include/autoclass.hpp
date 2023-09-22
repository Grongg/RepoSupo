#ifndef AUTOCLASS_H_
# define AUTOCLASS_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <fstream>
#include <map>
#include <utility>
#include <filesystem>

using namespace std;

void dispAttr();
bool checkType(string type);
void displayAttribut();
string getType(string attribut);
void menu(string className);
void checkClassName(std::string *className);
bool validateEntry(const std::string blabla);
bool validateEntryAttribut(std::string blabla);
bool duplicate(const std::string attrName, std::map<std::string, std::string> attr);
void headerfilegenerator (std::string className, std::map<std::string, std::string> attributs);
void sourcefilegenerator(std::string className, std::map<std::string, std::string> attributs);
void mainfilegenerator(std::string className, std::map<std::string, std::string> attributes);
void makefilegenerator (std::string className);
void classnamegenerator(std::string className);
std::string initAttributes(std::map<std::string, std::string> attributes);

template <typename T>
std::string initAttributes(T data, std::string att, std::string attribute, std::map<std::string, std::string> attributes)
{
    std::string tmp = "";

    for (const auto& elem : attributes)
    {
        if (elem.second == attribute && elem.first == att)
        {
            if (attribute == "string")
            {
                tmp += elem.first + " = " +  "\"0\" ";
            }
            else
                tmp += elem.first + " = " + std::to_string(data);
        }
    }
    return tmp;
}

#endif /* AUTOCLASS_H_ */