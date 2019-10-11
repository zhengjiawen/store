//
// Created by zheng on 2019/10/9.
//
#include "node.h"

Node::Node() {}
Node::Node(int id, int length, DATA_TYPE *data):id(id), length(length) {
    this->data = new DATA_TYPE[length];
    for(int i=0; i<length; i++)
    {
        this->data[i] = data[i];
    }
}

Node::Node(const Node &node) {
    this->id = node.id;
    this->length = node.length;
    this->data =  new DATA_TYPE[node.length];
    for(int i=0; i<length; i++)
    {
        this->data[i] = node.data[i];
    }
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
    if(index > this->length){
        throw "attr index is not exist, pleast check node.";
    }
    return this->data[index];
}

Node::~Node() {
    if(nullptr != data)
        delete[] data;
}

