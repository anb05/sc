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
        /* Конструкторы деструктор */

        // Конструкторы умолчаний, создает контейнер длиной в 1 ячейку
        // со значением 0.
        // Значение containerLength устанавливаетмя равным 1
        WavRaw();

        // Конструктор создающий контейнер с WAV отсчетами из WAV файла
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

        // Конструктор создающий контейнер из массива с отсчётами
        // В качестве аргументов передаются:
        //   - указатель на массив отсчётов амплитуд;
        //   - количество элементов в массиве
        WavRaw(const short* const ptrShortArray, const unsigned int & numOfElements);

        // Конструктор копирования
        WavRaw(const WavRaw & copyWavRaw);

        // Деструктор
        ~WavRaw();

        /* Перегруженные операторы */

        // Неконстантный оператор индексирования,
        // возвращает ссылку на отсчёт, который можно изменить
        short & operator[](int offset);

        // Константный оператор индексирования,
        // используется для константных объктов (см. конструктор-копировщик)
        short operator[](int offset) const;

        // Оператор создаёт новый объект WavRaw в контейнере которого содержится
        // объединенные отсчеты двух объектов WavRaw
        WavRaw operator+ (const WavRaw &);

        // К текущему контейнеру добаляет отсчеты из контейнера аргумента
        void operator+= (const WavRaw &);

        // Оператор копирования
        WavRaw & operator= (const WavRaw &);

        // Переопределяемые методы

        // Метод для непосредственного извлечения данных из WAV файла и изменения (заполнения) объекта.
        // Исходными данными являются:
        //    - нименование файла, из которого осуществляется чтение;
        //    - начальное смещение в байтах от начала файла (для wav файла 44);
        //    - количество извлекаемых отсчётов.
        //
        // Если значение length (количество извлекаемых отсчетов)
        // больше размера контейнера (containerLength),
        // то будет извлечено только containerLength отсчетов.
        // Если значение length меньше containerLength,
        // то оставшиеся значения будут замещены нулями
        //
        void extractData(string sourceName, unsigned int addres = 0, unsigned int length = 0);


        //T* readAllData(void) const;
        //T* readChunk(unsigned int offset, unsigned int length);
        short* readAllData(void) const;
        short& readChunk(unsigned int offset, unsigned int length);


    private:
        // Непосредственно контейнер (адрес) на массив с 16-битными отсчётами амплитуды
        short* itsContainer;

        // Количество 16-битных отсчётов в контейнере
        unsigned int containerLength;

        // Закрытый конструктор, создающий контейнер заданой длины
        // с элементами, рвными 0
        WavRaw(unsigned int requiredLength);
};

#endif

