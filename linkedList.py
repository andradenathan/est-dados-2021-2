from node import Node

class LinkedList:
  def __init__(self):
    self.head = None
    self._size = 0

  def __len__(self):
    return self._size

  def push(self, elem):
    if self.head:
      pointer = self.head
      while pointer.next:
        pointer = pointer.next
      pointer.next = Node(elem)
    else:
      self.head = Node(elem)
    self._size += 1

  def get(self, index):
    pointer = self.head
    for _ in range(index):
      if pointer:
        pointer = pointer.next
      else:
        raise IndexError("list index out of range")
    
    if pointer:
      return pointer.data
    raise IndexError("list index out of range")
    
  def set(self, index, elem):
    pointer = self.head
    for _ in range(index):
      if pointer:
        pointer = pointer.next
      else:
        raise IndexError("list index out of range")
    
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