//---------------------------------------------------------------------------


#pragma hdrstop

#include "RozmiarGrafiki.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
RozmiarGrafiki::RozmiarGrafiki()
{
        SzerokoscX = 0;
        WysokoscY = 0;
}

RozmiarGrafiki::RozmiarGrafiki(int szerokoscX, int wysokoscY)
{
        SzerokoscX = szerokoscX;
        WysokoscY = wysokoscY;
}

