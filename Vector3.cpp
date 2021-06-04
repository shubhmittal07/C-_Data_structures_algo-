//23-05-21 18:08
#include <iostream>
#include <assert.h>
#include <string.h>
#include <math.h>
#include <cmath>
//#define log(x) std::cout<<x<<std::endl;
class Vector3
{
private:
    float x,y,z;
public:
    float get_x() const {return x;}
    float get_y() const {return y;}
    float get_z() const {return z;}
    Vector3(int _x,int _y,int _z):x(_x),y(_y),z(_z){}
    Vector3 operator+(const Vector3& other) const
    {
        return Vector3(other.x+x,other.y+y,other.z+z);
    }
    Vector3 operator*(const Vector3& other) const
    {
        return Vector3(other.x*x,other.y*y,other.z*z);
    }
    Vector3 operator*(const float& num) const //multiplying with scalar
    {
        return Vector3(x*num,y*num,z*num);
    }
    float magnitude() 
    {
        return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
    }
    Vector3 Normalize()
    {
        float mag = sqrt(pow(x,2)+pow(y,2)+pow(z,2));
        return Vector3(x/mag,y/mag,z/mag); 
    }
    float angle_between(Vector3& other)
    {
        return (other.x*x+other.y*y+other.z*z)/(magnitude()*other.magnitude());
    }
    float dotProduct(Vector3& other)
    {
        return other.x*x+other.y*y+other.z*z;
    }
    
};
std::ostream& operator<<(std::ostream& stream , const Vector3& other)
{
    stream << "x: "<<other.get_x()<<" "<<"y: "<<other.get_y()<<" "<<"z: "<<other.get_z();
    return stream;
}

int main()
{
    Vector3 speed(1,2,3);
    Vector3 position(4,5,6);
    Vector3 result  = speed + position;
    Vector3 result2 = result*2;
    std::cout<<speed<<std::endl;
    std::cout<<position<<std::endl;
    std::cout<<result<<std::endl;
    std::cout<<result2<<std::endl;
    std::cout<<"Magnitude of vector2 is: "<<result2.magnitude()<<std::endl;
    std::cout<<"Normalized vector2 is: "<<result2.Normalize()<<std::endl;
    std::cout<<"Dot product of result1 and result2 is: "<< result.dotProduct(result2)<<std::endl;
    std::cout<<"Angle between result1 and result2 is: "<< result.angle_between(result2)<<std::endl;
    std::cin.get();
    return 0;
}


