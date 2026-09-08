class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> record;

        for (string& op : operations) {
            if (op == "+") {
                int top = record.top();
                record.pop();
                int newTop = record.top();
                record.push(top);             
                record.push(top + newTop);     
            } else if (op == "D") {
                record.push(record.top() * 2);
            } else if (op == "C") {
                record.pop();
            } else {
                record.push(stoi(op)); 
            }
        }

        int sum = 0;
        stack<int> temp = record; 
        while (!temp.empty()) {
            sum += temp.top();
            temp.pop();
        }

        return sum;
    }
};