#include <iostream>

using namespace std;

struct nod
{
 int info;
 nod *urm;
};

void adaug_final(nod* &cap,int val,int &dim)
{nod *p = new nod;
 p->info = val;
 p->urm = NULL;
 if (cap == NULL)
    cap = p;
 else
    {nod *nod_crt = cap;
     while(nod_crt->urm != NULL)
        nod_crt = nod_crt->urm;
     nod_crt->urm = p;
    }
 dim++;
}

void adaug_inceput(nod* &cap,int val,int &dim)
{nod * nou = new nod;
 nou->info = val;
 nou->urm = cap;
 cap = nou;
 dim++;
}

void adaug_interior(nod* &cap,int poz,int val,int &dim)
{int i;
 nod *nod_crt = cap;
 if(poz<=0)
    adaug_inceput(cap,val,dim);
 else
    {if(poz>=dim)
        adaug_final(cap,val,dim);
     else
        {for(i=0;i<poz-1;i++)
            nod_crt = nod_crt->urm;
         nod *p=new nod;
         p->info=val;
         p->urm=nod_crt->urm;
         nod_crt->urm=p;
        }
    }
 dim++;
}

void afisareLista(nod* cap)
{
  if (cap == NULL)
        cout << "Lista nu are elemente"<<endl;
  else
        cout << "Lista este : " <<endl;
  while (cap != NULL)
        {
         cout<<cap->info<<endl;
         cap = cap->urm;
        }
}

void cautare_val(nod* cap,int val)
{if(cap==NULL)
    {
     cout << "Lista este vida "<<endl;
     return;
    }
 int gasit=0;
 do
    {
     if(cap->info==val)
           gasit=1;
     cap=cap->urm;
    }
 while (cap);
 if(gasit==0)
    cout << "Elementul dat nu se afla in lista";
 else
    cout << "Elementul dat se afla in lista";
}

void cautare_poz(nod* cap,int poz)
{//atentie lista este numerotata incepand cu pozitia zero
 int i=0,ok=0;
 if(cap==NULL)
    {
     cout << "Lista este vida "<<endl;
     return;
    }
 do
    {if(i==poz)
        {
            cout << "Elementul de pe pozitia " << poz << " a fost gasit si are valoarea " << cap->info;
            ok=1;
        }
     cap=cap->urm;
     i++;
    }
 while (cap);
 if(ok==0)
    cout << "Elementul dat nu se afla in lista";
}

void sterg_poz(nod* &cap,int poz,int &dim)
{int i;
 if(cap==NULL)
    {
     cout << "Lista este vida si nu se poate efectua stergere "<<endl;
     return;
    }
 if(poz<=0)
    {
     cout<<"Stergere de la inceput";
     nod* temp=cap;
     cap=cap->urm;
     delete temp;
    }
 else
    {if(poz>=dim)
        {
         cout<<"Stergere de la sfarsit";
         nod *temp=cap;
         while(temp->urm->urm)
            temp=temp->urm;
         delete temp->urm;
         temp->urm=NULL;
        }
     else
        {
         nod *temp=cap,*r;
         for(i=0;i<poz-1;i++)
            temp = temp->urm;
         r=temp->urm;
         temp->urm=r->urm;
         delete r;
        }
    }
 dim--;
}

void sterg_val(nod* &cap,int val,int &dim)
{if(cap==NULL)
    {
     cout << "Lista este vida si nu se poate efectua stergere "<<endl;
     return;
    }
 if(cap->info==val)
    {
     nod* temp=cap;
     cap=cap->urm;
     delete temp;
     dim--;
    }
 nod* elem=cap;
 while(elem->urm != NULL)
        if(elem->urm->info==val)
            {
             nod* temp=elem->urm;
             elem->urm=elem->urm->urm;
             delete temp;
             dim--;
            }
        else
            elem=elem->urm;

}


void sterg_tot(nod* &cap)
{if(cap==NULL)
    {
     cout << "Lista este vida si nu se poate efectua stergere "<<endl;
     return;
    }
 nod* temp;
 while(cap != NULL)
    {
     temp = cap;
     cap = cap->urm;
     delete temp;
    }
}

int dimensiune(nod* cap)
{
 int i=0;
 while(cap)
    {
     cap=cap->urm;
     i++;
    }
 return i-1;
}

int main()
{//Am ales sa initializam lista cu NULL
 nod * cap = NULL;
 int dim=dimensiune(cap);
 string expr;
 cout << "Meniul contine urmatoarele operatii :"<<endl;
 cout << "1.Adaugarea unui nou element la finalul listei"<<endl;
 cout << "2.Adaugarea unui nou element la inceputul listei"<<endl;
 cout << "3.Adaugarea unui nou element in interiorul listei"<<endl;
 cout << "4.Afisarea listei"<<endl;
 cout << "5.Cautarea unui element dupa valoare"<<endl;
 cout << "6.Cautarea unui element dupa pozitie"<<endl;
 cout << "7.Stergerea unui element dupa valoare"<<endl;
 cout << "8.Stergerea unui element dupa pozitie"<<endl;
 cout << "9.Stergerea intregii liste"<< endl;
 cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
 cin >> expr;
 while(expr!="stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
 {if(expr=="1")
     {
      int val;
      cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
      cin >> val;
      adaug_final(cap,val,dim);
     }
  if(expr=="2")
     {
      int val;
      cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
      cin >> val;
      adaug_inceput(cap,val,dim);
     }
  if(expr=="3")
    {
     int val,poz;
     cout << "Dati valoarea si pozitia elementului pe care doriti sa-l adaugati ";
     cin >> val >> poz;
     adaug_interior(cap,poz,val,dim);
    }
  if(expr=="4")
    {
     afisareLista(cap);
    }
  if(expr=="5")
    {
     int val;
     cout << "Dati valoarea elementului pe care doriti sa-l cautati ";
     cin >> val;
     cautare_val(cap,val);
    }
  if(expr=="6")
    {
     int poz;
     cout << "Dati pozitia elementului pe care doriti sa-l cautati ";
     cin >> poz;
     cautare_poz(cap,poz);
    }
  if(expr=="7")
    {
     int val;
     cout << "Dati valoarea elementului pe care doriti sa-l stergeti ";
     cin >> val;
     sterg_val(cap,val,dim);
    }
  if(expr=="8")
    {int poz;
     cout << "Dati pozitia elementului pe care doriti sa-l stergeti ";
     cin >> poz;
     sterg_poz(cap,poz,dim);
    }
  if(expr=="9")
    {
     sterg_tot(cap);
    }
  cout << "Alegeti optiunea pe care o doriti dintre cele mentionate in meniu : ";
  cin >> expr;
 }
 return 0;
}
