class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        for(int i=0;i<students.size();i++)
        {
            q.push(students[i]);
            s.push(sandwiches[sandwiches.size()-1-i]);
        }
        int sw=0;
        while(sw!=q.size() && q.size()!=0)
        {
            if(q.front()==s.top())
            {
                sw=0;
                q.pop();
                s.pop();
            }
            else
            {
                sw+=1;
                int x=q.front();
                q.pop();
                q.push(x);
            }
        }
        return sw;

        
    }
};