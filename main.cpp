/*  Program created on 3/18/2022

    The program takes in a line of text from the user. It
    then splits the line into words and outputs it to the user.

    It will assume that spaces indicates a new word. This program
    is made to test strings and vectors. This code is used for preparation
    in order to update the time adder project.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
    string userInput;
    vector<string> wordList;

    //Loops the whole program
    while(true){
        int wordNum = 0;
        string word;

        //Getting userInput
        std::cout << "Enter a line of text: ";
        getline(cin, userInput);

        //length of the userInput
        int length = userInput.length();

        //Separating the words into a vector
        for(int i = 0; i < length; i++){
            if(userInput[i] != ' '){
                word = word + userInput[i];
            }
            else{
                wordList.push_back(word);
                word = "";
                wordNum++;
            }
        }

        //Because there is not a space at the end, we need to
        //Add the last word manually
        wordList.push_back(word);

        //Outputting the number of words
        if(wordList.size() == 1){
            cout << endl << "There is only " << wordList.size() << " word in your line. Here is the word: " << endl;
        }
        else{
            cout << endl << "There are " << wordList.size() << " words in your line. Here are the words: " << endl;
        }

        //Outputting the words
        for(int i = 0; i < wordList.size(); i++){
            cout << "Word " << i+1 << ": ";
            cout << wordList[i] << endl;
        }
        cout << endl;

        //Reset everything
        word = "";
        wordList.clear();
    }

    return 0;
}
