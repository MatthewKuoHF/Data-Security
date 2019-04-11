#include<iostream>
#include<cctype>
#include<fstream>
using namespace std;
int main(){
    string ifile, ofile;
    //cout<<int('w')-int('e');
    int num=0;
    cout<<"Enter the name of the file you want to open: ";
    cin>>ifile;
    cout<<"Enter the key: ";
    cin>>num;
    ifstream fin;
    fin.open(ifile.c_str());
    cout<<"Enter the name of the output file: ";
    cin>>ofile;
    ofstream fout;
    fout.open(ofile.c_str());
    char a;
    while(fin.get(a)){
        //cout<<int(a)<<endl;
        if(isalpha(a)){
            a=tolower(a);
            if((int(a)+num)>122)
                a=int(a)-26;
            else if((int(a)+num)<97)
                a=int(a)+26;
            fout<<char(int(a)+num);
            //cout<<char(int(a)+num);
        }
        else{
            fout<<a;
            //cout<<a;
        }
    }
}
