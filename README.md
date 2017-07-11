# StanAlg

C++ implementation of various algorithms, developed while following the Stanford's ["Algorithms: Design and Analysis" course](https://lagunita.stanford.edu/courses/course-v1:Engineering+Algorithms1+SelfPaced/about) (by Tim Roughgarden).  

The code in `src` gets compiled to a library, while `src_app` contains source code of various command line tools for user interaction with the algorithms and reading data files. `spikes` includes miscellaneous programs for testing C++ features and the like ([inspired by Hiltmon](http://hiltmon.com/blog/2013/07/03/a-simple-c-plus-plus-project-structure/)).

Currently implemented algorithms:

 - merge sort
 - inversions counting
 - quick sort with counting compares

Examples of command line tools usage:

```
invcount -f /path/to/IntegerArray.txt

quicksort -f /path/to/QuickSort.txt --median
```
