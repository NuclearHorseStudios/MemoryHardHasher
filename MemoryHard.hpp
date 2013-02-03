#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
using namespace std;

class MemoryHard
{   
    public:
        char            currentHash[SHA256_DIGEST_LENGTH];
        unsigned char*  hashBuffer;
        time_t          timeTaken;
                        MemoryHard (void);
        void            InitSSL (void);
        string          HashHard(unsigned char* message, int strength);
        void            Hash256 (char* message);
        unsigned long   SumHash (unsigned char* hash);
        unsigned char*  XorHash (unsigned char* a, 
                                 unsigned char* b, 
                                 unsigned char* r);
        string          HashToString (unsigned char* hash);
};