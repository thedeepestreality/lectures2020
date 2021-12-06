В следующих задачах можно использовать STL.

**Задача 1)** Реализовать класс **RationalFraction (рациональная дробь)** для хранения дробей с целыми числителем и знаменателем. Перегрузить операторы арифметических операций, вывод в поток, преобразования к типу **int**. Реализовать методы ceil() и round() для округления дробей до целого числа. Реализовать конструктор от **double** с заданной точностью.

**Задача 2)** Реализовать функцию, проверяющую валидность строки, составленной из круглых скобок (использовать стек).

Пример: "(()())" -- валидно.

Пример: "(()()" -- невалидно

Пример: ")(" -- невалидно.

**Задача 3)** Реализовать функцию, проверяющую валидность строки, составленной из круглых, квадратных и фигурных скобок (использовать стек).

Пример: "{[()]({}){[]}}" -- валидно.

Пример: "([)]" -- невалидно

**Задача 4)** Реализовать метод обхода бинарного дерева в ширину (использовать очередь).

**Задача 5)** Написать функцию для нахождения индексов пары элементов массива целых чисел, сумма которых равна заданному целому числу. Считаем, что решение всегда есть и оно единственно. Размер массива от 2 до 10^3 элементов. Элменты из диапазона [-10^9;10^9].

Пример: [2,7,11,15], target = 9
Output: [0,1]

**Задача 6)** Добавить в программу-словарь обработку аргументов командной строки:

* Найти перевод слова word в словаре dictionary-ru.txt, вывести в консоль:

```
> dictionary.exe dictionary-ru.txt 1 word
```

* Вывести словарь из файла dictionary-ru.txt в файл out.txt, отсортированный по английским словам:

```
> dictionary.exe dictionary-ru.txt 2 out.txt
```

* Вывести словарь из файла dictionary-ru.txt в файл out.txt, отсортированный по русским словам:

```
> dictionary.exe dictionary-ru.txt 3 out.txt
```

* Вывести слова из словаря dictionary-ru.txt, начинающиеся на букву letter, в файл out.txt, отсортировав по английским словам:

```
> dictionary.exe dictionary-ru.txt 4 out.txt letter
```