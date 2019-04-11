#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
using namespace std;
double psi=0.0685692;
double close_psi[100];
int cnt=0;
string close_psistring[100];
void check_psi(const string & s);
double return_psi(int * n, int num);
int main(){
    ifstream fin;
    string section;
    fin.open("alice_in_wonderland.txt");
    ofstream fout;
    char a;
    int swi=0;
    while(fin.get(a)){
        if(isalpha(a)){
            //cout<<"get: "<<a<<endl;
            //system("pause");
            a=tolower(a);
            if(swi==0){
                swi=1;
                section+=a;
                for(int i=1; i<235;){
                    fin.get(a);
                    if(isalpha(a)){
                        a=tolower(a);
                        section+=a;
                        i++;
                    }
                }
            }
            else{
                section.erase(0, 1);
                /*cout<<"get: "<<a<<endl;
                system("pause");*/
                section+=a;
            }
            /*cout<<section<<endl;
            cout<<section.length()<<endl;
            system("pause");*/
            check_psi(section);
        }
    }
    for(int i=0; i<cnt; i++){
        cout<<close_psi[i]<<endl;
        cout<<"Words count: "<<close_psistring[i].length()<<endl;
        cout<<close_psistring[i]<<endl<<endl;
        fout.open("found.txt");
        for(int j=0; j<close_psistring[i].length(); j++)
            fout<<j+1<<close_psistring[i][j]<<" ";

    }

}
void check_psi(const string & s){
    char c[26], a;
    int found=0, exist=0, ct[26], swi=0;
    for(int i=0; i<26; i++)
        ct[i]=0;
    for(int i=0; i<s.length(); i++){
        found=0;
        if(isalpha(s[i])){
            tolower(s[i]);
            if(swi==1){
                for(int j=0; j<exist; j++){
                    if(c[j]==s[i]){
                        ct[j]++;
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    //cout<<char(a)<<endl;
                    c[exist]=s[i];
                    ct[exist]++;
                    exist++;
                }
            }
            if(swi==0){
                c[0]=s[i];
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
    /*for(int i=0; i<exist; i++){
        cout<<c[i]<<": "<<ct[i]<<endl;
    }*/
    double temp;
    //temp=return_psi(ct, exist);
    //cout<<temp<<endl;
    if((s[0]==s[6])&&(s[2]==s[11])&&(s[2]==s[14])&&(s[12]==s[15])&&(s[10]==s[16])&&(s[16]==s[19])){
        //cout<<"psi: "<<temp<<endl;
        cout<<s<<endl;
        //close_psi[cnt]=temp;
        close_psistring[cnt]=s;
        cnt++;
        //cout<<cnt<<endl;
        /*cout<<"psi: "<<temp<<endl;
        cout<<s<<endl<<endl;
        system("pause");*/
    }
    //cout<<s<<endl;
    //system("pause");
}
double return_psi(int * n, int num){
    double psi=0;
    int total=0;
    for(int i=0; i<num; i++)
        total+=n[i];
    for(int i=0; i<num; i++)
        psi=psi+(double(n[i])/total)*(double(n[i])/total);
    return psi;
}
