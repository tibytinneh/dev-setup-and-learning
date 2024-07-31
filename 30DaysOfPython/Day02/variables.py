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


numbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Truenumbers = [5, 15, 20, 8]
any_greater_than_10 = any(num > 10 for num in numbers)
print(any_greater_than_10)  # Output: Trueprint('Exercises: Level 2\n'
	  '------------------')
current_var = 'first_name'
print(f'Variable Name: {current_var}')
print(f'Variable Value: {eval(current_var)}')
print(f'Variable Type: {type(eval(current_var))}')

current_var = 'last_name'
print(f'Variable Name: {current_var}')
print(f'Variable Value: {eval(current_var)}')
print(f'Variable Type: {type(eval(current_var))}')


# for var_name, var_value in var.items():
#     print(f'Variable Name: {var_name}')
#     print(f'Variable Value: {var_value}')
#     print(f'Variable Type: {type(var_value)}\n')

# for item in var.items():
#     print(f'Item: {item}')
