/*
 * MostFreqString.cpp
 *
 *  Created on: Dec 28, 2019
 *      Author: HY
 */


#include <iostream>
#include <map>
#include <iterator>

using namespace std;

int MostFreqString(string str, string* feature) {
	string word = "";
	map<string, int> feature_map;
	map<string, int>::iterator itr;
	multimap<int, string, greater <int>> order_feature_map;
	multimap<int, string>::iterator order_itr;

	for (int i = 0; i < 7; i++) {
		feature_map.insert(pair<string, int>(feature[i], 0));
	}

	for (auto x : str) {
		if (x == ' ' || x == '.') {
			itr = feature_map.find(word);
			if (itr != feature_map.end()) {
				itr->second++;
			}
			word = "";
		} else {
			word += x;
		}
	}

	itr = feature_map.find(word);
	if (itr != feature_map.end()) {
		itr->second++;
	}

	for (itr = feature_map.begin(); itr != feature_map.end(); ++itr) {
		order_feature_map.insert(pair<int, string>(itr->second, itr->first));
	}

	for (order_itr = order_feature_map.begin(); order_itr != order_feature_map.end(); ++order_itr) {
		cout << '\t' << order_itr->first
		     << '\t' << order_itr->second << '\n';
	}

	return 0;
}


int main() {
	string str = " This is the price testing battery waterproof design asdasd screen 123123 screen";
	string feature[7] = {"battery", "screen", "waterproof", "life", "design", "size", "price"};
	MostFreqString(str, feature);
	return 0;
}
