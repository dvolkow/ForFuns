#----функция считает разность между максимальным и минимальным элементами
def LAB4_VAR_13(list_): #--принимает на вход список целых
    return int(max(list_)) - int(min(list_))

#----получение списка из стандартного ввода
list_inp = input()
list_inp = list_inp.split(" ") #---преобразование строки - разбиение по пробелам

#---преобразование листа строк в лист целых
list_inp = list(map(int, list_inp))

print(LAB4_VAR_13(list_inp))