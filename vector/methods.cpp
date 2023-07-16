#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> d;
    d.push_back(1);     //start inserting element from backside
    d.push_back(2);
    d.push_back(3);
    d.push_back(4);
    cout<<d.size()<<endl;           //gives the size of vector
    d.pop_back();                   //deletes the last element
    cout<<d.size()<<endl;
    d.insert(d.begin()+2,20);       //insert an elemtn in the middle
    for(auto v:d){
        cout<<v<<",";
    }
    cout<<endl;
    d.insert(d.begin()+3,3,30);
    for(auto v:d){
        cout<<v<<",";
    }
    cout<<endl;
    d.erase(d.begin()+2);               //erase an element from the middle
    for(auto v:d){
        cout<<v<<",";
    }
    cout<<endl;
    d.erase(d.begin()+3,d.begin()+6);       //erase a range of the element form the middle
    for(auto v:d){
        cout<<v<<",";
    }
    cout<<endl;
    cout<<d.size()<<endl;                   //gives the size of the vector (means how many element are present in the vector)
    cout<<d.capacity()<<endl;               //gives the capacity of the vector (means how much element it can hold)

    d.resize(10);                           //increases the size of the vector and includes zero's in the end also if capacity is lower than the resize the capacity also increases
    for(auto v:d){
        cout<<v<<",";
    }
    cout<<endl;
    cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;
    d.clear();                              //deletes all the element of the vector and makes the size zero but does not delete the memory of the vector means capacity remains unchanged
    if(d.empty()){                      //check if the vector is empty means no element is there in the vector
        cout<<"this is an empty vector"<<endl;
    }
     cout<<d.size()<<endl;
    cout<<d.capacity()<<endl;
     d.push_back(10);
    d.push_back(22);
    d.push_back(34);
    cout<<d.front()<<endl;              //shows the element which was first inserted in the vector 
    cout<<d.back()<<endl;               //shows the element which was last inserted in the vector
    vector<int> v;
    v.reserve(1000);                    //already grants a specific memory to the vector means fixed the capacity of the vector in the beginning itself this helps in time as the vector now don't have to keep doubling itself again and again it will only do so after the current capacity has been fulled
    cout<<v.size()<<endl;       //here size is zero
    cout<<v.capacity()<<endl;     //and capacity is already set to 1000
    
    



    return 0;
}