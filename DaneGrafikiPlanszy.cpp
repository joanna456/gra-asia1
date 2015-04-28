//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "DaneGrafikiPlanszy.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------



DaneGrafikiPlanszy::DaneGrafikiPlanszy()
{
        IloscZmiennychGrafik = 0;
}

DaneGrafikiPlanszy::~DaneGrafikiPlanszy()
{
        delete [] ZmienneElementyGrafiki;
}

void DaneGrafikiPlanszy::WczytajDaneGrafikiTla()
{
        AnsiString sciezkaGrafiki = "images/tlo.jpg";
        GrafikaTla = ElementGrafiki(-1, 1000, 507, 0, 0, sciezkaGrafiki, "");
}

void DaneGrafikiPlanszy::WczytajDaneZmiennychGrafik()
{
        IloscZmiennychGrafik = 6;
        
        ZmienneElementyGrafiki
                = new ElementGrafiki[IloscZmiennychGrafik];

        AnsiString sciezkaGrafiki1 = "images/p1.bmp";
        AnsiString sciezkaAlternatywnejGrafiki1 = "images/p1a.bmp";
        ZmienneElementyGrafiki[0] = ElementGrafiki(1,
                146, 260,
                56, 204,
                sciezkaGrafiki1,
                sciezkaAlternatywnejGrafiki1);

        AnsiString sciezkaGrafiki2 = "images/p2.bmp";
        AnsiString sciezkaAlternatywnejGrafiki2 = "images/p2a.bmp";
        ZmienneElementyGrafiki[1] = ElementGrafiki(2,
                165, 130,
                303, 150,
                sciezkaGrafiki2,
                sciezkaAlternatywnejGrafiki2);

        AnsiString sciezkaGrafiki3 = "images/p3.bmp";
        AnsiString sciezkaAlternatywnejGrafiki3 = "images/p3a.bmp";
        ZmienneElementyGrafiki[2] = ElementGrafiki(3,
                143, 140,
                550, 127,
                sciezkaGrafiki3,
                sciezkaAlternatywnejGrafiki3);

        AnsiString sciezkaGrafiki4 = "images/p4.bmp";
        AnsiString sciezkaAlternatywnejGrafiki4 = "images/p4a.bmp";
        ZmienneElementyGrafiki[3] = ElementGrafiki(4,
                117, 210,
                804, 223,
                sciezkaGrafiki4,
                sciezkaAlternatywnejGrafiki4);




                 AnsiString sciezkaGrafiki5 = "images/proba1.bmp";
        AnsiString sciezkaAlternatywnejGrafiki5 = "images/proba1a.bmp";
        ZmienneElementyGrafiki[4] = ElementGrafiki(5,
                76, 76,
                303, 130,
                sciezkaGrafiki5,
                sciezkaAlternatywnejGrafiki5);

                    AnsiString sciezkaGrafiki6 = "images/proba2.bmp";
        AnsiString sciezkaAlternatywnejGrafiki6 = "images/proba2a.bmp";
        ZmienneElementyGrafiki[5] = ElementGrafiki(6,
                76, 76,
                493, 130,
                sciezkaGrafiki6,
                sciezkaAlternatywnejGrafiki6);
}

void DaneGrafikiPlanszy::WczytajDaneGrafiki()
{
      WczytajDaneGrafikiTla();
      WczytajDaneZmiennychGrafik();
}

ElementGrafiki DaneGrafikiPlanszy::PobierzElementGrafiki(int id)
{
        for (int i = 0; i < IloscZmiennychGrafik; i++)
        {
                if (ZmienneElementyGrafiki[i].Id == id)
                {
                        return ZmienneElementyGrafiki[i];
                }
        }
        return ZmienneElementyGrafiki[0];
}
