#include "./WavHead.hpp"
#include <fstream>

using std::ifstream;
using std::ios;

WavHead::WavHead() {}
WavHead::~WavHead() {}

void WavHead::setHeadData(string fileName)
{
    ifstream isf;
    isf.open(fileName, ios::in | ios::binary);

    isf.close();
}

string getSourceType(void)
{
    return "WAVE";
}

