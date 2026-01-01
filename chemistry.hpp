#pragma once

#include <map>
#include <string>
#include <unordered_map>
#include <vector>

namespace chemistry {

struct Element {
  std::string name;
  std::string symbol;
  double atomic_mass;
  int atomic_number;
};

struct PartialCompound {
  std::string symbol;
  int amount;
};

using element_map = std::unordered_map<std::string, Element>;

const static element_map elements = {
    {"H", {"Hydrogen", "H", 1.008, 1}},
    {"He", {"Helium", "He", 4.002602, 2}},
    {"Li", {"Lithium", "Li", 6.94, 3}},
    {"Be", {"Beryllium", "Be", 9.0122, 4}},
    {"B", {"Boron", "B", 10.81, 5}},
    {"C", {"Carbon", "C", 12.011, 6}},
    {"N", {"Nitrogen", "N", 14.007, 7}},
    {"O", {"Oxygen", "O", 15.999, 8}},
    {"F", {"Fluorine", "F", 18.998, 9}},
    {"Ne", {"Neon", "Ne", 20.180, 10}},
    {"Na", {"Sodium", "Na", 22.990, 11}},
    {"Mg", {"Magnesium", "Mg", 24.305, 12}},
    {"Al", {"Aluminum", "Al", 26.982, 13}},
    {"Si", {"Silicon", "Si", 28.085, 14}},
    {"P", {"Phosphorus", "P", 30.974, 15}},
    {"S", {"Sulfur", "S", 32.06, 16}},
    {"Cl", {"Chlorine", "Cl", 35.45, 17}},
    {"Ar", {"Argon", "Ar", 39.948, 18}},
    {"K", {"Potassium", "K", 39.098, 19}},
    {"Ca", {"Calcium", "Ca", 40.078, 20}},
    {"Sc", {"Scandium", "Sc", 44.956, 21}},
    {"Ti", {"Titanium", "Ti", 47.867, 22}},
    {"V", {"Vanadium", "V", 50.9415, 23}},
    {"Cr", {"Chromium", "Cr", 51.9961, 24}},
    {"Mn", {"Manganese", "Mn", 54.938044, 25}},
    {"Fe", {"Iron", "Fe", 55.845, 26}},
    {"Co", {"Cobalt", "Co", 58.933194, 27}},
    {"Ni", {"Nickel", "Ni", 58.933194, 28}},
    {"Cu", {"Copper", "Cu", 63.546, 29}},
    {"Zn", {"Zinc", "Zn", 65.38, 30}},
    {"Ga", {"Gallium", "Ga", 69.723, 31}},
    {"Ge", {"Germanium", "Ge", 72.63, 32}},
    {"As", {"Arsenic", "As", 74.921595, 33}},
    {"Se", {"Selenium", "Se", 78.971, 34}},
    {"Br", {"Bromine", "Br", 79.904, 35}},
    {"Kr", {"Krypton", "Kr", 83.798, 36}},
    {"Rb", {"Rubidium", "Rb", 85.4678, 37}},
    {"Sr", {"Strontium", "Sr", 87.62, 38}},
    {"Y", {"Yttrium", "Y", 88.90584, 39}},
    {"Zr", {"Zirconium", "Zr", 91.224, 40}},
    {"Nb", {"Niobium", "Nb", 92.90637, 41}},
    {"Mo", {"Molybdenum", "Mo", 95.95, 42}},
    {"Tc", {"Technetium", "Tc", 98, 43}},
    {"Ru", {"Ruthenium", "Ru", 101.07, 44}},
    {"Rh", {"Rhodium", "Rh", 102.90550, 45}},
    {"Pd", {"Palladium", "Pd", 106.42, 46}},
    {"Ag", {"Silver", "Ag", 107.8682, 47}},
    {"Cd", {"Cadmium", "Cd", 112.414, 48}},
    {"In", {"Indium", "In", 114.818, 49}},
    {"Sn", {"Tin", "Sn", 118.710, 50}},
    {"Sb", {"Antimony", "Sb", 121.760, 51}},
    {"Te", {"Tellurium", "Te", 127.60, 52}},
    {"I", {"Iodine", "I", 126.90447, 53}},
    {"Xe", {"Xenon", "Xe", 131.293, 54}},
    {"Cs", {"Cesium", "Cs", 132.90545196, 55}},
    {"Ba", {"Barium", "Ba", 137.327, 56}},
    {"La", {"Lanthanum", "La", 138.904, 57}},
    {"Ce", {"Cerium", "Ce", 140.116, 58}},
    {"Pr", {"Praseodymium", "Pr", 140.90766, 59}},
    {"Nd", {"Neodymium", "Nd", 144.242, 60}},
    {"Pm", {"Promethium", "Pm", 145, 61}},
    {"Sm", {"Samarium", "Sm", 150.36, 62}},
    {"Eu", {"Europium", "Eu", 151.964, 63}},
    {"Gd", {"Gadolinium", "Gd", 157.25, 64}},
    {"Tb", {"Terbium", "Tb", 158.92535, 65}},
    {"Dy", {"Dysprosium", "Dy", 162.500, 66}},
    {"Ho", {"Holmium", "Ho", 164.93033, 67}},
    {"Er", {"Erbium", "Er", 167.259, 68}},
    {"Tm", {"Thulium", "Tm", 168.93422, 69}},
    {"Yb", {"Ytterbium", "Yb", 173.04, 70}},
    {"Lu", {"Lutetium", "Lu", 174.9668, 71}},
    {"Hf", {"Hafnium", "Hf", 178.49, 72}},
    {"Ta", {"Tantalum", "Ta", 180.94788, 73}},
    {"W", {"Tungsten", "W", 183.84, 74}},
    {"Re", {"Rhenium", "Re", 186.207, 75}},
    {"Os", {"Osmium", "Os", 190.23, 76}},
    {"Ir", {"Iridium", "Ir", 192.217, 77}},
    {"Pt", {"Platinum", "Pt", 195.084, 78}},
    {"Au", {"Gold", "Au", 196.966569, 79}},
    {"Hg", {"Mercury", "Hg", 200.592, 80}},
    {"Tl", {"Thallium", "Tl", 204.38, 81}},
    {"Pb", {"Lead", "Pb", 207.2, 82}},
    {"Bi", {"Bismuth", "Bi", 208.98040, 83}},
    {"Po", {"Polonium", "Po", 209, 84}},
    {"At", {"Astatine", "At", 210, 85}},
    {"Rn", {"Radon", "Rn", 222, 86}},
    {"Fr", {"Francium", "Fr", 223, 87}},
    {"Ra", {"Radium", "Ra", 226, 88}},
    {"Ac", {"Actinium", "Ac", 227, 89}},
    {"Th", {"Thorium", "Th", 232.0377, 90}},
    {"Pa", {"Protactinium", "Pa", 231.03588, 91}},
    {"U", {"Uranium", "U", 238.02891, 92}},
    {"Np", {"Neptunium", "Np", 237, 93}},
    {"Pu", {"Plutonium", "Pu", 244, 94}},
    {"Am", {"Americium", "Am", 243, 95}},
    {"Cm", {"Curium", "Cm", 247, 96}},
    {"Bk", {"Berkelium", "Bk", 247, 97}},
    {"Cf", {"Californium", "Cf", 251, 98}},
    {"Es", {"Einsteinium", "Es", 252, 99}},
    {"Fm", {"Fermium", "Fm", 257, 100}},
    {"Md", {"Mendelevium ", "Md ", 258, 101}},
    {"No", {"Nobelium", "No", 259, 102}},
    {"Lr", {"Lawrencium", "Lr", 262, 103}},
    {"Rf", {"Rutherfordium", "Rf", 267, 104}},
    {"Db", {"Dubnium", "Db", 268, 105}},
    {"Sg", {"Seaborgium", "Sg", 271, 106}},
    {"Bh", {"Bohrium", "Bh", 270, 107}},
    {"Hs", {"Hassium", "Hs", 277, 108}},
    {"Mt", {"Meitnerium ", "Mt ", 278, 109}},
    {"Ds", {"Darmstadtium ", "Ds ", 281, 110}},
    {"Rg", {"Roentgenium ", "Rg ", 282, 111}},
    {"Cn", {"Copernicium ", "Cn ", 285, 112}},
    {"Nh", {"Nihonium ", "Nh ", 286, 113}},
    {"Fl", {"Flerovium ", "Fl ", 289, 114}},
    {"Mc", {"Moscovium ", "Mc ", 288, 115}},
    {"Lv", {"Livermorium ", "Lv ", 293, 116}},
    {"Ts", {"Tennessine ", "Ts ", 294, 117}},
    {"Og", {"Oganesson ", "Og ", 294, 118}},
    {"Uut", {"Ununtrium ", "Uut ", 289, 113}}};

double get_atomic_mass(const std::string& symbol);
std::vector<PartialCompound> get_brokendown_compound(const std::string& chemical_param);

}  // namespace chemistry