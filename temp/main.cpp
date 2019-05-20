#include <ctime>
#include <iostream>
int main(void) {
    time_t rawtime;
    struct tm * timeinfo;

    time (&rawtime);
    timeinfo = localtime (&rawtime);

    std::cout << "rawtime = " << rawtime << "\n";
    std::cout << "Welcome to " << 1900 + timeinfo->tm_year << "\n";
}