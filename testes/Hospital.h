#ifndef HOSPITAL_H
#define HOSPITAL_H

#include "Ala.h"
#include "ArquivoPacientes.h"
#include <iostream>

struct endereco_internacao // armazena os indices para o vetor de ala, sala e leito no qual o paciente está internado
{
	int ala;
	int sala;
	int leito;
};

class Hospital
{
private:
    vector<Ala> alas; //Vetor que armazena as alas do hospital
    ArquivoPacientes arquivoPacientes;
    vector<endereco_internacao> endereco; //vetor de enderecos de internação de cada paciente
    
public:
    Hospital();
    Hospital(int);                   //Construtor que cria o hospital informando o total de alas
    ~Hospital();                     
    void Create();                  // Insere uma ala nova
    void Create(Ala);               // Insere uma ala feita
    void Create(ArquivoPacientes);  //Insere os pacientes nos arquivos do hospital
    void Delete();                  // Deleta a ultima ala
    void Delete(int);               // Deleta uma ala especifica
    //void InternarPaciente(Paciente, int);
    //void InternarPaciente(string, int);
    void relatorio_estatistico();   // Relatórios
};

#endif
