# JAR: https://cs50.harvard.edu/x/2023/problems/6/jar/

class Jar:
    def __init__(self, capacity=12):
        if capacity < 1:
            raise ValueError("Please insert a positive number")
        self._capacity = capacity
        self._n = 0

    def __str__(self):
        return "🍪" * self._n

    def deposit(self, n):
        if self._n + n > self._capacity:
            raise ValueError("Capacity exceeded")
        self._n += n

    def withdraw(self, n):
        if self._n < n:
            raise ValueError("Withdraw number greater than currently number of cookies")
        self._n -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._n

my_jar = Jar(10)
my_jar.deposit(4)
print(my_jar)