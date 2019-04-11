#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;
double count_fqpsi(int * num, int n, int total);
double count_fqphi(int * num, int n, int total);
void count_pair(const string & b);
int main(){
    char c[26], a, cd[50];
    ifstream fin;
    string ff;
    int found=0, exist=0, ct[26], swi=0, total=0, ctd[50];
    for(int i=0; i<26; i++)
        ct[i]=0;
    fin.open("1.txt");
    while(fin.get(a)){
        found=0;
        if(isalpha(a)){
            ff+=a;
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
        cout<<i+1<<" "<<c[i]<<": "<<ct[i]<<endl;
        total+=ct[i];
    }
    cout<<count_fqphi(ct, exist, total)<<endl<<endl<<endl;
    count_pair(ff);

}
double count_fqpsi(int * num, int n, int total){
    double psi=0;
    for(int i=0; i<n; i++)
        psi=psi+(double(num[i])/total)*(double(num[i])/total);
    return psi;
}
double count_fqphi(int * num, int n, int total){
    double phi=0;
    for(int i=0; i<n; i++)
        phi=phi+(double(num[i])/total)*((double(num[i])/total)-(1./n));
    return phi;
}
void count_pair(const string & b){
    int tn=0;
    char c[650][2];
    int found=0, exist=0, ct[650]={0}, swi=0;
    for(int i=0; i<=b.length(); i+=2){
        tolower(b[i]);
        tolower(b[i+1]);
        found=0;
        if(isalpha(b[i])&&isalpha(b[i+1])){
            if(i==0){
                c[0][0]=b[0];
                c[0][1]=b[1];
                ct[0]++;
                exist=1;
            }
            else{
                for(int j=0; j<exist; j++){
                    if((c[j][0]==b[i])&&(c[j][1]==b[i+1])){
                        ct[j]++;
                        found=1;
                        break;
                    }
                }
                if(found==0){
                    //cout<<char(a)<<endl;
                    c[exist][0]=b[i];
                    c[exist][1]=b[i+1];
                    ct[exist]++;
                    exist++;
                }
            }
        }
    }
    for(int i=0; i<exist-1; i++){
        for(int j=0; j<exist-i-1; j++){
            if(ct[j]<ct[j+1]){
                swap(ct[j], ct[j+1]);
                swap(c[j][0], c[j+1][0]);
                swap(c[j][1], c[j+1][1]);
            }
        }
    }
    for(int i=0; i<exist; i++){
        cout<<i+1<<" "<<c[i][0]<<c[i][1]<<": "<<ct[i]<<endl;
    }
    /*for(int i=0; i<b.length();i++){
        if(i%2==0)
            cout<<" ";
        cout<<b[i];
    }*/
    double temp=0;
    for(int i=0; i<exist; i++)
        tn+=ct[i];
    temp=count_fqphi(ct, exist, tn);
    //cout<<"psi: "<<temp<<endl;
    //cout<<"phi: "<<count_fqphi(ct, exist, tn)<<endl;
    cout<<temp<<endl;
}
