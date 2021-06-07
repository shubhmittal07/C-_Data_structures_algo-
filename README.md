BIT ARRAYS


The next class that will be discussed is the manual bit array class. A bit is oneeighth of a byte. Since there are no data types smaller than a char (byte) in C++, we
have to use bit-wise operators to access and manipulate individual bits of a byte.
There are many benefits to using arrays of bits. The first benefit is storage. For
every one char, we have eight bits. In situations in which boolean values are needed,
this 8:1 compaction can be very beneficial for a large number of bits. Also, bit-wise
operators are very fast, and working with them is efficient. Later we will use arrays
of bits for various algorithms, with one example being compression.