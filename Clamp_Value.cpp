#include <iostream>

int Clamp(int value , int max,int min)
{
    value = (value<min)?min:value;
    value = (value>max)?max:value;
    return value;
}
int main()
{
    int clamp_value;
    int max_value=10,min_value=0;
    for(int i=0;i<100;i++)
    {
        clamp_value = i;
        clamp_value = Clamp(clamp_value,10,0);
        std::cout<<clamp_value<<" , ";
    }
}