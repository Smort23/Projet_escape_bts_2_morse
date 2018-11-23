#include <QCoreApplication>
#include <iostream>
#include "afficheur.h"
#include <iostream>
#include <sstream>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <windows.h>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "bonjour" << std::endl;


    Afficheur affich1;
    affich1.envoyerMessage("RED IS DEAD ");


    return a.exec();

}
