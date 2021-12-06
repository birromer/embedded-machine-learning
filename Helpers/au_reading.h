#ifndef AU_READING_H
#define AU_READING_H

//32 bit word (unsigned)    field   Description/Content Hexadecimal numbers in C notation
//0                         magic number    the value 0x2e736e64 (four ASCII characters ".snd")
//1                         data offset     the offset to the data in bytes, must be divisible by 8. The minimum valid number is 24 (decimal), since this is the header length (six 32-bit words) with no space reserved for extra information (the annotation field). The minimum valid number with an annotation field present is 32 (decimal).
//2                         data size   data size in bytes. If unknown, the value 0xffffffff should be used.
//3                         encoding    Data encoding format:
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
//4     sample rate     the number of samples/second, e.g., 8000
//5     channels    the number of interleaved channels, e.g., 1 for mono, 2 for stereo; more channels possible, but may not be supported by all readers.
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <string>
#include <filesystem>
#include <vector>
#include "globals.h"

typedef uint32_t U32;
typedef uint16_t U16;

DataVector readAuFile(const std::string fileName) {
    FILE *fin = fopen(fileName.c_str(), "rb");
    std::ifstream myFile(fileName);
    DataVector data;
    //reading magic number
    U32 magic_num;
    U32 swapped;
    myFile.read(reinterpret_cast<char *>(&magic_num), sizeof(uint32_t));
    swapped = ((magic_num>>24)&0xff) | // move byte 3 to byte 0
                    ((magic_num<<8)&0xff0000) | // move byte 1 to byte 2
                    ((magic_num>>8)&0xff00) | // move byte 2 to byte 1
                    ((magic_num<<24)&0xff000000); // byte 0 to byte 3
    //check magic number
    if (swapped != 0x2e736e64)
        throw std::runtime_error("Wrong magic number.");

    //reading offset
    U32  offset;
    myFile.read(reinterpret_cast<char *>(&offset), sizeof(U32));

    //reading data_size
    U32 data_size;
    U32 data_size_swapped;
    myFile.read(reinterpret_cast<char *>(&data_size), sizeof(U32));
    data_size_swapped = ((data_size>>24)&0xff) | // move byte 3 to byte 0
                    ((data_size<<8)&0xff0000) | // move byte 1 to byte 2
                    ((data_size>>8)&0xff00) | // move byte 2 to byte 1
                    ((data_size<<24)&0xff000000); // byte 0 to byte 3
    std::cout << "Data size: " << data_size_swapped << std::endl;

    //reading encoding
    U32 enc;
    U32 swapped_enc;
    myFile.read(reinterpret_cast<char *>(&enc), sizeof(uint32_t));
    swapped_enc = ((enc>>24)&0xff) | // move byte 3 to byte 0
                    ((enc<<8)&0xff0000) | // move byte 1 to byte 2
                    ((enc>>8)&0xff00) | // move byte 2 to byte 1
                    ((enc<<24)&0xff000000); // byte 0 to byte 3
    std::cout <<"encodage: "<< swapped_enc<< std::endl;

    //reading two more header words
    myFile.seekg(sizeof(U32)*6); // zap first 3 uint32 headers

    //reading data
    int16_t word;
    int16_t word_swapped;
    for (std::size_t k = 0; k <= data_size_swapped/2; k++) {
        myFile.read(reinterpret_cast<char *>(&word), sizeof(uint16_t)); //in the case where data are encoding with 16 bits, but not sure
        word_swapped = ((word>>8)&0x00ff) | // move byte 3 to byte 0
                       ((word<<8)&0xff00); // byte 0 to byte 3
        data.push_back(word_swapped);
    }

    myFile.close();
    fclose(fin);
    std::cout<<"Reading data finished!!!"<< std::endl;
    return data;
}

#endif //AU_READING_H
