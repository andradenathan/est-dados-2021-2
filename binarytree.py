class TNode:
    def __init__(self, elem):
        self.elem = elem
        self.left = None
        self.right = None

class BinaryTree:
    def __init__(self, data = None):
        if data:
            self.root = TNode(data)
        else:
            self.root = None

    def symmetric_traversal(self, node = TNode):
        if node is None:
            node = self.root
        if node.left:
            self.symmetric_traversal(node.left)
        print(node.elem)
        if node.right:
            self.symmetric_traversal(node.right)
    
    #TODO: need to implement the preorder traversal and the postorder traversal

tree = BinaryTree()
root = TNode(4)
left = TNode(14)
right = TNode(27)

tree.root = root
tree.root.left = left
tree.root.right = right
tree.symmetric_traversal(tree.root)