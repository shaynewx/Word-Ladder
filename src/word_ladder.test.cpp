#include "word_ladder.h"

#include <catch2/catch.hpp>
#include <string>

TEST_CASE("word_ladder::read_lexicon works as expected") {
	auto const lexicon = word_ladder::read_lexicon("./english.txt");

	// Check if some specific words are contained
	REQUIRE(lexicon.find("aa") != lexicon.end());
	REQUIRE(lexicon.find("aah") != lexicon.end());
	REQUIRE(lexicon.find("zyzzyvas") != lexicon.end());

	// check the total number of words in the dictionary
	REQUIRE(lexicon.size() == 127142);
}

TEST_CASE("at -> it") {
	auto const lexicon = std::unordered_set<std::string>{"at", "it"};

	const auto expected = std::vector<std::vector<std::string>>{{"at", "it"}};

	auto const ladders = word_ladder::generate("at", "it", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("airplane -> tricycle") {
	auto const lexicon = std::unordered_set<std::string>{"airplane", "tricycle"};

	const auto expected = std::vector<std::vector<std::string>>{};

	auto const ladders = word_ladder::generate("airplane", "tricycle", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("awake -> sleep") {
	auto const lexicon = std::unordered_set<std::string>{
	    "awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep",
	    "sharn", "shawn", "shewn", "sheen"
	};

	const auto expected = std::vector<std::vector<std::string>>{
	    {"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"},
	    {"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"}
	};
	auto const ladders = word_ladder::generate("awake", "sleep", lexicon);

	CHECK(ladders == expected);
}