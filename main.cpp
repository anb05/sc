#include "./main.hpp"

int main(int argc, char const* argv[])
{
    /*
    cout << "argc: " << argc << endl;

    for (int i = 0; i < argc; ++i) {
        cout << "argv[" << i << "] = " << argv[i]<< endl;
    }
    */

    string sourceName = SOURCEDATA;
    Source sT = SOURCETYPE;

    cout << "SOURCEDATA = " << SOURCEDATA << endl;
    cout << "SOURCETYPE = " << SOURCETYPE << endl;

    AnalyzedData* aData = new AnalyzedData(sourceName, sT);

    cout << "Type data: " << aData->getType() << endl;
    cout << "Source name: " << aData->getSourceName() << endl;

    SourceHead* pntSourceHead = new WavHead();
    pntSourceHead->setHeadData(sourceName);
    
    cout << pntSourceHead->getSourceType() << endl;

    delete pntSourceHead;
/*
    aData->setType(streamOS);
    cout << "Type data: " << aData->getType() << endl;
    cout << "Source name: " << aData->getSourceName() << endl;


    unsigned short int iA = 5;
    char cC = '5';


    cout << "iA = " << iA << "sizeof(iA) = " << sizeof(iA) << endl;
    cout << "cC = " << cC << "sizeof(cC) = " << sizeof(cC) << endl;

*/


    return 0;
}

