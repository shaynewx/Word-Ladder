#include "word_ladder.h"
#include <fstream> // for std::ifstream
#include <stdexcept> // for std::runtime_error
#include <queue> // for std::queue

auto word_ladder::read_lexicon(const std::string& path) -> std::unordered_set<std::string> {
	std::unordered_set<std::string> lexicon;
	std::ifstream file(path); // open the file
	if (!file) {
		throw std::runtime_error("Unable to open file: " + path); // throw an error if the file cannot open
	}

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
	(void)from;
	(void)to;
	(void)lexicon;
	// remove this line once implemented

	return {};
}