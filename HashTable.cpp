#include "HashTable.h"
#include "FileManipulator.h"
#include "Node.h"
#include <iomanip>
int HashTable::GetSize() {

    return hashTable.size();

}

void HashTable::SetSize(int size) {

    hashTable.resize(size);

}

std::vector <Node*> HashTable::GetHashTable() {

    return hashTable;
}

Node* HashTable::SearchHash(std::string userid) {

    int hashCode =  HashFunction(userid);
    if(hashTable.at(hashCode) == NULL) {
       
        return NULL;
    } else {
        if(hashTable.at(hashCode)->getUserid() == userid) {

            return hashTable.at(hashCode);
        } else {

            Search(userid, hashTable.at(hashCode)->getNextNode()); 
        }
    }
}

Node* HashTable::Search(std::string userid, Node* curr) {

    if(userid == curr->getUserid()) {

        return curr;
    } else {

        if(curr->getNextNode() == NULL) {

            return NULL;
        } else {

            Search(userid, curr->getNextNode());
        }

    }

}


void HashTable::InsertNode(int position, Node* node) {

    if(hashTable.at(position) == NULL) {

        hashTable.at(position) = node;
    } else {


        Insert(hashTable.at(position), node);

    }


}

void HashTable::Insert(Node* curr, Node* insert) {

    if(curr->getNextNode() == NULL) {

        curr->setNextNode(insert);

    } else {
     
        Insert(curr->getNextNode(), insert);

    }
}

int HashTable::HashFunction(std::string userid) {

    int hashValue = 0;

    for(int i = 0; i < userid.length(); i++) {
        hashValue += userid[i];
    }

    hashValue +=  hashValue*(userid.length()*userid.length());


    return hashValue;
}
int HashTable::HashFunction(Node* node) {

    int hashValue = 0;

    for(int i = 0; i < node->getUserid().length(); i++) {
        hashValue += node->getUserid()[i];
    }

    hashValue +=  hashValue*(node->getUserid().length()*node->getUserid().length());


    return hashValue;
}

void HashTable::Test() {

    std::string userid [5] = {"SMITH", "JOHNSON", "WILLIAMS", "JONES", "BROWN"}; 
    std::string Passwords [5] = {"nwlrbbmqb", "ebgnhamdh", "gvwqtyskr", "hxkovzdbw", "tlwqsokph"};
    std::string wrongPasswords [5] = {"awlrbbmgb", "abgnhamdh", "avwqtyskr", "axkovzdbw", "alwqsokph"};

    std::cout << "Leagal:" << std::endl;
    std::cout << std::setw(12) << "Userid"  << " " << std::setw(12)<< "Password" <<  " " << std::setw(12) << "Result" << std::setw(12) << " " << std::setw(12) <<std::endl;
    for(int i = 0; i <= 4; i++) {

        TestUser(userid[i], Passwords[i]);

    }
    std::cout << std::endl;
    std::cout << "Illegal:" << std::endl;

    std::cout << std::setw(12) << "Userid"  << " " << std::setw(12)<< "Password" <<  " " << std::setw(12) << "Result" << std::setw(12) << " " << std::setw(12) <<std::endl;
    for(int i = 0; i <= 4; i++) {

        TestUser(userid[i], wrongPasswords[i]);
    }


}

void HashTable::TestUser(std::string userid, std::string passwords) {


    FileManipulator* fm;
    Node* curr = SearchHash(userid);
    std::cout << std::setw(12) << curr->getUserid() << " " << std::setw(12) << curr->getPassword() << " " << std::setw(12); 
    if(curr->getPassword() == fm->Encrypt(passwords)) {

        std::cout << "match" << std::endl;
    } else {

        std::cout << "no match" << std::endl;
    }





}



























