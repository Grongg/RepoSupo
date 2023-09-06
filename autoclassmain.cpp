#include "autoclass.hpp"

using namespace std;

map<string, string> attr;
vector<string> attributTypes = {"int", "long", "float", "double", "char", "string", "bool"};

void dispAttr()
{
    cout << "Les attributs et leurs types sont sont:" << endl;
    cout << "-------------------" << endl;
    for (const auto& p : attr)
        std::cout << p.first << " => " << p.second << '\n';
    cout << "-------------------" << endl;
}

bool checkType(string type)
{
    for (int i = 0; type[i] != '\0'; i++)
    {
        type[i] = tolower(type[i]);
    }
    if (find(attributTypes.begin(), attributTypes.end(), type) == attributTypes.end())
    {
        cout << "Type ne correspond pas à la liste, reesayer" << endl;
        return false;
    }
    return true;
}

string getType(string attribut)
{
    string type;

    cout << "Veuillez entrer le type de l'attribut:" << endl;
    getline(cin, type);
    if (!checkType(type))
    {
        cout << "Type ne fais pas partie de la liste, Veuillez reessayer" << endl;
        getType(attribut);
    }
    attr.emplace(make_pair(attribut, type));

    return type;
}

void menu(string className)
{
    string attribut;
    string another;
    bool boucleinf = true;

    cout << 
            "Veuillez entrer un attribut de la classe:\n" 
            << "(l'attribut \"end\" est interdit)"
        << endl;
    getline(cin, attribut);
    if (attribut == "end")
    {
        cout << "Erreur, attribut end trouvé." << endl;
        // cin.clear();
        // cin.ignore();
        menu(className);
    }
    else
    {
        getType(attribut);
        cout << 
            "Voulez vous ajouter un autre attribut ?\n"
            << "1 - Oui\n"
            << "2 - Non"
        << endl;
        while (boucleinf == true)
        {
            getline(cin, another);
            if (another == "oui" || another == "o")
            {
                boucleinf = false;
                menu(className);
            }
            else if (another == "non" || another == "n")
            {
                boucleinf = false;
                dispAttr();
                break;
            }
            else
            {
                cout << "Entrer oui ou non svp." << endl;
                continue;
            }
        }
    }
}

int main()
{
    string className;

    cout << "Veuillez entrer le nom de la classe:" << endl;
    getline(cin, className);
    if (!validateEntry(className))
        cout << "machin diozndzio" << endl;
    if (!isValidFileName(className))
        cout << "machin diozndzio" << endl;
    className[0] = toupper(className[0]);
    menu(className);
    headerfilegenerator(className, attr);
    // sourcefilegenerator(className, attr);
    // mainfilegenerator(className, attr);
    // makefilegenerator(className);

    return 0;
}