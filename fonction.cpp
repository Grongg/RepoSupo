#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void headerfilegenerator(std::string className, std::vector<std::string> attributs)
{
    std::ofstream headerFile(className + ".h");
    headerFile << "#ifndef " << className << "_H" << std::endl;
    headerFile << "#define " << className << "_H" << std::endl;
    headerFile << "#include <iostream>" << std::endl;
    headerFile << "#include <string>" << std::endl;

    headerFile << std::endl;
    headerFile << "class " << className << " {" << std::endl;
    headerFile << "public:" << std::endl;
    headerFile << "    " << className << "();" << std::endl;
    headerFile << std::endl;
    headerFile << std::endl;
    headerFile << "private:" << std::endl;
    for (size_t i = 0; i < attributs.size(); i++)
    {
        headerFile << "\t"
                   << "std::string " << attributs[i] << ";" << std::endl;
    }
    headerFile << "};" << std::endl;
    headerFile << std::endl;
    headerFile << "#endif // " << className << "_H" << std::endl;
    headerFile.close();
}
void sourcefilegenerator(std::string className, std::vector<std::string> attributs)
{
    std::ofstream sourceFile(className + ".cpp");
    sourceFile << "#include \"" << className << ".h\"" << std::endl;
    sourceFile << std::endl;
    sourceFile << className << "::" << className << "() {" << std::endl;
    sourceFile << "    // Constructeur par défaut" << std::endl;
    sourceFile << "\n";
    sourceFile << "\t" << className << "::" << className << "()"
               << "{\n";
    for (size_t i = 0; i < attributs.size(); i++)
    {
        sourceFile << "\t" << attribus[i] << " = \"\";\n";
    }
    sourceFile << "\n";
    sourceFile << "\t" << className << "::" << className << "("
               << "{\n";

    // getvalue
    sourceFile << "\n";
    for (size_t i = 0; i < attributs.size(); i++ 0)
    {
        sourceFile << "\t int" << className << "::get" << attributs[i] << "()const{\n";
        sourceFile << "\t return" << attributs[i] << ";\n";
        sourceFile << "\t void" << className << "::set" << attributs[i] << "("
                   << "int" << attributs[i] << ")const{\n";
        sourceFile << "\t this->" << attributs[i] << ";\n";
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
