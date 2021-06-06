#Vector Notes

1)Syntax-> std::vector<type> name;

2)Object type reference .vs. Pointer type reference---->

-> Basically object type vertex is more optimal as it store data in line,
as compared to pointer type data, which scatters data on heap,
which makes it a bit slow for iterating through the vertex.

-> vector.reserve()-- is used to set the capacity of the vector
-> Size of a vector -- is number of elements it contains.
-> Capacity of a vector is -- how many elements it can store.

Tips for using vector-->

Tip 1------->
Unless there is a reason not to, you should always use vector classes with user-defined classes or even class pointers. This is suggested because with traditional arrays,
if you were to do the following,

    SomeClass someArray[100];

100 constructors, one for each object, would be executed. If those constructors
have special needs, such as large and expensive memory allocation, this can be not
only a performance bottleneck but also a waste of time if not all elements are to be
used. The same can be said for dynamic arrays. Use the following instead:
    vector<SomeClass> someVec;
    someVec.reserve(100);

No constructors are executed and, assuming you know you need at least 100 elements, the container will be ready to store at least 100 objects.

Tip 2-------------->
Use reserve() to avoid unnecessary reallocations whenever possible. If you know
the minimum or even maximum number of elements your container will use, using
reserve() can avoid or minimize the number of reallocations the container will
need to perform. Depending on the application, the savings can add up and prove
to be beneficial.

Tip 3------------->
Avoid using vector<bool>. Because of the nature of Booleans used with the vector
container, they cannot be used to create true containers. The container will attempt
to use bit fields instead of bools to save space, and it uses proxy classes instead of
references with the [] operator. A container of bools can’t be created because the
following won’t compile 
        vector<bool> array;
        bool *ptr = &array[0];

The above won’t compile because what is returned is a proxy class and not a
reference to a Boolean. An alternative to using vector<bool> is to use an STL 
bitset, which we’ll discuss later in this chapter.
For some compilers, if you do not specify a copy constructor and a copy assignment
operator for containers that need them, the compiler will attempt to create them for
you. This code creation can happen without your knowledge at compile time for
your user-defined classes whenever the compiler can step in and do so.

Tip 4------------->

Manually delete pointers of new-ed memory that was stored in a container, because
the container will not delete that memory for you. When a container is destroyed,
so are the elements in the container. Unfortunately, although the elements are
destroyed, their destructors are not called when working with pointers because
they did not use the delete keyword. Deleting memory is the responsibility of the
programmer, not the containers. Because of this, if you don’t delete dynamically
allocated objects that were placed in a container, you will have a memory leak. This
happens because what was pushed onto the container is a copy of the pointer.
There is no way for the container to know that it has pointers to dynamically allocate memory, and even if it knew that, it would have no way of knowing if it was
free to delete that memory, because other pointers can still be using it

Tip 5
Hold off from creating a container until the last possible moment. Containers such
as vector allocate memory upon construction. Because of this, there can be a
wasted construction in many cases where the container was not used. For example,
void SomeFunc(SomeClass *ptr)
{
vector<AnotherClass> exampleVec;
if(ptr == NULL)
return;
// ... INSERT CODE HERE ...
}
Because the code in the previous example has a condition that could cause the
container to never be used, it is a waste to declare the container in such situations.
A better solution would be the following:

            void SomeFunc(SomeClass *ptr)
            {
            if(ptr == NULL)
            return;
            vector<AnotherClass> exampleVec;
            // ... INSERT CODE HERE ...
            }

C++ gives programmers the freedom to declare objects and variables anywhere
they want as long as it is in scope and is declared before it is used. Therefore, C++
programmers should take advantage of this feature, unlike C programmers.
Trick 1
The following can be used to clear a vector by swapping the contents in an empty
vector (by calling the constructor) with one you want to clear:
            vector<int> vec;
            vector<int>().swap(vec);
The same trick can be used to trim a vector with excess space by doing the
following:

            vector<int> vec;
            vector<int>(vec.begin(), vec.end()).swap(vec);

