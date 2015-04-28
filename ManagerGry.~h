//---------------------------------------------------------------------------

#ifndef ManagerGryH
#define ManagerGryH
#include "SekwencjaLosowa.h"
#include "StatystykiGry.h"
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
class ManagerGry {
public:
        ManagerGry(TLabel * przyciskKontroli, TLabel * etykietaPunktow, TLabel * etykietaPoziomu);
        ~ManagerGry();        

        void WyswietlGrafike(TWinControl * komponentNadrzedny);
        void WyczyscGrafike(TWinControl * komponentNadrzedny);
        void PodmienObrazek(int numerObrazka);
        void GenerujSekwencje();
        void RozpocznijKolejnyPoziom();
        void WyswietlStatystyke();        

        void _fastcall ObrazekClick(TObject *Sender, TMouseButton Button,
              TShiftState Shift, int X, int Y);

        void __fastcall PrzyciskKontroliClick(TObject *Sender);              
};
#endif

