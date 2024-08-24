# Word Ladder Library

A C++ library for generating word ladders, demonstrating the use of C++ Standard Library containers and algorithms.

## Overview

This library provides a back-end for generating word ladders—a sequence of words connecting two given words by changing one letter at a time, with each intermediate word being valid. The shortest path from the start word to the destination word is guaranteed using the breadth-first search algorithm.

### What is a Word Ladder?

A word ladder connects one word to another by altering one letter at a time, ensuring each intermediate step is a valid word. For example, a word ladder from "code" to "data" could look like:

```
code -> cade -> cate -> date -> data
```

The library ensures all possible shortest paths are found and returned in lexicographical order.

### Features

- Utilizes C++ Standard Library containers such as `std::vector`, `std::queue`, and `std::unordered_set`.
- Implements breadth-first search to find the shortest word ladder between two words.
- Supports large lexicons and provides efficient search and manipulation of word ladders.

## Installation

To include the Word Ladder library in your project:

1. Clone the repository:
    ```sh
    git clone git@github.com:shaynewx/Word-Ladder.git
    ```
2. Include the library files in your project:
    - `src/word_ladder.h`
    - `src/word_ladder.cpp`

3. Compile your project using a C++ compiler that supports C++17 or later.

## Usage

Include the header file in your source file and use the provided functions to generate word ladders:

```cpp
#include "word_ladder.h"

int main() {
    auto lexicon = word_ladder::read_lexicon("path/to/lexicon.txt");
    auto ladders = word_ladder::generate("start", "end", lexicon);

    for (const auto& ladder : ladders) {
        for (const auto& word : ladder) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
```

## Functionality

### `word_ladder::generate`

Generates all shortest word ladders between a start word and an end word.

- **Parameters:**
    - `const std::string& start`: The starting word.
    - `const std::string& end`: The destination word.
    - `const std::unordered_set<std::string>& lexicon`: A set of valid words.

- **Returns:** `std::vector<std::vector<std::string>>` - A vector of word ladders, each represented as a vector of strings.

### `word_ladder::read_lexicon`

Reads a lexicon from a file.

- **Parameters:**
    - `const std::string& path`: The path to the lexicon file.

- **Returns:** `std::unordered_set<std::string>` - A set of valid words.

## Testing

Unit tests are provided in `word_ladder_test.cpp` to ensure the correctness and efficiency of the library. To run the tests:

1. Configure your project with CMake in the root directory:
    ```sh
    cmake -B build
    ```
2. Build the project:
    ```sh
    cd build
    make
    ```
3. Run the tests:
    ```sh
    ctest
    ```

## Benchmarking

The library includes a benchmark utility to test performance with large datasets. To run the benchmark:

1. Compile in Release mode for optimal performance:
    ```sh
    cmake -DCMAKE_BUILD_TYPE=Release -B build
    cd build
    make word_ladder_benchmark_exe
    ```
2. Execute the benchmark:
    ```sh
    ./word_ladder_benchmark
    ```

## Contribution

Contributions are welcome! Please fork the repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Attribution

This project is based on an original assignment developed for educational purposes. All credit goes to the original creator of the assignment for the foundational concept and structure of this word ladder project.

---

This version includes an "Attribution" section at the end of the README to acknowledge the original creator of the project.