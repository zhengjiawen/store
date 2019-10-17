//
// Created by Administrator on 2019/10/13.
//

#ifndef STORE_INDEX_H
#define STORE_INDEX_H

#include <map>
#include <vector>
#include <string>
#include "node.h"


using namespace std;


class Index {
private:
    multimap<DATA_TYPE, Node&> map;
    multimap<DATA_TYPE, int> value2id;
    int attr_id;

public:
    Index()= delete;
    Index(int attr_Id);
    Index(vector<Node>& node_list, int attr_Id);
    Index(string path);
    Index(const Index &index);

    void insert(Node& node);
    int findNodebyValue(vector<Node> &ret, DATA_TYPE value);
    int findNodebyValue(vector<Node> &ret, DATA_TYPE low, DATA_TYPE high, int max_len);


    int get_attr_Id();

    int write_to_file(string path);





};


#endif //STORE_INDEX_H
