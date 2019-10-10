//
// Created by zheng on 2019/10/9.
//
#include "node.h"

Node::Node() {}
Node::Node(int id, int length, DATA_TYPE *data) {
    this->id=id;
    this->length=length;
    this->data=data;
}

int Node::getId() {
    return this->id;
}

int Node::getLength() {
    return this->length;
}

void Node::setId(int id) {
    this->id=id;
}

DATA_TYPE* Node::getAllData() {
    return this->data;
}

DATA_TYPE Node::getDataById(int index) {
    return this->data[index];
}

Node::~Node() {
}

