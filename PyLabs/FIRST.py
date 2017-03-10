#----импорт математической библиотеки языка
import math

#----определение функции, которая вычисляет выражение из условия
def my_function(x1, x2):
    #----проверка корректности аргументов:
    if x1 <= 0:
        print("Аргумент x1 должен быть больше нуля!")
        return
    if x1 > 1:
        print("Аргумент x1 не должен быть больше 1")
        return
    #-----непосредственно вычисление и возвращение результата:
    return math.sqrt(-2 * math.log(x1, math.e)) * math.sin(2 * math.pi * x2)

#---тестовые наборы для проверки:
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




