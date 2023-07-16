#include<iostream>
#include<list>
using namespace std;

int main(){
    list<int> l;  //declaration of list also known as double linked list
    list<int> l2;
    l2.push_back(1);        //push or add at the end of the list
    l2.push_back(2);
    l2.push_back(3);
    l2.push_back(4);
    l2.push_back(5);
    cout<<l2.front();       //shows the first element of the list
    l2.push_front(0);           //add at the head of the list
    for(int it:l2){
        cout<<it<<"-->";
    }
    cout<<endl;
    list<string> l3;
    l3.push_back("oranges");
    l3.push_back("apple");
    l3.push_back("mangoes");
    l3.push_back("kiwi");
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    l3.push_back("lichi");
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl; 
    l3.pop_back();              //delete from the end of the list
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    l3.sort();              //sort the list in the   lexiographically order
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    l3.reverse();           //sort in the reverse lexiographically order
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    l3.push_back("apple");
    string f="apple";
    l3.remove(f);                       //remove all the occurence of the string apple
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    l3.push_back("strawberry");

    l3.push_back("pineapple");
    l3.push_back("dragonfruit");
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    auto it=l3.begin();
    it++;                       //use to move forward by one node in the list
    it++;
    l3.erase(it);                       //delete that particular node at it
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;

    it=l3.begin();
    it++;
    it++;
    l3.insert(it,"guava");                      //insert a new node at that particular it
    for(auto it=l3.begin();it!=l3.end();it++){
        cout<<(*it)<<" ";

    }
    cout<<endl;
    return 0;
}
