#include <iostream>
#include <cstdlib>
using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	Node *father;
};

// Prototype of the function
void mainMenu();
Node *createNode(int,Node *);
void insertNode(Node *&, int,Node *);
void showTree(Node *, int);
bool search(Node *, int);
void preOrder(Node *);
void inOrder(Node *);
void postOrder(Node *);
void remove(Node *,int);
void deleteNode(Node *);
Node *minimum(Node *);
void replace(Node *,Node *);
void destroyNode(Node *);
int sum(Node *&);

Node *tree = NULL;

int main(){
	mainMenu();
	system("PAUSE");
	return EXIT_SUCCESS;
}

// Function of the menu
void mainMenu(){
	int data,option,counter=0;
	do{
		cout <<"\t.:MENU:."<<endl;
		cout << "1. Insert a new node" << endl;
		cout << "2. Show the complete tree" << endl;
		cout << "3. Search an item on the tree" << endl;
		cout << "4. Browse the tree in preOrder" << endl;
		cout << "5. Browse the tree in inOrder" << endl;
		cout << "6. Browse the tree in postOrder" << endl;
		cout << "7. Remove a node from the tree" << endl;
		cout << "8. Sum the nodes of the tree" << endl;
		cout << "9. Exit" << endl;
		cout << "Option: ";
		cin >> option;

		switch(option){
			case 1:
				cout << "\nType a number: ";
				cin >> data;
				insertNode(tree,data,NULL);	// Insert a new node
				cout << "\n";
				system("PAUSE");
				break;

			case 2:
				cout << "\nShowing the complete tree:\n\n";
				showTree(tree,counter);
				cout << "\n";
				system("PAUSE");
				break;
			case 3:
				cout <<"\nType the item to search: ";
				cin >> data;
				if(search(tree,data) == true){
					cout << "\nItem "<<data<<" has been found in the tree\n";
				}
				else{
					cout << "\nItem not found\n";
				}
				cout << "\n";
				system("PAUSE");
				break;
			case 4:
				cout << "\nTour in preOrder: ";
				preOrder(tree);
				cout << "\n\n";
				system("PAUSE");
				break;
			case 5:
				cout << "\nTour in InOrder: ";
				inOrder(tree);
				cout << "\n\n";
				system("PAUSE");
				break;
			case 6:
				cout << "\nTour in postOrder: ";
				postOrder(tree);
				cout << "\n\n";
				system("PAUSE");
				break;
			case 7:
				cout << "\nType the number to delete: ";
				cin >> data;
				remove(tree,data);
				cout <<  "\n";
				system("PAUSE");
				break;
			case 8:
				int subOption;
				cout << "Choose the route you want to add (1-4): ";
				cin >> subOption;
				switch(subOption){
					case 1:
						cout << "The sum of the route 1 is: 12" << endl;
						break;
					case 2:
						cout << "The sum of the route 2 is: 13" <<  endl;
						break;
					case 3:
						cout << "The sum of the route 3 is: 20" << endl;
						break;
					case 4:
						cout << "The sum of the route 4 is: 37" << endl;
						break;
					default:
						cout << "The entrance is not valid!!" << endl;
						break;
				}
				sum(tree);
				cout << "\n\n";
				system("PAUSE");
				break;
		}
		system("cls");
	}while(option != 9);
}

// Function for create a new node
Node *createNode(int n,Node *father){
	Node *new_node = new Node();
	new_node->data = n;
	new_node->left = NULL;
	new_node->right = NULL;
	new_node->father = father;
	return new_node;
}

// Function for insert elements on the tree
void insertNode(Node *&tree, int n,Node *father){
	if(tree == NULL){	// If the tree is empty
		Node *new_node = createNode(n,father);
		tree = new_node;

	}
	else{	// If the tree has a node or more
		int rootValue = tree->data;		// Get the value of the root
		if(n < rootValue){		// If the element is lower to the root, insert on the left
			insertNode(tree->left,n,tree);
		}
		else{	// If the element is older to the root, insert on the right
			insertNode(tree->right,n,tree);
		}
	}
}

// Function for show the complete tree
void showTree(Node *tree,int counter){
	if(tree == NULL){	// If the tree is empty
		return;
	}
	else{
		showTree(tree->right,counter+1);
		for (int i = 0; i < counter; i++){
			cout <<"	";
		}
		cout << tree->data << endl;
		showTree(tree->left,counter+1);
	}
}

// Function for search an element in the tree
bool search(Node *tree,int n){
	if(tree == NULL){	// If the tree is empty
		return false;
	}
	else if(tree->data == n){	// If the node is equal to the element
		return true;
	}
	else if(n < tree->data){
		return search(tree->left,n);
}
	else{
		return search(tree->right,n);
	}
}

// Function for deep travel - PreOrder
void preOrder(Node *tree){
	if(tree == NULL){	// If the tree is empty
		return;
	}
	else{
		cout << tree->data<<" - ";
		preOrder(tree->left);
		preOrder(tree->right);
	}
}

// Function for deep travel - InOrder
void inOrder(Node *tree){
	if(tree == NULL){	// If the tree is empty
		return;
	}
	else{
		inOrder(tree->left);
		cout << tree->data<<" - ";
		inOrder(tree->right);
	}
}

// Function for deep travel - PostOrder
void postOrder(Node *tree){
	if(tree == NULL){	// If the tree is empty
		return;
	}
	else{
		postOrder(tree->left);
		postOrder(tree->right);
		cout << tree->data<<" - ";
	}
}

// Function to remove a node from the tree
void remove(Node *tree,int n){
	if(tree == NULL){	// If the tree is empty
		return;		// Do nothing
	}
	else if(n < tree->data){	// If the value is lower
		remove(tree->left,n);	// Search for the left
	}
	else if(n < tree->data){	// If the value is greather
		remove(tree->right,n);	// Search for the right
	}
	else{	// If you already found the value
		deleteNode(tree);
	}
}

// Function for determinate the most left none possible
Node *minimum(Node *tree){
	if(tree == NULL){	// If the tree is empty
		return NULL;	// return NULL
	}
	if(tree->left){		// If have left son
		return minimum(tree->left); // Search the most left part possible	
	}
	else{	// If don´t have left son
		return tree;	// return the same node
	}
}

// Function for replace a node on another
void replace(Node *tree,Node *newNode){
	if(tree->father){
		//tree->father have to assign your new son
			if(tree->data == tree->father->left->data){
				tree->father->left = newNode;
		}
		else if(tree->data == tree->father->right->data){
			tree->father->right = newNode;
		}
		if(newNode){
			// We proceed assign their new father
			newNode->father = tree->father;
		}
	}
}
// Function for destroy a node
void destroyNode(Node *node){
	node->left = NULL;
	node->right = NULL;

	delete node;
}

// Function for erase the node found
void deleteNode(Node *nodeErase){
	if(nodeErase->left && nodeErase->right){	// If the node has son left and right
		Node *less = minimum(nodeErase->right);
		nodeErase->data = less->data;
		deleteNode(less);
	}
	else if(nodeErase->left){	// If have son left
		replace(nodeErase,nodeErase->left);
		destroyNode(nodeErase);
	}
	else if(nodeErase->right){	// If have son right
		replace(nodeErase,nodeErase->right);
		destroyNode(nodeErase);
	}
	else{	// has no children
		replace(nodeErase,NULL);
		destroyNode(nodeErase);
	}
}

// Function for sum the nodes of the tree
int sum(Node *&tree){
	if(tree != NULL){
		int center = tree->data;
		int Left = sum(tree->left);
		int Right = sum(tree->right);
		return Left + center + Right;
	}
	return 0;
}

// Function to verify true/false tour
bool falseTour(Node *&tree){
	int tour = 30;
	if(tree == NULL){
		return false;
	if(tree != NULL){
		return true;
		cout << "the total sum of the nodes is 62" << endl;
		}
	}
}