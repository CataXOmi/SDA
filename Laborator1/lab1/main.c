#include <stdio.h>
#include <stdlib.h>

void bubblesort()
{int *v,n,i,gasit,aux;
 printf("\nDati numarul de elemente ");
 scanf("%d",&n);
 v=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    {
     printf("Elementul v[%d] este egal cu ",i);
     scanf("%d",&v[i]);
    }
  do
  {gasit=1;
   for(i=0;i<n-1;i++)
        {if(v[i]>v[i+1])
            {aux=v[i];
             v[i]=v[i+1];
             v[i+1]=aux;
             gasit=0;
            }
        }
  }
  while(gasit==0);
  printf("\nVectorul sortat este : ");
  for(i=0;i<n;i++)
    {if(i!=n-1)
        printf("%d,",v[i]);
     else
        printf("%d",v[i]);
    }
  free(v);
}

void insertion()
{int *v,x,n,i,j;
 printf("\nDati numarul de elemente ");
 scanf("%d",&n);
 v=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    {
     printf("Elementul v[%d] este egal cu ",i);
     scanf("%d",&v[i]);
    }
 for(i=1;i<n;i++)
    {
     x=v[i];
     j=i-1;
     while(j>=0 && x<v[j])
        {
         v[j+1]=v[j];
         j--;
        }
     v[j+1]=x;
    }
 printf("\nVectorul sortat este : ");
 for(i=0;i<n;i++)
    {if(i!=n-1)
        printf("%d,",v[i]);
     else
        printf("%d",v[i]);
    }
 free(v);
}

void selection()
{int *v,min,poz,n,i,j;
 printf("\nDati numarul de elemente ");
 scanf("%d",&n);
 v=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    {
     printf("Elementul v[%d] este egal cu ",i);
     scanf("%d",&v[i]);
    }
 for(i=0;i<n-1;i++)
    {min=v[i];
     poz=i;
     for(j=i+1;j<n;j++)
        if(min>v[j])
            {min=v[j];
             poz=j;
            }
     v[poz]=v[i];
     v[i]=min;
    }
 printf("\nVectorul sortat este : ");
 for(i=0;i<n;i++)
    {if(i!=n-1)
        printf("%d,",v[i]);
     else
        printf("%d",v[i]);
    }
 free(v);
}

void cautsecv()
{int *v,n,i,x,ok=0;
 printf("\nDati numarul de elemente ");
 scanf("%d",&n);
 printf("\nDati valoarea care trebuie cautata ");
 scanf("%d",&x);
 v=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    {
     printf("Elementul v[%d] este egal cu ",i);
     scanf("%d",&v[i]);
    }
 for(i=0;i<n;i++)
    {if(v[i]==x)
        {
         printf("Valoarea data a fost gasita ca fiind elementul %d din vector",i);
         ok=1;
        }
    }
 if(ok==0)
    printf("Valoarea data nu a fost gasita");
 free(v);
}

void cautbin()
{int *v,ok=0,n,i,x,st=0,dr;
 printf("\nDati numarul de elemente ");
 scanf("%d",&n);
 printf("\nDati valoarea care trebuie cautata ");
 scanf("%d",&x);
 v=(int*)malloc(n*sizeof(int));
 for(i=0;i<n;i++)
    {
     printf("Elementul v[%d] este egal cu ",i);
     scanf("%d",&v[i]);
    }
 dr=n-1;
 i=1;
 while(st<=dr)
 {int mij=st+(dr-st)/2;
  if(v[i]==x)
    {
     i=mij;
     ok=1;
     break;
    }
  if(v[mij]>x)
    dr=mij-1;
  if(v[mij]<x)
    st=mij+1;
 }
 if(ok==1)
    printf("Valoarea a fost gasita ca fiind elementul %d din vector",i);
 if(ok==0)
    printf("Valoarea nu a fost gasita");
 free(v);
}

int main()
{int met;
 printf("Alegeti o metoda : ");
 scanf("%d",&met);
 switch(met)
    {case 1:
        printf("Ati ales metoda bubblesort");
        bubblesort();
        break;
     case 2:
        printf("Ati ales metoda insertion");
        insertion();
        break;
     case 3:
        printf("Ati ales metoda selection");
        selection();
        break;
     case 4:
        printf("Ati ales metoda cautsecv");
        cautsecv();
        break;
     case 5:
        printf("Ati ales metoda cautbin");
        cautbin();
        break;
    }
 return 0;
}
