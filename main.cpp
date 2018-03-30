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
    aData->setType(streamOS);
    cout << "Type data: " << aData->getType() << endl;
    cout << "Source name: " << aData->getSourceName() << endl;
    return 0;
}

