#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

string className;
vector<string> attr;

void createClassInFile(string className)
{

}

void menu()
{
    string attributes, token;
    istringstream iss(attributes);

    cout << "Veuillez entrer le nom de la classe:" << endl;
    getline(cin, className);
    cout << className << endl;
    cout << "Veuillez entrer les atributs de la classe:" << endl;
    getline(cin, attributes);
    while (getline(iss, token, ' '))
    {
        if (token == "end")
            break;
    }
    
}

int main()
{
    menu();
    // createClassInFile();

    return 0;
}