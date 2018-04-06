// SourceHead.hpp
// Абстрактный класс, определяющий общий интерфейс для анализа заголовков всех истночников анализа

#ifndef SOURCEHEAD_H
#define SOURCEHEAD_H

#include <string>

using std::string;

class SourceHead
{
    public:
        // Используются конструктор и деструктор умолчаний
        SourceHead();
        virtual ~SourceHead();

        virtual void           setHeadData(string sourceName)  = 0;
        virtual string         getSourceType(void)       const = 0;
        virtual unsigned int   getDataLength(void)       const = 0;
        virtual unsigned int   getDataBegin(void)        const = 0;
        virtual unsigned short getBPS(void)              const = 0;

    private:
};

#endif

