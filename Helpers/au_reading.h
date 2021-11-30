#ifndef AU_READING_H
#define AU_READING_H

//32 bit word (unsigned) 	field 	Description/Content Hexadecimal numbers in C notation
//0 	                    magic number 	the value 0x2e736e64 (four ASCII characters ".snd")
//1 	                    data offset 	the offset to the data in bytes, must be divisible by 8. The minimum valid number is 24 (decimal), since this is the header length (six 32-bit words) with no space reserved for extra information (the annotation field). The minimum valid number with an annotation field present is 32 (decimal).
//2 	                    data size 	data size in bytes. If unknown, the value 0xffffffff should be used.
//3 	                    encoding 	Data encoding format:
//
//1 = 8-bit G.711 μ-law
//2 = 8-bit linear PCM
//3 = 16-bit linear PCM
//4 = 24-bit linear PCM
//5 = 32-bit linear PCM
//6 = 32-bit IEEE floating point
//7 = 64-bit IEEE floating point
//8 = Fragmented sample data
//9 = DSP program
//10 = 8-bit fixed point
//11 = 16-bit fixed point
//12 = 24-bit fixed point
//13 = 32-bit fixed point
//18 = 16-bit linear with emphasis
//19 = 16-bit linear compressed
//20 = 16-bit linear with emphasis and compression
//21 = Music kit DSP commands
//23 = 4-bit compressed using the ITU-T G.721 ADPCM voice data encoding scheme
//24 = ITU-T G.722 SB-ADPCM
//25 = ITU-T G.723 3-bit ADPCM
//26 = ITU-T G.723 5-bit ADPCM
//27 = 8-bit G.711 A-law
//
//4 	sample rate 	the number of samples/second, e.g., 8000
//5 	channels 	the number of interleaved channels, e.g., 1 for mono, 2 for stereo; more channels possible, but may not be supported by all readers.
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <filesystem>
#include <vector>
#include "globals.h"

typedef uint32_t U32;

struct Wave_header {
    U32  magic_num;
    U32  offset;
    U32 data_size;
    

};

DataVector readAuFile(const std::string fileName) {
    FILE *fin = fopen(fileName.c_str(), "rb");
    std::ifstream myFile(fileName);
    DataVector data;
    myFile.seekg(24); // zap first 6 uint32 headers
    U32  magic_num;
    myFile.read(reinterpret_cast<char *>(&magic_num), sizeof(U32));
    U32  offset;
    myFile.read(reinterpret_cast<char *>(&offset), sizeof(U32));
    U32 data_size;
    myFile.read(reinterpret_cast<char *>(&data_size), sizeof(U32));
    std::cout << "data size"<<data_size << std::endl;
    myFile.seekg(12); // zap first 3 uint32 headers
    uint8_t lower_bits;
    uint8_t higher_bits;
    for (std::size_t k = 0; k < data_size / 2; k++) {
        myFile.read(reinterpret_cast<char *>(&higher_bits), sizeof(uint8_t));
        myFile.read(reinterpret_cast<char *>(&lower_bits), sizeof(uint8_t));
        data.push_back(static_cast<real>((signed short) ((higher_bits << 8) + lower_bits)));
    }
    myFile.close();
    fclose(fin);
    return data;
}





#endif //AU_READING_H
