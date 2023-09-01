#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

vector<string> attr;

void dispAttr()
{
    cout << "Les attributs sont:" << endl;
    cout << "-------------------" << endl;
    for (size_t i = 0; i < attr.size(); i++)
    {
        cout << attr[i] << endl;
    }
    cout << "-------------------" << endl;
}

void menu(string className)
{
    string attributes, token;

    cout << className << endl;
    cout << "Veuillez entrer les atributs de la classe:" << endl;
    getline(cin, attributes);
    stringstream iss(attributes);
    while (getline(iss, token, ' '))
    {
        if (token == "end")
            break;
        attr.push_back(token);
    }
    dispAttr();
}

void headerfilegenerator (std::string className, std::vector<std::string> attributs);

int main()
{
    string className;

    cout << "Veuillez entrer le nom de la classe:" << endl;
    getline(cin, className);
    menu(className);
    headerfilegenerator(className, attr);

    return 0;
}