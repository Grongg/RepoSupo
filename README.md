# RepoSupo

**How to push**
(reminder pour guillaume)
git status -> voir ou en est l'état des fichiers: rouge pas add, vert à bien été add.
git add <nom du fichier> ou git add . ou git add \* -> ajouter un/tous les fichiers pour le git commit -m "<message de commit>" -> envoyer les fichiers ajouter dans le tampon d'envoi
git push ou git push <premiere branche> <deuxieme branche> -> envoi les fichiers dans le tampon d'envoi sur le dossier sur le serveur git
git restore <nom du fichier> -> reset le contenu du fichier sur la derniere version du dossier sur le serveur git

# **Générateur de Code AutoClass**

    Ce programme génère des fichiers de classe C++ en fonction de l'entrée de l'utilisateur pour les attributs de la classe. Il crée les fichiers suivants pour une classe nommée VotreNomDeClasse :

    VotreNomDeClasse.h : Fichier d'en-tête contenant la définition de la classe.
    VotreNomDeClasse.cpp : Fichier source contenant les implémentations des fonctions membres de la classe.
    main.cpp : Un programme principal d'exemple pour démontrer l'utilisation de la classe.
    Makefile : Un fichier Makefile pour la compilation du programme.

## **Utilisation**

    Compilez et exécutez le programme.
    Entrez le nom de la classe lorsque vous y êtes invité.
    Entrez une liste d'attributs de classe séparés par des espaces. Tapez "end" pour terminer la saisie des attributs.
    Les entrez utilisateur ne doivent pas contenir de caractère spéciaux.
    Le programme générera les fichiers de classe nécessaires et un fichier Makefile.
    Compilez le programme à l'aide de la commande make.
    Exécutez l'exécutable généré myprogram.

## **Fonctions**

**_headerfilegenerator_** : Génère le fichier d'en-tête de classe en fonction du nom de la classe et des attributs fournis.
**_sourcefilegenerator_** : Génère le fichier source de classe avec les méthodes de constructeur et de getter/setter.
**_mainfilegenerator_** : Génère un programme principal d'exemple pour démontrer l'utilisation de la classe.
**_makefilegenerator_** : Génère un fichier Makefile pour la compilation du programme.

**_validatentry_** : Vérifie si une chaîne de caractères ne contient que des caractères alphanumériques et des traits de soulignement.

**_duplicate_** : Vérifie si un nom d'attribut est en double dans la liste des attributs.

**_isValidFileName_** : Vérifie si une chaîne de caractères est un nom de fichier valide.

## **Exemple d'utilisation**

**_step 1_** => Télécharger les fichier "autoclass.hpp" , "autoclassmain.cpp" & "fonction.cpp".
**_step 2_** => Ouvrir un ide type "Visual studio code".
**_step 3_**=> Ouvrir un nouveau terminal dans "visual studio code".
**_step 4_**=> Se placer dans le dossier ou les fichier autoclass.hpp" , "autoclassmain.cpp" & "fonction.cpp" se trouve. utilisez les commande cd nomdedossier et cd .. pour naviguer.
**_step 5_**=> compiler les fichier avec la commande g++ autoclass.hpp , "autoclassmain.cpp fonction.cpp.
**_step 6_**=> Suivre les instruction du programme

## **Remarque**

    Le programme s'assure que les noms d'attributs sont valides (alphanumériques sans caractères spéciaux).
    Il vérifie les noms d'attributs en double.
    Les fichiers générés sont nommés en fonction du nom de classe fourni.
    Le programme principal généré démontre comment définir et obtenir des valeurs d'attribut pour la classe.

Assurez-vous de compiler et d'exécuter ce programme dans un répertoire où vous avez des autorisations d'écriture pour la création de fichiers.
