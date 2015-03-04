/**
 * Combination generation based on given index 
 * This function is especially useful for hashing unique indices
 * @author  Hanefi Mercan
 * @firstCommit 05/03/2015
 * @lastCommit  05/03/2015
 */


#include <iostream>
using namespace std;

int nChooseK(int n, int k) 
{
  /* Number of combinations of N choose K */
    if (k > n) 
		  return 0;
    if (k * 2 > n) 
	   	k = n-k;
    if (k == 0) 
	  	return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) 
	  {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}


void findCombBasedOnIndex(int *comb, int index, int numElements, int length)   
{
	/* Index based combination calculation */
	int tempIndex, t = 0;
	comb[0] = 0;
	for (; t < length-1; t++) 
	{
		tempIndex = nChooseK(numElements-comb[t]-1, length-t-1);
		while(index >= tempIndex)
		{
			index -= tempIndex;
			comb[t]++;
			tempIndex = (tempIndex*(numElements-comb[t]-length+t+1))  / (numElements-comb[t]);
		}
		comb[t+1] = comb[t] + 1;
	}
	comb[t] = comb[t-1] + index + 1;
}


int main() {
	
	int length = 3, numElements = 5;
	int *myArray = new int [length];
	int numTotalCombs = nChooseK(numElements, length);
	
	for(int j = 0; j < numTotalCombs; j++)
	{
		findCombBasedOnIndex(myArray, j, numElements, length);
		for(int i = 0; i < length; i++)
			cout << myArray[i] << " ";
		cout << endl;
	}
	return 0;
}
