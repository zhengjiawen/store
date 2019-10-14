//
// Created by Administrator on 2019/10/9.
//

#ifndef STORE_TABLE_H
#define STORE_TABLE_H


#include <vector>
#include <string>
#include <utility>
#include "node.h"
#include <set>
#include <iostream>
#include <thread>
#include <fstream>


using namespace std;

class Table {
private:
    vector<Node> data_list;
    vector<Node> add_list;
    set<int> id_set;
    int length;
    string path;
    fstream outfile;


public:
    Table();
    Table(vector<Node>& data_list, int length);
    //attr_len是每个node属性的数量
    Table(string path, int attr_len);

    Node& getNodeByIndex(int index);
    vector<Node>& getAllData();

    // 通过Node中属性的id和值范围寻找node
    int findAttrByRange(vector<Node>& ret,int attrId, DATA_TYPE low, DATA_TYPE high ,int max_len=10e6);

    void addOneNode(int id, int length, DATA_TYPE* data);

    void addOneNode(Node& node);

    int addNodes(vector<Node>& node_list);

    int merge();

    //write to file
    int writeFile();
    int writeFile(string &output_path);

    //read disk file
    int readFile(string path);

    //check node id
    int check_node(int id);

    void check_data_list(vector<Node>& data_list);

    ~Table();

};


#endif //STORE_TABLE_H
