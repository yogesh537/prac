def accept():
    n = int(input("Enter Total of students: "))
    L = []
    print("Enter first year percentage of students:")
    for i in range(n):
        L.append(float(input()))
    return L, n

def bubbleSort(arr, n):
    f = 0
    for i in range(n - 1):  # 0 to n-2
        for j in range(0, n - i - 1):  # 0 to n-i-2
            if arr[j] > arr[j + 1]:
                temp = arr[j + 1]
                arr[j + 1] = arr[j]
                arr[j] = temp
        print(f"After pass {i + 1}", arr)
    return arr

def selectionSort(arr, n):
    for i in range(n):  # 0 to n-1
        min_index = i  # Assume the minimum is at index i
        for j in range(i + 1, n):  # i+1 to n-1
            if arr[j] < arr[min_index]:
                min_index = j
        temp = arr[i]
        arr[i] = arr[min_index]
        arr[min_index] = temp
        print(f"After pass {i + 1}", arr)
    return arr

L, n = accept()
print("Entered list is:", L)

a = bubbleSort(L, n)
print("Sorted list after Bubble Sort:\n", a)

b = selectionSort(L, n)
print("Sorted list after Selection Sort:\n", b)

print("Top 5 scores are:")
print(b[:-6:-1])