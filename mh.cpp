#include <iostream>
#include "MemoryHard.h"
using namespace std;

int main (int argc, char* argv[])
{
    unsigned char*  message  = (unsigned char*) argv[1];
    string          hash;
    int             strength = atoi(argv[2]);

    MemoryHard* mh = new MemoryHard();
    hash = mh->HashHard(message, strength);

    cout << "Hash: " << hash << endl;
    cout << "Time Taken: " << mh->timeTaken << " seconds." << endl;
    return 0;
}