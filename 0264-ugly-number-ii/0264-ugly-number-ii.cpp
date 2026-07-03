// class Solution {
// public:

//     int nthUglyNumber(int n) {

//         vector<long long>ans;

//         priority_queue<long long , vector<long long> , greater<long long>>q;

//         q.push(1);

//         while(n > 0 && !q.empty()){

//             long long val = q.top();
//             q.pop();

//             if(ans.size() == 0 || ans.back() != val){
//                 ans.push_back(val);
//                 n--;

//                 q.push(val * 2);
//                 q.push(val * 3);
//                 q.push(val * 5);
//             }
//         }

//         return ans.back();
//     }
// };



class Solution {
public:

    int nthUglyNumber(int n) {

        vector<int>ans(n+1);

        ans[1] = 1;

        int i2 = 1 , i3 = 1 , i5 = 1;

        for(int i = 2; i <= n; i++){

            int val2 = ans[i2] * 2;
            int val3 = ans[i3] * 3;
            int val5 = ans[i5] * 5;

            int mini = min(val2 , min(val3 , val5));
            ans[i] = mini;
            
            if(mini == val2){
                i2++;
            }

            if(mini == val3){
                i3++;
            }

            if(mini == val5){
                i5++;
            }
        }

        return ans[n];
    }
};