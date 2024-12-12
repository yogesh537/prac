def accept():
    """Accept a sorted list of integers from the user."""
    n = int(input("Enter the number of elements in the list: "))
    arr = []
    print("Enter the elements in sorted order:")
    for i in range(n):
        num=int(input("Enter the number :-"))
        arr.append(num)
    return arr

def linear_search(arr, key):
    """Perform Linear Search."""
    for i in range(len(arr)):
        if arr[i] == key:
            return i  # Return the index if found
    return -1  # Return -1 if not found

def binary_search(arr, key):
    """Perform Binary Search."""
    low, high = 0, len(arr) - 1
    while low <= high:
        mid = (low + high) // 2
        if arr[mid] == key:
            return mid  # Key found
        elif arr[mid] < key:
            low = mid + 1
        else:
            high = mid - 1
    return -1  # Key not found

def sentinel_search(arr, key):
    """Perform Sentinel Search."""
    n = len(arr)
    last = arr[-1]
    arr[-1] = key
    i = 0
    while arr[i] != key:
        i += 1
    arr[-1] = last
    if i < n - 1 or arr[-1] == key:
        return i  # Key found
    return -1  # Key not found

def fibonacci_search(arr, key):
    """Perform Fibonacci Search."""
    n = len(arr)
    fib2, fib1 = 0, 1  # (n-2)th and (n-1)th Fibonacci numbers
    fib = fib2 + fib1  # nth Fibonacci number

    while fib < n:
        fib2, fib1 = fib1, fib
        fib = fib2 + fib1

    offset = -1

    while fib > 1:
        i = min(offset + fib2, n - 1)
        if arr[i] < key:
            fib = fib1
            fib1 = fib2
            fib2 = fib - fib1
            offset = i
        elif arr[i] > key:
            fib = fib2
            fib1 -= fib2
            fib2 = fib - fib1
        else:
            return i  # Key found

    if fib1 and offset + 1 < n and arr[offset + 1] == key:
        return offset + 1  # Key found

    return -1  # Key not found

arr = accept()
key = int(input("Enter the key to search: "))

# Linear Search
index = linear_search(arr, key)
print("Linear Search: ", "Found at index" if index != -1 else "Not Found", index)

# Binary Search
index = binary_search(arr, key)
print("Binary Search: ", "Found at index" if index != -1 else "Not Found", index)

# Sentinel Search
index = sentinel_search(arr, key)
print("Sentinel Search: ", "Found at index" if index != -1 else "Not Found", index)

# Fibonacci Search
index = fibonacci_search(arr, key)
print("Fibonacci Search: ", "Found at index" if index != -1 else "Not Found", index)

