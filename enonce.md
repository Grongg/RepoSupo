TP - Générateur de Code1TP - Générateur de Code
PROJET

1. Demandez à l'utilisateur de saisir le nom de la classe.
2. Demandez à l'utilisateur de spécifier les attributs de la classe, y compris leur
   nom et leur type. Permettez à l'utilisateur d'ajouter autant d'attributs que
   nécessaire.
3. Générez automatiquement les fichiers suivants :
   Un fichier <nom_de_la_classe>.h contenant le prototype complet de la classe.
   Un fichier <nom_de_la_classe>.cpp contenant la déclaration de la classe et les
   implémentations des méthodes de la classe.
   Un fichier main.cpp avec des tests pour la classe générée.
   Un fichier Makefile qui compile le projet avec g++.
4. Assurez-vous que le code généré est propre, bien formaté, et qu’il suit les
   conventions du Google Style Guide C++.
5. Créez un fichier README.md qui explique comment utiliser le programme,
   comment compiler et exécuter les fichiers générés, et fournissez un exemple
   d'utilisation.
   BONUS
   La partie bonus ne sera considérée que si la gestion d’erreurs est correctement
   implémentée dans la partie principale.
6. Ajoutez une option pour spécifier un répertoire de sortie personnalisé pour les
   fichiers générés.
   TP - Générateur de Code22. Demandez à l'utilisateur de spécifier les méthodes de la classe, y compris leur
   nom, leur type de retour et leurs paramètres. Permettez à l'utilisateur d'ajouter
   autant de méthodes que nécessaire.
7. Permettez à l'utilisateur de spécifier des modificateurs d'accès (public, private,
   protected) pour les attributs et les méthodes.
8. Ajoutez la possibilité de générer des constructeurs et destructeurs
   automatiquement.
9. Permettez à l'utilisateur de spécifier des types de données plus complexes tels
   que des tableaux ou des vecteurs.
10. Permettez la génération de classes et de méthodes génériques en utilisant des
    templates.
11. Intégrez une fonctionnalité pour ajouter des commentaires explicatifs au code
    généré pour une meilleure lisibilité.
12. Permettez à l'utilisateur de spécifier l'héritage de classes et générez
    automatiquement des classes dérivées avec des méthodes.
13. Ajoutez une option pour initialiser un dépôt Git ou SVN pour le projet généré,
    avec un commit initial.
14. Ajoutez une option qui permet de créer un journal de log. Par exemple, créer un
    fichier “maclasse.log” qui contient par exemple les etapes de creation des
    differents fichiers au fil de l’execution du projet.
    ERREURS POTENTIELLES
15. Gestion des erreurs de saisie utilisateur : Assurez-vous que les entrées de
    l'utilisateur sont valides et que le programme ne plante pas en cas de saisie
    incorrecte (nombres, caractères spéciaux, etc...).
16. Vérification des doublons : Évitez la création d'attributs ou de méthodes avec
    des noms en double.
17. Gestion des espaces de noms : Si nécessaire, assurez-vous que les espaces de
    noms sont gérés correctement dans les fichiers générés.
18. Gestion des noms de fichiers : Assurez-vous que les noms de fichiers générés
    ne contiennent pas de caractères non valides.
    TP - Générateur de Code35. Gestion des cas spéciaux : Prenez en compte les cas spéciaux tels que les
    noms réservés en C++, les noms de méthodes/attributs déjà utilisés, etc.
19. Types de données : Assurez-vous que les types de données spécifiés par
    l'utilisateur sont valides et compatibles avec le langage C++.
20. Depassement de mémoire : Vérifiez que le programme généré n'entraîne pas de
    fuites de mémoire ou de dépassements de mémoire en cas d'utilisation
    intensive.
21. Exception : Ajoutez des mécanismes de gestion des exceptions pour gérer les
    erreurs inattendues qui pourraient survenir lors de la génération du code.
22. Droits : Vérifiez ce qu’il se passe si vous essayez de manipuler un fichier pour
    lequel vous n’avez pas les droits.
23. Multiplateforme : Vérifier que le code généré est compatible avec différentes
    plateformes et systèmes d'exploitation (BONUS).
    EVALUATION
    Si la partie principale du projet est remplie en implémentant les notions vues dans le
    cours et que la gestion d’erreurs est correcte, le projet est réussi et vous pouvez
    passer à l’implémentation des bonus.
    Le projet est à rendre à 17h15 maximum.
    Joignez votre projet compressé au format zip juste ici :
    https://forms.gle/akiwX9iyB4cSKPfX7
