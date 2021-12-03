const fs = require("fs");

const filterArray = (byteArray, reducedBits, index = 0, mode = "oxygen") => {
  let filter;

  if (mode == "oxygen") {
    reducedBits["single"] >= reducedBits["zero"] ? (filter = 1) : (filter = 0);
  } else {
    reducedBits["single"] < reducedBits["zero"] ? (filter = 1) : (filter = 0);
  }

  byteArray = byteArray.filter((byte) => byte[index] == filter);

  if (byteArray.length <= 1) {
    return byteArray[0];
  }

  let rb = {};
  rb["single"] = [...byteArray.map((bytes) => bytes.substr(index + 1))].reduce(
    bitReducer,
    0
  );
  rb["zero"] = byteArray.length - rb["single"];

  return filterArray(byteArray, rb, index + 1, mode);
};

// Parse File into Array
const bytes = fs
  .readFileSync("./input.txt")
  .toString()
  .split("\n")
  .slice(0, -1);
const lines = bytes.length;

const bitReducer = (prev, curr) => prev + parseInt(curr[0]);

// Get Amount of 1s and 0s
const bits = { single: bytes.reduce(bitReducer, 0) };
bits["zero"] = 7 - bits["single"];

const OxygenLevel = parseInt(filterArray(bytes, bits, 0, "oxygen"), 2);

const CO2Scrubber = parseInt(filterArray(bytes, bits, 0, "co2"), 2);

console.log(OxygenLevel * CO2Scrubber);
