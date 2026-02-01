#include <iostream>
#include <string>
#include <algorithm> 
#include <cctype>
#include <locale>
#include <cstdlib>
int main()
{
    wchar_t e_grave = L'\u00E8';
    bool book = true;
    std::string eyes;
    std::string originalfind;
    int currbookmark = 0;
    int bookmark[1000];
    std::string ToFind;
    std::string replacer = "";
    int in, current1;
    std::string Where;
    std::string currentword = "";
    std::string nextchars = "";
    int currentarray = 0;
    int WordNumber = 0;
    std::string words[1000];
    char prev = 'L';
    std::cout << "Cosa vuoi trovare? ";
    std::cin >> ToFind;
    originalfind = ToFind;
    std::cout << "Dove lo vuoi trovare? ";
    std::cin.ignore();
    std::getline(std::cin, Where);
    std::cout << "Vuoi vedere tutte le parole?(Si/No)  ";
    while (true) {
        std::cin >> eyes;
        if (eyes == "Si" || eyes == "si" || eyes == "sI") {
            book = false;
            break;
        }
        else if (eyes == "No" || eyes == "no" || eyes == "nO") {
            book = true;
            break;
        }
        else {
            std::cout << "Non sono sicuro di cosa abbia scritto, la prego di ripetere: ";
            std::cin >> eyes;
        }
    }
    system("cls");
    if (Where[(Where.length() - 1)] != ' ') {
        Where += ' ';
    }
    if (Where[0] == ' ') {
        Where.erase(Where.begin());
    }
    std::transform(ToFind.begin(), ToFind.end(), ToFind.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    std::transform(Where.begin(), Where.end(), Where.begin(), [](unsigned char c) {
        return std::tolower(c);
        });
    for (int i = 0; i < Where.length(); i++) {
        if (Where[i] == ' ' && prev != ' ') {
            WordNumber++;
            prev = ' ';
        }
        else {
            prev = Where[i];
        }
    }
    prev = 'L';    
    for (int i = 0; i < Where.length(); i++) {
        if (Where[i] != ' ' && !std::ispunct(Where[i])) {
            currentword += Where[i];
        }
        else if (Where[i] == ' ') {
            words[currentarray] = currentword;
            currentarray++;
            currentword = "";
        }
    }
    std::cout<< "Ci sono: " << WordNumber << " parole\n";
    currentword = "";
    if (ToFind.length() > 1) {
        for (int i = 0; i < WordNumber; i++) {
            currentword = words[i];
            in = i;            
            for (int ia = 0; ia < currentword.length(); ia++) {                
                if (currentword[ia] == ToFind[0]) {                    
                    if (ToFind.length() <= (currentword.length() - ia)) {
                        nextchars = "";
                        for (size_t j = 0; j < ToFind.length(); j++) {
                            nextchars += currentword[ia + j];
                        }                        
                        if (nextchars == ToFind) {                            
                            replacer = "";
                            for (int j = 0; j < ToFind.length(); j++) {
                                currentword[ia + j] = std::toupper(currentword[ia + j]); 
                            }                            
                            words[in] = currentword;
                            bookmark[currbookmark] = in;
                            currbookmark++;
                            currentword = "";
                        }
                    }
                }
                
            }
        }
    }
    else {
        for (int i = 0; i < WordNumber; i++) {
            currentword = words[i];            
            for (int j = 0; j < currentword.length(); j++) {                
                if (currentword[j] == ToFind[0]) {
                    currentword[j] = std::toupper(currentword[j]);
                }                
            }
            words[i] = currentword;
        }
    }
    if(book == false){
    for (int i = 0; i < WordNumber; i++) {
         std::cout << words[i] << " ";
         
     }
    }else{
        for (int i = 0; i < currbookmark; i++) {
            std::cout << " " << words[bookmark[i]];
        }
        std::cout << "\n In tutto ho trovato \"" << originalfind << "\" " << currbookmark << " volte.";
        
    }
}

