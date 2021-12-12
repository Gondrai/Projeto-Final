#ifndef DATEINOUT_H
#define DATEINOUT_H

#include <time.h>
#include <cstdlib>
// Estrutura para salvar data de pacientes
struct Date
{
    int day;
    int mon;
    int year;
    int hour;
    int min;
    int sec;
};

class DateInOut
{
public:
    struct Date in;  // Data de entrada
    struct Date out; // Data de saida
    DateInOut(); // Inicializa os atributos de in e out com valor -1
    ~DateInOut(){}
    void gen_Date_in(); // Adiciona a data atual na variável da data de entrada
    void gen_Date_out(); // Adiciona a data atual na variável da data de saída
    struct Date get_Date_in(); // Retorna a data de entrada
    struct Date get_Date_out(); // Retorna a data de saída
};

#endif

