# **Générateur de Code AutoClass**

    Ce programme génère des fichiers de classe C++ en fonction de l'entrée de l'utilisateur pour les attributs de la classe. Il crée les fichiers suivants pour une classe nommée VotreNomDeClasse :

    VotreNomDeClasse.h : Fichier d'en-tête contenant la définition de la classe.
    VotreNomDeClasse.cpp : Fichier source contenant les implémentations des fonctions membres de la classe.
    main.cpp : Un programme principal d'exemple pour démontrer l'utilisation de la classe.
    Makefile : Un fichier Makefile pour la compilation du programme.

    Le tout rangé dans un dossier au nom de la classe(Commençant toujours avec une majuscule) ex: nom de classe = "test", donne = Test/test.h Test/test.cpp Test/main.cpp Test/Makefile.

## **Utilisation**

    Faite un make et lancez l'executable classgen.
    Entrez le nom de la classe lorsque vous y êtes invité.
    Entrez une liste d'attributs de classe séparés par des espaces.
    Les attributs doivent avoir un nom unique.
    Les entrées utilisateur ne doivent pas contenir de caractère spéciaux, ni ne doivent pas correspondre à des types de variables.
    Tapez quit ou end pour sortir du programme.
    Le programme générera les fichiers de classe nécessaires et un fichier Makefile.
    Compilez le programme à l'aide de la commande make runclass.

## **Variables Globales**
**_map<string, string> attr_** : tableau de pair/tuples contenant les attributs et leurs types.
**_const vector<string> attributTypes_** : tableau contenant les types disponibles pour l'utilisateur.

## **Fonctions**

**_dispAttr()_** : Affiche les attributs et leurs types correspondant
**_checkType(std::string)_**: Fonction qui verifie que le choix de type soit diponible en comparant la variable type à la liste des types.
**_displayAttribut(std::string)_**: Fonction qui affiche les types d'attribut disponible.
**_getType(std::string)_**: Fonction qui stock le type choisie par l' utilisateur.
**_menu(std::string)_**: Fonction principale regroupant les autres fonctions et affiche le menu pour l'utilsateur.
**_checkClassName(std::string *)_**: Vérifie si nom de la classe est valide
**_validatEntry(const std::string)_** : Vérifie si une chaîne de caractères ne contient que des caractères alphanumériques et des traits de soulignement.
**_validateEntryAttribut(std::string)_** : Vérifie si la chaine de caractères ne contient pas de types appartenant à la library c++.
**_duplicate(const std::string, std::map<std::string, std::string>)_** : Vérifie si un nom d'attribut est en double dans la liste des attributs.

**_headerfilegenerator(std::string, std::map<std::string, std::string>)_** : Génère le fichier d'en-tête de classe en fonction du nom de la classe et des attributs fournis.
**_sourcefilegenerator(std::string, std::map<std::string, std::string>)_** : Génère le fichier source de classe avec les méthodes de constructeur et les getters/setters des attributs.
**_mainfilegenerator(std::string, std::map<std::string, std::string>)_** : Génère un programme principal d'exemple pour démontrer l'utilisation de la classe.
**_makefilegenerator(std::string)_** : Génère un fichier Makefile pour la compilation du programme.
**_classnamegenerator(std::string)_** : Génère un fichier .lastClassName contenant le dernier nom de la classe entrée.
**_initAttributes(T, std::string, std::string, std::map<std::string, std::string>)_** : Template permettant d'initialiser les attributs selon leurs types.

## **Exemple d'utilisation**

**_step 1_** => Télécharger les fichier "autoclass.hpp" , "autoclassmain.cpp" & "fonction.cpp" depuis le dossier src et include.

**_step 2_** => Ouvrir un ide type "Visual studio code".

**_step 3_**=> Ouvrir un nouveau terminal dans "visual studio code".

**_step 4_**=> Se placer dans le dossier où les fichier autoclass.hpp" , "autoclassmain.cpp" et "fonction.cpp" se trouvent.
**Utilisez les commandes cd nomdedossier et cd .. afin pour naviguer.**

**_step 5_**=> faite un make

**_step 6_**=> Suivre les instructions du programme.

**_step 7_**=> Vous pouvez observer la création des différents fichier dans le dossier du nom de la classe entré.

**_step 8_**=> Vous pouvez verifier en tapant la console "make runclass" en minuscule.

**_step 9_**=> Voir les résultats.

## **Remarque**

Le programme s'assure que les noms d'attributs sont valides (alphanumériques sans caractères spéciaux).
Il vérifie les noms d'attributs en double.
Les fichiers générés sont nommés en fonction du nom de classe fourni.
Le programme principal généré démontre comment définir et obtenir des valeurs d'attribut pour la classe.

Assurez-vous de compiler et d'exécuter ce programme dans un répertoire où vous avez des autorisations d'écriture pour la création de fichiers.
