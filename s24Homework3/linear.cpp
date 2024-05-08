//
//  linear.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/7/24.
//
// For this part of the homework, you will turn in one file named linear.cpp that contains the five functions and nothing more:
// no #include directives, no using namespace std;, no implementation of somePredicate and no main routine.

// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool allFalse(const string a[], int n)
{
    if(n <= 0)
        return true;
    if (somePredicate(a[0]))
        return false;
    return allFalse(a+1, n-1);
}

// Return the number of elements in the array for which the
// somePredicate function returns false.
int countFalse(const string a[], int n)
{
//    cerr << "Recursive call!" << endl;
    if(n <= 0)
        return 0;
    int count = !somePredicate(a[0]) + countFalse(a+1, n-1);
//    cerr << "value being returned: " << count << endl;
    return count;
}

// Return the subscript of the first element in the array for which
// the somePredicate function returns false.  If there is no such
// element, return -1.
int firstFalse(const string a[], int n)
{
    if (n <= 0)
        return -1;
    if(!somePredicate(a[0]))
        return 0;
//    int pos = 1 + firstFalse(a+1, n-1);
//    if (pos == 0) // this implies -1 was returned in and all the statements in somePredicate were true
//        return -1;
    int pos = firstFalse(a+1, n-1);
    if (pos != -1)
        return pos+1;
    return -1;
}

// Return the subscript of the greatest string in the array (i.e.,
// return the smallest subscript m such that a[m] >= a[k] for all
// k from 0 to n-1).  If the function is told that no strings are to
// be considered to be in the array, return -1.
int indexOfMax(const string a[], int n)
{
    if (n <= 0)
        return -1;
    if (n <= 1)
        return 0;
    
    int p = indexOfMax(a+1, n-1);
    if (a[0] >= a[p+1])
        return 0;
    else
        return p+1;
}

// If all n2 elements of a2 appear in the n1 element array a1, in
// the same order (though not necessarily consecutively), then
// return true; otherwise (i.e., if the array a1 does not include
// a2 as a not-necessarily-contiguous subsequence), return false.
// (Of course, if a2 is empty (i.e., n2 is 0), return true.)
// For example, if a1 is the 7 element array
//    "john" "amy" "ketanji" "sonia" "amy" "ketanji" "elena"
// then the function should return true if a2 is
//    "amy" "sonia" "elena"
// or
//    "amy" "ketanji" "ketanji"
// and it should return false if a2 is
//    "amy" "elena" "sonia"
// or
//    "john" "sonia" "sonia"
bool has(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)
        return true;
    if (n1 <= 0)
        return false;
    if (a1[0] == a2[0])
        return has(a1+1, n1-1, a2+1, n2-1);
    return has(a1+1, n1-1, a2, n2);
}

