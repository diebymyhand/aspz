# Завдання по варіантах
# Варіант 5

Реалізуйте фрагмент програми з подвійним звільненням пам’яті, який не завжди викликає помилку при виконанні.

![](https://github.com/diebymyhand/aspz/blob/main/Practice5/1.png)

У коді програми спочатку виділяється пам'ять для двох змінних x і y за допомогою malloc. Потім пам'ять для x та y звільняється за допомогою free(x) і free(y). Після цього пам'ять для x знову виділяється за допомогою malloc.
Потім програма намагається знову викликати free(y), хоча пам'ять для y вже була звільнена.
Не зважаючи на те, що зазвичай при подвійному звільненні пам'яті програма робить аварійне завершення (segmentation fault), у даному випадку програма не завершується аварійно, а виводить "Hello world" на екран.
Тим не менш подвійне звільнення порушує цілісність роботи програми.
