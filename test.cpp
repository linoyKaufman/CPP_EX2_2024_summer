

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "node.hpp"
#include "tree.hpp"
#include "complex.hpp"
using namespace std;


TEST_CASE("Tree traverse on binary tree with double")
{
    Node<double> root_node(1.1);
    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    Tree<double> tree(2);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);



    SUBCASE("PreOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("PostOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
        {

            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.4, 1.5, 1.2, 1.6, 1.3, 1.1};
        CHECK(result == excepted);
    }

    SUBCASE("InOrder")
    {
        vector<double> result;
        for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.4, 1.2, 1.5, 1.1, 1.6, 1.3};
        CHECK(result == excepted);
    }

    SUBCASE("BFS")
    {
        vector<double> result;
        for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("DFS")
    {
        vector<double> result;
        for (auto node = tree.begin_dfs_scan(); node != tree.end_dfs_scan(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.4, 1.5, 1.3, 1.6};
        CHECK(result == excepted);
    }

    SUBCASE("Min Heap")
    {
        vector<double> result;
        for (auto node = tree.begin_heap(); node != tree.end_heap(); ++node)
        {
            result.push_back(node->get_value());
        }
        vector<double> excepted = {1.1, 1.2, 1.3, 1.4, 1.5, 1.6};
        CHECK(result == excepted);
    }
}



