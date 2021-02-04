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
#include <cstdlib>
#include <ctime>

void FileManipulator::ProcessUsers() {

    lastNames.open("lastNames.txt");
    if(!lastNames.is_open()){

        std::cout << "Unable to open the file!1" << std::endl;

    } else {

        raw.open("raw.txt");
        if(!raw.is_open()) {

            std::cout << "Unable to open the file!" << std::endl;

        } else {
        
            std::string name;
            float num1, num2, num3;

            while(!lastNames.eof()){
            lastNames >> name;
            lastNames >> num1;
            lastNames >> num2;
            lastNames >> num3;

            std::cout << name << std::endl;

            raw << name;
            raw << " ";
            raw << RandomPassword() << std::endl;
            Sleep(1);
            }
        }
    }
}

std::string FileManipulator::RandomPassword() {

    std::string password;
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    int string_length = sizeof(alphanum) - 1;
    srand(time(0));
    for(int i = 0; i < 9; i++)
        password += alphanum[rand() % string_length];


    return password;


}















