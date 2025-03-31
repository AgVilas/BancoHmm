#include "Pessoa.hpp"
#include <string>

// Constructor
Pessoa::Pessoa(std::string nome, int idade, std::string sexo) 
    : nome(nome), idade(idade), sexo(sexo) {}

// Getters
std::string Pessoa::getName() { return nome; }
int Pessoa::getIdade() { return idade; }
std::string Pessoa::getSexo() { return sexo; }

// Setters
void Pessoa::setName(std::string n) { nome = n; }
void Pessoa::setIdade(int id) { idade = id; }
void Pessoa::setSexo(std::string s) { sexo = s; }

// Utility
std::string Pessoa::getDetalhes1() {
    return "nome: " + nome + "\nidade: " + std::to_string(idade) + "\nsexo: " + sexo;
}