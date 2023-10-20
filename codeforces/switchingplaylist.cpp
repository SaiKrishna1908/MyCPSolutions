#include <iostream>

using namespace std;


class stack {

  string *s;
  int top;
  int capacity;


  public:
  stack(int size);
  ~stack();

  void push(string s);
  string pop();
  string peek();

  bool isEmpty();
  
};


stack::stack(int size){
  s = new string[size];
  capacity = size;
  top = -1;
}
stack::~stack(){
  delete[] s;
}

void stack::push(string element){

  s[++top] = element;
}

string stack::pop(){

  return s[top--];
}

string stack::peek(){

  if(!isEmpty()) {
    return s[top];
  }
  
  return "";
}

bool stack::isEmpty(){

  
  return top==-1;
}
       

   

int main() {

  int n;

  cin >> n ;

  string s[n];

  for(int i=0;i<n;++i){

    cin >> s[i];
  }

  stack st(n);


  for(int i=n-1;i>=0;--i){
    st.push(s[i]);
  }

  for(int i=0;i<n;++i){
    cout<< st.pop() << "\n";
  }

}

