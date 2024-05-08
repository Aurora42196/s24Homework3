//
//  linear.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/7/24.
//

#include <iostream>
#include <string>
using namespace std;

bool somePredicate(string s);

bool somePredicate(string s) // implementation of the predicate "s is empty"
{
    return s.empty();
}

//bool somePredicate(string s) // implementation of the predicate "s contains exactly 10 digits"
//{
//    int nDigits = 0;
//    for (int k = 0; k != s.size(); k++)
//    {
//        if (isdigit(s[k]))
//            nDigits++;
//    }
//    return nDigits == 10;
//}

// Return false if the somePredicate function returns true for at
// least one of the array elements; return true otherwise.
bool allFalse(const string a[], int n)
{
    if(n == 0)
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
    if(n == 0)
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
    if (n == 0)
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
    if (n == 0)
        return -1;
    if (n == 1)
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
    if (n2 == 0)
        return true;
    if (n1 == 0)
        return false;
    if (a1[0] == a2[0])
        return has(a1+1, n1-1, a2+1, n2-1);
    return has(a1+1, n1-1, a2, n2);  // This is not always correct.
}

//question 2 test cases
#include <iostream>
#include <string>
#include <cassert>

using namespace std;

//use:

/*
bool somePredicate(string s) {
    return s.empty();
}
*/

int main() {
    string a[] = { "", "35", "ufwu9fe", "", "bakersfield" };
    assert(!allFalse(a, 4));
    assert(allFalse(a, 0));
    assert(countFalse(a, 3) == 2);
    assert(firstFalse(a, 2) == 1);
    string b[] = { "a", "b", "c", "d" };
    assert(allFalse(b, 3));
    assert(countFalse(b, 3) == 3);
    assert(firstFalse(b, 2) == 0);
    string c[] = { "", "", "" };
    assert(firstFalse(c, 2) == -1);

    assert(indexOfMax(b, 0) == -1);
    assert(indexOfMax(b, 1) == 0);
    assert(indexOfMax(b, 2) == 1);
    assert(indexOfMax(b, 3) == 2);
    assert(indexOfMax(b, 4) == 3);
    string d[] = { "a", "c", "d" };
    assert(has(b, 4, d, 3));
    assert(!has(d, 3, b, 3));
    string e[] = {"b", "c", "d" };
    assert(!has(e, 3, b, 4));
    assert(has(b, 4, e, 3));

    string a1[] = { "a", "b", "c", "d", "c"};
    string a2[] = { "5", "7", "6", "1", "9", "2", "8"};
    string a2b[] = { "", "", "6", "", "9", "", "8" };
    string a3[] = { "A", "C", "", "D", "", "F", "H"};
    string a4[] = { "", "", "", ""};
    string a5[] = { "c", "c"};
    string a6[] = { "", ""};

    assert(allFalse(a1, 5) == true);
    assert(allFalse(a1, 2) == true);
    assert(allFalse(a2, 7) == true);
    assert(allFalse(a3, 7) == false);
    assert(allFalse(a3, 4) == false);
    assert(allFalse(a3, 2) == true);
    assert(allFalse(a4, 1) == false);
    assert(countFalse(a1, 5) == 5);
    assert(countFalse(a3, 7) == 5);
    assert(countFalse(a3, 4) == 3);
    assert(countFalse(a3, 2) == 2);
    assert(countFalse(a6, 2) == 0);
    assert(firstFalse(a1, 5) == 0);
    assert(firstFalse(a4, 4) == -1);
    assert(firstFalse(a2b, 7) == 2);
    assert(indexOfMax(a1, 5) == 3);
    assert(indexOfMax(a2, 7) == 4);
    assert(indexOfMax(a3, 6) == 5);
    assert(indexOfMax(a4, 4) == 0);
    assert(indexOfMax(a5, 2) == 0);
    assert(has(a1, 5, a5, 2));
    assert(!has(a2, 7, a2b, 7));
    assert(!has(a4, 4, a2b, 7));
    assert(has(a4, 4, a6, 2));
    assert(has(a4, 4, a2b, 2));
    assert(!has(a6, 2, a4, 4));
    assert(has(a1, 3, a3, 0));

    cerr << "All test cases passed!" << '\n';
    
//    string a[6] = { "john", "amy", "ketanji", "sonia", "amy", "ketanji" };
//    string a2[3] = { "amy", "sonia", "elena" };
//    string a3[3] = { "amy", "ketanji", "ketanji" };
//    string a4[3] = { "amy", "elena", "sonia" };
//    string a5[3] = { "john", "sonia", "sonia" };
//    
//    string b[3] = { "amy", "sonia", "elena" };
//    string b2[4] = { "amy", "sonia", "elena", ""};
//    string c[4] = { "", "", "", "" };
//    string d[6] = { "", "", "", "", "john", "amy", };
//    
//    
//    assert(allFalse(a, 6) == true);
//    assert(allFalse(b, 3) == true);
//    assert(allFalse(c, 4) == false);
//    
//    assert(countFalse(a, 6) == 6);
//    assert(countFalse(b, 3) == 3);
//    assert(countFalse(c, 4) == 0);
//    
//    assert(firstFalse(a, 6) == 0);
//    assert(firstFalse(b, 3) == 0);
//    assert(firstFalse(c, 4) == -1);
//    assert(firstFalse(d, 6) == 4);
//    cerr << "all tests PASSED" << endl;
    
    return 0;
}
