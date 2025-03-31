#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP

#include "Pessoa.hpp"
#include <string>
using std::string;

/**
 * @brief Classe que representa um funcionário, derivada de Pessoa.
 */
class Funcionario : public Pessoa {
protected:
    int salario;                 // Salário do funcionário
    string identificacao;        // Número de identificação do funcionário

public:
    // Construtor com inicialização dos atributos.
    Funcionario(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao);

    // Métodos de acesso e modificação
    int getSalario() const;
    void setSalario(int salario);
    string getIdentificacao() const;
    void setIdentificacao(const string& identificacao);

    // Exibe o salário atual no console.
    void exibirSalario() const;

    // Retorna os detalhes do funcionário em formato de string.
    string obterDetalhes() const;
};

#endif // FUNCIONARIO_HPP
