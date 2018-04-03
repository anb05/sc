//AnalyzedData.cpp


// Убрать после отладки
#include <iostream>
using std::cout;
using std::endl;

#include "./AnalyzedData.hpp"

AnalyzedData::AnalyzedData() :
    sourceName(SOURCEDATA), sourceType(SOURCETYPE)
{
    if (!isSourceExists(sourceName)) {
        throw 101;
    }

    readSource();
}

AnalyzedData::AnalyzedData(string sourceName, Source st) :
    sourceName(sourceName), sourceType(st)
{
    if (!isSourceExists(sourceName)) {
        throw 101;
    }

    readSource();
}

AnalyzedData::AnalyzedData(const AnalyzedData &rhv)
{
    /*************  ЗАГЛУШКА  ************************************************************/
    // Вначале создать конструктор копирования для классов источников данных:
    //         - WavHead;
    //         - WavRaw
    //         - и всех остальных
    // псле чего закончить конструктор копирования
    cout << "Конструктор копирования не готов будет выброшено исключение 201" << endl;
    throw 201;
}

AnalyzedData::~AnalyzedData()
{
    if (itsHead != NULL) {
        cout << "delete itsHead " << endl;
        delete itsHead;
    }
    if (itsData !=NULL) {
        delete itsData;
    }
}

// Оператор копирования
AnalyzedData AnalyzedData::operator= (const AnalyzedData &rhv)
{
    if (this != &rhv) {
    /*************  ЗАГЛУШКА  ************************************************************/
    // Вначале создать оператор присваивания для классов источников данных:
    //         - WavHead;
    //         - WavRaw
    //         - и всех остальных
    // псле чего закончить сдесь 
        throw 201;
    }

    return *this;
}

void AnalyzedData::setType(Source sT)
{
    if (file == sT) {
        string sourceName = SOURCEDATA;
    }
    else if (streamOS == sT){
        sourceName = "";
    }
    sourceType = sT;
}

int AnalyzedData::getType(void) const
{
    return sourceType;
}

void AnalyzedData::setSourceName(string sName)
{
    sourceName = sName;
    // Описать проверку проверку sName на файл файловой системы или поток и установить 
    // соответствующий sourceType
}

string AnalyzedData::getSourceName(void) const
{
    return sourceName;
}

unsigned int AnalyzedData::getDataLength(void) const
{
    return itsHead->getDataLength();
}

unsigned int AnalyzedData::getBegin(void) const
{
    return itsHead->getDataBegin();
}



// Приватные методы

bool AnalyzedData::isSourceExists(const string sourceName) const
{
    if (sourceType == file) {
        ifstream ifs(sourceName);
        if (ifs.is_open()) {
            return true;
        }
    } 
    return false;
}

void AnalyzedData::readSource(void)
{
    if (file == sourceType) {
        itsHead = new WavHead(sourceName);
    }
    else if (streamOS == sourceType) {
        throw 202;
    }
    else {
        throw 101;
    }




/*
    cout << "Проверка инициализации" << endl;

    itsHead->getSourceType();

    cout << "sizeof itsHead = " << sizeof(itsHead) << endl;

    SourceHead* pntSourceHead = new WavHead();
    pntSourceHead->setHeadData(sourceName);
    
    cout << pntSourceHead->getSourceType() << endl;

    delete pntSourceHead;
    aData->setType(streamOS);
    cout << "Type data: " << aData->getType() << endl;
    cout << "Source name: " << aData->getSourceName() << endl;


    unsigned short int iA = 5;
    char cC = '5';


    cout << "iA = " << iA << "sizeof(iA) = " << sizeof(iA) << endl;
    cout << "cC = " << cC << "sizeof(cC) = " << sizeof(cC) << endl;

*/



}

