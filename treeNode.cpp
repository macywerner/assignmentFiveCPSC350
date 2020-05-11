#include <iostream>
using namespace std;

//template <int K, class V>
template <class E>
class TreeNode{
public:
  TreeNode();
  //TreeNode(K k, V v);
  TreeNode(E e);
  ~TreeNode();
  //virtual ~TreeNode();

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
  key = key;
  //value = v;
  left = NULL;
  right = NULL;
}

//template <int K, class V>
template <class E>
TreeNode<E>::~TreeNode(){
  delete left;
  delete right;
}
