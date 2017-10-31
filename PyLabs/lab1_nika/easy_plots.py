#!/usr/bin/env python
# -*- coding: utf-8 -*-
import math
import numpy as np
import random
import matplotlib.pyplot as plt

SIGMA = 0.5                                 # --- Заданный параметр распределения
COUNT_ELEMENT = 1000                        # --- Количество элементов в выборке
COUNT_ROUNDS = 100                          # --- Количество элементов в выборке

M = math.sqrt(math.pi / 2) * SIGMA          # --- Теоретическое матожидание
D = (2 - math.pi / 2) * SIGMA ** 2          # --- Теоретическая дисперсия

# --- получение случайных величин по релеевскому закону распределения
def get_rayleigh():
    return math.sqrt(-SIGMA * math.log(1 - random.uniform(0, 1), math.e));


# --- массивы для хранения данных для построения графиков:
means_all = []                              # --- математические ожидания
disp_all = []                               # --- дисперсии
means_error_all = []                        # --- кв. ошибок матожданий
disps_error_all = []                        # --- кв. ошибок дисперсий

# --- генерация данных
for i in range(COUNT_ROUNDS):               # --- в этом цикле получаем выборки
    tmp_sum = 0                             # --- здесь хранится текущая сумма

    # --- создаем выборку из COUNT_ELEMENT элементов:
    random_array = np.array([get_rayleigh() for i in range(COUNT_ELEMENT)])

    # --- врЕменные массивы (для соответствующих параметров):
    tmp_means = []
    tmp_error_means = []
    tmp_disps = []
    tmp_error_disps = []

    for i in range(COUNT_ELEMENT):          # --- в этом цикле считаем матожидания и дисперсии
        tmp_sum += random_array[i]          # --- обновляем сумму
        current_mean = tmp_sum / (i + 1.0)    # --- вычисляем текущее среднее
        tmp_means.append(current_mean)      # --- добавляем в соответствующий массив

        # --- вычисляем квадрат ошибки среднего и записываем
        tmp_error_means.append((current_mean - M) ** 2)

        # --- вычисляем второй центральный момент
        current_disp = sum((random_array[:i] - current_mean) ** 2) / (i + 1)
        tmp_disps.append(current_disp)      # --- записываем его

        # --- вычисляем квадрат ошибки дисперсии и записываем
        tmp_error_disps.append((current_disp - D) ** 2)

    # --- добавляем временные массивы в глобальные:
    means_all.append(tmp_means)
    means_error_all.append(tmp_error_means)
    disp_all.append(tmp_disps)
    disps_error_all.append(tmp_error_disps)

    plt.plot(tmp_means) # --- здесь же рисуем средние

# --- рисуем линию для теоретического среднего:
plt.plot([M for i in range(COUNT_ELEMENT)], 'g--', linewidth=3.5)
# --- рисуем линии для границы 3 sigma:
plt.plot([M + 3.0 * math.sqrt(D / COUNT_ELEMENT) for i in range(COUNT_ELEMENT)], 'r--', linewidth=1.5)
plt.plot([M - 3.0 * math.sqrt(D / COUNT_ELEMENT) for i in range(COUNT_ELEMENT)], 'r--', linewidth=1.5)
plt.show() # --- cначала рисуем зависимость средних от N

# --- устанавливаем логарифмические масштабы по осям, основание 2
plt.xscale('log', basex=2)
plt.yscale('log', basey=2)
for i in range(COUNT_ROUNDS):
    plt.plot(means_error_all[i])
plt.show() # --- квадрат ошибки среднего от N

for i in range(COUNT_ROUNDS):
    plt.plot(disp_all[i])
# --- рисуем линию для теоретической дисперсии:
plt.plot([D for i in range(COUNT_ELEMENT)], 'g--', linewidth=3.5)
plt.show() # --- дисперсия от N

# --- устанавливаем логарифмические масштабы по осям, основание 2
plt.xscale('log', basex=2)
plt.yscale('log', basey=2)
for i in range(COUNT_ROUNDS):
    plt.plot(disps_error_all[i])
plt.show() # --- квадрат ошибки дисперсии от N

# --- осредненные графики:
mean = []  # --- для кв. ошибки матожидания
disp = []  # --- для кв. ошибки дисперсии
for i in range(COUNT_ELEMENT):
    tmp_sum_m = 0
    tmp_sum_d = 0
    for j in range(COUNT_ROUNDS):
        tmp_sum_m += means_error_all[j][i]
        tmp_sum_d += disps_error_all[j][i]
    tmp_sum_m /= COUNT_ROUNDS
    tmp_sum_d /= COUNT_ROUNDS

    mean.append(tmp_sum_m)
    disp.append(tmp_sum_d)

# --- устанавливаем логарифмические масштабы по осям, основание 2
plt.xscale('log', basex=2)
plt.yscale('log', basey=2)
plt.plot(mean)
plt.show() # --- квадрат ошибки среднего от N

# --- устанавливаем логарифмические масштабы по осям, основание 2
plt.xscale('log', basex=2)
plt.yscale('log', basey=2)
plt.plot(disp)
plt.show() # --- квадрат ошибки дисперсии от N

