#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define boyut 20
/////////////////////////////////////////////////////////////////////

struct dugumler{ // dugumler için verilen ozellýkler
	int dugum_deger; // dugumun sayýsý
	int deger; // yol
	int ebv;  // dugumun ebeveyni
	int isim; //  dugum ýsýmlerý
	
};

///////////////////////////////////////////////////////////////////
struct dugumler *RELAX(struct dugumler komsuluk[5][5], int q, int w)// q=u baslangýc w=v býtýs
{
	
	if(komsuluk[w][0].dugum_deger >  komsuluk[q][0].dugum_deger +  komsuluk[q][w].deger )
	{
		komsuluk[w][0].dugum_deger = komsuluk[q][0].dugum_deger + komsuluk[q][w].deger;
		komsuluk[w][0].ebv = komsuluk[q][0].isim ;
	}
	
}


//////////////////////////////////////////////////////////////////

struct dugumler *INITIALIZE_SINGLE_SOURCE(struct dugumler komsuluk[5][5], struct dugumler *start)  // bu fonksýyon matrýsý iþleme hazýrlar 
{
    int m;
    for(m=0;m<5;m++)
    {
    	komsuluk[m][0].dugum_deger=1000; // tum dugum degerlerýne 1000 verdým
    	komsuluk[m][0].ebv=NULL;  
	}
	komsuluk[0][0].dugum_deger=0; //  baslangýc dugumun sayýsýna 0 verdým 

}

///////////////////////////////////////////////////////////////////
// maliyeti en kucuk olan dugumu bulma
int extract_min(struct dugumler komsuluk[5][5], int Q[])
{	
	int kucuk1=100;
	int q, m, i, z;
	
	    for(q=0;q<5;q++)  // satýr  q
        {
        	m=Q[q]; // indisteki dugum ýsmýný m e attýk
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
// kuyruga ekleme fonksýyonu
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
// kuyruktan cýkarma fonsýyonu

int dequeue(int Q[], int head, int u) // cýkarma
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
	int head=0;   //cýkarma 
	int tail=0;   //ekleme
	
    INITIALIZE_SINGLE_SOURCE(komsuluk, start);  // fonksýyona grafý ve kaynak dugumu yolladým 
    
    int S[boyut]; // bir dizi olusturuldu
    int Q[boyut]; // kuyruk dýzýnýde olusturuldu
    
    for(i=0;i<5;i++)  // kuyruga isimleri ile dugumleri ekliyoruz
    {
    	tail=enqueue(Q,komsuluk[i][0].isim,tail);
	}
	
	//kuyrukta kalanlarýn malýyetýne bakýlýr 
	// kuyruktan malýyetý kucuk olan sýlýnýr ve onceden baktýgýmýz dýzýye eklenýr 
	// kuyruktan sýldýmýzýn komsularýna bakmaya baslarýz onlanda ýs býtýnce oda dýzýye eklenýr 
	// sonunda kuyruk bosalýr dýzýdede malýyetý kucuk olanlar sýrada olmus olur 


    for(t=0;t<5;t++)  
    {
        if(Q[t]!=NULL)  // kuyruk doluysa gir
        {
        		u=extract_min(komsuluk, Q); // kuyruktaký en kucuk degerli  dugumuun degerini bulduk
    	
    	        for(k=0;k<5;k++) // yukardan cýkan u deger býzým tekrardan ismþne ulasmak ýcýn dongu yaptým
    	        {
    		        if(komsuluk[k][0].dugum_deger == u)
    		        {
    			        u = komsuluk[k][0].isim;
			        }
		        }
		        
		        head=dequeue(Q,head,u); // u ýsmýný kuyruktan sýldik
    	        
    	        int r;
    	        for(r=0;r<6;r++)
    	        {
    	        	if(S[r] == NULL)
    	        	{
    	        		S[r]=u; // en kucuk degerlý olaný dýzýmýze ekledýk ekleye ekleye en sonra dýzýde en ucuz yol olmus olacak
					}
				}
    	        
    	         
    	        for(q=0;q<5;q++)
    	        {
    	        	if( komsuluk[q][0].isim == u )  // ismimizin satýrý bulundu
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
	
	struct dugumler komsuluk[5][5];  // matris nesnesýný olusturduk 
	 
	
	// matrisin komsuluklarýný deger degýskenýyle tanýmladýk 
    	
	komsuluk[0][0].deger=0;   komsuluk[0][1].deger=10;  komsuluk[0][2].deger=0;  komsuluk[0][3].deger=0;   komsuluk[0][4].deger=5;  
	komsuluk[1][0].deger=0;   komsuluk[1][1].deger=0;   komsuluk[1][2].deger=1;  komsuluk[1][3].deger=0;   komsuluk[1][4].deger=2; 
	komsuluk[2][0].deger=0;   komsuluk[2][1].deger=0;   komsuluk[2][2].deger=0;  komsuluk[2][3].deger=4;   komsuluk[2][4].deger=0; 
	komsuluk[3][0].deger=7;   komsuluk[3][1].deger=0;   komsuluk[3][2].deger=6;  komsuluk[3][3].deger=0;   komsuluk[3][4].deger=0;
	komsuluk[4][0].deger=0;   komsuluk[4][1].deger=3;   komsuluk[4][2].deger=9;  komsuluk[4][3].deger=2;   komsuluk[4][4].deger=0; 

	
    // 0= s  /  1= t /  2= x  /  3= z  / 4= y  seklýnde ýsýmlerý sayýlara eþledim
				 
	komsuluk[0][0].isim=0; 	  komsuluk[1][0].isim=1;   komsuluk[2][0].isim=2;
	komsuluk[3][0].isim=3;    komsuluk[4][0].isim=4; 
	
	komsuluk[0][0].ebv=0; 	  komsuluk[1][0].ebv=0;   komsuluk[2][0].ebv=0;
	komsuluk[3][0].ebv=0;    komsuluk[4][0].ebv=0; 
	// fonksýyona matrisi yolladýk ve baslangýc matrisin satýr sutununu yolladýk
     
    struct dugumler *start;
    start=&komsuluk[0][0];
	
	
    DIJKSTRA(komsuluk, start); 
     
    
  
  
}
