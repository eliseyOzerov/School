//
// Created by Elisey on 05/06/2019.
//

#ifndef LZW_BITSTREAM_H
#define LZW_BITSTREAM_H
#include <queue>

class bitstream {
private:
    std::queue<bool> stream;
public:
    int size(){return this->stream.size();}
    void write(int c, int len);
    //void write(const std::string c, int len);
    int read(int len);
    void complete();
};


#endif //LZW_BITSTREAM_H
