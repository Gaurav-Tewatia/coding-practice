#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool possible(int h,vector<int>& piles,int mid){
        int count=0;
        for(int i=0;i<piles.size();i++){
            int eaten=mid;
            count++;
            if(count>h){
                return false;
            }
            
                while(eaten<piles[i]){
                    eaten+=mid;
                    count++;
                    if(count>h){
                        return false;
                    }
                }
            
        }
        return true;
    }
    int main() {
        vector<int> piles;
        piles.push_back(30);
        piles.push_back(11);
        piles.push_back(23);
        piles.push_back(4);
        piles.push_back(20);
        int s=1;
        int h=5;
        
        int e=*max_element(piles.begin(),piles.end());
        int ans=0;
        
        while(s<=e){
          int mid=(s+e)/2;
            if(possible(h,piles,mid)){
                ans=mid;
                e=mid-1;
            }
            else{
                s=mid+1;
            }
            
    }
        cout<<ans;
    }