#include "SpatialTree.h"
#include <iostream>

// Constructor
SpatialTree::SpatialTree() : root(nullptr) {}

// Helper function to insert a probe
SpatialNode *SpatialTree::insertHelper(SpatialNode *node, Probe *probe)
{
    Probe blank;
    if (!node)
    { // THIS CONDITION IS NEVER MET
        return new SpatialNode(probe);
    }

    int x = probe->getPosition(0);
    int y = probe->getPosition(1);
    int currentX = node->probe->getPosition(0); // SEG FAULT LOCATION
    int currentY = node->probe->getPosition(1);

    // Compare coordinates: x first, then y
    if (x < currentX || (x == currentX && y < currentY))
    {
        node->left = insertHelper(node->left, probe);
    }
    else
    {
        node->right = insertHelper(node->right, probe);
    }
    return node;
}

// Insert a probe
void SpatialTree::insert(Probe *probe)
{
    root = insertHelper(root, probe);
}

// Helper ffunction to search probe by position
SpatialNode *SpatialTree::searchHelper(SpatialNode *node, int x, int y)
{
    if (!node)
        return nullptr;

    int currentX = node->probe->getPosition(0);
    int currentY = node->probe->getPosition(1);

    if (x == currentX && y == currentY)
    {
        return node;
    }
    else if (x < currentX || (x == currentX && y < currentY))
    {
        return searchHelper(node->left, x, y);
    }
    else
    {
        return searchHelper(node->right, x, y);
    }
}

// Search probe by position
Probe *SpatialTree::search(int x, int y)
{
    SpatialNode *node = searchHelper(root, x, y);
    if (node)
    {
        return node->probe;
    }
    else
    {
        return nullptr;
    }
}

// Helper functions for all 3 traversal
void SpatialTree::traverseInOrderHelper(SpatialNode *node)
{
    if (!node)
        return;

    traverseInOrderHelper(node->left);  // Traverse left subtree
    node->probe->displayProbe();        // Visit root
    traverseInOrderHelper(node->right); // Traverse right subtree
}

void SpatialTree::traversePreOrderHelper(SpatialNode *node)
{
    if (!node)
        return;

    node->probe->displayProbe();         // Visit root
    traversePreOrderHelper(node->left);  // Traverse left subtree
    traversePreOrderHelper(node->right); // Traverse right subtree
}

void SpatialTree::traversePostOrderHelper(SpatialNode *node)
{
    if (!node)
        return;

    traversePostOrderHelper(node->left);  // Traverse left subtree
    traversePostOrderHelper(node->right); // Traverse right subtree
    node->probe->displayProbe();          // Visit root
}

// All 3 traversal
void SpatialTree::traverseInOrder()
{
    traverseInOrderHelper(root);
}

void SpatialTree::traversePreOrder()
{
    traversePreOrderHelper(root);
}

void SpatialTree::traversePostOrder()
{
    traversePostOrderHelper(root);
}

// Helper function to delete the tree
void SpatialTree::deleteTree(SpatialNode *node)
{
    if (!node)
        return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Destructor
SpatialTree::~SpatialTree()
{
    deleteTree(root);
}