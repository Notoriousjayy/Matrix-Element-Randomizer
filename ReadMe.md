````markdown
# notoriousjayy-matrix-element-randomizer

A simple C/GLUT application that lets you enter the dimensions of a matrix (rows *m* and columns *n*) and then pick and display a random element’s indices. Provides an interactive window with buttons to randomize again or quit.

---

## Table of Contents

- [Features](#features)  
- [Requirements](#requirements)  
- [Directory Structure](#directory-structure)  
- [Building](#building)  
- [Usage](#usage)  
- [Controls](#controls)  
- [Contributing](#contributing)  
- [License](#license)  

---

## Features

- Prompt-based input for matrix dimensions (rows and columns).  
- Randomly selects an element position \(`i, j`\) within the given dimensions.  
- Interactive GUI window powered by OpenGL/GLUT.  
- “Randomize” button to pick a new random element.  
- “Quit” button to close the application.

---

## Requirements

- **CMake** ≥ 3.10  
- **C** compiler with OpenGL and GLUT support (e.g., `gcc` or `clang`)  
- **OpenGL** development libraries  
- **GLUT** (or freeglut) development libraries  

On Debian/Ubuntu, you can install the dependencies with:

```bash
sudo apt-get update
sudo apt-get install build-essential cmake freeglut3-dev libglu1-mesa-dev mesa-common-dev
````

On macOS (using Homebrew):

```bash
brew install cmake freeglut
```

---

## Directory Structure

```
notoriousjayy-matrix-element-randomizer/
├── CMakeLists.txt
└── main.c
```

* **CMakeLists.txt** – CMake build configuration
* **main.c**        – Source code for the GLUT application

---

## Building

In the project root:

```bash
mkdir build
cd build
cmake ..
make
```

This will generate the executable **MatrixRandomElement** in `build/`.

---

## Usage

From the `build/` directory:

```bash
./MatrixRandomElement
```

1. **Enter rows (m):**

   * Type an integer (up to 10 digits) and press **Enter**.
2. **Enter columns (n):**

   * Type an integer (up to 10 digits) and press **Enter**.
3. The window will display the randomly selected element’s indices in the form:

   ```
   A = [a_{i,j}]
   ```
4. Use the on-screen buttons:

   * **Randomize** – pick a new random element.
   * **Quit** – exit the application.

---

## Controls

* **Keyboard**

  * Number keys (`0–9`): enter digits for dimensions
  * Backspace/Delete: delete last digit
  * Enter: submit current input

* **Mouse**

  * Left-click **Randomize** button: generate new random indices
  * Left-click **Quit** button: close the program

---

## Contributing

Contributions, issues, and feature requests are welcome! Feel free to fork the repository and submit a pull request.

---

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

```

Just save this as `README.md` in the root of your project. Adjust any sections (e.g., license details) to fit your needs.
```
