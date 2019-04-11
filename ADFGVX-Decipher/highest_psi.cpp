//
//  main.cpp
//  ADFGVX1
//
//  Created by Hsiao-fan Kuo on 8/30/18.
//  Copyright © 2018 Hsiao-fan Kuo. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
void count_pair(const string & b, int * seq, int n);
void count_last(const string & b);
double count_fqpsi(int * num, int n, int total);
double count_fqphi(int * num, int n, int total);
string mostpsi;
string mostphi;
double mpsi=0;
double mphi=0;
int main(int argc, const char * argv[]) {
    int top=0;
    string a="xfggdaddxfaggxfvdgfavggxavvffvgxafafgvvfxavaafxvaavfavfaxvvavaagffaxafxgvdaafvavvvaafvgxdfaaavafdvxgvfvavavaafvgvxgfagvaavvfdavgdvagdfggdavgddfxdaggaaxvxgxvgfagfaavvxdaaffvvaggfxgxavxvgxadgavxgaffxgxvdavavfadgxgdaffdaaaavffaafaaafvvavgvaxvaaxavggdfaxvddgaxaagavfvxgfvaagavvdxfvggfffvgdavgaafvxgxvdfavfaavvaxagdavfdvvgvgaxaaxdxvaaavxvffvfxggdvvxgxgavxgfvfdvaavaaxvggvgxavgaavgaxxvgdvfgvdagxgdaxvvavaaavaadvggxvfavadfxggdfxxgvagdavaadvgfxvxafgdvaagvdxxafadgaagxaxfxdavvgvvvaaavxaxdxvaaavxvffvfxggdvvxgxgavxgfvfdvaavaaxvggxgv";
    //ifstream fin;
    //fin.open("adfgvx.encode.txt");
    //fin>>a;
    //cin>>a;
    int pn[10];
    for(int i=3; i<=10; i+=1){
        for(int j=0; j<i; j++){
            pn[j]=j;
            //cout<<pn[j];
        }
        //cout<<endl;
        do{
            /*for(int j=0; j<i; j++)
                cout<<pn[j];
            cout<<endl;*/
            //for(int k=0; k<i; k++)
                //cout<<pn[k];
            string aftera="";
            //cout<<a.length()<<endl;
            for(int x=0; x<a.length(); x+=i){
                if(x+i<a.length())
                    for(int y=0; y<i; y++){
                        aftera=aftera+a[pn[y]+x];
                        //cout<<pn[y]+x<<": "<<a[pn[y]+x]<<"\n";
                        //cout<<a[pn[y]+x]<<"\t";
                    }
                else
                    for(int y=x; y<a.length(); y++)
                        aftera+=a[y];
            }
            //cout<<aftera.length()<<endl;
            count_pair(aftera, pn, i);
            //cout<<aftera.length()<<endl;
            //modify the string here
            //cout<<endl;
            //cout<<pn[j];
        } while (next_permutation(pn,pn+i));
    }
    //ofstream fout;
    //fout.open("output_space.txt");
    //fout<<mostpsi;
    count_last(mostpsi);
    cout<<"The final outcome:\n";
    for(int i=0; i<mostpsi.length(); i++){
        if(i%2==0)
            cout<<" ";
        cout<<mostpsi[i];
    }
}
void count_pair(const string & b, int * seq, int n){
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
    /*for(int i=0; i<exist; i++){
        cout<<i+1<<" "<<c[i][0]<<c[i][1]<<": "<<ct[i]<<endl;
    }
    for(int i=0; i<b.length();i++){
        if(i%2==0)
            fout<<" ";
        fout<<b[i];
    }*/
    double temp=0;
    for(int i=0; i<exist; i++)
        tn+=ct[i];
    temp=count_fqpsi(ct, exist, tn);
    //cout<<"psi: "<<temp<<endl;
    //cout<<"phi: "<<count_fqphi(ct, exist, tn)<<endl;
    if(temp>mpsi){
        //cout<<b<<endl<<endl;
        cout<<"permutation: ";
        for(int a=0; a<n; a++)
            cout<<seq[a];
        cout<<endl;
        cout<<"current highest psi: "<<temp<<"\n\n";
        mpsi=temp;
        mostpsi=b;
    }
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
void count_last(const string & b){
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
    //cout<<"exist: "<<exist<<endl;
    for(int i=0; i<exist-1; i++){
        for(int j=0; j<exist-i-1; j++){
            if(ct[j]<ct[j+1]){
                swap(ct[j], ct[j+1]);
                swap(c[j][0], c[j+1][0]);
                swap(c[j][1], c[j+1][1]);
            }
        }
    }
    for(int i=0; i<exist; i++)
        cout<<i+1<<" "<<c[i][0]<<c[i][1]<<": "<<ct[i]<<endl;
}

