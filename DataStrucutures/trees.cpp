// Answers to tree implementations in hackerrank!
#include <iostream>
#include <queue>

// you only have to complete the function given below.
//Tree is defined as

class Tree
{
  public:
    int data;
    Tree *left;
    Tree *right;
    Tree(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

// PreOrder transveral
void preOrder(Tree *root)
{
    std::cout << root->data << " ";

    if (root->left)
        preOrder(root->left);

    if (root->right)
        preOrder(root->right);
}

// Post order transversal
void postOrder(Tree *root)
{

    if (root->left)
        postOrder(root->left);
    if (root->right)
        postOrder(root->right);

    std::cout << root->data << " ";
}

// Print in order
void inOrder(Tree *root)
{

    if (root->left)
        inOrder(root->left);

    std::cout << root->data << " ";

    if (root->right)
        inOrder(root->right);
}

// Height of a tree
int height(Tree *root)
{
    int edges = 0;

    if (!root)
        return 0;

    if (root->left)
        edges = 1 + height(root->left);
    if (root->right)
        edges = 1 + height(root->right);

    return edges;
}

// Level Order
void levelOrder(Tree *root)
{

    std::queue<Tree *> order;

    auto *temp = root;

    if (root)
    {
        order.push(root);
    }

    while (!order.empty())
    {
        std::cout << temp->data << " ";
        if (temp->left)
            order.push(temp->left);
        if (temp->right)
            order.push(temp->right);

        order.pop();
        temp = order.front();
    }
}

//Insertion
Tree *insert(Tree *root, int data)
{
    auto *to_insert_node = new Tree(data);

    // null root is found and insertion can happen
    if (!root)
    {
        root = to_insert_node;
        return root;
    }

    // search left if data is less than current data
    if (root->data >= to_insert_node->data)
        root->left = insert(root->left, data);

    // search right if data is greater than current data
    if (root->data < to_insert_node->data)
        root->right = insert(root->right, data);

    return root;
}

////Deletion

//Helper function
Tree *FindMax(Tree *root)
{
    if (!root)
        return nullptr;

    while (root->right)
    {
        root = root->right;
    }
    return root;
}

Tree *Delete(Tree *root, int data)
{
    if (!root)
    {
        delete root;
        root = nullptr;
    } // Searching
    else if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else // found if this else is executred
    {    // case 1: Leaf with no children
        if (!root->left && !root->right)
        {
            delete root;
            root = nullptr;
        } // case 2: One child
        else if (!root->left)
        {
            auto *temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;
        }
        else if (!root->right)
        {
            auto *temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
        }
        else // case 3: two children
        {
            auto *temp = FindMax(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }

        return root;
    }
}
