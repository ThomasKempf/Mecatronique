#include <stdio.h>
#include <string.h>
#include "sha-256.h"


int main() 
{
    char hashToFind[] = "454349e422f05297191ead13e21d3db520e5abef52055e4964b82fb213f593a1";
    char pswdTested[2] = "";
    pswdTested[1] = '\0';
    char input[] = "thomas";
    char hashString[65];
    for (int lettre = 'a'; lettre <= 'z'; lettre++)
    {
        pswdTested[0] = lettre;
        get_sha256(hashString,pswdTested);
        if (strcmp(hashString,hashToFind) == 0)
        {
            printf("Le mot de passe est : %s",pswdTested);
            return 0;
        }
    }
    printf("pas trouvée");
    return 0;
}

