#include <string>
#include "Sala.h"

class Ala
{
private:
    vector<Sala> salas; //Vetor para armazenar as salas da Ala

public:
    Ala();
    Ala(int total_salas);
    ~Ala();
    void Menu(int opc);
    void Create();                   // Cria uma sala nova
    void Create(Sala sala);          // Insere uma sala
    Sala Read(int pos);              // Obtem uma sala em especifico
    void Update(Sala sala, int pos); // Atualiza uma posição
    void Delete();                   // Deleta a última sala
    void Delete(int pos);            // Deleta uma posição
    float TaxaOcupacaoLeito();       // Taxa de ocupação
    float TaxaDesocupacaoLeito();    // Taxa de desoucupeção
    int TotalLeitos();               // Total de leitos
    int TotalSalas();                // Total salas
};
