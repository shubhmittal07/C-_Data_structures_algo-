#include <iostream>

class Array
{
private:
    int *m_arr;
    int m_size;
public:
    Array(int size):m_size(0),m_arr(NULL)
    {
        if(m_arr == NULL)
        {
            m_size = size;
            m_arr = new int[size];
        }
        else
        {
            std::cout<<"Array already initialised"<<std::endl;
        }
    }
    void Display() const
    {
        for(int i=0;i<m_size;i++)
        {
            std::cout<<m_arr[i]<<",";
        }
        std::cout<<std::endl;
    }
    void setArr() const
    {
        for(int i=0;i<m_size;i++)
        {
            std::cin>>m_arr[i];
        }
    }
    void insert(int element)
    {
        m_size++;
        m_arr[m_size-1] = element;
    }
    int BinarySearch(int element)
    {
        int lower_bound=0,upper_bound=m_size-1;
        int middle_bound;
        while(lower_bound<=upper_bound)
        {
            middle_bound = (lower_bound+upper_bound)/2;
            if(element==m_arr[middle_bound])
            {
                std::cout<<"Element found at index: "<<middle_bound<<std::endl;
                return middle_bound;
            }
            else if(element>m_arr[middle_bound])
            {
                lower_bound = middle_bound+1;
            }
            else
            {
                upper_bound = middle_bound-1;
            }
        }
        std::cout<<"Element not found";
        return -1;
        
    }
    ~Array()
    {
        if(m_arr!=NULL)
        {
            delete[] m_arr;
            m_size = 0;
            m_arr = NULL;
            std::cout<<"Array deletion:Successful"<<std::endl;
        }
        else
        {
            std::cout<<"Array already deleted"<<std::endl;
        }
    }

};
int main()
{
    Array arr(5);
    arr.setArr();
    arr.Display();
    arr.insert(6);
    arr.Display();
    arr.BinarySearch(5);

}