#ifndef SEARCHTREE_CPP
#define SEARCHTREE_CPP

#include "treeNode.cpp"
#include <fstream>
using namespace std;

template <class E>
class BST{
public:
  BST();
  //virtual ~BST();
  ~BST();


  void insert(const E& value);
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
  void printDescendingTree(TreeNode<E> *node);
  void serialize(ofstream& file);
  void deSerialize(ifstream& file);
  void serialize(TreeNode<E> *root, ofstream& file);
  void deSerialize(TreeNode<E> *root, ifstream& file);

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
void BST<E>::printDescendingTree(TreeNode<E> *node){
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
void BST<E>::insert(const E& value){
  cout << flush;
  TreeNode<E> *node = new TreeNode<E>(value); //value is also Key
  if(root == NULL){
    root = node;
  }
  else{
    TreeNode<E> *curr = root;
    TreeNode<E> *parent;

    while(true){
      parent = curr;

      if(value < curr -> key){
        //go left
        curr = curr -> left;
        if(curr == NULL){
          parent -> left = node;
          break;
        }
      }
      else{
        //go right
        curr = curr -> right;
        if(curr == NULL){
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

//attempt at serialization and deserialization 
template <class E>
void BST<E>::serialize(ofstream& file){
  return serialize(root, file);
}

template <class E>
void BST<E>::deSerialize(ifstream& file){
  return deSerialize(root, file);
}

template <class E>
void BST<E>::serialize(TreeNode<E> *root, ofstream& file){
  if (root == NULL){
    return;
  }
  file << root -> key << "/n";
  serialize(root->left, file);
  serialize(root->right, file);

}

template <class E>
void BST<E>::deSerialize(TreeNode<E> *root, ifstream& file){
  if (root == NULL){
    return;
  }
  else{
    while(!file.eof()){
      insert(root -> key);
      deSerialize(root->left, file);
      deSerialize(root->right, file);
    }
  }
}

#endif
