#include "Sala.h"

Sala::Sala() {}

//Cria uma sala com o total de leitos desejÃ¡vel
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

//Deleta o ultimo leito da sala
void Sala::Delete()
{
    this->leitos.pop_back();
}

//Deleta um leito informando a posiÃ§Ã£o no vetor
void Sala::Delete(int pos)
{
    this->leitos.erase(this->leitos.begin() + pos);
}

void Sala::set_ocupacao_leito(int pos, int ocp)
{
    this->leitos[pos].set_ocupacao(ocp);
}

Sala::~Sala() {}

//Retorna o nÃºmero de leitos
int Sala::get_numero_leitos()
{
    return this->leitos.size();
}

//Retorna o nÃºmero de leitos ocupados(ocupado = 1)
int Sala::get_numero_leitos_ocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (this->leitos[i].get_ocupacao())
            total += 1;
    return total;
}

//Retorna o nÃºmero de leitos desocupados(ocupado = 0)
int Sala::get_numero_leitos_desocupados()
{
    int total = 0;
    for (int i = 0; i < this->leitos.size(); i++)
        if (!this->leitos[i].get_ocupacao())
            total += 1;
    return total;
}

int main(){
	Sala s(10);
	s.set_ocupacao_leito(3, 1);
	cout << s.get_numero_leitos_desocupados() << endl;
	return 0;
}
