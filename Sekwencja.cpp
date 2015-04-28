//---------------------------------------------------------------------------


#pragma hdrstop

#include "Sekwencja.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

Sekwencja::Sekwencja(int rozmiar)
{
        sekwencjaZainicjowana = false;
        ZmienRozmiar(rozmiar);
        sekwencjaZainicjowana = true;
}

Sekwencja::~Sekwencja()
{
        delete[] elementySekwencji;
}

bool Sekwencja::DodajElement(int element)
{
        if (indeksElementuDoDodania + 1 >= rozmiarSekwencji)
                return false;

        indeksElementuDoDodania += 1;
        elementySekwencji[indeksElementuDoDodania] = element;
        return true;
}

int Sekwencja::PobierzNastepnyElement()
{
        if (indeksElementuDoPobrania + 1 >= rozmiarSekwencji)
                return -1;

        indeksElementuDoPobrania += 1;
        return elementySekwencji[indeksElementuDoPobrania];
}

void Sekwencja::ResetujPobieranie()
{
        indeksElementuDoPobrania = -1;
}

void Sekwencja::ZmienRozmiar(int rozmiar)
{
        WyczyscSekwencje();

        elementySekwencji = new int[rozmiar];
        rozmiarSekwencji = rozmiar;
        indeksElementuDoDodania = -1;
        indeksElementuDoPobrania = -1;
}

void Sekwencja::WyczyscSekwencje()
{
        if (sekwencjaZainicjowana == true)
                delete[] elementySekwencji;
}

int Sekwencja::PobierzRozmiarSekwencji()
{
        return rozmiarSekwencji;
}
