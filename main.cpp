#include <iostream>
#include <test.h>
#include <heap.h>
using namespace std;

int main()
{
   Heap heap;
   heap.push(3);
   heap.push(2);
   heap.push(15);
   heap.push(60);
   cout<<"Size is"<< heap.size()<<"\n";

   cout<<heap.top() << " ";
   heap.pop();

   cout<<heap.top() << " ";
   heap.pop();

   heap.push(5);
   heap.push(4);
   heap.push(45);
   cout<<"\n"<<"Size is "<<heap.size()<<"\n";

   cout<<heap.top() << " ";
   heap.pop();
   cout<<heap.top() << " ";
   heap.pop();
   cout<<heap.top() << " ";
   heap.pop();
   cout<<heap.top() << " ";
   heap.pop();
}
