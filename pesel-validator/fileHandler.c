#define _CRT_SECURE_NO_WARNINGS
#include "fileHandler.h"

#define PESEL_LENGTH 11
#define DATE_LENGTH 8
#define RESULTS_FILE_NAME "Results.txt"

void takePeselFromFile()
{
	char fileName[50];
	printf("Type file's name with extention(up to 50 characters): ");
	if (fgets(fileName, sizeof(fileName), stdin))
	{
		char * p;						// --
		if (p = strchr(fileName, '\n'))	// --
		{								// --
			*p = 0;						// --
		}								// --
		else							// Clearing fgets buffer
		{								// --
			scanf("%*[^\n]");			// --
			scanf("%*c");				// --
		}								// --
	}
	FILE * file;
	file = fopen(fileName, "rt");
	if (file == NULL)
	{
		printf("Error while opening file\n");
	}
	else
	{
		char pesel[PESEL_LENGTH + 1];
		while (fgets(pesel, sizeof(pesel), file))
		{
			handleGivenPesel(pesel);
		}
		fclose(file);
	}
}

void saveDataToFile(char * pesel, char * birthDate, char sex)
{
	FILE * results = fopen(RESULTS_FILE_NAME, "a+");
	fprintf(results, "PESEL: %s\n", pesel);
	fprintf(results, "Birth date (dd.mm.yyyy): ");
	for (int i = 0; i < DATE_LENGTH; ++i)
	{
		fprintf(results, "%c", birthDate[i]);
		if ((i == 1) || (i == 3))
		{
			fprintf(results, ".");
		}
	}
	fprintf(results, "\n");
	fprintf(results, "Sex: ");
	if (sex == 'f')
	{
		fprintf(results, "Female");
	}
	else
	{
		fprintf(results, "Male");
	}
	fprintf(results, "\n\n");
	fclose(results);
	resultsSavedToFileMessage();
}

void resultsSavedToFileMessage()
{
	printf("Results has been saved to %s\n\n", RESULTS_FILE_NAME);
}

void savePeselIsInvalidMessageToFile(char * message)
{
	FILE * results = fopen(RESULTS_FILE_NAME, "a+");
	fprintf(results, "%s\n\n", message);
	fclose(results);
	resultsSavedToFileMessage();
}
