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
    Sala(int total_leitos);
    ~Sala();
    void Create();
    void Delete();
    void Delete(int pos);
    int get_numero_leitos();
    int get_numero_leitos_ocupados();
    int get_numero_leitos_desocupados();
    void set_ocupacao_leito(int, int);
};

#endif
