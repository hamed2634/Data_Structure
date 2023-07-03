#include "app.h"

int main(){
	Stack s;
	Initialize_Stack(&s);
	printf("\nStack Is Initialized!\n");
	while(1){
		printf("\nChoose An Operation: \n"
			   "1- Push Element\n"
			   "2- Pop Element\n"
			   "3- Print Top\n"
			   "4- Check If empty\n"
			   "5- Print The Size\n"
			   "6- Traverse The Stack\n"
			   "7- Clear The Stack\n");
		int operation = string_to_int(takestring_v2());
		StackEntry e;
		switch(operation){
			case 1:
				printf("\nEnter Number of Elements You want To Push: ");
				int times = string_to_int(takestring_v2());
				while(times--){
					printf("\nEnter Element To Push: ");
					int val = string_to_int(takestring_v2());
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
			default:
				printf("\nInvalid Choice!\n");
		}
	}
	getchar();
	return 0;
}
