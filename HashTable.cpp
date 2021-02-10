#include "HashTable.h"
#include "Node.h"
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
       
        std::cout << "userid not found in hash table" << std::endl;
        return NULL;
        std::cout << "userid not found in hash table" << std::endl;
    } else {
        if(hashTable.at(hashCode)->getUserid() == userid) {

            std::cout << "user found" << std::endl;
            return hashTable.at(hashCode);
        } else {

            //std::cout << hashTable.at(hashCode)->getUserid() << std::endl;
        
            //std::cout << hashCode << std::endl;
            Search(userid, hashTable.at(hashCode)->getNextNode()); 
        }
    }
}

Node* HashTable::Search(std::string userid, Node* curr) {

    if(userid == curr->getUserid()) {

        std::cout << "user found on recursive" << std::endl;    
        std::cout << curr->getUserid() << " " << curr->getPassword() << std::endl;
        return curr;
    } else {

        if(curr->getNextNode() == NULL) {

            std::cout << "user not found in hash" << std::endl;
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
