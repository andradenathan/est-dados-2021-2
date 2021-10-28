class Node:
  def __init__(self, data):
    self.data = data
    self.next = None

class Queue:
  def __init__(self):
    self.head = None
    self.tail = None
    self._size = 0
    

  def push(self, elem):
    node = Node(elem)
    if self.tail is None:
      self.tail = node
    else:
      self.tail.next = node
      self.tail = node
    
    if self.head is None:
      self.head = node

    self._size += 1

  def pop(self):
    if self._size > 0:
      elem = self.head.data
      self.head = self.head.next
      self._size -= 1
      return elem    
    raise IndexError("Empty queue")
  
  def peek(self):
    if self._size > 0:
      elem = self.head.data
      return elem
    raise IndexError("Empty queue")

  def __len__(self):
    return self._size

  def __repr__(self):
    if self._size > 0:
      r = ""
      pointer = self.head
      while pointer:
        r += str(pointer.data) + " "
        pointer = pointer.next
      return r
    else:
      return 'Empty queue'

  def __str__(self):
    return self.__repr__()