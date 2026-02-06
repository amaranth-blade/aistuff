#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <math.h>
#include <map>
#include <cstdlib>
#include <fstream>
using namespace std;
int main() {
    ifstream SampleFile("sample.txt");
    string SampleText_TEMP;
    getline(SampleFile,SampleText_TEMP);
    const string SampleText = SampleText_TEMP;
    cout << SampleText;
}