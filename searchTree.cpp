#include "treeNode.cpp"
using namespace std;

template <class E>
class BST{
public:
  BST();
  //virtual ~BST();
  ~BST();


  void insert(E value);
  bool searchNode(E value);
  E searchByKey(int key);
  bool deleteNode(E k);
  bool deleteByKey(int key);
  bool isEmpty();

  TreeNode<E> *getMin();
  TreeNode<E> *getMax();

  TreeNode<E> *getSuccessor(TreeNode<E> *d);
  void printTree(TreeNode<E> *node);
  void printTree();
  void printAscendingTree(TreeNode<E> *node);

  TreeNode<E> *root;
};

//.cpp implementation
template <class E>
BST<E>::BST(){
  root = NULL;
}

template <class E>
BST<E>::~BST(){
  delete root;
}

//print inorder
template <class E>
void BST<E>::printTree(TreeNode<E> *node){
  if(node == NULL){
    return;
  }
  printTree(node -> left);
  cout << node -> key << endl;
  printTree(node -> right);
}

template <class E>
void BST<E>::printTree(){
	printTree(root);
}

template <class E>
void BST<E>::printAscendingTree(TreeNode<E> *node){
  if(node == NULL){
    return;
  }
  printTree(node -> right);
  cout << node -> key << endl;
  //need to print values as well
  printTree(node -> left);
}

template <class E>
TreeNode<E> *BST<E>::getMax(){

  TreeNode<E> *curr = root; //start at root

  if(root == NULL){
    return NULL; //tree is isEmpty
  }

  while(curr -> right != NULL){
    curr = curr -> right;
  }
  return curr;
}

template <class E>
TreeNode<E> *BST<E>::getMin(){
  TreeNode<E> *curr = root; //start at root

  if(root == NULL){
    return NULL; //tree is isEmpty
  }

  while(curr -> left != NULL){
    curr = curr -> left;
  }
  return curr;
}

template <class E>
bool BST<E>::isEmpty(){
  return(root==NULL);
}

template <class E>
void BST<E>::insert(E value){
  cout << '1' << endl;
  TreeNode<E> *node = new TreeNode<E>(value); //value is also Key

  if(root == NULL){
	cout << '2' << endl;
    root = node;
	cout << "2 be continued" << endl;
  }
  else{
	cout << '3' << endl;
    TreeNode<E> *curr = root;
    TreeNode<E> *parent;

    while(true){
      cout << '4' << endl;
      parent = curr;

      if(value < curr -> key){
        //go left
		cout << '5' << endl;
        curr = curr -> left;
        if(curr == NULL){
		  cout << '6' << endl;
          parent -> left = node;
          break;
        }
      }
      else{
        //go right
		cout << '7' << endl;
        curr = curr -> right;
        if(curr == NULL){
		  cout << '8' << endl;
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template <class E>
bool BST<E>::searchNode(E value){
  if(isEmpty()){
    return false;
  }
  else{
    TreeNode<E> *curr = root;

    while(curr -> key != value){
      if(value < curr -> key){
        curr = curr ->left;
      }
      else{
        curr = curr -> right;
      }
      if(curr == NULL){
        return false;
      }
    }
    return true;
  }
}

template <class E>
E BST<E>::searchByKey(int key){
  if(isEmpty()){
    return E();
  }
  else{
    TreeNode<E> *curr = root;

    while(curr -> key != key){
      if(curr -> key > key){
		curr = curr ->left;
      }
      else{
		curr = curr -> right;
      }
      if(curr == NULL){
        return E();
      }
    }
    return curr->key;
  }
}

template <class E>
bool BST<E>::deleteNode(E k){
  if(isEmpty()){
    return false;
  }
  
  // Looking for the value in the tree
  TreeNode<E> *curr = root;
  TreeNode<E> *parent = root;
  bool isLeft = true;

  while(curr -> key != k){
    parent = curr;
    if(curr -> key > k){
      isLeft = true;
      curr = curr -> left;
    }
    else{
      isLeft = false;
      curr = curr -> right;
    }
    if(curr == NULL){
      return false;
    }
  }

  // If we've made it here, we've found the specified node; Now let's delete it

  //no children, leaf TreeNode
  if(curr -> left == NULL && curr -> right == NULL){
    if(curr == root){
      root = NULL;
    }
    else if(isLeft){
      parent -> left = NULL;
    }
    else{
      parent -> right = NULL;
    }
  }
  
  // One child; child is left
  else if(curr -> right == NULL){
    if(curr == root){
      root = curr -> left;
    }
    else if(isLeft){
      parent -> left = curr -> left;
    }
    else{
      parent -> right = curr -> left;
    }
  }
  
  // One child; child is right
  else if(curr -> left == NULL){
    if(curr == root){
      root = curr -> right;
    }
    else if(isLeft){
      parent -> left = curr -> right;
    }
    else{
      parent -> right = curr -> right;
    }
  }
  
  // Two children
  else{
    TreeNode<E> *successor = getSuccessor(curr);

    if(curr == root){
      root = successor;
    }
    else if(isLeft){
      parent -> left = successor;
    }
    else{
      parent -> right = successor;
    }
	successor -> left = curr -> left;
	return true;
  }
}

template <class E>
bool BST<E>::deleteByKey(int key){
  return deleteNode(searchByKey(key));
}

template <class E>
TreeNode<E> *BST<E>::getSuccessor(TreeNode<E> *d){
  TreeNode<E> *sp = d;
  TreeNode<E> *successor = d;
  TreeNode<E> *curr = d -> right;

  while(curr != NULL){
    sp = successor;
    successor = curr;
    curr = curr -> left;

    if(successor != d -> right){
      sp -> left = successor -> right;
      successor -> right = d -> right;
    }
  }
  return successor;
}
