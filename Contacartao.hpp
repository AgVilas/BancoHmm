#ifndef CONTACARTAO_HPP
#define CONTACARTAO_HPP

#include "Pessoa.hpp"

class Contacartao : public Pessoa {
protected:
    int saldo;
    std::string tipoConta;
    int emprestimo;

public:
    Contacartao(std::string nome, int idade, std::string sexo, std::string tC);
    int getSaldo();
    std::string getTipoConta();
    void Depositar(int valor);
    void levantar(int valor);
    void setFazerEmprestimo(int valor);
    std::string getDetalhes3();
};

#endif