#ifndef ATENDENTE_HPP
#define ATENDENTE_HPP

#include "Funcionario.hpp"
#include "ContaCartao.hpp"
#include <string>
using std::string;

/**
 * @brief Classe que representa um atendente, derivada de Funcionario.
 */
class Atendente : public Funcionario {
private:
    int numeroBalcao;          // Número do balcão do atendente
    string categoriaAtendente; // Categoria do atendente

public:
    // Construtor com inicialização dos atributos.
    Atendente(const string& nomeCompleto, int idade, const string& genero, int salario, const string& identificacao,
              int numeroBalcao, const string& categoriaAtendente);

    // Métodos de acesso e modificação
    int getNumeroBalcao() const;
    void setNumeroBalcao(int numeroBalcao);
    string getCategoriaAtendente() const;

    // Cria uma conta para um cliente.
    ContaCartao abrirConta(const string& nomeCompleto, int idade, const string& genero, const string& tipoConta) const;

    // Retorna os detalhes do atendente.
    string obterDetalhes() const;
};

#endif // ATENDENTE_HPP
