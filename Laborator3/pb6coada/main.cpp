#include <iostream>

using namespace std;

struct nod
{
 int info;
 nod *next;
};

nod *prim = NULL;
nod *ultim = NULL;

nod * newNode(int data)
{
  nod* nodNou = new nod();
  nodNou -> info = data;
  nodNou -> next = NULL;
  return nodNou;
}

bool isempty(nod* prim)
{
    return prim == NULL;
}

void push(int a, nod* &prim, nod* &ultim)
{
    nod* nodnou=newNode(a);

    if (prim == NULL)
        prim = ultim = nodnou;
    else
        {
         ultim -> next = nodnou;
         ultim = nodnou;
        }
}

int pop(nod* &prim)
{
  if (isempty(prim))
    return 0;
  else
    {
     nod* temp = prim;
     prim = prim -> next;
     int varf_inf = temp -> info;
     delete temp;
     return varf_inf;
    }
}

int peek(nod* prim)
{
  if (isempty(prim))
        return 0;
  return prim -> info;
}

int cautare(int a, nod* prim)
{
  if (isempty(prim))
    {
     cout << "Coada este vida si nu se poate efectua cautarea" << endl;
     return -1;
    }
  int distanta = 0;
  while (prim != NULL)
    {
      if (prim -> info == a)
        return distanta;
      prim = prim -> next;
      distanta++;
    }
 return -1;
}

void afiseaza(nod* prim)
{
 if (isempty(prim))
    cout << "Coada este vida" << endl;
 else
    {
     cout << "Coada contine urmatoarele elemente :" << endl;
     while (prim != NULL)
        {
         cout << prim -> info <<endl;
         prim = prim -> next;
        }
    }
}

int main()
{
  string expr;
  cout << "Prin conventie 0 este un element de marcaj" << endl;
  cout << "Meniul contine urmatoarele operatii :" << endl;
  cout << "1. Adaugati un element in coada" << endl;
  cout << "2. Scoateti primul element din coada" << endl;
  cout << "3. Afisati primul element din coada" << endl;
  cout << "4. Verificati daca coada este vida" << endl;
  cout << "5. Verificati daca un element se afla in coada" << endl;
  cout << "6. Afisati coada" << endl;
  cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
  cin >> expr;
  while(expr != "stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {
     if(expr == "1")
        {
         int val;
         cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
         cin >> val;
         push(val,prim,ultim);
        }
     if(expr ==  "2")
        {int varf = pop(prim);
         if (varf != 0)
            cout << "Primul element din coada in urma operatiei pop este " << varf << endl;
         else
            cout << "Coada este vida" << endl;
        }
     if(expr == "3")
        {
         if (peek(prim) != 0)
            cout << "Primul element din coada in urma operatiei peek este " << peek(prim) << endl;
         else
            cout << "Coada este vida" << endl;
        }
     if(expr == "4")
        {
         if (isempty(prim))
            cout << "Coada este vida" << endl;
         else
            cout << "Coada nu este vida" << endl;
        }
     if(expr == "5")
        {
         int val;
         cout << "Dati valoarea elementului pe care doriti sa-l cautati ";
         cin >> val;
         int rez_caut = cautare(val, prim);
         if(rez_caut == -1)
            cout << "Elementul dat nu se afla in coada" << endl;
         else
            cout << "Elementul dat se afla in coada si este la distanta " << rez_caut << endl;
        }
     if(expr == "6")
        {
         afiseaza(prim);
        }
     cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
     cin >> expr;
    }
    return 0;
}
