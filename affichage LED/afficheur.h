#ifndef AFFICHEUR_H
#define AFFICHEUR_H
#include <QtSerialPort/QSerialPort>

class Afficheur
{
public:
    Afficheur();
    ~Afficheur();

    void envoyerMessage( std::string s);


private:
    int calculerChecksum(const char* trame) const;
    bool connexionEtablie() const;

private:
    /** \brief Le port série. */
    QSerialPort m_portSerie;

    /** \brief La couleur actuelle de l'affichage. */
    char m_couleur;
};

#endif // AFFICHEUR_H
