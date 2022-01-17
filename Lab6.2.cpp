// Laba6.2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <deque>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool Palindrome(string aString) {
    deque<char> chardeque;
    int strLen = aString.length();
    for (int i = 0; i < strLen; i++) {
        //pushes each char in the string to the deque.
        chardeque.push_back(aString[i]);
    }

    bool stillEqual = true;

    while (chardeque.size() > 1 && stillEqual) {
        char first = chardeque.front();
        chardeque.pop_front();
        char last = chardeque.back();
        chardeque.pop_back();
        if (first != last) { //if the two opposite positions of the
                             //word is not the same, then it is not
                             //a palindrome.
            stillEqual = false;
        }
    }
    if (stillEqual == true)cout << "Your string is palindrome";
    if (stillEqual == false)cout << "Your string is not palindrome";
    return stillEqual;
}



struct Point
{
    int x;
    int y;
};

int orientation(Point A, Point B, Point C)
{
    int val = (B.y - A.y) * (C.x - B.x) - (B.x - A.x) * (C.y - B.y);

    if (val == 0)
        return 0; // colinear
    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

void convexHull(Point points[], int n)// Prints convex hull of a set of n points.
{
    if (n < 3)// There must be at least 3 points
        return;

    vector<Point> hull;// Initialize Result
    int l = 0;
    for (int i = 1; i < n; i++) {// Find the leftmost point
        if (points[i].x < points[l].x) {// Start from leftmost point, keep moving counterclockwise
            l = i;                      // until reach the start point again
        }
    }

    int A = l, B;
    do
    {
        hull.push_back(points[A]);// Search for a point 'A' such that orientation(A, i, B) is
        B = (A + 1) % n;          // counterclockwise for all points 'i'
        for (int i = 0; i < n; i++) {
            if (orientation(points[A], points[i], points[B]) == 2) {
                B = i;
            }
        }
        A = B; // Set A as B for next iteration
    } while (A != l);

    for (int i = 0; i < hull.size(); i++) // Print Result
    {
        cout << "(" << hull[i].x << ", " << hull[i].y << ")\n";
    }
}


int main()
{
    int choise = 0;
    while (true)
    {
        cout << "1) Task 1, Palindrome." << endl;
        cout << "2) Task 2, convexHull." << endl;
        cout << "3) EXIT" << endl;
        cout << "Select task: ";
        cin >> choise;
        switch (choise) {
        case 1: {
            string text;
            cout << "enter" << endl;
            cin >> text;
            cout << Palindrome(text) << endl;
            break;
        }
        case 2: {
            Point points[] = { { 0, 3 }, { 5, 5 }, { 1, 2 }, { 2, 1 }, { 1, 0 },
           { 0, 0 }, { 3, 3 } };
            cout << "The points in the convex hull are: " << endl;
            int n = sizeof(points) / sizeof(points[0]);
            convexHull(points, n);
            return 0;
            break;
        }
        case 3:
            return 0;
        default:
            break;
        }
    }
}

