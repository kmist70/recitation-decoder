#include "solution.hpp"

std::string DecodeMessage(const std::string& encoded, const std::map<std::string, std::string>& mapping) {
  std::string lowered_message = encoded;
  std::string decoded_message;

  // makes passed message lowercase
  for (char &c : lowered_message) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }

  // parse string by character and check if it exists in the map
  int i = 0;
  while (i < static_cast<int>(lowered_message.length())) {
    bool match_made = false;

    // check if value exists in the map
    for (const auto& [key, value] : mapping) {
      int key_length = static_cast<int>(key.size());

      if (i + key_length <= static_cast<int>(lowered_message.size()) && lowered_message.substr(i, key_length) == key) {
        decoded_message += value;
        i += key_length;
        match_made = true;
        break;
      }
    }

    // adds char to result string if match was not made
    if (!(match_made)) {
      decoded_message += lowered_message[i];
      i++;
    }
  }
  
  return decoded_message;
}
