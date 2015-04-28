//---------------------------------------------------------------------------

#ifndef SekwencjaLosowaH
#define SekwencjaLosowaH
#include <vcl.h>
//---------------------------------------------------------------------------
class SekwencjaLosowa {
private:
        bool sekwencjaZainicjowana;

        int numerElementuOd;
        int numerElementuDo;

        int * elementySekwencji;
        int rozmiarSekwencji;
        int indeksElementuDoPobrania;
        int indeksSprawdzeniaZgodnosci;

public:
        SekwencjaLosowa(int rozmiar, int nrElementuOd, int nrElementuDo);
        ~SekwencjaLosowa();

        void ZmienParametrySekwencji(int rozmiar, int nrElementuOd, int nrElementuDo);
        void WylosujElementy();

        int PobierzNastepnyElement();
        void ResetujPobieranie();
        int PorownajKolejnyElement();
        void ResetujPorownywanie();
        int PobierzRozmiarSekwencji();

        bool CzyKolejnyElementZgodny(int elementDoSprawdzenia);
        void ResetujPorownywanieZgodnosci();
        bool CzyKoniecSekwencjiPorownania();
};
#endif
