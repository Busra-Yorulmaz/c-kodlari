#include<stdio.h>
#include<stdio.h>

int ToplamAl (int dizi[],int t);
int main()
{
	int dizi[]={1,2,3,4,5};
	int t,i;
	printf("Kacinci elemana kadar toplam alinacak?\n");
	scanf("%d",&t);
	dizi[t]=ToplamAl(dizi,t);
	for (i=0;i<5;i++)
	{
		printf("%d-",dizi[i]);
	}
}

int ToplamAl (int dizi[],int t)
{
	int i,sonuc=0;
	for (i=0;i<=t;i++)
	{
		sonuc+=dizi[i];
	}
	return sonuc;
}
