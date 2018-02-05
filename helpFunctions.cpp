#include <string>
using namespace std;

/** \brief
 *  Wypełnia tablicę 0
 * \param tab Tablica
 * \param numberOfElements Liczba elementów tablicy
 *
 */
void fillZeroTab(int* tab, int numberOfElements)
{
    for(int i=0; i<numberOfElements; i++){
        tab[i]=0;
    }
}

/** \brief
 *
 * Konwertuje liczbę int do napisu string
 * \param n liczba
 * \return napis
 *
 */
string intToStr(int n)
{
    string tmp, ret;
    do
    {
        tmp += n % 10 + 48;
        n -= n % 10;
    }
    while(n /= 10);
    for(int i = tmp.size()-1; i >= 0; i--)
        ret += tmp[i];
    return ret;
}
