MemoryHardHasher
================

An implementation of memory hard hashing in C++.  

Created as an exercise in C++, use at your own risk.  It all seems to work 
though.  Assumes OpenSSL/SHA256.

**INSTALLATION**

     $ make

**EXAMPLE USAGE OUTPUT**
Pass a string to hash and a strength.  Strength is used to determine the number 
of iterations of the hashed password to use to fill out memory.  Memory usage 
will be correlated with 2^strength.  Strength of 24 uses about 16.7MB of memory.

     $ ./mh "Hello, World" 16
     Hash: 85c376aa5fc8b75e027cad088dc76c7e56137b555e49db73f39ae766e40de317
     Time Taken: 0 seconds.

     $ ./mh "Hello, World" 22
     Hash: 1454ab24885f12dd053920463fe424bc06092e8e2d35f93a797faa225cb1e371
     Time Taken: 5 seconds.

     $ ./mh "Hello, World" 23
     Hash: c29c401544514e86a88e2143e309a2be830e4e6612a135e733dd4200fe3ccf55
     Time Taken: 9 seconds.

     $ ./mh "Hello, World" 24
     Hash: cd7909a3419555adcbdb82883848fa9927a0846bf103ee9a90046b078ece8d28
     Time Taken: 18 seconds.

     $ ./mh "Hello, World" 25
     Hash: 6423a7d74ead0618f77f015977f074d6c6542a654e745f233680a0b48083834a
     Time Taken: 37 seconds.
