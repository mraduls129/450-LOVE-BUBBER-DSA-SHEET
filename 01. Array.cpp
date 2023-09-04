//ARRAY

#include<bits/stdc++.h>
using namespace std;

//01. REVERSE THE STRING                                                         {T.C = O(N), S.C = O(1)}
string reverseWord(string str){
    int n = str.length();
    for(int i = 0 ; i < n/2 ; i++){
        char temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
    cout<<str;
}
//another approach
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


//03. KTH SMALLEST ELEMENT                                                     {T.C = O(N*LOGK), S.C = O(N)}
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
void rearrangeArray(std::vector<int>& arr) {
    int left = 0; // Pointer for the left end
    int right = arr.size() - 1; // Pointer for the right end

    while (left <= right) {
        if (arr[left] < 0 && arr[right] < 0) {
            // Both elements are negative, move the left pointer to the right.
            left++;
        } else if (arr[left] > 0 && arr[right] < 0) {
            // Left is positive, right is negative, so swap them.
            std::swap(arr[left], arr[right]);
            left++;
            right--;
        } else if (arr[left] > 0 && arr[right] > 0) {
            // Both elements are positive, move the right pointer to the left.
            right--;
        } else {
            // Left is negative, right is positive, move both pointers.
            left++;
            right--;
        }
    }
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
        set<int>st;
        
        //insert element of 1st array into unionset/hash
        for(int i = 0 ; i < n ; i++){
            s.insert(a[i]);
        }
        
        //insert element of 2nd array into unionset/hash
        for(int i  = 0 ; i < m ; i++){
            s.insert(b[i]);
        }
        
        return s.size();
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
        unordered_set<int>s;
        unordered_set<int>A(a,a+n);
        
        //insert intersection of element of array in unordered set/hash
        for(int i = 0 ; i < m ; i++){
            if(A.count(b[i]) > 0){
                s.insert(b[i]);
            }
        }
        
        return s.size();
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
    
        for(int i = 0 ; i < n ; i++){
            if(arr[i]-k < 0){
                continue;
            }
          int maxi = max(arr[n-1]-k ,arr[i-1]+k);
           int mini = min(arr[0]+k , arr[i]-k);
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


//10. MINIMUM NUMBER OF JUMPS                                                      {T.C = O(N), S.C = O(1)}
class Solution{
  public:
    int minJumps(int arr[], int n){
        
        int far = 0;                 //far == maximum reachable index
        int curr = 0;
        int jumps = 0;
        
        for(int i = 0 ; i < n-1 ; i++){  //check till second last index
            far = max(far, i + arr[i]);
            if(curr == i){
                jumps++;
                curr = far;
            }
        }
        if(curr < n-1){
            return -1;
        }
        else{
            return jumps;
        }
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
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        //finds cycle is present or not
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        //to find actual number
        fast = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
/*
Input: nums = [1,3,4,2,2]
Output: 2
*/


//12. MERGE 2 SORTED ARRAYS WITHOUT USING EXTRA SPACE   thoda alag h                    {T.C = O(N+M(LOG(M+N))), S.C = O(1)}
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
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& arr) {
       
        sort(arr.begin(), arr.end());

        vector<vector<int>> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i][0] <= ans.back()[1]) {
                ans.back()[1] = max(arr[i][1], ans.back()[1]);
            } else {
                ans.push_back(arr[i]);
            }
        }

        return ans;
    }
};
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


//16. COUNT INVERSION pair
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

/*
Input: N = 5, arr[] = {2, 4, 1, 3, 5}
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 
has three inversions (2, 1), (4, 1), (4, 3).
*/


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





//22. FACTORIAL OF LARGE NUMBER (mt kro)                                                         {T.C = O(N^2), S.C = O(N)}
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
    int findLongestConseqSubseq(int arr[], int n) {
        unordered_set<int> s;

        for (int i = 0; i < n; i++) {
            s.insert(arr[i]);
        }
          for (int i = 0; i < n; i++) {
            if (s.find(arr[i] - 1) == s.end()) {
                int length = 1;

                while (s.find(arr[i] + 1) != s.end()) {
                    arr[i]++;
                   length++;
                }

               int ans = max(ans, length);
            }
        }

        return ans;
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


//26. BUY AND SELL A SHARE AT MOST TWICE  (dont)
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




/*----------------------------------------------------  THE  END    ---------------------------------------------------------*/
