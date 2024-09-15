
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"
#include "gui.hpp"
#include "complex"

using namespace std;

int main(){
//declaration of the node of type double
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);
    Node<double> n6(1.7);
    Node<double> n7(1.8);
    Node<double> n8(1.9);
    Node<double> n9(1.10);
    Node<double> n10(1.11);
    
//declaration of tree of type double
    Tree<double> tree_double; 
    tree_double.add_root(root_node);
    tree_double.add_sub_node(root_node, n1);
    tree_double.add_sub_node(root_node, n2);
    tree_double.add_sub_node(n1, n3);
    tree_double.add_sub_node(n1, n4);
    tree_double.add_sub_node(n2, n5);
    
//display the tree_double on the screen
    Draw<double> d1(tree_double);
    d1.display();

//print all iterators
    cout << "Preorder : " << endl;
    for (auto node = tree_double.begin_pre_order(); node != tree_double.end_pre_order(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "Postorder: " << endl;
    for (auto node = tree_double.begin_post_order(); node != tree_double.end_post_order(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "Inorder : " << endl;
    for (auto node = tree_double.begin_in_order(); node != tree_double.end_in_order(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "BFS : " << endl;
    for (auto node = tree_double.begin_bfs_scan(); node != tree_double.end_bfs_scan(); ++node){
        cout << node->get_value() << endl;
    } 

    cout << "DFS : " << endl;
    for (auto node = tree_double.begin_dfs_scan(); node != tree_double.end_dfs_scan(); ++node){
        cout << node->get_value() << endl;
    } 

    cout << "Min Heap :" << endl;
    for (auto node = tree_double.begin_heap(); node != tree_double.end_heap(); ++node){
        cout << node->get_value() << endl;
    } 
    
     //clear the tree 
    root_node.clear_children();
    n1.clear_children();
    n2.clear_children();
    n3.clear_children();
    n4.clear_children();
    n5.clear_children();
    
//declaration of tree of type double with 3 childrens
    Tree<double> tree_3_children(3); 
    tree_3_children.add_root(root_node);
    tree_3_children.add_sub_node(root_node, n1);
    tree_3_children.add_sub_node(root_node, n2);
    tree_3_children.add_sub_node(root_node, n3);
    tree_3_children.add_sub_node(n1, n4);
    tree_3_children.add_sub_node(n1, n5);
    tree_3_children.add_sub_node(n1, n6);
    tree_3_children.add_sub_node(n2, n7);
    tree_3_children.add_sub_node(n2, n8);
    tree_3_children.add_sub_node(n3, n9);
    tree_3_children.add_sub_node(n3, n10);
//display the tree_double on the screen
    Draw<double> d2(tree_3_children);
    d2.display();
    
//print all iterators
    cout << "BFS : " << endl;
    for (auto node = tree_3_children.begin_bfs_scan(); node != tree_3_children.end_bfs_scan(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "DFS : " << endl;
    for (auto node = tree_3_children.begin_dfs_scan(); node != tree_3_children.end_dfs_scan(); ++node){
        cout << node->get_value() << endl;
    }

     cout << "Preorder : " << endl;
    for (auto node = tree_3_children.begin_pre_order(); node != tree_3_children.end_pre_order(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "Postorder: " << endl;
    for (auto node = tree_3_children.begin_post_order(); node != tree_3_children.end_post_order(); ++node){
        cout << node->get_value() << endl;
    }

    cout << "Inorder : " << endl;
    for (auto node = tree_3_children.begin_in_order(); node != tree_3_children.end_in_order(); ++node){
        cout << node->get_value() << endl;
    }

}
