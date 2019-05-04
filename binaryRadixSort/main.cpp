#include <iostream>
#include <vector>
#include <math.h>
#include <time.h>

int *intToBinary(int number) {
    int k = 7; // iterator
    int *binary = new int[8];
    for (int i = 0; i <= 7; i++) {
        if (number >= pow(2, k)) {
            binary[i] = 1;
            number -= pow(2, k);
        } else {
            binary[i] = 0;
        }
        k--;
    }

    return binary;
}

int binaryToInt(int *bitArr, int size) {
    int k = size - 1; //exponent
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += bitArr[i] * pow(2, k);
        k--;
    }
    return result;
}

void swap(int* a, int* b) {
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

std::vector<int*> countingSort(std::vector<int *> &vec, int *array, int size, int maxVal) {
    int *arrayCopyC = new int[maxVal + 1]{};
    std::vector<int*> res(size, 0);
    for (int i = 0; i < size; i++) {
        arrayCopyC[array[i]] += 1;
    }

    for (int i = 1; i < maxVal + 1; i++) {
        arrayCopyC[i] += arrayCopyC[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        //res[arrayCopyC[array[i]] - 1] = array[i];

        res[arrayCopyC[array[i]] - 1] = vec[i];

        arrayCopyC[array[i]]--;
    }
    delete arrayCopyC;
    return res;

}

int main() {
    int number, N;
    int max = 0;
    std::cout << "Enter the number of numbers to sort: ";
    while (!(std::cin >> N)) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "Invalid input.";
    }
    std::vector<unsigned char> intVec;
    std::vector<int *> bitVec;
    srand(time(nullptr));
    for (int i = 0; i < N; i++) {

        number = rand() % 256;

        if (number > max) {
            max = number;
        }

        bitVec.push_back(intToBinary(number));

        //PRINT NUMBERS IN BINARY AND NORMAL
        for(int j = 0; j<8;j++){
            std::cout << bitVec[i][j];
        }
        std::cout << ' ' << number << '\n';

    }
    std::cout << std::endl;

    for (int j = 7; j >= 0; j--) {
        int *tmp = new int[bitVec.size()]{};

        for (int i = 0; i < bitVec.size(); i++) {
            tmp[i] = bitVec[i][j];
        }

        bitVec = countingSort(bitVec, tmp, bitVec.size(), max);

        delete tmp;
    }

    for (int i = 0; i < bitVec.size(); i++) {
        intVec.push_back(binaryToInt(bitVec[i], 8));
        std::cout << std::to_string(intVec[i]) << ' ';
    }
    std::cout << std::endl;
    return 0;
}