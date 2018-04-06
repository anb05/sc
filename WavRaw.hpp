// WavRaw.hpp

#ifndef WAVRAW_H
#define WAVRAW_H

#ifndef SOURCEDATA_H
#include "./SourceData.hpp"
#endif

#include "./ConstAndVar.hpp"
#include <fstream>

using std::string;

//template <typename T>
class WavRaw : public SourceData
{
    public:
        // Конструкторы деструктор
        WavRaw();
        WavRaw(string sourceName, unsigned int addres, unsigned int length);
        ~WavRaw();

        // Переопределяемые методы

        void extractData(string sourceName, unsigned int addres, unsigned int length);
        //T* readAllData(void) const;
        //T* readChunk(unsigned int offset, unsigned int length);
        char* readAllData(void) const;
        char* readChunk(unsigned int offset, unsigned int length);


    private:
        char* itsContainer;
        unsigned int containerLength;
};

#endif

