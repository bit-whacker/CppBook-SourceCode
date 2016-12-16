 #include <iostream>
 #include <vector>
 #include "comparer.h"

 /*
  *   selection_sort(a, compare)
  *       Arranges the elements of vector a in an order determined
  *       by the compare object.
  *       a is a vector of ints.  
  *       compare is a function that compares the ordering of
  *            two integers.
  *       The contents of a are physically rearranged.
  */
 void selection_sort(std::vector<int>& a, Comparer& compare) {
     int n = a.size();
     for (int i = 0;  i < n - 1;  i++) {
         //  Note: i,small, and j represent positions within a
         //  a[i], a[small], and a[j] represents the elements at
         //  those positions.
         //  small is the position of the smallest value we've seen
         //  so far; we use it to find the smallest value less 
         //  than a[i]
         int small = i;  
         //  See if a smaller value can be found later in the array
         for (int j = i + 1;  j < n;  j++)
             if (compare.compare(a[j], a[small]))
                 small = j;  //  Found a smaller value
         //  Swap a[i] and a[small], if a smaller value was found
         if (i != small)
             compare.swap(a[i], a[small]);
     }
 }

 /*
  *  print
  *     Prints the contents of an integer vector
  *     a is the vector to print.
  *     a is not modified.
  */
 void print(const std::vector<int>& a) {
     int n = a.size();
     std::cout << '{';
     if (n > 0) {
         std::cout << a[0];  //  Print the first element
         for (int i = 1; i < n; i++)
             std::cout << ',' << a[i];  //  Print the rest
     }
     std::cout << '}';
 }

 /*
  *  less_than(a, b)
  *     Returns true if a < b; otherwise, returns
  *     false.
  */
 bool less_than(int a, int b) {
     return a < b;
 }

 /*
  *  greater_than(a, b)
  *     Returns true if a > b; otherwise, returns
  *     false.
  */
 bool greater_than(int a, int b) {
     return a > b;
 }

 int main() {
    //  Make a vector of integers
    std::vector<int> original { 23, -3, 4, 215, 0, -3, 2, 23, 100, 88, -10 };

    //  Make a working copy of the original vector
    std::vector<int> working = original;
    std::cout << "Before:   ";
    print(working);
    std::cout << '\n';
    Comparer lt(less_than), gt(greater_than);
    selection_sort(working, lt);
    std::cout << "Ascending:  ";
    print(working);
    std::cout << "  (" << lt.comparisons() << " comparisons, " 
              << lt.swaps() << " swaps)\n";
    std::cout << "----------------------------\n";
    //  Make another copy of the original vector
    working = original;
    std::cout << "Before:   ";
    print(working);
    std::cout << '\n';
    selection_sort(working, gt);
    std::cout << "Descending: ";
    print(working);
    std::cout << "  (" << gt.comparisons() << " comparisons, " 
              << gt.swaps() << " swaps)\n";
    std::cout << "----------------------------\n";
    //  Sort a sorted vector
    std::cout << "Before:   ";
    print(working);
    std::cout << '\n';
    //  Reset the greater than comparer so we start counting at
    //  zero
    gt.reset();
    selection_sort(working, gt);
    std::cout << "Descending: ";
    print(working);
    std::cout << "  (" << gt.comparisons() << " comparisons, " 
              << gt.swaps() << " swaps)\n";
 }

