#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define boyut 20
/////////////////////////////////////////////////////////////////////

struct dugumler{ // dugumler i�in verilen ozell�kler
	int dugum_deger; // dugumun say�s�
	int deger; // yol
	int ebv;  // dugumun ebeveyni
	int isim; //  dugum �s�mler�
	
};

///////////////////////////////////////////////////////////////////
struct dugumler *RELAX(struct dugumler komsuluk[5][5], int q, int w)// q=u baslang�c w=v b�t�s
{
	
	if(komsuluk[w][0].dugum_deger >  komsuluk[q][0].dugum_deger +  komsuluk[q][w].deger )
	{
		komsuluk[w][0].dugum_deger = komsuluk[q][0].dugum_deger + komsuluk[q][w].deger;
		komsuluk[w][0].ebv = komsuluk[q][0].isim ;
	}
	
}


//////////////////////////////////////////////////////////////////

struct dugumler *INITIALIZE_SINGLE_SOURCE(struct dugumler komsuluk[5][5], struct dugumler *start)  // bu fonks�yon matr�s� i�leme haz�rlar 
{
    int m;
    for(m=0;m<5;m++)
    {
    	komsuluk[m][0].dugum_deger=1000; // tum dugum degerler�ne 1000 verd�m
    	komsuluk[m][0].ebv=NULL;  
	}
	komsuluk[0][0].dugum_deger=0; //  baslang�c dugumun say�s�na 0 verd�m 

}

///////////////////////////////////////////////////////////////////
// maliyeti en kucuk olan dugumu bulma
int extract_min(struct dugumler komsuluk[5][5], int Q[])
{	
	int kucuk1=100;
	int q, m, i, z;
	
	    for(q=0;q<5;q++)  // sat�r  q
        {
        	m=Q[q]; // indisteki dugum �sm�n� m e att�k
        	for(i=0;i<5;i++)
        	{
        		if( komsuluk[i][0].isim== m)
        		{
        			z=i;
				}
				
				if( komsuluk[i][0].isim== m)
        		{
        			
        			if( komsuluk[z][0].dugum_deger <= kucuk1)
        	        {
        		        kucuk1=komsuluk[z][0].dugum_deger;
			        }
				}
				
			}
			
		}	

	return kucuk1;
	

}

//////////////////////////////////////////////////////////////////
// kuyruga ekleme fonks�yonu
int enqueue(int Q[], int x, int tail)  //ekleme  (kuyruk, eklenecek_sayi, tail_degeri)
{
	Q[tail]=x;
	if(tail==boyut)
	{
		tail=0;
		return tail;
	}
	else
	{
		tail=tail+1;
		return tail;
	}
}
////////////////////////////////////////////////////////////////////
// kuyruktan c�karma fons�yonu

int dequeue(int Q[], int head, int u) // c�karma
{
	int m=head;
	int x=head;
    int d;
    
    for(d=x;d>=0;d--)
    {
    	if(Q[x]==u)
    	{
    		m=m-1;
    		return m;
		}
	}
    
	
}

//////////////////////////////////////////////////////////////////

struct dugumler *DIJKSTRA(struct dugumler komsuluk[5][5], struct dugumler *start)
{
	int t;
	int k;
	int u;
	int i;
	int q, w;
	int head=0;   //c�karma 
	int tail=0;   //ekleme
	
    INITIALIZE_SINGLE_SOURCE(komsuluk, start);  // fonks�yona graf� ve kaynak dugumu yollad�m 
    
    int S[boyut]; // bir dizi olusturuldu
    int Q[boyut]; // kuyruk d�z�n�de olusturuldu
    
    for(i=0;i<5;i++)  // kuyruga isimleri ile dugumleri ekliyoruz
    {
    	tail=enqueue(Q,komsuluk[i][0].isim,tail);
	}
	
	//kuyrukta kalanlar�n mal�yet�ne bak�l�r 
	// kuyruktan mal�yet� kucuk olan s�l�n�r ve onceden bakt�g�m�z d�z�ye eklen�r 
	// kuyruktan s�ld�m�z�n komsular�na bakmaya baslar�z onlanda �s b�t�nce oda d�z�ye eklen�r 
	// sonunda kuyruk bosal�r d�z�dede mal�yet� kucuk olanlar s�rada olmus olur 


    for(t=0;t<5;t++)  
    {
        if(Q[t]!=NULL)  // kuyruk doluysa gir
        {
        		u=extract_min(komsuluk, Q); // kuyruktak� en kucuk degerli  dugumuun degerini bulduk
    	
    	        for(k=0;k<5;k++) // yukardan c�kan u deger b�z�m tekrardan ism�ne ulasmak �c�n dongu yapt�m
    	        {
    		        if(komsuluk[k][0].dugum_deger == u)
    		        {
    			        u = komsuluk[k][0].isim;
			        }
		        }
		        
		        head=dequeue(Q,head,u); // u �sm�n� kuyruktan s�ldik
    	        
    	        int r;
    	        for(r=0;r<6;r++)
    	        {
    	        	if(S[r] == NULL)
    	        	{
    	        		S[r]=u; // en kucuk degerl� olan� d�z�m�ze ekled�k ekleye ekleye en sonra d�z�de en ucuz yol olmus olacak
					}
				}
    	        
    	         
    	        for(q=0;q<5;q++)
    	        {
    	        	if( komsuluk[q][0].isim == u )  // ismimizin sat�r� bulundu
    	        	{
    	        		for(w=0;w<5;w++)
    	        		{
    	        			if(komsuluk[q][w].deger != 0)
    	        			{
    	        				RELAX(komsuluk, q, w);
							}
						}
					}
				}
    	        
    	
		}
		
	}
	
	
    printf("%d\n", head);
    
    
    
}

/////////////////////////////////////////////////////////////////

int main()
{
	
	struct dugumler komsuluk[5][5];  // matris nesnes�n� olusturduk 
	 
	
	// matrisin komsuluklar�n� deger deg�sken�yle tan�mlad�k 
    	
	komsuluk[0][0].deger=0;   komsuluk[0][1].deger=10;  komsuluk[0][2].deger=0;  komsuluk[0][3].deger=0;   komsuluk[0][4].deger=5;  
	komsuluk[1][0].deger=0;   komsuluk[1][1].deger=0;   komsuluk[1][2].deger=1;  komsuluk[1][3].deger=0;   komsuluk[1][4].deger=2; 
	komsuluk[2][0].deger=0;   komsuluk[2][1].deger=0;   komsuluk[2][2].deger=0;  komsuluk[2][3].deger=4;   komsuluk[2][4].deger=0; 
	komsuluk[3][0].deger=7;   komsuluk[3][1].deger=0;   komsuluk[3][2].deger=6;  komsuluk[3][3].deger=0;   komsuluk[3][4].deger=0;
	komsuluk[4][0].deger=0;   komsuluk[4][1].deger=3;   komsuluk[4][2].deger=9;  komsuluk[4][3].deger=2;   komsuluk[4][4].deger=0; 

	
    // 0= s  /  1= t /  2= x  /  3= z  / 4= y  sekl�nde �s�mler� say�lara e�ledim
				 
	komsuluk[0][0].isim=0; 	  komsuluk[1][0].isim=1;   komsuluk[2][0].isim=2;
	komsuluk[3][0].isim=3;    komsuluk[4][0].isim=4; 
	
	komsuluk[0][0].ebv=0; 	  komsuluk[1][0].ebv=0;   komsuluk[2][0].ebv=0;
	komsuluk[3][0].ebv=0;    komsuluk[4][0].ebv=0; 
	// fonks�yona matrisi yollad�k ve baslang�c matrisin sat�r sutununu yollad�k
     
    struct dugumler *start;
    start=&komsuluk[0][0];
	
	
    DIJKSTRA(komsuluk, start); 
     
    
  
  
}
