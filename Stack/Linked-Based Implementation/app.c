#include "app.h"

int main(){
	Stack s;
	int exit = 0;
	Initialize_Stack(&s);
	printf("Stack Is Initialized!\n");
	while(1){
		printf("\nChoose An Operation: \n"
			   "1- Push Element\n"
			   "2- Pop Element\n"
			   "3- Print Top\n"
			   "4- Check If empty\n"
			   "5- Print The Size\n"
			   "6- Traverse The Stack\n"
			   "7- Clear The Stack\n"
			   "8- Exit Program\n");
		int operation = string_to_int(takestring_v2());
		int times = 0;
		StackEntry e;
		switch(operation){
			case 1:
				times = getnumber("\nEnter Number of Elements You want To Push: ",MAX_TRIES);
				while(times != invalid && times > 0 && times--){
					int val = getnumber("\nEnter Element To Push: ",MAX_TRIES);
					Push(&s, val);
				}
				break;
			case 2:
				if(!Stack_Empty(&s)){
					Pop(&e, &s);
					printf("\n%d Is Popped From Stack Successfully!\n", e);
				}
				else{
					printf("\nStack Is Empty!\n");
				}
				break;
			case 3:
				if(!Stack_Empty(&s)){
					printf("\nThe Top = %d\n",Top(&s));
				}
				else{
					printf("\nStack Is Empty!\n");
				}
				break;
			case 4:
				if(!Stack_Empty(&s)){
					printf("\nStack Isn't Empty!\n");
				}
				else{
					printf("\nStack Is Empty!\n");
				}
				break;
			case 5:
				printf("\nThe Size Of The Stack = %d\n", Stack_Size(&s));
				break;
			case 6:
				if(Stack_Empty(&s)){
					printf("\nStack Is Empty!\n");
					break;
				}
				printf("\nPrinting The Stack Elements..\n");
				Traverse_Stack(&s, &display);
				break;
			case 7:
				if(Stack_Empty(&s)){
					printf("\nStack Is Empty!\n");
					break;
				}
				Clear_Stack(&s);
				printf("\nStack Cleared Successfully!\n");
				break;
			case 8:
				exit = 1;
			default:
				printf("\nInvalid Choice!\n");
		}
		if(exit){
			Clear_Stack(&s);
			break;
		}
	}
	return 0;
}
