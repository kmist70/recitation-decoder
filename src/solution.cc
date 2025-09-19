#include "solution.hpp"

std::string DecodeMessage(const std::string& encoded, const std::map<std::string, std::string>& mapping) {
  std::string lowered_message = encoded;
  std::string decoded_message;

  // makes passed message lowercase
  for (char &c : lowered_message) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }

  // parse string by character and check if it exists in the map
  for (unsigned int i = 0; i < lowered_message.length(); ++i) {
    
  }

  // // CAUSES ISSUES DOWN THE LINE populates vector by word
  // std::vector<std::string> word_list;
  // std::string single_word;
  // for (unsigned int i = 0; i < lowered_message.length(); ++i) {
  //   if (lowered_message[i] == ' ') {
  //     word_list.push_back(single_word);
  //     single_word = "";
  //   } else {
  //     single_word += word_list[i];
  //   }
  // }
  
  // // checks keys in mapping for decoded phrases
  // for (unsigned int i = 0; i < word_list.size(); ++i) {
  //   std::string phrase_to_find;
  //   for (unsigned int j = i + 1; j < word_list.size(); ++j) {

  //   }
  // }
  
  
  return decoded_message;
}
