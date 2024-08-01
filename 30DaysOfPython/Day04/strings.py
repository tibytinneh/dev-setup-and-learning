# rushing this, revisit later.

concat = " ".join(['Thirty', 'Days', 'Of', 'Python'])
print(concat)

concat = " ".join(['Coding', 'For', 'All'])
print(concat)

company = concat
print(company)
print(len(company))
print(company.upper())
print(company.lower())
print(company.capitalize())
print(company.title())
print(company.swapcase())

company = ' '.join((company.split())[1:])
print(company)

print("in:")
if 'Coding' in company:
	print(True)
else:
	print(False)

print("find:")
if company.find('Coding') != -1:
	print(True)
else:
	print(False)

# print("index")
# if company.index('Coding'):
# 	print(True)
# else:
# 	print(False)

company = 'Coding For All'
company.replace('Coding', 'Python')
print(company)
company2 = 'Python For Everyone'
company.replace('Python For Everyone', 'Python For All')
print(company2)

company = 'Coding For All'
lst = company.split(sep=' ')
print(lst)

companies = "Facebook, Google, Microsoft, Apple, Amazon"
companies_list = companies.split(', ')
print(companies_list)

company = 'Coding For All'
print(company[0])
print(company[10])


pfe = 'Python For Everyone'
cfa = 'Coding For All'
print(cfa)
print(cfa.index('C'))
print("Coding For All People".rfind('l'))
longaf = "You cannot end a sentence with because because because is a conjunction."
print(longaf.index('because'))
print(longaf.index('because'))
print(longaf.rindex('because'))
print(longaf.replace("because because because", ""))


print('---------')
if cfa.startswith('Coding'):
	print(True)
else:
	print(False)
if cfa.endswith('Coding'):
	print(True)
else:
	print(False)
print('---------')

print('   Coding For All   '.strip())
print("30DaysOfPython".isidentifier())
print("thiry_days_of_python".isidentifier())

print('---------')

liblst = ['Django', 'Flask', 'Pyramid', 'Falcon']
print("# ".join(liblst))

seq = "I am enjoying this challenge.\nI just wonder what is next."
print(seq.splitlines())

print("Name\t\tAge\t\tCountry\t\tCity")
print("Asabeneh\t\t250\t\tFinland\t\tHelsinki")

radius = 10
area = 3.14 * radius ** 2

print(f"The area of circle with radius {radius} is {area} meters square")
print(f'''{8 + 6}
{8 - 6}
{8 * 6}
{round(8 / 6)}
{8 % 6}
{8 // 6}
{8 ** 6}''')










