#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
    char c[26], a;
    ifstream fin;
    fin.open("ceaser2.txt");
    int found=0, exist=0, ct[26], swi=0;
    for(int i=0; i<26; i++)
        ct[i]=0;
    while(fin.get(a)){
        found=0;
        if(isalpha(a)){
            a=tolower(a);
            if(swi==1){
                for(int i=0; i<exist; i++){
                    if(c[i]==a){
                        ct[i]++;
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    c[exist]=a;
                    ct[exist]++;
                    exist++;
                }
            }
            if(swi==0){
                c[0]=a;
                ct[0]++;
                swi=1;
                exist=1;
            }
        }
    }
    for(int i=0; i<exist-1; i++){
        for(int j=0; j<exist-i-1; j++){
            if(ct[j]<ct[j+1]){
                swap(ct[j], ct[j+1]);
                swap(c[j], c[j+1]);
            }
        }
    }
    for(int i=0; i<exist; i++){
        cout<<c[i]<<": "<<ct[i]<<endl;
    }
    cout<<"The key is "<<int(c[0]-'e')<<endl;
}

