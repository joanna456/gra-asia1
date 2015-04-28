//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ManagerGrafiki.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

ManagerGrafiki::ManagerGrafiki()
{
        IloscZmiennychGrafik = 0;
}

void ManagerGrafiki::WczytajDaneGrafikiTla()
{
        AnsiString sciezkaGrafiki = "images/tlo.jpg";
        grafikaTla =  ElementGrafiki(-1, 1000, 507, 0,0,sciezkaGrafiki);
}

void ManagerGrafiki::WczytajDaneZmiennychGrafik()
{
        IloscZmiennychGrafik = 6;
        
        zmienneElementyGrafiki
                = new ElementGrafiki[IloscZmiennychGrafik];

        AnsiString sciezkaGrafiki1 = "images/p1a.bmp";
        zmienneElementyGrafiki[0] = ElementGrafiki(1,
                146, 260,
                56, 204,
                sciezkaGrafiki1);

        AnsiString sciezkaGrafiki2 = "images/p2a.bmp";
        zmienneElementyGrafiki[1] = ElementGrafiki(2,
                165, 130,
                303, 127,
                sciezkaGrafiki2);

        AnsiString sciezkaGrafiki3 = "images/p3a.bmp";
        zmienneElementyGrafiki[2] = ElementGrafiki(3,
                143, 140,
                550, 127,
                sciezkaGrafiki3);

        AnsiString sciezkaGrafiki4 = "images/p4a.bmp";
        zmienneElementyGrafiki[3] = ElementGrafiki(4,
                117, 210,
                804, 223,
                sciezkaGrafiki4);


        AnsiString sciezkaGrafiki5 = "images/proba1a.bmp";
        ZmienneElementyGrafiki[4] = ElementGrafiki(5,
                76, 76,
                303, 130,
                sciezkaGrafiki5);

        AnsiString sciezkaGrafiki6 = "images/proba2a.bmp";
        ZmienneElementyGrafiki[5] = ElementGrafiki(6,
                76, 76,
                493, 130,
                sciezkaGrafiki6);
}

void ManagerGrafiki::WczytajDaneGrafiki()
{
        ManagerGrafiki::WczytajDaneGrafikiTla();
        WczytajDaneZmiennychGrafik();
}

void ManagerGrafiki::WyswietlGrafike(TWinControl * komponentNadrzedny)
{
        TImage* tloImage = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(tloImage);
        tloImage->Parent = komponentNadrzedny;
        tloImage->Width = grafikaTla.Rozmiar.SzerokoscX;
        tloImage->Height = grafikaTla.Rozmiar.WysokoscY;
        tloImage->Left = grafikaTla.Pozycja.PunktX;
        tloImage->Top = grafikaTla.Pozycja.PunktY;
        tloImage->Transparent = true;
        tloImage->Picture->LoadFromFile(grafikaTla.SciezkaGrafiki);

        TImage* elementImage1 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage1);
        elementImage1->Parent = komponentNadrzedny;
        elementImage1->Width = zmienneElementyGrafiki[0].Rozmiar.SzerokoscX;
        elementImage1->Height = zmienneElementyGrafiki[0].Rozmiar.WysokoscY;
        elementImage1->Left = zmienneElementyGrafiki[0].Pozycja.PunktX;
        elementImage1->Top = zmienneElementyGrafiki[0].Pozycja.PunktY;
        elementImage1->Transparent = true;
        elementImage1->Picture->LoadFromFile(
                zmienneElementyGrafiki[0].SciezkaGrafiki);

        TImage* elementImage2 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage2);
        elementImage2->Parent = komponentNadrzedny;
        elementImage2->Width = zmienneElementyGrafiki[1].Rozmiar.SzerokoscX;
        elementImage2->Height = zmienneElementyGrafiki[1].Rozmiar.WysokoscY;
        elementImage2->Left = zmienneElementyGrafiki[1].Pozycja.PunktX;
        elementImage2->Top = zmienneElementyGrafiki[1].Pozycja.PunktY;
        elementImage2->Transparent = true;
        elementImage2->Picture->LoadFromFile(
                zmienneElementyGrafiki[1].SciezkaGrafiki);

        TImage* elementImage3 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage3);
        elementImage3->Parent = komponentNadrzedny;
        elementImage3->Width = zmienneElementyGrafiki[2].Rozmiar.SzerokoscX;
        elementImage3->Height = zmienneElementyGrafiki[2].Rozmiar.WysokoscY;
        elementImage3->Left = zmienneElementyGrafiki[2].Pozycja.PunktX;
        elementImage3->Top = zmienneElementyGrafiki[2].Pozycja.PunktY;
        elementImage3->Transparent = true;
        elementImage3->Picture->LoadFromFile(
                zmienneElementyGrafiki[2].SciezkaGrafiki);

        TImage* elementImage4 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage4);
        elementImage4->Parent = komponentNadrzedny;
        elementImage4->Width = zmienneElementyGrafiki[3].Rozmiar.SzerokoscX;
        elementImage4->Height = zmienneElementyGrafiki[3].Rozmiar.WysokoscY;
        elementImage4->Left = zmienneElementyGrafiki[3].Pozycja.PunktX;
        elementImage4->Top = zmienneElementyGrafiki[3].Pozycja.PunktY;
        elementImage4->Transparent = true;
        elementImage4->Picture->LoadFromFile(
                zmienneElementyGrafiki[3].SciezkaGrafiki);
                
        TImage* elementImage5 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage5);
        elementImage5->Parent = komponentNadrzedny;
        elementImage5->Width = zmienneElementyGrafiki[4].Rozmiar.SzerokoscX;
        elementImage5->Height = zmienneElementyGrafiki[4].Rozmiar.WysokoscY;
        elementImage5->Left = zmienneElementyGrafiki[4].Pozycja.PunktX;
        elementImage5->Top = zmienneElementyGrafiki[4].Pozycja.PunktY;
        elementImage5->Transparent = true;
        elementImage5->Picture->LoadFromFile(
                zmienneElementyGrafiki[4].SciezkaGrafiki);


                  TImage* elementImage6 = new TImage(komponentNadrzedny);
        komponentNadrzedny->InsertComponent(elementImage6);
        elementImage6->Parent = komponentNadrzedny;
        elementImage6->Width = zmienneElementyGrafiki[5].Rozmiar.SzerokoscX;
        elementImage6->Height = zmienneElementyGrafiki[5].Rozmiar.WysokoscY;
        elementImage6->Left = zmienneElementyGrafiki[5].Pozycja.PunktX;
        elementImage6->Top = zmienneElementyGrafiki[5].Pozycja.PunktY;
        elementImage6->Transparent = true;
        elementImage6->Picture->LoadFromFile(
                zmienneElementyGrafiki[5].SciezkaGrafiki);


}

void ManagerGrafiki::ZmienObrazek(int numerObrazka)
{

}

void ManagerGrafiki::PrzywrocOryginalnyObrazek(int numerObrazka)
{

}


