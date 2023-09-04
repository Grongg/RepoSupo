#include "Personne.h"

    // Constructeur par défaut

Personne::Personne(){
	age = "";
	nom = "";
	notes = "";
}
Personne::Personne(std::string _age, std::string _nom, std::string _notes){

	this->age = _age;
	this->nom = _nom;
	this->notes = _notes;
}

std::string Personne::getAge()const{
	return age;
}
void Personne::setAge(std::string age){
	this->age = age;
}std::string Personne::getNom()const{
	return nom;
}
void Personne::setNom(std::string nom){
	this->nom = nom;
}std::string Personne::getNotes()const{
	return notes;
}
void Personne::setNotes(std::string notes){
	this->notes = notes;
}