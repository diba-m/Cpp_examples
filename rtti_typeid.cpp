//RTTI(Run Time Type Identification) example
#include <typeinfo>   //includere questo header per le operazioni RTTI
#include <iostream>

using std::cout;    //using only the name 'cout' from 'std' namespace
using std::endl;    //using only the name 'endl' from 'std' namespace

class A{
    public:
        virtual ~A(){}     //distruttore virtuale --> modo 'minimale' per rendere polimorfa una classe
};

class B: public A{
};



int main(){
        //proviamo ad usare l'operatore 'typeid' su diversi tipi, polimorfi e non
        int a = 0;
        cout << "codice per il tipo della variabile intera 'a': " << typeid(a).name() << endl;   //typeid(var).name dà il nome di un tipo come stringa

        //########typeid SU PUNTATORI
        int * b = &a;
        cout << "codice per il tipo del puntatore ad intero 'b': " << typeid(b).name() << endl;
        cout << "codice per il tipo dell'oggetto puntato da 'b': " << typeid(*b).name() << endl;


        //#######typeid SU PUNTATORE A CLASSE POLIMORFA
        A* aPtr = new B;
        /*NB1: typeid chiamato su un puntatore non dereferenziato, anche se polimorfo,
              restituisce TS del puntatore*/
        cout << "tipo(statico) del puntatore 'aPtr': " << typeid(aPtr).name() << endl;
        /*NB2: typeid chiamato su un puntatore polimorfo dereferenziato restituisce il TD del puntatore
        */
        cout << "tipo(dinamico) del puntatore 'aPtr': " << typeid(*aPtr).name() << endl;


        //#######typeid su RIFERIMENTO A CLASSE POLIMORFA
        B bObj;
        A& aRef = bObj;
        cout << "tipo(dinamico) del riferimento 'aRef': " << typeid(aRef).name() << endl;

}

