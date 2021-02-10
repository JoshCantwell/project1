#include "Node.h"

void Node::setUserid(std::string userid) {

    this->userid = userid;

}

void Node::setPassword(std::string password) {
     
    this->password = password;
}

void Node::setNextNode(Node* node){

    this->nextNode = node;
}

Node* Node::getNextNode() {

    return this->nextNode;

}

std::string Node::getUserid() {

    return userid;
}

std::string Node::getPassword() {

    return password;
}
