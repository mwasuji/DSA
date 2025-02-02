class BrowserHistory {
    stack<string> browserstack, fwdstack;
public:
    BrowserHistory(string homepage) {
        browserstack.push(homepage);
    }
    
    void visit(string url) {
        while (!fwdstack.empty()) {
            fwdstack.pop();
        }
        browserstack.push(url);
    }
    
    string back(int steps) {
        while (steps-- && browserstack.size() > 1) {
            fwdstack.push(browserstack.top());
            browserstack.pop();
        }
        return browserstack.top();
    }
    
    string forward(int steps) {
        while (steps-- && !fwdstack.empty()) {
            browserstack.push(fwdstack.top());
            fwdstack.pop();
        }
        return browserstack.top();
    }
};