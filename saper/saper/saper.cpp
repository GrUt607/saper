#include <iostream>
#include <windows.h>

using namespace std;

void gotoxy(int x, int y)
{
    COORD p = { x,y };  // Установка позиции курсора в консоли по координатам (x, y)
    SetConsoleCursorPosition(GetStdHandle(STD_INPUT_HANDLE), p);  // Функция установки позиции курсора
}

class Map {
private:
    int size;  // Размер карты
public:
    Map() {
        size = 15;  // Инициализация размера карты
    }
    void show() {
        for (int i = 0; i < size; i++) {  // Перебор строк карты
            for (int j = 0; j < size; j++) {  // Перебор столбцов карты
                if (i == 0 || j == 0 || i == size - 1 || j == size - 1)
                    cout << "$";  // Вывод символа "$" для границ карты
                else
                    cout << " ";  // Вывод пробела для внутренних клеток карты
            }
            cout << endl;  // Переход на новую строку после отображения строки карты
        }
    }
};

class Game {
private:
    void showLogo() {
        gotoxy(60, 10);  // Установка позиции вывода логотипа
        cout << "Saper" << endl;  // Вывод логотипа
        Sleep(2000);  // Задержка 2 секунды
        system("cls");  // Очистка экрана консоли
    }
public:
    void run() {
        showLogo();  // Показать логотип
        Map map;  // Создание объекта карты
        map.show();  // Отображение карты
    }
};

int main()
{
    Game game;  // Создание объекта игры
    game.run();  // Запуск игры
}