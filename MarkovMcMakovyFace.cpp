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
    struct timeval time;
    srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
    ifstream SampleFile("sample.txt");
    string SampleText;
    getline(SampleFile,SampleText);
    string CurrentStoredWord;
    char PreviousCharacter;
    int AmountOfWords = 0;
    int CurrentWordArrayPosition = 0;
    int AmountOfWordsToPredict_NonCon;
    cout << "Quante parole vuoi predirre?";
    cin >> AmountOfWordsToPredict_NonCon;
    const int AmountOfWordsToPredict = AmountOfWordsToPredict_NonCon;
    if (SampleText[SampleText.length()] != ' ') {
        SampleText = SampleText + ' '; 
    } 
    for (int i = 0; i <= SampleText.length(); i++) {
        if (SampleText[i] == ' ' &&  PreviousCharacter != ' ') {
            AmountOfWords++;
            PreviousCharacter = ' ';
        }
        else {
            PreviousCharacter = SampleText[i];
        }
    } // ^ Finds the amount of words in the sample text, so the array size may corresp50nd to it.
    string WordArray[AmountOfWords];
    map<string, map<string, int>> bigrams;
    for (int i = 0; i < SampleText.length(); i++) {
        if (SampleText[i] != ' ' && !ispunct(SampleText[i])) {
            CurrentStoredWord += SampleText[i];
        }
        else if (SampleText[i] == ' ' && CurrentWordArrayPosition != AmountOfWords) {
            WordArray[CurrentWordArrayPosition] = CurrentStoredWord;
            CurrentWordArrayPosition++;
            CurrentStoredWord = "";
        } else {
            WordArray[CurrentWordArrayPosition - 1] = CurrentStoredWord;
            exit; 
        }
    } // ^ Puts all the words in the sample text into an array
    //for (int i = 0; i < AmountOfWords; i++) {
    //   cout << WordArray[i] << ' ';
    //}
    cout << "\n";
    //the part of the code that sorts the simple word array into a bigram map 
    //its borked, i hate it, i disown it
    //oh my god bruh i messed up the god darn map
    for (int i = 0; i < AmountOfWords; i++) {
        string w1 = WordArray[i];
        string w2;
        if (i + 1 < AmountOfWords) {
          w2 = WordArray[i + 1]; 
        }
        if (!bigrams[w1][w2]) {
            bigrams[w1][w2] = 1;
        } else{
            bigrams[w1][w2] += 1;
        }        

    }
    int test_int = rand() / (RAND_MAX / AmountOfWords + 1);
    string SeedWord = WordArray[test_int]; 
    vector<string> Output;
    for (int i = 0; i < AmountOfWordsToPredict; i++) {
        vector<string> Possibles = {};
        for (auto it = bigrams[SeedWord].begin(); it != bigrams[SeedWord].end(); ++it){
        // add the key to the vector how many times the second time says?
           for (int k = 0; k <= it -> second;k++) {
            Possibles.push_back(it->first);
           }            
        }
        string NewSeed = Possibles[rand() / (RAND_MAX / Possibles.size() + 1)];
        Output.push_back(NewSeed); 
        SeedWord = NewSeed;       
    }
    for (int i = 0; i < Output.size(); i++) {
        cout << Output[i] << " ";
    }
    //update 4, god damnit
    //update 5, im so sick of tihs
    //update 6 yayyyyy it works!!!
    //update 7 it keeps repeating words :sob:
    cout << "hi";
    return 0;
}