#include "pesel.h"
#include "mainMenu.h"

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		initMainMenu();
	}
	else
	{
		int i;
		for (i = 1; i < argc; i++)
		{
			handleGivenPesel(argv[i]);
		}
	}
    getchar();
    return 0;
}