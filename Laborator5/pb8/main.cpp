#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

using namespace std;

//Folosim oartitionarea Lomuto

int partitionare(int *v, int st, int dr)
{
    int pivot = v[dr];
    int i = st;
    for (int j = st; j < dr ; j++)
        {
            if (v[j] <= pivot)
            {
             swap(v[i], v[j]);
             i++;
            }
        }
    swap(v[i], v[dr]);
    cout << endl << "nu";
    return i;
}

void insertion(int n, int *v)
{
 int x,i,j;
 for(i=2;i<=n;i++)
    {
     x=v[i];
     j=i-1;
     while(j>=1 && x<v[j])
        {
         v[j+1]=v[j];
         j--;
        }
     v[j+1]=x;
    }
 cout << endl << "da";
}

void insertion2(int *v, int inc, int sf)
{
 int x,i,j;
 for(i=inc;i<=sf;i++)
    {
     x=v[i];
     j=i-1;
     while(j>=1 && x<v[j])
        {
         v[j+1]=v[j];
         j--;
        }
     v[j+1]=x;
    }
 cout << endl << "da";
}

int partition_r(int *v, int st, int dr)
{
    srand(time(NULL));
    int random = st + rand()%(dr - st);
    swap(v[random], v[dr]);
    return partitionare(v, st, dr);
}

void quickSort(int *v, int st, int dr)
{
    if (st < dr)
      {
        if(dr - st <= 11)
            insertion2(v, st, dr);
        int piv = partition_r(v, st, dr);
        quickSort(v, st, piv - 1);
        quickSort(v, piv + 1, dr);
      }
}

void quickSort2(int *v, int st, int dr)
{
    if (st < dr)
      {
        if(dr - st <= 11)
            insertion2(v, st, dr);
        else
            {
                int piv = partition_r(v, st, dr);
                quickSort(v, st, piv - 1);
                quickSort(v, piv + 1, dr);
            }
      }
}

void quickSort3(int *v, int st, int dr)
{
    if (st < dr)
      {
        if(dr - st <= 11)
            insertion2(v, st, dr);
        int piv = partition_r(v, st, dr);
        if(piv - 1 - st <= 11)
            insertion2(v,st,piv-1);
        else
            quickSort(v, st, piv - 1);
        if(dr - piv -1 <= 11)
            insertion2(v,piv+1,dr);
        else
            quickSort(v, piv + 1, dr);
      }
}

void quickSort4(int *v, int st, int dr)
{
    if (st < dr)
      {
        int piv = partition_r(v, st, dr);
        if(piv - 1 - st <= 11)
            insertion2(v,st,piv-1);
        else
            quickSort(v, st, piv - 1);
        if(dr - piv -1 <= 11)
            insertion2(v,piv+1,dr);
        else
            quickSort(v, piv + 1, dr);
      }
}

int main()
{
 int *v,n,i;
 cout << "Dati numarul de elemente: ";
 cin >> n;
 v = new int [n+1];
 cout << "Dati elementele vectorului: ";
 for (i = 1; i <= n; i++)
         cin >> v[i];
 if (n <= 11)
    insertion2(v,1,n);
 else
    quickSort4(v,1,n);
 cout << endl <<"Vectorul sortat: ";
 for (i=1; i <= n; i++)
    cout << v[i] << " ";
 delete []v;
    return 0;
}
