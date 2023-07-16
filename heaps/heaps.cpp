#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class heap{

    vector<int> v;
    bool minheap;
    bool compare(int a, int b){
        if(minheap){
            return a<b;
        }
        else{
            return a>b;
        }
    }
       void heapfy(int idx){
            int left=2*idx;
            int right=left+1;
            int last=v.size()-1;
            int min_index=idx;

            if(left<=last and compare(v[left],v[idx])){
                min_index=left;
            }
            if(right<=last and compare(v[right],v[min_index])){
                min_index=right;
            }
            if(min_index!=idx){
            swap(v[min_index],v[idx]);
            heapfy(min_index);
            }
        }
    public:

    heap(int default_size=10 ,bool type=true){
        v.reserve(default_size);
        v.push_back(-1);
        minheap=type;

    }

    void push(int data){
        v.push_back(data);
        int index=v.size()-1;
        int parent=index/2;
        while(index>1 and compare(v[index],v[parent])){
            swap(v[index],v[parent]);
            index=parent;
            parent=parent/2;
        }
    }

    int top(){
        return v[1];
    }

    void pop(){

        int last=v.size()-1;
        swap(v[1],v[last]);
        v.pop_back();
        heapfy(1);
    }

    bool empty(){
        return v.size()==1;
    }
};
int main(){
    heap h;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        h.push(t);
    }

    while(!h.empty()){
        cout<<h.top()<<" ";
        h.pop();
    }
    return 0;
}