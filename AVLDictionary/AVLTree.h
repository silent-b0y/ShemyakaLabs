#ifndef AVLTREE_H
#define AVLTREE_H

#include "DictionaryList.h"
#include "QueueArray.h"

template < class K, class D >
class AVLTree
{
public:
  AVLTree():
    root_(nullptr)
  {}
  ~AVLTree();
  struct Node
  {
    K key_;
    Node* left_;
    Node* right_;
    int balanceFactor_;
    D data_;
    Node(const K& key, const D& data, Node* left = nullptr, Node* right = nullptr):
      key_(key),
      balanceFactor_(0),
      left_(left),
      right_(right),
      data_(data)
    {}
  };
  AVLTree(const AVLTree&) = delete;
  AVLTree(AVLTree&&) noexcept;
  bool insert(const K&, const D&);
  Node* search(const K&) const;
  bool deleteKey(const K&);
  AVLTree& operator=(const AVLTree&) = delete;
  AVLTree& operator=(AVLTree&&) noexcept;
private:
  Node* root_;
  int height(Node*);
  int balanceFactor(Node*);
  void fixBF(Node*);
  Node* rotateRight(Node*);
  Node* rotateLeft(Node*);
  Node* balance(Node*);
  Node* insert(Node*, const K&, const D&, bool&);
  Node* findMin(Node*);
  Node* deleteMin(Node*);
  Node* deleteKey(Node*, const K&, bool&);
};

#endif

template<class K, class D>
inline AVLTree<K, D>::~AVLTree()
{
  if (root_ != nullptr)
  {
    QueueArray< Node* > queue;
    queue.enQueue(root_);
    
    while (!queue.isEmpty())
    {
      for (int i = 0; i < queue.size(); ++i)
      {
        Node* temp = queue.deQueue();
        if (temp->left_ != nullptr)
        {
          queue.enQueue(temp->left_);
        }
        if (temp->right_ != nullptr)
        {
          queue.enQueue(temp->right_);
        }
        delete temp;
      }
    }
  }
}

template<class K, class D>
inline AVLTree<K, D>::AVLTree(AVLTree&& tree) noexcept:
  root_(tree.root_)
{
  tree.root_ = nullptr;
}

template<class K, class D>
inline bool AVLTree<K, D>::insert(const K& key, const D& data)
{
  bool inserted = false;
  root_ = insert(root_, key, data, inserted);
  return inserted;
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::search(const K& key) const
{
  if (root_ == nullptr)
  {
    return nullptr;
  }
  else
  {
    Node* node = root_;
    while (node != nullptr)
    {
      if (key > node->key_)
      {
        node = node->right_;
      }
      else if (key < node->key_)
      {
        node = node->left_;
      }
      else
      {
        return node;
      }
    }
  }
  return nullptr;
}

template<class K, class D>
inline bool AVLTree<K, D>::deleteKey(const K& key)
{
  bool deleted = false;
  root_ = deleteKey(root_, key, deleted);
  return deleted;
}

template<class K, class D>
inline AVLTree<K, D>& AVLTree<K, D>::operator=(AVLTree&& tree) noexcept
{
  if (this != &tree)
  {
    std::swap(root_, tree.root_);
  }
  return *this;
}

template<class K, class D>
inline int AVLTree<K, D>::height(Node* node)
{
  if (node == nullptr)
  {
    return 0;
  }
  int left = height(node->left_);
  int right = height(node->right_);
  if (left > right)
  {
    return left + 1;
  }
  else
  {
    return right + 1;
  }
}

template<class K, class D>
inline int AVLTree<K, D>::balanceFactor(Node* node)
{
  return node ? node->balanceFactor_ : 0;
}

template<class K, class D>
inline void AVLTree<K, D>::fixBF(Node* node)
{
  if (node != nullptr)
  {
    node->balanceFactor_ = height(node->right_) - height(node->left_);
  }
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::rotateRight(Node* node)
{
  Node* newRoot = node->left_;
  node->left_ = newRoot->right_;
  newRoot->right_ = node;
  fixBF(node);
  fixBF(newRoot);
  if (root_ == node)
  {
    root_ = newRoot;
  }
  return newRoot;
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::rotateLeft(Node* node)
{
  Node* newRoot = node->right_;
  node->right_ = newRoot->left_;
  newRoot->left_ = node;
  fixBF(node);
  fixBF(newRoot);
  if (root_ == node)
  {
    root_ = newRoot;
  }
  return newRoot;
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::balance(Node* node)
{
  fixBF(node);
  if (balanceFactor(node) == 2)
  {
    if (balanceFactor(node->right_) < 0)
    {
      node->right_ = rotateRight(node->right_);
    }
    return rotateLeft(node);
  }
  if (balanceFactor(node) == -2)
  {
    if (balanceFactor(node->left_) > 0)
    {
      node->left_ = rotateLeft(node->left_);
    }
    return rotateRight(node);
  }
  return node;
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::insert(Node* node, const K& key, const D& data, bool& inserted)
{
  if (node == nullptr)
  {
    Node* newNode = new Node(key, data);
    inserted = true;
    return newNode;
  }
  if (key < node->key_)
  {
    node->left_ = insert(node->left_, key, data, inserted);
  }
  else if (key > node->key_)
  {
    node->right_ = insert(node->right_, key, data, inserted);
  }
  else
  {
    return node;
  }
  return balance(node);
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::findMin(Node* node)
{
  return node->left_ ? findMin(node->left_) : node;
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::deleteMin(Node* node)
{
  if (node->left_ == nullptr)
  {
    return node->right_;
  }
  node->left_ = deleteMin(node->left_);
  return balance(node);
}

template<class K, class D>
inline typename AVLTree<K, D>::Node* AVLTree<K, D>::deleteKey(Node* node, const K& key, bool& deleted)
{
  if (node == nullptr)
  {
    return nullptr;
  }
  if (key < node->key_)
  {
    node->left_ = deleteKey(node->left_, key, deleted);
  }
  else if (key > node->key_)
  {
    node->right_ = deleteKey(node->right_, key, deleted);
  }
  else
  {
    Node* left = node->left_;
    Node* right = node->right_;
    delete node;
    deleted = true;
    if (right == nullptr)
    {
      return left;
    }
    Node* min = findMin(right);
    min->right_ = deleteMin(right);
    min->left_ = left;
    return balance(min);
  }
  return balance(node);
}
