/*Simran Kaur */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>



// Define statements:
#define LINEAR 1
#define FORM 0




// Constant TAX value:
const double TAX = 0.13;




// Item structure:
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};




// Function Prototypes Milestone 1:
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void pause(void);
void flushKeyboard(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int yes(void);






// Function Prototypes Milesone 2:
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);








// Function Implementations Milestone 1:
void welcome(void)                                                            // function definitions
{
	printf("---=== Grocery Inventory System ===--- \n\n");
}


void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| QTY | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---");
}


void printFooter(double gTotal)
{
	printf("\n--------------------------------------------------------+----------------\n");
	if (gTotal > 0)
	{
		printf("\n                                           Grand Total: |%12.2lf ", gTotal);
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







// Function Implementations Milestone 2:
double totalAfterTax(struct Item item)
{
	double totalPrice = 0;
	if (item.isTaxed == 0) 
	{
		totalPrice = item.price * item.quantity;
		return totalPrice;
	}
    else if (item.isTaxed == 1) 
	{
		totalPrice = item.price * item.quantity;
		totalPrice = totalPrice + (totalPrice * TAX);
		item.isTaxed = 1;
		return totalPrice;
	}
}


int isLowQuantity(struct Item item)
{
	if (item.quantity < item.minQuantity)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


struct Item itemEntry(int sku) {
	struct Item itemEntry;
	itemEntry.sku = sku;
	printf("        SKU: %d", sku);
	printf("\n");
	printf("       Name: ");
	scanf("%20[^\n]", itemEntry.name);
	flushKeyboard();
	printf("      Price: ");
	itemEntry.price = getDouble();
	printf("   Quantity: ");
	itemEntry.quantity = getInt();
	printf("Minimum Qty: ");
	itemEntry.minQuantity = getInt();
	printf("   Is Taxed: ");
	itemEntry.isTaxed = yes();
	return itemEntry;
}


void displayItem(struct Item item, int linear)
{
	int i;
	if (linear == 1)
	{
		double j;
		j = totalAfterTax(item);
		printf("|%3d|%20s|%8.2lf|%3d|%3d|%3d|%12.2lf|", item.sku, item.name, item.price, item.isTaxed, item.quantity, item.minQuantity, j);
		i = isLowQuantity(item);
		if (i == 1 || item.isTaxed == 'Yes')
		{
			printf("|***");
		}
	}

	else
	{
		printf("             SKU: %d\n", item.sku);
		printf("            Name: %s\n", item.name);
		printf("           Price: %lf\n", item.price);
		printf("        Quantity: %d\n", item.quantity);
		printf("Minimum Quantity: %d\n", item.minQuantity);
		printf("        Is Taxed: %d\n", item.isTaxed);
		i = isLowQuantity(item);
		if (i = 1 && item.isTaxed == 'yes')
		{
			printf("WARNING: Quantity low, please order ASAP!!!");

		}
	}

}


void listItems(const struct Item item[], int NoOfItems)
{
	int c = 0;
	double gTotal = 0;
	printTitle();
	while (c < NoOfItems)
	{
		gTotal = gTotal + totalAfterTax(item[c]);
		for (c = 0; c < NoOfItems; c++)
		{
			printf("\n%4d", c + 1);
			displayItem(item[c], LINEAR);
		}
		
	}
	printFooter(gTotal);
}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int count = 0, temp = 0;
	while (count < NoOfRecs)
	{
	    if (item[count].sku == sku)
		{
			*index = count;
			temp = 1;

		}

		count++;
	}
	return temp;
}

