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
    
    return 0;
}

//#include <string>
//#include <iostream>
//#include <cassert>
//using namespace std;
//
//int main()
//{
//  string a[6] = { "john", "amy", "ketanji", "sonia", "amy", "ketanji" };
//  string a2[3] = { "amy", "sonia", "elena" };
//  string a3[3] = { "amy", "ketanji", "ketanji" };
//  string a4[3] = { "amy", "elena", "sonia" };
//  string a5[3] = { "john", "sonia", "sonia" };
//
//  string b[3] = { "amy", "sonia", "elena" };
//  string b2[4] = { "amy", "sonia", "elena", ""};
//  string c[4] = { "", "", "", "" };
//  string d[6] = { "", "", "", "", "john", "amy", };
//
//
//  assert(allFalse(a, 6) == true);
//  assert(allFalse(b, 3) == true);
//  assert(allFalse(c, 4) == false);
//
//  assert(countFalse(a, 6) == 6);
//  assert(countFalse(b, 3) == 3);
//  assert(countFalse(c, 4) == 0);
//
//  assert(firstFalse(a, 6) == 0);
//  assert(firstFalse(b, 3) == 0);
//  assert(firstFalse(c, 4) == -1);
//  assert(firstFalse(d, 6) == 4);
//
//  assert(indexOfMax(a, 6) == 3);
//  assert(indexOfMax(a, 2) == 0);
//  assert(indexOfMax(b, 0) == -1);
//  assert(indexOfMax(b, 3) == 1);
//  assert(indexOfMax(c, 4) == 0);
//  assert(indexOfMax(d, 6) == 4);
//  assert(indexOfMax(d, 4) == 0);
//
//  assert(has(a, 7, a2, 3) == false);
//  assert(has(a, 7, a3, 3) == true);
//  assert(has(a, 3, a3, 3) == false);
//  assert(has(a, 7, a4, 3) == false);
//  assert(has(a, 7, a5, 3) == false);
//  assert(has(a, 1, a2, -2) == true);
//
//  cerr << "all tests PASSED" << endl;
//}

////test cases from rawspinach
//#include <cassert>
//int main() {
//    string arra[] = {"", "", "", "", ""}; // all are true
//    assert(!allFalse(arra, 5));
//    string arrb[] = {"a", "", "a", "", ""}; // at least one is true
//    assert(!allFalse(arrb, 5));
//    string arrc[] = {"a", "v", "a", "s", "r"}; // none are true
//    assert(allFalse(arrc, 5));
//    cerr << "passed all tests for allFalse" << endl;
//    
//    string arr1[] = {};
//    assert(countFalse(arr1, 0) == 0);
//    string arr2[] = {"", "", "", ""};
//    assert(countFalse(arr2, 4) == 0);
//    string arr3[] = {"full", "full", "full", "full"};
//    assert(countFalse(arr3, 4) == 4);
//    string arr4[] = {"full", "", "", ""};
//    assert(countFalse(arr4, 4) == 1);
//    string arr5[] = {"full", "full", "", ""};
//    assert(countFalse(arr5, 4) == 2);
//    string arr6[] = {"", "full", "", ""};
//    assert(countFalse(arr6, 4)  == 1);
//    string arr7[] = {"full", "", "", "full"};
//    assert(countFalse(arr7, 4) == 2);
//    string arr8[] = {"full", "", "", "full", "full"};
//    assert(countFalse(arr8, 5) == 3);
//    string arr9[] = {""}; // 1
//    assert(countFalse(arr9, 1) == 0);
//    string arr10[] = {"full"}; // 0
//    assert(countFalse(arr10, 1) == 1);
//    string arr88[] = {"full", "", "", "full", "full", "full", "", "full"};
//    assert(countFalse(arr88, 8) == 5); // with even number of elements
//    string arr89[] = {"full", "", "", "full", "full", "full", "full"};
//    assert(countFalse(arr89, 7) == 5); // with odd number of elements
//    cerr << "passed all tests for countFalse" << endl;
//    
//    string arr11[] = {}; // -1
//    assert(firstFalse(arr11, 0) == -1);
//    string arr21[] = {"", "", "", ""}; // -1
//    assert(firstFalse(arr21, 4) == -1);
//    string arr31[] = {"full", "full", "full", "full"}; // 0
//    assert(firstFalse(arr31, 4) == 0);
//    string arr41[] = {"full", "", "", ""}; // 0
//    assert(firstFalse(arr41, 4) == 0);
//    string arr51[] = {"full", "full", "", ""}; // 0
//    assert(firstFalse(arr51, 4) == 0);
//    string arr61[] = {"", "full", "", ""}; // 1
//    assert(firstFalse(arr61, 4) == 1);
//    string arr71[] = {"full", "", "", "full"}; // 0
//    assert(firstFalse(arr71, 4) == 0);
//    string arr81[] = {"", "", "", "full", "full"}; // 3
//    assert(firstFalse(arr81, 5) == 3);
//    string arr91[] = {""}; // -1
//    assert(firstFalse(arr91, 1) == -1);
//    string arr101[] = {"full"}; // 0
//    assert(firstFalse(arr101, 1) == 0);
//    cerr << "passed all tests for firstFalse" << endl;
//    
//    
//    string arr12[] = {"", "", "", ""}; // 0
//    assert(indexOfMax(arr12, 3)  == 0);
//    string arr22[] = {"a", "b", "c", "d"}; // 3
//    assert(indexOfMax(arr22, 4)  == 3);
//    string arr32[] = {"", "a", "", "a"}; // 1
//    assert(indexOfMax(arr32, 4)  == 1);
//    string arr42[] = {"c", "a", "b", "d", ""}; // 3
//    assert(indexOfMax(arr42, 5)  == 3);
//    string arr52[] = {"", "c", ""}; // 1
//    assert(indexOfMax(arr52, 3)  == 1);
//    string arr62[] = {"g", "a", "v", "z"}; // 3
//    assert(indexOfMax(arr62, 4)  == 3);
//    string arr72[] = {"p", "z", "z", "z", "z", "z", "p"}; // 1
//    assert(indexOfMax(arr72, 7)  == 1);
//    string arr82[] = {"a", "a", "a", "a"}; // 0
//    assert(indexOfMax(arr82, 4)  == 0);
//    string arr92[] = {"a"}; // 0
//    assert(indexOfMax(arr92, 1)  == 0);
//    string arr102[] = {""}; // 0
//    assert(indexOfMax(arr102, 1)  == 0);
//    cerr << "passed all tests for indexOfMax" << endl;
//    
//    
//    // where some elements contained but not all
//    string a1a[] = {"john", "amy", "ketanji", "sonia", "amy", "ketanji", "elena"};
//    string a1b[] = {"amy", "ketanji", "poop"};
//    assert(has(a1a, 7, a1b, 3) == 0);
//    
//    // where all elements are contained but not in the same order
//    string a2a[] = {"a", "b", "c", "d", "e", "f", "g"};
//    string a2b[] = {"b", "d", "a"};
//    assert(has(a2a, 7, a2b, 3) == 0);
//    
//    // where no elements are conatined
//    string a3a[] = {"a", "b", "c", "d", "e", "f", "g"};
//    string a3b[] = {"poop", "pee", "fart"};
//    assert(has(a3a, 7, a3b, 3) == 0);
//    
//    // where all elements are conatined in the right order
//    string a4a[] = {"a", "b", "c", "d", "e", "f", "g", "h"};
//    string a4b[] = {"b", "c", "e", "g"};
//    assert(has(a4a, 8, a4b, 4) == 1);
//    
//    // where all elements are conatined in the right order, but in two ways
//    string a5a[] = {"a", "b", "c", "c", "e", "f", "g", "h"};
//    string a5b[] = {"b", "c", "e", "h"};
//    assert(has(a5a, 8, a5b, 4) == 1);
//    
//    // where array a is empty but array b is not
//    string a6a[] = {};
//    string a6b[] = {"trash", "poop"};
//    assert(has(a6a, 0, a6b, 2) == 0);
//    
//    // where array b is empty but array a is not
//    string a7a[] = {"smallberg"};
//    string a7b[] = {};
//    assert(has(a7a, 1, a7b, 0) == 1);
//    
//    // where both arrays are empty
//    string a8a[] = {};
//    string a8b[] = {};
//    assert(has(a8a, 0, a8b, 0) == 1);
//    
//    // where both arrays are size 1 and have the same elements
//    string a9a[] = {"smallberg"};
//    string a9b[] = {"smallberg"};
//    assert(has(a9a, 1, a9b, 1) == 1);
//    
//    // where both arrays are size 1 and have different elements
//    string a10a[] = {"smallberg"};
//    string a10b[] = {"nachenberg"};
//    assert(has(a10a, 1, a10b, 1) == 0);
//    
//    cerr << "good job u passed mwah!" << endl;
//}
