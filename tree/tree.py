class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
  
  def __str__(self):
    return str(self.data)
class BinaryTree:
  def __init__(self, data = None):
    if data:
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