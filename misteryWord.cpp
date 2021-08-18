#include "misteryWord.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <time.h>


void displayVector(std::vector <char> array1){
    for(int i=0; i<array1.size(); i++){
        std::cout << array1[i] << ' ';
    }
    std::cout << std::endl;
}

std::vector <char> getWord(){
    std::ifstream myFlow("./words.txt");
    std::vector <std::vector <char>> words;
    std::string line;
    srand(time(NULL));
    char fileChar;

    if(myFlow){
        while(getline(myFlow, line)){
            std::vector <char> wordChar(line.begin(), line.end());
            words.push_back(wordChar);
        }
    }else
    {
      std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }
    int rngWordIndex =  rand() %words.size() +1;
    return words[rngWordIndex-1];

}

bool arraysComparaison(std::vector <char> array1, std::vector <char> array2){

    for(int i=0; i<array1.size(); i++){
        if(array1[i] != array2[i]){
            return false;
        }
    }
    return true;
}

int myScore(){
    std::ifstream myFlow("./scores.txt");
    int score = 0;
    if(myFlow)
        {
            std::string stringScore;
            getline(myFlow, stringScore);
            score = std::stoi(stringScore);
            myFlow.close();
        }
        else
        {
            std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
        }
    return score;
}

void misteryWord(){
    int score = myScore();
    std::string guessedWord;
    int numberOfTry = 1;
    std::vector <char> misterywordToguessShuffled(getWord());
    std::vector <char> misterywordToguess;
    for(int i=0; i<misterywordToguessShuffled.size(); i++){
        misterywordToguess.push_back(misterywordToguessShuffled[i]);
    }

    std::random_shuffle(misterywordToguessShuffled.begin(), misterywordToguessShuffled.end());
    std::cout << "Guess the word and write it" << std::endl;
    displayVector(misterywordToguessShuffled);
    std::cin >> guessedWord;
    std::vector <char> guessedWordToCompare = {guessedWord.begin(), guessedWord.end()};
    while(!arraysComparaison(guessedWordToCompare, misterywordToguess )&& numberOfTry < 2 ){
            std::cout << "Try again" << std::endl;
            std::cin >> guessedWord;
            guessedWordToCompare = {guessedWord.begin(), guessedWord.end()};
            numberOfTry = numberOfTry + 1;
    }
    if(arraysComparaison(guessedWordToCompare, misterywordToguess )){
        std::cout << "GG !" << std::endl;
        score = score + 100;

    }else{
        std::cout << "Looser the mistery word was ";
        displayVector(misterywordToguess);
    }

    std::ofstream myFlow("./scores.txt");
    if(myFlow)
    {
        myFlow << score;
        myFlow.close();
    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier." << std::endl;
    }
}
