# rlly dying because im speedrunning fml


emptylst = []
print(len(emptylst))


lst5 = [1, 2, 3, 4, 5]
print(len(lst5))
print(lst5[0], lst5[len(lst5)//2], lst5[-1])

mixed_data_types = [1, 'two', 3.14, True, [5, 6, 7]]
it_companies = ['Facebook', 'Google', 'Micrsoft', 'Apple', 'IBM', 'Oracle', 'Amazon']

print(mixed_data_types)
print(it_companies)
print(len(it_companies))
print(it_companies[0], it_companies[len(it_companies)//2], it_companies[-1])
it_companies.append("Banana")
it_companies.insert(len(it_companies)//2,"Kiwi")
it_companies[0] = it_companies[0].upper()
print(it_companies)
it_str = "#; ".join(it_companies)
print(it_str)
print(it_companies)

if 'Apple' in it_companies:
	print("Apple is in the list")
else:
    print("Apple is not in the list")

it_companies.sort()
print(it_companies)
it_companies.reverse()
print(it_companies)
del it_companies[0:3]
print(it_companies)

del it_companies[-1:-4:-1]
print(it_companies)

del it_companies[len(it_companies)//2]
print(it_companies)

it_companies.clear()
print(it_companies)
del it_companies

front_end = ['HTML', 'CSS', 'JS', 'React', 'Redux']
back_end = ['Node', 'Express', 'MongoDB']

full_stack = (front_end + back_end).copy()
print(full_stack)

full_stack.insert(full_stack.index('Redux') + 1,"Python")
full_stack.insert(full_stack.index('Redux') + 2, "SQL")
print(full_stack)

# Exercises Level 2

ages = [19, 22, 19, 24, 20,25, 26, 24, 25, 24]
ages.sort()
print(ages)
min_age = min(ages)
max_age = max(ages)
print(min_age, max_age)

ages.append(min_age)
ages.append(max_age)
print(ages)

average_age = sum(ages)/len(ages)
print (average_age)

age_range = max_age - min_age
print(age_range)

value = abs(min_age - average_age - (max_age - average_age))
print(value)



# TODO: last country part next time im dying speedrunning in 30nmins


