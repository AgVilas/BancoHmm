#ifndef CONTA_CARTAO_HPP
#define CONTA_CARTAO_HPP

#include "Pessoa.hpp"
#include <string>
using std::string;

/**
 * @brief Classe que representa uma conta cartão, derivada de Pessoa.
 */
class ContaCartao : public Pessoa {
private:
    int saldo;                // Saldo disponível na conta
    string tipoConta;         // Tipo da conta (ex.: Conta Poupança, Conta Corrente)
    int valorEmprestimo;      // Valor do empréstimo realizado

public:
    // Construtor que inicializa os atributos e define saldo e empréstimo como zero.
    ContaCartao(const string& nomeCompleto, int idade, const string& genero, const string& tipoConta);

    // Métodos de acesso
    int getSaldo() const;
    string getTipoConta() const;
    int getValorEmprestimo() const;

    // Operações da conta
    void depositar(int valor);
    void levantar(int valor);
    void definirValorEmprestimo(int valor);

    // Retorna os detalhes da conta, incluindo informações pessoais.
    string obterDetalhes() const;
};

#endif // CONTA_CARTAO_HPP
