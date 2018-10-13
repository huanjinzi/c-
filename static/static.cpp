#include<iostream>
using namespace std;
void func();

int main()
{
    /* code */
    for(size_t i = 0; i < 5; i++)
    {
        /* code */
        func();
    }
    return 0;
}

void func(){
    static int i = 5;
    i++;

    cout << "i = " << i << endl;
}
