#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Superclasse Pessoa
class Pessoa {
protected:
    string name;  // Nome da pessoa
    int idade;    // Idade da pessoa
    string sexo;  // Sexo da pessoa

public:
    // Construtor da classe Pessoa
    Pessoa(string n, int id, string s) {
        name = n;
        idade = id;
        sexo = s;
    }

    // Métodos de acesso e modificação
    string getName() {
        return name;
    }
    void setName(string n) {
        name = n;
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
        return "nome: " + name + "\nidade: " + to_string(idade) + "\nsexo: " + sexo;
    }
};

// Classe Funcionario que herda de Pessoa
class Funcionario : public Pessoa {
protected:
    int salario;     // Salário do funcionário
    string numero;   // Número do funcionário

public:
    // Construtor da classe Funcionario
    Funcionario(string name, int idade, string sexo, int s, string nu) : Pessoa(name, idade, sexo) {
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
        cout << "Salario atual: " << getSalario();
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
    Contacartao(string name, int idade, string sexo, string tC) : Pessoa(name, idade, sexo) {
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
        if (saldo > valor) {
            saldo -= valor;
            cout << "levamento feito com sucesso" << endl;
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
    Gestor(string name, int idade, string sexo, int s, string nu, string sd, string c, int nf) : Funcionario(name, idade, sexo, s, nu) {
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
        return tipo == "Conta Corente";
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
    Atendente(string name, int idade, string sexo, int s, string nu, int nrb, string ct) : Funcionario(name, idade, sexo, s, nu) {
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
    Contacartao abrirConta(string name, int idade, string sexo, string tipoc) {
        return Contacartao(name, idade, sexo, tipoc);
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
        arquivo << t << "\n";
        arquivo.close();
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
            cout << "nao foi possivel abrir o arquivo";
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
    Contacartao ct = at.abrirConta("Joao", 18, "Masculino", "Conta ponpanca");
    Gestor ge = Gestor("Saldina", 35, "Feminino", 70000, "258++::", "Atendimento", "Gestor da economia", 10);

    // Menu de opções
    cout << "selecione uma opcao\n1-Saldo\n2-depositar dinheiro\n3-levantar dinheiro\n4-fazer emprestimo";
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
            if (a == true) {
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