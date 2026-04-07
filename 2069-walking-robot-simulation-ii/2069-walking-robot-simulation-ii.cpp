class Robot {
private:
    int w, h;
    int x, y;
    int dir;
    vector<string> directions = {"East", "North", "West", "South"};
    vector<pair<int,int>> moves = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    int cycle;

public:
    Robot(int width, int height) {
        w = width;
        h = height;
        x = 0;
        y = 0;
        dir = 0;
        cycle = 2 * (w + h) - 4;
    }
    
    void step(int num) {
        num %= cycle;
        if (num == 0) num = cycle;
        
        while (num--) {
            int nx = x + moves[dir].first;
            int ny = y + moves[dir].second;

            if (nx < 0 || nx >= w || ny < 0 || ny >= h) {
                dir = (dir + 1) % 4;
                nx = x + moves[dir].first;
                ny = y + moves[dir].second;
            }

            x = nx;
            y = ny;
        }
    }
    
    vector<int> getPos() {
        return {x, y};
    }
    
    string getDir() {
        return directions[dir];
    }
};