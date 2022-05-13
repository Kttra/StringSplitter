/*  Program created on 3/18/2022

    The program takes in a line of text from the user. It
    then splits the line into words and outputs it to the user.

    It will assume that spaces indicates a new word. This program
    is made to test strings and vectors. This code is also used for preparation
    in order to update my time adder project.

    Update 5/12/2022
    Made it so white space and empty strings are not added to the word vector.
    Got rid of using namespace std. Converted blocks of code into functions to
    transfer to other projects more easily
*/

#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> SplitStr(std::string strToSplit);
void PrintWords(std::vector<std::string> wordList);

int main(){
    std::string userInput;

    //Loops the whole program
    while(true){
        //Getting userInput
        std::cout << "Enter a line of text: ";
        getline(std::cin, userInput);

        //Split the string
        SplitStr(userInput);
    }

    return 0;
}

//Split the string at every space and append each word to a vector
std::vector<std::string> SplitStr(std::string strToSplit){
    std::vector<std::string> wordList;
    int wordNum = 0;
    std::string word;

    //Length of the string
    int length = strToSplit.length();

    //Separating the words into a vector
    for(int i = 0; i < length; i++){
        //If the char is not a space, append it
        if(strToSplit[i] != ' '){
            word = word + strToSplit[i];
        }
        //Make sure that the word is not empty
        else if(!word.empty()){
            wordList.push_back(word);
            word = "";
            wordNum++;
        }
    }

    //Because there is not a space at the end, we need to add the last word manually
    //Also need to make sure that it is not just white space
    if(word.find_first_not_of(' ') != std::string::npos){
        wordList.push_back(word);
    }

    PrintWords(wordList);

    return wordList;
}

void PrintWords(std::vector<std::string> wordList){
    //Outputting the number of words
    if(wordList.size() == 1){
        std::cout << '\n' << "There is only 1 word in your line. Here is the word: " << '\n';
    }
    else{
        std::cout << '\n' << "There are " << wordList.size() << " words in your line. Here are the words: " << '\n';
    }

    //Outputting the words
    for(int i = 0; i < wordList.size(); i++){
        std::cout << "Word " << i+1 << ": ";
        std::cout << wordList[i] << '\n';
    }
    std::cout << std::endl;
}
