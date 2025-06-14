## README (English)

### HR Management System (C++)

This is a simple console-based HR (Human Resources) management system implemented in C++. The program allows basic operations with a list of employees, including adding new employees, removing them (via a soft delete), and viewing the current staff.

### Features

- Adding new employees
- Marking employees as "not working" instead of full deletion
- Displaying all active employees
- Manual memory management and dynamic array resizing
- Basic object-oriented structure using classes

### How it works

- At startup, the program asks for the number of current employees and collects their information.
- The user is then presented with a menu:
  1. Show all active employees  
  2. Delete employee by name  
  3. Add a new employee  
  4. Exit

- When an employee is "deleted", their slot can be reused when adding a new one.
- The array of employees resizes dynamically if needed.

### Requirements

- C++11 or newer
- Console environment (Windows preferred due to use of `system("cls")`)

### Build instructions

Compile using any C++ compiler that supports C++11 or later. For example:

```bash
g++ -std=c++11 hr_system.cpp -o hr_system
./hr_system
```

On Windows:

```bash
g++ -std=c++11 hr_system.cpp -o hr_system.exe
hr_system.exe
```

### Notes

- This program does not use persistent storage — all data is kept in memory and lost after the program ends.
- The console-clearing command (`system("cls")`) is Windows-specific. On Linux or macOS, replace with `system("clear")`.
- The code is intended for educational or demo purposes.

---

## README (на русском)

### Система управления персоналом на C++

Простая консольная программа для учета сотрудников компании. Реализована на C++ с использованием классов и ручного управления памятью.

### Возможности

- Добавление новых сотрудников
- Удаление сотрудников (пометка как "неработающий", а не полное удаление)
- Просмотр всех активных сотрудников
- Динамическое расширение массива при необходимости

### Как работает

- При запуске программа спрашивает количество сотрудников и запрашивает их данные.
- Затем выводится меню:
  1. Показать всех сотрудников  
  2. Удалить сотрудника по имени  
  3. Добавить нового сотрудника  
  4. Выйти из программы

- При удалении сотрудник просто помечается как неактивный.
- Если при добавлении есть освободившееся место — оно будет переиспользовано. В противном случае — массив расширяется.

### Требования

- Компилятор с поддержкой C++11 или выше
- Консольная среда (предпочтительно Windows из-за использования `system("cls")`)

### Сборка

Пример компиляции:

```bash
g++ -std=c++11 hr_system.cpp -o hr_system
./hr_system
```

Для Windows:

```bash
g++ -std=c++11 hr_system.cpp -o hr_system.exe
hr_system.exe
```

### Примечания

- Данные не сохраняются между сессиями. Это полностью оперативная система учёта.
- Команда очистки экрана (`system("cls")`) работает только в Windows. На других ОС нужно заменить на `system("clear")`.
- Программа создана в учебных целях или как демо-проект.
