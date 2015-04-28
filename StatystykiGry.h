//---------------------------------------------------------------------------

#ifndef StatystykiGryH
#define StatystykiGryH
//---------------------------------------------------------------------------

class StatystykiGry {

public:
        int Poziom;
        int Punkty;

        StatystykiGry();
        void ZwiekszPoziom();
        void DodajPunkty(int rozmiarSekwencji);
        void Wyzeruj();
};
#endif
