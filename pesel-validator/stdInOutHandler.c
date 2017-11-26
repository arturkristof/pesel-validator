#define _CRT_SECURE_NO_WARNINGS
#include "stdInOutHandler.h"
#include "pesel.h"

#define PESEL_LENGTH 11
#define DATE_LENGTH 8

void takePeselFromUser()
{
	char pesel[PESEL_LENGTH + 1];
	int result;

	printf("Type PESEL: ");
	if (fgets(pesel, sizeof(pesel), stdin))
	{
		char * p;						// --
		if (p = strchr(pesel, '\n'))	// --
		{								// --
			*p = 0;						// --
		}								// --
		else							// Clearing fgets buffer
		{								// --
			scanf("%*[^\n]");			// --
			scanf("%*c");				// --
		}								// --
	}
	handleGivenPesel(pesel);
}

void displayData(char * pesel, char * birthDate, char sex)
{
	printf("PESEL: %s\n", pesel);
	printf("Birth date (dd.mm.yyyy): ");
	for (int i = 0; i < DATE_LENGTH; ++i)
	{
		printf("%c", birthDate[i]);
		if ((i == 1) || (i == 3))
		{
			printf(".");
		}
	}
	printf("\n");
	printf("Sex: ");
	if (sex == 'f')
	{
		printf("Female");
	}
	else
	{
		printf("Male");
	}
	printf("\n\n");
}

void displayPeselIsInvalidMessage(char * message)
{
	printf("%s\n\n", message);
}