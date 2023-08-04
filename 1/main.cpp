#include <iostream>
#include <sstream>

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
    for (int i = 0; i < actual_size; ++i) {
        if (i < logical_size) {
            std::cout << arr[i] << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int actual_size{};
    int logical_size{};

    std::string input_user{};

    while(true) {
        std::cout << "Введите фактический размер массива: ";
        std::getline(std::cin, input_user);

        std::stringstream iss(input_user);

        if(!(iss >> actual_size && iss.eof())) {
            std::cout << "Некорректный ввод! Повторите попытку..." << std::endl;
        }
        else {
            break;
        }
    }

    while(true) {
        std::cout << "Введите логический размер массива: ";
        std::getline(std::cin, input_user);

        std::stringstream iss(input_user);

        if(!(iss >> logical_size && iss.eof())) {
            std::cout << "Некорректный ввод! Повторите попытку..." << std::endl;
        }
        else {
            break;
        }
    }

    if (logical_size > actual_size) {
        std::cout << "Ошибка! Логический размер массива не может превышать фактический!" << std::endl;
        return 1;
    }

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; ++i) {
        while(true) {
            std::cout << "Введите arr[" << i << "]: ";
            std::getline(std::cin, input_user);

            std::stringstream iss(input_user);

            if(!(iss >> arr[i] && iss.eof())) {
                std::cout << "Некорректный ввод! Повторите попытку..." << std::endl;
            }
            else {
                break;
            }
        }
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
    return 0;
}