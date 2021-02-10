/*
/
/       Author: Josh Cantwell
/       Data Structures and Algorith 2 
/       02-02-21
/       UseID and Password Database
/
*/

#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include "Node.h"
#include <iostream>
#include <vector>

class HashTable{ 


    public:

        HashTable(){


        }

        std::vector <Node*> GetHashTable(); 
        int GetSize();
        void SetSize(int size);
        Node* SearchHash(std::string userid);
        Node* Search(std::string, Node* node);
        int HashFunction(Node* node);
        int HashFunction(std::string userid);
        void InsertNode(int position, Node* node);
        void Insert(Node* curr,Node* insert);

        void Test();
        void TestUser(std::string userid, std::string passwords);

    private:

        std::vector <Node*>  hashTable;

};

#endif
