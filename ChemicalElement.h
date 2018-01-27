#ifndef CHEMICALELEMENT_H
#define CHEMICALELEMENT_H

#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glut.h>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>

using namespace std;

class ChemicalElement
{
public:
    /** \brief
     * Konstruktor bez parametrów
     */
    ChemicalElement();

    /** \brief
     * Konstruktor tworzący pierwiastek według podanego rekordu
     * \param number numer rekordu w pliku
     *
     */
    ChemicalElement(int number);

    /** \brief
     * Destruktor
     */
    virtual ~ChemicalElement();

    /** \brief
     * Metoda odpowiedzialna za rysowanie elektronów
     *\param electronMovementAngle Odpowiedzialny za ruch elektronów
     *\param &electrons Odpowiedzialny za listę elektronów
     */
    void drawElectrons(GLuint &electrons, GLfloat electronMovementAngle);

    /** \brief
     * Metoda wywołująca rysowanie protonów i neutronów
     *
     * \param &protonsAndNeutrons Odpowiedzialny za listę elektronów
     *
     */
    void drawProtonsAndNeutrons(GLuint &protonsAndNeutrons);

    /** \brief
     * Metoda pomocnicza, zarządzająca rysowaniem protonów i neutronów
     *
     */
    void drawByRings(void);

    /** \brief
     * Metoda pomocnicza rysująca "pierścień" składający się z protonów i neutronów
     * \param number wartość tablicy pomocniczej służącej do obliczenia pozycji na osi X
     * \param index indeks tablicy pomocniczej służącej do obliczenia pozycji na osi Y
     * \param nucleons liczba pozostałych do narysowania nukleonów (protony+neutrony)
     * \param colorTab tablica przechowująca wylosowane wartości służące do narysowania sfery w odpowiednim kolorze
     * \return liczba narysowanych nukleonów
     *
     */
    int drawRing(int number, int index, int nucleons, int colorTab[]);

    /** \brief
     * Metoda losująca wartości odpowiedzialnych za kolory nukleonów
     * \param tab tablica przechowująca wartości, służące do określenia kolorów nukleonów,
     *
     */
    void drawColors(int tab[]);

    /** \brief
     *Wyświetlenie na ekranie infomacji na temat danego pierwiastka
     */
    void showInformationsAboutElement(GLuint &informationsAboutElements);
    int getProtons() const;
    void setProtons(int protons);
    int getNeutrons() const;
    void setNeutrons(int neutrons);
    int getK() const;
    void setK(int k);
    int getL() const;
    void setL(int l);
    int getM() const;
    void setM(int m);
    int getN() const;
    void setN(int n);
    int getO() const;
    void setO(int o);
    int getP() const;
    void setP(int p);
    int getQ() const;
    void setQ(int q);
    int getMass() const;
    void setMass(int mass);
    int getPeriod() const;
    void setPeriod(int period);
    const string &getGroup() const;
    void setGroup(const string &symbol);
    const string &getSymbol() const;
    void setSymbol(const string &symbol);
    const string &getName() const;
    void setName(const string &name);

protected:

private:
    ///liczba protonów
    int protons;
    ///liczba neutronów
    int neutrons;
    ///liczba elektronów na powłoce K
    int k;
    ///liczba elektronów na powłoce L
    int l;
    ///liczba elektronów na powłoce M
    int m;
    ///liczba elektronów na powłoce N
    int n;
    ///liczba elektronów na powłoce O
    int o;
    ///liczba elektronów na powłoce P
    int p;
    ///liczba elektronów na powłoce Q
    int q;
    ///masa atomowa
    int mass;
    ///liczba powłok
    int period;
    ///numer/nazwa grupy
    string group;
    ///symbol pierwiastka
    string symbol;
    ///nazwa pierwiastka
    string name;
};

#endif // CHEMICALELEMENT_H
