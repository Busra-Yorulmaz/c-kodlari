
#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n);

int main(){
	int deger,i;

	printf("dizi degeri girin: ");
	scanf("%d",&deger);
	int dizi[deger];
	
	printf("Dizinin random hali:\n");
    for( i=0; i<deger; i++){
        dizi[i]=rand()%100;
		printf("%d\t",dizi[i]);
    }
    printf("\n");
    
    insertionSort(dizi,deger);
    printf("\nDizinin insertion sort ile sirali hali:\n");
    	for( i=0; i<deger; i++){
    	 	printf("%d\t", dizi[i]);
	}    
   	getch();
    return 0;
	}
    
	
void insertionSort(int arr[], int n)
{
   int i, deger, j;
   for (i = 1; i < n; i++)
   {
       deger = arr[i];
       j = i-1;

       while (j >= 0 && arr[j] > deger)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = deger;
   }
}

