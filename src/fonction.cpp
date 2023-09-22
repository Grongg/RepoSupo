#include "autoclass.hpp"

// fonction pour les données valides characteres speciaux
bool validateEntry(const std::string blabla)
{
    for (char x : blabla)
    {
        if (!isalnum(x))
        {
            throw std::invalid_argument("Code 187 : Merci de ne pas utilisé de caractère spéciaux ");
        }
    }
    return true;
}

// fonction pour les données valides c++ types
bool validateEntryAttribut(std::string blabla)
{
    for (size_t i = 0; i < blabla.length(); i++)
    {
        blabla[i] = tolower(blabla[i]);
    }
    if (blabla == "string" 
        || blabla == "int" 
        || blabla == "float" 
        || blabla == "double"
        || blabla == "long" 
        || blabla == "char" 
        || blabla == "bool" 
        || blabla == "std"
        || blabla == "null" 
        || blabla == "vector" 
        || blabla == "operator"
        || blabla.find("std::") != std::string::npos
        )
    {
        throw std::invalid_argument("Error:9001: vous ne pouvez pas utiliser des types provenant de c++");
    }

    return true;
}

// fonction pour le duplicate
bool duplicate(const std::string attrName, std::map<std::string, std::string> attributes)
{
    if (attributes.find(attrName) != attributes.end())
        throw std::invalid_argument("Error:9003: attributs avec ce nom existe deja");
    return false;
}

void headerfilegenerator(std::string className, std::map<std::string, std::string> attributs)
{
    size_t ctn = 0;
    std::ofstream headerFile(className + "/" + className + ".h");
    std::string constructor = "";
    std::string headerName = className;
    std::string tmp;

    for (int i = 0; headerName[i] != '\0'; i++)
    {
        headerName[i] = toupper(headerName[i]);
    }
    headerFile << "#ifndef " << headerName << "_H" << std::endl;
    headerFile << "#define " << headerName << "_H" << std::endl;
    headerFile << "#include <iostream>" << std::endl;
    headerFile << "#include <string>" << std::endl;

    headerFile << std::endl;
    headerFile << "class " << className << " {" << std::endl;
    headerFile << "public:" << std::endl;
    for (const auto& elem : attributs)
    {
        if (ctn + 1 >= attributs.size())
        {
            if (elem.second == "string")
                constructor += "std::";
            constructor += elem.second + " _" + elem.first;
        }
        else
        {
            if (elem.second == "string")
                constructor += "std::";
            constructor += elem.second + " _" + elem.first + ", ";
        }
        ctn++;
    }
    ctn = 0;
    headerFile << "\t" << className << "();" << std::endl;
    headerFile << "\t" << className << "(" << constructor << ");" << std::endl;
    headerFile << endl;
    for (const auto& elem : attributs)
    {
        tmp = elem.first;
        tmp[0] = toupper(tmp[0]);
        if (elem.second == "string")
        {
            headerFile << "\t" << "std::" << elem.second <<  " get" << tmp << "() const;" << std::endl;
            headerFile << "\tvoid set" << tmp << "(" <<  "std::" << elem.second << " " << elem.first << ");" << std::endl;
        }
        else
        {
            headerFile << "\t" << elem.second <<  " get" << tmp << "() const;" << std::endl;
            headerFile << "\tvoid set" << tmp << "(" << elem.second << " " << elem.first << ");" << std::endl;
        }
        headerFile << std::endl;
    }
    headerFile << "private:" << std::endl;
    for (const auto& elem : attributs)
    {
        if (elem.second == "string")
        {
            headerFile << "\t"
                   << "std::" << elem.second << " " << elem.first << ";" << std::endl;
        }
        else
            headerFile  << "\t"
                        << elem.second << " " << elem.first << ";" << std::endl;
    }
    headerFile << "};" << std::endl;
    headerFile << std::endl;
    headerFile << "#endif // " << headerName << "_H" << std::endl;
    headerFile.close();
}

void sourcefilegenerator(std::string className, std::map<std::string, std::string> attributes)
{
    std::ofstream sourceFile(className + "/" + className + ".cpp");
    std::string constructor, tmp, init;
    size_t ctn = 0;

    sourceFile << "#include \"" << className << ".h\"" << std::endl;
    sourceFile << std::endl;
    sourceFile << "// Constructeur par défaut" << std::endl;
    sourceFile << "\n";
    sourceFile << className << "::" << className << "()"
               << "{\n";
    for (const auto& elem : attributes)
    {
        init = "\t" + initAttributes(0, elem.first, elem.second, attributes) + ";";
        sourceFile << init << endl;
    }
    sourceFile << "}";
    sourceFile << "\n";
    for (const auto& elem : attributes)
    {
        if (ctn + 1 >= attributes.size())
        {
            if (elem.second == "string")
                constructor += "std::";
            constructor += elem.second + " _" + elem.first;
        }
        else
        {
            if (elem.second == "string")
                constructor += "std::";
            constructor += elem.second + " _" + elem.first + ", ";
        }
        ctn++;
    }
    ctn = 0;
    sourceFile << className << "::" << className << "(" << constructor << ")"
               << "{\n\n";
    for (const auto& elem : attributes)
    {
        sourceFile << "\tthis->" << elem.first << " = _" << elem.first << ";" << std::endl;
    }
    sourceFile << "}\n";
    sourceFile << "\n";
    for (const auto& elem : attributes)
    {
        tmp = elem.first;
        tmp[0] = toupper(tmp[0]);
        if (elem.second == "string")
        {
            sourceFile << "std::" << elem.second << " " << className << "::get" << tmp << "() const{\n";
        }
        else
        {
            sourceFile << elem.second << " " << className << "::get" << tmp << "() const{\n";
        }
        sourceFile << "\treturn " << elem.first << ";\n";
        sourceFile << "}\n";
        if (elem.second == "string")
        {
            sourceFile << "void " << className << "::set" << tmp << "("
                    << "std::" << elem.second << " " << elem.first << "){\n";
        }
        else
        {
            sourceFile << "void " << className << "::set" << tmp << "("
                << elem.second << " " << elem.first << "){\n";
        }
        sourceFile << "\tthis->" << elem.first << " = " << elem.first << ";\n";
        sourceFile << "}";
        sourceFile << endl;
        sourceFile << endl;
    }
    sourceFile.close();
}

void mainfilegenerator(std::string className, std::map<std::string, std::string> attributes)
{
    std::ofstream mainFile(className + "/" + "main.cpp");
    std::string tmp;

    mainFile << "#include \"" << className << ".h\"" << std::endl;
    mainFile << std::endl;
    mainFile << "int main() {" << std::endl;
    mainFile << "\t" << className << " obj;\n";
    for (const auto& elem : attributes)
    {
        tmp = elem.first;
        tmp[0] = toupper(tmp[0]);
        if (elem.second == "string")
            mainFile << "\tobj.set" << tmp << "(" << "\"1\"" << ");" << std::endl;
        else
            mainFile << "\tobj.set" << tmp << "(" << "1" << ");" << std::endl;
        mainFile << "\tstd::cout << \"" << elem.first << " = \" "
                 << "<< obj.get" << tmp << "() << std::endl;" << std::endl;
    }

    mainFile << "\n\treturn 0;" << std::endl;
    mainFile << "}" << std::endl;
    mainFile.close();
}

void makefilegenerator(std::string className)
{
    std::ofstream makefile(className + "/" + "Makefile");

    makefile << "CXX = g++" << std::endl;
    makefile << "CXXFLAGS = -std=c++11 -Wall -Werror" << std::endl;
    makefile << std::endl;
    makefile << "all: myprogram" << std::endl;
    makefile << std::endl;
    makefile << "myprogram: " << className << ".cpp main.cpp" << std::endl;
    makefile << "\t$(CXX) $(CXXFLAGS) -o myprogram " << className << ".cpp main.cpp" << std::endl;
    makefile << std::endl;
    makefile << "clean:" << std::endl;
    makefile << "\trm -f myprogram" << std::endl;
    makefile << "\trm -f " << className << ".h" << std::endl;
    makefile << "\trm -f " << className << ".cpp" << std::endl;
    makefile << "\trm -f main.cpp" << std::endl;
    makefile.close();
}

void classnamegenerator(std::string className)
{
    std::ofstream classNameFile(".lastClassName");

    classNameFile << className << std::endl;
    classNameFile.close();
}
