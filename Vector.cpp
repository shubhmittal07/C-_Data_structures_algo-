#include <iostream>
#include <string>
#include <vector>
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
    std::vector<Vertex> vertices2(vertices); //copy constructor for vector
    for(Vertex& v:vertices)
    {
        std::cout<<v<<std::endl;
    }
    for(Vertex& v:vertices2)
    {
        std::cout<<v<<std::endl;
    }
    vertices.erase(vertices.begin()); //code to remove second element
    std::cout<<"Capacity: "<<vertices.capacity()<<std::endl;
    return 0;
}