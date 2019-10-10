//
// Created by Administrator on 2019/10/9.
//

#include "table.h"

Table::Table() {
    this->length=0;
}

Table::Table(string path) {

}

Table::Table(list<Node>& data_list, int length):data_list(data_list), length(length) {

}

int Table::addNodes(list<Node>& node_list) {
    this->data_list.insert(this->data_list.end(), node_list.begin(), node_list.end());
    this->add_list.insert(this->add_list.end(), node_list.begin(), node_list.end());
    this->length+=node_list.size();
    return node_list.size();
}


void Table::addOneNode(Node& node) {
    this->data_list.emplace_back(node.getId(), node.getLength(), node.getAllData());
    this->add_list.emplace_back(node.getId(), node.getLength(), node.getAllData());
    this->length++;
}
void Table::addOneNode(int id, int length, DATA_TYPE* data)
{
    this->data_list.emplace_back(id, length, data);
    this->add_list.emplace_back(id, length, data);
    this->length++;
}


int Table::check_node(list<Node>& node_list) {

}

Node& Table::getNodeByIndex(int index) {

}

list<Node>& Table::getAllData() {
    return this->data_list;
}

list<Node>& Table::findAttrByRange(int attrId, DATA_TYPE& low, DATA_TYPE& high) {

}

int Table::writeFile() {

}

int Table::readFile(string path) {

}

// write added list node to file
int Table::merge() {

}

Table::~Table() {


}
