#include <stdio.h>
#include "sha-256.h"

int main() {
    char input[] = "thomas";
    char hash_string[65];
    get_sha256(hash_string,input);
    printf("Hash from %s is : %s",input,hash_string);
    return 0;
}



