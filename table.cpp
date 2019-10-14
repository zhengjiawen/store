//
// Created by Administrator on 2019/10/9.
//

#include "table.h"


Table::Table():length(0) {}

Table::Table(string path, int attr_len):path(path) {
    fstream infile;
    infile.open(this->path, ios::in);

    int count=0;
    DATA_TYPE* data = new DATA_TYPE[attr_len];
    int id;
    while (!infile.eof())
    {
        if(infile.fail())
            break;
        if(count == 0)
        {
            infile >> id;
        }

        infile >> data[count%attr_len];
//        cout << data[count%attr_len] << endl;

        if(count%attr_len==0 && count !=0)
        {
            this->data_list.emplace_back(id, attr_len, data);
            infile >> id;
        }
        count++;


    }
    delete[] data;
    infile.close();
//    this->outfile.open(this->path, ios::app);

}

Table::Table(vector<Node>& data_list, int length):data_list(data_list), add_list(data_list),length(length) {
    this->check_data_list(data_list);

}

int Table::addNodes(vector<Node>& node_list) {
    this->check_data_list(node_list);
    this->data_list.insert(this->data_list.end(), node_list.begin(), node_list.end());
    this->add_list.insert(this->add_list.end(), node_list.begin(), node_list.end());
    this->length+=node_list.size();
    return node_list.size();
}


void Table::addOneNode(Node& node) {
    auto ret = this->check_node(node.getId());

    if(ret == -1)
    {
        cout << "id is not unique" << endl;
        throw "id is not unique";
    }
    this->data_list.emplace_back(node.getId(), node.getLength(), node.getAllData());
    this->add_list.emplace_back(node.getId(), node.getLength(), node.getAllData());
    this->length++;
}
void Table::addOneNode(int id, int length, DATA_TYPE* data)
{
    auto ret = this->check_node(id);
    if(ret == -1)
    {
        cout << "id is not unique" << endl;
        throw "id is not unique";
    }

    this->data_list.emplace_back(id, length, data);
    this->add_list.emplace_back(id, length, data);
    this->length++;
}

// check id is unique
int Table::check_node(int id) {
    auto ret = this->id_set.insert(id);
    if(!ret.second)
        return -1;
    return 0;

}

void Table::check_data_list(vector<Node> &data_list) {
    for(auto &node:data_list){
        int ret = this->check_node(node.getId());
        if(ret == -1)
        {
            cout << "id is not unique" << endl;
            throw "id is not unique";
        }

    }
}

Node& Table::getNodeByIndex(int index) {
    if(index > this->length)
        throw "index must be lower than attr length";

    return this->data_list[index];


}

vector<Node>& Table::getAllData() {
    return this->data_list;
}

//返回找到的node数量
int Table::findAttrByRange(vector<Node>& ret,int attrId, DATA_TYPE low, DATA_TYPE high, int max_len) {
    auto iter = this->data_list.begin();
    int count = 0;

    for(;iter!=this->data_list.end();iter++)
    {
        DATA_TYPE value = (*iter).getDataById(attrId);
        if(value >= low && value <= high)
        {
            ret.emplace_back((*iter).getId(), (*iter).getLength(), (*iter).getAllData());
            count++;
            if(count >= max_len)
                return max_len;
        }
    }
    return count;
}

int Table::writeFile() {
    if(this->path.empty())
    {
        return 0;
    }


    for(auto node:this->add_list)
    {
        DATA_TYPE* data = node.getAllData();
        int len = node.getLength();
        this->outfile << node.getId() << " ";

        for(int i=0; i<len; i++)
        {
            this->outfile << data[i] << " " ;
        }
        this->outfile << endl;
    }
    this->outfile.flush();
    this->add_list.clear();
    return this->add_list.size();

}

int Table::writeFile(string &output_path) {
    this->path=output_path;

    this->outfile.open(this->path, ios::app);

    return writeFile();

}

int Table::readFile(string path) {

}

// write added list node to file
int Table::merge() {

}

Table::~Table() {
    this->outfile.close();

}
