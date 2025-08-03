#include<bits/stdc++.h>
using namespace std;

bool kw(string str)
{
    if ((str== "if") || (str == "else") ||
        (str== "while") || (str == "do") ||
        (str== "break") ||  (str =="continue")
        || (str== "int") || (str =="double")
        || (str== "float") || (str == "return")
        || (str== "char") || (str == "case")
        || (str== "long") || (str =="short")
        || (str== "typedef") || (str == "switch")
        || (str== "unsigned") || (str == "void")
        || (str== "static") || (str == "struct")
        || (str== "sizeof") || (str == "long")
        || (str== "volatile") || (str == "typedef")
        || (str== "enum") || (str =="const")
        || (str == "union") || (str ==  "extern")
        || (str =="bool"))
        {
            return true;
        }
        else return false;
}
bool op(string s)
{
    if(s == "+" || s == "-" || s == "<" || s == ">" || s == "*" || s == "/" || s == "%" || s == "=" || s == "!" || s == "&" || s == "^" || s == ">=" || s == "<=" || s == "==" || s== "|" || s == "||" || s == "&&") return true;
    return false;
}
bool sep(string s)
{
    if(s=="\'" || s == ","|| s == "\"" || s== ";") return true;
    else return false;
}
bool par(string s)
{
    if(s=="(" || s == ")") return true;
    else return false;
}
bool id(string str)
{
if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||
        str[0] == '9' )
        {
            return false;
        }									
    int i,len = str.size();
    if (len == 1)
    {
        return true;
    }										
    else
    {
    for (i = 1 ; i < len ; i++)						
    {
        if (sep(to_string(str[0])) == true || op(to_string(str[0])) == true)
        {
            return false;
        }
    }
    }
    return true;
}
bool num(string s)
{
    int cnt = 0;
    for(int i = 0; i<s.size(); i++)
    {
        if(s[i] != '0' && s[i] != '1' && s[i] != '2' && s[i] != '3' && s[i] != '4' && s[i] != '5' && s[i] != '6' && s[i] != '7' && s[i] != '8' && s[i] != '9' && s[i]  != '.')
        {
            return false;
        }
        if(s[i] == '.') cnt++;
    }
    if(cnt>1) return false;

    return true;
}

int main(){

    ifstream file1("input.txt");
    ofstream file2("output.txt");

    if(!file1.is_open()){
        cout << "Not found" << endl;
        return 0;
    }
    string l,w;
    while(getline(file1,l))
    {
        stringstream s(l);
        while(s >> w){
            string sb = "";
            for(int i = 0; i < w.size(); i++){
                if(w[i] == '>'){
                    if(i < w.size()-1 && w[i+1] == '='){
                        sb += " >= ";
                        i++;
                    }
                    else{
                        sb += " > ";
                    }
                    continue;
                }
                if(w[i] == '<'){
                    if(i < w.size()-1 && w[i+1] == '='){
                        sb += " <= ";
                        i++;
                    }
                    else{
                        sb += " < ";
                    }
                    continue;
                }
                if(w[i] == '='){
                    if(i < w.size()-1 && w[i+1] == '='){
                        sb += " == ";
                        i++;
                    }
                    else{
                        sb += " = ";
                    }
                    continue;
                }
                if(w[i] == '=' || w[i] == ',' || w[i] == ';' || w[i] == '(' || w[i] == ')' || w[i] == '*' || w[i] == '/' || w[i] == '+' || w[i] == '-' || w[i] == '|' || w[i] == '&' || w[i] == '\'')
                    {
                        sb += " ";
                        sb += w[i];
                        sb += " ";
                        continue;
                    }
                    sb += w[i];
            }
            
            stringstream lex(sb);
            while(lex >> w){
                if(kw(w))
                    {
                        file2 << "[kw " << w << "] ";
                    }
                    else if(op(w))
                    {
                        file2 << "[op " << w << "] ";
                    }
                    
                    else if(sep(w))
                    {
                        file2 << "[sep " << w << "] ";
                    }   
                    else if(par(w))
                    {
                        file2 << "[par " << w << "] ";
                    }
                    else if(num(w))
                    {
                        file2 << "[num " << w << "] ";
                    }
                    else if(id(w))
                    {
                        file2 << "[id " << w << "] ";
                    }
                    else{   
                        cout << w << " is unknown\n";
                        file2 << "[unkn " << w << "] ";
                    }

            }
        }
    }
    file1.close();
    file2.close();
}