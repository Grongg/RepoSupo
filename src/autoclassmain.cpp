#include "autoclass.hpp"

using namespace std;

map<string, string> attr;
const vector<string> attributTypes = {"int", "float", "double", "char", "string", "bool"};

void dispAttr()
{
    cout << "Les attributs et leurs types sont sont:" << endl;
    cout << "-------------------" << endl;
    for (const auto &p : attr)
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

void displayAttribut()
{
    for (const auto &n : attributTypes)
    {
        std::cout << n << std::endl;
    }
}

string getType(string attribut)
{
    string type;

    cout << "Veuillez entrer le type de l'attribut parmis la Liste ci-dessous: " << endl;
    displayAttribut();
    getline(cin, type);
    if (!validateEntry(type))
    {
        cout << "Merci de ne pas utilser de caractère spéciaux";
    }
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

    cout << "Veuillez entrer un attribut de la classe:\n"
         << "(l'attribut \"end\" est interdit)\n"
         << "(exit ou quit pour sortir du programme)"
         << endl;
    getline(cin, attribut);
    try
    {
        validateEntry(attribut);
        validateEntryAttribut(attribut);
        duplicate(attribut, attr);
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl;
        menu(className);
    }
    if (attribut == "end")
    {
        cout << "Erreur, attribut end trouvé." << endl;
        menu(className);
    }
    else if (attribut == "exit" || attribut == "quit")
    {
        cout << "Sortie du programme" << endl;
        exit(0);
    }
    else
    {
        getType(attribut);

        while (boucleinf == true)
        {
            cout << "Voulez vous ajouter un autre attribut (Y/N)?" << endl;
            getline(cin, another);
            if (another == "y" || another == "Y")
            {
                boucleinf = false;
                menu(className);
            }
            else if (another == "n" || another == "N")
            {
                boucleinf = false;
                dispAttr();
                headerfilegenerator(className, attr);
                sourcefilegenerator(className, attr);
                mainfilegenerator(className, attr);
                makefilegenerator(className);
                classnamegenerator(className);
                exit(0);
            }
            else
            {
                cout << "Entrer \"y\" ou \"n\" svp." << endl;
                continue;
            }
        }
    }
}

void checkClassName(std::string *className)
{

    cout << "Veuillez entrer le nom de la classe:" << endl;
    getline(cin, *className);
    try
    {
        validateEntry(*className);
        validateEntryAttribut(*className);
    }
    catch (const std::exception &e)
    {
        cout << e.what() << endl;
        checkClassName(className);
    }
}

int main()
{
    int status = 0;
    string className;

    checkClassName(&className);
    className[0] = toupper(className[0]);
    try
    {
        status = filesystem::create_directories(className);
        if (!status)
        {
            throw std::runtime_error("Warning: dossier avec le nom " + className +  " existe deja");
        }
    }
    catch (const std::exception &r)
    {
        std::cerr << r.what() << std::endl;
    }
    menu(className);
    cout << "Files generated in " << className << " folder" << endl;

    return 0;
}