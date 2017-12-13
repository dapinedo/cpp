//
//  main.cpp
//  binaryTree
//
//  Created by Solomon Russell on 11/19/15.
//  Copyright (c) 2015 Solomon Russell. All rights reserved.
//

#include <iostream>
using namespace std;

typedef int ItemType;

struct TreeNode {
    ItemType info;
    TreeNode* left;
    TreeNode* right;
};

class TreeType {
private:
    TreeNode* root;
    void Insert(TreeNode*& nodeptr, ItemType item);
    void Destroy(TreeNode*& nodeptr);
    void PrintTree(TreeNode* nodeptr);
public:
    TreeType() 
	{
		root = nullptr;
	}
    ~TreeType();
    void PutItem(ItemType item);
    void Print();
	void remove(ItemType obj);
	void deleteNode(TreeNode * & node, ItemType item);
	ItemType rightMost(TreeNode *& node);
	void deleteRightMost(TreeNode * & node);
	bool contains(ItemType obj);
	bool isEmpty();
	void makeEmpty();
	void CopyTree(TreeNode *& copy, TreeNode * OriginalTree);
	TreeType(const TreeType & Other);
	 const TreeType & operator = (const TreeType & OriginalTree);
};

 const TreeType & TreeType::operator = (const TreeType & OriginalTree)
{
	if (this != &OriginalTree)
	{
		Destroy(root);
		CopyTree(root, OriginalTree.root);
	}

	return *this;
}
TreeType::TreeType(const TreeType & Other)
{
	if (this == &Other)
	{
		cout << "Self copy is not allowed." << endl;
		exit(0);
	}
	CopyTree(root, Other.root);
}
void TreeType::CopyTree(TreeNode *& copy, TreeNode * OriginalTree)
{
	if (OriginalTree == nullptr)
	{
		copy = nullptr;
	}
	else
	{
		copy = new TreeNode();
		copy->info = OriginalTree->info;
		CopyTree(copy->left, OriginalTree->left);
		CopyTree(copy->right, OriginalTree->right);
	}
}
void TreeType::makeEmpty()
{
	Destroy(root);
	root = nullptr;
}
bool TreeType::isEmpty()
{
	return root == nullptr;
}
bool TreeType::contains(ItemType obj)
{
	TreeNode * current = root;

	while (current != nullptr)
	{
		if (obj<current->info)
		{
			current = current->left;
		}
		else if (obj > current->info)
		{
			current = current->right;
		}
		else
		{
			break;
		}
	}

	return current != nullptr;
}
ItemType TreeType::rightMost(TreeNode *& node)
{
	if (node->right == nullptr)
	{
		return node->info;
	}
	else
	{
		return rightMost(node->right);
	}
}
void TreeType::deleteRightMost(TreeNode * & node)
{
	if (node->right == nullptr)
	{
		TreeNode * Temp = node->left;

		if (Temp != nullptr)
		{
			*node = *Temp;
			delete Temp;
		}
		else
		{
			Temp = node;
			node = nullptr;
			delete Temp;
		}
	}
	else
	{
		deleteRightMost(node->right);
	}
}
void TreeType::deleteNode(TreeNode * & node, ItemType item)
{
	if (node == nullptr)
	{
		cout << "Tree is empty." << endl;
		return;
	}
	if (item<node->info)
	{
		deleteNode(node->left, item);
	}
	else if (item>node->info)
	{
		deleteNode(node->right, item);
	}

	TreeNode * Temp;

	if (node->left == nullptr && node->right == nullptr)
	{
		Temp = node;
		node = nullptr;
		delete Temp;
	}
	else if (node->left == nullptr)
	{
		Temp = node->right;
		*node = *Temp;
		delete Temp;
	}
	else if (node->right == nullptr)
	{
		Temp = node->left;
		*node = *Temp;
		delete Temp;
	}
	else
	{
		ItemType replaceWithValue = rightMost(node->left);
		node->info = replaceWithValue;
		deleteRightMost(node->left);
	}
}
void TreeType::Print() {
    
    PrintTree(root);
    cout << endl;
}

void TreeType::PrintTree(TreeNode* nodeptr) {
    
    if (nodeptr == nullptr)
        return;
    PrintTree(nodeptr->left);
    cout << nodeptr->info << " ";
    PrintTree(nodeptr->right);
}

void TreeType::PutItem(ItemType item) {
    
    Insert(root, item);
}

void TreeType::Insert(TreeNode*& nodeptr, ItemType item) {
    
    if (nodeptr == nullptr) {
        nodeptr = new TreeNode;
        nodeptr->info = item;
        nodeptr->right = nullptr;
        nodeptr->left = nullptr;
        return;
    }
    if (item < nodeptr->info)
        Insert(nodeptr->left, item);
    else
        Insert(nodeptr->right, item);
}


void TreeType::Destroy(TreeNode*& nodeptr) {
    
    if (nodeptr != nullptr) {
        Destroy(nodeptr->right);
        Destroy(nodeptr->left);
        delete nodeptr;
    }
}

TreeType::~TreeType() {
    
    Destroy(root);
}

void TreeType::remove(ItemType obj)
{
	if (contains(obj))
	{
		deleteNode(root, obj);
	}
	else
	{
		cout << "Item " << obj << " is not in the tree." << endl;
	}
}