//---------------------------------------------------------------------------


#pragma hdrstop

#include "ElementGrafiki.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

ElementGrafiki::ElementGrafiki()
{

}

ElementGrafiki::ElementGrafiki(int id,
        int szerokoscX, int wysokoscY,
        int pozycjaX, int pozycjaY,
        AnsiString sciezkaGrafiki,
        AnsiString sciezkaAlternatywnejGrafiki)
{
        Id = id;
        Rozmiar = RozmiarGrafiki(szerokoscX, wysokoscY);
        Pozycja = PozycjaGrafiki(pozycjaX, pozycjaY);
        SciezkaGrafiki = sciezkaGrafiki;
        SciezkaAlternatywnejGrafiki = sciezkaAlternatywnejGrafiki;
}


