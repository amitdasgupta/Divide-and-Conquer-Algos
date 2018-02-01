#include <iostream>
#include<queue>
using namespace std;
int fixedpoint(int *array,int start,int last)
{
    if(start>last)
        return INT_MIN;
    else
    {
        int mid=(start+last)/2;
        if(array[mid]==mid)
            return mid;
        else
            if(array[mid]<mid)
            return fixedpoint(array,mid+1,last);
        else
            return fixedpoint(array,start,mid-1);
    }
}
/******************find fixed point in an array*///////
int main()
{
    int n;
    cin>>n;
    int *array=new int[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    cout<<fixedpoint(array,0,n-1);
    delete[] array;
}
