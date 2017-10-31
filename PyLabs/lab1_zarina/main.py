#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math
import numpy as np
import random
import matplotlib.pyplot as plt

N = 20                                      # --- Заданный параметр распределения
P = 0.2                                     # --- Заданный параметр распределения
COUNT_ELEMENT = 1000                        # --- Количество элементов в выборке
COUNT_ROUNDS = 100                          # --- Количество элементов в выборке

M = N * P          # --- Теоретическое матожидание
D = N * P * (1 - P)          # --- Теоретическая дисперсия

# --- массивы для хранения данных для построения графиков:
means_all = []                              # --- математические ожидания
disp_all = []                               # --- дисперсии
means_error_all = []                        # --- кв. ошибок матожданий
disps_error_all = []                        # --- кв. ошибок дисперсий

for i in range(COUNT_ROUNDS):
    tmp_sum = 0
    random_array = np.array([np.random.binomial(N, P) for i in range(COUNT_ELEMENT)])
    tmp_means = []
    tmp_error_means = []
    tmp_disps = []
    tmp_error_disps = []

    for i in range(COUNT_ELEMENT):
        tmp_sum += random_array[i]
        current_mean = tmp_sum / (i + 1)
        tmp_means.append(current_mean)
        tmp_error_means.append(math.log((current_mean - M) ** 2 + 1, 2))

        current_disp = sum((random_array[:i] - current_mean) ** 2) / (i + 1)
        tmp_disps.append(current_disp)
        tmp_error_disps.append(math.log((current_disp - D) ** 2, 2))

    means_all.append(tmp_means)
    means_error_all.append(tmp_error_means)
    disp_all.append(tmp_disps)
    disps_error_all.append(tmp_error_disps)
    plt.plot(tmp_means)

plt.show() # --- cначала рисуем зависимость средних от N

for i in range(COUNT_ROUNDS):
    plt.plot([math.log(j + 1, 2) for j in range(COUNT_ELEMENT)], means_error_all[i])
plt.show() # --- квадрат ошибки среднего от N

for i in range(COUNT_ROUNDS):
    plt.plot(disp_all[i])
plt.show() # --- дисперсия от N

for i in range(COUNT_ROUNDS):
    plt.plot([math.log(j + 1, 2) for j in range(COUNT_ELEMENT)], disps_error_all[i])
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

plt.plot([math.log(j + 1, 2) for j in range(COUNT_ELEMENT)], mean)
plt.show() # --- квадрат ошибки среднего от N

plt.plot([math.log(j + 1, 2) for j in range(COUNT_ELEMENT)], disp)
plt.show() # --- квадрат ошибки дисперсии от N
