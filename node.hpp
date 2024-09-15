#ifndef NODE_HPP
#define NODE_HPP

#include <vector>
using namespace std;

template <typename T>
class Node{

public:
//value of the node
    T key;
//childrens of the node
    vector<Node<T> *> children;

    //constractor
    Node(T value) : key(value) {}

    //main function of the node
    T get_value() const{return key;}
    vector<Node *> &get_children(){return children;}
    void add_child(Node<T> *child){ children.push_back(child);}
    void clear_children(){children.clear();}
};

#endif
