//
// Created by Administrator on 2019/10/13.
//

#include "index.h"


Index::Index(int attr_id):attr_id(attr_id) {}

Index::Index(vector<Node> &node_list, int attr_Id):attr_id(attr_Id) {
    for(int i=0; i<node_list.size(); i++)
    {
        map.insert({node_list[i].getDataById(attr_Id), node_list[i]});
        value2id.insert({node_list[i].getDataById(attr_Id), node_list[i].getId()});
    }
}

Index::Index(const Index &index):attr_id(index.attr_id) {
    map = index.map;
}

Index::Index(string path) {}

void Index::insert(Node &node) {
    this->map.insert({node.getDataById(this->attr_id), node});
    this->value2id.insert({node.getDataById(this->attr_id), node.getId()});
}

int Index::findNodebyValue(vector<Node> &ret, DATA_TYPE value) {
    int count=0;
    for(auto pos = this->map.equal_range(value); pos.first!=pos.second; ++pos.first)
    {
        ret.emplace_back(pos.first->second.getId(), pos.first->second.getLength(), pos.first->second.getAllData());

        count++;
    }
    return count;
}

int Index::get_attr_Id() {
    return this->get_attr_Id();
}

int Index::write_to_file(string path) {}