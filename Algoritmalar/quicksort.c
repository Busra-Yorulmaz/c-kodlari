/*KAHRAMANMARA� S�TC� �MAM �N�VERS�TES� M�HEND�SL�K VE M�MARLIK FAK�LTES�
                    B�LG�SAYAR M�HEND�SL���
      B��RA YORULMAZ      18110131018        2. SINIF ��RENC�S� */
      
#include <stdio.h>
#include <stdlib.h>

int PARTITION(int A[], int p, int r);
void QUICKSORT(int A[], int p, int r);

int main(){
	int length,i;
	int p,r;  // p = dizinin ilk eleman� , r = dizinin en sa��nda bulunan elaman

	printf("dizi degeri girin: ");   // kullan�c�dan boyut miktar� al�n�r
	scanf("%d",&length);
	int A[length];
	
	printf("Dizinin random hali:\n");  
    for( i=0; i<length; i++){
        A[i]=rand()%100;
		printf("%d\t",A[i]);   // kullan�c�dan al�nan boyut kadar random dizi ekrana yazd�r�l�r
    }
    printf("\n");
    
    QUICKSORT(A, 0 , length - 1);   // quick sort fonksiyonu �a��r�l�r
    printf("\nDizinin quick sort ile sirali hali:\n");
    	for( i=0 ; i<length ; i++){
    	 	printf("%d\t", A[i]);  // dizi quick sort s�ralamas� ile ekrana yazd�r�l�r
	}    
    return 0;
	}
	
	void swap(int* a, int* b)  // swap elemanlar�n konumlar�n� de�i�tirme i�levidir
	{
		int t = *a;
			*a = *b;
			*b = t;
	}
	int PARTITION(int A[], int p, int r) // Diziyi pivot ��esi temelinde b�l�mleme i�levi
	{
		int j;
    	int pivot = A[r]; //dizinin en son eleman� (r) pivot olarak se�ilir.
    	int i = (p - 1);  

	
  	
  	for ( j = p; j <= r - 1; j++)  
    {
        if (A[j] <= pivot)// Pivot'tan daha k���k �geler sola yerle�tirilir
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
        QUICKSORT(A, p, q - 1);// Pivotun solundaki �geler s�ralan�r
        QUICKSORT(A, q + 1, r);// pivotun sa��ndaki �geler s�ralan�r
    }
	}

