#include "treeNode.cpp"
using namespace std;

template <class E>
class BST{
public:
  BST();
  //virtual ~BST();
  ~BST();

  void insert(E value);
  bool searchNode(int value);
  bool deleteNode(int k);
  bool isEmpty();

  TreeNode<E>* getMin();
  TreeNode<E>* getMax();

  TreeNode<E>* getSuccessor(TreeNode<E> *d);
  void printTree(TreeNode<E> *node);

private:
  TreeNode<E> *root;
  TreeNode<E> *curr;
  TreeNode<E> *current;
  TreeNode<E> *parent;
  TreeNode<E> *successor;
  TreeNode<E> *sp;
};

//.cpp implementation
template <class E>
BST<E>::BST(){
  root = NULL;
}

template <class E>
BST<E>::~BST(){
  //need to do
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
TreeNode<E>* BST<E>::getMax(){

  curr = root; //start at root

  if(root == NULL){
    return NULL; //tree is isEmpty
  }

  while(curr -> right != NULL){
    curr = curr -> right;
  }
  return curr;
}

template <class E>
TreeNode<E>* BST<E>::getMin(){
  curr = root; //start at root

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
  TreeNode<E> *node = new TreeNode<E>(value); //value is also Key

  if(root == NULL){
    root = node;
  }
  else{
    curr = root;
    parent;

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
        if(curr = NULL){
          parent -> right = node;
          break;
        }
      }
    }
  }
}

template <class E>
bool BST<E>::searchNode(int value){
  if(isEmpty()){
    return false;
  }
  else{
    current = root;

    while(current -> key != value){
      if(value < current -> key){
        current = current ->left;
      }
      else{
        current = current -> right;
      }
      if(current == NULL){
        return false;
      }
    }
    return true;
  }
}

template <class E>
bool BST<E>::deleteNode(int k){
  if(isEmpty()){
    return false;
  }
  current = root;
  parent = root;
  bool isLeft = true;

  while(current -> key != k){
    parent = current;
    if(k < current -> key){
      isLeft = true;
      current = current -> left;
    }
    else{
      isLeft = false;
      current = current -> right;
    }
    if(current == NULL){
      return false;
    }
  }

  //no children, leaf TreeNode
  if(current -> left == NULL && current -> right == NULL){
    if(current == root){
      root = NULL;
    }
    else if(isLeft){
      parent -> left = NULL;
    }
    else{
      parent -> right = NULL;
    }
  }
  else if(current -> right == NULL){
    if(current == root){
      root = current -> left;
    }
    else if(isLeft){
      parent -> left = current -> left;
    }
    else{
      parent -> right = current -> left;
    }
  }
  else if(current -> left == NULL){
    if(current == root){
      root = current -> right;
    }
    else if(isLeft){
      parent -> left = current -> right;
    }
    else{
      parent -> right = current -> right;
    }
  }
  else{
    successor = getSuccessor(current);

    if(current == root){
      root = successor;
    }
    else if(isLeft){
      parent -> left = successor;
    }
    else{
      parent -> right = successor;
    }
  }
  successor -> left = current -> left; //might be wrong line
  return true;
}

template <class E>
TreeNode<E>* BST<E>::getSuccessor(TreeNode<E> *d){
  sp = d;
  successor = d;
  current = d -> right;

  while(current != NULL){
    sp = successor;
    successor = current;
    current = current -> left;

    if(successor != d -> right){
      sp -> left = successor -> right;
      successor -> right = d -> right;
    }
  }
  return successor;
}
