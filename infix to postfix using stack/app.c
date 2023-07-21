#include "app.h"

int main(){
	Stack st;
	int exit = 0;
	Initialize_Stack(&st);
	int priority[100];
	priority['+'] = priority['-'] = 0;
	priority['*'] = priority['/'] = 1;
	priority['^'] = 2;
	printf("\nThis Program Convert Infix Expressions To Postfix Expressions\n");
	while(!exit){
		printf("\nPlease Enter A Valid Infix Expression: ");
		char* infix = takestring_v2();
		char* postfix = (char *)malloc(strlen(infix + 1));
		int postfix_ind = 0;
		for(int i = 0; i < strlen(infix); ++i){
			if(infix[i] == ')'){
				char c;
				while(!Stack_Empty(&st) && Top(&st) != '('){
					Pop(&c,&st);
					postfix[postfix_ind] = c;
					postfix_ind++;
				}
				Pop(&c,&st);
			}
			else{
				if(infix[i] == '('){
					Push(&st, infix[i]);
				}
				else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^'){
					while(!Stack_Empty(&st) && Top(&st) != '(' && priority[infix[i]] <= priority[Top(&st)]){
						char c;
						Pop(&c,&st);
						postfix[postfix_ind] = c;
						postfix_ind++;
					}
					Push(&st, infix[i]);
				}
				else {
					postfix[postfix_ind] = infix[i];
					postfix_ind++;
				}	
			}
		}
		while(!Stack_Empty(&st)){
			char c;
			Pop(&c,&st);
			postfix[postfix_ind] = c;
			postfix_ind++;
		}
		
		printf("The Postfix Expression:- \n%s\n",postfix);
		printf("Do You Want To Convert Another Expression?\nEnter 'y' For Yes and Anything To Exit: ");
		char* choice = takestring_v2();
		if(strcmp(choice,"y")){
			exit = 1;
			Clear_Stack(&st);
		}	
	}
	return 0;
}
