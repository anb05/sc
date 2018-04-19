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
    itsContainer = new short[1];
    itsContainer[0] = 0;
    containerLength = 1;
}

//template <typename T>
//WavRaw<T>::WavRaw(string sourceName, unsigned int addres, unsigned int length)
WavRaw::WavRaw(string sourceName, unsigned int addres, unsigned int length)
{
    cout << " конструктор WavRaw" << endl;
    extractData(sourceName, addres, length);
}


//template <typename T>
WavRaw::~WavRaw()
{
    delete [] itsContainer;
    containerLength = 0;
    cout << "destructor WavRaw" << endl;
}

//template <typename T>
//void WavRaw<T>::extractData(string sourceName, unsigned int addres, unsigned int length)
void WavRaw::extractData(string sourceName, unsigned int addres, unsigned int length)
{
    cout << "WavRaw::sourceName = " << sourceName << endl;
    cout << "WavRaw::addres = " << addres << endl;
    cout << "WavRaw::length = " << length << endl;
    cout << "WavRaw::containerLength = " << containerLength << endl;

    //if (containerLength > 0) {
    //    delete[] itsContainer;
    //}

    containerLength = length / sizeof(short);
    cout << "WavRaw::containerLength = " << containerLength << endl;

    itsContainer = new short[containerLength];



    ifstream inpFile;
    inpFile.open(sourceName, ios::in | ios::binary);
    /*
    if (inpFile.is_open()) {
        inpFile.seekg(addres);
        //for (unsigned int counter = 0; counter < containerLength; ++ counter) {
        //    inpFile.read((char*)&itsContainer[counter], sizeof(short));
        //}
    }
    */
    inpFile.close();



    //for (int i = containerLength - 10 ; i < containerLength; ++i) {
        //cout << "itsContainer[" << i << "] = " << hex << itsContainer[i] << endl;
    //}
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


