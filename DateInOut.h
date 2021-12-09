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
    bool valid; //false -> acabou de entrar: só printa data de entrada
                //true -> entrou e saiu: printa entrada e saida
};

class DateInOut
{
public:
    struct Date *in;  // Data de entrada
    struct Date *out; // Data de saída
    DateInOut(){in = out = NULL;}
    ~DateInOut(){delete in; delete out; in = out = NULL;}
    void gen_Date_in(); // Adiciona a data atual na variável da data de entrada
    void gen_Date_out(); // Adiciona a data atual na variável da data de saída
    struct Date get_Date_in(); // Retorna a data de entrada
    struct Date get_Date_out(); // Retorna a data de saída
};
