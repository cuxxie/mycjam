#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <time.h>

#define LOG2(X) ((unsigned) (8*sizeof (unsigned long long) - __builtin_clzll((X)) - 1))
using namespace std;

void calculate(unsigned long long n, unsigned long long k, unsigned long long output[])
{
	unsigned long maxHeight = LOG2(k); // get the binary tree height
	unsigned long long baseNum = n>>(maxHeight); // get the base number of the leaf
	unsigned long long minKBase = pow(2,maxHeight); //get the Base of K (max power of 2 up to K)
	unsigned long long deltaK = k - minKBase; // get the left behind number e.g. K=17 baseK=16, delta = 1
	unsigned long long baseN = baseNum<<(maxHeight); //get the Base of N (used to get the bit which are taken from shift right)
	unsigned long long deltaN = n-baseN; // get the bit which are shifted right
	unsigned long long zeros = deltaN+1; // add +1
	
	if(deltaK<zeros) // if deltaK < the taken bit + 1, the baseNum is the large basenum
	{
		output[0]=baseNum>>1;
		if(baseNum%2==0 && output[0]>0)
			output[1] = output[0]-1;
		else
			output[1] = output[0];
	}
	else // else the baseNum is the lower base
	{
		baseNum--;
		output[0]=baseNum>>1;
		if(baseNum%2==0 && output[0]>0)
			output[1] = output[0]-1;
		else
			output[1] = output[0];
	}
}
    

int main() {
    unsigned long long t, n, k;
    unsigned long long output[2];
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        cin >> n >> k; 
		calculate(n,k,output);
        cout << "Case #" << i << ": "<< output[0] << " " << output[1]<<endl;
    }
    return 0;
}
