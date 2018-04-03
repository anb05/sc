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

    try {
        //AnalyzedData* aData = new AnalyzedData("other", streamOS);
        //AnalyzedData* aData = new AnalyzedData(sourceName, sT);
        AnalyzedData* aData = new AnalyzedData();

        cout << "Type data: " << aData->getType() << endl;
        cout << "Source name: " << aData->getSourceName() << endl;

        cout << "Begin Data adres = " << aData->getBegin() << endl;
        cout << "Data length = " <<  aData->getDataLength() << endl;

        delete aData;

    } catch (int numExp) {
        switch (numExp) {
            case 101:
                cout << "The source is not exists!" << endl;
                return 101;
                break;

            case 201:
                cout << "Do not created copy of AnalyzedData Object" << endl;
                return 201;
                break;

            case 202:
                cout << "The stream inputs is not created" << endl;
                return 202;

            default:
                return 1;
        }
    }

/*
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

    return 0;
}

