#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "table.h"
#include "node.h"

using namespace std;

void print_table(Table *table)
{
    list<Node>* node_list = table->getAllData();

    list<Node>::iterator iter;
    iter = node_list->begin();

    while(iter!=node_list->end())
    {
        Node* current_node = &(*iter++);
        int* data = current_node->getAllData();
        for(int i=0; i<current_node->getLength(); i++)
        {
            cout << *(data+i) << " ";
        }
        cout<<endl;
    }
}

Node* gen_random_node(int id)
{
    int* data = new int[5];
    for(int j=0; j<5; j++)
    {
        *(data+j) = rand();
    }

    Node *node = new Node(id, 5, data);
    return node;
}

int main() {
    unsigned int seed = 100;
    srand(seed);
    list<Node> *node_list = new list<Node>();
    for(int i=0; i<10; i++)
    {
        Node* node = gen_random_node(i);
        node_list->push_back(*node);
    }

    // init table
    Table *table_p = new Table(node_list, node_list->size());
    cout << "=====================init table=====================" << endl;
    print_table(table_p);

    Node *added_node = gen_random_node(11);
    table_p->addOneNode(*added_node);

    cout << "=====================add node=====================" << endl;
    print_table(table_p);


    delete(table_p);
    return 0;
}