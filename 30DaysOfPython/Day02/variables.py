# Day 2: 30 Days of python programming

print('Exercises: Level 1\n'
	  '------------------')

# first_name = 'tinni'
# last_name = 'tinnerz'
# full_name = first_name + ' ' + last_name
# country = 'Singapore'
# city = 'Singapore'
# age = 69
# year = 2000
# is_married = False
# is_true = True
# is_light_on = True

# a, b, c = 1, 2, 3

# Modified for learning
# Define variables in a dictionary
#	an unordered collection of key-value pairs, enclosed in curly braces.
#  you cannot access the values in the dictionary, in the dictionary(?)

first_name = 'tinni'
last_name = 'tinnerz'

var = {
    'full_name': first_name + ' ' + last_name,
    'country': 'Singapore',
    'city': 'Singapore',
    'age': 69,
    'year': 2000,
    'is_married': 'Soon',
    'is_true': True,
    'is_light_on': True,
    'a': 1,
    'b': 2,
    'c': 3
}


print('Exercises: Level 2\n'
	  '------------------')

current_var = 'first_name'
print(f'Variable Name: {current_var}')
print(f'Variable Value: {eval(current_var)}')
print(f'Variable Type: {type(eval(current_var))}')

current_var = 'last_name'
print(f'Variable Name: {current_var}')
print(f'Variable Value: {eval(current_var)}')
print(f'Variable Type: {type(eval(current_var))}')


for key, value in var.items():
    print(f'Variable Name: {key}')
    print(f'Variable Value: {value}')
    print(f'Variable Type: {type(value)}\n')

print('------------------')
first_name_len = len(first_name)
last_name_len = len(last_name)
len_diff = first_name_len - last_name_len
print(len_diff)

print('------------------\n''num_one = 5\nnum_two = 4')
num_one = 5
num_two = 4
total = num_one + num_two
print(f'total:{total}')
diff = num_one - num_two
print(f'diff:{diff}')
product = num_one * num_two
print(f'product:{product}')
division = num_one / num_two
print(f'division:{division}')
remainder = num_one % num_two
print(f'remainder:{remainder}')
exp = num_one ** num_two
print(f'exp:{exp}')
floor_division = num_one // num_two
print(f'floor_division:{floor_division}')
print('------------------\n')

import math
radius = 30

area_of_circle = round((math.pi * radius ** 2), 2)
print(f'Area of circle: {area_of_circle}')
circum_of_circle = round((2* math.pi * radius), 2)
print(f'Circumference of circle: {circum_of_circle}')

radius = (int)(input("Enter the radius of the circle: "))
print(f'Area of circle: {area_of_circle}')

first_name = input("Enter your first name: ")
last_name = input("Enter your last name: ")
country = input("Enter your country: ")
age = int(input("Enter your age: "))

print(f'Hello, {first_name} {last_name} from {country}! Congrats on being {age}.')














