# print()

print("Hello world")

# Printing multiple items
name = "Miku"
age = "18"

print("Name:", name, "Age:", age)
# f-string {}
print(f"Name: {name} Age: {age}")

# Printing with custom separator and end
print("My", "name", "is", name, sep="-", end="!\n")
print("My", "name", "is", name, sep="_", end="!\n")


# len()

# length of a list
numbers = [1, 2, 3, 4, 5]
print(len(numbers))

# length of a string 
strz = "My name is Miku!"
print(len(strz))


# input()
# name = input("What's your name? ")
# print("Nice to meet you, " + name + "!")


# int()
# converting numeric string into integer

# int(input())
# typecasting the input string as an integer
# age = int(input("How old are you? "))
# print("Next year, you will be", age + 1)

# type()
# Checks the type of different variables
number = 10
text = "hello"
print("type of number: ", number, type(number))
print("Type of text: ", text, type(text))



# int(), float(), str()
# int() is atoi, converts from str to int
# float is atof, converts from str to float
# str() is itoa, converts from int to str

print(type(int('42')))
print(type(float('22.0')))
print(type(str(2231)))

# sum()
numbers = [1, 2, 3, 4, 5]
print("List: ", numbers, " | Sum: ", sum(numbers))


# min() max()
# Finding the minimum and maximum in a list
print(min(numbers))
print(max(numbers))

# list(), tuple(), dict(), set()

# list() creates a list from a str
chars = list("hello")
print (chars) #Output: ['h', 'e', 'l', 'l', 'o']
chars = list("hello world!")
print (chars)

# tuple() creates a tuple from a list
# tuple is an immutable list
print((tuple(chars)))

# dict() creates a dictionary. dict(key=value, ..., key=value)
person = dict(name="Miku",age=18)
print(person)
print(person["name"])
print(person["age"])


# set() creates a set from a list

# list `chars`
print(chars)

# set from list `chars`
print(set(chars))

# list from set from list `chars` (unsorted)
print((list(set(chars))))

# sorted list from set from list `chars`
print(sorted(list(set(chars))))

# reverse sorted list from set from list `chars`
print(sorted(list(set(chars)), reverse = True))


# range()
# range(stop) -> range object
# range(start, stop[, step]) -> range object
# range() returns an object that produces a sequence of integers from start (inclusive)
#   to stop (exclusive) by step.
#   range(4) produces 0, 1, 2, 3.
#   range(i, j) produces i, i+1, i+2, ..., j-1.
#   option `step`  specifies the increment or decrement


# creating a list from a range

range_list = list(range(5))
print(range_list)

range_list = list(range(3, 8))
print(range_list)

range_list = list(range(1, 10, 2))
print(range_list)


# using range in a for loop

for i in range(5):
    print(i) # Output 0 1 2 3 4
print('---------')

for i in range(3, 8):
    print(i)
print('---------')

for i in range(1, 10, 2):
    print(i)
print('---------')

# abs() absolute value of a number
print(abs(-5))
print('---------')

# sorted(list) to sort a list in ascending number
# sorted(list, reverse = True) to sort a list in descending number

# zip()
# combines two or more iterables into a single iterable of tuples
# Zipping two lists together
print('---------')
print("zip")
print('---------')
#list(zip('abcdefg', range(3), range(4)))
# |     [('a', 0, 0), ('b', 1, 1), ('c', 2, 2)]

print(zip('abcdefg', range(3), range(4)))
print(type(zip('abcdefg', range(3), range(4))))
print(list(zip('abcdefg', range(3), range(4))))

names = ['Alice', 'Bob']
scores = [85, 92]
zipped = list(zip(names, scores))
print(zipped)  # Output: [('Alice', 85), ('Bob', 92)]
print(zipped[0])
print(type(zipped[0]))



print('---------')
print("lamda\n")
# lambda -> anonymous functions
# small one-line function that can be defined without a name.
# used in Python to create simple, inline functions that can be passed as arguments to other functions or stored in variables.

# lamba <function parameters>: <function body>
multiply =  lambda x, y: x * y
print("multiply = lambda x, y: x * y")
print("multiply(5,3):", multiply(5,3))


# filter()
# filter(function, iterable)
#   - `function` contains the expression or operations that will be performed on the iterable

# Filtering out even numbers from a list
print('---------')
numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
print("numbers:", numbers)
print('---------')
print("filter(function, iterable)")
print("even numbers:", "[lambda x : x % 2 == 0]",
    list(filter(lambda x: x % 2 == 0, numbers)))
print("odd numbers:", "[lambda x : x % 2 == 1]",
    list(filter(lambda x: x % 2 == 1, numbers)))
print("numbers lesser than 3:",
      "[lamba x: x < 3]", list(filter(lambda x: x < 3, numbers)))

# map()
# map(function, iterable)

# usage with lambda

print('---------')
print("map(function, iterable)")
list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
# lamba function to increment all values by 1
print("increment 1:", "lambda x: x + 1", list(map(lambda x: x + 1, list1)))
# lamba function to raise all values to the power of 2
print("power of 2:", "lambda x: pow(x, 2)", list(map(lambda x: pow(x, 2), list1)))

print('---------')
# any() and all()
print('any() and all()')
# any() returns `True` if any of the element of the iterable is true
# all() returns `True` if all of the elements of the iterable is true
print("any([0, 0, 1, 0]:", any([0, 0, 1, 0]))
print("any([0, 0, 0, 0]:", any([0, 0, 0, 0]))
print("all([1, 1, 1, 1]:", all([1, 1, 1, 1]))
print("all([0, 0, 0, 0]:", all([0, 0, 0, 0]))
print("all([0, 0, 1, 0]:", all([0, 0, 1, 0]))

# check if any number is greater than 10
numbers = [5, 15, 20, 8]
any_greater_than_10 = any(i> 10 for i in numbers)
print(any_greater_than_10)  # Output: True

# check if all numbers are even
numbers = [2, 4, 6, 8]
all_even = all(num % 2 == 0 for num in numbers)
print(all_even)  # Output: True

# check if any number is greater than 10 and if all numbers are even
numbers = [2, 15, 20, 8]
any_greater_than_10_and_all_even = any(num > 10 for num in numbers) and all(num % 2 == 0 for num in numbers)
print(any_greater_than_10_and_all_even)  # Output: False

# syntax = <any>/<all>(i> 10 for num in numbers)


print('---------')
print("enumerate()")
# enumerate()
items = ['apple', 'banana', 'cherry']


print((list(enumerate(items))))
print((list(enumerate(items)))[0])
print((type(list(enumerate(items)))[0]))

# reversed()
# returns a reversed iterator over the values of the given sequence
# remember to typecast into list to access the reversed elementsi

# reversed(my_list)
print(reversed([1, 2, 5, 4]))
print(type(reversed([1, 2, 5, 4])))
print(list(reversed([1, 2, 5, 4])))

# reversed(range(start, stop, step))
print(list(range(10)))
print(list(reversed(range(10))))
print(list(range(1, 10, 2)))
print(list(reversed(range(1, 10, 2))))


# round()
# round(nbr) rounds off to 0 decimal places
# round(nbr, 2) rounds off to 2 decimal places

pi = 3.14159
print(round(pi))
print(type(round(pi)))
print(round(pi, 2))
print(type(round(pi, 2)))
