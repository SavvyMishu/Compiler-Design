#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream file1("input.c");
    ofstream file2("output.txt");

    if(!file1.is_open()){
        cout << "File not found!!!" << endl;
    }

    int count = 0;
    string s;
    while(getline(file1,s)){
        size_t fi = s.find("){");

        if(fi != string::npos){
            count++;
        }
    }
    
        file2 << "No. of functions: " << count << endl;

    file1.close();
    file2.close();
    return 0;
}