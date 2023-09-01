# Enoncé

**Instructions :**

1. **Génération de la Classe :** Chaque groupe doit développer un programme C++ qui génère automatiquement une classe C++ avec les caractéristiques suivantes :
    - Un constructeur par défaut.
    - Un constructeur prenant en compte les paramètres.
    - Des méthodes getters et setters pour les membres de la classe.
2. **Génération des Fichiers :** Le programme doit également générer les fichiers suivants :
    - Un fichier <nom_de_la_classe> (.h) contenant ld prototype complet de la classe.
    - Un fichier <nom_de_la_classe> (.cpp) contenant la declaration de la classe et les implémentations des méthodes de la classe.
    - Un fichier main.cpp avec des tests pour la classe générée.
    - Un Makefile qui compile le projet avec g++.
3. **Tests de la Classe :** Dans le fichier main.cpp, vous devez tester la classe générée en créant une instance de la classe, en appelant les méthodes getters et setters, et en affichant les résultats.

Bonus :

- Demandez le type de l’attribut à l’utilisateur et adapter le traitement de l’attribut entré en conséquence (dans la partie principale vous pouvez vous contenter de considerer tous les attributs entrés comme un seul et même type)

Voici un exemple de ce à quoi le code final pourrait ressembler après avoir suivi les étapes de l'exercice :

```cpp

// Exemple de fichier d'en-tête (MyClass.h)
#ifndef MYCLASS_H
#define MYCLASS_H

class MyClass {
public:
    MyClass();
    MyClass(int value1, int value2);

    int getValue1() const;
    void setValue1(int value1);

    int getValue2() const;
    void setValue2(int value2);

private:
    int value1;
    int value2;
};

#endif // MYCLASS_H

```

```cpp

// Exemple de fichier source (MyClass.cpp)
#include "MyClass.h"

MyClass::MyClass() {
    value1 = 0;
    value2 = 0;
}

MyClass::MyClass(int value1, int value2) {
    this->value1 = value1;
    this->value2 = value2;
}

int MyClass::getValue1() const {
    return value1;
}

void MyClass::setValue1(int value1) {
    this->value1 = value1;
}

int MyClass::getValue2() const {
    return value2;
}

void MyClass::setValue2(int value2) {
    this->value2 = value2;
}

```

```cpp

// Exemple de fichier main (main.cpp)
#include "MyClass.h"#include <iostream>int main() {
    MyClass obj;
    obj.setValue1(42);
    obj.setValue2(56);

    std::cout << "Value1 = " << obj.getValue1() << std::endl;
    std::cout << "Value2 = " << obj.getValue2() << std::endl;

    return 0;
}

```

```makefile
# Exemple de Makefile
CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: myprogram

myprogram: MyClass.cpp main.cpp
	$(CXX) $(CXXFLAGS) -o myprogram MyClass.cpp main.cpp

clean:
	rm -f myprogram
	rm -f MyClass.h
	rm -f MyClass.cpp
	rm -f main.cpp

```