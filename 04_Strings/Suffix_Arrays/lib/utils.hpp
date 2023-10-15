#ifndef UTILS_H
#define UTILS_H

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

class SuffixArray {
	private:
    	std::vector<std::string> suffixes;
		std::vector<int> positions;

  	public:
    	SuffixArray(const std::string &s) {
			suffixes.push_back("$");
      		for (int i = s.length() - 1; i > -1; i--) {
				std::stringstream ss;
				ss << s.substr(i) << "$";
        		suffixes.push_back(ss.str());
			}

			// Temporal vector find the position of the suffixes
			std::vector<std::string> temp(suffixes);
			
      		std::sort(++suffixes.begin(), suffixes.end());

			for (std::string s: suffixes) {
				auto it = std::find(temp.begin(), temp.end(), s);
				int pos = temp.size() - (it - temp.begin());
				positions.push_back(pos);
			}
    	}

		friend std::ostream& operator<<(std::ostream& os, const SuffixArray& arr) {
      		os  << "[" << arr.positions[0];

      		for (int i = 1; i < arr.positions.size(); i++)
        		os << ", " << arr.positions[i];
			
			os << "]";

      		return os;
    	}


    	/* friend std::ostream& operator<<(std::ostream& os, const SuffixArray& arr) {
      		os << arr.suffixes[0];

      		for (int i = 1; i < arr.suffixes.size(); i++)
        		os << ", " << arr.suffixes[i];

      		return os;
    	} */
};


#endif