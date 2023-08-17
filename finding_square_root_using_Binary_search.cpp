#include <iostream>
using namespace std;

// // CODE STUDIO APPROACH
// int square_root(int n){
//     if(n == 0 || n == 1){
//         return n;
//     }
//     int start = 2,end = n;
//     int mid;
//     while (start <= end){
//         mid = start + ((end - start)/2);
//         if(mid <= (n/mid)){ // condition -> if the square of mid is less than or equal to number.
//             start = mid + 1;
//         }
//         else 
//             end = mid - 1;
//     }

//     return start - 1;
// }


// // TEACHER APPROACH
// int square_root(int n)
// {
//     if (n == 0 || n == 1){
//         return n;
//     }

//     int start = 0,end = n;
//     long long int mid;
//     long long int ans;

//     while(start <= end){
        
//         mid = start + ((end - start)/2);

//        if(mid * mid > n){
//            end = mid - 1;
//        }
//        else if(mid * mid == n){
//            return mid;
//        } 
//        else {
//          ans = mid;
//          start = mid + 1;
//        }

//     }

//     return ans;
// }


// // where I stuck in the problem -> float me typecast me galti hoo rha tha mid ko
// // MY APPROACH HAVE SOME ERROR or full error
// int square_root(int x)
// {

//     int start = 0, end = x;
//     float mid = start + ((end - start) / (float)2);
//     while (start < end)
//     {

//         if (mid == (x/mid))
//         {
//             return int(mid);
//         }

//         else if (mid > (x/mid))
//         {
//             end = mid;
//         }
//         else
//         {
//             start = mid + 1;
//         }

//         mid = start + ((end - start) / (float)2);
//     }

//     return start-1;
// }

int main()
{
    int x = 81;
    int root = square_root(x);
    cout << "The square root of " << x << " is " << root << endl;
    return 0;
}