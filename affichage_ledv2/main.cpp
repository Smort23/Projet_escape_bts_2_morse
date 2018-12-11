#include <QCoreApplication>
#include <iostream>
#include "afficheur.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>
#include <QThread>
#include "client.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "bonjour" << std::endl;


    Afficheur affich1;
    std::cout << "QUEL BEL AFFICHEUR"<< std::endl;
    affich1.envoyerMessage("Vous devez rentranscire en morse: -----.-.....  a l'aide des boutons poussoirs");
    QThread::sleep(1);
    affich1.envoyerMessage("RETRANSCRIVEZ : -----.-.....");
    QThread::sleep(1);
    affich1.envoyerMessage("-----.-.....");

    std::cout << "Saisir le mot de passe"<< std::endl;
    std::string s;
    std::cin >> s;

    bool continuer = true;

    do {

        if(s == "MORSE" || s == "morse")
        {
            s = "toto";
            continuer = false;

        }
        else
        {
           std::cout << "Ce n'est pas le bon mot de passe, reessayez"<< std::endl;
           std::cin >> s;
         }
    }while( continuer );


    std::cout << "PLUS DE BOUCLE"<< std::endl;

    affich1.envoyerMessage("C'est gagne !");
    Client * c1 = new Client;
    QThread::sleep(4);
    QCoreApplication::processEvents();
    QCoreApplication::processEvents();

    return a.exec();

}
