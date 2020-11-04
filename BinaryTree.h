//
// Created by leone on 11/4/2020.
//

#ifndef TP_PROGRA3_BINARYTREE_H
#define TP_PROGRA3_BINARYTREE_H

#include "TreeNode.h"
#include <iostream>
#include <string>

// CRUD
template <class T> class BinaryTree {
private:
    TreeNode<T> *root;

    TreeNode<T> *put(T dato, TreeNode<T> *r);
    void print(bool esDerecho, std::string identacion, TreeNode<T> *r);
    T search(T dato, TreeNode<T> *r);
    void preorder(TreeNode<T> *r);
    void inorder(TreeNode<T> *r);
    void postorder(TreeNode<T> *r);
    void backwards(TreeNode<T> *r);
    void backwards(int &n,TreeNode<T> *r);
    TreeNode<T> *remove(T dato, TreeNode<T> *r);

    T findMax(TreeNode<T> *r);

    void clear(TreeNode<T> *r);

public:
    BinaryTree();

    void put(T dato);

    T search(T dato);

    void remove(T dato);

    void preorder();

    void inorder();

    void postorder();

    void backwards();
    void backwards(int &n);

    ~BinaryTree();

    bool isEmpty();

    void print();
};

/**
 * Constructor del Arbol
 * @tparam K Clave por la cual va a ordenar el árbol
 * @tparam T Valor guardado por el árbol
 */
template <class T> BinaryTree<T>::BinaryTree() { root = nullptr; }

/**
 * Destructor del Arbol
 */
template <class T> BinaryTree<T>::~BinaryTree() { clear(root); }
template <class T> void BinaryTree<T>::clear(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    clear(r->getLeft());
    clear(r->getRight());
    delete r;
}

/**
 * Busca un dato en el árbol. Si no esta el dato en el árbol
 * tira una excepción
 * @param clave Valor a buscar
 * @return el valor buscado
 */
template <class T> T BinaryTree<T>::search(T dato) {
    return search(dato, root);
}
template <class T> T BinaryTree<T>::search(T dato, TreeNode<T> *r) {
    if (r == nullptr)
        throw 404;

    if (dato > r->getData()) {
        return search(dato, r->getRight());
    } else if (dato < r->getData()) {
        return search(dato, r->getLeft());
    } else {
        return r->getData();
    }
}
/**
 * Agrega un dato al árbol
 * @param clave Clave para agregar el dato
 * @param dato Dato a agregar
 */
template <class T> void BinaryTree<T>::put(T dato) { root = put(dato, root); }

template <class T> TreeNode<T> *BinaryTree<T>::put(T dato, TreeNode<T> *r) {

    if (r == nullptr)
        return new TreeNode<T>(dato);

    if (dato > r->getData()) {
        r->setRight(put(dato, r->getRight()));
    } else if (dato < r->getData()) {
        r->setLeft(put(dato, r->getLeft()));
    } else {
        throw 302;
    }
    return r;
}

/**
 * Elimina un dato del árbol
 * @param clave Clave para identificar el nodo a borrar
 */
template <class T> void BinaryTree<T>::remove(T dato) {
    root = remove(dato, root);
}
template <class T> TreeNode<T> *BinaryTree<T>::remove(T dato, TreeNode<T> *r) {
    TreeNode<T> *aux;
    if (r == nullptr)
        throw 404;

    if (dato > r->getData()) {
        r->setRight(remove(dato, r->getRight()));
    } else if (dato < r->getData()) {
        r->setLeft(remove(dato, r->getLeft()));
    } else {
        // Remover el nodo
        if (r->getLeft() == nullptr && r->getRight() == nullptr) {
            delete r;
            return nullptr;
        } else if (r->getLeft() != nullptr && r->getRight() == nullptr) {
            aux = r->getLeft();
            delete r;
            return aux;
        } else if (r->getLeft() == nullptr && r->getRight() != nullptr) {
            aux = r->getRight();
            delete r;
            return aux;
        } else {
            T tmp = findMax(r->getLeft());
            r->setLeft(remove(tmp, r->getLeft()));
            r->setData(tmp);
        }
    }

    return r;
}

template <class T> T BinaryTree<T>::findMax(TreeNode<T> *r) {
    TreeNode<T> *aux = r;

    while (r->getRight() != nullptr) {
        r = r->getRight();
    }
    return r->getData();
}
/**
 * Informa si un árbol esta vacío
 * @return
 */
template <class T> bool BinaryTree<T>::isEmpty() { return root == nullptr; }

/**
 * Recorre un árbol en preorden
 */
template <class T> void BinaryTree<T>::preorder() { preorder(root); }
template <class T> void BinaryTree<T>::preorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    std::cout << r->getData() << " ";
    preorder(r->getLeft());
    preorder(r->getRight());
}

/**
 * Recorre un árbol en orden
 */
template <class T> void BinaryTree<T>::inorder() { inorder(root); }
template <class T> void BinaryTree<T>::inorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    inorder(r->getLeft());
    std::cout << r->getData() << " ";
    inorder(r->getRight());
}
/**
 * *Recorre un arbol en sentido contrario
 */
template <class T> void BinaryTree<T>::backwards() { backwards(root); }
template <class T> void BinaryTree<T>::backwards(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    backwards(r->getRight());
    std::cout << r->getData() << " ";
    backwards(r->getLeft());
}
template <class T> void BinaryTree<T>::backwards(int &n) { backwards(n,root); }
template <class T> void BinaryTree<T>::backwards(int &n,TreeNode<T> *r) {
    if (r == nullptr){
        n=n-1;
        return;}
        backwards(n,r->getRight());
    if(n>=0){
        std::cout << r->getData() << " ";
    } else
        return;
        backwards(n,r->getLeft());

}
/**
 * Recorre un árbol en postorden
 */
template <class T> void BinaryTree<T>::postorder() {postorder(root);}
template <class T> void BinaryTree<T>::postorder(TreeNode<T> *r) {
    if (r == nullptr)
        return;

    postorder(r->getLeft());
    postorder(r->getRight());
    std::cout << r->getData() << " ";
}

/**
 * Muestra un árbol por consola
 */
template <class T> void BinaryTree<T>::print() { print(true, "", root); }

template <class T>
void BinaryTree<T>::print(bool esDerecho, std::string identacion,
                          TreeNode<T> *r) {
    if (r->getRight() != nullptr) {
        print(true, identacion + (esDerecho ? "     " : "|    "), r->getRight());
    }
    std::cout << identacion;
    if (esDerecho) {
        std::cout << " /";
    } else {
        std::cout << " \\";
    }
    std::cout << "-- ";
    std::cout << r->getData() << std::endl;
    if (r->getLeft() != NULL) {
        print(false, identacion + (esDerecho ? "|    " : "     "), r->getLeft());
    }
}




#endif //TP_PROGRA3_BINARYTREE_H
