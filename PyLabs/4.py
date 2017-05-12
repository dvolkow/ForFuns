#----функция считает разность между максимальным и минимальным элементами
def range_(list_):
    a = int(min(list_))
    b = int(max(list_))
    return b - a

list_inp = input()
list_inp = list_inp.split(" ")

#---преобразование листа строк в лист целых
list_inp = list(map(int, list_inp))

print(range_(list_inp))