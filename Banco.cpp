#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> // Adicionado para usar std::vector

using namespace std;

// Superclasse Pessoa
class Pessoa {
protected:
    string nome;  // Nome da pessoa
    int idade;    // Idade da pessoa
    string sexo;  // Sexo da pessoa

public:
    // Construtor da classe Pessoa
    Pessoa(string nome, int idade, string sexo) {
        this->nome = nome;
        this->idade = idade;
        this->sexo = sexo;
    }

    // Métodos de acesso e modificação
    string getName() {
        return nome; // Corrigido de "name" para "nome"
    }
    void setName(string n) {
        nome = n; // Corrigido de "name" para "nome"
    }
    int getIdade() {
        return idade;
    }
    void setIdade(int id) {
        idade = id;
    }
    string getSexo() {
        return sexo;
    }
    void setSexo(string s) {
        sexo = s;
    }

    // Método para obter os detalhes da pessoa
    string getDetalhes1() {
        return "nome: " + nome + "\nidade: " + to_string(idade) + "\nsexo: " + sexo; // Corrigido de "name" para "nome"
    }
};

// Classe Funcionario que herda de Pessoa
class Funcionario : public Pessoa {
protected:
    int salario;     // Salário do funcionário
    string numero;   // Número do funcionário

public:
    // Construtor da classe Funcionario
    Funcionario(string nome, int idade, string sexo, int s, string nu) : Pessoa(nome, idade, sexo) {
        salario = s;
        numero = nu;
    }

    // Métodos de acesso e modificação
    int getSalario() {
        return salario;
    }
    void setSalario(int s) {
        salario = s;
    }
    string getNumero() {
        return numero;
    }
    void setNumero(string nu) {
        numero = nu;
    }

    // Método para consultar o salário
    void consultarS() {
        cout << "Salario atual: " << getSalario() << endl;
    }

    // Método para obter os detalhes do funcionário
    string getDetalhes2() {
        return "salario: " + to_string(salario) + "\nNumeroTrabalhor: " + numero + "\nDados pessoais:\n" + getDetalhes1();
    }
};

// Classe Contacartao que herda de Pessoa
class Contacartao : public Pessoa {
protected:
    int saldo;          // Saldo da conta
    string tipoConta;   // Tipo da conta
    int emprestimo;     // Valor do empréstimo

public:
    // Construtor da classe Contacartao
    Contacartao(string nome, int idade, string sexo, string tC) : Pessoa(nome, idade, sexo) {
        saldo = 0;
        tipoConta = tC;
        emprestimo = 0;
    }

    // Métodos de acesso e modificação
    int getSaldo() {
        return saldo;
    }
    string getTipoConta() {
        return tipoConta;
    }

    // Método para depositar dinheiro
    void Depositar(int valor) {
        saldo += valor;
        cout << "deposito feito com sucesso" << endl;
    }

    // Método para levantar dinheiro
    void levantar(int valor) {
        if (saldo >= valor) { // Corrigido para permitir levantamento igual ao saldo
            saldo -= valor;
            cout << "levantamento feito com sucesso" << endl;
        } else {
            cout << "saldo insuficiente, recarregue a conta primeiro" << endl;
        }
    }

    // Método para fazer empréstimo
    void setFazerEmprestimo(int valor) {
        emprestimo = valor;
    }

    // Método para obter os detalhes da conta
    string getDetalhes3() {
        return "Informacao do cliente:\nSaldo atual: " + to_string(saldo) + "\nTipo de conta: " + tipoConta + "\nValor da divida: " + to_string(emprestimo) + "\nDados pessoais:\n" + getDetalhes1();
    }
};

// Classe Gestor que herda de Funcionario
class Gestor : public Funcionario {
private:
    string setor;       // Setor do gestor
    string cargo;       // Cargo do gestor
    int numFunciona;    // Número de funcionários gerenciados

public:
    // Construtor da classe Gestor
    Gestor(string nome, int idade, string sexo, int s, string nu, string sd, string c, int nf) : Funcionario(nome, idade, sexo, s, nu) {
        setor = sd;
        cargo = c;
        numFunciona = nf;
    }

    // Métodos de acesso e modificação
    string getSetor() {
        return setor;
    }
    void setSetor(string st) {
        setor = st;
    }
    string getCargo() {
        return cargo;
    }
    int getNumfunciona() {
        return numFunciona;
    }
    void setNumfunciona(int nuf) {
        numFunciona = nuf;
    }

    // Método para autorizar empréstimo
    bool AutorizarEmprest(string tipo) {
        return tipo == "Conta Corrente"; // Corrigido para "Conta Corrente"
    }

    // Método para obter os detalhes do gestor
    string getDetalhes() {
        return "Informacao do Gestor:\nSetor do gestor: " + setor + "\ncargo do gestor: " + cargo + "\nquantidade de funcionario: " + to_string(numFunciona) + "\nDados do gestor:\n" + getDetalhes2();
    }
};

// Classe Atendente que herda de Funcionario
class Atendente : public Funcionario {
private:
    int nrbalcao;       // Número do balcão
    string categoria;   // Categoria do atendente

public:
    // Construtor da classe Atendente
    Atendente(string nome, int idade, string sexo, int s, string nu, int nrb, string ct) : Funcionario(nome, idade, sexo, s, nu) {
        nrbalcao = nrb;
        categoria = ct;
    }

    // Métodos de acesso e modificação
    int getNrbalcao() {
        return nrbalcao;
    }
    void setNrbalcao(int nrb) {
        nrbalcao = nrb;
    }
    string getCategoria() {
        return categoria;
    }

    // Método para abrir uma conta
    Contacartao abrirConta(string nome, int idade, string sexo, string tipoc) {
        return Contacartao(nome, idade, sexo, tipoc);
    }

    // Método para obter os detalhes do atendente
    string getDetalhes4() {
        return "Informacao do Atendente:\nNumero de balcao: " + to_string(nrbalcao) + "\ncategoria: " + categoria + "\n" + getDetalhes2();
    }
};

// Classe Arquivo para manipulação de arquivos
class Arquivo {
protected:
    fstream arquivo;    // Objeto para manipulação de arquivos

public:
    // Construtor da classe Arquivo
    Arquivo() {}

    // Método para arquivar informações
    void arquivar(string t, string b) {
        arquivo.open(b, ios::out);
        if (arquivo.is_open()) {
            arquivo << t << "\n";
            arquivo.close();
        } else {
            cout << "Erro ao abrir o arquivo para escrita." << endl;
        }
    }

    // Método para mostrar informações do arquivo
    void mostrararq(string b) {
        string linha;
        arquivo.open(b, ios::in);
        cout << "informacao do arquivo:\n";
        if (arquivo.is_open()) {
            while (getline(arquivo, linha)) {
                cout << linha << endl;
            }
            arquivo.close();
        } else {
            cout << "nao foi possivel abrir o arquivo" << endl;
        }
    }
};

// Classe Menu para interação com o usuário
class Menu {
public:
    Menu() {
        cout << "x================Menu===================x" << endl;
        cout << "1-Entrar na Conta\n2-Criar Conta\n3-Sair" << endl;
        cout << "x========================================x" << endl;
        int opcao;
        cin >> opcao;
        switch (opcao) {
            case 1:
                cout << "Entrar na Conta" << endl;
                break;
            case 2:
                cout << "Criar Conta" << endl;
                break;
            case 3:
                cout << "Sair" << endl;
                break;
            default:
                cout << "Opcao Invalida" << endl;
        }
    }

    void entrar_naConta() {
        string id, linha;
        cout << "Digite o ID da conta: ";
        cin >> id;

        ifstream arquivo("infclient.txt");
        bool encontrado = false;
        vector<string> elementos;

        if (arquivo.is_open()) {
            while (getline(arquivo, linha)) {
                stringstream ss(linha);
                string item;
                elementos.clear();

                while (getline(ss, item, ',')) { // Supondo que os elementos estão separados por vírgulas
                    elementos.push_back(item);
                }

                if (!elementos.empty() && elementos[0] == id) {
                    encontrado = true;
                    break;
                }
            }
            arquivo.close();
        } else {
            cout << "Não foi possível abrir o arquivo." << endl;
            return;
        }

        if (encontrado) {
            cout << "ID encontrado. Criando objeto..." << endl;
            // Aqui você pode criar o objeto com base nos dados encontrados
            Contacartao ct(elementos[1], stoi(elementos[2]), elementos[3], elementos[4]); // Exemplo
        } else {
            cout << "ID não encontrado." << endl;
        }
    }
};

// Função principal
int main() {
    string informaCliente, informaAtendente, informaGestor;
    int op, valor;
    bool a;

    // Criação de objetos
    Atendente at = Atendente("Mandinho", 30, "Masculino", 50000, "258+::", 156, "Area da economica");
    Contacartao ct = at.abrirConta("Joao", 18, "Masculino", "Conta poupanca"); // Corrigido para "Conta poupanca"
    Gestor ge = Gestor("Saldina", 35, "Feminino", 70000, "258++::", "Atendimento", "Gestor da economia", 10);

    // Menu de opções
    cout << "selecione uma opcao\n1-Saldo\n2-depositar dinheiro\n3-levantar dinheiro\n4-fazer emprestimo" << endl;
    cin >> op;
    cout << endl;

    // Processamento das opções
    switch (op) {
        case 1:
            cout << "Saldo: " << ct.getSaldo() << endl;
            break;
        case 2:
            cout << "quanto deseja depositar? ";
            cin >> valor;
            cout << endl;
            ct.Depositar(valor);
            break;
        case 3:
            cout << "quanto deseja levantar? ";
            cin >> valor;
            cout << endl;
            ct.levantar(valor);
            break;
        case 4:
            a = ge.AutorizarEmprest(ct.getTipoConta());
            if (a) {
                cout << "digite o valor de Emprestimo" << endl;
                cin >> valor;
                ct.setFazerEmprestimo(valor);
            } else {
                cout << "nao e possivel fazer o emprestimo" << endl;
            }
            break;
        default:
            cout << "opcao invalida " << endl;
    }

    // Obtenção de informações detalhadas
    informaCliente = ct.getDetalhes3();
    informaAtendente = at.getDetalhes4();
    informaGestor = ge.getDetalhes();

    // Manipulação de arquivos
    Arquivo aq = Arquivo();
    aq.arquivar(informaCliente, "infclient.txt");
    aq.arquivar(informaAtendente, "infatendent.txt");
    aq.arquivar(informaGestor, "infgesto.txt");

    return 0;
}