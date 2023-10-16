// BinaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <queue>
#include <stack>

class Node {
public:
    int key;
    Node* left;
    Node* right;

    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

public:
    BinaryTree() : root(nullptr) {}

    void addNode(int key) {   //Добавление узла 
        Node* newNode = new Node(key);

        if (root == nullptr) {
            root = newNode;
            std::cout << "Узел " << key << " добавлен в дерево." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->left == nullptr) {
                current->left = newNode;
                std::cout << "Узел " << key << " добавлен в дерево." << std::endl;
                return;
            }
            else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                std::cout << "Узел " << key << " добавлен в дерево." << std::endl;
                return;
            }
            else {
                q.push(current->right);
            }
        }
    }

    void removeNodes(int key) {   //удаление узла
        if (root == nullptr) {
            std::cout << "Дерево пустое." << std::endl;
            return;
        }

        std::queue<Node*> q;
        std::stack<Node*> s;

        q.push(root);
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            if (current->key == key) {
                s.push(current);
            }

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            delete current;
        }

        std::cout << "Узлы с ключом " << key << " удалены из дерева." << std::endl;
    }

    void print() {   //Вывод двоичного дерева в горизонтальном виде
        if (root == nullptr) {
            std::cout << "Дерево пустое." << std::endl;
            return;
        }

        std::queue<Node*> q;
        q.push(root);

        std::cout << "Двоичное дерево (горизонтальный вид):" << std::endl;
        while (!q.empty()) {
            int levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();

                std::cout << current->key << " ";

                if (current->left != nullptr) {
                    q.push(current->left);
                }

                if (current->right != nullptr) {
                    q.push(current->right);
                }
            }

            std::cout << std::endl;
        }
    }
};

int main() {
    BinaryTree tree;

    tree.addNode(50);
    tree.addNode(30);
    tree.addNode(20);
    tree.addNode(40);
    tree.addNode(70);
    tree.addNode(60);
    tree.addNode(80);

    tree.print();

    tree.removeNodes(30);
    tree.removeNodes(60);

    tree.print();

    return 0;
}


