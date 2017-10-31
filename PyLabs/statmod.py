#!/usr/bin/env python
# -*- coding: utf-8 -*-

import math
import numpy as np
import random
import matplotlib as mpl
import matplotlib.pyplot as plt
mpl.rc('font', family='verdana')

count_element = 1000  #Количество элементов выборки
count_round = 100    #Количество испытаний
sigma = 0.5
M = math.sqrt(math.pi / 2) * sigma
D = (2 - math.pi / 2) * sigma ** 2
m4 = - (6 * math.pi ** 2 - 24 * math.pi + 16) / (4 - math.pi) ** 2

def rayleigh():
    return math.sqrt(-sigma * math.log(1 - random.uniform(0,1), math.e));

k = 2    #Параметр для вычисления k-ого центрального момента

top=[]
bot=[]

Mu = [1 for n in range(count_element)]    #Мат.ожидание

line1=[]
line2=[]
line3=[]

lictok = plt.figure()

#ax1 = lictok.add_axes([0,2.4,1,1])
#ax2 = lictok.add_axes([0,1.2,1,1])
#ax3 = lictok.add_axes([0,0,1,1])

#ax1.grid(True, color = [1,0,0], lw = 1)
#ax2.grid(True, color = [1,0,0], lw = 1)
#ax3.grid(True, color = [1,0,0], lw = 1)

#ax1.set_ylim(0,2)
#ax1.set_xlim(0,400)

#ax2.set_ylim(-0.5,4)
#ax2.set_xlim(0,10)

#ax3.set_ylim(0,2.5)
#ax3.set_xlim(0,1000)

SredEN=[0 for n in range(count_element)]
TeorSredEN=[]


for i in range(count_round):
    np.MO = []
    np.eN = []
    np.OcenkaVtorogoMomenta = []
    
    x1 = 0
    
    red = random.uniform(0,0.9)     #Задаём случайное число по красному цвету
    green = random.uniform(0,0.9)   #Задаём случайное число по зелёному цвету
    blue = random.uniform(0,0.9)    #Задаём случайное число по синему цвету
    
    randomMasElem = np.array([original() for i in range(count_element)])
    
    for i in range(count_element):
        
        x1+=randomMasElem[i]           #Задаём случайные значения по экспоненциальному закону
        
        MatOj = x1/(i+1)
        EN=math.log((MatOj-MU)**2,2)   #Расчитываем значения для графика квадрата ошибки в логарифмических координатах по основанию 2
        SredEN[i]+=(MatOj-MU)**2       #Складываем значения для усреднения графика квадрата ошибки
        np.MO.append(MatOj)
        np.eN.append(EN)
        
        #Решение пункта 9
        np.OcenkaVtorogoMomenta.append((sum((randomMasElem[:i]-MatOj)**k))/(i+1))    #Оценка второго центрального момента
        #Конец решения пункта 9
        
    line2.append(ax2.plot(np.eN,  color = [red,green,blue], lw=1))                      #График квадрата ошибки от объема выборки в логарифмических координатах
    line1.append(ax1.plot(np.MO,  color = [red,blue,green], lw=1))                      #График зависимости u оn N
    line3.append(ax3.plot(np.OcenkaVtorogoMomenta,  color = [blue,red,green], lw=1))    #График оценки к-ого(по заданию второго) центрального момента
    
for n in range(count_element):
    SredEN[n]=math.sqrt(SredEN[n]/100)                  #Усредняем значения практического графика
    if n!=0:
        top.append(MU+3*sigma/n)
        bot.append(MU-3*sigma/n)
        TeorSredEN.append(math.sqrt(dispers/(n+1)))     #Рассчитываем значения теоретического графика
        
line1.append(ax1.plot(top, color = 'black', lw = 3))    #Верхняя граничная линия
line1.append(ax1.plot(bot, color = 'black', lw = 3))    #Нижняя граничная линия 
        
line1.append(ax1.plot( Mu,  color = 'r', lw = 3))       #Истинное мат.ожидание
line3.append(ax3.plot( Mu,  color = 'r', lw = 3))       #Истинное мат.ожидание
    
line2.append(ax2.plot(SredEN, color = 'r', lw =3))      #Усредненный график полученный практически
line2.append(ax2.plot(TeorSredEN, color = 'b', lw =3))  #Усредненный график расчитанный теоретически
 
plt.show()

lictok.savefig('1.png', bbox_inches='tight')


