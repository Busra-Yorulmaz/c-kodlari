#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void mergeSort(int arr[], int l, int r);

int main(){
	int deger,i;
	clock_t basla_1,bit_1; 

	printf("dizi degeri girin: ");
	scanf("%d",&deger);
	int dizi[deger];
	
	printf("Dizinin random hali:\n");
    for( i=0; i<deger; i++){
        dizi[i]=rand()%100;
		printf("%d\t",dizi[i]);
    }
    printf("\n");
     
    basla_1 = clock();  
    mergeSort(dizi,0,deger-1); 
    bit_1 = clock(); 
    printf("\nDizinin merge sort ile sirali hali:\n");
    	for( i=0; i<deger; i++){
    		printf("%d\t", dizi[i]);
	}
   
		printf("\nMerge Calisma performansi: %f \n",(double)(bit_1 - basla_1) / CLOCKS_PER_SEC);
    
		getch();
    return 0;
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}
