#include "afficheur.h"

#include <string>
#include <iostream>
#include <sstream>

Afficheur::Afficheur()
{
    m_couleur = 'J';

    // Paramétrage du port série
    m_portSerie.setPortName("COM6");
    m_portSerie.setBaudRate(QSerialPort::Baud9600);
    m_portSerie.setDataBits(QSerialPort::Data8);
    m_portSerie.setParity(QSerialPort::NoParity);
    m_portSerie.setStopBits(QSerialPort::OneStop);

    // Ouverture du port série
    m_portSerie.open(QIODevice::ReadWrite);

    if ( m_portSerie.isOpen() )
        std::cout << "port com ouvert" << std::endl;
    else
        std::cout << "ERREUR : port com non ouvert" << std::endl;
}



/** --------------------------------------------------------------------------------------
 * \brief Destructeur de la classe AfficheurInterface.
 */
Afficheur::~Afficheur()
{
    if( m_portSerie.isOpen() )
        m_portSerie.close();
}

/** --------------------------------------------------------------------------------------
 * \brief Teste si la connexion est correctement établie.
 * \return \b True si la connexion est établie, \b False sinon.
 */
bool Afficheur::connexionEtablie() const
{
    return m_portSerie.isOpen() && m_portSerie.isWritable();
}

/** --------------------------------------------------------------------------------------
 * \brief Envoie un message à l'afficheur.
 * \param m Une référence constance sur le message à envoyer.
 */
void Afficheur::envoyerMessage( std::string s)
{
   // MessageClient m1(s.numero(),"AFFICHER");
    //m1.setParametre(0, "hé hé !!!");

    if ( connexionEtablie() )
    {
        std::string startOfTrame = "<ID01>";
        std::string startOfMessage = "<L1><PA><FE><MA><WD><FE>";
        std::string mess = startOfMessage + "<C" + m_couleur + ">" + s;


        int checkSum = calculerChecksum(mess.c_str());
        std::string endOfTrame = "<E>";

        std::stringstream hx;
        std::stringstream hh;
        hx << std::uppercase << std::hex << checkSum; // int decimal_value
        if (checkSum < 16)
            hh << "0";
        hh << hx.str();
        std::string res(hh.str());
        res += "\0";

        std::string data = startOfTrame + mess + res + endOfTrame;

        m_portSerie.write(data.c_str(), data.length());
        m_portSerie.flush();
        std::cout << "envoi de data=" << data.c_str() << std::endl;

        m_portSerie.waitForReadyRead(3000);
        QByteArray retour_data = m_portSerie.readAll();
        std::cout << "retour_data=" << retour_data.toStdString() << std::endl;
    }
    else
        std::cout << "connexion non etablie" << std::endl;
}


/** --------------------------------------------------------------------------------------
 * \brief Calcul du checksum d'une trame donnée. Le checksum est un simple xor.
 * \param trame La trame dont il faut calculer le checksum.
 * \return L'entier checksum calculé.
 */
int Afficheur::calculerChecksum(const char* trame) const
{
    unsigned char c, checksum=0;
    int i=0;

    while ((c=trame[ i ])!=0)
    {
        checksum^=c;
        i++;
    }

    return checksum;
}
