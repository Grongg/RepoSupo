#ifndef PERSONNE_H
#define PERSONNE_H
#include <iostream>
#include <string>

class Personne {
public:
	Personne();
	Personne(std::string _age, std::string _nom, std::string _notes);

	std::string getAge() const;
	void setAge(std::string age);

	std::string getNom() const;
	void setNom(std::string nom);

	std::string getNotes() const;
	void setNotes(std::string notes);

private:
	std::string age;
	std::string nom;
	std::string notes;
};

#endif // PERSONNE_H
