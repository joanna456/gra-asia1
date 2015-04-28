//---------------------------------------------------------------------------


#pragma hdrstop

#include "ManagerGry.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
SekwencjaLosowa * Sekwencja;
StatystykiGry * Statystyki;
DaneGrafikiPlanszy DaneGrafiki;
TImage ** KontrolkiGrafiki;
bool GraRozpoczeta;
bool SprawdzanieSekwencji;
bool TrwaOdliczanieDoStartu;
TLabel * PrzyciskKontroli;
TLabel * EtykietaPunktow;
TLabel * EtykietaPoziomu;

ManagerGry::ManagerGry(TLabel * przyciskKontroli, TLabel * etykietaPunktow, TLabel * etykietaPoziomu)
{
        Sekwencja = new SekwencjaLosowa(0,0,0);

        Statystyki = new StatystykiGry();
        Statystyki->Wyzeruj();

        EtykietaPunktow = etykietaPunktow;
        EtykietaPoziomu = etykietaPoziomu;

        DaneGrafiki.WczytajDaneGrafiki();
        KontrolkiGrafiki = new TImage*[DaneGrafiki.IloscZmiennychGrafik + 1];

        GraRozpoczeta = false;
        SprawdzanieSekwencji = false;
        PrzyciskKontroli = przyciskKontroli;
        przyciskKontroli->OnClick = ManagerGry::PrzyciskKontroliClick;
}

ManagerGry::~ManagerGry()
{
        for (int i = 0; i < DaneGrafiki.IloscZmiennychGrafik + 1; i++)
        {
                delete KontrolkiGrafiki[i];
        }
        delete [] KontrolkiGrafiki;
        delete Statystyki;
        delete Sekwencja;
}

void ManagerGry::WyswietlGrafike(TWinControl * komponentNadrzedny)
{
        KontrolkiGrafiki[0] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[0]);
        KontrolkiGrafiki[0]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[0]->Width = DaneGrafiki.GrafikaTla.Rozmiar.SzerokoscX;
        KontrolkiGrafiki[0]->Height = DaneGrafiki.GrafikaTla.Rozmiar.WysokoscY;
        KontrolkiGrafiki[0]->Left = DaneGrafiki.GrafikaTla.Pozycja.PunktX;
        KontrolkiGrafiki[0]->Top = DaneGrafiki.GrafikaTla.Pozycja.PunktY;
        KontrolkiGrafiki[0]->Transparent = true;
        KontrolkiGrafiki[0]->Picture->LoadFromFile(DaneGrafiki.GrafikaTla.SciezkaGrafiki);

        KontrolkiGrafiki[1] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[1]);
        KontrolkiGrafiki[1]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[1]->Name = "Obrazek1";
        KontrolkiGrafiki[1]->Width = DaneGrafiki.ZmienneElementyGrafiki[0].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[1]->Height = DaneGrafiki.ZmienneElementyGrafiki[0].Rozmiar.WysokoscY;
        KontrolkiGrafiki[1]->Left = DaneGrafiki.ZmienneElementyGrafiki[0].Pozycja.PunktX;
        KontrolkiGrafiki[1]->Top = DaneGrafiki.ZmienneElementyGrafiki[0].Pozycja.PunktY;
        KontrolkiGrafiki[1]->Transparent = true;
        KontrolkiGrafiki[1]->Cursor = crHandPoint;
        KontrolkiGrafiki[1]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[1]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[0].SciezkaGrafiki);

        KontrolkiGrafiki[2] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[2]);
        KontrolkiGrafiki[2]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[2]->Name = "Obrazek2";
        KontrolkiGrafiki[2]->Width = DaneGrafiki.ZmienneElementyGrafiki[1].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[2]->Height = DaneGrafiki.ZmienneElementyGrafiki[1].Rozmiar.WysokoscY;
        KontrolkiGrafiki[2]->Left = DaneGrafiki.ZmienneElementyGrafiki[1].Pozycja.PunktX;
        KontrolkiGrafiki[2]->Top = DaneGrafiki.ZmienneElementyGrafiki[1].Pozycja.PunktY;
        KontrolkiGrafiki[2]->Transparent = true;
        KontrolkiGrafiki[2]->Cursor = crHandPoint;
        KontrolkiGrafiki[2]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[2]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[1].SciezkaGrafiki);

        KontrolkiGrafiki[3]= new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[3]);
        KontrolkiGrafiki[3]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[3]->Name = "Obrazek3";
        KontrolkiGrafiki[3]->Width = DaneGrafiki.ZmienneElementyGrafiki[2].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[3]->Height = DaneGrafiki.ZmienneElementyGrafiki[2].Rozmiar.WysokoscY;
        KontrolkiGrafiki[3]->Left = DaneGrafiki.ZmienneElementyGrafiki[2].Pozycja.PunktX;
        KontrolkiGrafiki[3]->Top = DaneGrafiki.ZmienneElementyGrafiki[2].Pozycja.PunktY;
        KontrolkiGrafiki[3]->Transparent = true;
        KontrolkiGrafiki[3]->Cursor = crHandPoint;
        KontrolkiGrafiki[3]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[3]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[2].SciezkaGrafiki);

        KontrolkiGrafiki[4] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[4]);
        KontrolkiGrafiki[4]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[4]->Name = "Obrazek4";
        KontrolkiGrafiki[4]->Width = DaneGrafiki.ZmienneElementyGrafiki[3].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[4]->Height = DaneGrafiki.ZmienneElementyGrafiki[3].Rozmiar.WysokoscY;
        KontrolkiGrafiki[4]->Left = DaneGrafiki.ZmienneElementyGrafiki[3].Pozycja.PunktX;
        KontrolkiGrafiki[4]->Top = DaneGrafiki.ZmienneElementyGrafiki[3].Pozycja.PunktY;
        KontrolkiGrafiki[4]->Transparent = true;
        KontrolkiGrafiki[4]->Cursor = crHandPoint;        
        KontrolkiGrafiki[4]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[4]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[3].SciezkaGrafiki);

                KontrolkiGrafiki[5] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[5]);
        KontrolkiGrafiki[5]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[5]->Name = "Obrazek5";
        KontrolkiGrafiki[5]->Width = DaneGrafiki.ZmienneElementyGrafiki[4].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[5]->Height = DaneGrafiki.ZmienneElementyGrafiki[4].Rozmiar.WysokoscY;
        KontrolkiGrafiki[5]->Left = DaneGrafiki.ZmienneElementyGrafiki[4].Pozycja.PunktX;
        KontrolkiGrafiki[5]->Top = DaneGrafiki.ZmienneElementyGrafiki[4].Pozycja.PunktY;
        KontrolkiGrafiki[5]->Transparent = true;
        KontrolkiGrafiki[5]->Cursor = crHandPoint;
        KontrolkiGrafiki[5]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[5]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[4].SciezkaGrafiki);

                   KontrolkiGrafiki[6] = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(KontrolkiGrafiki[6]);
        KontrolkiGrafiki[6]->Parent = komponentNadrzedny;
        KontrolkiGrafiki[6]->Name = "Obrazek6";
        KontrolkiGrafiki[6]->Width = DaneGrafiki.ZmienneElementyGrafiki[5].Rozmiar.SzerokoscX;
        KontrolkiGrafiki[6]->Height = DaneGrafiki.ZmienneElementyGrafiki[5].Rozmiar.WysokoscY;
        KontrolkiGrafiki[6]->Left = DaneGrafiki.ZmienneElementyGrafiki[5].Pozycja.PunktX;
        KontrolkiGrafiki[6]->Top = DaneGrafiki.ZmienneElementyGrafiki[5].Pozycja.PunktY;
        KontrolkiGrafiki[6]->Transparent = true;
        KontrolkiGrafiki[6]->Cursor = crHandPoint;
        KontrolkiGrafiki[6]->OnMouseDown = ObrazekClick;
        KontrolkiGrafiki[6]->Picture->LoadFromFile(
                DaneGrafiki.ZmienneElementyGrafiki[5].SciezkaGrafiki);
}

void ManagerGry::WyczyscGrafike(TWinControl * komponentNadrzedny)
{
        for (int i = 0; i < DaneGrafiki.IloscZmiennychGrafik + 1; i++)
        {
                KontrolkiGrafiki[i]->Parent = NULL;
                komponentNadrzedny->RemoveComponent(KontrolkiGrafiki[i]);
        }
}

void _fastcall ManagerGry::ObrazekClick(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
        if (GraRozpoczeta == false && (
                SprawdzanieSekwencji == false || TrwaOdliczanieDoStartu == true))
                return;

        int kliknietyNumerObrazka = -1;
        TImage* img = dynamic_cast<TImage*> (Sender);
        if (img->Name == "Obrazek1")
        {
                kliknietyNumerObrazka = 1;
        }
        else if (img->Name == "Obrazek2")
        {
                kliknietyNumerObrazka = 2;
        }
        else if (img->Name == "Obrazek3")
        {
                kliknietyNumerObrazka = 3;
        }
        else if (img->Name == "Obrazek4")
        {
                kliknietyNumerObrazka = 4;
        }
         else if (img->Name == "Obrazek5")
        {
                kliknietyNumerObrazka = 5;
        }
          else if (img->Name == "Obrazek6")
        {
                kliknietyNumerObrazka = 6;
        }
        PodmienObrazek(kliknietyNumerObrazka);
        Application->ProcessMessages();
        Sleep(100);
        PodmienObrazek(-1);
        Application->ProcessMessages();

        if (Sekwencja->CzyKolejnyElementZgodny(kliknietyNumerObrazka) == false)
        {
                PrzyciskKontroli->Caption = "Skucha! Rozpocznij od nowa!";
                Statystyki->Wyzeruj();

                GraRozpoczeta = false;
                SprawdzanieSekwencji = false;
        }
        else if (Sekwencja->CzyKoniecSekwencjiPorownania() == true)
        {
                GraRozpoczeta = false;
                SprawdzanieSekwencji = false;

                Statystyki->DodajPunkty(Sekwencja->PobierzRozmiarSekwencji());                
                WyswietlStatystyke();

                PrzyciskKontroli->Caption = "Brawo! Sekwencja zapamiêtana poprawnie!";
                Application->ProcessMessages();
                Sleep(1000);

                RozpocznijKolejnyPoziom();
        }
        else
        {
                Statystyki->DodajPunkty(Sekwencja->PobierzRozmiarSekwencji());
                WyswietlStatystyke();
        }

}

void __fastcall ManagerGry::PrzyciskKontroliClick(TObject *Sender)
{
        RozpocznijKolejnyPoziom();
}

void ManagerGry::RozpocznijKolejnyPoziom()
{
        if (GraRozpoczeta == false && TrwaOdliczanieDoStartu == false)
        {
                TrwaOdliczanieDoStartu = true;

                Statystyki->ZwiekszPoziom();
                WyswietlStatystyke();                
                int numerPoziomu = Statystyki->Poziom;

                int sekundDoRozpoczecia = 3;
                for(int sekunda = sekundDoRozpoczecia; sekunda > 0; sekunda--)
                {
                        PrzyciskKontroli->Caption = "Start " + IntToStr(numerPoziomu) + " rundy za: " + IntToStr(sekunda);

                        Application->ProcessMessages();
                        Sleep(1000);
                }
                TrwaOdliczanieDoStartu = false;

                PrzyciskKontroli->Caption = "Zapamiêtaj sekwencjê";
                GenerujSekwencje();
                PrzyciskKontroli->Caption = "Potwórz zapamiêtan¹ sekwencjê";

                GraRozpoczeta = true;
                SprawdzanieSekwencji = true;
                return;
        }
}

void ManagerGry::WyswietlStatystyke()
{
        EtykietaPunktow->Caption = "Punkty: " + IntToStr(Statystyki->Punkty);
        EtykietaPoziomu->Caption = "Poziom: " + IntToStr(Statystyki->Poziom);
}

void ManagerGry::PodmienObrazek(int numerObrazka)
{
        for (int i = 1; i < DaneGrafiki.IloscZmiennychGrafik + 1; i++)
        {
                if (KontrolkiGrafiki[i]->Hint == ".")
                {
                        KontrolkiGrafiki[i]->Hint = "";                
                        KontrolkiGrafiki[i]->Picture->LoadFromFile(
                                DaneGrafiki.ZmienneElementyGrafiki[i-1].SciezkaGrafiki);
                }
        }
        if (numerObrazka != -1)
        {
                KontrolkiGrafiki[numerObrazka]->Hint = ".";
                KontrolkiGrafiki[numerObrazka]->Picture->LoadFromFile(
                        DaneGrafiki.ZmienneElementyGrafiki[numerObrazka-1].SciezkaAlternatywnejGrafiki);
        }
}

void ManagerGry::GenerujSekwencje()
{
        randomize();

        int rozmiarSekwencji = Statystyki->Poziom + 1;
        Sekwencja = new SekwencjaLosowa(rozmiarSekwencji, 1, 6);
        Sekwencja->WylosujElementy();

        int numerObrazka = -1;
        while ((numerObrazka = Sekwencja->PobierzNastepnyElement()) != -1)
        {
                PodmienObrazek(numerObrazka);
                Application->ProcessMessages();
                Sleep(500);                
        }
        PodmienObrazek(-1);
}

