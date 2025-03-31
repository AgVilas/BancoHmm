#include <iostream>
#include "Atendente.hpp"
#include "Gestor.hpp"
#include "Arquivo.hpp"
#include "Menu.hpp"

using std::cout;
using std::cin;
using std::endl;

int main() {
    // Criação de objetos de exemplo
    Atendente atendente("Mandinho Silva", 30, "Masculino", 50000, "FUNC123", 156, "Área Econômica");
    ContaCartao contaCliente = atendente.abrirConta("João Pereira", 18, "Masculino", "Conta Poupança");
    Gestor gestor("Saldina Costa", 35, "Feminino", 70000, "FUNC456", "Atendimento", "Gestora Econômica", 10);

    int opcao;
    int valor;
    bool autorizacaoEmprestimo;

    cout << "Selecione uma opção:" << endl;
    cout << "1 - Ver Saldo" << endl;
    cout << "2 - Depositar Dinheiro" << endl;
    cout << "3 - Levantar Dinheiro" << endl;
    cout << "4 - Solicitar Empréstimo" << endl;
    cin >> opcao;
    cout << endl;

    // Processamento da opção selecionada
    switch (opcao) {
        case 1:
            cout << "Saldo: " << contaCliente.getSaldo() << endl;
            break;
        case 2:
            cout << "Quanto deseja depositar? ";
            cin >> valor;
            contaCliente.depositar(valor);
            break;
        case 3:
            cout << "Quanto deseja levantar? ";
            cin >> valor;
            contaCliente.levantar(valor);
            break;
        case 4:
            autorizacaoEmprestimo = gestor.autorizarEmprestimo(contaCliente.getTipoConta());
            if (autorizacaoEmprestimo) {
                cout << "Digite o valor do Empréstimo: ";
                cin >> valor;
                contaCliente.definirValorEmprestimo(valor);
            } else {
                cout << "Empréstimo não autorizado para este tipo de conta." << endl;
            }
            break;
        default:
            cout << "Opção inválida." << endl;
    }

    // Obtenção dos detalhes para salvamento
    string detalhesCliente = contaCliente.obterDetalhes();
    string detalhesAtendente = atendente.obterDetalhes();
    string detalhesGestor = gestor.obterDetalhes();

    // Manipulação de arquivos para salvar os dados
    Arquivo arquivo;
    arquivo.salvarConteudo(detalhesCliente, "informacoesCliente.txt");
    arquivo.salvarConteudo(detalhesAtendente, "informacoesAtendente.txt");
    arquivo.salvarConteudo(detalhesGestor, "informacoesGestor.txt");

    // Exibição do conteúdo salvo (opcional)
    arquivo.exibirConteudo("informacoesCliente.txt");

    // Inicia o menu de interação com o usuário.
    Menu menu;

    return 0;
}
