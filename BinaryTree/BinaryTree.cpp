// BinaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>

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
    Node* getRoot() const {
        return root;
    }
    void addNode(int key) {
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
            } else {
                q.push(current->left);
            }

            if (current->right == nullptr) {
                current->right = newNode;
                std::cout << "Узел " << key << " добавлен в дерево." << std::endl;
                return;
            } else {
                q.push(current->right);
            }
        }
    }

    void removeNodes(int key) {
        if (root == nullptr) {
            std::cout << "Дерево пустое." << std::endl;
            return;
        }

        Node* parent = nullptr;
        Node* current = root;

        std::queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            current = q.front();
            q.pop();

            if (current->key == key) {
                break;
            }

            parent = current;

            if (current->left != nullptr) {
                q.push(current->left);
            }

            if (current->right != nullptr) {
                q.push(current->right);
            }
        }

        if (current == nullptr) {
            std::cout << "Узел с ключом " << key << " не найден в дереве." << std::endl;
            return;
        }

        if (parent == nullptr) {
            root = nullptr; // Удаляем корень
        } else if (parent->left == current) {
            parent->left = nullptr;
        } else {
            parent->right = nullptr;
        }

        delete current;
        std::cout << "Узлы с ключом " << key << " удалены из дерева." << std::endl;
    }

    void print(Node* root, int space) {
        if (root == nullptr) {
            return;
        }

        int COUNT = 3;  // Расстояние между уровнями узлов

        space += COUNT;

        print(root->right, space);

        std::cout << std::endl;
        for (int i = COUNT; i < space; i++) {
            std::cout << " ";
        }
        std::cout << root->key << "\n";

        print(root->left, space);
    }

    void print() {
        if (root == nullptr) {
            std::cout << "Дерево пустое." << std::endl;
            return;
        }

        std::cout << "Двоичное дерево (горизонтальный вид):" << std::endl;
        print(root, 0);
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

    std::cout << "Двоичное дерево (горизонтальный вид):" << std::endl;
    tree.print();

    tree.removeNodes(30);
    tree.print(tree.getRoot(), 0); // Печатаем после первого удаления


    return 0;
}

