#include <stdbool.h>

void handleGivenPesel(char * pesel);
bool isPeselValid(char* pesel);
void peselIsInvalid(char* pesel);
void convertPeselToIntArray(char * pesel, int * result);
void defineBirthDate(char * pesel, char * dateToDefine);
char defineSex(char* pesel);