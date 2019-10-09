//
// Created by Administrator on 2019/10/9.
//

#ifndef STORE_TABLE_H
#define STORE_TABLE_H


#include <list>
#include <string>
#include "node.h"

using namespace std;

class Table {
private:
    list<Node> *data_list;
    list<Node> *add_list;
    int length;

public:
    Table();
    Table(list<Node> *data_list, int length);
    Table(string path);

    Node getNodeByIndex(int index);
    list<Node> getAllData();

    // 通过Node中属性的id和值范围寻找node
    list<Node> findAttrByRange(int attrId);

    void addOneNode(Node node);

    int addNodes(list<Node> node_list);

    int merge();

    //write to file, format json
    int writeFile();

    //read disk file
    int readFile(string path);

    //check node id
    int check_node(list<Node> node_list);

    ~Table();

};


#endif //STORE_TABLE_H
