#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Funcionario.hpp"
#include <string>
using std::string;

/**
 * @brief Classe que representa um gestor, derivada de Funcionario.
 */
class Gestor : public Funcionario {
private:
    string setor;                      // Setor de atuação do gestor
    string cargo;                      // Cargo do gestor
    int numeroFuncionariosGerenciados; // Número de funcionários gerenciados

public:
    // Construtor que inicializa todos os atributos.
    Gestor(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao,
           const string& setor, const string& cargo, int numeroFuncionariosGerenciados);

    // Métodos de acesso e modificação
    string getSetor() const;
    void setSetor(const string& setor);
    string getCargo() const;
    int getNumeroFuncionariosGerenciados() const;
    void setNumeroFuncionariosGerenciados(int numero);

    // Autoriza empréstimo somente para contas do tipo "Conta Corrente".
    bool autorizarEmprestimo(const string& tipoConta) const;

    // Retorna os detalhes do gestor, incluindo os dados do funcionário.
    string obterDetalhes() const;
};

#endif // GESTOR_HPP
