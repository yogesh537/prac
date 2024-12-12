# Function to input a matrix
def input_matrix():
    row = int(input("Give the number of rows: "))
    col = int(input("Give the number of columns: "))
    matrix1 = [[0 for i in range(col)] for i in range(row)]
    for i in range(row):
        for j in range(col):
            matrix1[i][j] = int(input(f"Enter the value of [{i}][{j}]: "))
    return matrix1, row, col

# Function to display a matrix
def display_matrix(matrix, row, col):
    for i in range(row):
        for j in range(col):
            print(matrix[i][j], end=" ")
        print()

# Function to add matrices
def add_matrices(matrix1, matrix2, row1, col1, row2, col2):
    matrix3 = [[0 for i in range(col1)] for i in range(row1)]
    if row1 == row2 and col1 == col2:
        for i in range(row2):
            for j in range(col2):
                matrix3[i][j] = matrix1[i][j] + matrix2[i][j]
        return matrix3
    else:
        print("Addition not possible, dimensions do not match!")
        return None

# Function to subtract matrices
def subtract_matrices(matrix1, matrix2, row1, col1, row2, col2):
    matrix4 = [[0 for i in range(col1)] for i in range(row1)]
    if row1 == row2 and col1 == col2:
        for i in range(row2):
            for j in range(col2):
                matrix4[i][j] = matrix1[i][j] - matrix2[i][j]
        return matrix4
    else:
        print("Subtraction not possible, dimensions do not match!")
        return None

# Function to multiply matrices
def multiply_matrices(matrix1, matrix2, row1, col1, row2, col2):
    matrix5 = [[0 for i in range(col2)] for i in range(row1)]
    if col1 == row2:
        for i in range(row1):
            for j in range(col2):
                for k in range(col1):
                    matrix5[i][j] = matrix5[i][j] + matrix1[i][k] * matrix2[k][j]
        return matrix5
    else:
        print("Multiplication not possible, dimensions do not match!")
        return None

# Function to transpose matrix1
def transpose_matrix(matrix1, row, col):
    matrix6 = [[0 for i in range(row)] for i in range(col)]
    for i in range(row):
        for j in range(col):
            matrix6[j][i] = matrix1[i][j]
    return matrix6

print("Enter the 1st matrix information: ")
matrix1, row1, col1 = input_matrix()
display_matrix(matrix1, row1, col1)

print("Enter the 2nd matrix information: ")
matrix2, row2, col2 = input_matrix()
display_matrix(matrix2, row2, col2)

matrix3 = add_matrices(matrix1, matrix2, row1, col1, row2, col2)
if matrix3:
    print("The addition of matrices is: ")
    display_matrix(matrix3, row1, col1)

matrix4 = subtract_matrices(matrix1, matrix2, row1, col1, row2, col2)
if matrix4:
    print("The subtraction of matrices is: ")
    display_matrix(matrix4, row1, col1)

matrix5 = multiply_matrices(matrix1, matrix2, row1, col1, row2, col2)
if matrix5:
    print("The multiplication of matrices is: ")
    display_matrix(matrix5, row1, col2)

matrix6 = transpose_matrix(matrix1, row1, col1)
print("The transpose of matrix 1 is: ")
display_matrix(matrix6, col1, row1)

matrix7 = transpose_matrix(matrix2, row2, col2)
print("The transpose of matrix 2 is: ")
display_matrix(matrix2, col2, row2)
