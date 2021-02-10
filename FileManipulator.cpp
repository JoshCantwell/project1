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

void FileManipulator::LoadHashTable(HashTable* hashTable) {

    int i= 0;
    std::string userid, password;

    lastNames.open("encrypted.txt");
    if(!lastNames.is_open()){
       
        std::cout << "Unable to open that file!" << std::endl;

    } else {

        while(!lastNames.eof()) {

            Node* node;
            node = new Node();;
            lastNames >> userid;
            lastNames >> password;
            node->setUserid(userid);
            node->setPassword(password);

            hashTable->InsertNode(hashTable->HashFunction(node), node);
            //Need to make insert function for hashtable

            //std::cout << userid << " " << password << " " << hashTable->HashFunction(node) << std::endl;
        }


    }

}

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
            float num1, num2;

            int num3;
            while(!lastNames.eof()){
            lastNames >> name;
            lastNames >> num1;
            lastNames >> num2;
            lastNames >> num3;

            raw << name;
            raw << " ";
            raw << RandomPassword(num3) << std::endl;
            
            }


            lastNames.close();
            raw.close();
        }
    }
}

void FileManipulator::PasswordEncrypter() {

    std::string userid, password;
    lastNames.open("raw.txt");

    if(!lastNames.is_open()) {

        std::cout << "Unable to open raw.txt file, sorry" << std::endl;

    } else {


        raw.open("encrypted.txt");
        if(!raw.is_open()){

            std::cout << "Unable to create encrypted.txt, sorry" << std::endl;
        } else {

            while(!lastNames.eof()) {
            
                lastNames >> userid;
                lastNames >> password;
                raw << userid;
                raw << " ";
                raw << Encrypt(password) << std::endl;
            }
            lastNames.close();
            raw.close();

        }

    }


}

std::string FileManipulator::Encrypt(std::string password) {

    int i = 0;
    char letter, spareLetter;
    std::string encryptedPassword = "";

    while(i < password.length()) {

        switch(i) {
            case 0 :
                spareLetter = password[i];
                if((spareLetter + 9) > 122) {
                    letter =  98 + (spareLetter + 7  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 9; 
                    encryptedPassword += letter;
                    i++;
                }
                break;

            case 1 :
                 spareLetter = password[i];
                if((spareLetter + 14) > 122) {
                    letter =  98 + (spareLetter + 12  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 14; 
                    encryptedPassword += letter;
                    i++;
                }
                break;

            case 2 :
                spareLetter = password[i];
                if((spareLetter + 13) > 122) {
                    letter =  98 + (spareLetter + 11  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 13; 
                    encryptedPassword += letter;
                    i++;
                }
                break;
            
            case 3 :

                spareLetter = password[i];
                if((spareLetter + 4) > 122) {
                    letter =  98 + (spareLetter + 2  - 122);
                    
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 4; 
                    
                    encryptedPassword += letter;
                    i++;
                }
                break;
            
            case 4 :
                 spareLetter = password[i];
                if((spareLetter + 18) > 122) {
                    letter =  98 + (spareLetter + 16  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 18; 
                    encryptedPassword += letter;
                    i++;
                }
               break;

            case 5 :
                spareLetter = password[i];
                if((spareLetter + 9) > 122) {
                    letter =  98 + (spareLetter + 7  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 9; 
                    encryptedPassword += letter;
                    i++;
                }
               break;
            
            case 6 :
               spareLetter = password[i];
                if((spareLetter + 14) > 122) {
                    letter =  98 + (spareLetter + 12  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 14; 
                    encryptedPassword += letter;
                    i++;
                }
               
               break;

            case 7 :
 
               spareLetter = password[i];
                if((spareLetter + 13) > 122) {
                    letter =  98 + (spareLetter + 11  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 13; 
                    encryptedPassword += letter;
                    i++;
                }
              break;

            case 8 :
              spareLetter = password[i];
                if((spareLetter + 4) > 122) {
                    letter =  98 + (spareLetter + 2  - 122);
                    encryptedPassword += letter;
                    i++;
                } else {
                    letter = password[i] + 4; 
                    encryptedPassword += letter;
                    i++;
                }
                break;
            default :

                std::cout << "Something went wrong with the encryption fucntion" << std::endl;
                break;
        }
        

    }

    return encryptedPassword;;
}

std::string FileManipulator::RandomPassword(int num3) {

    int x = 0;
    std::string password;
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
    int string_length = sizeof(alphanum) - 1;
    srand(num3);
    for(int i = 0; i < 9; i++)
        password += alphanum[rand() % string_length];


    return password;


}













