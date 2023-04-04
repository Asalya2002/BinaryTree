// BinaryTree.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <random>
using namespace std;
class BinaryTree
{
    class Node
    {
    public:
        int key;
        Node* leftChild;
        Node* rightChild;
        Node()     //конструктор по умолчанию 
        {
            leftChild = nullptr;
            rightChild = nullptr;
        }
        Node(int key, Node* leftChild = nullptr, Node* rightChild = nullptr) //конструктор с параметрами
        {
            m_leftChild = leftChild;
            m_rightChild = rightChild;
        }
        ~Node() = default;
        int getkey() const { return m_key; }
        void setKey(const int key) { m_key = key; }
        Node* getleftChild() { return  m_leftChild; }
        void setleftChild(Node* leftChild) { m_leftChild = leftChild; }
        Node* getrightChild() { return  m_rightChild; }
        void setrightChild(Node* rightChild) { m_rightChild = rightChild; }
    private:
        friend class BinaryTree;
        int m_key = 0;             //ключ
        Node* m_leftChild = nullptr;   //указатель на левого потомка данной вершины.
    Node* m_rightChild = nullptr;// указатель на правого потомка данной вершины.
    }; 
 private:
    Node* m_root = nullptr;  //указатель на корень дерева.
    
  public:
    BinaryTree() = default; //конструктор по умолчанию 
    BinaryTree(const BinaryTree&) = default;  //конструктор  копирования
    ~BinaryTree() { delete m_root; }  //деструктор
    Node* root() const; //получение корня
    Node* addNode(int key); //Вспомогательная функция, для добавления узла относительно корня
    Node* addNode(Node* root, int key);//Добавление узла в двоичное дерево
    int height(Node* root);// Рекурсивная функция для вычисления высоты заданного бинарного дерева
    bool DeleteUzel(Node* root);//Удаление всех узлов и через ключ
    void Deletesubtree(); //удаление поддерева 
    bool isEmpty(); //функция пустоты
    int NodeCount(Node* root);  //поиск числа узлов
    bool isBalanced(Node* root); //проверка дерева на сбалансированность
    int sum_k(Node* root, int key); // получение суммы всех ключей дерева
    void printHorizontal() const; //Вывод двоичного дерева 
    void printMinMax(Node* root);// получение минимального максимального ключа дерева;

    BinaryTree::Node* root() const
    {
        return m_root;
    }
    Node* addNode(int key)  //Вспомогательная функция, для добавления узла относительно корня
    {
        m_root = addNode(m_root, key);
        return m_root;
    }
    Node* addNode(Node* root, int key)
    {
        if (!root) {
            root = new Node(key);
        }
        else if (rand() % 2) {
            root->setleftChild(addNode(root->leftChild, key));
        }
        else {
            root->setrightChild(addNode(root->rightChild, key));
        }

        return root;

    }
    bool isEmpty(Node* root)
    {
        if (!root)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void Deletesubtree(Node* Subroot)
    {
        if (Subroot != NULL)
            Deletesubtree(Subroot->leftChild);
        Deletesubtree(Subroot->rightChild);
        delete Subroot;
    }
    bool DeleteUzel(Node* root)
    {
        if (root != NULL)
        {
            DeleteUzel((root)->leftChild);
            DeleteUzel((root)->rightChild);
            delete& (root)->key;
            delete root;
            return true;
        }
    }
    void printHorizontal(Node* root, int marginLeft, int levelSpacing) const
    {
        if (root == nullptr) {
            return;
        }
        printHorizontal(root->rightChild, marginLeft + levelSpacing, levelSpacing);
        cout << string(marginLeft, ' ') << root->key << endl;
        printHorizontal(root->leftChild, marginLeft + levelSpacing, levelSpacing);
    }
    // Рекурсивная функция для вычисления высоты заданного бинарного дерева
    int height(Node* root)
    {
        // базовый случай: пустое дерево имеет высоту 0
        if (root == nullptr) {
            return 0;
        }
        // повторяем для левого и правого поддерева и учитываем максимальную глубину
        return 1 + max(height(root->leftChild), height(root->rightChild));
    }
    int NodeCount(Node* root)  //поиск числа узлов
    {
        if (root->leftChild == NULL && root->rightChild == NULL)
            return 1;
        int left, right;
        if (root->leftChild != NULL)
            left = NodeCount(root->leftChild);
        else
            left = 0;
        if (root->rightChild != NULL)
            right = NodeCount(root->rightChild);
        else
            right = 0;

        return left + right + 1;
    }
    void printMinMax(Node* root) {
        if (root == NULL)
        {
            cout << "Tree is empty";
            return;
        }
        Node* current = root;

        Node* pre;

        // Максимальная переменная для хранения максимального значения  
        int max_value = INT_MIN;

        // Переменная  Min для сохранения минимального значения
        int min_value = INT_MAX;
        while (current != NULL)
        {
            // Если левый дочерний элемент не существует
            if (current->leftChild == NULL)
            {
                max_value = max(max_value, current->key);
                min_value = min(min_value, current->key);

                current = current->rightChild;
            }
            else
            {
                // Найти порядок, предшествующий текущему
                pre = current->leftChild;
                while (pre->rightChild != NULL && pre->rightChild != current)
                    pre = pre->rightChild;

                // Сделать current правым дочерним элементом
     // своего предшественника по порядку
                if (pre->rightChild == NULL)
                {
                    pre->rightChild = current;
                    current = current->leftChild;
                }

                // Верните изменения, внесенные в части 'if', чтобы
    // восстановить исходное дерево, т.е. исправить
    // правый дочерний элемент предшественника
                else
                {
                    pre->rightChild = NULL;

                    max_value = max(max_value, current->key);
                    min_value = min(min_value, current->key);

                    current = current->rightChild;
                } // Конец условия if pre->right == NULL

            } // Конец текущего условия if->оставлено == NULL

        }

        // Наконец, выведите максимальное и минимальное значения
        cout << "Max Value is : " << max_value << endl;
        cout << "Min Value is : " << min_value << endl;
    }
    bool isBalanced(Node* root)
    {
        //высота для левого поддерева
        int lh;

        //высота для правого поддерева
        int rh;

        // Если дерево пустое, то вернет значение true
        if (root == NULL)
            return 1;

        //Получите высоту левого и правого поддеревьев
        lh = height(root->leftChild);
        rh = height(root->rightChild);

        if (abs(lh - rh) <= 1 && isBalanced(root->leftChild)
            && isBalanced(root->rightChild))
            return 1;

        // Если мы доберемся сюда, то дерево не будет сбалансировано по высоте
        return 0;
    }
    int sum_k(Node* root, int key) // получение суммы всех ключей дерева
    {
        int sum = 0;
        if ((root != NULL) && (key > 0))
        {
            sum += sum_k(root->leftChild, key - 1);
            sum += sum_k(root->rightChild, key - 1);
        }
        return sum;
    }
    BinaryTree& operator=(const BinaryTree& root) //присваивание
    {
        if (this != &root)
        {
            this->~BinaryTree();

        }
        return *this;
    }

    int main()
    {
        Node* root = NULL; // указатель на корень дерева
        setlocale(LC_ALL, "rus");
        // чтобы генератор каждый раз возвращал различные числа
        srand((unsigned)time(0));
        Node* addNode(int key); //Вспомогательная функция, для добавления узла относительно корня
        Node* addNode(Node * root, int key);//Добавление узла в двоичное дерево
        int height(Node * root);// Рекурсивная функция для вычисления высоты заданного бинарного дерева
        int NodeCount(Node * root);  //поиск числа узлов
        bool isBalanced(Node * root); //проверка дерева на сбалансированность
        int sum_k(Node * root, int key); // получение суммы всех ключей дерева
        void printHorizontal(); //Вывод двоичного дерева 
        void printMinMax(Node * root);
        bool DeleteUzel(Node * root);//Удаление всех узлов и через ключ
        void Deletesubtree(); //удаление поддерева 
        bool isEmpty(); //функция пустоты
        system("pause");
        return 0;
    }
};


