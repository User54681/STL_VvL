#include <iostream>
#include <chrono>
#include <vector>
#include <list>

int main()
{
    setlocale(LC_ALL, "Rus");
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int> list{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    auto start_vec = std::chrono::high_resolution_clock::now();
    vec.insert(vec.begin() + vec.size() / 2, 8);
    auto end_vec = std::chrono::high_resolution_clock::now();

    auto start_list = std::chrono::high_resolution_clock::now();
    auto iter{ list.begin() };
    std::advance(iter, list.size() / 2); 
    list.insert(iter, 8);
    auto end_list = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double, std::milli> vec_time = end_vec - start_vec;
    std::chrono::duration<double, std::milli> lst_time = end_list - start_list;

    std::cout << "Время вставки в середину вектора: " << vec_time.count() << " мс\n";
    std::cout << "Время вставки в середину списока: " << lst_time.count() << " мс\n";
}
