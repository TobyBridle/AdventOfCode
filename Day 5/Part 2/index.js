class Point {
  constructor(x, y, duplicates = 0) {
    this.x = x;
    this.y = y;
    this.duplicates = duplicates;
  }
}

class CoordinateSystem {
  constructor() {
    this.grid = {};
  }

  addPoint = ({ x, y }) => {
    this.grid[`${x},${y}`] !== Point.construtor
      ? this.grid[`${x},${y}`].duplicates++
      : (this.grid[`${x},${y}`] = new Point(x, y, 1));
  };

  countOverlays = (minOverlay = 2) => {
    return Object.values(this.grid).filter((n) => n.duplicates >= minOverlay)
      .length;
  };
}

const fs = require("fs");

const lines = fs
  .readFileSync("./input.txt")
  .toString()
  .split("\n")
  .slice(0, -1);

const CoordSystem = new CoordinateSystem();

const points = lines.map((line) => line.split(" -> ").toString().split(","));

points.forEach((point) => {
  let [x1, y1, x2, y2] = point;

  if (y1 == y2) {
    for (i = Math.min(x1, x2); i <= Math.max(x1, x2); i++) {
      CoordSystem.addPoint({ x: i, y: parseInt(y1) });
    }
  } else if (x1 == x2) {
    for (i = Math.min(y1, y2); i <= Math.max(y1, y2); i++) {
      CoordSystem.addPoint({ x: parseInt(x1), y: i });
    }
  } else {
    const gradient =
      Math.abs((y2 - y1) / (x2 - x1)) !== Infinity ? (y2 - y1) / (x2 - x1) : 0;
    const intercept = y1 - gradient * x1;

    for (x = Math.min(x1, x2); x <= Math.max(x1, x2); x++) {
      const yValue = gradient * x + intercept;
      CoordSystem.addPoint({ x: x, y: yValue });
    }

  }
});

console.log("Overlays: ", CoordSystem.countOverlays());
