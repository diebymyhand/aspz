# Завдання по варіантах
# 5 варіант

Test Case #1: реалізуйте і відловіть доступ до неініціалізованої змінної (наприклад, локальної int).

![](https://github.com/diebymyhand/aspz/blob/main/Practice6/1.png)

![](https://github.com/diebymyhand/aspz/blob/main/Practice6/2.png)

У коді програми без інізціалізації створено змінну x типу int. 
Без ініціалізації значення змінної є випадковим, і програма може вивести будь-яке значення. Це створює потенційну проблему, оскільки ми не можемо передбачити, яке значення буде виведене.
За допомогою Valgrind ми відловили помилку. Він виводить повідомлення про використання неініціалізованої змінної, вказуючи, де саме сталася помилка, і як саме програма зверталася до цієї пам'яті.
