#include "autoclass.hpp"

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

int main()
{
    string className;

    cout << "Veuillez entrer le nom de la classe:" << endl;
    getline(cin, className);
    className[0] = toupper(className[0]);
    menu(className);
    headerfilegenerator(className, attr);
    sourcefilegenerator(className, attr);

    return 0;
}