#include <iostream>
#include <string>
#include <vector>
#include <numeric>
struct Vertex
{
    int x,y,z;
};

std::ostream& operator<<(std::ostream& stream,const Vertex& vertex)
{
    stream<<vertex.x<<" , "<<vertex.y<<" , "<<vertex.z;
    return stream;
}
int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back({1,2,3});
    vertices.push_back({4,5,6});
    //std::vector<Vertex> vertices3(5);//create a vector of size 5
    std::vector<Vertex> vertices2(vertices); //copy constructor for vector
    std::vector<Vertex> vertices4(vertices.begin(),vertices.end());//create a new vector containing elements of vertices vector
    std::cout<<vertices.front()<<std::endl;// prints the first element of the vector
    for(Vertex& v:vertices)
    {
        std::cout<<v<<std::endl;
    }
    for(Vertex& v:vertices2)
    {
        std::cout<<v<<std::endl;
    }
    for(Vertex& v:vertices4)
    {
        std::cout<<v<<std::endl;
    }
    vertices.erase(vertices.begin()); //code to remove second element
    std::cout<<"Capacity: "<<vertices.capacity()<<std::endl;
    return 0;
}