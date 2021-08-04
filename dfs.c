#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/////////////////////////////////////////////////////////////////////

struct dugumler{
	int deger;
	int color;
	int ebv;
	int isim;
	int zaman_bas;
	int zaman_son;
};

//////////////////////////////////////////////////////////////////

struct dugumler *DFS_VISIT(struct dugumler komsuluk[6][6], int j, int time)
{
   time=time+1;  // o ank� zaman b�r artt�r�ld�
   komsuluk[j][5].zaman_bas=time; // zaman�n baslang�c zaman�n� kaydett�k
   komsuluk[j][5].color=11;  // dugumun reg� grey yap�ld�
   
   int m;
   for(m=0;m<6;m++) // sat�r bell� sutunlarda gezerek komsular� bulacaz
   {
   	    if(komsuluk[j][m].deger == 1) // baglant� varsa g�r
   	    {
		   if(komsuluk[m][5].color==10) // komsunun reng� beyazsa g�r
		   {
		        komsuluk[m][5].ebv=	komsuluk[j][5].isim;
		        DFS_VISIT(komsuluk, m, time);
		   } 
		}
   }
   
   komsuluk[j][5].color=12;
   time=time+1;
   komsuluk[j][5].zaman_son=time;
   
   
}


//////////////////////////////////////////////////////////////////

struct dugumler *DFS(struct dugumler komsuluk[6][6])
{
	// her b�r dugumun reng�ne beyaz at�yacaz 
	int i, j;
	int time=0;
	for(i=0;i<6;i++)
	{
		komsuluk[i][5].color=10; // her bir dugumun reng�n� beyaz yapt�k
		komsuluk[i][5].ebv=NULL;  // her bir dugumun ebeveyn�n� null yapt�k
	}
	
	for(j=0;j<6;j++) // s�rayla her b�r dugum �c�n 
	{
		if(komsuluk[j][5].color==10) // reng� beyaz �se g�r
		{
			DFS_VISIT(komsuluk, j, time);
		}
	}
	
}

/////////////////////////////////////////////////////////////////

int main()
{
	//    white 10      grey 11     black 12      olsun dede�m 
	int i, j;
	struct dugumler komsuluk[6][6];  // matris nesnes�n� olusturduk 
	
	// matrisin komsuluklar�n� deger deg�sken�yle tan�mlad�k 
    	
	komsuluk[0][0].deger=0;   komsuluk[0][1].deger=1;   komsuluk[0][2].deger=0;  komsuluk[0][3].deger=1;   komsuluk[0][4].deger=0;  komsuluk[0][5].deger=0;
	komsuluk[1][0].deger=0;   komsuluk[1][1].deger=0;   komsuluk[1][2].deger=0;  komsuluk[1][3].deger=0;   komsuluk[1][4].deger=1;  komsuluk[1][5].deger=0;
	komsuluk[2][0].deger=0;   komsuluk[2][1].deger=0;   komsuluk[2][2].deger=0;  komsuluk[2][3].deger=0;   komsuluk[2][4].deger=1;  komsuluk[2][5].deger=1; 
	komsuluk[3][0].deger=0;   komsuluk[3][1].deger=1;   komsuluk[3][2].deger=0;  komsuluk[3][3].deger=0;   komsuluk[3][4].deger=0;  komsuluk[3][5].deger=0; 
	komsuluk[4][0].deger=0;   komsuluk[4][1].deger=0;   komsuluk[4][2].deger=0;  komsuluk[4][3].deger=1;   komsuluk[4][4].deger=0;  komsuluk[4][5].deger=0;
	komsuluk[5][0].deger=0;   komsuluk[5][1].deger=0;   komsuluk[5][2].deger=0;  komsuluk[5][3].deger=0;   komsuluk[5][4].deger=0;  komsuluk[5][5].deger=1;
	
	
						 
	komsuluk[0][5].isim=4; 	  komsuluk[1][5].isim=5;   komsuluk[2][5].isim=6;  // matrislere say�larla �s�m verd�m
	komsuluk[3][5].isim=7;    komsuluk[4][5].isim=8;   komsuluk[5][5].isim=9;		

   
    DFS(komsuluk);
    
    printf("SONUC :\n");
    
    int r;
    printf("\n12 degeri siyahtir\n");
    printf("tum renkler siyah olduysa tum dugumlerde is bitmis demektir kodun ispati kabul edilir\n\n");
    
    for(r=0;r<6;r++)
    {
    	printf("%d\n", komsuluk[r][5].color );
	}
  
  
  
}
