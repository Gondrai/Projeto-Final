#include "ArquivoPacientes.h"

using namespace std;
//Construtor
ArquivoPacientes::ArquivoPacientes()
{
}

void ArquivoPacientes::Menu(int escolha){
    cout << "MENU" <<;
    cout << "1 -  Criar" <<;
    cout << "2 -  Marcar saída" <<;
    cout << "3 -  Ler" <<;
    cout << "4 -  Atualizar" <<;
    cout << "5 -  Deletar" <<;
    cout << "6 -  Deletar com CPF" <<;
    cout << "7 -  Dizer o total de altas" <<;
    cout << "Favor informar a atividade que deseja realizar:" <<;
    cin >> escolha;
    If (escolha = 0)
    {
        cout << "Opção inexistente" ;
    }
    If (escolha = 1)
    {
         void ArquivoPacientes::Create();
    }
    If (escolha = 2)
    {
         void ArquivoPacientes::MarcarSaida();
    }
    If (escolha = 3)
    {
         Paciente ArquivoPacientes::Read();
    }
    If (escolha = 4)
    {
         void ArquivoPacientes::Update();
    }
    
}

void ArquivoPacientes::Create(Paciente p)
{   
    DateInOut dateIn;
    dateIn.gen_Date_in();
    this->pacientes.push_back(p);      // pushback adiciona um novo
    this->dateInOut.push_back(dateIn); // pushback date
}

void ArquivoPacientes::MarcarSaida(string cpf)
{
    int pos = this->ReadPos(cpf);
    this->dateInOut[pos].gen_Date_out();
    this->pacientes[pos].set_situacao("alta");
}

Paciente ArquivoPacientes::Read(int i)
{
    return this->pacientes[i];
}

void ArquivoPacientes::Update(Paciente p, int i)
{
    this->pacientes[i] = p;
}

void ArquivoPacientes::Delete()
{
    this->pacientes.pop_back(); //remove o ultimo paciente do vetor
    this->dateInOut.pop_back();
}

void ArquivoPacientes::DeleteWithCpf(string cpf)
{
    for (int i = 0; i < this->pacientes.size(); i++)
    {
        if (this->pacientes[i].get_cpf() == cpf)
        {
            this->pacientes.erase(this->pacientes.begin() + i);
            this->dateInOut.erase(this->dateInOut.begin() + i);
            break;
        }
    }
}

DateInOut ArquivoPacientes::getDataPaciente(int pos){
    return this->dateInOut[pos];
}

Paciente ArquivoPacientes::Read(string cpf)
{
  int pos;
    for (int i = 0; i < this->pacientes.size(); i++)
      if (this->pacientes[i].get_cpf() == cpf)
        pos = i;
  return this->pacientes[pos];
}

int ArquivoPacientes::ReadPos(string cpf)
{
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_cpf() == cpf)
            return i;
    return -1;
}

int ArquivoPacientes::Total() {
    return this->pacientes.size();
}

int ArquivoPacientes::TotalAlta()
{
    int totalAlta = 0;
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_situacao() == "alta")
            totalAlta++;
    return totalAlta;
}

int ArquivoPacientes::TotalInternados()
{
    int totalInternado = 0;
    for (int i = 0; i < this->pacientes.size(); i++)
        if (this->pacientes[i].get_situacao() == "internado")
            totalInternado++;
    return totalInternado;
}
