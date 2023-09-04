#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "autoclass.hpp"

void headerfilegenerator(std::string className, std::vector<std::string> attributs)
{
    std::ofstream headerFile(className + ".h");
    std::string constructor = "";
    std::string headerName = className;

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
    for (size_t i = 0; i < attributs.size(); i++)
    {
        if (i + 1 >= attributs.size())
            constructor += "std::string _" + attributs[i];
        else
            constructor += "std::string _" + attributs[i] + ", ";
    }
    headerFile << "\t" << className << "();" << std::endl;
    headerFile << "\t" << className << "(" << constructor << ");" << std::endl;
    headerFile << "\t~" << className << "();" << std::endl;
    headerFile << endl;
    std::string tmp;
    for (size_t i = 0; i < attributs.size(); i++)
    {
        tmp = attributs[i];
        tmp[0] = toupper(tmp[0]);
        // mettre la premiere lettre de l'attribut en Capitalise avec toupper()
        headerFile << "\tstd::string get" << tmp << "() const;" << std::endl;
        headerFile << "\tvoid set" << tmp << "(std::string _" << attributs[i] << ");" << std::endl;
        headerFile << std::endl;
    }
    headerFile << "private:" << std::endl;
    for (size_t i = 0; i < attributs.size(); i++)
    {
        headerFile << "\t"
                   << "std::string " << attributs[i] << ";" << std::endl;
    }
    headerFile << "};" << std::endl;
    headerFile << std::endl;
    headerFile << "#endif // " << headerName << "_H" << std::endl;
    headerFile.close();
}

void sourcefilegenerator(std::string className, std::vector<std::string> attributs)
{
    std::ofstream sourceFile(className + ".cpp");
    sourceFile << "#include \"" << className << ".h\"" << std::endl;
    sourceFile << std::endl;
    sourceFile << "    // Constructeur par défaut" << std::endl;
    sourceFile << "\n";
    sourceFile << "\t" << className << "::" << className << "()"
               << "{\n";
    for (size_t i = 0; i < attributs.size(); i++)
    {
        sourceFile << "\t" << attributs[i] << " = \"\";\n";
    }
    sourceFile << "}";
    sourceFile << "\n";
    sourceFile << "\t" << className << "::" << className << "("
               << "{\n";

    // getvalue
    sourceFile << "\n";
    for (size_t i = 0; i < attributs.size(); i++)
    {
        sourceFile << "\t int " << className << "::get" << attributs[i] << "()const{\n";
        sourceFile << "\t return " << attributs[i] << ";\n";
        sourceFile << "}";
        sourceFile << "\t void " << className << "::set" << attributs[i] << "("
                   << "std::string " << attributs[i] << ")const{\n";
        sourceFile << "\t this->" << attributs[i] << ";\n";
        sourceFile << "}";
    }
    sourceFile.close();
}
void mainfilegenerator(std::string className)
{
    std::ofstream mainFile("main.cpp");
    mainFile << "#include \"" << className << ".h\"" << std::endl;
    mainFile << "#include <iostream>" << std::endl;
    mainFile << std::endl;
    mainFile << "int main() {" << std::endl;
    mainFile << "    return 0;" << std::endl;
    mainFile << "}" << std::endl;
    mainFile.close();
}

void makefilegenerator(std::string className)
{
    std::ofstream makefile("Makefile");
    makefile << "CXX = g++" << std::endl;
    makefile << "CXXFLAGS = -std=c++11 -Wall" << std::endl;
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
