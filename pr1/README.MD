# Завдання 1.5

Умова: Уявіть, що ваша програма на C складається з кількох окремих файлів, і вони використовують заголовкові файли, як показано нижче:
- main.c - stdio.h, process1.h  
- input.c - stdio.h, list.h  
- output.c - stdio.h  
- process1.c - stdio.h, process1.h  
- process2.c - stdio.h, list.h

Які файли потрібно перекомпілювати після внесення змін до process1.c?
Які файли потрібно перекомпілювати після внесення змін до process1.h?
Які файли потрібно перекомпілювати після внесення змін до list.h?

Додайте ще один файл (utility.c) із залежністю від process1.h та stdio.h.

---

## Додайте ще один файл (utility.c) із залежністю від process1.h та stdio.h.

Маємо:
- main.c - stdio.h, process1.h  
- input.c - stdio.h, list.h  
- output.c - stdio.h  
- process1.c - stdio.h, process1.h  
- process2.c - stdio.h, list.h
- utility.c - process1.h, stdio.h

### Компіляція коду
```
gcc -Wall -c main.c -o main.o
gcc -Wall -c input.c -o input.o
gcc -Wall -c output.c -o output.o
gcc -Wall -c process1.c -o process1.o
gcc -Wall -c process2.c -o process2.o
gcc -Wall -c utility.c -o utility.o
```
```
gcc main.o input.o output.o process1.o process2.o utility.o -o task1.5
```

---

## Які файли потрібно перекомпілювати після внесення змін до `process1.c`?

Після внесення змін до `process1.c` потрібно перекомпілювати лише сам файл `process1.c`, через те, що це реалізаційний файл, який не впливає напряму на інші `.c` файли.

---

## Які файли потрібно перекомпілювати після внесення змін до `process1.h`?

Після зміни `process1.h` потрібно перекомпілювати усі файли, які його використовують, а саме:
- main.c 
- process1.c
- utility.c 

---

## Які файли потрібно перекомпілювати після внесення змін до `list.h`?

Після зміни `list.h` потрібно перекомпілювати усі файли, які його використовують, а саме:
- input.c
- process2.c

