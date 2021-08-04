#include<stdio.h>
#include<stdlib.h>

int faktoriyel(int x);

int main(){
	int sayi;
	
	printf("bir sayi girin: ");
	scanf("%d",&sayi);
	
	faktoriyel(sayi);
		
	getch();
	return 0;
}

int faktoriyel(int x){
	int i,sonuc=1;
	
	for(i=1 ; i<=x ; i++){
			sonuc *= i ;
	}
	printf("%d sayisinin faktoriyeli: %d ",x,sonuc);	
}


