#include<bits/stdc++.h>
using namespace std;
int main(){
    ifstream file("input.c");
    ofstream file_2("output.txt");

    if(!file.is_open()){
        cout << "File can't be opened!!" << endl;
        return 0;
    }

    string line;
    int i = 1;
    while(getline(file, line)){
        file_2 << i << ":" << line << endl;
        i++;
    }
    file.close();
    file_2.close();
    return 0;
}