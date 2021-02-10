/*
/
/       Author: Josh Cantwell
/       Data Structures and Algorith 2 
/       02-02-21
/       UseID and Password Database
/
*/

#ifndef _node_h_
#define _node_h_

#include <string>
class Node {

    public:

        Node() {


        }

        Node(std::string userid, std::string password) {

            this->userid = userid;
            this->password = password;
        }

      
        Node* getNextNode();
        std::string getUserid();
        std::string getPassword();
        void setUserid(std::string userid);
        void setPassword(std::string password);
        void setNextNode(Node* node);


    private:


        Node* nextNode = NULL;
        std::string userid;
        std::string password;

};

#endif
