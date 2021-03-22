#include <iostream>
#include <fstream>
using namespace std;

void servire(int *coada,int n,int &ndim)
{
 int i;
 for (i=1;i<ndim;i++)
    coada[i] = coada[i+1];
 ndim = ndim-1;
 for(i=ndim+1;i<=n;i++)
    coada[i]=0;
}

void sosire(int *coada, int n, int &nelem, int &ndim)
{
 int i;
 for(i=1;i<=n;i++)
    if(coada[i]==0 && ndim < n)
        {
         nelem++;
         coada[i]=nelem;
         ndim++;
         break;
        }
}

void imbrancire(int x,int *coada,int ndim)
{
 int i,aux,j;
 for(i=1;i<=ndim;i++)
    if(coada[i]==x)
        if(i!=1)
            {
             aux=coada[1];
             coada[1]=coada[i];
             coada[i]=aux;
             int poz=i;
             for(j=i-1;j>=2;j--)
                {
                 aux=coada[j];
                 coada[j]=coada[poz];
                 coada[poz]=aux;
                 poz--;
                }

            }
}

int main()
{
 int n,k,i,j,*op,*elem3,nr3=1,*coada,ndim;
 ifstream f;
 f.open("lacoada.in");
 ofstream g;
 g.open("lacoada.out");
 f >> n;
 while (n < 1 || n > 60000)
    f >> n;
 f >> k;
 while (k < 1 || k > 1000000)
    f >> k;
 coada = new int [n+1];
 op = new int [k+1];
 elem3 = new int [k+1];
 for(i=1;i<=k;i++)
    {
     f >> op[i];
     if (op[i] == 3)
        f >> elem3[nr3++];
    }
 for(i=1;i<=n;i++)
    coada[i] = i;
 ndim = n;
 int nelem = n;
 int apar = 1;
 for(i=1;i<=k;i++)
    {
     if(op[i]==1)
        if(ndim!=0)
            {
                servire(coada,n,ndim);
                g << endl << "Servire: ";
                for(j=1;j<=ndim;j++)
                    g  << coada[j] << " ";
                g << endl;
            }
     if(op[i]==2)
            {
                sosire(coada,n,nelem,ndim);
                g << endl << "Sosire: ";
                for(j=1;j<=ndim;j++)
                    g  << coada[j] << " ";
                g << endl;
            }
     if(op[i]==3)
       if(ndim!=0)
        {
         imbrancire(elem3[apar],coada,ndim);
         apar++;
         g << endl << "Imbrancire: ";
                for(j=1;j<=ndim;j++)
                    g  << coada[j] << " ";
                g << endl;
        }
    }
 g << ndim << endl;
 for(i=1;i<=ndim;i++)
     g << coada[i] << " ";
 f.close();
 g.close();

    return 0;
}
