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
 nod * A = NULL;
 nod * B = NULL;
 int dimA=0, dimB=0,val,i;
 string expr;
 nod *temp=A;
 cout << "Doriti sa adaugati elemente pentru lista A ? ";
 cin >> expr;
 while(expr!="stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
     cin >> val;
     temp=A;
     if(A==NULL)
        {
         adaug_inceput(A,val,dimA);
        }
     else
        {i=0;
         if(A->info<=val)
            {while(temp->urm!=NULL && temp->urm->info<=val)
                {i++;
                 temp=temp->urm;
                }
             nod * nou = new nod;
             nou->info = val;
             nou->urm = temp->urm;
             temp->urm = nou;
             dimA++;
             //adaug_interior(cap,i+1,val,dim);
            }
         else
            {
                    adaug_inceput(A,val,dimA);
            }
        }
     cout << "Doriti sa adaugati elemente pentru lista A ? ";
     cin >> expr;
    }
 afisareLista(A);
 nod *tmp=B;
 cout << "Doriti sa adaugati elemente pentru lista B? ";
 cin >> expr;
 while(expr!="stop")//Prin conventie am stabilit ca "stop" sa insemne incheierea alegerilor utilizatorului
    {cout << "Dati valoarea elementului pe care doriti sa-l adaugati ";
     cin >> val;
     tmp=B;
     if(B==NULL)
        {
         adaug_inceput(B,val,dimB);
        }
     else
        {i=0;
         if(B->info<=val)
            {while(tmp->urm!=NULL && tmp->urm->info<=val)
                {i++;
                 tmp=tmp->urm;
                }
             nod * nou = new nod;
             nou->info = val;
             nou->urm = tmp->urm;
             tmp->urm = nou;
             dimB++;
             //adaug_interior(cap,i+1,val,dim);
            }
         else
            {
                    adaug_inceput(B,val,dimB);
            }
        }
     cout << "Doriti sa adaugati elemente pentru lista B? ";
     cin >> expr;
    }
 afisareLista(B);
 cout << dimA << " " << dimB;
 nod *C = NULL;
 int dimC=0;
 while (A != NULL || B != NULL)
    {if(dimA!=0 && dimB!=0)
        {
         if(A->info<=B->info)
            {
             adaug_final(C,A->info,dimC);
             A=A->urm;
             dimA--;
            }
          else
            {
             adaug_final(C,B->info,dimC);
             B=B->urm;
             dimB--;
            }
         }
     else
        {
         if(dimA==0)
            if(dimB!=0)
                {
                 adaug_final(C,B->info,dimC);
                 B=B->urm;
                 dimB--;
                }
         if(dimB==0)
            if(dimA!=0)
                {
                 adaug_final(C,A->info,dimC);
                 A=A->urm;
                 dimA--;
                }
        }
     }
 cout << endl;
 afisareLista(C);
    return 0;
}
