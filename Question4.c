#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "sha-256.h"


#define nbrCaratere 3
char pswdTested[nbrCaratere+1] = "aaa\0";


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
    char hashToFind[] = "fa690b82061edfd2852629aeba8a8977b57e40fcb77d1a7a28b26cba62591204";
    pswdTested[nbrCaratere] = '\0';
    char input[] = "thomas";
    char hashString[65];
    char pswdEnd[] = "zzz\0";
    printf("test : %s\n",pswdEnd);
    
    while (strcmp(pswdTested,pswdEnd) != 0)
    {
        get_sha256(hashString,pswdTested);
        if (strcmp(hashString,hashToFind) == 0)
        {
            printf("Le mot de passe est : %s",pswdTested);
            return 0;
        }
        printf("test : %s\n",pswdTested);
        incrementerPswd();
    }
    printf("pas trouvée");
    return 0;
}

