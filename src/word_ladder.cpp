#include "word_ladder.h"
#include <algorithm>
#include <fstream> // for std::ifstream
#include <iostream>
#include <queue> // for std::queue

auto word_ladder::read_lexicon(const std::string& path) -> std::unordered_set<std::string> {
	std::unordered_set<std::string> lexicon;
	std::ifstream file(path); // open the file

	// insert each word of the line to the lexicon (skip every empty line)
	std::string word;
	while (std::getline(file, word)) {
		if (!word.empty()) {
			lexicon.emplace(std::move(word));
		}
	}

	return lexicon;
}

auto word_ladder::generate(const std::string& from,
                           const std::string& to,
                           const std::unordered_set<std::string>& lexicon) -> std::vector<std::vector<std::string>> {
	std::vector<std::vector<std::string>> result; // the vector of word ladders

	std::unordered_set<std::string> filtered_lexicon;
	size_t length = from.size();
	// keep those words with the same length as start word
	std::copy_if(lexicon.begin(),
	             lexicon.end(),
	             std::inserter(filtered_lexicon, filtered_lexicon.end()),
	             [length](const std::string& word) { return word.size() == length; });

	std::queue<std::vector<std::string>> queue; // use queue to store words which wait to search next hop
	std::unordered_set<std::string> visited; // use set to store words have been visited
	queue.push({from}); // initialize the queue by push the vector of first word

	// for each word in the queue, search for the word with same length but with one letter difference while queue is
	// not empty
	while (!queue.empty()) {
		size_t current_size = queue.size();
		std::unordered_set<std::string> to_be_visited; // record the words have been visited in this layer

		// iterate over each vector in the queue
		for (size_t i = 0; i < current_size; i++) {
			std::vector<std::string> path = queue.front();
			queue.pop(); // select the first element of the queue, store it and pop it out
			std::string current_word = path.back(); // store the last word in the path and then search for next hop

			// transform each character position of current_word
			for (size_t pos = 0; pos < current_word.length(); ++pos) {
				char original_char = current_word[pos];
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == original_char)
						continue;
					current_word[pos] = c;
					// only handle those words which is in the filtered_lexicon and have not been visited
					if (filtered_lexicon.contains(current_word) and !visited.contains(current_word)) {
						std::vector<std::string> new_path = path;
						new_path.push_back(current_word); // create a new path and add the word into it
						if (current_word == to) {
							result.push_back(new_path);
						}
						queue.push(new_path);
						to_be_visited.insert(current_word);
					}
				}
				current_word[pos] = original_char; // restore to the original character
			}
		}
		visited.insert(to_be_visited.begin(), to_be_visited.end()); // update the set of visited words
	}

	std::sort(result.begin(), result.end()); // sort the solutions in lexicographical order
	for (const auto& ladder : result) {
		for (const auto& word : ladder) {
			std::cout << word << " ";
		}
		std::cout << std::endl;
	}

	return result;
}