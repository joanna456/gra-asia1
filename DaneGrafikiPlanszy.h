//---------------------------------------------------------------------------

#ifndef DaneGrafikiPlanszyH
#define DaneGrafikiPlanszyH
#include "RozmiarGrafiki.h"
#include "PozycjaGrafiki.h"
#include "ElementGrafiki.h"
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
#include <vcl.h>
//---------------------------------------------------------------------------
class DaneGrafikiPlanszy {
public:

        ElementGrafiki GrafikaTla;
        ElementGrafiki * ZmienneElementyGrafiki;

        DaneGrafikiPlanszy();
        ~DaneGrafikiPlanszy();

        int IloscZmiennychGrafik;
        void WczytajDaneGrafiki();
        void WczytajDaneGrafikiTla();
        void WczytajDaneZmiennychGrafik();
        ElementGrafiki PobierzElementGrafiki(int id);
};
#endif
