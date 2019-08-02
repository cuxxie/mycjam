#include<iostream>
#include<string.h>
#include <utility>
using namespace std;

void printAns(int N, string S){
    /*pair<int,int> move;
    vector< pair <int,int> > lydiaMove;*/
    for(std::string::iterator it = S.begin(); it != S.end(); ++it) {
        char c = *it;
        if(c=='S')cout<<"E";
        else cout<<"S";
    }
    cout<<endl;
    
}

int main(){
    int T,N;
    string S;
    cin>>T;
    for(int i=1;i<=T;i++){
        cout<<"Case #"<<i<<": ";
        cin>>N;
        cin>>S;
        printAns(N,S);
    }
}
