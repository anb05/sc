// WavRaw.hpp

#ifndef WAVRAW_H
#define WAVRAW_H

#include <string>
#include "./SourceData.hpp"

using std::string;

class WavRaw : public SourceData
{
    public:
        // Конструкторы деструктор
        WavRaw();
        ~WavRaw();

        // Переопределяемые методы

        virtual void extractData(string sourceName, unsigned int addres, unsigned int length);
        virtual int& readData(unsigned int sdBegin, unsigned int sdLength);

    private:
        unsigned int itsContainer[];
};

#endif

