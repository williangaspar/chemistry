#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

#include "chemistry.hpp"

#define CHEMICAL_PARAM "-c"
#define MOLE_PARAM "-m"
#define GRAMS_PARAM "-g"
#define HELP_PARAM "-h"
#define BALANCE_PARAM "-b"

using namespace std;

using string_map = unordered_map<string, string>;

static const vector<string> param_vec = {CHEMICAL_PARAM,
                                         MOLE_PARAM,
                                         GRAMS_PARAM};

string_map read_arguments(int argc, char* argv[]) {
  string_map param;

  if (argc < 3) {
    if (argc == 2) {
      const std::string arg = argv[1];
      if (arg == HELP_PARAM) {
        param[HELP_PARAM] = "";
        return param;
      }
    }

    std::cerr << "Not enough arguments provided." << std::endl;
    exit(0);
  }

  for (int i = 1; i < argc; ++i) {
    const std::string arg = argv[i];

    const auto it = std::find(param_vec.begin(), param_vec.end(), arg);

    if (it != param_vec.end()) {
      if (i + 1 >= argc) {
        std::cerr << "No value provided for argument: " << arg << std::endl;
        exit(0);
      }

      param[arg] = argv[i + 1];
      ++i;  // Skip the next argument as it's the value for the current parameter
    } else {
      std::cerr << "Invalid argument: " << arg << std::endl;
      exit(0);
    }
  }

  return param;
}

double get_compound_mole_mass(const string& compound_name) {
  double total_mass = 0.0;

  auto chemical = chemistry::get_brokendown_compound(compound_name);

  for (const auto& el : chemical) {
    const auto mass = chemistry::get_atomic_mass(el.symbol);
    if (mass == -1) {
      std::cerr << "Element not found: " << el.symbol << std::endl;
      exit(0);
    }

    total_mass += mass * el.amount;
  }

  return total_mass;
}

int main(int argc, char* argv[]) {
  const auto param = read_arguments(argc, argv);

  const auto help_it = param.find(HELP_PARAM);
  if (help_it != param.end()) {
    std::cout << "Usage: " << std::endl;
    std::cout << argv[0] << " " << CHEMICAL_PARAM
              << " <chemical_formula> [" << MOLE_PARAM
              << " <moles>] [" << GRAMS_PARAM << " <grams>]  * for molar mass" << std::endl;
    std::cout << argv[0] << " " << HELP_PARAM << "  * For help" << std::endl;
    std::cout << argv[0] << " " << BALANCE_PARAM << " <equation>  * For balance an equation" << std::endl;
    return 0;
  }

  const auto compound_it = param.find(CHEMICAL_PARAM);

  if (compound_it == param.end()) {
    std::cerr << "Chemical symbol not provided." << std::endl;
    exit(0);
  }

  const auto& compound_name = compound_it->second;

  const double mass = get_compound_mole_mass(compound_name);

  std::cout << std::fixed << std::setprecision(4);

  if (argc == 3) {
    std::cout << "Molar mass of " << compound_name << " is: " << mass
              << " g/mol" << std::endl;
    exit(0);
  }

  const auto mole_it = param.find(MOLE_PARAM);
  if (mole_it != param.end()) {
    const double moles = std::stod(mole_it->second);
    std::cout << "Mass of " << moles << " moles of " << compound_name
              << " is: " << mass * moles << " g" << std::endl;
  }

  const auto grams_it = param.find(GRAMS_PARAM);
  if (grams_it != param.end()) {
    const double grams = std::stod(grams_it->second);
    std::cout << grams << " grams of " << compound_name
              << " is: " << grams / mass << " moles" << std::endl;
  }

  const auto balance_it = param.find(BALANCE_PARAM);
  if (balance_it != param.end()) {
    std::cout << "Chemical equation balancing is not implemented yet." << std::endl;
  }

  return 0;
}