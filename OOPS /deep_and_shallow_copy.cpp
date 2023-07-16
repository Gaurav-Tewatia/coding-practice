#include<iostream>
#include<string>

using namespace std;
class car{
private:
    float price;
public:
    int model;
    char *name;              //remember here we are declaring a pointer of char type not the char variable itself
                 
    car(){
        cout<<"constructor is called";
    }
    car(float p, int m, char *n){
        cout<<"paramaterized constructor is called";
        price=p;
        model=m;
        name=new char[strlen(n)+1];        //first we assign the poiter to a dynamically created array 
        strcpy(name,n);                     //Then we copy the item in that dynamically created array
    }
    car(car &x):price(x.price){
        cout<<"copy constructor is called";
        price=x.price;
        model=x.model;
        name= new char[strlen(x.name)+1];   //we create a different dynamically createdd array and then copy the item of previous object in it
        strcpy(name,x.name);                //this is called deep copying because if we hadn't done this it would have created problem in the future
    }                               //if we would have simply done strcpy(name,x.name) it would have simply start pointing toward the same dynamic array that we have previously created in paramaterized constructor
    
     void operator=(car &x){            //this is copy assignment operator
            cout<<"copy assignment operator";
            price=x.price;
            model=x.model;
            name=new char[strlen(x.name)+1];        //this also has the same concept of shallow and deep copy that's why we have done this
            strcpy(name,x.name);
     }
     void print(){
        cout<<"price "<<price<<endl;
        cout<<"model "<<model<<endl;
        cout<<"name "<<name<<endl;
     }

    ~car(){
        cout<<"car is destroyed "<<name<<endl;
        if(name!=NULL){             //used to delete data member which is a pointer
            delete [] name;
        }
    }

};
int main(){
    car c;
    car d(100,1,"BMW");
    cout<<endl;
    d.print();
    car e(d);
    e.name[0]='A';      //if we do this and hadn't created a deep copy then the values of d also would have change as then both the pointer would be pointing to the same dynamic array locaton
    e.print();
    car f;
    f=d;     //copy assignmet operator has been called   and it can be used many times unlike constructor which can be used only one time
    f.name[0]='T';
    f.print();
    //dynamically created car
    car *r=new car(400,3,"mercedes");   //creates a pointer of type car which points towards a parameterized dyanmically created car constructor
    //(*r).print();         work same as the below line
    r->print();
    delete r;                           //deletes the pointer of car type
    
    return 0;
}
