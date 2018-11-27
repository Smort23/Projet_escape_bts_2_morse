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

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "bonjour" << std::endl;


    Afficheur affich1;
    affich1.envoyerMessage("APPUYEZ SUR ENTREE");
    std::cout << "Tapez entree pour commencer" << std::endl;
    std::string s;
    std::cin >> s;

    QThread::sleep(3);
    affich1.envoyerMessage("phrase 2");
    QThread::sleep(3);
    affich1.envoyerMessage("phrase 3");
    QThread::sleep(3);

    affich1.envoyerMessage("phrase 4");


    return a.exec();

}
