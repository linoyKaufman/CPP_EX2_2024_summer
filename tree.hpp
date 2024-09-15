#ifndef TREE_HPP
#define TREE_HPP

#include <vector>
#include <iomanip>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include "node.hpp"
#include "complex.hpp"

using namespace std;
template <typename T>
class Tree{
private:
    Node<T> *root;//root of the tree
    size_t k;//max number of children 

public:
    explicit Tree(size_t k = 2) : root(nullptr), k(k) {}//constractor
    ~Tree() {}//destractord
//add root to the tree
    void add_root(Node<T> &node){
        if (!root){root = &node;}
        else{throw runtime_error("Error .The root the the tree exists");}
    }
//return the root of the tree
    Node<T> *get_root() const{
        return root;
    }

//add children node to a specific node(parent)
    void add_sub_node(Node<T> &parent, Node<T> &ch){
    //check if exist root
        if (!root){throw runtime_error("Tree empty");}
        //check if the number of children < k 
        if (parent.children.size() < k){parent.add_child(&ch);}
        //if the number of children > k throw error not poossible to add children 
        else{throw runtime_error("The number of children not can great that k");}
    }


public:
    class PreOrderIterator{
    private:
        stack<Node<T> *> st; //stack for the preorder

    public:
        PreOrderIterator() = default;
        //constractord
        //add the root to the stack 
        PreOrderIterator(Node<T> *root){
            if (root){st.push(root);}
        }

//operators
        bool operator!=(const PreOrderIterator &other) const{ return !st.empty();}
        Node<T> &operator*() const{ return *st.top(); }
        Node<T> *operator->() const{return st.top();}
        PreOrderIterator &operator++(){
            Node<T> *node = st.top();
            st.pop();                
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i){
                st.push(*i);
            }
            return *this;
        }
    };

    class PostOrderIterator{
    private:
        stack<Node<T> *> st, st2;//two stack for postorder

    public:
        PostOrderIterator() = default;
        
        //constractor
        PostOrderIterator(Node<T> *root){
            if (root){
                st.push(root);
                while (!st.empty()){
                    Node<T> *node = st.top();
                    st.pop();
                    st2.push(node);
                    for (auto ch : node->children){
                        st.push(ch);
                    }
                }
            }
        }

        //operators
        bool operator!=(const PostOrderIterator &other) const{return !st2.empty();}
        Node<T> &operator*() const{return *st2.top();}
        Node<T> *operator->() const{ return st2.top();}
        PostOrderIterator &operator++(){
            st2.pop();
            return *this;
        }
    };



    class BFSIterator{
    private:
        queue<Node<T> *> que;//queu for bfs iterator

    public:
        BFSIterator() = default;
        //cosntractor
        BFSIterator(Node<T> *root){
            if (root){
                que.push(root); 
            }
        }
       //operators 
        bool operator!=(const BFSIterator &other) const{return !que.empty();}
        Node<T> &operator*() const{return *que.front(); }
        Node<T> *operator->() const{return que.front(); }
        BFSIterator &operator++(){
            Node<T> *node = que.front(); 
            que.pop();                  
            for (auto ch : node->children) {
                que.push(ch);
            }
            return *this;
        }
    };
    
        class InOrderIterator{
    private:
        stack<Node<T> *> st; //stack for inorder iterator
        Node<T> *curr_node;    //current node  

        void push_left(Node<T> *node) {
            while (node){
                st.push(node);
                if(!node->children.empty() ){
                     node=node->children[0];
                }
                else{
                  node= nullptr;
                }
            }
        }

    public:
        InOrderIterator() = default;
        //constractor
        InOrderIterator(Node<T> *root) : curr_node(root){
            push_left(root);
        }
        //operator
        bool operator!=(const InOrderIterator &other) const{ return !st.empty();}
        Node<T> &operator*() const{ return st.top();}
        Node<T> *operator->() const{return st.top();}
        InOrderIterator &operator++(){
            Node<T> *node = st.top();
            st.pop();
            if (!node->children.empty()){
                for (size_t i = 1; i < node->children.size(); ++i){
                    push_left(node->children[i]);
                }
            }
            return *this;
        }
    };
    

    class DFSIterator {
    private:
        stack<Node<T> *> st;

    public:
        DFSIterator() = default;
        DFSIterator(Node<T> *root){
            if (root){st.push(root);}
        }
        //operators
        bool operator!=(const DFSIterator &other) const{ return !st.empty();}
        Node<T> &operator*(){ return *st.top();}
        Node<T> *operator->() {return st.top(); }
        DFSIterator &operator++(){
            Node<T> *node = st.top(); 
            st.pop();                 
            for (auto i = node->children.rbegin(); i != node->children.rend(); ++i){
                st.push(*i);
            }
            return *this;
        }
    };

    class HeapIterator{
    private:
        vector<Node<T> *> vec_heap;
        struct NodeCompartor{
            bool operator()(Node<T> *n1, Node<T> *n2){
                return n1->get_value() > n2->get_value();
            }
        };

        void collect_nodes(Node<T> *node){
            if (node){
                vec_heap.push_back(node);
                for (auto ch : node->get_children()){
                    collect_nodes(ch); 
                }
            }
        }

    public:
        HeapIterator() = default;
        HeapIterator(Node<T> *root, size_t k){
            if (k != 2){
                throw runtime_error("The k must be 2 to heap tree");
            }
            if (root){
                collect_nodes(root);  
                make_heap(vec_heap.begin(), vec_heap.end(), NodeCompartor());
            }
        }

       //operators
        bool operator!=(const HeapIterator &other) const{return !vec_heap.empty() != !other.vec_heap.empty();}
        Node<T> *operator->() const{return vec_heap.front();}
        Node<T> &operator*() const{return *vec_heap.front();}
        HeapIterator &operator++(){
            if (!vec_heap.empty()){
                pop_heap(vec_heap.begin(), vec_heap.end(), NodeCompartor()); 
                vec_heap.pop_back();                                          
            }
            return *this;
        }
    };

    //begin ,end iterator
    auto begin_pre_order() const{return PreOrderIterator(root);}
    auto end_pre_order() const{return PreOrderIterator();}
    auto begin_post_order() const{return PostOrderIterator(root);}
    auto end_post_order() const{return PostOrderIterator();}
    auto begin_in_order() const{return InOrderIterator(root);}
    auto end_in_order() const{ return InOrderIterator();}
    auto begin_heap() const{return HeapIterator(root, k);}
    auto end_heap() const{return HeapIterator();}
    auto begin_bfs_scan() const{return BFSIterator(root);}
    auto end_bfs_scan() const{return BFSIterator();}
    auto begin_dfs_scan() const{return DFSIterator(root);}
    auto end_dfs_scan() const{return DFSIterator();}
 
};

#endif
