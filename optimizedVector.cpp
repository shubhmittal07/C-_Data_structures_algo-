#include <iostream>
#include <string>
#include <vector>
#include <numeric>
struct Vertex
{
    
    int x,y,z;

    Vertex(int x,int y,int z)
        :x(x),y(y),z(z){}
    
    Vertex(const Vertex& v)
        :x(v.x),y(v.y),z(v.z)
    {
        std::cout<<"Copied!!"<<std::endl;
    }
};

std::ostream& operator<<(std::ostream& stream,const Vertex& vertex)
{
    stream<<vertex.x<<" , "<<vertex.y<<" , "<<vertex.z;
    return stream;
}
int main()
{
    std::vector<Vertex> vertices;
    vertices.push_back(Vertex(1,2,3));
    vertices.push_back(Vertex(4,5,6));
    vertices.push_back(Vertex(4,5,6));
    return 0;
}