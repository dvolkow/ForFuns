#--функция считает, сколько раз меняется знак в последовательности ненулевых чисел
def LAB5_VAR_9(list_):
    i = 1 #---здесь храним индекс элемента
    count = 0 #--здесь храним счетчик смен знака
    while i < len(list_):
        if (list_[i] > 0 and list_[i - 1] < 0) or (list_[i] < 0 and list_[i - 1] > 0):
            count = count + 1
        i = i + 1
    return count


#----получение списка из стандартного ввода
list_inp = input()
list_inp = list_inp.split(" ") #---преобразование строки - разбиение по пробелам
#---преобразование листа строк в лист целых
list_inp = list(map(int, list_inp))

print(LAB5_VAR_9(list_inp))
    
