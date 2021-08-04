#include <stdio.h>
#include <stdbool.h>
#define size 10
#define boyut 8

typedef struct q{
	int head;
	int tail;
	int deger[size];
}queue;


void enqueue(queue *Q, int x);

int dequeue(queue *Q);

bool isempty(queue *q);



void enqueue(queue *Q, int x){

	if((Q->tail == Q->head-1)||(Q->tail==size-1 && Q->head==0)) {
		printf("Kuyruk Dolu \n");
		return;
	}
	else Q->deger[Q->tail]=x;
	if(Q->tail==size-1)
		Q->tail=0;
	else Q->tail=Q->tail+1;
	printf("Enqueue: Added: %d   Tail: %d\n",x,Q->tail);
}

int dequeue(queue *Q){
	int x;
	if(Q->head==Q->tail){
		printf("Kuyruk Bos\n");
		return -1;
	}
	x=Q->deger[Q->head];
	if(Q->head==size-1)
		Q->head=0;
	else Q->head=Q->head+1;
	printf("Dequeue: Removed: %d  Head: %d\n", x, Q->head);
	return x;
}


bool isempty(queue *q){
	if(q->head==q->tail) return true;
	else return false;
}




void bfs(int k[boyut][boyut],int s){
	char renkler[boyut][6]={"beyaz","gri","beyaz","beyaz","beyaz","beyaz","beyaz","beyaz"};
	int ebeveyn[boyut]={0};
	int mesafe[boyut]={1000};
	mesafe[s]=0;
	int u=0,v=0,i;
	queue q1;
	queue *p=&q1;
	p->head=0;
	p->tail=0;
	enqueue(p,s);
	while(!isempty(p)){
		u=dequeue(p);
		for(i=0;i<boyut;i++){
			if(k[u][i]==1){
				if(strcmp(renkler[i],"beyaz")==0){
					strcpy(renkler[i],"gri  ");
					mesafe[i]=mesafe[u]+1;
					ebeveyn[i]=u;
					enqueue(p,i);
				}
			}
		}
		strcpy(renkler[u],"siyah");
	}
	printf("\nEBEVEYNLER\n");
	for(i=0;i<boyut;i++){
		printf("%d %d \n", i,ebeveyn[i]);
	}
	printf("\nRENKLER\n");
	for(i=0;i<boyut;i++){
		printf("%d %s\n",i, renkler[i]);
	}
	printf("\nMESAFELER\n");
	for(i=0;i<boyut;i++){
		printf("%d %d\n",i,mesafe[i]);
	}
}

int main(){
	int komsuluk[boyut][boyut]={{0,1,0,0,1,0,0,0},
								{1,0,0,0,0,1,0,0},
								{0,0,0,1,0,1,1,0},
								{0,0,1,0,0,0,1,1},
								{1,0,0,0,0,0,0,0},
								{0,1,1,0,0,0,1,0},
								{0,0,1,1,0,1,0,1},
								{0,0,0,1,0,0,1,0}};
	char renkler[boyut][6]={"beyaz","gri","beyaz","beyaz","beyaz","beyaz","beyaz","beyaz"};
	int ebeveyn[boyut]={0};
	int mesafe[boyut]={1000};
	bfs(komsuluk,1);
}	

