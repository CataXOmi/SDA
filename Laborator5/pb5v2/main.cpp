#include <iostream>
#include <string.h>
#include <stdio.h>
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

void sortare(nod *t,char *sircuv)
{
 if (t != NULL)
    {
     sortare(t -> dr,sircuv);
     int dim = strlen(sircuv);
     strcpy(sircuv+dim, t -> info);
     dim = strlen(sircuv);
     strcpy(sircuv+dim, " ");
     sortare(t -> st,sircuv);
    }
}

int main()
{
 char sircuv[365];
 char *p;
 cout << "Dati sirul de cuvinte: ";
 gets(sircuv);
 cout << "Sir initial: ";
 puts(sircuv);
 p = strtok(sircuv," ");
 while(p)
    {
     inserare(t,p);
     p = strtok(NULL," ");
    }
 cout << endl;
 strcpy(sircuv,"");
 sortare(t,sircuv);
 cout << "Sir ordonat descrescator: ";
 puts(sircuv);
}
