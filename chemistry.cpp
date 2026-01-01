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

  for (size_t i = 0; i < chemical_param.size(); ++i) {
    const char ch = chemical_param[i];
    if (std::isupper(ch) == true) {
      if (temp_chemical.size() > 0) {
        chemical.push_back({temp_chemical, 1});
        temp_chemical.clear();
      }

      temp_chemical += ch;

    } else if (std::isdigit(ch) == true) {
      chemical.push_back({temp_chemical, (ch - '0')});
      const char next_ch = (i + 1 < chemical_param.size()) ? chemical_param[i + 1] : '\0';

      /* If the compound have more than 99 atoms of a particular element, this code will break.
      I don't care. Go take your monster molecule somewhere else. */
      if (std::isdigit(next_ch) == true) {
        chemical.back().amount = chemical.back().amount * 10 + (next_ch - '0');
        ++i;
      }

      temp_chemical.clear();
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