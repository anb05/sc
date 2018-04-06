// Абстрактный класс, определяющий общий интерфейс для тела данных всех истночников анализа

#ifndef SOURCEDATA_H
#define SOURCEDATA_H

#include <string>

using std::string;

//template <typename T>
class SourceData
{
    public:
        // Используются конструктор и деструктор умолчаний
        SourceData();

        // Рассмотреть вариант использования закрытого конструктора в классах наследниках
        // для запрета создания объектов в стеке
        virtual ~SourceData();

        // чисто абстрактные методы доступа

        // Метод предназначен для извлечения битовой последовательности из источника данных
        // Во входных параметрах передаётся:
        //     - источник данных - sourceName;
        //     - адрес (смещение) с которого начинать считывать;
        //     - количество данных которое необходимо считать.
        virtual void extractData(string sourceName, unsigned int addres, unsigned int length) = 0;

        // Метод возвращает адрес на извлечённую битовую последовательность
        //virtual T* readAllData() const = 0;
        virtual char* readAllData() const = 0;

        // Метод создаёт в области кэш памяти новый массив с выбранными элементами:
        //     - адрес (смещение) с которого начинать считывать, по умолчанию НУЛЬ;
        //     - длина отдаваемого фрагмента, по умолчанию весь фрагмент
        // и возвращает его адрес
        //virtual T* readChunk(unsigned int offset, unsigned int length) = 0;
        virtual char* readChunk(unsigned int offset, unsigned int length) = 0;

    private:

};

#endif
