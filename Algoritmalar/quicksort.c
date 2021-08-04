/*KAHRAMANMARAÞ SÜTCÜ ÝMAM ÜNÝVERSÝTESÝ MÜHENDÝSLÝK VE MÝMARLIK FAKÜLTESÝ
                    BÝLGÝSAYAR MÜHENDÝSLÝÐÝ
      BÜÞRA YORULMAZ      18110131018        2. SINIF ÖÐRENCÝSÝ */
      
#include <stdio.h>
#include <stdlib.h>

int PARTITION(int A[], int p, int r);
void QUICKSORT(int A[], int p, int r);

int main(){
	int length,i;
	int p,r;  // p = dizinin ilk elemaný , r = dizinin en saðýnda bulunan elaman

	printf("dizi degeri girin: ");   // kullanýcýdan boyut miktarý alýnýr
	scanf("%d",&length);
	int A[length];
	
	printf("Dizinin random hali:\n");  
    for( i=0; i<length; i++){
        A[i]=rand()%100;
		printf("%d\t",A[i]);   // kullanýcýdan alýnan boyut kadar random dizi ekrana yazdýrýlýr
    }
    printf("\n");
    
    QUICKSORT(A, 0 , length - 1);   // quick sort fonksiyonu çaðýrýlýr
    printf("\nDizinin quick sort ile sirali hali:\n");
    	for( i=0 ; i<length ; i++){
    	 	printf("%d\t", A[i]);  // dizi quick sort sýralamasý ile ekrana yazdýrýlýr
	}    
    return 0;
	}
	
	void swap(int* a, int* b)  // swap elemanlarýn konumlarýný deðiþtirme iþlevidir
	{
		int t = *a;
			*a = *b;
			*b = t;
	}
	int PARTITION(int A[], int p, int r) // Diziyi pivot öðesi temelinde bölümleme iþlevi
	{
		int j;
    	int pivot = A[r]; //dizinin en son elemaný (r) pivot olarak seçilir.
    	int i = (p - 1);  

	
  	
  	for ( j = p; j <= r - 1; j++)  
    {
        if (A[j] <= pivot)// Pivot'tan daha küçük ögeler sola yerleþtirilir
        {
            i++;    
            swap(&A[i], &A[j]);       
        }
    }
    swap(&A[i + 1], &A[r]);
    return (i + 1);
}
	void QUICKSORT(int A[], int p, int r)
	{
    	if (p < r)
    {
    
    int q = PARTITION(A, p, r);    
        QUICKSORT(A, p, q - 1);// Pivotun solundaki ögeler sýralanýr
        QUICKSORT(A, q + 1, r);// pivotun saðýndaki ögeler sýralanýr
    }
	}

