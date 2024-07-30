# Day 1 of 30DaysOfPython Challenge
# Single line comments
""" Multi line comments"""
'''multi line comments'''

print("------------------------------------------------------\n"
"This are my exercises for Day 1 of 30DaysOfPython Challenge.\n")
print("Strings have to be in a quoted string format.\n"
      "They can be wrapped in double quotes (\") or in single quotes (\')\n"
      'We can include multiple quoted strings in a print() function call.\n'
      "A \\n character is printed out at the very end of every print() function call\n"
      "But we would have to include the \\n character in multiple quoted strings in a single print() function call.\n"
      "If the string is more than a sentence, we can use triple quotes. (\'\'\')\n")

print('''In triple quotes, we need to be wary of the indentation.
      Leaving an auto-indented tab within the triple quotes will print it out.
Within the triple quotes, indentations and \\n characters will be registered.
Printing in python is very convenient,
To print a digit 1, we can just print(1) without declaring the datatype.
print(1):''')
print(1)
print(''' We can directly use operations in the print function.
Spaces are negligible.''')
print("print(1+2)\nResult:")
print(1+2)
print("print(2 + 3.5)\nResult:")
print(2 + 3.5)
print("------------------------------------------------------\n"
      "Exercise 1:\n"
      "I will be practising the following operations with the operands 3 and 4:\n"
      "Addition(+)\n"
      "Subtraction(-)\n"
      "Multiplication(*)\n"
      "Modulus(%)\n"
      "Division(/)\n"
      "Exponential(**)\n"
      "Floor division operation(//)\n"
 )

print("------------------------------------------------------\n"
      "Addition(+)\n"
    "print(3 + 4)\nResult:")
print(3 + 4)
print("------------------------------------------------------\n"
      "Subtraction(-)\n"
      "print(3 - 4)\nResult:")
print(3 - 4)
print("------------------------------------------------------\n"
      "Multiplication(*)\n"
      "print(3 * 4)\nResult:")
print(3 * 4)
print("------------------------------------------------------\n"
      "Modulus(%) aka remainder\n"
      "print(3 % 4)\nResult:")
print(3 % 4)
print("------------------------------------------------------\n"
      "Division(/)\n"
    "print(3 / 4)\nResult:")
print(3 / 4)
print("------------------------------------------------------\n"
      "Exponential(**) aka a to the power of b\n"
    "print(3 ** 4)\nResult:")
print(3 ** 4)
print("------------------------------------------------------\n"
      "Floor divison operation(//) aka integer division\n"
    "print(3 // 4)\nResult:")
print(3 // 4)
print("------------------------------------------------------\n")

print("Exercise: Write strings")
print("Tinni")
print("Tinnerz")
print("Singapore")
print("I am enjoying 30 days of python")
print("------------------------------------------------------\n")
print('''We can check the type of a data using the type() function.
We can also use help() in Python interactive mode to check out what a function does.''')
print("Exercise: Check datatypes")
print(type(10))
print(type(9.8))
print(type(3.14))
print(type(4 - 4j)) #bruh wtf is j
print(type(['Asabeneh', 'Python', 'Finland']))
print(type('Tinni'))
print(type('Tinnerz'))
print(type('Singapore'))
print("------------------------------------------------------\n")
print('Level 3:\n'
      'Exercise: write an example for different Python datatypes such as Number\(Integer, Float, Complex\), String, Boolean, List, Tuple, Set and Dictionary.')

# Number(Integer, Float, Complex)
print("------------------------------------------------------")
print("Integer: Represents whole numbers without a fractional part")
print(type(69))
print("\n------------------------------------------------------")
print("Float: Represents real numbers with a fractional part")
print(type(6.9))
print(type(69.0))
print("\n------------------------------------------------------")
print("Complex: Represents complex numbers with a real and imaginary part")
print(type(4 + 4j))
print(type(69 + 6.9j))
print("\n------------------------------------------------------")
print("String: Represents a sequence of characters enclosed in single, double or triple quotes.")
print(type('uwu'))
print(type("uwu"))
print(type('''uwu'''))
print("\n------------------------------------------------------")
print("Boolean: Represents True or False")
print(type(True))
print(type(False))
print("\n------------------------------------------------------")
print("List: An ordered collection of items that can be of different types, enclosed in square brackets.")
print(type([1, 2, 3, 4]))
print(type(['a', 'b', 'c', 'd']))
print(type([2, 'b', 'c', 'd']))
print("\n------------------------------------------------------")
print("Tuple: An ordered collection of items similar to a list, but immutable, enclosed in parentheses.")
print(type((1, 2, 3, 4)))
print(type(('a', 'b', 'c', 'd')))
print(type((2, 'b', 'c', 'd')))
print("\n------------------------------------------------------")
print("Set: An unordered collection of unique items, enclosed in curly braces.")
print(type({1, 2, 3, 4}))
print(type({'a', 'b', 'c', 'd'}))
print(type({2, 'b', 'c', 'd'}))
print("\n------------------------------------------------------")
print("Dictionary: An unordered collection of key-value pairs, enclosed in curly braces.")
print(type({
    "name": "tinni",
    "age": 69,
    "country": "Singapore",
    "equipment": ["keyboard", "ipad", "mimi"],
    "favourite": {
        "color": "blue",
        6: 99999
     }
}))
print("\n------------------------------------------------------")
print('Exercise: Find an Euclidean distance between (2, 3) and (10, 8)')
print('''Euclidean distance is a measure of the "straight line" distance between two points in a Euclidean space.

The formula for Euclidean distance in 2D is 
      squareroot((x2 - x1)^2 + (y2 - y1)^2
The formula for Euclidean distance in 3D is
      squareroot((x2 - x1)^2 + (y2 - y1)^2 + (z2 -z1)^2).

In order to use the square root function in Python, we have to import the math library.
      import math
      
We can declare the points as tuple variables, immutable collection of items.

point1 = (2,3)
point2 = (10, 8)

We can access
      x1 (2) with point1[0], x2 with point2[0]
      y1 (2) with point1[1], y2 with point2[1]

To use the square root function from the math library
      math.sqrt()
In print(), we can use an f-string.
      print(f`Your string here {variable} {expression})           

f-string allows us to easily include variable values in strings.
The values of the expressions inside the curly braces are evaluated at runtime and converted into strings.
Resulting in a formatted string that includes the values of these variables.\n''')

import math

point1 = (2, 3)

point2 = (10, 8)

distance = math.sqrt((point2[0] - point1[0])**2 + (point2[1] - point1[1])**2)
print(f'The Euclidean distance between {point1} and {point2} is {distance}')
