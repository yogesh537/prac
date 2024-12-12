def input_marks():
    marklist = []
    n = int(input("Enter number of students: "))
    for i in range(n):
        mark = int(input(f"Enter marks of student {i + 1}: "))
        marklist.append(mark)
    return marklist

def calculate_average(marklist):
    total=0
    div=len(marklist)
    for i in marklist :
        if i != -1:
            total=total+i
        else:
            div-=1
    return (total/div)

def find_highest_and_lowest(marklist):
    Max=marklist[0]
    Min=marklist[0]
    for i in marklist :
        if i > Max:
            Max=i
        if i != -1 and i < Min  :
            Min = i
    return Max , Min

def count_absent_students(marklist):
    ab=0
    for i in marklist :
        if i == -1:
            ab+=1
    return ab

def find_highest_frequency(marklist):
    high=0
    m=0
    for mark in marklist:
        temp=0
        if mark != -1 :
            for i in marklist:
                if mark==i:
                    temp+=1
            if temp > high :
                high = temp 
                m=mark
    return high , m

# Input marks
marklist = input_marks()
print("Marks of each student:", marklist)

# Calculate and display average
avg = calculate_average(marklist)
print("Average is:", avg)

Max , Min = find_highest_and_lowest(marklist)
print("MAX :",Max, "MIN :" , Min)

ab_c=count_absent_students(marklist)
print("Absent :",ab_c)

high , m=find_highest_frequency(marklist)
print(" Highest Frequency :" , high, "marks is :", m)


