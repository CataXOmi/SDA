#include <iostream>

using namespace std;

int v[100];

void scufundare(int n, int k)
{
 int fiu = 0;
 do
    {
     if (2*k <= n)
        fiu = 2*k;
     if (2*k+1 <= n && v[2*k+1] > v[2*k])
        fiu = 2*k+1;
     if (v[fiu] > v[k])
        {
         swap(v[fiu],v[k]);
         k = fiu;
        }
     else
        fiu = 0;
    }
 while (fiu != 0);
}

void ridicare( int n, int k)
{
 int aux = v[k];
 while (k/2 > 0 && v[k/2] < aux)
    {
     v[k] = v[k/2];
     k = k/2;
    }
 v[k] = aux;
}

void adaug(int &n, int info)
{
 v[++n] = info;
 ridicare(n,n);
}

void stergere(int &n, int k)
{
 v[k] = v[n--];
 if (k/2 > 0 && v[k] > v[k/2])
    ridicare(n,k);
 else
    scufundare(n,k);
}

void sortare(int n, int m)
{
 for (int i=1; i <= m-1; i++)
    {
     swap(v[n--], v[1]);
     scufundare(n, 1);
    }
}

void max_heap(int n)
{
 for (int i = n/2; i >= 1; i--)
    scufundare(n,i);
}

int main()
{
 int n,i;
 cout << "Dati numarul de elemente: ";
 cin >> n;
 cout << "Dati elementele vectorului: ";
 for (i = 1; i <= n; i++)
         cin >> v[i];
 max_heap(n);
 int info, poz;
 for (i = 1; i <= n; i++)
    cout << v[i] << " ";
 cout << endl <<"Dati informatia nodului pe care doriti sa-l adaugati: ";
 cin >> info;
 adaug(n, info);
 max_heap(n);
 cout << "Heap-ul dupa adaugare: ";
 for (i = 1; i <= n; i++)
    cout << v[i] << " ";
 cout << endl << "Dati pozitia nodului pe care doriti sa-l stergeti: ";
 cin >> poz;
 stergere(n,poz);
 max_heap(n);
 cout << "Heap-ul dupa stergere: ";
 for (i = 1; i <= n; i++)
    cout << v[i] << " ";
 sortare(n,n);
 cout << endl << "Vectorul dupa heap sort: ";
 for (i = 1; i <= n; i++)
    cout << v[i] << " ";
 return 0;
}
