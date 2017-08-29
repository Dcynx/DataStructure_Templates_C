#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

typedef struct n
{
	int val;
	struct n *left;
	struct n *right;
	int height;
}node;

int min(int a,int b)
{
	if(a<=b)
		return a;
	else
		return b;
}

int max(int a,int b)
{
	if(a>=b)
		return a;
	else
		return b;
}

int height(node* N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

node* rightRotate(node* y)
{
    node *x = y->left;
    node *T2 = x->right;

    // Perform rotation
    x->right = y;
    y->left = T2;

    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    // Return new root
    return x;
}

node* leftRotate(node* x)
{
    node *y = x->right;
    node *T2 = y->left;

    // Perform rotation
    y->left = x;
    x->right = T2;

    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    // Return new root
    return y;
}

int getBalance(node* N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

node* Insert(node *root,int x)
{
	// first do normal BST insertion
	if(root==NULL)
	{
		node* newnode = (node *)malloc(sizeof(node));
		newnode->val = x;
		newnode->left = NULL;
		newnode->right = NULL;
		newnode->height = 1;
		return newnode;
	}
	if(x < root->val)
        root->left  = Insert(root->left, x);
    else if(x > root->val)
        root->right = Insert(root->right, x);
    else // Equal keys are not allowed in BST
        return root;
	// Update height of this ancestor node
	root->height = 1 + max(height(root->left),height(root->right));
	int balance = getBalance(root);
	// If this node becomes unbalanced, then
    // there are 4 cases

    // Left Left Case
    if (balance > 1 && x < root->left->val)
        return rightRotate(root);

    // Right Right Case
    if (balance < -1 && x > root->right->val)
        return leftRotate(root);

    // Left Right Case
    if (balance > 1 && x > root->left->val)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balance < -1 && x < root->right->val)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    /* return the (unchanged) node pointer */
    return root;
}

node* minValueNode(node* root)
{
    node* current = root;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

node *Delete(node* root,int x)
{
	// Find the node having x and delete it
	// Then find the balance and rotate it
	if(root==NULL)
		return NULL;
	if(x < root->val)
		root->left = Delete(root->left,x);
	else if(x > root->val)
		root->right = Delete(root->right,x);
	else
	{
		// Found the value delete this node
		if((root->left==NULL)||(root->right==NULL))		// 1 child or no child
		{
			node *temp = root->left ? root->left : root->right;
			// No child case
            if(temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
            	*root = *temp; // Copy the contents of the non-empty child
            free(temp);
		}
		else	// 2 children
		{
			// node with two children: Get the inorder
            // successor (smallest in the right subtree)
            node* temp = minValueNode(root->right);

            // Copy the inorder successor's data to this node
            root->val = temp->val;

            // Delete the inorder successor
            root->right = Delete(root->right, temp->val);
		}
	}

	if (root == NULL)
      return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->height = 1 + max(height(root->left),height(root->right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left =  leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void preorder(node *root)
{
	if(root!=NULL)
	{
		printf("%d ",root->val);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(node* root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d ",root->val);
		inorder(root->right);
	}
}

int main()
{
	node *root = NULL;
	root = Insert(root, 10);
	root = Insert(root, 20);
	root = Insert(root, 30);
	root = Insert(root, 40);
	root = Insert(root, 50);
	root = Insert(root, 25);
	inorder(root);
	printf("\n");
	root = Delete(root,25);
	inorder(root);
	printf("\n");
}
