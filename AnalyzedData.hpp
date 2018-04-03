// Контейнер для данных из которых необходимо выделить селективный вызов

#include <string>
#include <cstring>
#include <fstream>
#include "./SourceHead.hpp"
#include "./SourceData.hpp"
#include "./ConstAndVar.hpp"
#include "./WavHead.hpp"

using std::string;
using std::ifstream;

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
        AnalyzedData(const AnalyzedData &rhv);
        ~AnalyzedData(void);

        // Операторы 
        AnalyzedData operator= (const AnalyzedData &rhv);

        // Методы доступа к полям
        void   setType(Source typeDS);
        int    getType(void) const;
        void   setSourceName(string sName);
        string getSourceName(void) const;
        void   extractHead(void);
        void   extractHead(string fileName);
        void   extractData(void);
        unsigned int getDataLength(void) const;
        unsigned int getBegin(void) const;

    private:
        Source      sourceType;
        string      sourceName;
        SourceHead* itsHead;
        SourceData* itsData;
        int         dataLen; 

        bool isSourceExists(const string sourceName) const;
        void readSource(void);
};

