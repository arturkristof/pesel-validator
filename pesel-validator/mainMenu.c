#define _CRT_SECURE_NO_WARNINGS
#include "mainMenu.h"
#include "pesel.h"
#include "fileHandler.h"

void initMainMenu() 
{
	do
	{
		displayMainMenu();
		int option;
		do
		{
			option = getMainMenuOption();
			if ((option < 1) || (option > 3))
			{
				invalidOptionError();
			}
		} while ((option < 1) || (option > 3));

		switch (option)
		{
		case 1:
			takePeselFromUser();
			break;
		case 2:
			takePeselFromFile();
			break;
		case 3:
			exit(0);
			break;
		default:
			invalidOptionError();
			break;
		}
	} while (true);	
}

void displayMainMenu()
{
	printf("Choose option:\n");
	printf("1. Input PESEL with keyboard\n");
	printf("2. PESELs are in txt file\n");
	printf("3. Exit\n");
}

int getMainMenuOption()
{
	char input[2];
	int option;
	int result;

	do
	{
		printf("Option: ");
		if (fgets(input, sizeof(input), stdin))
		{
			char * p;						// --
			if (p = strchr(input, '\n'))	// --
			{								// --
				*p = 0;						// --
			}								// --
			else							// Clearing fgets buffer
			{								// --
				scanf("%*[^\n]");			// --
				scanf("%*c");				// --
			}								// --
		}
		result = sscanf(input, "%d", &option);
		if (result < 1)
		{
			invalidOptionError();
		}
	} while (result < 1);
	
	return option;
}

void invalidOptionError()
{
	printf("Invalid option!\n");
}