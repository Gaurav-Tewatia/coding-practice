#include<iostream>
using namespace std;
//defining the car data type which hold two int data types and one character array of size 20
class car{
    private:        //cannot be accessed outside the class
    float price;
    public:         //can be accessed outside the class
    car(){                                      //function having the same name as class is called constructor
        cout<<"constructor is called ";            //they are always present there are are automatically called
    }                                              //they are nothing but just an empty function which do nothing
    car(float p,int m, char*n){                 //here we have explicityly called an constructor to use it for initialization
        cout<<"paramaterized constructor is called";
        price=p;                               //this type of constructor are called paramaterized constructor
        model=m;                                //calling multiple constructor is called constructor overloading
        strcpy(name,n);
    }
    car(car &x){     
        cout<<"this a copy constructor ";               //this is a copy constructor
        price=x.price;
        model=x.model;
        strcpy(name,x.name);
    }
    int model;
    char name[20];
    
    void print(){
        cout<<"model "<<model<<endl;
        cout<<"price "<<price<<endl;
        cout<<"name "<<name<<endl;

    }
    float get_discount(float x){
        return price*(1-x);
    }
    void apply_discount(float x){
        price=price*(1-x);
        
    }
    void set_price(int x){          //these are called setters
        price=x;
        cout<<endl;
    }
    void get_price(){               //these are called the getters
        cout<<price;
    }
};

int main(){
    //car c[2];       //remember car is the data type it does it hold a space in the memory however the c is an object of car data type it holds a space in the mermory which is 28
    car a,d(400,2,"audi");      //constructor is automatically called whenecer a class object is called or created;
    cout<<endl;
    cout<<" car D"<<endl;
    d.print();
    car e(d);
    cout<<"car E"<<endl;
    e.print();
    car f=e;
    cout<<"car F"<<endl;
    f.print();

    
    
    a.model=1;
    a.set_price(102);
    a.get_price();
    cout<<endl;
    a.name[0]='B';
    a.name[1]='M';
    a.name[2]='W';
    a.name[3]='\0';
    cout<<"model "<<a.model<<" "<<"name "<<a.name<<endl;
    cout<<"enter the discount you want to check ";
    float n;
    cin>>n;
    cout<<endl;
    cout<<a.get_discount(n);
    cout<<endl<<"want to apply the discount (y)"<<endl;
    char ch;
    cin>>ch;
    if(ch=='y'){
        a.apply_discount(n);
        cout<<endl;
    }
    else{
        cout<<"discount not applied"<<endl;
    }
   a.print();

    

    

    return 0;
}