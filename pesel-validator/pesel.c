#define _CRT_SECURE_NO_WARNINGS
#include "pesel.h"
#include "fileHandler.h"

#define PESEL_LENGTH 11
#define DATE_LENGTH 8

void handleGivenPesel(char * pesel) {
	char birthDate[DATE_LENGTH + 1];
	char sex;

	if (isPeselValid(pesel))
	{
		defineBirthDate(pesel, birthDate);
		sex = defineSex(pesel);
		displayData(pesel, birthDate, sex);
		saveDataToFile(pesel, birthDate, sex);
	}
	else
	{
		peselIsInvalid(pesel);
	}
}

bool isPeselValid(char * pesel)
{
	int amountOfNumbers = 0;
	while (pesel[amountOfNumbers] != '\0')
	{
		if (isdigit(pesel[amountOfNumbers]) != false)
		{
			amountOfNumbers++;
		}
		else
		{
			return false;
		}
	}

	if (amountOfNumbers == PESEL_LENGTH)
	{
		int peselInt[PESEL_LENGTH];
		convertPeselToIntArray(pesel, peselInt);
			
		int checkSum;
		checkSum = peselInt[0] + 3 * peselInt[1] + 7 * peselInt[2] + 9 * peselInt[3] + peselInt[4]
			+ 3 * peselInt[5] + 7 * peselInt[6] + 9 * peselInt[7] + peselInt[8] + 3 * peselInt[9];
		checkSum = checkSum % 10;
		if (checkSum == 0)
		{
			return (checkSum == peselInt[PESEL_LENGTH - 1]);
		}
		else
		{
			checkSum = 10 - checkSum;
			return (checkSum == peselInt[PESEL_LENGTH - 1]);
		}
	}
	else
	{
		return false;
	}
}

void peselIsInvalid(char * pesel)
{
	char peselStr[] = "PESEL ";
	char isIncorrect[] = " is incorrect.";

	char message[sizeof(peselStr) + sizeof(isIncorrect) + PESEL_LENGTH];
	strcpy(message, peselStr);
	strcat(message, pesel);
	strcat(message, isIncorrect);
	displayPeselIsInvalidMessage(message);
}

void convertPeselToIntArray(char * pesel, int * result)
{
    for (int i = 0; i < PESEL_LENGTH; ++i)
        {
            switch(pesel[i])
            {
            case '0':
                result[i] = 0;
                break;
            case '1':
                result[i] = 1;
                break;
            case '2':
                result[i] = 2;
                break;
            case '3':
				result[i] = 3;
                break;
            case '4':
				result[i] = 4;
                break;
            case '5':
				result[i] = 5;
                break;
            case '6':
				result[i] = 6;
                break;
            case '7':
				result[i] = 7;
                break;
            case '8':
				result[i] = 8;
                break;
			case '9':
				result[i] = 9;
                break;
			default:
				break;
            }
        }
}

void defineBirthDate(char * pesel, char * dateToDefine)
{
	int peselInt[PESEL_LENGTH];
	convertPeselToIntArray(pesel, peselInt);
    int day[2]; 
    int month[2]; 
    int year[4]; 
    day[0] = peselInt[4];
    day[1] = peselInt[5];

    month[0] = peselInt[2];
    month[1] = peselInt[3];

	switch (month[0])
	{
	case 9:
	case 8:
		year[0] = 1;
		year[1] = 8;
		month[0] = month[0] - 8;
		break;
	case 7:
	case 6:
		year[0] = 2;
		year[1] = 2;
		month[0] = month[0] - 6;
		break;
	case 5:
	case 4:
		year[0] = 2;
		year[1] = 1;
		month[0] = month[0] - 4;
		break;
	case 3:
	case 2:
		year[0] = 2;
		year[1] = 0;
		month[0] = month[0] - 2;
		break;
	default:
		year[0] = 1;
		year[1] = 9;
		break;
	}

    year[2] = peselInt[0];
    year[3] = peselInt[1];

	dateToDefine[0] = day[0] + '0';
	dateToDefine[1] = day[1] + '0';
	dateToDefine[2] = month[0] + '0';
	dateToDefine[3] = month[1] + '0';
	dateToDefine[4] = year[0] + '0';
	dateToDefine[5] = year[1] + '0';
	dateToDefine[6] = year[2] + '0';
	dateToDefine[7] = year[3] + '0';
}

char defineSex(char * pesel) 
{
	char sexChar = pesel[9];
	int sexInt = sexChar - '0';

	if ((sexInt % 2) == 0)
	{
		return 'f'; // Female
	}
	else
	{
		return 'm'; // Male
	}
}