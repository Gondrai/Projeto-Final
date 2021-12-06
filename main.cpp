// Controle e gerenciamento de paciente.
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Paciente.h"

using namespace std;

// Estrutura para salvar data de pacientes
struct Date
{
    int day;
    int mon;
    int year;
    int hour;
    int min;
    int sec;
    bool valid; //false -> acabou de entrar: só printa data de entrada
                //true -> entrou e saiu: printa entrada e saida
};

// Salva quando o usuário entrou e quanto saiu
class DateInOut
{
public:
    struct Date in;  // Data de entrada
    struct Date out; // Data de saída
};

class Sala
{
private:
    vector<Leito> leitos;

public:
    Sala();
    Sala(int total_leitos);
    ~Sala();
    void Create();
    void Create(Leito leito);
    void Delete();
    void Delete(int pos);
    int get_numero_leitos();
    int get_numero_leitos_ocupados();
    int get_numero_leitos_desocupados();
};

Sala::Sala() {}

//Cria uma sala com o total de leitos desejável
Sala::Sala(int total_leitos)
{
    for (int i = 0; i < total_leitos; i++)
    {
        Leito leito;
        leito.set_ocupacao(0);
        this->leitos.push_back(leito);
    }
}

//Adiciona um leito  na sala
void Sala::Create()
{
    Leito leito;
    this->leitos.push_back(leito);
}

//Adiciona um leito na sala passando o leito desejado
void Sala::Create(Leito leito)
{
    this->leitos.push_back(leito);
}

//Deleta um leito da sala
void Sala::Delete()
{
    this->leitos.pop_back();
}

//Deleta um leito informando a posição no vetor
void Sala::Delete(int pos)
{
    this->leitos.erase(this->leitos.begin() + pos);
}

Sala::~Sala() {}

//Retorna o número de leitos
int Sala::get_numero_leitos()
{
    return this->leitos.size();
}

//Retorna o número de leitos ocupados(ocupado = 1)
int Sala::get_numero_leitos_ocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao() == 1)
            total += 1;
    return total;
}

//Retorna o número de leitos desocupados(ocupado = 0)
int Sala::get_numero_leitos_desocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao() == 0)
            total += 1;
    return total;
}

class Ala
{
private:
    vector<Sala> salas; //Vetor para armazenar as salas da Ala

public:
    Ala();
    Ala(int total_salas);
    ~Ala();
    void Create();                   // Cria uma sala nova
    void Create(Sala sala);          // Insere uma sala
    Sala Read(int pos);              // Obtem uma sala em especifico
    void Update(Sala sala, int pos); // Atualiza uma posição
    void Delete();                   // Deleta a última sala
    void Delete(int pos);            // Deleta uma posição
    float TaxaOcupacaoLeito();       // Taxa de ocupação
    float TaxaDesocupacaoLeito();    // Taxa de desoucupeção
    int TotalLeitos();               // Total de leitos
    int TotalSalas();                // Total salas
};

Ala::Ala() {}

//Cria uma ala passando o total desejado de salas
Ala::Ala(int total_salas)
{
    for (int i = 0; i < total_salas; i++)
    {
        Sala sala;
        this->salas.push_back(sala);
    }
}

Ala::~Ala() {}

//Cria uma sala nova na ala
void Ala::Create()
{
    Sala sala;
    this->salas.push_back(sala);
}

//Insere uma sala na ala
void Ala::Create(Sala sala)
{
    this->salas.push_back(sala);
}

//Retorna uma sala pela posição no vetor
Sala Ala::Read(int pos)
{
    return this->salas[pos];
}

//Atualiza uma sala com sua posição no vetor
void Ala::Update(Sala sala, int pos)
{
    this->salas[pos] = sala;
}

//Deleta a última sala
void Ala::Delete()
{
    this->salas.pop_back();
}

//Deleta uma sala informando a posição no vetor
void Ala::Delete(int pos)
{
    this->salas.erase(this->salas.begin() + 1);
}

//Retorna a taxa de ocupação de leitos na ala
float Ala::TaxaOcupacaoLeito()
{
    int total = 0;
    int ocupacao = 0;
    for (int i = 0; i < this->salas.size(); i++)
    {
        ocupacao += this->salas[i].get_numero_leitos_ocupados();
        total += this->salas[i].get_numero_leitos();
    }
    return ((float)ocupacao / total) * 100;
}

//Retorna a taxa de desocupação de leitos na ala
float Ala::TaxaDesocupacaoLeito()
{
    int total = 0;
    int desocupacao = 0;
    for (int i = 0; i < this->salas.size(); i++)
    {
        desocupacao += this->salas[i].get_numero_leitos_desocupados();
        total += this->salas[i].get_numero_leitos();
    }
    return ((float)desocupacao / total) * 100;
}

//Retorna o total de leitos da ala
int Ala::TotalLeitos()
{
    int total = 0;
    for (int i = 0; i < this->salas.size(); i++)
        total += this->salas[i].get_numero_leitos();
    return total;
}

//Retorna o total de salas na ala
int Ala::TotalSalas()
{
    return this->salas.size();
}

class Hospital
{
private:
    vector<Ala> alas; //Vetor que armazena as alas do hospital
    ArquivoPacientes arquivoPacientes;

public:
    Hospital();
    Hospital(int total_alas);
    ~Hospital();
    void Create();                // Insere uma ala nova
    void Create(Ala ala);         // Insere uma ala feita
    void Create(ArquivoPacientes arquivo);
    void Delete();                // Deleta a ultima ala
    void Delete(int pos);         // Deleta uma ala especifica
    void relatorio_estatistico(); // Relatórios
};

Hospital::Hospital() {}

//Construtor que cria o hospital informando o total de alas
Hospital::Hospital(int total_alas)
{
    for (int i = 0; i < total_alas; i++)
    {
        Ala ala;
        this->alas.push_back(ala);
    }
}

Hospital::~Hospital() {}

//Insere uma ala padrão no hospital
void Hospital::Create()
{
    Ala ala;
    this->alas.push_back(ala);
}

//Insere os pacientes nos arquivos do hospital
void Hospital::Create(ArquivoPacientes arquivo) {
    this->arquivoPacientes = arquivo;
}

//Insere uma ala feita
void Hospital::Create(Ala ala)
{
    this->alas.push_back(ala);
}

//Relatório final do hospital
void Hospital::relatorio_estatistico()
{
    cout << "-------------------------------------------------------------" << endl;
    cout << "---------------- RELATORIO HOSPITAL -------------------------" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << endl;
    
    // Informações sobre os pacientes
    cout << "Total de pacientes que passaram no hospital: " << this->arquivoPacientes.Total() << endl;
    cout << "Total de internados: " << this->arquivoPacientes.TotalInternados() << endl;
    cout << "Total de altas: " << this->arquivoPacientes.TotalAlta() << endl;
    cout << "Quantidade de Alas: " << this->alas.size() << endl;
    cout << endl;

    // Investiga cada Ala
    for (int i = 0; i < this->alas.size(); i++)
    {
        Ala ala = this->alas[i];
        cout << "-------------------------------------------------------------" << endl;
        cout << "\tRELATORIO DA ALA " << i+1 << endl;
        cout << "\tTotal de salas: " << ala.TotalSalas() << endl;
        cout << "\tTotal de leitos: " << ala.TotalLeitos() << endl;
        if(ala.TotalSalas() > 0) {
            cout << "\tTaxa de ocupacao dos leitos: " << ala.TaxaOcupacaoLeito() << "%" << endl;
            cout << "\tTaxa de desocupacao dos leitos: " << ala.TaxaDesocupacaoLeito()<< "%" << endl;
        }

        // Investiga cada Sala da Ala atual
        for (int j = 0; j < ala.TotalSalas(); j++)
        {
            Sala sala = ala.Read(j);
            cout << "\t\t-------------------------------" << endl;
            cout << "\t\tRELATORIO DA SALA " << j+1 << endl;
            cout << "\t\tTotal de leitos: " << sala.get_numero_leitos() << endl;
            cout << "\t\tTotal de leitos ocupado: " << sala.get_numero_leitos_ocupados() << endl;
            cout << "\t\t-------------------------------" << endl;
            cout << endl;
        }
        cout << endl;
    }

    // Investiga cada usuário
    for (int i = 0; i < this->arquivoPacientes.Total(); i++) {
        Paciente paciente = this->arquivoPacientes.Read(i);
        DateInOut datePaciente = this->arquivoPacientes.getDataPaciente(i);
        paciente.imprimir();
        if(datePaciente.in.day < 10){
            cout << "Data de entrada: " << "0" << datePaciente.in.day << "/" << datePaciente.in.mon << "/" << datePaciente.in.year << endl;
            if (datePaciente.out.valid)
                cout << "Data de saida: " << "0" << datePaciente.out.day << "/" << datePaciente.out.mon << "/" << datePaciente.out.year << endl;
            cout << endl;
        }else{
            cout << "Data de entrada: " << datePaciente.in.day << "/" << datePaciente.in.mon << "/" << datePaciente.in.year << endl;
            if (datePaciente.out.valid)
                cout << "Data de saida: " << datePaciente.out.day << "/" << datePaciente.out.mon << "/" << datePaciente.out.year << endl;
            cout << endl;
        }
    }
}

int main()
{
    Paciente * p1 = new Paciente("563.732.250-38", "Gabriel", "Quadra 912 Sul Alameda 8", "(63) 99996-2471", "A", 18);
    Paciente * p2 = new Paciente("389.220.400-41", "Priscila", "Rua Andirá", "(92) 99180-1304", "AB", 12);
    Paciente * p3 = new Paciente("244.075.500-15", "Roberta", "Rua Felipe Colombo", "(48) 99311-5496", "AB", 18);
    Paciente * p4 = new Paciente("623.561.930-81", "Renato", "Rua Governador Francisco Mello", "(82) 98769-7149", "O", 80);
    Paciente * p5 = new Paciente("234.640.150-17", "Raul", "Rua Nossa Senhora da Conceição", "(68) 98588-9935", "B", 23);
    p1->set_situacao("internado");
    p2->set_situacao("internado");
    p3->set_situacao("internado");
    p4->set_situacao("internado");
    p5->set_situacao("internado");

    // Arquivos Pacientes
    ArquivoPacientes * arquivoPacientes = new ArquivoPacientes();
    arquivoPacientes->Create(*p1);
    arquivoPacientes->Create(*p2);
    arquivoPacientes->Create(*p3);
    arquivoPacientes->Create(*p4);
    arquivoPacientes->Create(*p5);

    // Paciente com alta
    arquivoPacientes->MarcarSaida("234.640.150-17");

    // Criando leitos
    Leito * l1 = new Leito(0);
    Leito * l2 = new Leito(0);
    Leito * l3 = new Leito(0);
    Leito * l4 = new Leito(1);
    Leito * l5 = new Leito(1);
    Leito * l6 = new Leito(0);
    Leito * l7 = new Leito(1);
    Leito * l8 = new Leito(1);

    // Salas
    Sala * sala1 = new Sala();
    Sala * sala2 = new Sala();

    //Atribuindo os leitos criados a cada sala
    sala1->Create(*l1);
    sala1->Create(*l2);
    sala1->Create(*l3);
    sala1->Create(*l4);
    sala1->Create(*l5);
    sala2->Create(*l6);
    sala2->Create(*l7);
    sala2->Create(*l8);

    // Criando duas alas
    Ala * ala1 = new Ala();
    Ala * ala2 = new Ala();

    ala1->Create(*sala1);
    ala1->Create(*sala2);

    // Criando o hospital, adicionando o arquivo de pacientes, suas alas
    Hospital * hospital = new Hospital();
    hospital->Create(*arquivoPacientes);
    hospital->Create(*ala1);
    hospital->Create(*ala2);
    //Imprimindo relatório final
    hospital->relatorio_estatistico();
    return 0;
}
