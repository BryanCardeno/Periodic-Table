/*
* Author: Bryan Cardeno
* File : AvlTree.h
* Date : 4/19/2024
* Description: AVLTree template class header file
*/

#pragma once

#include <iostream>

//region TEMPLATE DEFINITION
template <class T>
class AvlTree {
private:
    struct Node {
        T* data;
        Node* left;
        Node* right;
        int height;
        int counter;

        explicit Node(T value);
    };

    Node* root;
public:
//region CONSTRUCTORS
/**
 * @brief working constructor. creates a root node with the value passed.
 * @param value generic data.
 */
explicit AvlTree(T value);

/**
 * @brief default constructor. utilizes working constructor.
 */
AvlTree();
//endregion

//region MUTATORS

/**
 * @brief Insert a node into the proper location of the tree. Outer insert function.
 * @param data generic data to insert.
 */
void insert(T &data);

/**
 * @brief Rotate nodes to the left once to balance tree.
 * @param root_ptr current node.
 */
void rotateWithLeftChild(Node* &root_ptr);

/**
 * @brief Rotate nodes to the right once to balance tree.
 * @param root_ptr current node.
 */
void rotateWithRightChild(Node* &root_ptr);

/**
 * @brief Rotate nodes twice to the left to balance tree.
 * @param root_ptr current node.
 */
void doubleWithLeftChild(Node* &root_ptr);

/**
 * @brief Rotate nodes twice to the right to balance tree.
 * @param root_ptr current node.
 */
void doubleWithRightChild(Node* &root_ptr);
//endregion

//region ACCESSORS
/**
* @brief Find and return the smallest value in the tree. Outer findMin function.
* @return smallest generic value from the tree.
*/
T findMin();

/**
* @brief Find and return the largest value in the tree. Outer findMax function.
* @return largest generic value from the tree.
 */
T findMax();

/**
* @brief Print values of each node in the tree. Outer printTree function.
*/
void printTree();

/**
 * @brief Print values and counter of each node in the tree. Outer printTreeAndCounter function.
 */
void printTreeAndCounter();

/**
 * @brief Retrieve data if it exists. Outer retrieveData function.
 * @param search data to find.
 * @return T generic type if it exists and nullptr if it doesnt.
 */
T* retrieveData(std::string &search);

/**
 * @brief Retr
 * @param search
 * @return
 */
T* retrieveData(int &search);
//endregion

private:
//region HELPERS
int height(Node* &node_ptr);

/**
* @brief Insert node into the tree. Recursive insert function.
* @param node_value generic node value to for comparison.
* @param node_ptr current node in the tree.
*/
void insert(T data, Node* &node_ptr);

/**
* @brief Find the minimum value in the tree. Recursive inner findMin function.
* @param node_ptr current node in the tree.
* @return generic value of the smallest node in the tree.
*/
T findMin(Node* &node_ptr);

/**
* @brief Find the maximum value in the tree. Recursive inner findMax function.
* @param node_ptr current node in the tree.
* @return generic value of the largest node in the tree.
*/
T findMax(Node* &node_ptr);

/**
* @brief Print value of each node in the tree. Recursive inner printTree function.
* @param node_ptr current node in the tree.
*/
void printTree(Node* &node_ptr);

/**
* @brief Print value and counter of each node in the tree. Recursive inner printTreeAndCounter function.
* @param node_ptr current node in the tree.
*/
void printTreeAndCounter(Node* &node_ptr);

/**
 * @brief Determines which node height is higher. .
 * @param left_operator main node height.
 * @param right_operator secondary node height.
 * @return whichever value is larger.
 */
int max(int left_operator, int right_operator);

/**
 * @brief Retrieve node data if it exists.
 * @param search Data to search
 * @param node_ptr current node in the tree.
 * @return data if it exists and nullptr if it doesnt.
 */
T* retrieveData(std::string &search, Node* &node_ptr);

/**
 * @brief Retrieve node data if it exists. Traversing through each level of the tree. Inner recursive function.
 * @param Search Data to search.
 * @param node_ptr current node in the tree.
 * @return data if it iexists and nullptr if it doesnt.
 */
T* retrieveData(int &search, Node* &node_ptr);
//endregion

};

//endregion

//region TEMPLATE IMPLEMENTATION

//region CONSTRUCTORS
template <class T>
AvlTree<T>::AvlTree(T value) {
    root = new Node(value);
}

template <class T>
AvlTree<T>::AvlTree() {
    root = nullptr;
}

template <class T>
AvlTree<T>::Node::Node(T value) {
    data = new T(value);
    left = nullptr;
    right = nullptr;
    counter = 0;
    height = 0;
}
//endregion

//region MUTATORS
template <class T>
void AvlTree<T>::insert(T& data) {
    if(root == nullptr) {
        root = new Node(data);
        ++root->counter;
        return;
    }

    insert(data, root);
}

template<class T>
void AvlTree<T>::rotateWithLeftChild(AvlTree::Node *&root_ptr) {
    Node* temp_node = root_ptr->left;

    root_ptr->left = temp_node->right;
    temp_node->right = root_ptr;

    root_ptr->height = max(height(root_ptr->left), height(root_ptr->right)) + 1;
    temp_node->height = max(height(temp_node->left), root_ptr->height) + 1;

    root_ptr = temp_node;
}

template<class T>
void AvlTree<T>::rotateWithRightChild(AvlTree::Node *&root_ptr) {
    Node* temp_node = root_ptr->right;

    root_ptr->right = temp_node->left;
    temp_node->left = root_ptr;

    root_ptr->height = max(height(root_ptr->left), height(root_ptr->right)) + 1;
    temp_node->height = max(height(temp_node->right), root_ptr->height) + 1;
    root_ptr = temp_node;
}

template<class T>
void AvlTree<T>::doubleWithLeftChild(AvlTree::Node *&root_ptr) {
    rotateWithRightChild(root_ptr->left);
    rotateWithLeftChild(root_ptr);
}

template<class T>
void AvlTree<T>::doubleWithRightChild(AvlTree::Node *&root_ptr) {
    rotateWithLeftChild(root_ptr->right);
    rotateWithRightChild(root_ptr);
}
//endregion

//region ACCESSORS
template<class T>
T AvlTree<T>::findMin() {
    return findMin(root);
}

template<class T>
T AvlTree<T>::findMax() {
    return findMax(root);
}

template<class T>
void AvlTree<T>::printTree() {
    printTree(root);
}

template<class T>
void AvlTree<T>::printTreeAndCounter() {
    printTreeAndCounter(root);
}

template<class T>
T* AvlTree<T>::retrieveData(std::string &search) {

return retrieveData(search, root);
}

template<class T>
T *AvlTree<T>::retrieveData(int &search) {
    return retrieveData(search, root);
}

//endregion

//region HELPERS

template<class T>
int AvlTree<T>::height(AvlTree::Node *&node_ptr) {
    return node_ptr == nullptr ? -1 : node_ptr->height;
}

template<class T>
void AvlTree<T>::insert(T data, AvlTree::Node *&node_ptr) {
    if(node_ptr == nullptr) {
        node_ptr = new Node(data);
        ++node_ptr->counter;
        return;
    }

    if(*(node_ptr->data) == data) {
        ++node_ptr->counter;
        return;
    }

    if(data < *(node_ptr->data)) {
        insert(data, node_ptr->left);

        if(height(node_ptr->left) - height(node_ptr->right) == 2) {
            if(data < *(node_ptr->left->data)) {
                rotateWithLeftChild(node_ptr);
                return;
            }

            doubleWithLeftChild(node_ptr);
        }

        return;
    }

    if(data > *(node_ptr->data)) {
        insert(data, node_ptr->right);

        if(height(node_ptr->right) - height(node_ptr->left) == 2) {
            if(data > *(node_ptr->right->data)) {
                rotateWithRightChild(node_ptr);
                return;
            }

            doubleWithRightChild(node_ptr);
        }

        return;
    }

    node_ptr->height = max(height(node_ptr->left), height(node_ptr->right)) + 1;
}

template<class T>
T AvlTree<T>::findMin(AvlTree::Node *&node_ptr) {
    if(node_ptr->left == nullptr) {
        return node_ptr->data;
    }

    return findMin(node_ptr->left);
}

template<class T>
T AvlTree<T>::findMax(AvlTree::Node *&node_ptr) {
    if(node_ptr->right == nullptr) {
        return node_ptr->data;
    }

    return findMax(node_ptr->right);
}

template <class T>
void AvlTree<T>::printTree(Node* &node_ptr) {
    if(node_ptr == nullptr) {
        return;
    }

    std::cout << node_ptr->data << std::endl;

    printTree(node_ptr->left);
    printTree(node_ptr->right);
}

template<class T>
void AvlTree<T>::printTreeAndCounter(AvlTree::Node *&node_ptr) {
    if(node_ptr == nullptr) {
        return;
    }

    T value = node_ptr->data;
    int counter = node_ptr->counter;

    std::cout << value << " - " << counter << std::endl;

    printTreeAndCounter(node_ptr->left);
    printTreeAndCounter(node_ptr->right);
}

template<class T>
int AvlTree<T>::max(int left_operator, int right_operator) {
    return left_operator > right_operator ? left_operator : right_operator;
}

template<class T>
T* AvlTree<T>::retrieveData(std::string &search, AvlTree::Node* &node_ptr) {
    if(node_ptr == nullptr) {
        return nullptr;
    }

    T &local_data_ref = *node_ptr->data;

    if(local_data_ref == search) {
        return node_ptr->data;
    }

    if(local_data_ref > search) {
        return retrieveData(search, node_ptr->left);
    }

    return retrieveData(search, node_ptr->right);
}

template<class T>
T *AvlTree<T>::retrieveData(int &search, AvlTree::Node *&node_ptr) {
    if(node_ptr == nullptr) {
        return nullptr;
    }

    if(*(node_ptr->data) == search) {
        return node_ptr->data;
    }

    T* left_result = retrieveData(search, node_ptr->left);
    T* right_result = retrieveData(search, node_ptr->right);

    if(left_result == nullptr && right_result == nullptr) {
        return nullptr;
    }

    return (left_result == nullptr) ? right_result : left_result;
}
//endregion

//endregion

