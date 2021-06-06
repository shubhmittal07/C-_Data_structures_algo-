THE valarray------------>

The next class that will be discussed is the valarray, which is a template class used
to hold a sequence of elements for fast mathematical operations. When fast math
operations are a must, the valarray might be a great choice over a vector. The
types used with a valarray must be able to have mathematical operations performed on them or the benefit is lost. The class is made up of a one-dimensional
“smart” array that checks the subscript references (by []) at runtime to ensure that
they are in bounds. When compared to a vector, the valarray is a near-container,
in that it does not fully support the features of a sequence container. One noticeable
difference is that there are no iterators with a valarray as there are with vector
classes.