#ifndef TREENODE_CPP
#define TREENODE_CPP

#include <iostream>
using namespace std;

//template <int K, class V>
template <class E>
class TreeNode{
public:
  TreeNode();
  //TreeNode(K k, V v);
  TreeNode(const E& e);
  TreeNode(const TreeNode& tn);
  ~TreeNode();
  //virtual ~TreeNode();

  void operator=(const TreeNode& tn);


  //int key;
  E key;
  //V value;
  TreeNode *left;
  TreeNode *right;
};

//.cpp implementation
//template <int K, class V>
template <class E>
TreeNode<E>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

//template <int K, class V>
template <class E>
TreeNode<E>::TreeNode(const E& e){
  key = e;
  left = NULL;
  right = NULL;
}

template <class E>
TreeNode<E>::TreeNode(const TreeNode& tn){
  key = E(tn.key);
  
  if(tn.left == NULL) {
    left = NULL;
  }
  else {
    left = new TreeNode<E>(*tn.left);
  }

  if(tn.right == NULL) {
    right = NULL;
  }
  else {
    right = new TreeNode<E>(*tn.right);
  }
}

//template <int K, class V>
template <class E>
TreeNode<E>::~TreeNode(){
  if(left != NULL) {
    delete left;
  }
  if(right != NULL) {
    delete right;
  }
}

template <class E>
void TreeNode<E>::operator=(const TreeNode& tn){
  key = tn.key;
  left = tn.left;
  right = tn.right;
}

#endif