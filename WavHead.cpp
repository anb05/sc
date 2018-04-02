#include "./WavHead.hpp"
#include <fstream>

using std::ifstream;
using std::ios;

WavHead::WavHead() {}
WavHead::~WavHead() {}

void WavHead::setHeadData(string fileName)
{
    ifstream isf;
    isf.open(fileName, ios::in | ios::binary);
    if (isf.is_open()) {
        cout << "The file " << fileName << " is opend" << endl;
        // считываем chunkId = RIFF
        isf.read(chunkId, sizeof(chunkId));

        // считываем chunkSize = fileSize - 8 байт
        isf.read((char*)&chunkSize, sizeof(chunkSize));

        // считываем forman = WAVE
        isf.read(format, sizeof(format));

        // считываем признак WAVE формата = "fmt "
        isf.read(subchunk1Id, sizeof(subchunk1Id));

        // считываем разрядность квантования subchunk1Size
        isf.read((char*)&subchunk1Size, sizeof(subchunk1Size));

        // считываем формат сжатия
        isf.read((char*)&audioFormat, sizeof(audioFormat));

        // считываем формат сжатия
        isf.read((char*)&numChannels, sizeof(numChannels));

        // Частота дискретизации
        isf.read((char*)&sampleRate, sizeof(sampleRate));

        // Количество байт, переданных за секунду воспроизведения
        isf.read((char*)&byteRate, sizeof(byteRate));

        // Количество байт для одного сэмпла, включая все каналы
        isf.read((char*)&blockAlign, sizeof(blockAlign));

        // Количество бит в сэмпле
        isf.read((char*)&bitsPerSample, sizeof(bitsPerSample));

        // Содержит символы “data” 
        isf.read(subchunk2Id, sizeof(subchunk2Id));

        // Количество байт в области данных.
        isf.read((char*)&subchunk2Size, sizeof(subchunk2Size));

    }
    else {
        cout << "прозже написать свое исключение" << endl;
    }

    isf.close();
}

string WavHead::getSourceType(void)
{
    cout << "sizeof(chunkId) = " << sizeof(chunkId) << endl;
    int i = 0;
    int countSize = sizeof(chunkId);

    cout << "chunkId = ";
    for (i = 0; i < countSize; ++i) {
        cout << chunkId[i];
    }
    cout << endl;

    cout << "chunkSize = " << chunkSize << endl;

    countSize = sizeof(format);
    cout << "format = ";
    for (i = 0; i < countSize; ++i) {
        cout << format[i];
    }
    cout << endl;

    countSize = sizeof(subchunk1Id);
    for (i = 0; i < countSize; ++i) {
        cout << subchunk1Id[i];
    }
    cout << endl;

    cout << "Size of PCM = " << subchunk1Size << endl;

    cout << "Audio Format = " << audioFormat << endl;

    cout << "Numbers of chanels = " << numChannels << endl;

    cout << "частота дискретизации = " << sampleRate << endl;

    cout << "Количество байт за секунду воспроизведения = " << byteRate << endl;

    cout << "Количество байт для одного сэмпла, включая все каналы = " << blockAlign << endl;

    cout << "Количество бит в сэмпле = " << bitsPerSample << endl;

    countSize = sizeof(subchunk2Id);
    cout << "символы “data” = ";
    for (i = 0; i < countSize; ++i) {
        cout << subchunk2Id[i];
    }
    cout << endl;

    cout << "Количество байт в области данных = "<< subchunk2Size << endl;

    return "WAVE";
}


