//TUR DONUSUMLERI
#include<stdio.h>
int main()
{
	int x=80;
	char y='a';
	double z=73.786;
	printf("%d-->%lf\n",x,(double)x);
	printf("%c-->%d\n",y,(int)y);
	printf("%c-->%lf\n",y,(double)y);
	
	printf("%d-->%c\n",x,(char)x);
	printf("%lf-->%d\n",z,(int)z);
	printf("%lf-->%c\n",z,(char)z);
}
