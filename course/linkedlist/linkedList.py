from node import Node
class LinkedList:
  def __init__(self):
    self.head = None
    self._size = 0

  def __len__(self):
    return self._size
  
  def __repr__(self):
    r = ""
    pointer = self.head
    while pointer:
      r += str(pointer.data) + "->"
      pointer = pointer.next
    return r
    
  def __str__(self):
    return self.__repr__

  def _getNode(self, index):
    pointer = self.head
    for _ in range(index):
      if pointer:
        pointer = pointer.next
      else:
        raise IndexError("list index out of range")
    return pointer

  def append(self, elem):
    if self.head:
      pointer = self.head
      while pointer.next:
        pointer = pointer.next
      pointer.next = Node(elem)
    else:
      self.head = Node(elem)
    self._size += 1

  def get(self, index):
    pointer = self._getNode(index)
    
    if pointer:
      return pointer.data
    raise IndexError("list index out of range")
    
  def set(self, index, elem):
    pointer = self._getNode(index)

    if pointer:
      pointer.data = elem

    else:
      raise IndexError("list index out of range")

  def index(self, elem):
    pointer = self.head
    i = 0
    while pointer:
      if pointer.data == elem:
        return i

      pointer = pointer.next
      i += 1
    raise ValueError(f"{elem} is not in list")
  
  def insert(self, index, elem):
    node = Node(elem)
    if index == 0:
      node.next = self.head
      self.head = node
    
    else:
      pointer = self._getNode(index-1)
      node.next = pointer.next
      pointer.next = node
    self._size += 1

  def remove(self, elem):
    if self.head == None:
      raise ValueError(f"{elem} is not in list") 

    elif elem == self.head.data:
      self.head = self.head.next
      self._size -= 1
      return True

    else:
      ancestor = self.head
      pointer = self.head.next
      while pointer:
        if pointer.data == elem:
          ancestor.next = pointer.next
          pointer.next = None
        ancestor = pointer
        pointer = pointer.next
      self._size -= 1
      return True