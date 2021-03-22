#include <iostream>

using namespace std;

void inter(int st, int mij, int dr, int n, int *v)
{
 int i = st, j = mij+1, *w, k=0;
 w = new int [n];
 while (i <= mij && j <= dr)
    {
     if (v[i] < v[j])
        w[k++] = v[i++];
     else
        w[k++] = v[j++];
    }
 for (int l = i; l <= mij; l++)
    w[k++] = v[l];
 for (int l = j; l <= dr; l++)
    w[k++] = v[l];
 for (int a = st; a <= dr; a++)
    v[a] = w[a-st];
 cout << endl << "nu";
 delete []w;
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

void merge_sort(int st, int dr, int n, int *v)
{
 if (st < dr)
    {
     int mij = st + (dr - st)/2;
     if (mij - st < 10)
        insertion2(v,st,mij);
     else
        merge_sort(st, mij, n, v);
     if (dr - mij - 1 < 10)
        insertion2(v, mij+1, dr);
     else
        merge_sort(mij+1, dr, n, v);
     if(dr - mij >= 10 && mij - st >= 10)
        inter(st, mij, dr, n, v);
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
 if (n < 10)
    insertion2(v,1,n);
 else
    merge_sort(1,n,n,v);
 cout << endl <<"Vectorul sortat: ";
 for (i=1; i <= n; i++)
    cout << v[i] << " ";
 delete []v;
    return 0;
}
