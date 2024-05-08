//
//  tree.cpp
//  s24Homework3
//
//  Created by Cameron Maiden on 5/7/24.
//

#include <iostream>
#include <string>
using namespace std;
// Return the number of ways that all n2 elements of a2 appear
// in the n1 element array a1 in the same order (though not
// necessarily consecutively).  The empty sequence appears in a
// sequence of length n1 in 1 way, even if n1 is 0.
// For example, if a1 is the 7 element array
//    "john" "amy" "ketanji" "sonia" "amy" "ketanji" "elena"
// then for this value of a2            the function must return
//    "john" "sonia" "ketanji"                      1
//    "john" "ketanji" "elena"                      2
//    "sonia" "john" "ketanji"                      0
//    "amy" "ketanji" "elena"                       3
int numberOfTimesHas(const string a1[], int n1, const string a2[], int n2)
{
    if (n2 <= 0)
        return 1;
    if (n1 <= 0)
        return 0;
    
    int count = 0;
    if(a1[0] == a2[0])
        count += numberOfTimesHas(a1+1, n1-1, a2+1, n2-1);
            
    return count += numberOfTimesHas(a1+1, n1-1, a2, n2);
}

// Exchange two strings
void exchange(string& x, string& y)
{
    string t = x;
    x = y;
    y = t;
}

// Rearrange the elements of the array so that all the elements
// whose value is < separator come before all the other elements,
// and all the elements whose value is > separator come after all
// the other elements.  Upon return, firstNotLess is set to the
// index of the first element in the rearranged array that is
// >= separator, or n if there is no such element, and firstGreater is
// set to the index of the first element that is > separator, or n
// if there is no such element.
// In other words, upon return from the function, the array is a
// permutation of its original value such that
//   * for 0 <= i < firstNotLess, a[i] < separator
//   * for firstNotLess <= i < firstGreater, a[i] == separator
//   * for firstGreater <= i < n, a[i] > separator
// All the elements < separator end up in no particular order.
// All the elements > separator end up in no particular order.
void separate(string a[], int n, string separator,
              int& firstNotLess, int& firstGreater)
{
    if (n < 0)
        n = 0;
    
    // It will always be the case that just before evaluating the loop
    // condition:
    //  firstNotLess <= firstUnknown and firstUnknown <= firstGreater
    //  Every element earlier than position firstNotLess is < separator
    //  Every element from position firstNotLess to firstUnknown-1 is
    //    == separator
    //  Every element from firstUnknown to firstGreater-1 is not known yet
    //  Every element at position firstGreater or later is > separator
    
    firstNotLess = 0;
    firstGreater = n;
    int firstUnknown = 0;
    while (firstUnknown < firstGreater)
    {
        if (a[firstUnknown] > separator)
        {
            firstGreater--;
            exchange(a[firstUnknown], a[firstGreater]);
        }
        else
        {
            if (a[firstUnknown] < separator)
            {
                exchange(a[firstNotLess], a[firstUnknown]);
                firstNotLess++;
            }
            firstUnknown++;
        }
    }
}

// Rearrange the elements of the array so that
// a[0] <= a[1] <= a[2] <= ... <= a[n-2] <= a[n-1]
// If n <= 1, do nothing.
void order(string a[], int n)
{
    if (n <= 1)
        return;
    int front, back; // references to keep track of the new reordered array
    if (a[0] >= a[1])
        separate(a, n, a[1], front, back);
    order(a+1, n-1);
    return;
}

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
    // Return the number of ways that all n2 elements of a2 appear
    // in the n1 element array a1 in the same order (though not
    // necessarily consecutively).  The empty sequence appears in a
    // sequence of length n1 in 1 way, even if n1 is 0.
    // For example, if a1 is the 7 element array
    //    "john" "amy" "ketanji" "sonia" "amy" "ketanji" "elena"
    // then for this value of a2            the function must return
    //    "john" "sonia" "ketanji"                      1
    //    "john" "ketanji" "elena"                      2
    //    "sonia" "john" "ketanji"                      0
    //    "amy" "ketanji" "elena"                       3
    
    string num1[] = {"1", "2", "3"};
    string num2[] = {"2", "3"};
    assert(numberOfTimesHas(num1, 3, num2, 2) == 1);

    string a1[] = {"john", "amy", "ketanji", "sonia", "amy", "ketanji", "elena"};
    string a2a[] = {"john", "sonia", "ketanji"};
    string a2b[] = {"john", "ketanji", "elena"};
    string a2c[] = {"sonia", "john", "ketanji"};
    string a2d[] = {"amy", "ketanji", "elena" };
    
    assert(numberOfTimesHas(a1, 7, a2a, 3) == 1);
    assert(numberOfTimesHas(a1, 7, a2b, 3) == 2);
    assert(numberOfTimesHas(a1, 7, a2c, 3) == 0);
    assert(numberOfTimesHas(a1, 7, a2d, 3) == 3);

    cerr << "All test cases passed!" << '\n';
    
    string fruit[] = {"apple", "orange", "banana", "grape", "kiwi", "orange", "peach"};
    string a[] = { "", "35", "ufwu9fe", "", "bakersfield" };

    order(fruit, 7);
    for (int i = 0; i < 7; i++)
        cerr << fruit[i] << " ";
    cerr << endl;
    
    order(num1, 3);
    for (int i = 0; i < 3; i++)
        cerr << num1[i] << " ";
    cerr << endl;
    
//    a1[5] = "ketanji         ";
    order(a1, 7);
    for (int i = 0; i < 7; i++)
        cerr << a1[i] << " ";
    cerr << endl;
    
    order(a, 4);
    for (int i = 0; i < 5; i++)
        cerr << a[i] << " ";
    cerr << endl;
    return 0;
}
