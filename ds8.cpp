//Priority Queue

#include<bits/stdc++.h>
using namespace std;

// C++ creates max heap by default for priority queue
void showpq(priority_queue<int>pq){
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<"\n";
}

// C++ program to demonstrate min heap
void show_min_pq(priority_queue<int,vector<int>,greater<int> >pq1){
     while(!pq1.empty()){
        cout<<pq1.top()<<" ";
        pq1.pop();
    }
    cout<<"\n";
}

int main()
{
  priority_queue<int>pq;
  pq.push(21);
  pq.push(22);
  pq.push(31);
  pq.push(43);
  pq.push(27);
  cout<<pq.size()<<"\n";
  cout<<pq.top()<<"\n";
showpq(pq);

// min heap
priority_queue<int,vector<int>,greater<int> >pq1 ;
  pq1.push(21);
  pq1.push(22);
  pq1.push(31);
  pq1.push(43);
  pq1.push(27);

  cout<<pq1.size()<<"\n";
  cout<<pq1.top()<<"\n";
  show_min_pq(pq1);
}