#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>

using namespace std;

class StringCalculator{
    public:

    int Add(string numbers)
    {
        if(numbers == "") return 0;
        int Number1=0,Number2=0;
        string CurrentNumberStr = "";
        try{
            for(int i=0;i<numbers.size();++i){
                if(isDelimiter(numbers[i])){
                    Number1 = stoi(CurrentNumberStr);
                    CurrentNumberStr = "";
                    continue;
                }
                if(numbers[i] >= '0' && numbers[i] <= '9') CurrentNumberStr += numbers[i];
                else{
                    cout<<"numbers[i]="<<numbers[i]<<"i="<<i<<"\n";
                    string error = "Invalid Input!";
                    throw error;
                }
            }
            if(CurrentNumberStr != "") Number2 = stoi(CurrentNumberStr);
        }
        catch(string err){
            cout<<err<<"\n";
            exit(1);
        }
        int Answer = Number1 + Number2;
        return Answer;
    }

    private:

    //Checks if current character is a delimiter or not.
    bool isDelimiter(char c)
    {
        if(c == ',') return true;
        return false;
    }
};

int main()
{
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