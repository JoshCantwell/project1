/*
/
/       Author: Josh Cantwell
/       Data Structures and Algorith 2 
/       02-02-21
/       UseID and Password Database
/
*/

#ifndef _filemanipulator_h_
#define _filemanipulator_h_

#include "HashTable.h"
#include <fstream>
#include <iostream>

class FileManipulator {

        public:
            
            
            FileManipulator() {


            }


            void LoadHashTable(HashTable* hashTable);
            void PasswordEncrypter(); 
            void ProcessUsers();
            std::string RandomPassword(int num3);
            std::string Encrypt(std::string password);
        
        
        private:


        std::ofstream raw;
        std::ifstream lastNames;
};

#endif
