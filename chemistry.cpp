#ifndef CHEMISTRY_HPP
#define CHEMISTRY_HPP

#include "chemistry.hpp"

#include <string>
#include <vector>

namespace chemistry {

double get_atomic_mass(const std::string& symbol) {
  auto el = chemistry::elements.find(symbol);
  if (el != elements.end()) {
    return el->second.atomic_mass;
  } else {
    return -1;  // Element not found
  }
}

std::vector<PartialCompound> get_brokendown_compound(const std::string& chemical_param) {
  // Support parentheses (and nested parentheses) using a stack of maps.
  // Each map accumulates element counts for its level; ')' applies a multiplier to the group.
  std::vector<std::unordered_map<std::string, int>> stack;
  stack.emplace_back();

  size_t i = 0;
  while (i < chemical_param.size()) {
    char ch = chemical_param[i];

    if (ch == '(') {
      stack.emplace_back();
      ++i;

    } else if (ch == ')') {
      // consume ')'
      ++i;
      // parse multiplier (if any)
      int mul = 0;
      while (i < chemical_param.size() && std::isdigit(static_cast<unsigned char>(chemical_param[i]))) {
        mul = mul * 10 + (chemical_param[i] - '0');
        ++i;
      }
      if (mul == 0) mul = 1;

      if (stack.size() < 2) {
        throw std::runtime_error("Unmatched closing parenthesis in formula.");
      }

      auto group = std::move(stack.back());
      stack.pop_back();
      for (const auto& kv : group) {
        stack.back()[kv.first] += kv.second * mul;
      }

    } else if (std::isupper(static_cast<unsigned char>(ch))) {
      // parse element symbol (capital letter followed by zero or more lowercase letters)
      std::string symbol;
      symbol += ch;
      ++i;
      while (i < chemical_param.size() && std::islower(static_cast<unsigned char>(chemical_param[i]))) {
        symbol += chemical_param[i++];
      }

      // parse number (if any)
      int num = 0;
      while (i < chemical_param.size() && std::isdigit(static_cast<unsigned char>(chemical_param[i]))) {
        num = num * 10 + (chemical_param[i] - '0');
        ++i;
      }
      if (num == 0) num = 1;

      stack.back()[symbol] += num;

    } else {
      // ignore unexpected characters (e.g., whitespace)
      ++i;
    }
  }

  if (stack.size() != 1) {
    throw std::runtime_error("Unmatched opening parenthesis in formula.");
  }

  std::vector<PartialCompound> result;
  for (const auto& kv : stack.back()) {
    result.push_back({kv.first, kv.second});
  }
  return result;
}

}  // namespace chemistry

#endif  // CHEMISTRY_HPP