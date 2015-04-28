//---------------------------------------------------------------------------

#pragma hdrstop

#include "SekwencjaLosowa.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

SekwencjaLosowa::SekwencjaLosowa(int rozmiar, int nrElementuOd, int nrElementuDo)
{
        sekwencjaZainicjowana = false;
        ZmienParametrySekwencji(rozmiar, nrElementuOd, nrElementuDo);
        sekwencjaZainicjowana = true;
}

SekwencjaLosowa::~SekwencjaLosowa()
{
        if (sekwencjaZainicjowana == true)
                delete [] elementySekwencji;
}

void SekwencjaLosowa::ZmienParametrySekwencji(int rozmiar, int nrElementuOd, int nrElementuDo)
{
        if (sekwencjaZainicjowana == true)
                delete [] elementySekwencji;

        numerElementuOd = nrElementuOd;
        numerElementuDo = nrElementuDo;

        elementySekwencji = new int[rozmiar];
        rozmiarSekwencji = rozmiar;

        indeksElementuDoPobrania = -1;
        indeksSprawdzeniaZgodnosci = -1;
}

void SekwencjaLosowa::WylosujElementy()
{
        randomize();
        int ostatnioWylosowanyNumer = -1;
        for(int i=0; i< rozmiarSekwencji; i++)
        {
                int wylosowanyNumer = random(numerElementuDo) + numerElementuOd;
                if (ostatnioWylosowanyNumer == wylosowanyNumer)
                {
                        i--;
                        continue;
                }
                ostatnioWylosowanyNumer = wylosowanyNumer;
                elementySekwencji[i] = wylosowanyNumer;
        }
}

int SekwencjaLosowa::PobierzNastepnyElement()
{
        if (indeksElementuDoPobrania + 1 >= rozmiarSekwencji)
                return -1;

        indeksElementuDoPobrania += 1;
        return elementySekwencji[indeksElementuDoPobrania];
}

void SekwencjaLosowa::ResetujPobieranie()
{
        indeksElementuDoPobrania = -1;
}

int SekwencjaLosowa::PobierzRozmiarSekwencji()
{
        return rozmiarSekwencji;
}

bool SekwencjaLosowa::CzyKolejnyElementZgodny(int elementDoSprawdzenia)
{
        indeksSprawdzeniaZgodnosci++;
        return (elementySekwencji[indeksSprawdzeniaZgodnosci] == elementDoSprawdzenia);
}

void SekwencjaLosowa::ResetujPorownywanieZgodnosci()
{
        indeksSprawdzeniaZgodnosci = -1;
}

bool SekwencjaLosowa::CzyKoniecSekwencjiPorownania()
{
        return (rozmiarSekwencji - 1 == indeksSprawdzeniaZgodnosci);
}
