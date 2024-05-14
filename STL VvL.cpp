#include <iostream>
#include <chrono>
#include <vector>
#include <list>

int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<int> vec;
    std::list<int> list;

    for (int i = 0; i < 200000; ++i) {
        vec.push_back(i);
        list.push_back(i);
    }

    std::cout << "Размер вектора: " << sizeof(vec) + (vec.size() * sizeof(int)) << " байт\n";
    std::cout << "Размер списка: " << sizeof(list) + (list.size() * sizeof(int)) << " байт\n";

    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    auto start_vec = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin(), 8);
    auto end_vec = std::chrono::high_resolution_clock::now();

    auto start_list = std::chrono::high_resolution_clock::now();
    auto iter{ list.begin() };
    list.insert(iter, 8);
    auto end_list = std::chrono::high_resolution_clock::now();

    auto duration_vector = std::chrono::duration_cast<std::chrono::microseconds>(end_vec - start_vec).count();
    auto duration_list = std::chrono::duration_cast<std::chrono::microseconds>(end_list - start_list).count();

    std::cout << "Время вставки в вектор: " << duration_vector << " мкс\n";
    std::cout << "Время вставки в список: " << duration_list << " мкс\n";
}
