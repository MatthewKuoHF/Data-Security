#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
int main(){
    char c[26], a;
    ifstream fin;
    int found=0, exist=0, ct[26], swi=0;
    for(int i=0; i<26; i++)
        ct[i]=0;
    fin.open("ceaser1.txt");
    while(fin.get(a)){
        found=0;
        if(isalpha(a)){
            a=tolower(a);
            //cout<<a;
            if(swi==1){
                //cout<<exist<<endl;
                for(int i=0; i<exist; i++){
                    if(c[i]==a){
                        ct[i]++;
                        found=1;
                        break;
                        //cout<<c[i];
                    }
                }
                if(found==0){
                    //cout<<char(a)<<endl;
                    c[exist]=a;
                    ct[exist]++;
                    exist++;
                }
            }
            if(swi==0){
                c[0]=a;
                ct[0]++;
                //cout<<c[0]<<" "<<ct[0]<<endl;
                swi=1;
                exist=1;
            }
        }
    }
    //cout<<endl;
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
    cout<<"\nThe key of ceaser1.txt is 3 (and we can indeed get the plaintext with this key.)\n";
}
