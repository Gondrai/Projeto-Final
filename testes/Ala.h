#ifndef ALA_H
#define ALA_H

#include "Sala.h"

class Ala
{
private:
    vector<Sala> salas; //Vetor para armazenar as salas da Ala

public:
    Ala();
    Ala(int); //Cria uma ala passando o total desejado de salas
    ~Ala();
    void Create();                   // Cria uma sala nova
    void Create(Sala);               // Insere uma sala ja criada no vetor
    Sala Read(int);                  // Obtem uma sala em especifico
    void Update(Sala, int);          // Atualiza a sala da posição escolhida
    void Delete();                   // Deleta a última sala
    void Delete(int);                // Deleta a sala na posição escolhida
    float TaxaOcupacaoLeito();       // Retorna o percentual de leitos ocupados na ala
    float TaxaDesocupacaoLeito();    // Retorna o percentual de leitos desocupados na ala
    int TotalLeitos();               // Retorna o total de leitos na ala
    int TotalSalas();                // Retorna o total de salas na ala
};

#endif
