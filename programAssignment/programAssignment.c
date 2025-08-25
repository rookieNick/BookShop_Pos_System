#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#pragma warning (disable:4996)

/*
TO-DO LIST

PROBLEMS LIST

*/


//function declaration
void chooseBookField(void);
void showField1(void);
void showField2(void);
int chooseMainOption(void);
char chooseBook(void);
bool prompt(char prompt[50]);
int isQuantity(void);
void logo(void);

void main(void)
{
	//Price
	const float priceA = 100.00;
	const float priceB = 129.00;
	const float priceC = 231.00;
	const float priceD = 99.00;
	const float priceE = 170.00;
	const float priceF = 240.00;

	//Start
	logo();

	bool isInvalid;
	int mainOption;

backMainOption:
	//Choose main option menu
	mainOption = chooseMainOption();

	//Book Menu view (option 1)
	while (mainOption == 1)
	{
		chooseBookField();

		//choose main option again
		mainOption = chooseMainOption();
	}



	//Sales order (option 2)
	if (mainOption == 2)
	{
		//Variables
		char optionSales;
		int quantity;
		bool isYes;
		int quantityA = 0, quantityB = 0, quantityC = 0, quantityD = 0, quantityE = 0, quantityF = 0;
		float totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalE = 0, totalF = 0;
		float subtotal = 0, total = 0;
		int salesOrderNo = 0;

		int finalQuantityA = 0, finalQuantityB = 0, finalQuantityC = 0, finalQuantityD = 0, finalQuantityE = 0, finalQuantityF = 0;
		int finalTotalQuantity = 0;
		float finalTotalAmount = 0;

		float discount = 0;
		float totalDiscount = 0;
		do { // loop if next order
			do {//loop until order is confirmed
				subtotal = 0, total = 0;
				quantityA = 0, quantityB = 0, quantityC = 0, quantityD = 0, quantityE = 0, quantityF = 0;
				totalA = 0, totalB = 0, totalC = 0, totalD = 0, totalE = 0, totalF = 0;




				//User buy book
				do {//loop until exit order
					optionSales = chooseBook();


					if (optionSales == '0')
					{
						goto backMainOption; //back to main option
					}
					else if (optionSales == 'X')
					{
						break; // exit order
					}
					else
					{
						quantity = isQuantity(); // prompt quantity

						switch (optionSales) {
						case 'A':
							quantityA += quantity;
							totalA = priceA * quantityA;
							break;
						case 'B':
							quantityB += quantity;
							totalB = priceB * quantityB;
							break;
						case 'C':
							quantityC += quantity;
							totalC = priceC * quantityC;
							break;
						case 'D':
							quantityD += quantity;
							totalD = priceD * quantityD;
							break;
						case 'E':
							quantityE += quantity;
							totalE = priceE * quantityE;
							break;
						case 'F':
							quantityF += quantity;
							totalF = priceF * quantityF;
							break;
						}

						subtotal = totalA + totalB + totalC + totalD + totalE + totalF;


						if (subtotal > 200 && subtotal <= 300)
						{
							discount = 0.05 * subtotal;
							total = subtotal - discount;
						}
						else if (subtotal > 300 && subtotal <= 500)
						{
							discount = 0.10 * subtotal;
							total = subtotal - discount;
						}
						else if (subtotal > 500)
						{
							discount = 0.15 * subtotal;
							total = subtotal - discount;
						}
						else
						{
							total = subtotal;
						}

					}

				} while (optionSales != 'X');






				//confirmation
				isYes = prompt("Confirm the order? (Y = Yes, N = No): ");


				/* 1. Print quantity
				   2. Record for no. of sales order and total quantity of each book, total discount and final total amount (for summary report)*/
				if (isYes == true)
				{
					finalQuantityA += quantityA;
					finalQuantityB += quantityB;
					finalQuantityC += quantityC;
					finalQuantityD += quantityD;
					finalQuantityE += quantityE;
					finalQuantityF += quantityF;
					if (quantityA > 0 || quantityB > 0 || quantityC > 0 || quantityD > 0 || quantityE > 0 || quantityF > 0)
					{
						salesOrderNo += 1;
						finalTotalAmount += subtotal;
						totalDiscount += discount;
					}

					//Print quantity of books bought and total
					printf("\n");
					if (quantityA > 0)
					{
						printf("Book A: %d @ RM100.00 = RM%.2f\n", quantityA, totalA);
					}
					if (quantityB > 0)
					{
						printf("Book B: %d @ RM129.00 = RM%.2f\n", quantityB, totalB);
					}
					if (quantityC > 0)
					{
						printf("Book C: %d @ RM231.00 = RM%.2f\n", quantityC, totalC);
					}
					if (quantityD > 0)
					{
						printf("Book D: %d @ RM99.00 = RM%.2f\n", quantityD, totalD);
					}
					if (quantityE > 0)
					{
						printf("Book E: %d @ RM170.00 = RM%.2f\n", quantityE, totalE);
					}
					if (quantityF > 0)
					{
						printf("Book F: %d @ RM240.00 = RM%.2f\n", quantityF, totalF);
					}

					printf("\nSubtotal: RM%.2f\n", subtotal);

					if (subtotal > 200 && subtotal <= 300)
					{
						printf("Discount 5%%: RM%.2f\n", discount);
					}
					else if (subtotal > 300 && subtotal <= 500)
					{
						printf("Discount 10%%: RM%.2f\n", discount);
					}
					else if (subtotal > 500)
					{
						printf("Discount 15%%: RM%.2f\n", discount);
					}
					else
					{
						printf("Discount: RM0.00\n");
					}

					printf("\nTotal: RM%.2f\n", total);

				}

			} while (isYes == false);





			//Prompt next order
			isYes = prompt("\nNext order? (Y = Yes, N = No): ");


		} while (isYes == true);



		//No more next order (SUMMARY REPORT)
		finalTotalQuantity = finalQuantityA + finalQuantityB + finalQuantityC + finalQuantityD + finalQuantityE + finalQuantityF;

		if (isYes == false)
		{
			printf("\nSUMMARY REPORT\n");
			printf("No. of Sales Order: %d\n", salesOrderNo);
			printf("%-10s%-10s%10s\n", "Book", "Quantity", "Amount");
			printf("A%15d%14.2f\n", finalQuantityA, finalQuantityA * priceA);
			printf("B%15d%14.2f\n", finalQuantityB, finalQuantityB * priceB);
			printf("C%15d%14.2f\n", finalQuantityC, finalQuantityC * priceC);
			printf("D%15d%14.2f\n", finalQuantityD, finalQuantityD * priceD);
			printf("E%15d%14.2f\n", finalQuantityE, finalQuantityE * priceE);
			printf("F%15d%14.2f\n", finalQuantityF, finalQuantityF * priceF);
			printf("------------------------------\n");
			printf("(Before discount)\n");
			printf("Total%11d%14.2f\n", finalTotalQuantity, finalTotalAmount);
			printf("Discount%22.2f\n", totalDiscount);
			printf("(After discount)\n");
			printf("Total%11d%14.2f\n", finalTotalQuantity, finalTotalAmount - totalDiscount);
			printf("------------------------------\n");
		}

		goto backMainOption;

	}


	//Exit (option 3)
	else
	{
		printf("You have quit\n");
	}


	system("pause");
}




void chooseBookField(void)
{
	float bookField;
	bool isInvalid;

back:
	do {
		bookField = -999.0; //because %d cant store character, if user input character, the bookField value will not change (remain -999)
		isInvalid = false;
		printf("\nSelect a field to view:\n");
		printf("1 = Software Engineering Books\n");
		printf("2 = Software Development Books\n");
		printf("0 = Back\n");
		printf("Input: ");
		scanf("%f", &bookField);
		rewind(stdin);


		if (bookField == 0.0)
		{
			goto backBookField; // exit view book field
		}
		else if (bookField == -999.0)
		{
			isInvalid = true;
			printf("Invalid option, please key in number");
		}
		else if (bookField != 1.0 && bookField != 2.0)
		{
			isInvalid = true;
			printf("Invalid option, please try again\n");
		}
		else if (bookField == 1.0)
		{
			showField1();
		}
		else
		{
			showField2();
		}

	} while (isInvalid == true);


	char yesOrNo[11];

backError:

	printf("Continue view? (Y = Yes, N = No): ");
	gets(yesOrNo);
	rewind(stdin);

	//convert to upper letter
	yesOrNo[0] = toupper(yesOrNo[0]);

	// -------second space got contain character or digit----   
	if (isalpha(yesOrNo[1]) != 0 || isdigit(yesOrNo[1]) != 0 || (yesOrNo[0] != 'Y' && yesOrNo[0] != 'N'))
	{
		printf("Invalid option, please try again\n");
		goto backError;
	}
	else if (yesOrNo[0] == 'Y')
	{
		goto back; //continue view (loop back)
	}







backBookField:
	return;
}
//15/9
int chooseMainOption(void)
{
	int mainOption;
	bool isInvalid;
	do {
		printf("\nSelect an option (1 = View Menu, 2 = Sales Order, 3 = Exit): ");
		scanf("%d", &mainOption);
		printf("\n");
		rewind(stdin);

		if (mainOption != 1 && mainOption != 2 && mainOption != 3)
		{
			isInvalid = true;
			printf("Invalid option, please try again\n");
		}
		else
		{
			isInvalid = false;
		}

	} while (isInvalid == true);


	return mainOption;
}

void showField1(void)
{
	printf("\nSoftware Engineering Books\n");
	printf("[A] = %-60s%15s\n", "Patterns of Enterprise Application Architecture", "RM100.00");
	printf("[B] = %-60s%15s\n", "Code Complete", "RM129.00");
	printf("[C] = %-60s%15s\n", "Clean Code", "RM231.00");
}

void showField2(void)
{
	printf("\nSoftware Development Books\n");
	printf("[D] = %-60s%15s\n", "You Don't Know JS Yet", "RM99.00");
	printf("[E] = %-60s%15s\n", "Working Effectively With Legacy Code%15s", "RM170.00");
	printf("[F] = %-60s%15s\n", "Code: The Hidden Language of Computer Hardware and Software", "RM240.00");
}

char chooseBook(void)
{
	char salesOrder;
	char input[11];
	bool isInvalid;
	int size = sizeof(input) / sizeof(input[0]);
	do {
		printf("Book A,B,C,D,E,F (X = Finish order) (0 = Back & Restart): ");
		gets(input);
		rewind(stdin);

		//convert to upper letter
		for (int i = 0; i < size; i++)
		{
			input[i] = toupper(input[i]);
		}

		if (input[0] == '\0') // user input nothing
		{
			isInvalid = true;
			printf("Invalid option, please try again\n");
		}
		// ----------second space contain digit or character-------
		else if ((isalpha(input[1]) != 0 || isdigit(input[1]) != 0) || (input[0] != 'A' && input[0] != 'B' && input[0] != 'C' && input[0] != 'D' && input[0] != 'E' && input[0] != 'F' && input[0] != 'X' && input[0] != '0'))
		{
			isInvalid = true;
			printf("Invalid option, please try again\n");
		}
		else
		{
			isInvalid = false;
		}
	} while (isInvalid == true);
	salesOrder = input[0]; // use a char variable to store

	return salesOrder;
}

// add loop if contain more than one characters
bool prompt(char prompt[21])
{
	char userInput[11];
	bool isInvalid, isYes;
	int size = sizeof(userInput) / sizeof(userInput[0]);

	do {

		printf("%s", prompt);
		gets(userInput);
		rewind(stdin);

		//convert to upper letter
		for (int i = 0; i < size; i++)
		{
			userInput[i] = toupper(userInput[i]);
		}
		//													--------second space contain character or digit----------
		if ((userInput[0] != 'Y' && userInput[0] != 'N') || (isalpha(userInput[1]) != 0 || isdigit(userInput[1]) != 0))
		{
			isInvalid = true;
			printf("Invalid option, please try again\n");
		}
		else
		{
			isInvalid = false;
		}

	} while (isInvalid == true);




	if (userInput[0] == 'Y')
	{
		isYes = true;
	}
	else
	{
		isYes = false;
	}

	return isYes;
}

// add loop if contain alphabet
int isQuantity(void)
{
	float input;
	bool isQuantity;
	int quantity;
	int intPart;
	float fracPart;


	do {
		printf("Quantity: ");
		scanf("%f", &input);
		rewind(stdin);

		intPart = input;
		fracPart = input - intPart;
		// calculate got decimal or user input character
		if (fracPart > 0 || input < 0)
		{
			isQuantity = false;
			printf("Invalid option, please try again\n");
		}
		else
		{
			isQuantity = true;
		}

	} while (isQuantity == false);

	quantity = input; // use integer variable to store
	return quantity;
}

void logo(void)
{
	printf("\\n \\t \\r \\b %cc %cs %cd %co %cf \\n \\t \\r \\b %cc %cs %cd %co %cf\n", '%', '%', '%', '%', '%', '%', '%', '%', '%', '%');
	printf("%cx %49cx\n", '%', '%');
	printf("%cc\t ==================================== %6cc\n", '%', '%');
	printf("%cs\t Computer Science BookShop IS HERE!!! %6cs\n", '%', '%');
	printf("%cd\t ==================================== %6cd\n", '%', '%');
	printf("%co %49co\n", '%', '%');
	printf("%cf \\n \\t \\r \\b %cc %cs %cd %cf %co %cf %19cf\n", '%', '%', '%', '%', '%', '%', '%', '%');
	printf("%31cx %19cx\n", '%', '%');
	printf("%31cc %19cc\n", '%', '%');
	printf("%25s\\ %4cs %19cs    //\n", "\\", '%', '%');
	printf("%26s\\ %3cd %19cd   //\n", "\\", '%', '%');
	printf("%27s\\ %2co %19co  //\n", "\\", '%', '%');
	printf("%28s\\ %1cf %19cf //\n", "\\", '%', '%');
	printf("%29s\\ %24s\n", "\\", "//");
	printf("%30s\\ %22s\n", "\\", "//");
	printf("%31s\\ %20s\n", "\\", "//");
	printf("%32s\\ %18s\n", "\\", "//");
	printf("%33s\\ %16s\n", "\\", "//");
	printf("%34s\\ %14s\n", "\\", "//");
	printf("%35s\\ %12s\n", "\\", "//");
	printf("%36s\\ %10s\n", "\\", "//");
	printf("%37s\\ %8s\n", "\\", "//");
	printf("%38s\\ %6s\n", "\\", "//");
	printf("%39s\\ %4s\n", "\\", "//");
	printf("%40s\\ %2s\n", "\\", "//");
}










