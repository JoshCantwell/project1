/*
/
/       Author: Josh Cantwell
/       Data Structures and Algorith 2 
/       02-02-21
/       UseID and Password Database
/
*/
#include "FileManipulator.h"
#include <iostream>
#include "HashTable.h"

int main() {

    HashTable* hashtable;
    FileManipulator* fm;
    fm = new FileManipulator();
    hashtable = new HashTable(); 
    fm->ProcessUsers();
    fm->PasswordEncrypter();
  
    hashtable->SetSize(200000);
    fm->LoadHashTable(hashtable);
    hashtable->SearchHash("JONES");
    return 0;


}


