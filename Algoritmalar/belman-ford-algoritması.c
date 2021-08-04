#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

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

//////////////////////////////////////////////////////////////////

struct dugumler *BELMAN_FORD(struct dugumler komsuluk[5][5], struct dugumler *start)
{
	
	int q;
	int w;
	int u;
	int i, j;
	
    INITIALIZE_SINGLE_SOURCE(komsuluk, start);  // fonks�yona graf� ve kaynak dugumu yollad�m 
    
    for(u=0;u<4;u++) // dugum say�s�n�n bir eks�ne kadar g�t
    {
        for(q=0;q<5;q++)  // sat�r  q
        {
        	for(w=0;w<5;w++) // sutun w
        	{
        		
			    if(komsuluk[q][w].deger != 0)  // yol varsa gir
				{
				    RELAX(komsuluk, q, w);  //  hedefe ulasmak yol masraf�n� hesaplayarak k�sa yolu bulur 
				}
			    
			}
		}
	}

	
	//////////////tum kenarlar �c�n 
	
	    for(q=0;q<5;q++)  // sat�r  q
        {
        	for(w=0;w<5;w++) // sutun w
        	{
        		if(komsuluk[q][w].deger != 0) // burda bir yol varsa
        		{
        			if(komsuluk[w][0].dugum_deger >  komsuluk[q][0].dugum_deger +  komsuluk[q][w].deger )
	                {
	                        return 0;  // false
	                }
				}
			    
			}
		}
	return 1; // true
	
    
}

/////////////////////////////////////////////////////////////////

int main()
{
	
	struct dugumler komsuluk[5][5];  // matris nesnes�n� olusturduk 
	 
	
	// matrisin komsuluklar�n� deger deg�sken�yle tan�mlad�k 
    	
	komsuluk[0][0].deger=0;   komsuluk[0][1].deger=6;   komsuluk[0][2].deger=0;  komsuluk[0][3].deger=0;   komsuluk[0][4].deger=7;  
	komsuluk[1][0].deger=0;   komsuluk[1][1].deger=0;   komsuluk[1][2].deger=5;  komsuluk[1][3].deger=(-4);   komsuluk[1][4].deger=8; 
	komsuluk[2][0].deger=0;   komsuluk[2][1].deger=(-2);   komsuluk[2][2].deger=0;  komsuluk[2][3].deger=0;   komsuluk[2][4].deger=0; 
	komsuluk[3][0].deger=2;   komsuluk[3][1].deger=0;   komsuluk[3][2].deger=7;  komsuluk[3][3].deger=0;   komsuluk[3][4].deger=0;
	komsuluk[4][0].deger=0;   komsuluk[4][1].deger=0;   komsuluk[4][2].deger=(-3);  komsuluk[4][3].deger=9;   komsuluk[4][4].deger=0; 

	
    // 0= s  /  1= t /  2= x  /  3= z  / 4= y  sekl�nde �s�mler� say�lara e�ledim
				 
	komsuluk[0][0].isim=0; 	  komsuluk[1][0].isim=1;   komsuluk[2][0].isim=2;
	komsuluk[3][0].isim=3;    komsuluk[4][0].isim=4; 
	
	komsuluk[0][0].ebv=0; 	  komsuluk[1][0].ebv=0;   komsuluk[2][0].ebv=0;
	komsuluk[3][0].ebv=0;    komsuluk[4][0].ebv=0; 
	// fonks�yona matrisi yollad�k ve baslang�c matrisin sat�r sutununu yollad�k
     
    struct dugumler *start;
    start=&komsuluk[0][0];
	
	int sonuc;
    sonuc=BELMAN_FORD(komsuluk, start); 
    
    //////////////////////////////////////////////
    
    int c, f;
    if(sonuc==1)
    {
    	printf("hesaplanabildi:\n");
    	printf("ispat olarak dugumlerin ebeveynlerini ekrana bastiriyorum:\n");
    	printf("(0=s, 1=t, 2=x, 3=z, 4=y olarak kodlanmistir)\n");
    	printf("(ilk sifir NULL dur sikinti cikardigi icin ben sifir yaptim)\n");
    	for(c=0;c<5;c++)
		{
			printf("\n%d\n", komsuluk[c][0].ebv );
		}
	}
	if(sonuc==0)
	{
		printf("\nhesaplanamaz");
	}
   
  
}
