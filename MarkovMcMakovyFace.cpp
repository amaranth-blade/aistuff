#include <iostream>
#include <vector>
#include <random>
using namespace std;
int main() {
    vector<string> Reference_Table;
    string SampleText = "It is never too late to have a. bad idea";
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
    for (int i = 0; i < SampleText.length(); i++) {
        if (SampleText[i] != ' ' && !ispunct(SampleText[i])) {
            CurrentStoredWord += SampleText[i];
        }
        else if (SampleText[i] == ' ') {
            WordArray[CurrentWordArrayPosition] = CurrentStoredWord;
            CurrentWordArrayPosition++;
            CurrentStoredWord = "";
        }
    } // Puts all the words in the sample text into an array
    for (int i = 0; i < AmountOfWords; i++) {
        cout << WordArray[i] << ' ';
    }
    return 0;
}