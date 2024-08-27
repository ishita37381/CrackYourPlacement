class Solution {
public:
    bool isNumber(string s) {
// On each character match and see if previous state is valid, if yes set current state and continue else return false
        int tracker = 0;
        bool dec_flag = false;
        for(auto c: s) {
            if(c == '+' || c == '-') {
                if (tracker == 0) { tracker = 1; } else if (tracker == 5) { tracker = 6; } else { return false; }
            } else if (c == 'e' || c == 'E') {
                if (tracker <= 4 && tracker !=0 && tracker !=1 ) { tracker = 5; } else { return false; }
            } else if (c == '.') {
                if ( tracker <= 2  ) { if(tracker == 0 || tracker == 1) {dec_flag = true;} tracker = 3; } else { return false; }
            } else if ( c <= 57 && c >= 48) {
                if (tracker <= 2) { tracker = 2; } else if ( tracker == 3 ) { tracker = 4;dec_flag = false; } else if ( tracker == 4) { tracker = 4; } else if ( tracker == 5 || tracker == 6 || tracker == 7) { tracker = 7; } else {
                    return false;
                } 
            } else {
                return false;
            }
        }
        if (dec_flag == true) {
            return false;
        }
        if (tracker == 2 || tracker == 3 || tracker == 4 || tracker ==7) {
            return true;
        } else {
            return false;
        }
    }
};
