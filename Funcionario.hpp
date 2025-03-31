#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Pessoa.hpp"

class Funcionario : public Pessoa {
protected:
    int salario;
    std::string numero;

public:
    Funcionario(std::string nome, int idade, std::string sexo, 
               int s, std::string nu);
    int getSalario();
    void setSalario(int s);
    std::string getNumero();
    void setNumero(std::string nu);
    void consultarS();
    std::string getDetalhes2();
};

#endif