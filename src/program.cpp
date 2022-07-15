#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector<char> delimiters;

class StringCalculator{
    public:

    int Add(string numbers)
    {
        if(numbers == "") return 0;
        vector<int> Numbers;
        string CurrentNumberStr = "";
        try{
            int startIndex = checkDelimiter(numbers);
            for(int i=startIndex;i<numbers.size();++i){
                if(isDelimiter(numbers[i])){
                    if(CurrentNumberStr == ""){
                        string error = "Invalid Input!";
                        throw error;
                    }
                    int currentNumberInt = stoi(CurrentNumberStr);
                    Numbers.push_back(currentNumberInt);
                    CurrentNumberStr = "";
                    continue;
                }
                if(numbers[i] >= '0' && numbers[i] <= '9') 
                    CurrentNumberStr += numbers[i];
                else{
                    cout<<"numbers[i]="<<numbers[i]<<"i="<<i<<"\n";
                    string error = "Invalid Input!";
                    throw error;
                }
            }
            if(CurrentNumberStr != ""){
                int currentNumberInt = stoi(CurrentNumberStr);
                Numbers.push_back(currentNumberInt);
                CurrentNumberStr = "";
            }
        }
        catch(string err){
            cout<<err<<"\n";
            exit(1);
        }
        int Answer = 0;
        for(int i=0;i<Numbers.size();++i)
            Answer += Numbers[i];
        return Answer;
    }

    private:

    //checks if current character is a delimiter or not.
    bool isDelimiter(char c)
    {
        for(int i=0;i<delimiters.size();++i) 
            if(c == delimiters[i]) 
                return true;
        return false;
    }

    //returns the index after removing delimiter if present.
    int checkDelimiter(string numbers)
    {
        if(numbers.size()>=3 && numbers[0] == '/' && numbers[1] == '/'){
            delimiters.push_back(numbers[2]);
            return 4;
        }
        return 0;
    }
};

int main()
{
    delimiters.push_back(',');
    delimiters.push_back('\n');

    fstream file;
    string word,inputStr="";
    
    file.open("read.txt");
    while(file >> word){
        inputStr += word;
        inputStr += "\n";
    }
    inputStr.pop_back(); //Removing last \n from string.

    StringCalculator calculator;
    int ans = calculator.Add(inputStr);
    cout<<"Answer: "<<ans<<"\n";
}