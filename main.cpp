// Controle e gerenciamento de paciente.
#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>
#include "Paciente.h"
#include "Leito.h"
#include "ArquivoPacientes.h"
#include "Sala.h"
#include "DateInOut.h"
#include "Ala.h"
#include "Hospital.h"

using namespace std;
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
