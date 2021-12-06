#include <string>
#include <vector>
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
    struct Date in;  // Data de entrada
    struct Date out; // Data de saída
};

// Salva quando o usuário entrou e quanto saiu

