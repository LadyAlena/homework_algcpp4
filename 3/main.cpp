#include <iostream>
#include <sstream>
#include <string>

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

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int new_element) {
    if (logical_size < actual_size) {
        arr[logical_size] = new_element;
        logical_size++;
    } 
    else {
        int new_actual_size = actual_size * 2;
        int* new_arr = new int[new_actual_size];

        for (int i = 0; i < logical_size; ++i) {
            new_arr[i] = arr[i];
        }

        new_arr[logical_size] = new_element;
        logical_size++;
        actual_size = new_actual_size;

        delete[] arr;

        return new_arr;
    }
    return arr;
}

int* remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
    if (logical_size - 1 > actual_size / 3) {

        for (int i = 0; i < logical_size - 1; ++i) {
            arr[i] = arr[i + 1];
        }
        logical_size--;
    } else {

        int new_actual_size = actual_size / 3;
        int* new_arr = new int[new_actual_size];

        for (int i = 1; i < logical_size; ++i) {
            new_arr[i - 1] = arr[i];
        }

        logical_size--;
        actual_size = new_actual_size;

        delete[] arr;

        return new_arr;
    }
    return arr;
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


    while(true){
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
        while(true)  {
            std::cout << "Введите arr[" << i << "]: ";
            std::getline(std::cin, input_user);

            std::stringstream iss(input_user);

            if(!(iss >> arr[i] && iss.eof()))  {
                std::cout << "Некорректный ввод! Повторите попытку..." << std::endl;
            }
            else {
                break;
            }
        }
    }

    std::cout << "Динамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    while (logical_size > 0) {
        std::string answer{};
        std::cout << "Удалить первый элемент? (да/нет): ";
        std::getline(std::cin, answer);

        if (answer == "да") {
            arr = remove_dynamic_array_head(arr, logical_size, actual_size);
            std::cout << "Динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
        } 
        else if(answer == "нет") {
            std::cout << "Спасибо! Ваш динамический массив: ";
            print_dynamic_array(arr, logical_size, actual_size);
            break;
        }
        else {
            std::cout << "Некорректный ввод! Повторите попытку..." << std::endl;
        }
    }

    delete[] arr;
    return 0;
}