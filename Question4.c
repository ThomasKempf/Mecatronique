#include <stdio.h>
#include <string.h>
#include "sha-256.h"


#define nbrCaratere 5
char pswdTested[nbrCaratere+1];
char pswdEnd[nbrCaratere+1];


void initialisation()
{
    for (int i = 0; i < nbrCaratere; i++)
    {
        pswdTested[i] = 'a';
        pswdEnd[i] = 'z';
    }
    pswdTested[nbrCaratere] = '\0';
    pswdEnd[nbrCaratere] = '\0';
}

void incrementerPswd()
{
    for (int i = 0; i <= nbrCaratere; i++)
    {
        if (pswdTested[i] == 'z')
        {
            pswdTested[i] = 'a';
        }
        else
        {
            if (pswdTested[i] == '\0')
            {
                return;
            }
            pswdTested[i]++;
            return;
        }
    }
}


int main() 
{
    char hashToFind[] = "1cc4af005a69f3e80dbf0ab833d8b86d9d9c6ebfc40ba8b6c96503d265aefe6b";
    pswdTested[nbrCaratere] = '\0';
    char hashString[65];
    initialisation();

    while (strcmp(pswdTested,pswdEnd) != 0)
    {
        get_sha256(hashString,pswdTested);
        if (strcmp(hashString,hashToFind) == 0)
        {
            printf("Le mot de passe est : %s",pswdTested);
            return 0;
        }
        incrementerPswd();
    }
    printf("pas trouvée");
    return 0;
}

