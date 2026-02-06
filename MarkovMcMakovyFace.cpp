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
    string CurrentStoredWord;
    char PreviousCharacter;
    int AmountOfWords = 0;
    int CurrentWordArrayPosition = 0;
    int AmountOfWordsToPredict_NonCon;
    cout << "Quante parole vuoi predirre?";
    cin >> AmountOfWordsToPredict_NonCon;
    const int AmountOfWordsToPredict = AmountOfWordsToPredict_NonCon;
    if (SampleText_TEMP[SampleText_TEMP.length()-1] != ' ') {
        SampleText_TEMP = SampleText_TEMP + ' '; 
    }   
    const string SampleText = SampleText_TEMP;
    for (int i = 0; i < SampleText.length(); i++) {
        if (SampleText[i] == ' ' &&  PreviousCharacter != ' ') {
            AmountOfWords++;
            PreviousCharacter = ' ';
        }
        else {
            PreviousCharacter = SampleText[i];
        }
    } // ^ Finds the amount of words in the sample text, so the array size may correspond to it.
    string WordArray[AmountOfWords];
    map<string, map<string, int>> bigrams;
    for (int i = 0; i < SampleText.length(); i++) {s
        if (SampleText[i] != ' ' && !ispunct(SampleText[i])) {
            CurrentStoredWord += SampleText[i];
        }
        else if (SampleText[i] == ' ') {
            WordArray[CurrentWordArrayPosition] = CurrentStoredWord;
            CurrentWordArrayPosition++;
            CurrentStoredWord = "";
        }
    } // ^ Puts all the words in the sample text into an array
    for (int i = 0; i < AmountOfWords; i++) {
        cout << WordArray[i] << ' ';
    }
    cout << "\n";
    //the part of the code that sorts the simple word array into a bigram map
    for (int i = 0; i < AmountOfWords; i++) {
        string w1 = WordArray[i];
        string w2 = WordArray[i++];
        if (bigrams.find(w1) == bigrams.end()) {
            bigrams[w1] = {};
        } else {
            if (!bigrams[w1][w2]) {
                bigrams[w1][w2] = 1;
            } else{
                bigrams[w1][w2] += 1;
            }        
        }
    }
    string SeedWord = WordArray[rand() % AmountOfWords]; 
    vector<string> Output;
    for (int i = 0; i < AmountOfWordsToPredict; i++) {
        vector<string> Possibles = {};
        for (auto it = bigrams[SeedWord].begin(); it != bigrams[SeedWord].end(); ++it){
        // add the key to the vector how many times the second time says?
           for (int k = 0; k <+ it -> second;k++) {
            Possibles.push_back(it->first);
           }            
        }
        string NewSeed = Possibles[rand() / (RAND_MAX / Possibles.size() + 1)];
        Output.push_back(NewSeed); 
        SeedWord = NewSeed;       
    }
    for (int i = 0; i < Output.size(); i++) {
        cout << Output[i];
    }
    //this should god willingly print my map, update what, thrid update please end my suffering
    return 0;
}