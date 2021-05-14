#include <iostream>
using namespace std;

 template <class Key>
	class nodeB
{
public:
		Key key;
		nodeB<Key>* left;
		nodeB<Key>* right;

		nodeB(Key Search_Key)
		{
			key = Search_Key;
			left = right = nullptr;
		}
};
template <class Key>
class BST
{
	nodeB<Key>* head;

public:
	// Default constructor.
	BST<Key>()
	{
		head = nullptr;
	}
	/* Compute the "height" of a tree -- the number of
		nodes along the longest path from the root node
		down to the farthest leaf node.*/
	int height(nodeB<Key>* node)
	{
		if (node == NULL)
			return 0;
		else
		{
			/* compute the height of each subtree */
			int lheight = height(node->left);
			int rheight = height(node->right);

			/* use the larger one */
			if (lheight > rheight)
				return(lheight + 1);
			else return(rheight + 1);
		}
	}

	// Insert function.
	void Insert(const Key&value)
	{
		if (head == nullptr)
		{
			// Insert the first node, if root is nullptr.
			
			head = new nodeB<Key>(value);
			return;
		}

		nodeB<Key> **iterate = &head; //using double pointer to keep position of the pointer where the new node is to be inserted

		// Insert data.
		
		while (*iterate != nullptr)
		{
			if (value > (*iterate)->key)
			{
				// Move to right node, if the 'value'
				// to be inserted is greater than 'iterate' node key.

				iterate = &((*iterate)->right);
			}
			else
			{
				// Move to left node, if the 'value'
				// to be inserted is smaller than 'root' node key.

				iterate = &((*iterate)->left);
			}
		}
		*iterate = new nodeB<Key>(value); //creating new node

	}
	


	/* Print nodes at a given level */
	void printGivenLevel(nodeB<Key>* root, int level)
	{
		if (root == nullptr)
		{
			if (level == 1)
				cout << "[.]";
			return;
		}

		if (level == 1)
			cout << "[" << root->key << "]";
		else if (level > 1)
		{
			printGivenLevel(root->left, level - 1);
			printGivenLevel(root->right, level - 1);
		}
	}
	// Level Order traversal.
	void printLevelOrder()
	{
		int h = height(head);
		int i;
		for (i = 1; i <= h+1; i++)
		{
			cout << "Level " << i - 1<<":";
			printGivenLevel(head, i);
			cout << endl;
		}
		
	}

	//Search for a value in the BST
	bool Search(const Key& find)
	{
		nodeB<Key>* iterator = head;
		bool found = false;
		while (iterator != nullptr && found == false)
		{
			if (find < iterator->key) // Move to the left node if 'find' is smaller than 'iterator' key
			{
				iterator = iterator->left;
			}
			else if(find>iterator->key) // Move to the rght node if 'find' is greater than 'iterator' key
			{
				iterator = iterator->right;
			}
			else //The element is found if 'find' is equal to 'iterator' key
			{
				found = true; //setting found to true to keep check that element has been found in the tree
			}
		}

		return found;
	}

};

template <typename Key>
void Menu(BST<Key>&tree)
{
	int option = -1;
	while (option != 0)
	{
		cout << "The current tree is:\n\n";

		tree.printLevelOrder();
		cout << "\n\n";

		cout << "0-Exit\n1-Insert\n2-Search\n\n";
		cout << "Enter an option from 0 to 2:";
		cin >> option;
		cout << endl;
		if (option == 0)
		{
			cout << "The program will now terminate...\n\n";
		}
		else if (option == 1)
		{
			int value = 0;
			cout << "Enter value:";
			cin >> value;
			cout << endl;
			tree.Insert(value);
		}
		else if (option == 2)
		{
			int value = 0;
			cout << "Enter value:";
			cin >> value;
			cout << endl;
			if (tree.Search(value) == true)
			{
				cout << value << " found in tree!\n\n";
			}
			else
			{
				cout <<"Couldn't find " <<value << " in tree!\n\n";
			}

		}
		else
		{
			cout << "Invalid input. Kindly choose an option from 0-2\n\n";
		}

		system("pause");
		system("cls");
	}
}

int main()
{
	BST<int> tree;
	Menu(tree);

	return 0;
}
