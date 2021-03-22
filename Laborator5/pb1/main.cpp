#include <iostream>

using namespace std;

struct nod
{
 int info, inalt;
 nod *st, *dr;
};

int maxim(int a, int b)
{
 return (a > b) ? a : b;
}

int inaltime(nod *p)
{
 if (p == NULL)
    return 0;
 return p->inalt;
}

nod *nou(int cheie)
{
 nod *nodnou = new nod();
 nodnou -> info = cheie;
 nodnou -> st = NULL;
 nodnou -> dr = NULL;
 nodnou -> inalt = 1;
 return nodnou;
}

nod *rotatiedreapta(nod *p)
{
 nod *x = p -> st;
 nod *t2 = x -> dr;
 x -> dr = p;
 p -> st = t2;
 p -> inalt = maxim(inaltime(p -> st), inaltime(p -> dr)) + 1;
 x -> inalt = maxim(inaltime(x -> st), inaltime(x -> dr)) + 1;
 return x;
}

nod *rotatiestanga(nod *p)
{
 nod *x = p -> dr;
 nod *t2 = x -> st;
 x -> st = p;
 p -> dr = t2;
 p -> inalt = maxim(inaltime(p -> st),inaltime(p -> dr)) + 1;
 x -> inalt = maxim(inaltime(x -> st),inaltime(x -> dr)) + 1;
 return x;
}

int echilibrare(nod *p)
{
 if (p == NULL)
    return 0;
 return inaltime(p -> st) - inaltime(p -> dr);
}

nod *add(nod *p, int cheie)
{
 if (p == NULL)
    return (nou(cheie));
 if (cheie < p -> info)
    p -> st = add(p -> st, cheie);
 else
    {
     if (cheie > p -> info)
        p -> dr = add(p -> dr, cheie);
     else
        {
         cout << "Nu se pot introduce chei egale!";
         return p;
        }
    }
 p -> inalt = 1 + maxim(inaltime(p -> st), inaltime(p -> dr));
 int echilibru = echilibrare(p);
 if (echilibru > 1 && cheie < p -> st -> info)
    return rotatiedreapta(p);
 if (echilibru < -1 && cheie > p -> dr -> info)
    return rotatiestanga(p);
 if (echilibru > 1 && cheie > p -> st -> info)
    {
     p -> st = rotatiestanga(p -> st);
     return rotatiedreapta(p);
    }
 if (echilibru < -1 && cheie < p -> dr -> info)
    {
     p -> dr = rotatiedreapta(p -> dr);
     return rotatiestanga(p);
    }
 return p;
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

int main()
{nod *np = NULL;
 int first;
 cout << "Dati primul element: ";
 cin >> first;
 while (1)
    {
      string opt;
      np = add(np, first);
      cout << "\nMai introduceti elemente?";//da sau nu
      cin >> opt;
      if (opt == "da")
        {
         cout << "Dati elementul din arbore: ";
         cin >> first;
        }
      else
        break;
    }
  cout << "Arborele AVL in preordine: ";
  RSD(np);
  cout << endl << "Arborele AVL in inordine: ";
  SRD(np);

    return 0;
}
