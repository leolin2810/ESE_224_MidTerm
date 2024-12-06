#ifndef SPATIALTREE_H
#define SPATIALTREE_H

#include "Probe.h"

class SpatialNode
{
public:
    Probe *probe;
    SpatialNode *left;
    SpatialNode *right;

    // Constructor
    SpatialNode(Probe *p) : probe(p), left(nullptr), right(nullptr) {}
};

class SpatialTree
{
private:
    SpatialNode *root;
    // Helper functions
    SpatialNode *insertHelper(SpatialNode *node, Probe *probe);
    SpatialNode *searchHelper(SpatialNode *node, int x, int y);
    void traverseInOrderHelper(SpatialNode *node);   // Inorder
    void traversePreOrderHelper(SpatialNode *node);  // Preorder
    void traversePostOrderHelper(SpatialNode *node); // Postorder

    void deleteTree(SpatialNode *node);

public:
    // Constructor
    SpatialTree();

    // Insertion
    void insert(Probe *probe);

    // Search probe by position
    Probe *search(int x, int y);

    // Traverse
    void traverseInOrder();   // Inorder
    void traversePreOrder();  // Preorder
    void traversePostOrder(); // Postorder

    // Destructor
    ~SpatialTree();
};

#endif // !SPATIALTREE_H
