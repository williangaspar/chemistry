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
  std::string group;
};

struct PartialCompound {
  std::string symbol;
  int amount;
};

using element_map = std::unordered_map<std::string, Element>;

const static element_map elements = {
    {"H", {"Hydrogen", "H", 1.008, 1, "Nonmetal"}},
    {"He", {"Helium", "He", 4.002602, 2, "Noble Gas"}},
    {"Li", {"Lithium", "Li", 6.94, 3, "Alkali Metal"}},
    {"Be", {"Beryllium", "Be", 9.0122, 4, "Alkaline Earth Metal"}},
    {"B", {"Boron", "B", 10.81, 5, "Metalloid"}},
    {"C", {"Carbon", "C", 12.011, 6, "Nonmetal"}},
    {"N", {"Nitrogen", "N", 14.007, 7, "Nonmetal"}},
    {"O", {"Oxygen", "O", 15.999, 8, "Nonmetal"}},
    {"F", {"Fluorine", "F", 18.998, 9, "Halogen"}},
    {"Ne", {"Neon", "Ne", 20.180, 10, "Noble Gas"}},
    {"Na", {"Sodium", "Na", 22.990, 11, "Alkali Metal"}},
    {"Mg", {"Magnesium", "Mg", 24.305, 12, "Alkaline Earth Metal"}},
    {"Al", {"Aluminum", "Al", 26.982, 13, "Post-transition Metal"}},
    {"Si", {"Silicon", "Si", 28.085, 14, "Metalloid"}},
    {"P", {"Phosphorus", "P", 30.974, 15, "Nonmetal"}},
    {"S", {"Sulfur", "S", 32.06, 16, "Nonmetal"}},
    {"Cl", {"Chlorine", "Cl", 35.45, 17, "Halogen"}},
    {"Ar", {"Argon", "Ar", 39.948, 18, "Noble Gas"}},
    {"K", {"Potassium", "K", 39.098, 19, "Alkali Metal"}},
    {"Ca", {"Calcium", "Ca", 40.078, 20, "Alkaline Earth Metal"}},
    {"Sc", {"Scandium", "Sc", 44.956, 21, "Transition Metal"}},
    {"Ti", {"Titanium", "Ti", 47.867, 22, "Transition Metal"}},
    {"V", {"Vanadium", "V", 50.9415, 23, "Transition Metal"}},
    {"Cr", {"Chromium", "Cr", 51.9961, 24, "Transition Metal"}},
    {"Mn", {"Manganese", "Mn", 54.938044, 25, "Transition Metal"}},
    {"Fe", {"Iron", "Fe", 55.845, 26, "Transition Metal"}},
    {"Co", {"Cobalt", "Co", 58.933194, 27, "Transition Metal"}},
    {"Ni", {"Nickel", "Ni", 58.933194, 28, "Transition Metal"}},
    {"Cu", {"Copper", "Cu", 63.546, 29, "Transition Metal"}},
    {"Zn", {"Zinc", "Zn", 65.38, 30, "Transition Metal"}},
    {"Ga", {"Gallium", "Ga", 69.723, 31, "Post-transition Metal"}},
    {"Ge", {"Germanium", "Ge", 72.63, 32, "Metalloid"}},
    {"As", {"Arsenic", "As", 74.921595, 33, "Metalloid"}},
    {"Se", {"Selenium", "Se", 78.971, 34, "Nonmetal"}},
    {"Br", {"Bromine", "Br", 79.904, 35, "Halogen"}},
    {"Kr", {"Krypton", "Kr", 83.798, 36, "Noble Gas"}},
    {"Rb", {"Rubidium", "Rb", 85.4678, 37, "Alkali Metal"}},
    {"Sr", {"Strontium", "Sr", 87.62, 38, "Alkaline Earth Metal"}},
    {"Y", {"Yttrium", "Y", 88.90584, 39, "Transition Metal"}},
    {"Zr", {"Zirconium", "Zr", 91.224, 40, "Transition Metal"}},
    {"Nb", {"Niobium", "Nb", 92.90637, 41, "Transition Metal"}},
    {"Mo", {"Molybdenum", "Mo", 95.95, 42, "Transition Metal"}},
    {"Tc", {"Technetium", "Tc", 98, 43, "Transition Metal"}},
    {"Ru", {"Ruthenium", "Ru", 101.07, 44, "Transition Metal"}},
    {"Rh", {"Rhodium", "Rh", 102.90550, 45, "Transition Metal"}},
    {"Pd", {"Palladium", "Pd", 106.42, 46, "Transition Metal"}},
    {"Ag", {"Silver", "Ag", 107.8682, 47, "Transition Metal"}},
    {"Cd", {"Cadmium", "Cd", 112.414, 48, "Transition Metal"}},
    {"In", {"Indium", "In", 114.818, 49, "Post-transition Metal"}},
    {"Sn", {"Tin", "Sn", 118.71, 50, "Post-transition Metal"}},
    {"Sb", {"Antimony", "Sb", 121.76, 51, "Metalloid"}},
    {"Te", {"Tellurium", "Te", 127.6, 52, "Metalloid"}},
    {"I", {"Iodine", "I", 126.90447, 53, "Halogen"}},
    {"Xe", {"Xenon", "Xe", 131.293, 54, "Noble Gas"}},
    {"Cs", {"Cesium", "Cs", 132.90545196, 55, "Alkali Metal"}},
    {"Ba", {"Barium", "Ba", 137.327, 56, "Alkaline Earth Metal"}},
    {"La", {"Lanthanum", "La", 138.904, 57, "Lanthanoid"}},
    {"Ce", {"Cerium", "Ce", 140.116, 58, "Lanthanoid"}},
    {"Pr", {"Praseodymium", "Pr", 140.90766, 59, "Lanthanoid"}},
    {"Nd", {"Neodymium", "Nd", 144.242, 60, "Lanthanoid"}},
    {"Pm", {"Promethium", "Pm", 145, 61, "Lanthanoid"}},
    {"Sm", {"Samarium", "Sm", 150.36, 62, "Lanthanoid"}},
    {"Eu", {"Europium", "Eu", 151.964, 63, "Lanthanoid"}},
    {"Gd", {"Gadolinium", "Gd", 157.25, 64, "Lanthanoid"}},
    {"Tb", {"Terbium", "Tb", 158.92535, 65, "Lanthanoid"}},
    {"Dy", {"Dysprosium", "Dy", 162.5, 66, "Lanthanoid"}},
    {"Ho", {"Holmium", "Ho", 164.93033, 67, "Lanthanoid"}},
    {"Er", {"Erbium", "Er", 167.259, 68, "Lanthanoid"}},
    {"Tm", {"Thulium", "Tm", 168.93422, 69, "Lanthanoid"}},
    {"Yb", {"Ytterbium", "Yb", 173.04, 70, "Lanthanoid"}},
    {"Lu", {"Lutetium", "Lu", 174.9668, 71, "Lanthanoid"}},
    {"Hf", {"Hafnium", "Hf", 178.49, 72, "Transition Metal"}},
    {"Ta", {"Tantalum", "Ta", 180.94788, 73, "Transition Metal"}},
    {"W", {"Tungsten", "W", 183.84, 74, "Transition Metal"}},
    {"Re", {"Rhenium", "Re", 186.207, 75, "Transition Metal"}},
    {"Os", {"Osmium", "Os", 190.23, 76, "Transition Metal"}},
    {"Ir", {"Iridium", "Ir", 192.217, 77, "Transition Metal"}},
    {"Pt", {"Platinum", "Pt", 195.084, 78, "Transition Metal"}},
    {"Au", {"Gold", "Au", 196.966569, 79, "Transition Metal"}},
    {"Hg", {"Mercury", "Hg", 200.592, 80, "Transition Metal"}},
    {"Tl", {"Thallium", "Tl", 204.38, 81, "Post-transition Metal"}},
    {"Pb", {"Lead", "Pb", 207.2, 82, "Post-transition Metal"}},
    {"Bi", {"Bismuth", "Bi", 208.9804, 83, "Post-transition Metal"}},
    {"Po", {"Polonium", "Po", 209, 84, "Metalloid"}},
    {"At", {"Astatine", "At", 210, 85, "Halogen"}},
    {"Rn", {"Radon", "Rn", 222, 86, "Noble Gas"}},
    {"Fr", {"Francium", "Fr", 223, 87, "Alkali Metal"}},
    {"Ra", {"Radium", "Ra", 226, 88, "Alkaline Earth Metal"}},
    {"Ac", {"Actinium", "Ac", 227, 89, "Actinoid"}},
    {"Th", {"Thorium", "Th", 232.0377, 90, "Actinoid"}},
    {"Pa", {"Protactinium", "Pa", 231.03588, 91, "Actinoid"}},
    {"U", {"Uranium", "U", 238.02891, 92, "Actinoid"}},
    {"Np", {"Neptunium", "Np", 237, 93, "Actinoid"}},
    {"Pu", {"Plutonium", "Pu", 244, 94, "Actinoid"}},
    {"Am", {"Americium", "Am", 243, 95, "Actinoid"}},
    {"Cm", {"Curium", "Cm", 247, 96, "Actinoid"}},
    {"Bk", {"Berkelium", "Bk", 247, 97, "Actinoid"}},
    {"Cf", {"Californium", "Cf", 251, 98, "Actinoid"}},
    {"Es", {"Einsteinium", "Es", 252, 99, "Actinoid"}},
    {"Fm", {"Fermium", "Fm", 257, 100, "Actinoid"}},
    {"Md", {"Mendelevium", "Md", 258, 101, "Actinoid"}},
    {"No", {"Nobelium", "No", 259, 102, "Actinoid"}},
    {"Lr", {"Lawrencium", "Lr", 262, 103, "Actinoid"}},
    {"Rf", {"Rutherfordium", "Rf", 267, 104, "Transition Metal"}},
    {"Db", {"Dubnium", "Db", 268, 105, "Transition Metal"}},
    {"Sg", {"Seaborgium", "Sg", 271, 106, "Transition Metal"}},
    {"Bh", {"Bohrium", "Bh", 270, 107, "Transition Metal"}},
    {"Hs", {"Hassium", "Hs", 277, 108, "Transition Metal"}},
    {"Mt", {"Meitnerium", "Mt", 278, 109, "Transition Metal"}},
    {"Ds", {"Darmstadtium", "Ds", 281, 110, "Transition Metal"}},
    {"Rg", {"Roentgenium", "Rg", 282, 111, "Transition Metal"}},
    {"Cn", {"Copernicium", "Cn", 285, 112, "Transition Metal"}},
    {"Nh", {"Nihonium", "Nh", 286, 113, "Post-transition Metal"}},
    {"Fl", {"Flerovium", "Fl", 289, 114, "Post-transition Metal"}},
    {"Mc", {"Moscovium", "Mc", 288, 115, "Post-transition Metal"}},
    {"Lv", {"Livermorium", "Lv", 293, 116, "Post-transition Metal"}},
    {"Ts", {"Tennessine", "Ts", 294, 117, "Halogen"}},
    {"Og", {"Oganesson", "Og", 294, 118, "Noble Gas"}},
    {"Uut", {"Ununtrium", "Uut", 289, 113, "Post-transition Metal"}}};

double get_atomic_mass(const std::string& symbol);
std::vector<PartialCompound> get_brokendown_compound(const std::string& chemical_param);

}  // namespace chemistry