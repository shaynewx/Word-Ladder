#include "word_ladder.h"
#include <fstream> // for std::ifstream
#include <queue> // for std::queue
#include <stdexcept> // for std::runtime_error
#include <algorithm>

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
			lexicon.emplace(std::move(worlad));
		}
	}

	return lexicon;
}

auto word_ladder::generate(const std::string& from,
                           const std::string& to,
                           const std::unordered_set<std::string>& lexicon) -> std::vector<std::vector<std::string>> {
	std::vector<std::vector<std::string>> result; // 储存单词阶梯的vector

	// 搜索出所有与from长度一致，且只相差一个字母的单词，然后在lexicon中查看这些单词是否存在，如果存在则存入queue中
	std::queue<std::vector<std::string>> queue; // 使用queue储存待访问单词
	std::unordered_set<std::string> visited; // 使用set储存已访问单词
	queue.push({from}); // 初始化queue
	visited.insert(from); // 初始化visited

	// 当队列不为空时，对queue中每个单词寻找与之长度一样但相差一个字母的单词
	while (!queue.empty()) {
		size_t current_size = queue.size();
		// 依次遍历queue中的单词
		for (size_t i = 0; i < current_size; i++) {
			std::vector<std::string> path = queue.front();
			queue.pop(); // 选择queue的第一个单词，储存并pop出去
			std::string current_word = path.back(); // 储存路径中最后一个单词，然后搜寻下一层单词的
			for (size_t pos = 0; pos < current_word.length(); ++pos) { // 对current_word的每个字符位置进行变换，尝试a-z
				char original_char = current_word[pos]; // 当前字母
				for (char c = 'a'; c <= 'z'; ++c) {
					if (c == original_char)
						continue; // 如果字母是原始字母就跳过
					current_word[pos] = c; // 更改字符
					// 只有那些既存在于字典中又未被之前的搜索路径访问过的单词才会被处理
					if (lexicon.find(current_word) != lexicon.end() and visited.find(current_word) == visited.end()) {
						visited.insert(current_word); // 将当前单词添加到已访问集合中，记录下这个单词已经被使用过
						std::vector<std::string> new_path = path; // 创建一个新的路径
						new_path.push_back(current_word); // 将当前单词添加到新路径的末尾
						if (current_word == to) {
							result.push_back(new_path);
						}
						queue.push(new_path);
					}
					current_word[pos] = original_char; // 恢复原始字符
				}
			}
		}
	}

	return result; // 返回结果，如果没有找到路径则为空
}