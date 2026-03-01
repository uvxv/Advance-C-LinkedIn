#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

struct stock {
	char symbol[8]; // symbol string
	int quantity;
	float price;
	struct stock *next;
};

/* open a saved database */
void open(void) {}

/* output the portfolio */
void list(void) {}

/* create a new node/record */
struct stock * add(void) {
	struct stock *stk;

	stk = (struct stock *)malloc(sizeof( struct stock));
	if (stk == NULL){
		fprintf(stderr,"[malloc] fail to allocate memory");
		exit(1);
	}

	printf("stock symbol: ");
	scanf("%s", stk->symbol);
	printf("Number of shares: ");
	scanf("%d", &stk->quantity);
	printf("Price: ");
	scanf("%f", &stk->price);
	stk->next = NULL;

	puts("[info] node created");
	return(stk);
}

/* edit an existing node */
void edit(void) {}

/* remove a node */
void delete(void) {}

/* save the database */
void save(void) {}

int main()
{
	struct stock *portfolio,*current;
	int done,c;

	done = FALSE;
	while(!done)
	{
		/* output menu */
		puts("Stock Portfolio");
		puts("1. Open portfolio");
		puts("2. List portfolio");
		puts("3. Add stock");
		puts("4. Edit stock");
		puts("5. Delete stock");
		puts("6. Save portfolio");
		puts("9. Quit");
		printf("Choice: ");
		scanf("%d",&c);

		/* process input */
		switch(c)
		{
			case 1:
				open();
				break;
			case 2:
				list();
				break;
			case 3:
				if( portfolio == NULL ){
					portfolio = add();
				}
				else{
					current = portfolio;
					while(current->next)
						current = current->next;
					current->next = add();
				}
				break;
			case 4:
				edit();
				break;
			case 5:
				delete();
				break;
			case 6:
				save();
				break;
			case 9:
				done = TRUE;
				break;
			default:
				puts("? Unknown command");
		}
	}

	/* clean-up */
	return 0;
}
