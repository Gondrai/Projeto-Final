#include <string>
#include <vector>
#include <iostream>
#include "Ala.h"
#include "ArquivoPacientes.h"
#include "Leito.h"
#include "Sala.h"
#include "Hospital.h"

Menu::Menu() {};

void Ala::Menu(int opcao){
    cout << "MENU" << endl;
    cout << "1 -  Hospital" << endl;
    cout << "2 -  Arquivo paciente" << endl;
    cout << "3 -  Leito" << endl;
    cout << "4 -  Ala" << endl;
    cout << "5 -  Sala" << endl;
    cout << "6 -  Encerrar sessão" << endl;
    cin >> opcao;
    while ( opcao =! 6 )   // Walks buffer until NULL
   {
      switch ( opcao )
      {
         case '1':
            Hospital::Hospital();
            break;
         case '2':
            ArquivoPacientes::ArquivoPacientes();
            break;
         case '3':
            Leito::Leito();
            break;
         case '4':
            Ala::Ala();
            break;
         case '5':
            Sala::Sala();
            break;
         default:
            cout << "Sessã encerrada" << endl;;
      }
   }
}
