import math

def my_function(x1, x2):
    if x1 <= 0:
        print("Аргумент x1 должен быть больше нуля!")
        return
    if x1 > 1:
        print("Аргумент x1 не должен быть больше 1")
        return
    return math.sqrt(-2 * math.log(x1, math.e)) * math.sin(2 * math.pi * x2)


print(my_function(1.1, 1))
print("=================")
print(my_function(0, 1))
print("=================")
print(my_function(1, 0))
print("=================")
print(my_function(-1, 100))
print("=================")
print(my_function(0.5, 1))
print("=================")
print(my_function(4, 3))
print("=================")




