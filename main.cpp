#include <iostream>
#include<queue>
using namespace std;
/******************find fixed point in an array
int fixedpointInDuplicateAllowed(int *array,int start,int last)
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
*///////
/***********fixed point in an array in which duplicate is allowed*///////
int fixedPointDuplicate(int *array,int start,int last)
{
    if(start>last)
        return INT_MIN;
    else
    {
        int mid=(start+last)/2;
        if(array[mid]==mid)
            return mid;
        int left=min(array[mid],mid-1);
        int leftfind=fixedPointDuplicate(array,start,left);
        if(leftfind!=INT_MIN)
            return leftfind;
        int right=max(array[mid],mid+1);
        int rightfind=fixedPointDuplicate(array,right,last);
        return rightfind;
    }
}
int main()
{
    int n;
    cin>>n;
    int *array=new int[n];
    for(int i=0;i<n;i++)
        cin>>array[i];
    cout<<fixedPointDuplicate(array,0,n-1);
    delete[] array;
}
