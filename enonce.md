# BONUS - Générateur de code

### Liste de bonus à faire, non exhaustifs. Vous pouvez en selectionner un ou plusieurs, ou rajouter vos propres fonctionnalités si vous les trouver pertinentes, seule la gestion d’erreurs sera obligatoire d’ici à la fin du projet

1. **Personnalisation du Type d'Attributs :** Avant de générer la classe, demandez à l'utilisateur de spécifier le type des attributs qu'il souhaite inclure dans la classe. Vous pouvez permettre à l'utilisateur de saisir le type pour chaque attribut individuellement ou de spécifier un type global pour tous les attributs. Voici comment vous pouvez implémenter cette fonctionnalité dans votre programme :
   - Avant de générer la classe, demandez à l'utilisateur de spécifier le type des attributs. Vous pouvez utiliser la saisie standard pour cela.
   - Si l'utilisateur souhaite spécifier un type global pour tous les attributs, demandez-lui de le faire une seule fois.
   - Si l'utilisateur souhaite spécifier un type pour chaque attribut individuellement, demandez-lui de le faire pour chaque attribut en utilisant une boucle ou une série de saisies séparées.
   - Assurez-vous que le programme généré tienne compte du type spécifié par l'utilisateur lors de la création des attributs dans la classe.
   - Si l'utilisateur souhaite conserver le type par défaut pour certains attributs, proposez une option pour cela.
   - Une fois que l'utilisateur a spécifié les types des attributs, générez la classe avec les types corrects.
2. **Validation des Entrées Utilisateur :** Ajoutez une validation des entrées utilisateur pour vous assurer que les types d'attributs spécifiés sont valides. Par exemple, vérifiez que les types saisis correspondent à des types de données C++ valides.
3. **Génération de Commentaires :** Ajoutez une fonctionnalité qui génère automatiquement des commentaires de documentation pour la classe générée. Cela inclut la génération de commentaires pour les méthodes, les constructeurs et les attributs.
4. **Héritage :** Offrez la possibilité à l'utilisateur de spécifier si la classe générée doit hériter d'une autre classe. Si oui, demandez-lui de fournir le nom de la classe parente et générez la classe en conséquence.
5. **Regles Makefile** : Ajoutez des règles au Makefile (run, fclean, etc…)
6. **Gestion des Erreurs :** Implémentez une gestion des erreurs robuste pour gérer les éventuelles erreurs lors de la génération de la classe ou des fichiers. Informez l'utilisateur en cas d'échec de la génération et fournissez des informations utiles pour le débogage.
7. **Sauvegarde du Projet :** Ajoutez une option permettant de sauvegarder l'ensemble du projet généré (les fichiers .h, .cpp, le Makefile, etc.) dans un dossier spécifié par l'utilisateur. Cela permettra à l'utilisateur de conserver une copie du projet généré pour une utilisation ultérieure.
8. **Gestion des Noms de Fichiers :** Demandez à l'utilisateur de spécifier un nom de projet ou un préfixe de nom de fichier. Utilisez ce nom pour générer automatiquement les noms de fichiers (par exemple, mon_projet.h, mon_projet.cpp, etc.). Cela permettra de personnaliser davantage la structure des fichiers générés.
9. **Héritage Multiple :** Offrez la possibilité à l'utilisateur de spécifier si la classe générée doit utiliser l'héritage multiple et, le cas échéant, lui permettre de sélectionner plusieurs classes parentes.
10. **Gestion de la Visibilité :** Demandez à l'utilisateur de spécifier la visibilité (public, protected, private) des membres de la classe (attributs et méthodes) et générez la classe avec ces spécifications.
11. **Génération de Méthodes Supplémentaires :** En plus des méthodes getters et setters générées par défaut, demandez à l'utilisateur s'il souhaite ajouter des méthodes supplémentaires à la classe et générez-les en conséquence.
12. **Documentation de Code :** Ajoutez une fonctionnalité qui génère automatiquement des commentaires de documentation dans les fichiers de classe, y compris des descriptions pour les membres de la classe, les paramètres des méthodes, etc. Cela aidera les utilisateurs à comprendre rapidement l'utilisation de la classe générée.

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
