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
        // Конструкторы умолчаний, создает контейнер длиной в 1 ячейку
        // со значением 0.
        // Значение containerLength устанавливаетмя равным 1
        WavRaw();

        // В конструтр передаются:
        //    - нименование файла, из которого осуществляется чтение;
        //    - начальное смещение в байтах от начала файла (для wav файла 44);
        //    - длина массива информации в байтах.
        //
        // Т.к в программе используется не сжатый (сырой) wav - файл, то 
        // данные представляют из себя 16 разрядные числа. 
        // Следовательно общее количество отсчётов равно length/2 или 
        // length / sizeof(short)
        WavRaw(string sourceName, unsigned int addres, unsigned int length);
        ~WavRaw();

        // Переопределяемые методы

        // Метод для непосредственного извлечения данных из WAV файла и изменения (заполнения) объекта.
        // Исходными данными являются:
        //    - нименование файла, из которого осуществляется чтение;
        //    - начальное смещение в байтах от начала файла (для wav файла 44);
        //    - длина массива информации в байтах.
        void extractData(string sourceName, unsigned int addres, unsigned int length);


        //T* readAllData(void) const;
        //T* readChunk(unsigned int offset, unsigned int length);
        short* readAllData(void) const;
        short& readChunk(unsigned int offset, unsigned int length);


    private:
        // Непосредственно контейнер (адрес) на массив с 16-битными отсчётами амплитуды
        short* itsContainer;

        // Количество 16-битных отсчётов в контейнере
        unsigned int containerLength;
};

#endif

