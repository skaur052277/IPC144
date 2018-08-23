/*Simran Kaur */

#include <stdio.h>

// tools
void welcome(void);                                                   // function prototypes

void printTitle(void);

void printFooter(double gTotal);

void flushKeyboard(void);

void pause(void);

int getInt(void);

double getDouble(void);

int getIntLimited(int lowerLimit, int upperLimit);

double getDoubleLimited(double lowerLimit, double upperLimit);


// app interface
int yes(void);

void GroceryInventorySystem(void);

int menu(void);


void welcome(void)                                                            // function definitions
{
	printf("---=== Grocery Inventory System ===--- \n\n");
}


void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| QTY | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}


void printFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
	{
		printf("                                           Grand Total: |%12.2lf \n", gTotal);
	}
}


void flushKeyboard(void)
{
	while (getchar() != '\n');
}


void pause(void)
{
	printf("Press <ENTER> to continue... ");
	flushKeyboard();
}


int getInt(void)
{
	int a = 0, c = 0, no;
	char ch;
	do
	{
		scanf("%d%c", &no, &ch);
		if (ch == '\n')
		{
			c = no;
			a = 1;
			break;
		}
		else
		{
			printf("Invalid integer, please try again: ");
			flushKeyboard();
		}
	} while (a == 0);
	return c;
}


int getIntLimited(int lowerLimit, int upperLimit)
{
	int value;
	scanf("%d", &value);
	while (value < lowerLimit || value > upperLimit)
	{
		printf("Invalid value, 10 < value < 20: ");
		scanf("%d", &value);
	}
	return value;
}


double getDouble()
{
	int a = 0;
	double val, p;
	char ch;
	while (a == 0)
	{
		if (scanf("%lf%c", &val, &ch) != 2 || ch != '\n')
		{
			printf("Invalid number, please try again: ");
			flushKeyboard();
		}
		else
		{
			p = val;
			a = 1;
		}
	}
	return p;
}


double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double n1;
	scanf("%lf", &n1);
	while (n1 < lowerLimit || n1 > upperLimit)
	{
		printf("Invalid value, 10.000000< value < 20.000000: ");
		scanf("%lf", &n1);
	}
	return n1;
}


int yes(void)
{
	int a = 0, h;
	char ch;
	printf("Exit the program? (Y)es/(N)o: ");
	while (a == 0)
	{
		scanf("%c", &ch);
		if (ch == 'Y' || ch == 'y')
		{
			a = 1;
			h = 1;
		}
		else if (ch == 'N' || ch == 'n')
		{
			a = -1;
			h = 0;
		}
		else
		{
			printf("Only (Y)es or(N)o are acceptable: ");
			flushKeyboard();
		}
	}

	return h;
}


int menu(void)
{
	int choice;
	int x = 0, p = 0;
	while (x == 0) {
		printf("\n1- List all items");
		printf("\n2- Search by SKU");
		printf("\n3- Checkout an item");
		printf("\n4- Stock an item");
		printf("\n5- Add new item or update item");
		printf("\n6- delete item");
		printf("\n7- Search by name");
		printf("\n0- Exit program");
		printf("\n>");
		scanf("%d", &choice);
		if (choice < 0 || choice > 7)
		{
			printf("Invalid value, 0 < value < 7: ");
			scanf("%d", &choice);
		}
		else
		{
			p = choice;
			x = 1;
		}
	}
	return p;
}


void GroceryInventorySystem(void)
{
	int ar = 1;
	welcome();
	while (ar == 1) {
		int option = menu();

		switch (option)
		{
		    case 0: { int i;
			          flushKeyboard();
			          i = yes();
			          if (i == 1)
			          {
				        ar = 0;
				        break;
			          }
		            }

		    case 1: { printf("List Items under construction!\n");
			          flushKeyboard();
			          break; }

		    case 2: { printf("Search Items under construction!\n");
			          flushKeyboard();
			          break; }

  		    case 3: { printf("Checkout Item under construction!\n");
			          flushKeyboard();
			          break; }

		    case 4: { printf("Stock Item under construction!\n");
			          flushKeyboard();
			          break; }

		    case 5: { printf("Add/Update Item under construction!\n");
		 	          flushKeyboard();
			          break; }

		    case 6: { printf("Delete Item under construction!\n");
			          flushKeyboard();
			          break; }

		    case 7: { printf("Search by name under construction!\n");
			          flushKeyboard();
			          break; }

		    default: { break; }
		 }
		if (ar == 1)
		{ pause(); }
	}
}
