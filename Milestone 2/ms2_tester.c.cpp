/*Simran Kaur*/

#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define LINEAR 1
#define FORM 0

const double TAX = 0.13;

/* ms1*/
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

/* ms2*/
struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);




int main() {
	struct Item I[21] = {
		{ 4.4,275,0,10,2,"Royal Apples" },
		{ 5.99,386,0,20,4,"Watermelon" },
		{ 3.99,240,0,30,5,"Blueberries" },
		{ 10.56,916,0,20,3,"Seedless Grapes" },
		{ 2.5,385,0,5,2,"Pomegranate" },
		{ 0.44,495,0,100,30,"Banana" },
		{ 0.5,316,0,123,10,"Kiwifruit" },
		{ 4.49,355,1,20,5,"Chicken Alfredo" },
		{ 5.49,846,1,3,5,"Veal Parmigiana" },
		{ 5.29,359,1,40,5,"Beffsteak Pie" },
		{ 4.79,127,1,30,3,"Curry Checken" },
		{ 16.99,238,1,10,2,"Tide Detergent" },
		{ 10.49,324,1,40,5,"Tide Liq. Pods" },
		{ 10.99,491,1,50,5,"Tide Powder Det." },
		{ 3.69,538,1,1,5,"Lays Chips S&V" },
		{ 3.29,649,1,15,5,"Joe Org Chips" },
		{ 1.79,731,1,100,10,"Allen's Apple Juice" },
		{ 6.69,984,1,30,3,"Coke 24 Pack" },
		{ 7.29,350,1,50,5,"Nestea 24 Pack" },
		{ 6.49,835,1,20,2,"7up 24 pack" }
	};
	double val;
	int ival;
	int searchIndex;
	val = totalAfterTax(I[0]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=44.000000\n", val);
	val = totalAfterTax(I[7]);
	printf("totalAfterTax:\n"
		"    yours=%lf\n"
		"program's=101.474000\n", val);
	ival = isLowQuantity(I[0]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=0\n", ival);
	ival = isLowQuantity(I[14]);
	printf("isLowQuantity:\n"
		"    yours=%d\n"
		"program's=1\n", ival);
	pause();

	printf("itemEntry, enter the following values:\n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: n\n");
	printf("Enter the values:\n");
	I[20] = itemEntry(999);
	printf("displayItem, Linear:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|   No|  50 |   5 |      227.00|\n");
	printf("displayItem, Form:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 50\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: No\n");
	I[20].quantity = 2;
	I[20].isTaxed = 1;
	pause();

	printf("displayItem, Linear with low value and taxed:\nYours: ");
	displayItem(I[20], LINEAR);
	printf(" Prog: |999|Red Apples          |    4.54|  Yes|   2 |   5 |       10.26|***\n");
	printf("displayItem, Form with low value:\nYours:\n");
	displayItem(I[20], FORM);
	printf("Programs: \n");
	printf("        SKU: 999\n"
		"       Name: Red Apples\n"
		"      Price: 4.54\n"
		"   Quantity: 2\n"
		"Minimum Qty: 5\n"
		"   Is Taxed: Yes\n"
		"WARNING: Quantity low, please order ASAP!!!\n");
	pause();

	printf("Listing Items: \n");
	listItems(I, 21);
	pause();
	printf("Locate Item, successful search:\n");
	printf("program: Found the item 999 at index: 20\n");
	printf("  Yours: ");
	if (locateItem(I, 21, 999, &searchIndex)) {
		printf("Found the item 999 at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 999 is in the array!\n");
	}

	printf("Locae Item, unsuccessful search:\n");
	printf("Progam: No item with the sku 732 is in the array!\n");
	printf(" Yours: ");
	if (locateItem(I, 21, 732, &searchIndex)) {
		printf("Found the item at index: %d\n", searchIndex);
	}
	else {
		printf("No item with the sku 732 is in the array!\n");
	}
	return 0;
}



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
			printf("***");
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


























/*
void listItems(const struct Item item[], int NoOfItems)
{
	int counter;
	int i;
	double grandtotal = 0;
	printTitle();
	for (counter = 0; counter < NoOfItems; i++)
	{
		printf("%4d|%3d|%20c|%8.2lf|%3d|%3d|%3d|%12.2lf|", counter + 1, item[counter].sku, item[counter].name, item[counter].price, item[counter].isTaxed, item[counter].quantity, item[counter].minQuantity, item[counter].price);
		i = totalAfterTax(item[counter]);
		grandtotal += i;
		printf("%lf", grandtotal);
	}

}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i = 0;
	for (i = 0; i < NoOfRecs; i++)
		if (sku == item[i].sku)
		{
			*index = i + 1;
			return 1;
		}
		else
		{
			return 0;
		}
}*/
