# chemistry

Simple chemistry project

## Build

````
chmod +x build.sh
./build.sh
```

## Usage

- -c [compound] for cheminal compound
- -g [x grams] to get mole amount per x grams
- -m [x mole] to get total grams per x moles

````

Example:

```
app -c H2O
Molar mass of H2O is: 18.015 g/mol

app -c H2O -m 2
Mass of 2.00 moles of H2O is: 36.03 g
```
