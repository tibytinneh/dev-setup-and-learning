import math

age = 99
height = 1.55
cplx = 1 + 1j

base = int(input("Enter base: "))
height = int(input("Enter height: "))
print(f'The area of the triangle is: {0.5 * base * height}')

a = int(input("Enter side a: "))
b = int(input("Enter side b: "))
c = int(input("Enter side c: "))
print(f"The perimeter of the triangle is {a + b + c}")

r = float(input("Enter radius: "))
pi = 3.14
print(f"The area of the circle is {pi * r * r}")
print(f"The circumference of the circle is (2 * pi * r)")

# length = int(input("Enter length: "))
# width = int(input("Enter width: "))
x = int(input("Enter x-coordinate: "))
m = int(input("Enter slope: "))
y = int(input("Enter y-coordinate: "))
c = int(input("Enter y-intercept: "))
print(f"The equation is {y} = {m}x + {c}")
print(f"The slope is {m}")
print(f"The y-intercept is {c}")
print(f"The x-intercept is {-c/m}")
