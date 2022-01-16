#include <bits/stdc++.h>

using namespace std;


typedef  pair<int,int> pii;

const int N=105;
int t,n,cnt;
char s[N];

template<typename T, size_t DIM> 
struct vec {
  private:
    T data[DIM];  // store raw coordinates in this array

  public:
    vec() {
      for(size_t i=DIM;i--;data[i]= T());
    }

    T getData(unsigned int i=0) {
      return data[i];
    }

    T& operator[](const size_t i) {
      assert(i < DIM);
      return data[i];
    }
};

// Vector with 2 dimensions

template<typename T>
struct vec<T, 2> {

private:

  T data[2];

public:

  T x,y;

  vec() : x(T()), y(T()) {} // these are initializers 
  vec(T X, T Y): x(X), y(Y) {
    data[0] = x;
    data[1] = y;
  }

  T getData(unsigned int i =0) {
    return data[i];
  }

  T& operator[] (const size_t i) {
    assert(i < 2);
    return data[i];
  }

};

// Vector with 3 dimensions

template<typename T> 
struct vec<T, 3> {
private:
  T data[3];

public:
  T x,y,z;

  vec() : x(T()), y(T()), z(T()) {}
  vec(T X,T Y, T Z) : x(T(X)), y(T(Y)), z(T(Z)) {
    data[0] = X;
    data[1] = Y;
    data[2] = Z;
  }

  T& operator[] (const size_t i) {
    assert(i<3);
    return data[i];
  }

  const T& operator[] (const size_t i) const {
    assert(i < 3);
    return i==0 ? x : (i == 1)? y : z;
  }

  T getData(const unsigned int i) {
    assert(i<3);
    return data[i];
  }

  float norm() {return std::sqrt(x*x + y*y + z*z);}
  vec<T, 3>& normalize(T l = 1) 
  {
    *this = (*this) * (l/norm());
    return *this;
  }
};

// operator overloading << for vec

template<typename T, size_t DIM>
ostream& operator<<(ostream& os,vec<T, DIM>& v) {
  os<<"(";
  for(int i=0;i<DIM;i++) {        
    os<<v.getData(i)<<",";
  }
  os<<")"<<endl;

  return os;
}

// operator overloading << for vec2 

template<typename T>
ostream& operator<<(ostream& os,vec<T, 2>& v) {
  os<<"(";
  for(int i=0;i<2;i++) {        
    os<<v.getData(i)<<",";
  }
  os<<")"<<endl;

  return os;
}

// operator oerloading << for vec3

template<typename T>
ostream& operator<<(ostream& os, vec<T,3> &v) {
  os<<"(";
  for(int i=0;i<3;i++) {
    os<<v.getData(i)<<",";
  }
  os<<")"<<endl;

  return os;
}


// operator overloading * for vec3

template<size_t DIM,typename T, typename U>
vec<T,DIM> operator*(vec<T,DIM> lhs,const U &rhs) {
  for(size_t i = DIM;i--;lhs[i] *= rhs);

  return lhs;
} 



void templates() {

  vec<float, 3> vec3f(2,3,5);
  vec3f.normalize();
  cout<<vec3f<<flush;
  // cout<<vec3f<<flush;
  // vec<int, 2> vec2i(3,5);
  // cout<<vec2i<<flush;

  // vec2i[0] = 23;
  // cout<<vec3f[0]<<flush;
  // cout<<vec2i[0]<<flush;
}


int main(int argc, char *argv[])
{

  int a[] = {4,5,6};
  int (&ar)[3] = a;

  int b = int(3);

  templates();
  return 0;
}
