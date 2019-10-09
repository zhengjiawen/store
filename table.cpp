//
// Created by Administrator on 2019/10/9.
//

#include "table.h"

Table::Table() {
    this->data_list = new list<Node>();
    this->add_list = new list<Node>();
    this->length=0;
}

Table::Table(string path) {

}

Table::Table(list<Node> *data_list, int length) {
    this->data_list = data_list;
    this->length = length;
    this->add_list = new list<Node>();
}

int Table::addNodes(list<Node> node_list) {
    this->data_list->insert(this->data_list->end(), node_list.begin(), node_list.end());
    this->add_list->insert(this->add_list->end(), node_list.begin(), node_list.end());
    this->length+=node_list.size();
    return node_list.size();
}

void Table::addOneNode(Node node) {
    this->data_list->push_back(node);
    this->add_list->push_back(node);
    this->length++;
}

int Table::check_node(list<Node> node_list) {

}

Node Table::getNodeByIndex(int index) {

}

list<Node> Table::getAllData() {
    return *this->data_list;
}

list<Node> Table::findAttrByRange(int attrId) {

}

int Table::writeFile() {

}

int Table::readFile(string path) {

}

// write added list node to file
int Table::merge() {

}

Table::~Table() {
    list<Node>::iterator iter;
    iter = this->data_list->begin();
    while(iter!=this->data_list->end())
    {
        Node current_node = *iter++;
        delete[] current_node.getAllData();
        delete(&current_node);
    }

    delete(this->data_list);
    delete(this->add_list);

}
