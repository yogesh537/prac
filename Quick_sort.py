def partition(array, low, high):
    # First Element as pivot
    pivot = array[low]
    # start points to the starting of array
    start = low + 1
    # end points to the ending of the array
    end = high
    
    while True:
        # Move all elements greater than pivot to the right
        while start <= end and array[end] >= pivot:
            end = end - 1
        # Move all elements smaller than pivot to the left
        while start <= end and array[start] <= pivot:
            start = start + 1
        if start <= end:
            # Swap elements at start and end
            array[start], array[end] = array[end], array[start]
        else:
            # Swap pivot with element at end
            array[low], array[end] = array[end], array[low]
            return end

def quicksort(array, start, end):
    if start < end:  # If start is lesser than end
        idx = partition(array, start, end)
        quicksort(array, start, idx - 1)
        quicksort(array, idx + 1, end)

def print_arr(arr, n):
    for i in range(n):
        print(arr[i], end=" ")
    print()

# Driver Code
array = []
n = int(input("Enter total no of students: "))
for i in range(n):
    marks = float(input(f"Enter the marks of student {i + 1}: "))
    array.append(marks)

print("Original Marks:", array)

# Sort array using quicksort
quicksort(array, 0, n - 1)

# Display sorted marks in ascending order
print("Sorted Marks using quick sort:")
print_arr(array, n)

# Display top five elements
new_arr = array[::-1]
print("TOP FIVE MARKS ARE:")
print_arr(new_arr[:5], len(new_arr[:5]))
