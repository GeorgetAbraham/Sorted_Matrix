#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<vector>
using namespace std;
int search(int r1,int r2,int c1,int c2,int key,vector<vector<int>> &A){
  int i,j;
  int z1,z2,z3;
  i=(r1+r2)/2;
  j=(c1+c2)/2;
  if(A[i][j]==key){
    cout<<"number found at "<<i<<" "<<j<<"\n";
    return key;
  }
  else{
    if(i==r1 && j==c1){
      for(int i=r1;i<=r2;i++){
        for(int j=c1;j<=c2;j++){
          if(A[i][j]==key){
            cout<<"number found at "<<i<<" "<<j<<"\n";
            return key;
          }
        }
      }
    }
    else{
      z1=search(r1,i,j,c2,key,A);
      if(z1!=-999)
      {
        return z1;
      }
    }
    if(A[i][j]<key){
      if(i<=r2-1){
        z2=search(i+1,r2,c1,j,key,A);
        if(z2==-999)
        {
          return search(i+1,r2,j,c2,key,A);
        }
        return z2;
      }
    }
    if(A[i][j]>key){
      if(j>=c1+1){
        z2=search(r1,i,c1,j-1,key,A);
        if(z2==-999)
        {
          return search(i,r2,c1,j-1,key,A);
        }
        return z2;
      }
    }
  }
  return -999;
}
vector<vector<int>> matrix_genarator(int n)
{
  vector<vector<int>> array(n);
  for(int i=0;i<n;i++)
  {
    array[i].resize(n);
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(i==0 && j==0)
      {
        array[i][j]=rand()%10;
      }
      else if(j==0)
      {
        array[i][j]=array[i-1][n-1]+rand()%10;
      }
      else
      {
        array[i][j]=array[i][j-1]+rand()%10;
      }
    }
  }
  return array;
}
void print_matrix(int n,vector<vector<int>> &array)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<array[i][j]<<"  ";
    }
    cout<<endl;
  }
}

int main(void){
  int n;
  cout<<"size of matrix to be genarated with random values"<<endl;
  cin >> n;
  vector<vector<int>> array(n);
  array=matrix_genarator(n);
  cout<<"press 1 to print matrix otherwise press 0"<<endl;
  int print;
  cin>>print;
  if(print==1)
  {
    print_matrix(n,array);
  }
  else
  {
    cout<<"enter the any coordinates to know the nmber in that position"<<endl;
    int x,y;
    cin>>x;
    cin>>y;
    cout<<endl<<"number at that position is "<<array[x][y]<<endl;
  }  
  int key;
  cout<<"enter the number to be searched"<<endl;
  cin>>key;
  cout<<endl;
  int ans;
  ans=search(0,n-1,0,n-1,key,array);
  if(ans==-999)
  {
    cout<<"number is not found";
  }
}
