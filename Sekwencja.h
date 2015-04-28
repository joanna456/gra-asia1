//---------------------------------------------------------------------------

#ifndef SekwencjaH
#define SekwencjaH
//---------------------------------------------------------------------------
class Sekwencja {
private:
        bool sekwencjaZainicjowana;
        int * elementySekwencji;
        int rozmiarSekwencji;
        int indeksElementuDoDodania;
        int indeksElementuDoPobrania;
public:
        Sekwencja(int rozmiarSekwencji);
        ~Sekwencja();
        bool DodajElement(int element);
        int PobierzNastepnyElement();
        void ResetujPobieranie();
        void WyczyscSekwencje();
        void ZmienRozmiar(int rozmiar);
        int PobierzRozmiarSekwencji();        

};
#endif
