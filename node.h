//
// Created by zheng on 2019/10/9.
//

#ifndef STORE_NODE_H
#define STORE_NODE_H

#define DATA_TYPE long long

class Node{
private:
    DATA_TYPE *data;
    int length;
    int id;
    static int idGen;

public:
    Node();
    Node(int id,int length, DATA_TYPE *data);
    Node(int length, DATA_TYPE *data);

    Node(const Node &node);

    int getLength();
    int getId();
    void setId(int id);
    DATA_TYPE* getAllData();
    DATA_TYPE getDataById(int index);
    static int getIdGen();

    ~Node();

};
#endif //STORE_NODE_H
