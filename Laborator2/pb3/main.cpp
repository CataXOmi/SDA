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

void sterg_tot(nod* &cap)
{
 nod* temp;
 while(cap != NULL)
    {
     temp = cap;
     cap = cap->urm;
     delete temp;
    }
}


int main()
{//Am ales sa initializam lista cu NULL
 nod * cap = NULL;
 int nrpoz=0;
 float media,suma_media=0,nr_media=0;
 int dim=0;
 string expr;
 cout << "1.Adaugarea unui nou element la finalul listei"<<endl;
 cout << "2.Adaugarea unui nou element la inceputul listei"<<endl;
 cout << "3.Adaugarea unui nou element in interiorul listei"<<endl;
 cout << "Alegeti una dintre adaugarile mentionate anterior : ";
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
     cout << "Alegeti una dintre adaugarile mentionate anterior : ";
     cin >> expr;
    }
 afisareLista(cap);
 while(cap)
    {if(cap->info>0)
        nrpoz++;
     if(cap->info<0)
        {suma_media+=cap->info;
         nr_media++;
        }
     cap=cap->urm;
    }
 media=suma_media/nr_media;
 cout << "Numarul de elemente pozitive este : " << nrpoz << endl;
 cout << "Media elementelor negative este : " << media << endl;
 sterg_tot(cap);
    return 0;
}
