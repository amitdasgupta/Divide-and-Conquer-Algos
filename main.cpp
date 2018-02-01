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
/***********fixed point in an array in which duplicate is allowed
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
*///////
int median(int *array1,int *array2,int n)
{
    int count=0,val1,val2,i=0,j=0,temp;
    while(count<=n)
    {
        if(array1[i]>array2[j])
              {
                   temp=array2[j];
                   j++;
              }
        else
               {
                   temp=array1[i];
                   i++;
               }
        if(count==n-1)
            val1=temp;
        else
            if(count==n)
             val2=temp;
        count++;
    }
    return (val1+val2)/2;
}
int main()
{
   int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45};
    int n=sizeof(ar1)/sizeof(ar1[0]);
    cout<<median(ar1,ar2,n);
}
