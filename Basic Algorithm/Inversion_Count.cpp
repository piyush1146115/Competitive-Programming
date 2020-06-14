/*
 * FILE: Inversion_Count.cpp
 *
 * @author: Piyush Kanti Das <piyush123kantidas[at]gmail[dot]com>
 *
 * LINK:
 *
 * DATE CREATED: 20.09.2018 01:45:49 +06
 *
 * DESCRIPTION:
 *
 * DEVELOPMENT HISTORY:
 * Date         Version     Description
 * --------------------------------------------------------------
 * 20-09-2018	1.0         File Created
 *
 */


/*
// _______________________________________________________________/\\\_________
//  ______________________________________________________________\/\\\_________
//   ___/\\\\\\\\\___/\\\____/\\\__/\\\____________________________\/\\\_________
//    __/\\\/////\\\_\///____\//\\\/\\\___/\\\____/\\\__/\\\\\\\\\\_\/\\\_________
//     _\/\\\\\\\\\\___/\\\____\//\\\\\___\/\\\___\/\\\_\/\\\//////__\/\\\\\\\\\\__
//      _\/\\\//////___\/\\\_____\//\\\____\/\\\___\/\\\_\/\\\\\\\\\\_\/\\\/////\\\_
//       _\/\\\_________\/\\\__/\\_/\\\_____\/\\\___\/\\\_\////////\\\_\/\\\___\/\\\_
//        _\/\\\_________\/\\\_\//\\\\/______\//\\\\\\\\\___/\\\\\\\\\\_\/\\\___\/\\\_
//         _\///__________\///___\////_________\/////////___\//////////__\///____\///__
//
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long           ll;
typedef double              lf;
typedef unsigned long long  ull;
typedef pair<int, int>      pii;
typedef vector<pii>         vpii;
typedef vector<int>         vi;
typedef vector<long long>   vll;

#define __FastIO        ios_base::sync_with_stdio(false); cin.tie(0)

#define forr(i, a, b)   for (__typeof (a) i=a; i<=b; i++)
#define rof(i, b, a)    for (__typeof (a) i=b; i>=a; i--)
#define rep(i, n)       for (__typeof (n) i=0; i<n; i++)
#define forit(i, s)     for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
#define all(ar)         ar.begin(), ar.end()

#define fill(ar)   		memset(ar, -1, sizeof(ar))
#define clr(a)          memset(a, 0, sizeof(a))

#define nl              cout << '\n';
#define sp              cout << ' ';
#define ckk             cout << "##########\n"

#define pb              push_back
#define MP 				make_pair

#define debug1(x)       cerr << #x << ": " << x << endl
#define debug2(x, y)    cerr << #x << ": " << x << '\t' << #y << ": " << y << endl
#define debug3(x, y, z) cerr << #x << ": " << x << '\t' << #y << ": " << y << '\t' << #z << ": " << z << endl

#define gama 			0.57721566490
#define PI              acos(-1.0)
#define INF             0x7fffffff
#define MOD             1000000007
#define EPS             1e-7
#define MAX             100005

ll BM( ll a , ll b , ll m )
{
    if ( b == 0 ) return 1 ;
    ll x = BM(a,b/2,m);
    x = (( x % m) * (x % m))%m;
    
    if( b % 2 ) x = (( x % m) * (a %m)) % m ;
    return x ;
}

//Auto-format --> ctrl+shift+a
/********************* Code starts here ************************/

int  _mergeSort(int arr[], int temp[], int left, int right); 
int merge(int arr[], int temp[], int left, int mid, int right); 
  
/* This function sorts the input array and returns the 
   number of inversions in the array */
int mergeSort(int arr[], int array_size) 
{ 
    int *temp = (int *)malloc(sizeof(int)*array_size); 
    return _mergeSort(arr, temp, 0, array_size - 1); 
} 
  
/* An auxiliary recursive function that sorts the input array and 
  returns the number of inversions in the array. */
int _mergeSort(int arr[], int temp[], int left, int right) 
{ 
  int mid, inv_count = 0; 
  if (right > left) 
  { 
    /* Divide the array into two parts and call _mergeSortAndCountInv() 
       for each of the parts */
    mid = (right + left)/2; 
  
    /* Inversion count will be sum of inversions in left-part, right-part 
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid); 
    inv_count += _mergeSort(arr, temp, mid+1, right); 
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right); 
  } 
  return inv_count; 
} 
  
/* This funt merges two sorted arrays and returns inversion count in 
   the arrays.*/
int merge(int arr[], int temp[], int left, int mid, int right) 
{ 
  int i, j, k; 
  int inv_count = 0; 
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* j is index for right subarray*/
  k = left; /* k is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right)) 
  { 
    if (arr[i] <= arr[j]) 
    { 
      temp[k++] = arr[i++]; 
    } 
    else
    { 
      temp[k++] = arr[j++]; 
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i); 
    } 
  } 
  
  /* Copy the remaining elements of left subarray 
   (if there are any) to temp*/
  while (i <= mid - 1) 
    temp[k++] = arr[i++]; 
  
  /* Copy the remaining elements of right subarray 
   (if there are any) to temp*/
  while (j <= right) 
    temp[k++] = arr[j++]; 
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++) 
    arr[i] = temp[i]; 
  
  return inv_count; 
} 
  
/* Driver program to test above functions */
int main(int argv, char** args) 
{ 
  int arr[] = {1, 20, 6, 4, 5}; 
  printf(" Number of inversions are %d \n", mergeSort(arr, 5)); 
  getchar(); 
  return 0; 
}
