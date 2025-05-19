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
  std::vector<PartialCompound> chemical;

  std::string temp_chemical;

  for (auto& ch : chemical_param) {
    if (std::isupper(ch) == true) {
      if (temp_chemical.size() > 0) {
        chemical.push_back({temp_chemical, 1});
        temp_chemical.clear();
      }

      temp_chemical += ch;

    } else if (std::isdigit(ch) == true) {
      chemical.push_back({temp_chemical, 1});
      temp_chemical.clear();
      chemical[chemical.size() - 1].amount = ch - '0';
    } else {
      temp_chemical += ch;
    }
  }

  if (!temp_chemical.empty()) {
    chemical.push_back({temp_chemical, 1});
  }

  return chemical;
}

}  // namespace chemistry

#endif  // CHEMISTRY_HPP