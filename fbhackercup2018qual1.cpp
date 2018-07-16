//
//  main.cpp
//  testfbhcup
//
//  Created by Cuxxie on 16/07/18.
//  Copyright © 2018 cuxxie. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    int t;
    long long n,k,v;
    vector<string> strArray;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>n;
        cin>>k;
        cin>>v;
        strArray.clear();
        for(int j=0;j<n;j++){
            string temp;
            cin>>temp;
            strArray.push_back(temp);
        }
        long long prevVisit = v - 1;
        long long temp = ((k % n) * (prevVisit % n)) % n;
        vector<int> result;
        cout<<"Case #"<<i+1<<": ";
        while(k > 0){
            k--;
            result.push_back((int)temp);
            temp++;
            if(temp == n) temp = 0;
        }
        sort(result.begin(),result.end());
        for(int j=0;j<result.size();j++){
            string value = strArray[result[j]];
            cout<<value;
            if(j < result.size() - 1) cout<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
