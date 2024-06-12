#include "word_ladder.h"

#include <catch2/catch.hpp>
#include <iostream>
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

TEST_CASE("lead -> land") {
	auto const lexicon = std::unordered_set<std::string>{"lead", "land"};

	const auto expected = std::vector<std::vector<std::string>>{{"lead", "lend", "load"}};

	auto const ladders = word_ladder::generate("lead", "load", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("airplane -> tricycle") {
	auto const lexicon = std::unordered_set<std::string>{"airplane", "tricycle"};

	const auto expected = std::vector<std::vector<std::string>>{};

	auto const ladders = word_ladder::generate("airplane", "tricycle", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("Cat -> Dog") {
	auto const lexicon = std::unordered_set<std::string>{"Cat","cat" , "cot", "cog", "dot", "dog", "Dog"};

	const auto expected = std::vector<std::vector<std::string>>{{"cat", "cot", "cog", "dog"},{"cat", "cot", "dot", "dog"}};

	auto const ladders = word_ladder::generate("Cat", "Dog", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("awake -> sleep") {
	auto const lexicon = std::unordered_set<std::string>{"awake",
	                                                     "aware",
	                                                     "sware",
	                                                     "share",
	                                                     "shire",
	                                                     "shirr",
	                                                     "shier",
	                                                     "sheer",
	                                                     "sheep",
	                                                     "sleep",
	                                                     "sharn",
	                                                     "shawn",
	                                                     "shewn",
	                                                     "sheen"};

	const auto expected = std::vector<std::vector<std::string>>{
	    {"awake", "aware", "sware", "share", "sharn", "shawn", "shewn", "sheen", "sheep", "sleep"},
	    {"awake", "aware", "sware", "share", "shire", "shirr", "shier", "sheer", "sheep", "sleep"}};
	auto const ladders = word_ladder::generate("awake", "sleep", lexicon);

	CHECK(ladders == expected);
}

TEST_CASE("work -> play") {
	auto const lexicon = std::unordered_set<std::string>{"work", "fork", "form", "foam", "flam", "flay", "play", "pork",
	                                                     "perk", "peak", "pean", "plan", "peat", "plat", "pert", "porn",
	                                                     "pirn", "pian", "port", "word", "wood", "pood", "plod", "ploy",
	                                                     "worm", "worn", "wort", "bort", "boat", "blat", "wert"};

	const auto expected =
	    std::vector<std::vector<std::string>>{{"work", "fork", "form", "foam", "flam", "flay", "play"},
	                                          {"work", "pork", "perk", "peak", "pean", "plan", "play"},
	                                          {"work", "pork", "perk", "peak", "peat", "plat", "play"},
	                                          {"work", "pork", "perk", "pert", "peat", "plat", "play"},
	                                          {"work", "pork", "porn", "pirn", "pian", "plan", "play"},
	                                          {"work", "pork", "port", "pert", "peat", "plat", "play"},
	                                          {"work", "word", "wood", "pood", "plod", "ploy", "play"},
	                                          {"work", "worm", "form", "foam", "flam", "flay", "play"},
	                                          {"work", "worn", "porn", "pirn", "pian", "plan", "play"},
	                                          {"work", "wort", "bort", "boat", "blat", "plat", "play"},
	                                          {"work", "wort", "port", "pert", "peat", "plat", "play"},
	                                          {"work", "wort", "wert", "pert", "peat", "plat", "play"}};
	auto const ladders = word_ladder::generate("work", "play", lexicon);

	CHECK(ladders == expected);
}