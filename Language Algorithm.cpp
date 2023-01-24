#include <iostream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, int> bag_of_words(std::string text) {
    std::unordered_map<std::string, int> word_count;
    std::string word = "";
    for (char c : text) {
        if (isalnum(c)) {
            word += c;
        } else {
            if (word != "") {
                word_count[word]++;
                word = "";
            }
        }
    }
    if (word != "") {
        word_count[word]++;
    }
    return word_count;
}

int main() {
    std::string text = "This is a test text. It can be any text, but this one is just for testing purposes.";
    std::unordered_map<std::string, int> word_count = bag_of_words(text);
    for (const auto& word : word_count) {
        std::cout << word.first << ": " << word.second << std::endl;
    }
    return 0;
}
