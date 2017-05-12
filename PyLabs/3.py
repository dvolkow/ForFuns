import math

#--функция, вычисляющая log(2) по формуле из задания
def log_2():
    eps = 10**(-6) #--точность
    a = 1
    k = 1
    res = 0;
    while a > eps:
        if (k + 1) % 2 == 0:
            res += 1.0 / k
        else:
            res -= 1.0 / k
        k = k + 1
        a = 1.0 / k
    return res

print(log_2()) #---результат нашей функции
print(math.log(2, math.e))  #---результат библиотечной функции


