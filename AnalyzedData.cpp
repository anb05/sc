#include "./AnalyzedData.hpp"

AnalyzedData::AnalyzedData() {}
AnalyzedData::AnalyzedData(string sourceName, Source st) :
    sourceName(sourceName), sourceType(st)
{
}

AnalyzedData::~AnalyzedData() {}

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


