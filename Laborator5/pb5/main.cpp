#include <iostream>
#include <string.h>
using namespace std;

struct nod
{
 char info[100];
 nod *st, *dr;
};

nod *t, *aux;

void inserare(nod *&t, char x[100])
{
 if (t != NULL)
    {
     if (strcmp(x, t -> info) < 0)
        inserare (t -> st, x);
     else
        {
         if (strcmp(x, t -> info) > 0)
            inserare (t -> dr, x);
         else
            cout << "Nodul a fost inserat. Inserati alt nod!" << endl;
        }
    }
 else
    {
     t = new nod;
     strcpy(t -> info,x);
     t -> st = NULL;
     t -> dr = NULL;
    }
}

char* cautare(nod *t, char x[100])
{
 if (t == NULL)
    {
        cout << "Arborele nu are elemente" << endl;
        return "nu";
    }
 else
    {
     if (strcmp(x, t -> info) == 0)
        return "da";
     else
        {
         if (strcmp(x, t -> info) < 0)
            return cautare(t -> st, x);
         else
           {
            if (strcmp(x, t -> info) > 0)
               return cautare(t -> dr, x);
           }
        }
    }
 return "nu";
}

char* findMax(nod *t)
{
 if (t == NULL)
    {
        cout << "Arborele nu are elemente" << endl;
        return "nu";
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
     strcpy(c -> info, f -> info);
     aux = f;
     f = f -> dr;
     delete aux;
    }
}

void stergere(nod *&t, char x[100])
{
 nod *f;
 if (t)
    {
     if (strcmp(t->info, x) == 0)
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
         if (strcmp(t -> info, x) < 0)
            stergere(t -> dr, x);
         else
            stergere(t -> st, x);
        }
    }
 else
    cout << "Stergerea nu se poate efectua deoarece avem un arbore vid" << endl;
}

void sortare(nod *t)
{
 if (t != NULL)
    {
     sortare(t -> dr);
     cout << t -> info << " ";
     sortare(t -> st);
    }
}

int main()
{ int opt;
  char x[100];
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
     cout << "8. Sortare sir de cuvinte descrescator" << endl;
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
             char gasit[10];
             strcpy(gasit, cautare(t,x));
             if (gasit == "da")
                cout << "Nodul cu informatia data a fost gasit in arbore" << endl;
             else
                cout << "Nodul cu informatia data nu a fost gasit in arbore" << endl;
             break;
            }
         case 3:
            {
             char maxim[100];
             strcpy(maxim, findMax(t));
             if (maxim != "nu")
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
         case 8:
            {
             cout << "Afisare in ordine descrescatoare" << endl;
             sortare(t);
            }
        }
    }
  while(opt!=8);
     return 0;
}
