/*KAHRAMANMARA� S�TC� �MAM �N�VERS�TES� M�HEND�SL�K VE M�MARLIK FAK�LTES�
                    B�LG�SAYAR M�HEND�SL���
      B��RA YORULMAZ      18110131018        2. SINIF ��RENC�S� */


#include <stdio.h>
#include <stdlib.h>
#define boyut 100

void MaxHeapify(int A[],int i,int heapsize);
void BuildMaxHeap(int A[],int heapsize);
void HeapSort(int A[],int heapsize);


    int main()
    {   
       
	   int i;
       int A[boyut];
	   printf("RANDOM DIZI: \n ");
	   for(i=0;i<boyut;i++)
	   {
	    	A[i]=rand()%100;
		    printf("%d\t ",A[i]);     // Random say�lar ekrana yazd�r�l�r
	   }
	    printf("\n\nHEAP SORT ILE SIRALI DIZI: \n");
	    int heapsize=boyut-1;
	    HeapSort(A,heapsize);  // Heapsort fonksiyonunu �a��rarak s�ralamay� heapsort algoritmas� ile s�ralamas� sa�lan�r
		for(i=0;i<boyut;i++)
	    {
		   printf("%d\t ",A[i]);
	    }
		return 0;		
    }

    void MaxHeapify(int A[],int i,int heapsize)
    {   
	   int largest; 
	   int L=(2*i)+1;
	   int R=(2*i)+2;
	   if(L<=heapsize && A[L]>A[i])
    	{
	    	 largest=L;	
	    }
	    else 
 	    {
		    largest=i;
	    }
	    
	if(R<=heapsize&& A[R]>A[largest])
	{
		largest=R;
	}	
	if(largest!=i)
	{
		int n=A[largest];
		A[largest]=A[i];
		A[i]=n;
		MaxHeapify( A,largest,heapsize);
	}	
    }
   void BuildMaxHeap(int A[],int heapsize)
   {
    	int i;
	    for(i=(heapsize/2);i>=0;i--)
	    {
		   MaxHeapify( A,i,heapsize);
	    }
	
   }

 void HeapSort(int A[],int heapsize)
   {    
       int i,L,n;
	   BuildMaxHeap(A,heapsize);
	   for(i=heapsize;i>=1;i--)
	   {
	    	int temp=A[i];
		    A[i]=A[L];
	        A[L]=temp;
		    heapsize--;
		    MaxHeapify( A,0,heapsize);
	   }
   }

