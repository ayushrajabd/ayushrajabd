class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        struct EventInfo {
            int time;
            int type; 
            int index;
        };

        vector<EventInfo> sortedEvents;
        for (int i = 0; i < events.size(); ++i) {
            int t = stoi(events[i][1]);
            // Type 0 for OFFLINE (processed first), 1 for MESSAGE
            int type = (events[i][0] == "OFFLINE") ? 0 : 1;
            sortedEvents.push_back({t, type, i});
        }

        sort(sortedEvents.begin(), sortedEvents.end(), [](const EventInfo& a, const EventInfo& b) {
            if (a.time != b.time) return a.time < b.time;
            return a.type < b.type;
        });

        vector<int> mentions(numberOfUsers, 0);
        vector<int> onlineTime(numberOfUsers, 0); 

        for (const auto& evt : sortedEvents) {
            int currTime = evt.time;
            const vector<string>& originalEvent = events[evt.index];

            if (evt.type == 0) { 
                int userId = stoi(originalEvent[2]);
                onlineTime[userId] = currTime + 60;
            } else { 
                string mentionStr = originalEvent[2];
                if (mentionStr == "ALL") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        mentions[i]++;
                    }
                } else if (mentionStr == "HERE") {
                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (onlineTime[i] <= currTime) {
                            mentions[i]++;
                        }
                    }
                } else {
                    stringstream ss(mentionStr);
                    string token;
                    while (ss >> token) {
                        if (token.substr(0, 2) == "id") {
                            int userId = stoi(token.substr(2));
                            mentions[userId]++;
                        }
                    }
                }
            }
        }

        return mentions;
    }
};