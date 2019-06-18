//
// Created by Elisey on 05/06/2019.
//

#include <stdexcept>
#include <cmath>
#include "bitstream.h"

void bitstream::write(const int c, const int len) {
    if(std::pow(2, len) < sizeof(int)) throw std::invalid_argument(std::to_string(len));
    for(int i = len-1; i >= 0; i--){
        this->stream.push((c >> i) & 0x1);
    }
}

/*void bitstream::write(const std::string c, const int len) {
    if(len < (sizeof(c)*len/sizeof(c[0]))) throw std::invalid_argument((char*)len);
    for(const char &ch : c){
        for(int i = len-1; i >= 0; i--){
            this->stream.push((ch >> i) & 0x1);
        }
    }

}*/

int bitstream::read(int len) {
    int bitC = 0;
    for(int j = 0; j < len; j++){
        bitC <<= true;
        bitC |= this->stream.front();
        this->stream.pop();
    }
    return bitC;
}
/*
 * Completes the stream to 8k bits
 */
void bitstream::complete() {
    int bQs = 8-(this->size()%8);
    for (unsigned int j = 0; j < bQs; j++) {
        this->stream.push(false);
    }
}
