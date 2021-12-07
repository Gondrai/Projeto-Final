#include <string>
#include <vector>
#include <iostream>
#include "Sala.h"
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
