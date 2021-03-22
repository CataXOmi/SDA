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
 int dim=0,val,i;
 string expr;
 nod *temp=cap;
 cout << "Doriti sa adaugati elemente ? ";
 cin >> expr;
 while(expr!="stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
     cin >> val;
     temp=cap;
     if(cap==NULL)
        {
         adaug_inceput(cap,val,dim);
        }
     else
        {i=0;
         if(cap->info<=val)
            {while(temp->urm!=NULL && temp->urm->info<=val)
                {i++;
                 temp=temp->urm;
                }
             nod * nou = new nod;
             nou->info = val;
             nou->urm = temp->urm;
             temp->urm = nou;
             dim++;
             //adaug_interior(cap,i+1,val,dim);
            }
         else
            {
                    adaug_inceput(cap,val,dim);
            }
        }
     cout << "Doriti sa adaugati elemente ? ";
     cin >> expr;
    }
 afisareLista(cap);
 sterg_tot(cap);
    return 0;
}
