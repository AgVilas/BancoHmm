#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// superclasse
class PessoaZ {
    // atributos
    protected:
    string name;
    int idade;
    string sexo;
    public:
    // Metodos
    PessoaZ(string n,int id, string s ){
        name = n;
        idade = id;
        sexo = s;
    }
    string getName(){
        return name;
    }
    void setName(string n){
        name = n;
    }
    int getIdade(){
        return idade;
    }
    void setIdade(int id){
        idade = id;
    }
    string getSexo(){
        return sexo;
    }
    void setSexo(string s){
        sexo = s;
    }
    string getDetalhes1(){
        return " nome: " +name+ "\n idade: " +to_string(idade)+ "\n sexo: " +sexo;
    }
};

class Funcionario : public PessoaZ {
   // atributos
    protected:
    int salario;
    string numero;
    // metodos
    public:
     Funcionario(string name,int idade,string sexo,int s,string nu) : PessoaZ(name,idade,sexo) {
         salario = s;
         numero = nu;
     } 
    int getSalario(){
        return salario;
    }
    void setSalario(int s){
      salario = s;  
    }
    
    string getNumero(){
        return numero;
    }
    void setNumero(string nu){
       numero = nu; 
    }
    void consultarS(){
        cout << " Salario atual: " <<getSalario();
    }
    string getDetalhes2(){
        return "salario: " +to_string(salario)+ "\n NumeroTrabalhor: " +numero+ "\n Dados pessoais:\n " +getDetalhes1();
    }
};

class Contacartao : public PessoaZ {
    // atributos
    protected:
    int saldo;
    string tipoConta;
    int emprestimo;
    // metodos
    public:
    Contacartao(string name,int idade,string sexo,string tC) : PessoaZ(name,idade,sexo) {
         saldo = 0;
        tipoConta = tC;
        emprestimo=0;
}
    int getSaldo(){
        return saldo;
    }
    string getTipoConta(){
        return tipoConta;
    }
    
    void Depositar(int d){
        saldo += d;
        cout << "deposito feito com sucesso"; cout << endl;
    }
    void levantar(int l){
        if(saldo>l){
        saldo -= l;
        cout << "levamento feito com sucesso";  cout << endl;
    } else{
        cout << "saldo insuficirnte recaregue a conta primeiro"; cout << endl;
    }
    }
    void setFazerEmprestimo(int E){
        emprestimo = E;
            
        }
    
    string getDetalhes3(){
        return "Informacao do cliente:\n Saldo atual: " +to_string(saldo)+ "\n Tipo de conta: " +tipoConta+ "\n Valor da divida: " +to_string(emprestimo)+ "\n Dados pessoais:\n " +getDetalhes1();
    }
};
    
    class Gestor : public Funcionario {
        // atributos
        private:
        string setor;
        string cargo;
        int numFunciona;
        public:
        // metodos
       Gestor(string name,int idade,string sexo,int s,string nu,string sd,string c,int nf) : Funcionario(name,idade,sexo,s,nu){
        setor= sd;
        cargo = c;
        numFunciona = nf;           
       } 
        string getSetor(){
            return setor;
        }
        void setSetor(string st){
           setor = st; 
        }
        string getCargo(){
           return cargo; 
        }
        
        int getNumfunciona(){
            return numFunciona;
        }
        void setNumfunciona(int nuf){
           numFunciona = nuf; 
        }
        bool AutorizarEmprest(string tipo){
        if(tipo == "Conta Corente"){
            return true;
        }else{
            return false;
        }
        }
        string getDetalhes(){
            return "Informacao do Gestor:\n Setor do gestor: " +setor+ "\n cargo do gestor: " +cargo+ "\n quantidade de funcionario: " + to_string(numFunciona) + "\n Dados do gestor:\n " +getDetalhes2();
        }
    };
    class Atendente : public Funcionario {
        // atributos
        private:
        int nrbalcao;
        string categoria;
        // metodos
        public:
        Atendente(string name,int idade,string sexo,int s, string nu,int nrb,string ct) : Funcionario( name, idade, sexo,s, nu) {
            nrbalcao = nrb;
            categoria = ct;
            
        }
        int getNrbalcao(){
            return nrbalcao;
        }
        void setNrbalcao(int nrb){
           nrbalcao = nrb; 
        }
        string getCategoria(){
            return categoria;
        }
        Contacartao abrirConta(string name,int idade,string sexo,string tipoc){
          return   Contacartao(name,idade,sexo,tipoc);
            
        }
        string getDetalhes4(){
            return "Informacao do Atendente:\n Numero de balcao: " +to_string(nrbalcao)+ "\n categoria: " +categoria+ "\n" +getDetalhes2(); 
        }
    };
    class Arquivo {
        protected:
      fstream arquivo;
        
        
        // metodo
        public:
       Arquivo(){
       }
       void arquivar(string t,string b){
       arquivo.open(b,ios::out);
          arquivo << t << "\n" ;
           arquivo.close();
           cout << "arquivo criado com sucesso"; cout << endl;
      }
       void mostrararq(string b){
           string linha;
           arquivo.open(b,ios::in);
           cout << "informacao do arquivo:\n " ;
          if(arquivo.is_open()){
              while(getline(arquivo,linha)){
                   cout << linha;    cout << endl;
              }
             arquivo.close();
         }else {
               cout << " nao foi possivel abrir o arquivo";
         }
       }    
    
   };
int main() {
    string b,c,e;
    int op,d,l,Em;
    bool a;
    Atendente at = Atendente("Mandinho",30,"Masculino",50000,"258+::",156,"Area da economica");
    Contacartao ct = at.abrirConta("Joao",18,"Masculino","Conta ponpanca");
    Gestor ge = Gestor("Saldina",35,"Feminino",70000,"258++::","Atendimento","Gestor da economia",10);
    cout << "selecione uma opcao\n 1-Saldo\n 2-depositar dinheiro\n 3-levantar dinheiro\n 4-fazer emprestimo";
    cin >> op; cout << endl;
    switch (op){
        case 1: cout << "Saldo: " <<ct.getSaldo(); cout << endl;
        break;
        case 2: 
        cout<< "qunto deseja depositar? ";
        cin >> d;   cout << endl;
        ct.Depositar(d);
        break;
        case 3: 
        cout << "quanto deseja levantar? ";
        cin >> l;    cout << endl;
        ct.levantar(l);
        break;
        case 4:
        a =ge.AutorizarEmprest(ct.getTipoConta());
        if(a== true){
            cout << "digite o valor de Emprestimo";  cout << endl;
            cin >> Em;
            ct.setFazerEmprestimo(Em);
        } else {
            cout << "nao e possivel fazer o emprestimo"; cout << endl;
        }
        break;
        default: 
        cout << "opcao invalida "; cout << endl;
    }
    b= ct.getDetalhes3();
    c= at.getDetalhes4();
    e = ge.getDetalhes();
    
    Arquivo aq = Arquivo();
    aq.arquivar(b,"infclient.txt");
    aq.arquivar(c,"infatendent.txt");
   aq.arquivar(e,"infgesto.txt");
   aq.mostrararq("infclient.txt");
    aq.mostrararq("infatendent.txt");
    aq.mostrararq("infgesto.txt");
     
    
    return 0;
}
