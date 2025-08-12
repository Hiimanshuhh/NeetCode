class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
         if (strs.size() == 0) {
        return {};
    }

    // Map to store the groups
    // Key: string representing letter counts
    // Value: vector of original words that match that key
    unordered_map<string, vector<string>> ansMap;

    // Loop through each word in the input
    for (int i = 0; i < strs.size(); i++) {
        // Step 1: Create a count array for 26 lowercase letters
        int count[26];
        fill(count, count + 26, 0); // initialize with zeros

        // Step 2: Count the frequency of each character in the word
        string currentWord = strs[i];
        for (int j = 0; j < currentWord.size(); j++) {
            char c = currentWord[j];
            count[c - 'a']++;
        }

        // Step 3: Create a key from the count array
        // Format: "#<count_of_a>#<count_of_b>#..." to avoid ambiguity
        stringstream ss;
        for (int k = 0; k < 26; k++) {
            ss << "#" << count[k];
        }
        string key = ss.str();

        // Step 4: Add the word to the map
        if (ansMap.find(key) == ansMap.end()) {
            ansMap[key] = vector<string>(); // create new vector if key not present
        }
        ansMap[key].push_back(currentWord);
    }

    // Step 5: Collect all the values from the map into a result vector
    vector<vector<string>> result;
    for (unordered_map<string, vector<string>>::iterator it = ansMap.begin(); it != ansMap.end(); it++) {
        result.push_back(it->second);
    }

    return result;
    }
};