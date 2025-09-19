#include "solution.hpp"

std::string DecodeMessage(const std::string& encoded, const std::map<std::string, std::string>& mapping) {
  if (mapping.empty()) {
    return encoded;
  }

  std::string lowered = encoded;
  for (char& c : lowered) {
    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
  }

  std::string decoded;
  decoded.reserve(encoded.size());
  int n = static_cast<int>(encoded.size());
  int i = 0;
  bool any_replacement = false;

  while (i < n) {
    int best_len = 0;
    const std::string* best_value = nullptr;

    for (const auto& kv : mapping) {
      const std::string& key = kv.first;
      const std::string& val = kv.second;
      int klen = static_cast<int>(key.size());
      if (klen == 0) continue;
      if (i + klen > n) continue;

      bool matches = true;
      for (int j = 0; j < klen; ++j) {
        if (lowered[i + j] != key[j]) {
          matches = false;
          break;
        }
      }
      if (matches && klen > best_len) {
        best_len = klen;
        best_value = &val;
      }
    }

    if (best_len > 0 && best_value != nullptr) {
      decoded += *best_value;
      i += best_len;
      any_replacement = true;
    } else {
      decoded.push_back(encoded[i]);
      ++i;
    }
  }
  
  if (!any_replacement) return encoded;
  return decoded;
}