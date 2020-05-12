#include <iostream>
using namespace std;

//template <int K, class V>
template <class E>
class TreeNode{
public:
  TreeNode();
  //TreeNode(K k, V v);
  TreeNode(E e);
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
TreeNode<E>::TreeNode(E key){
  this->key = key;
  //value = v;
  left = NULL;
  right = NULL;
}

template <class E>
TreeNode<E>::TreeNode(const TreeNode& tn){
  key = tn.key;
  left = tn.left;
  right = tn.right;
}

//template <int K, class V>
template <class E>
TreeNode<E>::~TreeNode(){
  delete left;
  delete right;
}

template <class E>
void TreeNode<E>::operator=(const TreeNode& tn){
  key = tn.key;
  left = tn.left;
  right = tn.right;
}