// Абстрактный класс, определяющий общий интерфейс для тела данных всех истночников анализа

#include <string>

using std::string;

class SourceData
{
    public:
        // Используются конструктор и деструктор умолчаний
        SourceData();
        virtual ~SourceData();

        // чисто абстрактные методы доступа
        virtual void extractData(string sourceName) = 0;
        virtual int& readData(void) = 0;

    private:
};

