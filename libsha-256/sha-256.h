#ifndef SHA_256_H
#define SHA_256_H

/*
 * Implementation of the Hash function comes from : https://github.com/amosnier/sha-2 (Public Domain)
 */

/* 
 * The function returns the SHA-256 hash of string "input".
 * The hash is given as a string "hash_string" of 64 hexadecimal characters (256 bits)
 */
void get_sha256(char hash_string[65], const char * input);

#endif
