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
   time=time+1;  // o anký zaman býr arttýrýldý
   komsuluk[j][5].zaman_bas=time; // zamanýn baslangýc zamanýný kaydettýk
   komsuluk[j][5].color=11;  // dugumun regý grey yapýldý
   
   int m;
   for(m=0;m<6;m++) // satýr bellý sutunlarda gezerek komsularý bulacaz
   {
   	    if(komsuluk[j][m].deger == 1) // baglantý varsa gýr
   	    {
		   if(komsuluk[m][5].color==10) // komsunun rengý beyazsa gýr
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
	// her býr dugumun rengýne beyaz atýyacaz 
	int i, j;
	int time=0;
	for(i=0;i<6;i++)
	{
		komsuluk[i][5].color=10; // her bir dugumun rengýný beyaz yaptýk
		komsuluk[i][5].ebv=NULL;  // her bir dugumun ebeveynýný null yaptýk
	}
	
	for(j=0;j<6;j++) // sýrayla her býr dugum ýcýn 
	{
		if(komsuluk[j][5].color==10) // rengý beyaz ýse gýr
		{
			DFS_VISIT(komsuluk, j, time);
		}
	}
	
}

/////////////////////////////////////////////////////////////////

int main()
{
	//    white 10      grey 11     black 12      olsun dedeým 
	int i, j;
	struct dugumler komsuluk[6][6];  // matris nesnesýný olusturduk 
	
	// matrisin komsuluklarýný deger degýskenýyle tanýmladýk 
    	
	komsuluk[0][0].deger=0;   komsuluk[0][1].deger=1;   komsuluk[0][2].deger=0;  komsuluk[0][3].deger=1;   komsuluk[0][4].deger=0;  komsuluk[0][5].deger=0;
	komsuluk[1][0].deger=0;   komsuluk[1][1].deger=0;   komsuluk[1][2].deger=0;  komsuluk[1][3].deger=0;   komsuluk[1][4].deger=1;  komsuluk[1][5].deger=0;
	komsuluk[2][0].deger=0;   komsuluk[2][1].deger=0;   komsuluk[2][2].deger=0;  komsuluk[2][3].deger=0;   komsuluk[2][4].deger=1;  komsuluk[2][5].deger=1; 
	komsuluk[3][0].deger=0;   komsuluk[3][1].deger=1;   komsuluk[3][2].deger=0;  komsuluk[3][3].deger=0;   komsuluk[3][4].deger=0;  komsuluk[3][5].deger=0; 
	komsuluk[4][0].deger=0;   komsuluk[4][1].deger=0;   komsuluk[4][2].deger=0;  komsuluk[4][3].deger=1;   komsuluk[4][4].deger=0;  komsuluk[4][5].deger=0;
	komsuluk[5][0].deger=0;   komsuluk[5][1].deger=0;   komsuluk[5][2].deger=0;  komsuluk[5][3].deger=0;   komsuluk[5][4].deger=0;  komsuluk[5][5].deger=1;
	
	
						 
	komsuluk[0][5].isim=4; 	  komsuluk[1][5].isim=5;   komsuluk[2][5].isim=6;  // matrislere sayýlarla ýsým verdým
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
