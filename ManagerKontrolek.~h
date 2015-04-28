//---------------------------------------------------------------------------

#ifndef ManagerKontrolekH
#define ManagerKontrolekH
#include "RozmiarGrafiki.h"
#include "PozycjaGrafiki.h"
#include "ElementGrafiki.h"
#include "DaneGrafikiPlanszy.h"
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
class ManagerKontrolek {
public:
        ManagerKontrolek();
        ~ManagerKontrolek();        

        void WyswietlGrafike(TWinControl * komponentNadrzedny);
        void WyczyscGrafike(TWinControl * komponentNadrzedny);
        void PodmienObrazek(int numerObrazka);
        void GenerujSekwencje();
        void _fastcall ObrazekClick(TObject *Sender, TMouseButton Button,
              TShiftState Shift, int X, int Y);
};
#endif
