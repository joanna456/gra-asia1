//---------------------------------------------------------------------------


#pragma hdrstop

#include "StatystykiGry.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

StatystykiGry::StatystykiGry()
{
        Poziom = 0;
        Punkty = 0;
}

void StatystykiGry::ZwiekszPoziom()
{
     Poziom++;
     if (Poziom != 1)
     {
        Punkty += (100 * Poziom);
     }
}

void StatystykiGry::DodajPunkty(int rozmiarSekwencji)
{
     Punkty += (10 * Poziom * rozmiarSekwencji);
}

void StatystykiGry::Wyzeruj()
{
        Poziom = 0;
        Punkty = 0;
}
