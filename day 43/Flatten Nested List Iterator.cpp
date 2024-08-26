class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
            stack.push(*it);
        }
    }
    
    int next() {
        if (hasNext()) {
            NestedInteger top = stack.top();
            stack.pop();
            return top.getInteger();
        }
        return -1; 
    }
    
    bool hasNext() {
        while (!stack.empty()) {
            NestedInteger top = stack.top();
            if (top.isInteger()) {
                return true;
            }
            stack.pop();
            const vector<NestedInteger>& nestedList = top.getList();
            for (auto it = nestedList.rbegin(); it != nestedList.rend(); ++it) {
                stack.push(*it);
            }
        }
        return false;
    }

private:
    stack<NestedInteger> stack;
};
