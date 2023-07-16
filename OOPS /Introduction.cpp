Introduction

1 constructor
  - that is responsible for creating an object
  - gets called automatically and only once
  - same name as class name
  - parameterized constructor
  - constructor overloading

2 Copy constructor
  - make a copy of the given object
  - exist by default
  - when you need define your own copy constructor(in the case of dynamically created data member)
  - shallow copy
  - you have make your own copy constructor if a deep copy is needed

3  Copy Assignment Operator
  - copies when you do assignment
  - car d=c;
  - car d;
  - d=c;
  - you can write your own copy assignment operator to make a deep copy
  - can be called many times

4  Destructor
  - clear out the memory occupied by the object
  - automatically get called when the object goes out of scope
  - explicitly needs to delete a data member if it is a pointer (dyamically created)
  - ecplicity needs to delted a object that is dynamically created
  - eg:- car *e=car(paramaterized constructor);
  - then you to delte it explicitly delete e;