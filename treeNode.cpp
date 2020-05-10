#include <iostream>
using namespace std;

template <class E>
class TreeNode{
public:
  TreeNode();
  TreeNode(E e);
  ~TreeNode();
  //virtual ~TreeNode();

  //int key;
  E key;
  TreeNode *left;
  TreeNode *right;
};

//.cpp implementation
template <class E>
TreeNode<E>::TreeNode(){
  key = 0;
  left = NULL;
  right = NULL;
}

template <class E>
TreeNode<E>::TreeNode(E value){
  key = value;
  left = NULL;
  right = NULL;
}

template <class E>
TreeNode<E>::~TreeNode(){

}
