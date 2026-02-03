#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
int main() {
    
    string SampleText = "It is never too late to have a. bad idea It is never too late to have a. bad idea It is never too late to have a. bad idea ";
    string CurrentStoredWord;
    char PreviousCharacter;
    int AmountOfWords = 0;
    int CurrentWordArrayPosition = 0;
    if (SampleText[SampleText.length()] != ' ') {
        SampleText = SampleText + ' '; 
    }    
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
    for (int i = 0; i < SampleText.length(); i++) {
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
    //the part of the code that sorts the simple word array into a bigram map
    for (int i = 0; i <= AmountOfWords; i++) {
        string w1 = WordArray[i];
        string w2 = WordArray[i++];
        auto it = find(bigrams.begin(), bigrams .end(), w1);
        if (it == bigrams.end()) {
            bigrams[w1] = {};
        } else {
            if (!bigrams[w1][w2]) {
                bigrams[w1][w2] = 1;
            } else{
                bigrams[w1][w2] += 1;
            }        
        }
    }
    for (int i = 0; i < AmountOfWords; i++) {
        
    }
    return 0;
}