#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "table.h"
#include "node.h"

using namespace std;

void print_table(Table& table)
{
    list<Node> node_list = table.getAllData();

    list<Node>::iterator iter;
    iter = node_list.begin();

    while(iter!=node_list.end())
    {
        Node current_node = (*iter++);
        int* data = current_node.getAllData();
        for(int i=0; i<current_node.getLength(); i++)
        {
            cout << *(data+i) << " ";
        }
        cout<<endl;
    }
}

//Node* gen_random_node(int id)
//{
//    int* data = new int[5];
//    for(int j=0; j<5; j++)
//    {
//        *(data+j) = rand();
//    }
//
//    Node* node = new Node(id, 5, data);
//    return node;
//}

void gen_random_node(list<Node> &list, int index)
{
    for(int i=0; i<index; i++)
    {
        int* data = new int[5];
        for(int j=0; j<5; j++)
        {
            *(data+j) = rand();
        }
        int id = list.size()+i;
        list.emplace_back(id, 5, data);
    }
}

int main() {
    unsigned int seed = 100;
    srand(seed);
    list<Node> node_list;
    gen_random_node(node_list, 3);

    // init table
    Table table_p(node_list, node_list.size());
    cout << "=====================init table=====================" << endl;
    print_table(table_p);

    gen_random_node(node_list, 1);

    int* data = new int[5];
    for(int j=0; j<5; j++)
    {
        *(data+j) = rand();
    }
    Node node(11, 5, data);
    table_p.addOneNode(node);

    cout << "=====================add node=====================" << endl;
    print_table(table_p);


    return 0;
}