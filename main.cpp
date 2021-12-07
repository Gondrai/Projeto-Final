// Controle e gerenciamento de paciente.
#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "Paciente.h"
#include "Leito.h"
#include "ArquivoPacientes.h"
#include "Sala.h"
#include "DateInOut.h"

using namespace std;
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
