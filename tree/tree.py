class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
  
  def __str__(self):
    return str(self.data)
class BinaryTree:
  def __init__(self, data = None, node = None):
    if node:
      self.root = node
    elif data:
      node = Node(data)
      self.root = node
    else:
      self.root = None

  def inorder_traversal(self, node = None):
    if node is None:
      node = self.root
    if node.left:
      self.inorder_traversal(node.left)
    print(node)
    if node.right:
      self.inorder_traversal(node.right)

  def postorder_traversal(self, node = None):
    if node is None:
      node = self.root
    if node.left:
      self.postorder_traversal(node.left)
    if node.right:
      self.postorder_traversal(node.right)
    print(node)

  def height(self, node = None):
    if node is None:
      node = self.root
    hleft = 0
    hright = 0
    if node.left:
      self.height(node.left)
    if node.right:
      self.height(node.right)
    if hright > hleft:
      return hright + 1
    return hleft + 1

class BinarySearchTree(BinaryTree):
  def insert(self, value):
    parent = None
    pointer = self.root
    while pointer:
      parent = pointer
      if value < pointer.data:
        pointer = pointer.left
      else:
        pointer = pointer.right
    if parent is None:
      self.root = Node(value)
    elif value < parent.data:
      parent.left = Node(value)
    else:
      parent.right = Node(value)
    
  def search(self, value):
    return self._search(value, self.root)

  def _search(self, value, node):
    if node is None:
      return node
    if node.data == value:
      return BinarySearchTree(node)
    if value < node.data:
      return self._search(value, node.left)