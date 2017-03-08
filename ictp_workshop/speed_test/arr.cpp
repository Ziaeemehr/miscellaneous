#include <iostream>
#include <array>

using namespace std;

int main()
{
  const int N=10;
  array<int,3> myarray {10,20,30};
  array<array<int, N>, N>  A;
  
  for (int i=0; i<myarray.size(); ++i)
    ++myarray[i];
  for (int elem : myarray)
    cout << elem << '\n';
  
  for(int i=0; i<N; i++)
      for (int j=0; j<N; j++)
          A[i][j] = i+j;

  for(int i=0; i<N; i++)
      for (int j=0; j<N; j++)
          cout << A[i][j]<<endl;
}