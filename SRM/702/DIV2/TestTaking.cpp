#include<iostream>
using namespace std;
class TestTaking{
public:int findMax(int a,int b,int c){
return min(b,c)+min(a-b,a-c);
}
};
