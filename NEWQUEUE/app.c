#include "app.h"

int main(){
	Queue q;
	int exit = 0;
	Initialize_Queue(&q);
	printf("Queue Is Initialized!\n");
	while(1){
		printf("\nChoose An Operation: \n"
			   "1- Push Element\n"
			   "2- Serve Element\n"
			   "3- Print Ftont Element\n"
			   "4- Print Back Element\n"
			   "5- Check If empty\n"
			   "6- Print The Size\n"
			   "7- Traverse The Queue\n"
			   "8- Clear The Queue\n"
			   "9- Exit Program\n");
		int operation = string_to_int(takestring_v2());
		int times = 0;
		QueueEntry e;
		switch(operation){
			case 1:
				times = getnumber("\nEnter Number of Elements You want To Push: ",MAX_TRIES);
				if(times + Queue_Size(&q) > MAX_SIZE){
					printf("There Aren't %d Free Spaces In The Queue!\n",times);
					break;
				}
				while(times != invalid && times > 0 && times--){
					int val = getnumber("\nEnter Element To Push: ",MAX_TRIES);
					Push(&q, val);
				}
				break;
			case 2:
				if(!Queue_Empty(&q)){
					Serve(&e, &q);
					printf("\n%d Is Served From Queue Successfully!\n", e);
				}
				else{
					printf("\nQueue Is Empty!\n");
				}
				break;
			case 3:
				if(!Queue_Empty(&q)){
					printf("\nThe Front = %d\n",Front(&q));
				}
				else{
					printf("\nQueue Is Empty!\n");
				}
				break;
			case 4:
				if(!Queue_Empty(&q)){
					printf("\nThe Back = %d\n",Back(&q));
				}
				else{
					printf("\nQueue Is Empty!\n");
				}
				break;
			case 5:
				if(!Queue_Empty(&q)){
					printf("\nQueue Isn't Empty!\n");
				}
				else{
					printf("\nQueue Is Empty!\n");
				}
				break;
			case 6:
				printf("\nThe Size Of The Queue = %d\n", Queue_Size(&q));
				break;
			case 7:
				if(Queue_Empty(&q)){
					printf("\nQueue Is Empty!\n");
					break;
				}
				printf("\nPrinting The Queue Elements..\n");
				Traverse_Queue(&q, &display);
				break;
			case 8:
				if(Queue_Empty(&q)){
					printf("\nQueue Is Empty!\n");
					break;
				}
				Clear_Queue(&q);
				printf("\nQueue Cleared Successfully!\n");
				break;
			case 9:
				exit = 1;
			default:
				printf("\nInvalid Choice!\n");
		}
		if(exit){
			Clear_Queue(&q);
			break;
		}
	}
	return 0;
}
