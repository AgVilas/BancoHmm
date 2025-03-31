#ifndef PESSOA_HPP
#define PESSOA_HPP

#include <string>

class Pessoa {
protected:
    std::string nome;
    int idade;
    std::string sexo;

public:
    Pessoa(std::string nome, int idade, std::string sexo);
    std::string getName();
    void setName(std::string n);
    int getIdade();
    void setIdade(int id);
    std::string getSexo();
    void setSexo(std::string s);
    std::string getDetalhes1();
};

#endif