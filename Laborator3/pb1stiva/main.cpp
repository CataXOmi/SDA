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
  string expr;
  cout << "Prin conventie 0 este un element de marcaj" << endl;
  cout << "Meniul contine urmatoarele operatii :" << endl;
  cout << "1. Adaugati un element in varful stivei" << endl;
  cout << "2. Scoateti elementul din varful stivei" << endl;
  cout << "3. Afisati elementul din varful stivei" << endl;
  cout << "4. Verificati daca stiva este vida" << endl;
  cout << "5. Verificati daca un element se afla in stiva" << endl;
  cout << "6. Afisati stiva" << endl;
  cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
  cin >> expr;
  while(expr != "stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {
     if(expr == "1")
        {
         int val;
         cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
         cin >> val;
         push(val,top);
        }
     if(expr ==  "2")
        {int varf = pop(top);
         if (varf != 0)
            cout << "Elementul din varful stivei in urma operatiei pop este " << varf << endl;
         else
            cout << "Stiva este vida" << endl;
        }
     if(expr == "3")
        {
         if (peek(top) != 0)
            cout << "Elementul din varful stivei in urma operatiei peek este " << peek(top) << endl;
         else
            cout << "Stiva este vida" << endl;
        }
     if(expr == "4")
        {
         if (isempty(top))
            cout << "Stiva este vida" << endl;
         else
            cout << "Stiva nu este vida" << endl;
        }
     if(expr == "5")
        {
         int val;
         cout << "Dati valoarea elementului pe care doriti sa-l cautati ";
         cin >> val;
         int rez_caut = cautare(val, top);
         if(rez_caut == -1)
            cout << "Elementul dat nu se afla in stiva" << endl;
         else
            cout << "Elementul dat se afla in stiva si este la distanta " << rez_caut << endl;
        }
     if(expr == "6")
        {
         afiseaza(top);
        }
     cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
     cin >> expr;
    }
    return 0;
}
