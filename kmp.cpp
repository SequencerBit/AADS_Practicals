#include <iostream>
#include <vector>
#include <string>
using namespace std;

class KMP{
    string pattern;
    vector<int> LPS;
    public:
    KMP(){}
    void setPattern(string input){
        pattern = input;
        LPS.resize(pattern.size());
        formLPS();
    }
    void formLPS(){
        int i = 0;
        int j = 1;
        while(j<pattern.size()){
            if(pattern[j]==pattern[i]){
                i++;
                LPS[j]=i;
                j++;
            }
            else{
                if(i!=0){
                    i = LPS[i-1];
                }
                else{
                    LPS[j]=0;
                    j++;
                }
            }
        }
    }
    void printLPS(){
        for(int i : LPS){
            cout<<i;
        }
    }
    void match(string input){
        vector<int> foundidx;
        int j = 0;
        for(int i = 0; i<input.size(); i++){
            if(input[i]==pattern[j]){
                j++;
                // cout<<j<<" Value of J for: "<<input[i]<<endl;
                if(j==pattern.size()){
                    foundidx.push_back(i-pattern.size()+1);
                    // cout<<LPS[j - 1]<<" Value of LPS"<<endl;
                    j = LPS[j - 1];
                }
            }
            else{
                if(j>0){
                    j = LPS[j - 1];
                }
            }
        }
        for(int i : foundidx){
            cout<<"Pattern found at idx: "<<i<<endl; 
        }

    }
};

int main(){
string pattern;
string sent;
cin>>pattern;
cin>>sent;
KMP Matcher;
Matcher.setPattern(pattern);
Matcher.match(sent);
// Matcher.printLPS();
}