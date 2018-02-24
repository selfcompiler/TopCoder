// https://community.topcoder.com/stat?c=problem_statement&pm=1259

#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;    
class ZigZag{
    public:
    int longestZigZag(vector <int> sequence){
        if(sequence.size()<=1)
            return sequence.size();
        int plus=0;
        int minus=1;
        int dp[55][2]={0};
        int prev[55][2]={-1};
        dp[0][plus]=1;
        dp[0][minus]=1;
        if(sequence[1]>sequence[0]){
           dp[1][plus]=2;
           prev[1][plus]=0; 
           dp[1][minus]=1; 
           prev[1][minus]=-1; 
        }else if(sequence[1]<sequence[0]){
             dp[1][plus]=1;
             dp[1][minus]=2; 
             prev[1][plus]=-1; 
             prev[1][minus]=0;
        } else if (sequence[1]==sequence[0]){
           dp[1][plus]=1;
           dp[1][minus]=1; 

        }
        for(int i=2;i<sequence.size();i++){
            dp[i][plus]=1;
            dp[i][minus]=1;
            prev[i][plus]=-1;
            prev[i][minus]=-1;
          //  cout<<"i="<<i<<"\n";
        	for(int j=i-1;j>=0;j--){
            	  if(sequence[i]>sequence[j]){
                       // cout<<"j= "<<j<<"\n";
                       // cout<<"i,plus = "<<dp[i][plus]<<" j,mius = "<<dp[j][minus]<<"\n";
                      int olvv=dp[i][plus];
                  		dp[i][plus]=max(dp[i][plus],1+dp[j][minus]);
                        if(olvv<(1+dp[j][minus])){
                       //     cout<<"bola";
                            prev[i][plus]=j;
                        }
                  }else if(sequence[i]<sequence[j]){
                      int oldv=dp[i][minus];
                   		dp[i][minus]=max(dp[i][minus],1+dp[j][plus]);
                        if(oldv<(1+dp[j][plus])){
                            prev[i][minus]=j;
                      //       cout<<"hola";
                        }
                  }
            }
        }
        int ans=0;
        int oldans=ans;
        int index=0;
        int orgy=-1;
        for(int i=1;i<sequence.size();i++){
                oldans=ans;
        	    ans=max(ans,max(dp[i][plus],dp[i][minus]));
                if(oldans<ans){
                   index=i;
                   if(dp[i][plus]>dp[i][minus]){
                   		orgy=plus;    
                   }else{
                        orgy=minus;    
                   }
                }
                
        }
      //  cout<<"i= index"<<index<<"\n";
        while(prev[index][orgy]!=-1){
        //	cout<<sequence[index]<<" ";
            index=prev[index][orgy];
            orgy=(orgy+1)%2;
        }
    	return ans;
    }
        
};
