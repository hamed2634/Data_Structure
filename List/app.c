#include "app.h"

int main(){
	List l;
	int exit = 0;
	Initialize_List(&l);
	printf("List Is Initialized!\n");
	while(1){
		printf("\nChoose An Operation: \n"
			   "1- Insert Element\n"
			   "2- Delete Element\n"
			   "3- Get Element\n"
			   "4- Replace Element\n"
			   "5- Check If empty\n"
			   "6- Print The Size\n"
			   "7- Traverse The List\n"
			   "8- Destroy The List\n"
			   "9- Exit Program\n");
		int operation;
		string_to_int(takestring_v2(), &operation);
		int times = 0;
		ListEntry val;
		int index, num;
		switch(operation){
			case 1:
				getnumber("Enter Number of Elements You want To Insert: ",MAX_TRIES, &times);
				if(times + List_Size(&l) > MAX_SIZE){
					printf("There Aren't %d Free Spaces In The List!\n", times);
					break;
				}
				while(times != invalid && times > 0 && times--){
					
					getnumber("Enter The Index: ",MAX_TRIES, &index);
					getnumber("Enter Element To Insert: ", MAX_TRIES, &num);
					
					val.intger = num;
					Error State = Insert(index, val,&l);
					if(State == Error1){
						printf("Index Is Out Of The Range!\n");
					}
					else if(State == Error2){
						printf("The List Is Full!\n");
					}
					else if(State == Error3){
						printf("Cannot Allocate Size!\n");
					}
					else if(State == Valid){
						printf("%d Was Inserted at Index %d Successfully!\n", num,index);
					}
				}
				break;
			case 2:
				if(!List_Empty(&l)){
					getnumber("Enter The Index: ",MAX_TRIES, &index);
					
					Error State = Delete(index, &val, &l);
					if(State == Error1){
						printf("Index Is Out Of The Range!\n");
					}
					else if(State == Error3){
						printf("Error When Allocating!\n");
					}
					else if(State == Valid){
					printf("\n%d Was Deleted From List Successfully!\n", val);
					}
				}
				else{
					printf("\nList Is Empty!\n");
				}
				break;
			case 3:
				if(!List_Empty(&l)){
					getnumber("Enter The Index: ",MAX_TRIES, &index);
					
					Error State = Get(index, &val, &l);
					if(State == Error1){
						printf("Index Is Out Of The Range!\n");
					}
					else if(State == Valid){
						printf("\nValue At Index %d = %d\n",index, val);
					}
					
				}
				else{
					printf("\nList Is Empty!\n");
				}
				break;
			case 4:
				getnumber("Enter Number of Elements You want To Replace: ",MAX_TRIES, &times);
				if(times > List_Size(&l)){
					printf("There Aren't %d Element In The List!\n", times);
					break;
				}
				while(times != invalid && times > 0 && times--){
					getnumber("Enter The Index: ",MAX_TRIES, &index);
					getnumber("Enter The New Element: ", MAX_TRIES, &num);
					
					val.intger = num;
					Error State = Replace(index, val,&l);
					if(State == Error1){
						printf("Index Is Out Of The Range!\n");
					}
					else if(State == Error3){
						printf("Error When Allocating!\n");
					}
					else if(State == Valid){
						printf("Element At Index %d Was Replaced With %d Successfully!\n", index,num);
					}
					
				}
				break;
			case 5:
				if(!List_Empty(&l)){
					printf("\nList Isn't Empty!\n");
				}
				else{
					printf("\nList Is Empty!\n");
				}
				break;
			case 6:
				printf("\nThe Size Of The List = %d\n", List_Size(&l));
				break;
			case 7:
				if(List_Empty(&l)){
					printf("\nList Is Empty!\n");
					break;
				}
				printf("\nPrinting The List Elements..\n");
				Traverse_List(&l, &display);
				break;
			case 8:
				if(List_Empty(&l)){
					printf("\nList Is Empty!\n");
					break;
				}
				Destroy_List(&l);
				printf("\nList Destroyed Successfully!\n");
				break;
			case 9:
				exit = 1;
				break;
			default:
				printf("\nInvalid Choice!\n");
		}
		if(exit){
			Destroy_List(&l);
			printf("\nList Destroyed Successfully!\n");
			break;
		}
	}
	return 0;
}
