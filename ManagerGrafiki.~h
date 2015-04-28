//---------------------------------------------------------------------------

#ifndef ManagerGrafikiH
#define ManagerGrafikiH
#include "RozmiarGrafiki.h"
#include "PozycjaGrafiki.h"
#include "ElementGrafiki.h"
#include "Unit1.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <vcl.h>
//---------------------------------------------------------------------------
class ManagerGrafiki {
private:
        ElementGrafiki grafikaTla;
        ElementGrafiki * zmienneElementyGrafiki;

public:
        ManagerGrafiki();

        int IloscZmiennychGrafik;

        void WczytajDaneGrafikiTla();
        void WczytajDaneZmiennychGrafik();

        void WczytajDaneGrafiki();
        void WyswietlGrafike(TWinControl * komponentNadrzedny);

        void ZmienObrazek(int numerObrazka);
        void PrzywrocOryginalnyObrazek(int numerObrazka);
};
#endif
