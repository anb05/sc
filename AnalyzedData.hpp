// Контейнер для данных из которых необходимо выделить селективный вызов

#include <string>
#include "./SourceHead.hpp"
#include "./SourceData.hpp"
#include "./ConstAndVar.hpp"

using std::string;

enum Source {
	streamOS,
	file
};

class AnalyzedData
{
    public:
        // Конструктор и деструктор
        AnalyzedData(void);
        AnalyzedData(string sourceName, Source sT);
        ~AnalyzedData(void);

        // Методы доступа к полям
        void   setType(Source typeDS);
        int    getType(void) const;
        void   setSourceName(string sName);
        string getSourceName(void) const;
        void   extractHead(void);
        void   extractHead(string fileName);
        void   extractData(void);

    private:
        Source      sourceType;
        string      sourceName;
        SourceHead* itsHead;
        SourceData* itsData;
        int         dataLen; 
};

