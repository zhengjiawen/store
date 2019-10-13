#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "table.h"
#include "node.h"
#include "index.h"

using namespace std;

void print_table(Table& table)
{
    vector<Node> node_list = table.getAllData();

    vector<Node>::iterator iter;
    iter = node_list.begin();

    while(iter!=node_list.end())
    {
        Node current_node = (*iter++);
        int* data = current_node.getAllData();
        cout << current_node.getId() << " ";
        for(int i=0; i<current_node.getLength(); i++)
        {
            cout << *(data+i) << " ";
        }
        cout<<endl;
    }
}

void print_table(vector<Node>& node_list)
{

    vector<Node>::iterator iter;
    iter = node_list.begin();

    while(iter!=node_list.end())
    {
        Node current_node = (*iter++);
        cout << current_node.getId() << " ";

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

void gen_random_node(vector<Node> &list, int index)
{
    for(int i=0; i<index; i++)
    {
        int* data = new int[5];
        for(int j=0; j<5; j++)
        {
            *(data+j) = rand()%(10000);
        }
        int id = list.size()+1;
        list.emplace_back(id, 5, data);
    }
}

int main() {
    unsigned int seed = 100;
    srand(seed);
    vector<Node> node_list;
    gen_random_node(node_list, 3);

    // init table
    Table table_p(node_list, node_list.size());
    cout << "=====================init table=====================" << endl;
    print_table(table_p);

    gen_random_node(node_list, 1);

    int* data = new int[5];
    for(int j=0; j<5; j++)
    {
        *(data+j) = rand()%10000;
    }
    Node node(11, 5, data);
    table_p.addOneNode(node);

    cout << "=====================add node=====================" << endl;
    print_table(table_p);

    cout << "=====================find node by id=====================" << endl;
    Node node_by_index = table_p.getNodeByIndex(2);
    cout << node_by_index.getId() << endl;

    cout << "=====================find node by id and range=====================" << endl;
    vector<Node> search_ret;
    table_p.findAttrByRange(search_ret,0, 1000, 10000, 2);
    print_table(search_ret);

    cout << "=====================create index=====================" << endl;
    Index index(table_p.getAllData(), 0);
    vector<Node> index_ret ;
    index.findNodebyValue(index_ret, 180);
    print_table(index_ret);

    return 0;
}