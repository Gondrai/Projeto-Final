#ifndef SALA_H
#define SALA_H

#include <vector>
#include "Leito.h"

using namespace std;

class Sala
{
private:
    vector<Leito> leitos;

public:
    Sala();
    Sala(int total_leitos);                //Cria uma sala com o total de leitos desejável
    ~Sala();
    void Create();                         //Adiciona um leito  na sala
    void Create(Leito);
    void Delete();                         //Deleta o ultimo leito da sala
    void Delete(int pos);                  //Deleta um leito informando a posição no vetor
    int get_numero_leitos();               //Retorna o número de leitos
    int get_numero_leitos_ocupados();      //Retorna o nÃºmero de leitos ocupados(ocupado = 1)
    int get_numero_leitos_desocupados();   //Retorna o nÃºmero de leitos desocupados(ocupado = 0)
};

#endif
