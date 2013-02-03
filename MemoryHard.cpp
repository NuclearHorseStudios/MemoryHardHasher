#include <iomanip>
#include <sstream>
#include <string>
#include <ctime>
#include <cmath>
#include "MemoryHard.h"

MemoryHard::MemoryHard (void)
{
    InitSSL();
}

void MemoryHard::InitSSL (void)
{
    SSL_load_error_strings();
    ERR_load_BIO_strings();
    OpenSSL_add_all_algorithms();
}

string MemoryHard::HashHard(unsigned char* message, int strength)
{
    time_t  timeStarted =   time(NULL);
    long    n           =   (long long) ceil(pow(2, (double) strength));
            hashBuffer  =   (unsigned char*) 
                            calloc(n, sizeof(char) * SHA256_DIGEST_LENGTH);
    
    Hash256((char *) message);

    long i;
    for (long i = 0; i < n; i += SHA256_DIGEST_LENGTH)
    {
        memcpy(&hashBuffer[i], currentHash, SHA256_DIGEST_LENGTH);
        Hash256((char *) currentHash);
    }

    unsigned char* previous             = &hashBuffer[n - SHA256_DIGEST_LENGTH];
    unsigned char* intergeredPrevious   = &hashBuffer[SumHash(previous) % n];

    for (i = 0; i < n; i++)
    {
        Hash256((char *) XorHash(   previous, 
                                    intergeredPrevious, 
                                    (unsigned char*) currentHash));

        previous           = (unsigned char*) currentHash;
        intergeredPrevious = &hashBuffer[SumHash(previous) % n];
    }

    free (hashBuffer);

    timeTaken = time(NULL) - timeStarted;
    return HashToString((unsigned char *) currentHash);
}

void MemoryHard::Hash256 (char* message)
{ 
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final((unsigned char*) currentHash, &sha256);
}

unsigned long MemoryHard::SumHash (unsigned char* hash)
{
    long long sum = 0;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sum += (int) hash[i] << i;
    }

    return sum;
}

unsigned char* MemoryHard::XorHash( unsigned char* a, 
                                    unsigned char* b, 
                                    unsigned char* r)
{
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        r[i] = a[i] ^ b[i];
    }

    return r;
}

string MemoryHard::HashToString (unsigned char* hash)
{
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }

    return ss.str();
}