#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0
typedef struct stock stock;

struct stock
{
	char symbol[8]; // symbol string
	int quantity;
	float price;
	struct stock *next;
};

/* open a saved database */
stock *open(void)
{
	stock *base, *current; // base poiter and the looper
	FILE *fh;
	int count = 0;

	base = NULL; // init
	fh = fopen("saved", "r");
	if (fh == NULL)
	{
		fprintf(stderr, "unable to open the file\n");
		return (NULL);
	}

	while (!feof(fh)) // an eof tracker for given stream
	{
		if (base == NULL)
		{ // first record
			base = malloc(sizeof(stock));
			current = base;

			if (base == NULL) // error check
			{ 
				fprintf(stderr, "unable to allocate memory\n");
				exit(1);
			}

			if (fread(base, sizeof(stock), 1, fh) == 0)
			{ // if no data read
				puts("file is empty\n");
				free(base);
				return NULL;
			}

			count++;
		}
		else // if not the first record
		{
			if (current->next == NULL) // check if any mem address present before
				break;

			current->next = malloc(sizeof(stock));
			if (current->next == NULL)
			{
				fprintf(stderr, "Unable to allocate mem\n");
				exit(1);
			}

			// read the next data to current->next
			fread(current->next, sizeof(stock), 1, fh);
			current = current->next;
			count++;
		}
	}

	printf("%d records read\n\n", count);
	fclose(fh);
	return (base);
}

/* output the portfolio */
void list(stock *node_ptr)
{
	if (node_ptr == NULL)
	{
		puts("Lists empty\n");
		return;
	}

	puts("List Portfolio");
	printf("%-8s%7s%10s%12s\n", "Stock", "Shares", "Price", "Value");

	while (node_ptr)
	{
		printf("%-8s%7d%10.2f%12.2f\n",
					 node_ptr->symbol,
					 node_ptr->quantity,
					 node_ptr->price,
					 node_ptr->quantity * node_ptr->price);

		node_ptr = node_ptr->next;
	}

	putchar('\n');
}

/* create a new node/record */
stock *add(void)
{
	stock *stk;

	stk = (stock *)malloc(sizeof(stock));
	if (stk == NULL)
	{
		fprintf(stderr, "[malloc] fail to allocate memory");
		exit(1);
	}

	printf("stock symbol: ");
	scanf("%s", stk->symbol);
	printf("Number of shares: ");
	scanf("%d", &stk->quantity);
	printf("Price: ");
	scanf("%f", &stk->price);
	stk->next = NULL;

	puts("[info] node created\n");
	return (stk);
}

/* edit an existing node */
void edit(void) {}

/* remove a node */
stock *delete(stock *ptr)
{
	char scan[8];
	stock *base, *previous;

	if (ptr == NULL)
	{
		puts("List is empty\n");
		return (ptr);
	}

	// init ptrs
	base = previous = ptr;

	// ask which sym to delete
	list(ptr);
	printf("chose the symbol to remove: ");
	scanf("%s", scan);

	while (ptr)
	{ // Here we loop usign ptr and not base
		if (strcmp(ptr->symbol, scan) == 0)
		{ // mathched
			printf("%-8s%7d%10.2f%12.2f\n",
						 ptr->symbol,
						 ptr->quantity,
						 ptr->price,
						 ptr->quantity * ptr->price);

			printf("Delete (Y/N)? ");
			scanf("%s", scan);

			if (scan[0] == 'y' || scan[0] == 'Y')
			{
				// check for the first record
				if (ptr == base)
				{
					base = ptr->next;
					free(ptr);
					puts("record deleted\n");
					return (base);
				}
				else
				{ // no the first record
					previous->next = ptr->next;
					free(ptr);
					puts("Record deleted\n");
					return (base);
				}
			}
			else
			{ // select no
				puts("Record retained\n");
				return (base);
			}
		}
		previous = ptr;
		ptr = ptr->next;
	}
	printf("Stock symbol '%s' not found\n\n", scan);
	return (base);
}

/* save the database */
void save(stock *base_ptr)
{
	FILE *fh;

	if (base_ptr == NULL)
	{
		puts("List empty\n");
		return;
	}

	fh = fopen("saved", "w");
	// use $hexdump -C saved
	if (fh == NULL)
	{
		fprintf(stderr, "Unable to create the save file\n");
		return;
	}

	while (base_ptr)
	{
		fwrite(base_ptr, sizeof(stock), 1, fh);
		base_ptr = base_ptr->next;
	}

	fclose(fh);
	puts("Data written\n");
}

int main()
{
	stock *portfolio, *current;
	int done, c;

	done = FALSE;
	while (!done)
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
		scanf("%d", &c);

		/* process input */
		switch (c)
		{
		case 1:
			portfolio = open(); // newly extracted and genrated LL from the file1
			break;
		case 2:
			list(portfolio);
			break;
		case 3:
			if (portfolio == NULL)
			{
				portfolio = add();
			}
			else
			{
				current = portfolio;
				while (current->next)
					current = current->next;
				current->next = add();
			}
			break;
		case 4:
			edit();
			break;
		case 5:
			portfolio = delete(portfolio);
			break;
		case 6:
			save(portfolio);
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
