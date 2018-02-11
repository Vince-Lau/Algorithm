#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>    
#include <stdio.h>  
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <stack>

using namespace std;

//递归 + 缓存的版本
class Solution {
public:
	//递归
	bool dfs(vector<int> &A,vector<int> & dp,int index){
		//结束条件
		if(index>=A.size()-1){
			return true;
		}

		if(dp[index]!=-1){
			if(dp[index]==1){
				return true;
			}
			if(dp[index]==0){
				return false;
			}
		}

		//减枝条件
		if(A[index]==0){
			return false;
		}

		int temp = A[index];

		bool res=false;
		//进入下一层递归
		//dfs(1) + dfs(2)+ ... + dfs(temp)
		for (int i=1;i<=temp;i++){
			res=res|dfs(A,dp,index+i);
		}
		dp[index]=res;
		return res;
	}

    bool canJump(vector<int> &A) {
		vector<int> dp(A.size(),-1);
		return dfs(A,dp,0);
	}
};




int main(int argc, char const *argv[])
{
	//int arr[]= {2,3,1,1,4};
	int arr[]={4,6,9,5,9,3,0};
	//int arr[]= {0,8,2,0,9};
	//int arr[]={4,3,4,10,0, 7,5,5,1,0, 5,7,7,9,6, 7,3,10,8,2};  //daan : true
	//int arr[]={1,0};  //true
	Solution s;
	const int len=7;
	vector<int> vi(arr,arr+len);
	cout<<s.canJump(vi);
	//


	return 0;
}