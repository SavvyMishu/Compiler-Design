#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream p1("input1.c");
    ofstream p2("output.txt");
    // file_2 << "string";

    if(!p1.is_open()){
        cout << "File can't be opened!!" << endl;
        return 0;
    }

    string line;
    int flag = 0;
    while(getline(p1, line)){
        size_t f1 = line.find("/*");
        size_t f2 = line.find("*/");
        if(f1 != string::npos) flag = 1;
        if(f2 != string::npos){
            flag = 0;
            continue;
        }
        if(flag) continue;

        size_t start = line.find("//");
        if(start != string::npos){
            string line2 = line.substr(0, start);
            // p2 << line2;
            line = line2;
        }

        int flag2 = 0;
        for(char c : line){
            if(c != ' ' && flag2 == 0){
                flag2 = 1;
            }
            if(flag2) {
                p2 << c;
            }
        }
    }
    

    p1.close();
    p2.close();
    return 0;
}