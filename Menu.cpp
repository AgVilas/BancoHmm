#include "Menu.hpp"
#include "ContaCartao.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

// Construtor que exibe o menu e direciona para a opção escolhida.
Menu::Menu() {
    cout << "x================ Menu ===================x" << endl;
    cout << "1 - Entrar na Conta" << endl;
    cout << "2 - Criar Conta" << endl;
    cout << "3 - Sair" << endl;
    cout << "x========================================x" << endl;
    int opcao;
    cin >> opcao;
    switch (opcao) {
        case 1:
            cout << "Entrar na Conta" << endl;
            entrarNaConta();
            break;
        case 2:
            cout << "Criar Conta" << endl;
            // Implementar lógica para criação de conta, se necessário.
            break;
        case 3:
            cout << "Sair" << endl;
            break;
        default:
            cout << "Opção Inválida" << endl;
            break;
    }
}

// Processa a opção "entrar na conta" lendo dados de um arquivo.
void Menu::entrarNaConta() {
    string idConta;
    string linha;
    cout << "Digite o ID da conta: ";
    cin >> idConta;

    std::ifstream arquivo("informacoesCliente.txt");
    bool contaEncontrada = false;
    vector<string> elementos;

    if (arquivo.is_open()) {
        while (std::getline(arquivo, linha)) {
            std::istringstream stream(linha);
            string item;
            elementos.clear();

            while (std::getline(stream, item, ',')) {
                elementos.push_back(item);
            }

            // Verifica se o primeiro elemento corresponde ao ID informado.
            if (!elementos.empty() && elementos[0] == idConta) {
                contaEncontrada = true;
                break;
            }
        }
        arquivo.close();
    } else {
        cout << "Não foi possível abrir o arquivo." << endl;
        return;
    }

    if (contaEncontrada) {
        cout << "Conta encontrada. Criando objeto..." << endl;
        // Cria objeto ContaCartao a partir dos dados do arquivo (exemplo)
        ContaCartao contaCliente(elementos[1], std::stoi(elementos[2]), elementos[3], elementos[4]);
        // Aqui pode ser implementada a lógica de operações com o objeto 'contaCliente'
    } else {
        cout << "Conta não encontrada." << endl;
        // Retorna ao menu principal chamando novamente o construtor
        Menu novoMenu;
    }
}
