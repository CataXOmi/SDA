#include <iostream>

using namespace std;

struct nod
{
 int info;
 nod *st, *dr;
};

nod *t, *aux;

void inserare(nod *&t, int x)
{
 if (t != NULL)
    {
     if (x < t -> info)
        inserare (t -> st, x);
     else
        {
         if (x > t -> info)
            inserare (t -> dr, x);
         else
            cout << "Nodul a fost inserat. Inserati alt nod!" << endl;
        }
    }
 else
    {
     t = new nod;
     t -> info = x;
     t -> st = NULL;
     t -> dr = NULL;
    }
}

int cautare(nod *t, int x)
{
 if (t == NULL)
    {
        cout << "Arborele nu are elemente" << endl;
        return 0;
    }
 else
    {
     if (x == t->info)
        return 1;
     else
        {
         if (x < t -> info)
            return cautare(t -> st, x);
         else
           {
            if (x > t -> info)
               return cautare(t -> dr, x);
           }
        }
    }
 return 0;
}

int findMax(nod *t)
{
 if (t == NULL)
    {
        cout << "Arborele nu are elemente" << endl;
        return 0;
    }
 else
    {
     if (t -> dr)
       return findMax(t -> dr);
     else
        return t->info;
    }
}

void RSD(nod *t)
{
 if (t != NULL)
    {
     cout <<  t -> info << " ";
     RSD(t -> st);
     RSD(t -> dr);
    }
}

void SRD(nod *t)
{
 if (t != NULL)
    {
     SRD(t -> st);
     cout << t -> info << " ";
     SRD(t -> dr);
    }
}

void SDR(nod *t)
{
 if (t != NULL)
    {
     SDR(t -> st);
     SDR(t -> dr);
     cout << t -> info << " ";
    }
}

void sterg2(nod *&c, nod *&f)
{
 if (f -> st)
    sterg2(c, f -> st);
 else
    {
     c -> info = f -> info;
     aux = f;
     f = f -> dr;
     delete aux;
    }
}

void stergere(nod *&t, int x)
{
 nod *f;
 if (t)
    {
     if (t -> info == x)
        if (t -> dr == NULL && t -> st == NULL) // nodul e frunza
                    {
                     delete t;
                     t = NULL;
                    }
        else
            {if (t -> dr == NULL) // nodul are un fiu pe st
                {
                 f = t -> st;
                 delete t;
                 t = f;
                }
             else
                {
                 if (t -> st == NULL) // nodul are un fiu pe dr
                    {
                     f = t -> dr;
                     delete t;
                     t = f;
                    }
                 else // nodul are 2 fii
                    sterg2(t, t->dr);
                }
            }
     else
        {
         if (t -> info < x)
            stergere(t -> dr, x);
         else
            stergere(t -> st, x);
        }
    }
 else
    cout << "Stergerea nu se poate efectua deoarece avem un arbore vid" << endl;
}

int main()
{ int opt,x;
  do
    {
     cout << endl;
     cout << "Meniul contine urmatoarele operatii :" << endl;
     cout << "1. Adaugati o cheie in arbore" << endl;
     cout << "2. Cautati un element in arbore" << endl;
     cout << "3. Gasiti maximul din arbore" << endl;
     cout << "4. Afisarea prin parcurgere in preordine" << endl;
     cout << "5. Afisarea prin parcurgere in inordine" << endl;
     cout << "6. Afisarea prin parcurgere in postordine" << endl;
     cout << "7. Stergeti un nod din arbore" << endl;
     cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
     cin >> opt;
     switch (opt)
        {
         case 1:
            {
             cout << "Dati informatia nodului: ";
             cin >> x;
             inserare(t, x);
             break;
            }
         case 2:
            {
             cout << "Dati informatia nodului: ";
             cin >> x;
             int gasit = cautare(t, x);
             if (gasit == 1)
                cout << "Nodul cu informatia data a fost gasit in arbore" << endl;
             else
                cout << "Nodul cu informatia data nu a fost gasit in arbore" << endl;
             break;
            }
         case 3:
            {
             int maxim = findMax(t);
             if (maxim != 0)
                cout << "Elementul maxim din arbore este : " << maxim << endl;
             break;
            }
         case 4:
            {
             if (t)
                {
                    cout << "Afisarea prin parcurgere in preordine" << endl;
                    RSD(t);
                }
             else
                cout << "Arborele nu are elemente" << endl;
             break;
            }
         case 5:
            {
             if (t)
                {
                    cout << "Afisarea prin parcurgere in inordine" << endl;
                    SRD(t);
                }
             else
                cout << "Arborele nu are elemente" << endl;
             break;
            }
         case 6:
            {
             if (t)
                {
                    cout << "Afisarea prin parcurgere in postordine" << endl;
                    SDR(t);
                }
             else
                cout << "Arborele nu are elemente" << endl;
             break;
            }
         case 7:
            {
             cout << "Dati informatia nodului: ";
             cin >> x;
             stergere(t, x);
             break;
            }
        }
    }
  while(opt!=8);
     return 0;
}
