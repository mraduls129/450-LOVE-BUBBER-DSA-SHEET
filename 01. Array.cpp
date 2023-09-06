//ARRAY

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0;
        int end = s.size()-1;
        while(start < end){
            char temp = s[start];
            s[start] = s[end];
            s[end] = temp;
            start++;
            end--;
        }
    }
};
/*
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
*/


//02. FIND MAXIMUM AND MINIMUM ELEMENT IN AN ARRAY                                {T.C = O(N), S.C = O(1)}
class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	int max = INT_MIN;
    	int min = INT_MAX;
    	int sum = 0;
    	for(int i = 0 ; i < N ; i++){
    	    if(A[i] > max){
    	        max = A[i];
    	    }
    	    if(A[i] < min){
    	        min = A[i];
    	    }
    	}
	    sum = sum +  max + min;
    }
};


//03. KTH SMALLEST ELEMENT    /kth largest (only sign change and comment remain same)                                                 {T.C = O(N*LOGK), S.C = O(N)}
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int>pq;                          //max heap finding smallest element
        
        //step1- make max heap of first k elements
        for(int i = 0 ; i < k ; i++){
            pq.push(arr[i]);
        }
        
        //step2- for rest of elements answer from this loop
        for(int i = k ; i <= r ; i++){
            if(arr[i] < pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        
        //step3- return ans
        int ans = pq.top();
        return ans;
    }
};

//03.b KTH LARGEST ELEMENT                                                {T.C = O(N*LOGK), S.C = O(N)}
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //creating min heap
        priority_queue<int, vector<int>, greater<int>>pq;                         //insertinon 1 elements take's logn times

        //put first k elements to min heap
        for(int i = 0 ; i < k ; i++){
            pq.push(nums[i]);
        }

        //for rest of elements
        for(int i = k ; i < nums.size() ; i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }

        int ans = pq.top();
        return ans;
    }
};
/*
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
*/


//04. SORT AN ARRAY'S OF 0'S 1'S AND 2'S                                             {T.C = O(N) ,S.C = O(1)}
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        int ptr1 = 0, ptr2 = n-1 , i = 0;
        while(i <= ptr2){
            if(a[i] == 0){
                swap(a[i++],a[ptr1++]);
            }
            else if(a[i] == 2){
                swap(a[i],a[ptr2--]);   
            }
            else{                 //a[i] == 1
                i++;
            }
        }
    }
};


//05. Move all negative numbers to beginning and positive to end with constant extra space    {T.C = O(N) ,S.C = O(1)}
#include<iostream>
using namespace std;

void swap(int &a,int &b){
    int temp = a;
    a = b ;
    b = temp;
}
void reArrange(int arr[] , int &n){
    int low = 0 ;
    int high = n-1;
    while(low < high){
        if(arr[low] < 0){
            low++;
        }
        else if(arr[high] > 0){
            high--;
        }
        else{
            swap(arr[low],arr[high]);
        }
    }
}
void displayArray(int arr[], int n){
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    int arr[] = {5 , -3, 22 , -24 , 34 , 98 , -2};
    int n = sizeof(arr)/sizeof(arr[0]);
    reArrange(arr,n);
    displayArray(arr,n);
    
}
/*
output
-2 -3 -24 22 34 98 5 
*/


//06. UNION OF TWO ARRAYS                                                 {T.C = O(N+M), S.C = O(N+M)}
#include<unordered_set>
class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        unordered_set<int>unionSet;
        
        //insert element of 1st array into unionset/hash
        for(int i = 0 ; i < n ; i++){
            u.insert(a[i]);
        }
        
        //insert element of 2nd array into unionset/hash
        for(int i  = 0 ; i < m ; i++){
            u.insert(b[i]);
        }
        
        return u.size();
    }
};
/*
Input:
5 3
1 2 3 4 5
1 2 3
Output: 
5
*/


//06b. INTERSECTION OF TWO SORTED ARRAYS                                       {T.C = O(n + m),S.C= O(min(n,m))}
class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_set<int>in;
        unordered_set<int>set(a,a+n);
        
        //insert intersection of element of array in unordered set/hash
        for(int i = 0 ; i < m ; i++){
            if(setA.count(b[i]) > 0){
                in.insert(b[i]);
            }
        }
        
        return in.size();
    }
};
/*
Input:
n = 5, m = 3
a[] = {89, 24, 75, 11, 23}
b[] = {89, 2, 4}

Output: 1
*/


//07. CYCLICALLY ROTATE AN ARRAY BY ONE                                          {T.C = O(N) , S.C = O(1)}
void rotate(int arr[], int n)
{
    //store the last element
    int lastelement = arr[n-1];
    
    for(int i = n-1 ; i > 0 ; i--){
        arr[i] = arr[i-1];
    }
    
    //put last element to first place
    arr[0] = lastelement;
    
}
/*
Input:
N = 5
A[] = {1, 2, 3, 4, 5}
Output:
5 1 2 3 4
*/


//08./13.  KADANE'S ALGO                                                         {T.C = O(N), S.C = O(1)}
class Solution{
    public:
    
    long long maxSubarraySum(int arr[], int n){
        long long  sum = 0;
        long long maxi = arr[0];
        
        for(int i = 0 ; i < n ; i++){
            sum = sum + arr[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            } 
        }
        return maxi;
    }
};
/*
Input:
N = 5
Arr[] = {1,2,3,-2,5}
Output:
9
Explanation:
Max subarray sum is 9
of elements (1, 2, 3, -2, 5) which 
is a contiguous subarray.
*/

//09. MINIMIZE THE HEIGHTS II                                                  {T.C = O(N),S.C = O(1)}
class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        sort(arr,arr+n);
        int diff = arr[n-1]-arr[0];
        int mini = 0;
        int maxi = 0;
        for(int i = 0 ; i < n ; i++){
            if(arr[i] < k){
                continue;
            }
            maxi = max(arr[n-1]-k ,arr[i-1]+k);
            mini = min(arr[0]+k , arr[i]-k);
            diff = min(diff,(maxi-mini));
        }
        return diff;
    }
};
/*
Input:
K = 2, N = 4
Arr[] = {1, 5, 8, 10}
Output:
5
Explanation:
The array can be modified as 
{1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}. 
The difference between 
the largest and the smallest is 8-3 = 5.
*/


//10. MINIMUM NUMBER OF JUMPS /jump game                                                     {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int jump(vector<int>& nums) {
        int reach=0, jump=0, last=0;  
        for(int i=0;i<nums.size()-1;i++){  
            reach = max(reach, i+nums[i]);  
            if(i==last){  
                last = reach;  
                jump++;  
            }
        }
        return jump;  
    }
};
/*
Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 
Output: 3 
Explanation: 
First jump from 1st element to 2nd 
element with value 3. Now, from here 
we jump to 5th element with value 9, 
and from here we will jump to the last. 
*/


//11. FIND THE DUPLICATE NUMBER (THE FLOYD'S TORTOISE AND HARE ALGORITHM // TWO POINTER)                   {T.C = O(N), S.C = O(1)}

OR 

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       unordered_set<int> s;

        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return nums[i]; // Found the duplicate
            }
            s.insert(nums[i]);
        }

        return -1; // No duplicate found
    }
};
/*
Input: nums = [1,3,4,2,2]
Output: 2
*/


//12. MERGE 2 SORTED ARRAYS WITHOUT USING EXTRA SPACE                       {T.C = O(N+M(LOG(M+N))), S.C = O(1)}
class Solution{
    public:
        //Function to merge the arrays.
        void merge(long long arr1[], long long arr2[], int n, int m) 
        { 
            int i = 0, j = 0, k = n-1;            //three pointer 
            
            while(i <= k && j < m ){
                if(arr1[i] <= arr2[j]){
                    i++;
                }
                else{       //arr1[i] > arr2[j]        
                    swap(arr2[j], arr1[k]);
                    j++;
                    k--;
                }
            }
            //after element in arr1 we have to sort 
            sort(arr1, arr1+n);
            sort(arr2, arr2+m);
        } 
};
/*
Input: 
n = 4, arr1[] = [1 3 5 7] 
m = 5, arr2[] = [0 2 6 8 9]
Output: 
arr1[] = [0 1 2 3]
arr2[] = [5 6 7 8 9]
Explanation:
After merging the two 
non-decreasing arrays, we get, 
0 1 2 3 5 6 7 8 9.
*/

//14. MERGE INTERVALS                                                  {T.C = O(NLOGN), S.C = O(N)}

/*
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].
*/


//15. NEXT PERMUTAION                                                        {T.C = O(N), S.C = O(1)}
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k, l;

        // Step 1: Find the first decreasing element from the right
        for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }

        // Step 2: If no decreasing element found, reverse the entire vector
        if (k < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            // Step 3: Find the smallest element greater than nums[k] from the right
            for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            }
            // Step 4: Swap nums[k] with nums[l]
            swap(nums[k], nums[l]);

            // Step 5: Reverse the elements after k to get the next permutation
            reverse(nums.begin() + k + 1, nums.end());
        }
    }
};
/*
Input: nums = [1,2,3]
Output: [1,3,2]
*/


//16. COUNT INVERSION
//BRUTE FORCE                                                           {T.C = O(N^2), S.C = O(1)}
class Solution{
  public:
    long long int inversionCount(long long arr[], long long N)
    {
        int count = 0;
        for(int i = 0 ; i < N ; i++){
            for(int j = i+1 ; j < N ; j++){
                if(arr[i] > arr[j]){
                    count++;
                }
            }
        }
        return count;
    }
};


//17. BEST TIME TO BUY AND SELL STOCK  I                                                  {T.C = O(N), S.C = O(1)}
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int profit = 0;
        for(int i = 1 ; i < prices.size() ; i++){                                    //i = 1 , sell on 1st day (0) is not allowed
            int diff = prices[i] - mini;
            profit = max(profit, diff);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};
/*
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.
*/


//18. COUNT PAIRS WITH GIVEN SUM
//BRUTE FORCE                                                                                 {T.C = O(N^2), S.C = O(1)}
class Solution{   
public:

    int getPairsCount(int arr[], int n, int k) {
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = i+1 ; j < n ; j++){
                if(arr[i] + arr[j] == k){
                    count++;
                }
            }
        }
        return count;
    }
};
//OPTIMIZED APPROACH (unordered map)                                                               {T.C = O(N), S.C = O(N)}
class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        //create unordered map == store frequency of element
        unordered_map<int,int>m;
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            int b = k - arr[i];                          //b == 2 element of pair a == 1 first element
            //b is present in map
            if(m[b]){
                count += m[b];
            }
            m[arr[i]]++;
        }
        return count;
    }
};
/*
Input:
N = 4, K = 6
arr[] = {1, 5, 7, 1}
Output: 2
Explanation: 
arr[0] + arr[1] = 1 + 5 = 6 
and arr[1] + arr[3] = 5 + 1 = 6.
*/


//19. COMMON ELEMENTS
//BRUTE FORCE                                                                            {T.C = O(N^3) , S.C = O(N)}
class Solution
{
public:    
    vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int>ans;
        for(int i = 0 ; i < n1 ; i++){
            for(int j = 0 ; j < n2 ; j++ ){
                for(int k = 0 ; k < n3 ; k++){
                    if(A[i] == B[j] && B[j] == C[k]){
                        ans.push_back(A[i]);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
//OPTIMIZED APPROACH (THREE POINTER APPROACh)                                                  {T.C = O(N) , S.C = O(N)}
class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            vector<int>ans;
            int ptr1 = 0;
            int ptr2 = 0;
            int ptr3 = 0;
            
            while(ptr1 < n1 && ptr2 < n2 && ptr3 < n3){
                if(A[ptr1] == B[ptr2] && B[ptr2] == C[ptr3]){
                    //handle duplicate common elements
                    if(ans.empty() || A[ptr1] != ans.back()){
                        ans.push_back(A[ptr1]);
                    }
                    ptr1++;
                    ptr2++;
                    ptr3++;
                }
                else if( A[ptr1] <= B[ptr2] && A[ptr1] <= C[ptr3]){
                    ptr1++;
                }
                else if( B[ptr2] <= A[ptr1] && B[ptr2] <= C[ptr3]){
                    ptr2++;
                }
                else if( C[ptr3] <= B[ptr2] && C[ptr3] <= A[ptr1]){
                    ptr3++;
                }
            }
            return ans;
        }
};
/*
Input:
n1 = 6; A = {1, 5, 10, 20, 40, 80}
n2 = 5; B = {6, 7, 20, 80, 100}
n3 = 8; C = {3, 4, 15, 20, 30, 70, 80, 120}
Output: 20 80
Explanation: 20 and 80 are the only
common elements in A, B and C.
*/


//20. REARRANGE ARRAY IN ALTERNATING POSITIVE AND NEGATIVE ITEMS (S.C = O(1))
//Rearrange Array Elements by Sign                                       {T.C = O(N), S.C = O(N)}

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n, 0);

        int posIndex = 0;
        int negIndex = 1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0){
                ans[negIndex] = nums[i];
                negIndex += 2;
            }
            else{
                ans[posIndex] = nums[i];
                posIndex += 2;
            }
        }
        return ans;
    }
};
/*
Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. 
*/



//21. SUBARRAY WITH 0 SUM
//BRUTE FORCE                                                                               {T.C = O(N^2), S.C = O(1)}
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        for(int i = 0 ; i < n ; i++){
            int sum = 0; 
            for(int j = i ; j < n ; j++){
                sum += arr[j];
                if(sum == 0){
                    return true;
                }
            }
        }
        return false;
    }
};
//OPTIMIZED APPROACH (HASHING)                                                              {T.C = O(N), S.C = O(N)}
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        //hashing and prefix sum concept
        unordered_set<int>s;
        int sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += arr[i];
            if(sum == 0){
                return true;
            }
            if(s.find(sum) != s.end()){
                return true;
            }
            s.insert(sum);
        }
        return false;
    }
};
or
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int curr=0,ans=0;
        mp[0]=1;
        for(int i:nums){
            curr+=i;
            ans+= mp[curr-k];
             mp[curr] ++;
           
        }
        return ans;
    }
};
/*
Input:
5
4 2 -3 1 6

Output: 
Yes

Explanation: 
2, -3, 1 is the subarray 
with sum 0.
*/


//22. FACTORIAL OF LARGE NUMBER                                                          {T.C = O(N^2), S.C = O(N)}
class Solution {
public:
    vector<int> factorial(int n) {
        vector<int>res;
        res.push_back(1);
        for(int i = 2 ; i <= n ; i++){
            int carry = 0;
            for(int j = 0 ; j < res.size() ; j++){
                int val = res[j]*i + carry;
                res[j] = val % 10;
                carry = val / 10;
            }
            while( carry != 0){
                res.push_back(carry % 10);
                carry = carry / 10;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
/*
Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800
*/


//23. MAXIMUM PRODUCT SUBARRAY
//BRUTE FORCE                                                                       {T.C = O(N^2), S.C = O(1)}
class Solution {
public:
    // Function to find maximum product subarray
    long long maxProduct(vector<int>& arr, int n) {
        long long maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            long long product = 1;
            for (int j = i; j < n; j++) {
                product *= arr[j];
                maxi = max(maxi, product);
            }
        }
        return maxi;
    }
};
//OPTIMIZED APPROACH (OBSERVATION)
class Solution{
public:
	long long maxProduct(vector<int> arr, int n) {
	    long long  pref = 1;
	    long long suff = 1;
	    long long maxi = INT_MIN;
	    for(int i = 0 ; i < n ; i++){
	        if(pref == 0){
	            pref = 1;
	        }
	        if(suff == 0){
	            suff = 1;
	        }
	        pref = pref*arr[i];
	        suff = suff*arr[n-i-1];
	        maxi = max(maxi, max(pref, suff));
	    }
	    return maxi;
	}
};
/*
Input:
N = 5
Arr[] = {6, -3, -10, 0, 2}
Output: 180
Explanation: Subarray with maximum product
is [6, -3, -10] which gives product as 180.
*/


//24. FIND LONGEST CONSECUTIVE SUBSEQUECE                                   {T.C = O(N), S.C = O(N)}
class Solution{
  public:
    int findLongestConseqSubseq(int arr[], int n)
    {
        //create a set
        set<int>s;
        //insert all elements to set
        for(int i = 0 ; i < n ; i++){
            s.insert(arr[i]);
        }
        
        int ans = INT_MIN;                     //finding maximum/longest sequence
        for(int i = 0 ; i < n ; i++){
            if(s.find(arr[i]-1) == s.end()){
                int j = arr[i]+1;
                while(s.find(j) != s.end()){
                    j++;
                }
                ans = max(ans, j-arr[i]);
            }
        }
        return ans;
    }
};

or

class Solution {
public:
    int findLongestConseqSubseq(int arr[], int N) {
     unordered_set<int> h(arr, arr + N);
        int res = 1;

        for (int i = 0; i < N; i++) {
            if (h.find(arr[i] - 1) == h.end()) {
                int curr = 1;
                while (h.find(arr[i] + curr) != h.end()) {
                    curr++;
                }
                res = max(res, curr);
            }
        }

        return res;
    }
};
/*
Input:
N = 7
a[] = {2,6,1,9,4,5,3}
Output:
6
Explanation:
The consecutive numbers here
are 1, 2, 3, 4, 5, 6. These 6 
numbers form the longest consecutive
subsquence.
*/


//25. COUNT MORE THAN N/K OCCURENCES                                                                        {T.C = O(N), S.C = O(N)}
class Solution
{
    public:
    //Function to find all elements in array that appear more than n/k times.
    int countOccurence(int arr[], int n, int k) {
        //create a unordered map (hashing)
        unordered_map<int, int>mp;
        //put all array elements in map
        for(int i = 0 ; i < n ; i++){
            mp[arr[i]]++;
        }
        int ans = 0;
        for(auto x : mp){
            ans = ans + (x.second > n/k);
        }
        return ans;
    }
};
/*
Input:
N = 8
arr[] = {3,1,2,2,1,2,3,3}
k = 4
Output: 2
Explanation: In the given array, 3 and
 2 are the only elements that appears 
more than n/k times.
*/


//26. BUY AND SELL A SHARE AT MOST TWICE  no need
//BRUTE FORCE(RECURSION)
int solve(int index, bool buy, vector<int>&price, int limit){
    int n = price.size();
    //base case
    if(index == n || limit == 0){
        return 0;
    }
    int profit = 0;
    if(buy){
        int buyKaro = -price[index] + solve(index+1, 0, price, limit);
        int skipKaro = 0 + solve(index+1, 1, price, limit);
        profit = max(buyKaro, skipKaro);
    }
    else{
        int sellKaro = +price[index] + solve(index+1, 1, price, limit-1);
        int skipKaro = 0 + solve(index+1, 0 , price, limit);
        profit = max(sellKaro, skipKaro);
    }
    return profit;
}
int maxProfit(vector<int>&price){
    return solve(0, 1, price, 2);                     //index = 0 , buy = 1, limit = 2
}


Input:
6
10 22 5 75 65 80
Output:
87
Explanation:
Trader earns 87 as sum of 12, 75 
Buy at 10, sell at 22, 
Buy at 5 and sell at 80
*/


//27. FIND WHETHER AN ARRAY IS A SUBSET OF ANOTHER ARRAY
//BRUTE FORCE                                                                  {T.C = O(N^2), S.C = O(1)}
string isSubset(int a1[], int a2[], int n, int m) {
    bool isFound = false;
    for(int j = 0 ; j < m ; j++){
        for(int i = 0 ; i < n ; i++){
            if(a2[j] == a1[i]){
                isFound = true;
                break;
            }
        }
        if(!isFound){
            return "No";
        }
    }
    return "Yes";
}
//HASHING(unordered map)                                                {T.C = O(N), S.C = O(N)}
string isSubset(int a1[], int a2[], int n, int m) {
    if(m > n){
        return "No";
    }
    //create a unordered map
    unordered_map<int, int>mp;
    //put element of arr1 in map
    for(int i = 0 ; i < n ; i++){
        mp[a1[i]]++;
    }
    
    //search element of arr2 in arr1
    for(int i = 0 ; i < m ; i++){
        if(mp[a2[i]] == 0){
            return "No";
        }
        mp[a2[i]]--;
    }
    return "Yes";
}
/*
Input:
a1[] = {11, 7, 1, 13, 21, 3, 7, 3}
a2[] = {11, 3, 7, 1, 7}
Output:
Yes
Explanation:
a2[] is a subset of a1[]
*/
--------------
//majority (more freq element)
	int findMajorityElement(const vector<int>& nums) {
map<int, int> Map;

    for (int i=0 to nums.size()) {
        Map[nums]++;
        if (Map[nums] > nums.size() / 2) {
            return nums; // Found the majority element
        }
    }

    return -1; // No majority element found
}
//pivot equilibrium

//count pair with sum target K/0
int countPairsWithSum(vector<int>& arr, int targetSum) {
   map<int, int> m;
    int pairCount = 0;

    for (int i = 0; i < arr.size(); ++i) {
        int num = arr[i];
        int diff = targetSum - num;
        if (m.find(diff) != m.end()) {
            pairCount += m[diff];
        }
        m[num]++;
    }

    return pairCount;
}

//28. FIND THE TRIPLET SUM OF AN ARRAY

//29. TRAPPING RAIN WATER                                                  {T.C = O(N), S.C = O(N)}
class Solution{
    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
    
        //create 2 arrays left and right
        int left[n];
        int right[n];
        
        //traversing through left
        left[0] = arr[0];
        for(int i = 1 ; i < n ; i++){
            left[i] = max(left[i-1], arr[i]);
        }
        
        //traversing through right
        right[n-1] = arr[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            right[i] = max(right[i+1], arr[i]);
        }
        
        long long ans = 0;
        for(int i = 0 ; i < n ; i++){
            ans += min(left[i], right[i]) - arr[i];
        }
        return ans;
    }
};
/*
Input:
N = 4
arr[] = {7,4,0,9}
Output:
10
Explanation:
Water trapped by above 
block of height 4 is 3 units and above 
block of height 0 is 7 units. So, the 
total unit of water trapped is 10 units.
*/


//30. CHOCOLATE DISTRIBUTION PROBLEM                                         {T.C = O(N*LOGN), S.C = O(1)}
class Solution{                                                            
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        sort(a.begin(),a.end());
        
        int i = 0;
        int j = m-1;
        
        int mini = INT_MAX;
        
        while(j < a.size()){
            int diff = a[j]-a[i];
            mini = min(mini, diff);
            i++;
            j++;
        }
        return mini;
    }   
};
/*
Input:
N = 8, M = 5
A = {3, 4, 1, 9, 56, 7, 9, 12}
Output: 6
Explanation: The minimum difference between 
maximum chocolates and minimum chocolates 
is 9 - 3 = 6 by choosing following M packets :
{3, 4, 9, 7, 9}.
*/


//31. SMALLEST SUBARRAY WITH SUM GREATER THAN A GIVEN VALUE                       {T.C = O(N), S.C = O(1)}
//SLIDING WINDOW APPROACH
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        int first = 0;
        int second = 1;
        int res = INT_MAX;                          //finding smallest/minimum
        int sum = arr[first];
        if(sum > x){
            return 1;
        }
        if(second < n){
            sum += arr[second];
        }
        while(first < n && second < n){
            if(sum > x){
                res = min(res, second-first+1);     //minimum length
                sum -= arr[first];
                first++;
            }
            else{
                second++;
                if(second < n){
                    sum += arr[second];
                }
            }
        }
        return res;
    }
};
/*
Input:
A[] = {1, 4, 45, 6, 0, 19}
x  =  51
Output: 3
Explanation:
Minimum length subarray is 
{4, 45, 6}
*/


//32. THREE WAY PARTITIONING (DUTCH NATIONAL FLAG)                                {T.C = O(N), S.C = O(1)}
class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& arr,int a, int b)
    {   
        int n = arr.size();
        int low = 0,  mid = 0, high = n-1;
        
        //using dutch national flag algo
        while(mid <= high){
            if(arr[mid] < a){
                swap(arr[low], arr[mid]);
                low++;
                mid++;
            }
            else if(arr[mid] >= a && arr[mid] <= b){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};
/*
Input: 
n = 5
A[] = {1, 2, 3, 3, 4}
[a, b] = [1, 2]
Output: 1
Explanation: One possible arrangement is:
{1, 2, 3, 3, 4}. If you return a valid
arrangement, output will be 1.
*/

//33. MINIMUM SWAPS REQUIRED BRING ELEMENTS LESS EQUAL K TOGETHER                      {T.C = O(N), S.C = O(1)}
class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        int good = 0;                                    //gaod value < k value
        int bad = 0;                                     //bad value  > k value
        
        ///counting good value
        for(int i = 0 ; i < n ; i++){
            if(arr[i] <= k){
                good++;
            }
        }
        //counting bad value
        for(int i = 0 ; i < good ; i++){
            if(arr[i] > k){
                bad++;
            }
        }
        int i = 0 , j = good, ans = bad;
        while(j < n){
            //if the start window was the bad value
            if(arr[i] > k){
                bad--;
            }
            //if the end window was bad value
            if(arr[j] > k){
                bad++;
            }
            //update answer
            ans = min(ans, bad);
            i++;
            j++;
        }
        return ans;
    }
};
/*
Input : 
arr[ ] = {2, 1, 5, 6, 3} 
K = 3
Output : 
1
Explanation:
To bring elements 2, 1, 3 together,
swap index 2 with 4 (0-based indexing),
i.e. element arr[2] = 5 with arr[4] = 3
such that final array will be- 
arr[] = {2, 1, 3, 6, 5}
*/

//34. MINIMUM NO. OF OPERATIONS REQUIRED TO MAKE AN ARRAY PALINDROME
class Solution {
public:
    int PalinArray(int a[], int n)
    {
        for(int i = 0 ; i < n ; i++){
            int ans = 0;
            int temp = a[i];
            
            while(temp > 0){
                int r = temp % 10;
                temp /= 10;
                ans = (ans*10) + r;
            }
            if(ans != a[i]){
                return 0;
            }
        }
        return 1;
    }
};
/*
Input:
5
111 222 333 444 555

Output:
1

Explanation:
A[0] = 111 //which is a palindrome number.
A[1] = 222 //which is a palindrome number.
A[2] = 333 //which is a palindrome number.
A[3] = 444 //which is a palindrome number.
A[4] = 555 //which is a palindrome number.
As all numbers are palindrome so This will return 1.
*/

//35. MEDIAN OF 2 SORTED ARRAYS OF EQUAL SIZE
//FIND MEDIAN                                                                  {T.C = O(N*LOGN) , S.C = O(1)}
class Solution
{
public:
	public:
		int find_median(vector<int> v)
		{  
		    int n = v.size();
		    int ans = 0;
		    sort(v.begin(), v.end());

	        if(n % 2 == 0){                  //even length
	            ans = (v[n/2-1] + v[n/2])/2;
	        }
	        else{                  //odd length
	            ans = v[n/2];
	        }
		    return ans;
		}
};
/*
Input: N = 5
arr[] = 90 100 78 89 67
Output: 89
Explanation: After sorting the array 
middle element is the median 
*/




//36. MEDIAN OF 2 SORTED ARRAYS OF DIFFERENT SIZE                            {T.C =O(log(min(n1, n2))) , S.C = O(1) } 
class Solution{
    public:
    double MedianOfArrays(vector<int>& a1, vector<int>& a2)
    {
        //using binary search
        int n1 = a1.size();
        int n2 = a2.size();
        
        if(n2 < n1){
            return MedianOfArrays(a2, a1);
        }
        
        int low = 0 , high = n1;
        
        while(low <= high){
            int cut1 = (low+high)/2;
            int cut2 = ((n1+n2+1)/2) - cut1;
            int left1 = cut1 == 0 ? INT_MIN : a1[cut1-1];
            int left2 = cut2 == 0 ? INT_MIN : a2[cut2-1];
            int right1 = cut1 == n1 ? INT_MAX : a1[cut1];
            int right2 = cut2 == n2 ? INT_MAX : a2[cut2];
            
            if(left1 <= right2 && left2 <= right1){
                if((n1+n2) % 2 == 0){            //even
                    return (max(left1, left2) + min(right1, right2))/2.0;
                }
                else{                            //odd
                    return max(left1, left2);
                }
            }
            else if(left1 > left2){
                high = cut1-1;                   //move left
            }
            else{
                low = cut1+1;                    //move right
            }
        }
        return 0.0;
    }
};
/*
Input:
m = 3, n = 4
array1[] = {1,5,9}
array2[] = {2,3,6,7}
Output: 5
Explanation: The middle element for
{1,2,3,5,6,7,9} is 5
*/
// missing and repetating
vector<int> findTwoElement(vector<int> arr, int n) {
  unordered_map<int, int> freq;
    int repeating = -1, missing = -1;

    for (int i=0;i< arr.size();i++) {
        freq[i]++;
    }

    for (int i = 1; i <= n; ++i) {
        if (freq[i] == 0) {
            missing = i;
        } else if (freq[i] == 2) {
            repeating = i;
        }
    }

    return {repeating, missing};
}
// sliding window max
vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
vector<int> result;
   deque<int> dq; // Store indices
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove indices that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }
        
        // Remove indices of smaller elements as they are no longer candidates
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i); // Add the current index
        
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]); // Maximum of the current window
        }
    }
    
    return result;

// rotate array
void rotateRight(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // To handle k larger than array size

    vector<int> temp(n);
    for (int i = 0; i < n; ++i) {
        temp[(i + k) % n] = nums[i];   //right wala halka rhega
    }

    nums = temp;
}

void rotateLeft(vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // To handle k larger than array size

   vector<int> temp(n);
    for (int i = 0; i < n; ++i) {                 
        temp[i] = nums[(i + k) % n];  // left wala halka rhega
    } 

    nums = temp;    
}
//triplet sum with 0/k   
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> triplets;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // Skip duplicates.
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    triplets.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;

                    // Skip duplicates of the left and right elements.
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (sum < 0) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return triplets;
    }
};
//largest subaaraay with target k/0
lass Solution{
public:
    int lenOfLongSubarr(int A[], int N, int K) {
        int length = 0;
        unordered_map<int, int> m;
        int sum = 0;
        m[0] = -1;
        
        for (int i = 0; i < N; ++i) {
            sum += A[i];
            if (m.find(sum - K) != m.end()) {
                length =max(length, i - m[sum - K]);
            }
            if (m.find(sum) == m.end()) {              0 me ye wali line nhi hoti and else hota yha bs 
                m[sum] = i;
            }
        }

        return length;
    }
};
// row with  max 1s/0s
int findRowWithMaxZeros(const vector<vector<int>>& matrix) {
 
// fist and last occurernces
pair<long, long> indexes(const vector<long long>& v, long long x) {
    long firstIndex = -1;
    long lastIndex = -1;
    
    for (long i = 0; i < v.size(); ++i) {
        if (v[i] == x) {
            if (firstIndex == -1) {
                firstIndex = i;
            }
            lastIndex = i;
        }
    }
    
    return make_pair(firstIndex, lastIndex);
}
//count pair with sum 
int countPairsWithSum(const vector<int>& nums, int target) {
    unordered_map<int, int> m;
    int count = 0;

    for (int i=0 to nums.size) {
        int complement = target - nums[i];
        count += m[complement]; // Add the frequency of complement

        m[nums[i]]++; // Update frequency of the current number      //isme bhi h
    }

    return count;
}

//two pair sum 
pair<int, int> twoSum(const vector<int>& nums, int target) {
    std::unordered_map<int, int> m;
    
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        
        if (m.find(complement) != m.end()) {
            return {m[complement], i};         // (true)
        }
        
        m[nums[i]] = i;              // isme bhi h
    }
    
    return {-1, -1}; // No valid solution found    // (false)
}

//add two arrays
vector<int> sumArrays(const vector<int>& arr1, const vector<int>& arr2) {
    int size = max(arr1.size(), arr2.size());
    vector<int> result(size, 0);   // value can be comes from size value to o value

    for (int i = 0; i < size; ++i) {
        int val1 = (i < arr1.size()) ? arr1[i] : 0;
        int val2 = (i < arr2.size()) ? arr2[i] : 0;
        result[i] = val1 + val2;
    }

    return result;
}
// sum of infinity array
int main() {
    
    const int maxi = 1000000; 
    int sum = 0;

    for (int i = 0; i < maxi; ++i) {
        sum += i;
    }

//count pair with difference
int countPairsWithDifference(const std::vector<int>& nums, int k) {
   unordered_set<int> seen;
    int count = 0;

    for (int num : nums) {
        if (seen.count(num - k)) {
            count++;
        }
        if (seen.count(num + k)) {
            count++;
        }
        seen.insert(num);
    }

    return count;
}
// find pair with differnce
bool hasPairWithDifference(const vector<int>& arr, int N) {
 unordered_set<int> m;

   for (int i=0;i<arr.size;i++) {
        if (m.count(arr(i) + N) or m.count(arr(i) - N)) {
            return true; // Found a valid pair
        }                                                                            // both solution are same
        m.insert(num);
    }

    return false; // No valid pair found
}
//pair with differnce k
int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == k)
                    m[nums[i]] = nums[j];
            }
        }
        
        return m.size();
    }
//

/*----------------------------------------------------  THE  END    ---------------------------------------------------------*/
