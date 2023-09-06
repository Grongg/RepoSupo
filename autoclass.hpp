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

using namespace std;

void dispAttr();
void menu(string className);
void headerfilegenerator (std::string className, std::map<std::string, std::string> attributs);
void sourcefilegenerator(std::string className, std::map<std::string, std::string> attributs);
void mainfilegenerator(std::string className, std::map<std::string, std::string> attributes);
void makefilegenerator (std::string className);
bool validateEntry(const std::string blabla);
bool isValidFileName(const string &fileName);
bool validateAttribut(const std::string blabla);
bool validateEntryAttribut(const std::string blabla);
std::string initAttributes(std::map<std::string, std::string> attributes);

template <typename T>
std::string initAttributes(T data, std::string att, std::string attribute, std::map<std::string, std::string> attributes)
{
    string tmp = "";

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

template <typename T>
void useSeter(T data, std::string attribut)
{

}

#endif