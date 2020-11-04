//
// Created by leone on 11/4/2020.
//

#ifndef TP_PROGRA3_TREENODE_H
#define TP_PROGRA3_TREENODE_H

template <class T> class TreeNode {
private:
    TreeNode<T> *left, *right;
    T data;

public:
    explicit TreeNode(T data) : data(data) {
        left = nullptr;
        right = nullptr;
    }
    TreeNode() {
        left = nullptr;
        right = nullptr;
    }

    TreeNode<T> *getLeft() const { return left; }
    void setLeft(TreeNode<T> *left) { TreeNode::left = left; }
    TreeNode<T> *getRight() const { return right; }
    void setRight(TreeNode<T> *right) { TreeNode::right = right; }
    T getData() const { return data; }
    void setData(T data) { TreeNode::data = data; }
};

#endif //TP_PROGRA3_TREENODE_H
