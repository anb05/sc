// Абстрактный класс, определяющий общий интерфейс для анализа заголовков всех истночников анализа

#include <string>

using std::string;

class SourceHead
{
    public:
        // Используются конструктор и деструктор умолчаний
        SourceHead();
        ~SourceHead();

        virtual void   setHeadData(string sourceName) = 0;
        virtual string getSourceType(void) = 0;

    private:
};


