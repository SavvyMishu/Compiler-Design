#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream file("datafile1.c");
    ofstream file_2("Output.txt");

    if(!file.is_open()){
        cout << "File can't be opened!!" << endl;
        return 0;
    }

    char c;
    string ans = "";

    while(file.get(c)){
        if(c == '(' || c == ')'){
            ans += c;
            file_2.put(c);
        }
    }
    file.close();
    file_2.close();

    return 0;
}