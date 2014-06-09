#include <iostream>
#include <string>
#include <vector>

int number(int x) { // вспомогательная функция отбеливания
    x+=256;
    while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) { // подбираем код символа 0-9, a-z, A-Z
        if (x < 48) {x+=24;} else {x-=47;}    
    }
    return x;
}

std::string ruhash(std::vector<char> v) { // алгоритм хеширования
    
    int len = v.size();    
    int min = 64; // минимальный блок
    while (min < len) min*=2; // блок должен быть 64, 128, 256, 512 бит и т.д.
    if ((min - len) < 64) min*=2; // если количество информации, которое требуется дописать меньше 64, то будем дописывать больше
    int add = min-len; // количество информации, которую нужно добавить

    int salt = 0; // соль на основе суммы кодов всех символов и длины
    for (int i = 0; i < v.size(); ++i) salt+=v[i]; // собираем из кодов всех символов соль 
    salt = number(salt-len); // добавляем в соль длину
    for (int i = 1; i <= add; ++i) v.push_back(number(i*salt*v[i])); // дописываем информацию на основе соли, счетчика и входной строки, отбеливаем ее
    
        
    std::vector<int> prev; // выходной вектор
    for (int i = 0; i < v.size(); ++i) prev.push_back(v[i]); // переписываем коды символов в выходной вектор
    std::vector<int> now; // промежуточный вектор
    
    while (prev.size() != 32) { // пока размер вектора не станет 32, будем его сокращать
        for (int j = 0; j < prev.size(); j+=2) {
            int t = prev[j] + prev[j+1]; // складываем пары чисел в одно, тем самым уменьшая размер последовательности в 2 раза
            now.push_back(t);
        }
        prev = now; // промежуточный блок переписываем в выходной вектор
        now.clear();
    }
    std::vector<char> f; // конечный хеш
    for (int i = 0; i < prev.size(); ++i) {
        f.push_back(number(prev[i]+i*i)); // отбеливаем полученный вектор
    }
    
    std::string hash; // строка для результата
    for (int i = 0; i < f.size(); ++i) {
        hash+=f[i];   
    }
    return hash;
}
