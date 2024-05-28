//Дано бинарное дерево. Определить количество узлов на N-м уровне
//бинарного дерева(N ввести с клавиатуры)/
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

int countNodesAtLevel(Node* root, int level) {
    if (root == nullptr)
        return 0;

    if (level == 1)
        return 1;

    int leftCount = countNodesAtLevel(root->left, level - 1);
    int rightCount = countNodesAtLevel(root->right, level - 1);

    return leftCount + rightCount;
}

int main() {
    setlocale(LC_ALL, "Ru");

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    int level;
    cout << "Введите уровень: ";
    cin >> level;

    int count = countNodesAtLevel(root, level);

    cout << "Количество узлов на уровне " << level << ": " << count << endl;

    return 0;
}