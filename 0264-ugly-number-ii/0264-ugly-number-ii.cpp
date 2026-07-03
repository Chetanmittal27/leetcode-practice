class Solution {
public:

    int nthUglyNumber(int n) {

        vector<long long>ans;

        priority_queue<long long , vector<long long> , greater<long long>>q;

        q.push(1);

        while(n > 0 && !q.empty()){

            long long val = q.top();
            q.pop();

            if(ans.size() == 0 || ans.back() != val){
                ans.push_back(val);
                n--;

                q.push(val * 2);
                q.push(val * 3);
                q.push(val * 5);
            }
        }

        return ans.back();
    }
};