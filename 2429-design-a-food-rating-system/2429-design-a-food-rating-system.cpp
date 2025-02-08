#include <bits/stdc++.h>
using namespace std;

class FoodRatings {
public:
    struct compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) const {
            if (a.first != b.first) return a.first < b.first;  // Higher rating last
            return a.second > b.second;  // Lexicographically smaller last if tie
        }
    };

    map<string, int> fr; // Food -> Rating
    map<string, set<pair<int, string>, compare>> cs; // Cuisine -> (Rating, Food)
    map<string, string> fc; // Food -> Cuisine

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            fr[foods[i]] = ratings[i];
            fc[foods[i]] = cuisines[i];
            cs[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating) {
        string curCuisine = fc[food];
        auto& cuisineSet = cs[curCuisine];
        
        cuisineSet.erase({fr[food], food});  // Remove old rating
        fr[food] = newRating;                // Update rating
        cuisineSet.insert({newRating, food}); // Insert new rating
    }

    string highestRated(string cuisine) {
        return cs[cuisine].rbegin()->second; // Get highest-rated food
    }
};
