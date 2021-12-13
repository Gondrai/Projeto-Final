#include "Hospital.h"

Hospital::Hospital() {}

Hospital::Hospital(int total_alas)
{
    for (int i = 0; i < total_alas; i++)
    {
        Ala ala;
        this->alas.push_back(ala);
    }
}

Hospital::~Hospital() {}

void Hospital::Create()
{
    Ala ala;
    this->alas.push_back(ala);
}


void Hospital::Create(ArquivoPacientes arquivo) {
    this->arquivoPacientes = arquivo;
}

void Hospital::Create(Ala ala)
{
    this->alas.push_back(ala);
}

void Hospital::Delete()
{
    this->alas.pop_back();
}

void Hospital::Delete(int pos)
{
    this->alas.erase(this->alas.begin() + pos);
}

/*void Hospital::InternarPaciente(Paciente p, int pos)
{
	string cpf = p.get_cpf();
	this->arquivoPacientes.Create(p);
	int i = this->arquivoPacientes.ReadPos(cpf);
	this->alas[pos] =
}*/

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
            if (datePaciente.out.day != -1)
                cout << "Data de saida: " << "0" << datePaciente.out.day << "/" << datePaciente.out.mon << "/" << datePaciente.out.year << endl;
            cout << endl;
        }else{
            cout << "Data de entrada: " << datePaciente.in.day << "/" << datePaciente.in.mon << "/" << datePaciente.in.year << endl;
            if (datePaciente.out.day != -1)
                cout << "Data de saida: " << datePaciente.out.day << "/" << datePaciente.out.mon << "/" << datePaciente.out.year << endl;
            cout << endl;
        }
    }
}
