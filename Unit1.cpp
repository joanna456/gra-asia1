//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
ManagerGry *Manager = NULL;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormActivate(TObject *Sender)
{
        Manager = new ManagerGry(PrzyciskKontroli, EtykietaPunktow, EtykietaPoziomu);
        Manager->WyswietlGrafike(Panel1);
        //Manager->GenerujSekwencje();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
        Manager->WyczyscGrafike(Panel1);
}
//---------------------------------------------------------------------------



//---------------------------------------------------------------------------

