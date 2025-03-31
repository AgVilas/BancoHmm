#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Funcionario.hpp"

// Classe Gestor que herda da classe Funcionario
class Gestor : public Funcionario {
private:
    // Atributos privados da classe Gestor
    std::string setor;      // Setor do gestor
    std::string cargo;      // Cargo do gestor
    int numFunciona;        // Número de funcionários sob gestão

public:
    // Construtor da classe Gestor
    Gestor(std::string nome, int idade, std::string sexo, 
           int s, std::string nu, std::string sd, std::string c, int nf);

    // Métodos getters e setters para acessar e modificar os atributos
    std::string getSetor();                // Retorna o setor do gestor
    void setSetor(std::string st);         // Define o setor do gestor

    std::string getCargo();                // Retorna o cargo do gestor

    int getNumfunciona();                  // Retorna o número de funcionários sob gestão
    void setNumfunciona(int nuf);          // Define o número de funcionários sob gestão

    // Método para autorizar empréstimos
    bool AutorizarEmprest(std::string tipo);

    // Método para obter os detalhes do gestor
    std::string getDetalhes();
};

#endif