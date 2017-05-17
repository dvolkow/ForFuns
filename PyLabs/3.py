import math

#--функция, вычисляющая log(2) по формуле из задания
def LAB3_VAR9_4():
    eps = 10**(-6) #--точность
    a = 1 #--добавка к текущей сумме
    k = 1 #--номер слагаемого
    res = 0; #--промежуточный результат
    while a > eps: #--заголовок цикла
        if (k + 1) % 2 == 0: #--для нечетных k
            res += 1.0 / k #--прибавляем
        else: #--для четных k
            res -= 1.0 / k #--отнимаем
        k = k + 1 #--увеличиваем k
        a = 1.0 / k #--новая добавка
    return res #--возврат из функции

#---TEST---
print(LAB3_VAR9_4()) #---результат нашей функции
print(math.log(2, math.e))  #---результат библиотечной функции


