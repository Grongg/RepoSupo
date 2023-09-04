#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>

class Test {
public:
	Test();
	Test(std::string _nom, std::string _classe, std::string _age);
	~Test();

	std::string getNom() const;
	void setNom(std::string _nom);

	std::string getClasse() const;
	void setClasse(std::string _classe);

	std::string getAge() const;
	void setAge(std::string _age);

private:
	std::string nom;
	std::string classe;
	std::string age;
};

#endif // TEST_H
