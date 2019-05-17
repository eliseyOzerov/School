#include <iostream>
#include <list>
#include "templates.h"
#include <vector>
#include <exception>
/*
 * http://www.cplusplus.com/doc/oldtutorial/templates/
 * https://en.cppreference.com/w/cpp/language/function_template
 * https://www.programiz.com/cpp-programming/templates
 */
int main() {
    std::vector<int> vecI = { 100, 35, 7, 21, 89, 10, 148, 983, 33, 29 };
    std::vector<Date> vecDate = {Date(10, 1, 2010), Date(13, 3, 2011), Date(12, 3, 2011)};
    std::string s = "12345";
    std::string s2 = "123456";
    printVector<int>(vecI);
    bubbleSort<int, 0>(vecI);
    printVector(vecI);
    printVector<Date>(vecDate);
    std::cout << isAfter(vecDate[1], vecDate[2]) << '\n';
    std::cout << isAfter(s, s2) << '\n';

    return 0;
}