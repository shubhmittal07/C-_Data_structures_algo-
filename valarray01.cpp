#include <iostream>
#include <valarray>

void PrintValArray(const std::valarray<int> &valArray)
{
    std::cout << "Contents of valArray: ";
    for(int i = 0; i < 10; i++)
    {
    std::cout << valArray[i] << " ";
    }
    std::cout << std::endl << std::endl;
}
void sum(const std::valarray<int> &valArray)
{
    std::cout<<"The sum of valArray: "<<valArray.sum()<<std::endl;
}

int main(int args, char **argc)
{
    std::cout << "STL Val Array Example" << std::endl;
    std::cout << "Data Structures for Game Developers" << std::endl;
    std::cout << "Allen Sherrod" << std::endl << std::endl;
    std::valarray<int> valArray(10);
    std::valarray<int> valArray1;
    // Placing numbers 1 through 10 on for demonstration.
    for(int i = 0; i < 10; i++)
    {
    valArray[i] = i;
    }
    PrintValArray(valArray);

    std::valarray<int>::value_type rVal = 5;
    valArray *= rVal;// one way to manipulate elements of valarray

    valArray1 = valArray.apply([](int x){return x=x*5;});// another way to manipulate data

    PrintValArray(valArray);
    sum(valArray);
    PrintValArray(valArray1);
    sum(valArray1);
    return 1;
}