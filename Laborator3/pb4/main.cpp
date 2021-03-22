#include <iostream>

using namespace std;

struct nod
{
  int info;
  nod* next;
};

nod* top = NULL;

nod * newNode(int data)
{
  nod* nodNou = new nod();
  nodNou -> info = data;
  nodNou -> next = NULL;
  return nodNou;
}

bool isempty(nod* top) // verifica daca stiva este vida sau nu
{
  return top == NULL;
}

void push(int a, nod* &top) // adauga elementul a in varful stivei
{
  nod* nodnou = newNode(a);
  if (top == NULL)
     top = nodnou;
  else
     {
         nodnou -> next = top;
         top = nodnou;
     }
   /*cazul de mai sus se poate reduce la urmatoarele 2 comenzi deoarece , daca lista este vida atunci legatura se va face cu null
   nodnou -> next = top;
   top = nodnou;*/
}

int pop(nod* &top) // scoate elementul din varful stivei si il intoarce ca rezultat al functiei
{
  if (isempty(top))
        return 0;
  else
  {
    nod* temp = top;
    top = top -> next;
    int varf_inf = temp -> info;
    delete temp;
    return varf_inf;
  }
}

int peek(nod* top) // intoarece elementul din varful stivei fara a-l scoate
{
  if (isempty(top))
        return 0;
  return top -> info;
}

int cautare(int a, nod* top)
{
  if (isempty(top))
    {
     cout << "Stiva este vida si nu se poate efectua cautarea" << endl;
     return -1;
    }
  int distanta = 0;
  while (top != NULL)
    {
      if (top -> info == a)
        return distanta;
      top = top -> next;
      distanta++;
    }
 return -1;
}

void afiseaza(nod* top) // afisare varf -> baza
{
  if (isempty(top))
    cout << "Stiva este vida" << endl;
  else
    {
     cout << "Stiva contine urmatoarele elemente :" << endl;
     while (top != NULL)
        {
         cout << top -> info <<endl;
         top = top -> next;
        }
    }
}

int main()
{
  int n;
  cout << "Dati numarul de pini : ";
  cin >> n;
  int *pereche = new int[n+1];
  int i;
  for(i=1; i<=n; i++)
    {
     cout << "pereche[" << i << "]=";
     cin >> pereche[i];
    }

  for(int i=1; i<=n; i++)
    { if(isempty(top)) // Stiva e vida
            push(pereche[i],top);
      else
          if(pereche[i] == peek(top))
                pop(top);
          else
                push(pereche[i],top);
    }
  if (isempty(top))
    cout<<"Configuratie valida";
  else
    cout<<"Configuratie invalida";
  delete []pereche;
    return 0;
}
