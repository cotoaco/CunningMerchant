#include <iostream>
#include <limits>
#include "logic.h"
#include "checker.h"
int getValidInput(const std::string& prompt, int minVal){
    int value;
    std::cout << prompt;
    if(!(std::cin >> value)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw InvalidInput("Введено не число.");
    }
    if(value < minVal) {
        throw InvalidInput("Значение не может быть меньше " + std::to_string(minVal) + ".");
    }
    return value;
}
void runSimulation() {
    try {
        std::cout << "\n Начало \n";
        int n = getValidInput("Введите количество тюков (N): ", 1);
        int m = getValidInput("Введите текущее число месяца (M): ", 1);
        if (m > 31) {
            throw InvalidInput("Число месяца не может быть больше 31.");
        }
        int k = getValidInput("Введите шаг (K): ", 0);
        MerchantSolver solver(n, m, k);
        std::cout << "\n Ответ \n";
        std::cout << solver.solve();
    } catch (const InvalidInput& e) {
        std::cerr << "\n Ошибка. " << e.what() << " Попробуйте снова.\n";
    }
}
void showMenu() {
    std::cout << "\n---Меню---\n";
    std::cout << "1. Запустить расчет задачи\n";
    std::cout << "2. Показать условие задачи\n";
    std::cout << "3. Выйти из программы\n";
    std::cout << "Выберите пункт меню: ";
}
void showTaskDescrip() {
    std::cout << "\n--- Условие задачи ---\n"
              << "Два купца везут по N одинаковых тюков. Корабль тонет.\n"
              << "Нужно выбросить половину (N штук), считая по кругу по часовой стрелке,\n"
              << "начиная с M-го тюка, вычеркивая каждого (K+1)-го.\n"
              << "Программа рассчитывает схему расстановки, чтобы спасти груз первого купца.\n";
}
int main(){
    int choice = 0;
    while (true) {
        showMenu();
        if(!(std::cin >> choice)){
            std::cout << "\nНекорретный ввод. Попробуйте еще раз.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        switch (choice)
        {
        case 1:
            runSimulation();
            break;
        case 2:
            showTaskDescrip();
            break;
        case 3:
            std::cout << "\nПрограмма завершена.\n";
            return 0;
        default:
            std::cout << "\nТакого пункта нет.\n";
            break;
        }
    }
    return 0;
}