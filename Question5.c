#include <stdio.h>
#include <string.h>
#include "sha-256.h"

#define tailleMax 6

int nbrCaratere = 1;
char pswdTested[tailleMax+1];
char pswdEnd[tailleMax+1];


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


int testPswd()
{
    char hashToFind[] = "38f6c594ab58aad97993e44802be2491fc27bb00d1d6003ade56f2605c58b435";
    char hashString[65];
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
    return 1;
}


int main() 
{
    pswdTested[nbrCaratere] = '\0';
    for (; nbrCaratere <= tailleMax; nbrCaratere++)
    {
        initialisation();
        if (testPswd() == 0)
        {
            return 0;
        }
        printf("on a teste tous les mots de passe de taille %d\n",nbrCaratere);
    }
    printf("le mot de passe est supérieur à %d caractères",tailleMax);
}



