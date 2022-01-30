import sys

memoization = {}

def factorial(n):
  result = memoization.get(n)

  if result is not None: 
    return result
  
  if n <= 1: 
    return 1
  
  factorial_of_n = n * factorial(n-1)
  memoization[n] = factorial_of_n

  return factorial_of_n

sys.setrecursionlimit(2000)

print(factorial(1000))