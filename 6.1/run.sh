#!/bin/bash

# Имя исполняемого файла
EXECUTABLE=hash_table_program

# Компиляция программы
g++ -o $EXECUTABLE main.cpp hash_table.cpp

# Проверка успешности компиляции
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Запуск программы
    ./$EXECUTABLE
else
    echo "Compilation failed."
fi