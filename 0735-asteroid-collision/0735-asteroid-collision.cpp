class Solution {
public:
    #include<stack>
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>s;
        vector<int>ans;
        for(int i=asteroids.size()-1;i>=0;i--){
            if(s.empty()){
                s.push(asteroids[i]);
            }
            else{
                if(asteroids[i]>0 && s.top()<0){
                
                    if(abs(asteroids[i])<abs(s.top())){
                        continue;
                    }
                    else if(abs(asteroids[i])==abs(s.top())){
                        s.pop();
                        continue;
                    }
                    else{
                        while(!s.empty() && !(asteroids[i]>0 && s.top()>0) && abs(asteroids[i])>abs(s.top())){
                            s.pop();
                        }
                        if(!s.empty() && (asteroids[i]>0 && s.top()>0)){
                            s.push(asteroids[i]);
                            continue;
                        }
                        if(s.empty()){
                            s.push(asteroids[i]);
                        }
                        else{
                            if(abs(asteroids[i])<abs(s.top())){
                                continue;
                            }
                            else if(abs(asteroids[i])==abs(s.top())){
                                s.pop();
                                continue;
                            }
                        }
                    }    
                }
                else{
                    s.push(asteroids[i]);
                }
            }
        }
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};