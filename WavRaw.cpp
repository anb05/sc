// WavRaw.cpp

#include "./WavRaw.hpp"

#include <iostream>
using namespace std;

using std::ifstream;
using std::ios;

//template <typename T>
//WavRaw<T>::WavRaw()
WavRaw::WavRaw()
{
    //itsContainer = new T;
    itsContainer = new char;
    itsContainer = 0;
    containerLength = 1;
}

//template <typename T>
//WavRaw<T>::WavRaw(string sourceName, unsigned int addres, unsigned int length)
WavRaw::WavRaw(string sourceName, unsigned int addres, unsigned int length)
{
    containerLength = length;
    //itsContainer = new T[containerLength/sizeof(T)];
    itsContainer = new char[containerLength];
    extractData(sourceName, addres, containerLength);
}


//template <typename T>
WavRaw::~WavRaw()
{
    delete [] itsContainer;
    containerLength = 0;
}

//template <typename T>
//void WavRaw<T>::extractData(string sourceName, unsigned int addres, unsigned int length)
void WavRaw::extractData(string sourceName, unsigned int addres, unsigned int length)
{
    ifstream inpFile;
    inpFile.open(sourceName, ios::in | ios::binary);
    if (inpFile.is_open()) {
        inpFile.seekg(addres);
        inpFile.read(itsContainer, length);
    }
    inpFile.close();
    for (int i =0; i < 10; ++i) {
        cout << "itsContainer[" << i << "] = " << dec << (int)itsContainer[i] << endl;
    }
}

//template <typename T>
//T* WavRaw<T>::readAllData(void) const
char* WavRaw::readAllData(void) const
{
    return itsContainer;
}

char* WavRaw::readChunk(unsigned int offset, unsigned int length)
{
    // ЗАГЛУШКА!!!!!!!!!!!!
    return itsContainer;
}


