#include<iostream>
#include<vector>
using namespace std;
bool minheap=false;
bool compare(int a, int b){
        if(minheap){
            return a<b;
        }
        else{
            return a>b;
        }
    }

 void heapfy(vector<int> &v,int idx,int size){
            int left=2*idx;
            int right=left+1;
            int last=size-1;
            int min_index=idx;

            if(left<=last and compare(v[left],v[idx])){
                min_index=left;
            }
            if(right<=last and compare(v[right],v[min_index])){
                min_index=right;
            }
            if(min_index!=idx){
            swap(v[min_index],v[idx]);
            heapfy(v,min_index,size);
            }
        }

void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}

void buildheapoptimise(vector<int> &v){
    int idx=((v.size()-1)/2);
    for(int i=idx;i>=1;i--){
        heapfy(v,i,v.size());
    }
}

int main(){
    vector<int> v;
    v.push_back(-1);
    v.push_back(10);
    v.push_back(20);
    v.push_back(5);
    v.push_back(6);
    v.push_back(1);
    v.push_back(8);
    v.push_back(9);
    v.push_back(4);
    print(v);
    cout<<endl;
    buildheapoptimise(v);
    print(v);
    return 0;
}