Problem Statement :

Consider an n - element array, a, where each index i in the array a contains a reference to an array of  Ki integers (where the value Ki of varies from array to array). See the Explanation section below for a diagram.

Given a , you must answer q queries. Each query is in the format i j, where i denotes an index in array  a and j denotes an index in the array located at a[i] . For each query, find and print the value of element  j in the array at location a[i] on a new line.

Input Format

The first line contains two space-separated integers denoting the respective values of n (the number of variable-length arrays) and q (the number of queries). 

Each line i of n the subsequent lines contains a space-separated sequence in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i]. 

Each of the q subsequent lines contains two space-separated integers describing the respective values of i (an index in array ) and j (an index in the array referenced by a[i] ) for a query.

Constraints

1 <= n <= 10^5
1 <= q <= 10^5
1 <= k  <= 3 * 10^5
0 <= i  < n
0 <= j  < k

All indices in this challenge are zero-based.
All the given numbers are non negative and are not greater than  10^6.

Output Format

For each pair of i and j values (i.e., for each query), print a single integer that denotes the element located at index j of the array referenced by a[ i ]. There should be a total of q lines of output.

Code:

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


int main() {
    int n, q,i;
cin>>n>>q;
string temp;
vector<string> hrml;
vector<string> quer;
cin.ignore();
for(i=0;i<n;i++)
{
    getline(cin,temp);
    hrml.push_back(temp);
}
for(i=0;i<q;i++)
{
    getline(cin,temp);
    quer.push_back(temp);
}
map<string, string> m;
vector<string> tag;
for(i=0;i<n;i++)
{
    temp=hrml[i];
    temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end());
    temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());
    if(temp.substr(0,2)=="</")
    {
        tag.pop_back();
    }
    else
    {
        stringstream ss;
        ss.str("");
        ss<<temp;
        string t1,p1,v1;
        char ch;
        ss>>ch>>t1>>p1>>ch>>v1;
        string temp1="";
        if(tag.size()>0)
        {
            temp1=*tag.rbegin();
            temp1=temp1+"."+t1;
        }
        else
            temp1=t1;
        tag.push_back(temp1);
        m[*tag.rbegin()+"~"+p1]=v1;
        while(ss)
        {
            ss>>p1>>ch>>v1;
            m[*tag.rbegin()+"~"+p1]=v1;
        }
    }
}
for(i=0;i<q;i++){
    if (m.find(quer[i]) == m.end())
        cout << "Not Found!\n";
    else
        cout<<m[quer[i]]<<endl;
}
    return 0;
}
