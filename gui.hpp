
#ifndef GUI_HPP
#define GUI_HPP

#include <SFML/Graphics.hpp>
#include "tree.hpp"
#include "complex.hpp"
#include <iostream>
#include <sstream>
#include <iomanip> 
#include <map>
#include <functional>

//class for draw the tree
template <typename T>
class Draw {
private:
    Tree<T>& tree;//tree
    sf::RenderWindow screen;//window
    std::map<Node<T>*, sf::Vector2f> vec_emplacements;//vector for position of the nodes
    sf::Font f;//font 
   
   //help fonction to load the font 
    bool load_font() {
        if (!f.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf")) {
            std::cerr << "Error in load font " << std::endl;
            return false;
        }
        return true;
    }
//help ffunction to compute the position of the nodes of the tree
    void emplacement_nodes(Node<T>* node, float x, float y, float space) {
    //check if node exist
        if (!node) return;
        //update the position of the node to be (x,y)
        vec_emplacements[node] = sf::Vector2f(x, y);
        float f = x - (node->get_children().size() - 1) * space / 2.f;
        //compute the position of the childrens of the node by recursia
        for (size_t i = 0; i < node->get_children().size(); ++i) {
            Node<T>* ch = node->get_children()[i];
            if (ch) {emplacement_nodes(ch, f + i * space, y + 80.0f, space / 2.f);}
        }
    }
//main fonction to draw the tree
    void draw_tree() {
        for (const auto& p : vec_emplacements) {
            Node<T>* node = p.first;
            sf::Vector2f vec = p.second;

            // Draw the circle
            sf::CircleShape circle(25.0f);
            circle.setFillColor(sf::Color::Red);
            circle.setPosition(vec - sf::Vector2f(23.0f,23.0f));
            screen.draw(circle);

            // Draw the value of the node
            sf::Text value_node;
            value_node.setFont(f);
            std::ostringstream s;
            s << node->key;
            value_node.setString(s.str());
            value_node.setCharacterSize(20);
            value_node.setFillColor(sf::Color::Black);
            sf::FloatRect fr = value_node.getLocalBounds();
            value_node.setOrigin(fr.left + fr.width / 1.9f, fr.top + fr.height / 1.9f);
            value_node.setPosition(vec);
            screen.draw(value_node);

            // draw the lines for the childrens
            for (Node<T>* ch : node->get_children()) {
                if (ch) {
                    sf::Vector2f vec_child = vec_emplacements[ch];
                    sf::Vertex line[] = {
                        sf::Vertex(vec, sf::Color::Black),
                        sf::Vertex(vec_child, sf::Color::Black)
                    };
                    screen.draw(line, 2, sf::Lines);
                }
            }
        }
    }

public:
//constractor
    Draw(Tree<T>& tree) : tree(tree), screen(sf::VideoMode(800, 1200), "Tree Visualization") {
    //chec kif load font is succefuly 
        if (!load_font()) {
            std::cerr << "not possible to load the font" << std::endl;
            screen.close();
        }
    }
//display the tree on the window 
    void display() {
    //get the root of the tree
        Node<T>* root = tree.get_root();
        //compute the the  position of the nodes
        if (root) {
            emplacement_nodes(root, screen.getSize().x / 2.f, 75.0f, 200.0f);
        }
        while (screen.isOpen()) {
            sf::Event ev;
            while (screen.pollEvent(ev)) {
                if (ev.type == sf::Event::Closed){screen.close();}
                  
            }
            screen.clear(sf::Color::White);
            if (root) {draw_tree();}
            screen.display();
        }
    }
};

#endif
