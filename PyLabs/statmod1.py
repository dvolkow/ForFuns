import random # -- генератор псеводслучайных чисел в python
import math # -- математические функции

sample_f = open('data.txt', 'w') # -- выборка
mns_f = open('means.txt', 'w') # -- средние
sd_f = open('sd_means.txt', 'w') # -- ошибка среднего
disp_f = open('disp.txt', 'w') # -- дисперсии
err_disp_f = open('sd_disp.txt', 'w') # -- ошибки дисперсий

# -- объявление пустых списков
sample = []
means = [] # средние элементов выборки
disp = []

# -- временные переменные
tmp_sum = 0
tmp_means = 0

for i in range(1000):
    current = math.sqrt(-0.5 * math.log(1 - random.uniform(0,1), math.e)) # -- обратная функция распределения
    tmp_sum = tmp_sum + current # -- обновляем сумму

    if (i != 0):
        tmp_means = tmp_sum / i # -- вычисление среднего
        means.append(tmp_means) # -- добавляем в список
        mns_f.write(str(tmp_means)) # -- записываем в файл
        mns_f.write("\n")
    else:
        tmp_means = current # -- когда i = 0

    sample.append(current)
    sample_f.write(str(current))
    sample_f.write("\n")


sd = 0
for e in means: # -- по средним
    sd = (e - tmp_means) ** 2
    sd_f.write(str(sd))
    sd_f.write("\n")

tmp_disp = 0
tmp_d = 0
k = 1 # -- число элементов в выборке
for d in sample: # -- здесь считаем дисперсию
    tmp_d = tmp_d + (d - tmp_means) ** 2
    tmp_disp = tmp_d / k # -- дисперсия
    disp.append(tmp_disp)
    disp_f.write(str(tmp_disp))
    disp_f.write("\n")
    k = k + 1

for e in disp: # -- по дисперсиям
    sd = (e - tmp_disp) ** 2
    err_disp_f.write(str(sd))
    err_disp_f.write("\n")

# -- закрываем файлы
sample_f.close()
sd_f.close()
mns_f.close()
err_disp_f.close()
disp_f.close()
