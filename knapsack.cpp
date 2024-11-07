// /******************************************************************************

//                               Online C++ Compiler.
//               Code, Compile, Run and Debug C++ program online.
// Write your code in this editor and press "Run" button to compile and execute it.

// *******************************************************************************/

#include <bits/stdc++.h>
using namespace std;


int knapsack ( vector<int> &weights, vector<int> &prizes,int capacity,int ind, vector<vector<int>> &dp){
    if(ind >= weights.size()) return 0;
    
    if(dp[ind][capacity] != -1) return dp[ind][capacity]; 
    int pick = 0, notpick = knapsack(weights,prizes,capacity,ind + 1,dp);
    if(weights[ind] <= capacity)
     pick = prizes[ind] + knapsack(weights,prizes,capacity - weights[ind],ind + 1,dp);
     
     return dp[ind][capacity] = max(pick,notpick);
     
}
int main()
{
  vector<int> weights = {2,3,5};
  vector<int> prizes = {30,40,60};
  int capacity = 6;
  vector<vector<int> > dp(3,vector<int> (7,-1));
  
  cout<<"max prize - "<<knapsack(weights,prizes,capacity,0,dp);
}
