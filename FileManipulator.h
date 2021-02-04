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

#include <fstream>
#include <iostream>

class FileManipulator {

        public:
            
            
            FileManipulator() {


            }


            void ProcessUsers();
            std::string RandomPassword();
        private:


        std::ofstream raw;
        std::ifstream lastNames;
};

#endif
