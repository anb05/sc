// WavRaw.cpp

#include "./WavRaw.hpp"

#include <iostream>
using namespace std;

using std::ifstream;
using std::ios;

// Конструкор умолчаний
WavRaw::WavRaw()
{
    itsContainer = new short[1];
    itsContainer[0] = 0;
    containerLength = 1;
}

// Конструктор создающий контейнер из WAV файла
WavRaw::WavRaw(string sourceName, unsigned int addres, unsigned int length)
{
    cout << " конструктор WavRaw" << endl;
    containerLength = length / sizeof(short);
    itsContainer = new short[containerLength];

    extractData(sourceName, addres, containerLength);
}

// Конструктор создающий контейнер из массива с отсчётами
// В качестве аргумента передается указатель на массив отсчётов амплитуд
WavRaw::WavRaw(const short* const ptrShortArray, const unsigned int & numOfElements)
{
    containerLength = numOfElements;
    itsContainer = new short[containerLength];
    for (unsigned int counter = 0; counter < containerLength; ++counter) {
        itsContainer[counter] = ptrShortArray[counter];
    }
}

// Конструктор копирования
WavRaw::WavRaw(const WavRaw & copyWavRaw)
{
    containerLength = copyWavRaw.containerLength;
    itsContainer = new short[containerLength];
    for (unsigned int counter = 0; counter < containerLength; ++counter) {
        itsContainer[counter] = copyWavRaw[counter];
    }
}

// Закрытый конструктор, создающий контейнер заданой длины
// с элементами, рвными 0
WavRaw::WavRaw(unsigned int requiredLength) :
    containerLength(requiredLength)
{
    itsContainer = new short[containerLength];
    for (unsigned int counter = 0; counter < containerLength; ++counter) {
        itsContainer[counter] = 0;
    }
}


// Деструкор
WavRaw::~WavRaw()
{
    delete [] itsContainer;
    containerLength = 0;
    cout << "destructor WavRaw" << endl;
}

/* Перегруженные операторы */

// Неконстантный оператор индексирования,
// возвращает ссылку на отсчёт, который можно изменить
short & WavRaw::operator[](int offset)
{
    if (offset < containerLength) {
        return itsContainer[offset];
    }
    return itsContainer[containerLength - 1];
}

// Константный оператор индексирования,
// используется для константных объктов (см. конструктор-копировщик)
short WavRaw::operator[](int offset) const
{
    if (offset < containerLength) {
        return itsContainer[offset];
    }
    return itsContainer[containerLength - 1];
}

// Оператор создаёт новый объект WavRaw в контейнере которого содержится
// объединенные отсчеты двух объектов WavRaw
WavRaw WavRaw::operator+ (const WavRaw & rhs)
{
    unsigned int totalLength = containerLength + rhs.containerLength;
    WavRaw tempContainer(totalLength);
    unsigned int counter = 0;
    unsigned int rhsCounter = 0;
    for (counter = 0; counter < containerLength; ++ counter) {
        tempContainer.itsContainer[counter] = itsContainer[counter];
    }
    for (rhsCounter = 0; rhsCounter < rhs.containerLength; ++rhsCounter, ++counter) {
        tempContainer.itsContainer[counter] = rhs[rhsCounter];
    }
    return tempContainer;
}

// К текущему контейнеру добаляет отсчеты из контейнера аргумента
void WavRaw::operator+= (const WavRaw & rhs)
{
    unsigned int totalLength = containerLength + rhs.containerLength;
    WavRaw tempContainer(totalLength);
    unsigned int counter = 0;
    unsigned int rhsCounter = 0;
    for (counter = 0; counter < containerLength; ++counter) {
        tempContainer[counter] = itsContainer[counter];
    }
    for (rhsCounter = 0; rhsCounter < rhs.containerLength; ++rhsCounter, ++counter) {
        tempContainer[counter] = rhs[rhsCounter];
    }
}

        // 
WavRaw & WavRaw::operator= (const WavRaw & rhs)
{
    if (this == &rhs) {
        return *this;
    }

    containerLength = rhs.containerLength;
    delete[] itsContainer;
    itsContainer = new short[containerLength];
    for (unsigned int counter = 0; counter < containerLength; ++ counter) {
        itsContainer[counter] = rhs[counter];
    }
    return *this;
}

void WavRaw::extractData(string sourceName, unsigned int addres, unsigned int length)
{
    cout << "WavRaw::sourceName = " << sourceName << endl;
    cout << "WavRaw::addres = " << addres << endl;
    unsigned int delta = 0;

    if (length > containerLength) {
        length = containerLength;
    }
    else {
        delta = containerLength - length;
    }
    cout << "WavRaw::length = " << length << endl;

    unsigned int counter = 0;
    ifstream inpFile;
    inpFile.open(sourceName, ios::in | ios::binary);
    if (inpFile.is_open()) {
        inpFile.seekg(addres);
        for (counter = 0; counter < length; ++ counter) {
            inpFile.read((char*)&itsContainer[counter], sizeof(short));
        }
    }
    inpFile.close();

    if (delta > 0) {
        for (; counter < containerLength; ++ counter) {
            itsContainer[counter] = 0;
        }
    }




    for (int i = containerLength - 10 ; i < containerLength; ++i) {
        cout << "itsContainer[" << i << "] = " << hex << itsContainer[i] << endl;
    }
}

//template <typename T>
//T* WavRaw<T>::readAllData(void) const
short* WavRaw::readAllData(void) const
{
    return itsContainer;
}

short& WavRaw::readChunk(unsigned int offset, unsigned int length)
{
    // ЗАГЛУШКА!!!!!!!!!!!!
    return *itsContainer;
}


