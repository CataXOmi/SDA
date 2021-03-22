#include <iostream>

using namespace std;

struct nod
{
 float info;
 nod *urm;
};

void adaug_final(nod* &cap,float val,int &dim)
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

void adaug_inceput(nod* &cap,float val,int &dim)
{nod * nou = new nod;
 nou->info = val;
 nou->urm = cap;
 cap = nou;
 dim++;
}

void adaug_interior(nod* &cap,int poz,float val,int &dim)
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
 float media;
 int dim=0,i=0;
 string expr;
 cout << "1.Adaugarea unui nou element la finalul listei"<<endl;
 cout << "2.Adaugarea unui nou element la inceputul listei"<<endl;
 cout << "3.Adaugarea unui nou element in interiorul listei"<<endl;
 cout << "Alegeti una dintre adaugarile mentionate anterior : ";
 cin >> expr;
 while(expr!="stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {if(expr=="1")
      {
       float val;
       cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
       cin >> val;
       adaug_final(cap,val,dim);
      }
     if(expr=="2")
      {
       float val;
       cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
       cin >> val;
       adaug_inceput(cap,val,dim);
      }
     if(expr=="3")
      {
       float val;
       int poz;
       cout << "Dati valoarea si pozitia elementului pe care doriti sa-l adaugati ";
       cin >> val >> poz;
       adaug_interior(cap,poz,val,dim);
      }
     cout << "Alegeti una dintre adaugarile mentionate anterior : ";
     cin >> expr;
    }
 afisareLista(cap);
 nod *temp=cap;
 while(temp->urm!=NULL)
    {media=(temp->info+temp->urm->info)/2.;
     //adaug_interior(temp,i+1,media,dim);
     nod * nou = new nod;
     nou->info = media;
     nou->urm = temp->urm;
     temp->urm = nou;
     dim++;
     temp=temp->urm->urm;
     //i++;
    }
 afisareLista(cap);
 sterg_tot(cap);
    return 0;
}
