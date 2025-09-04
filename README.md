# Spirograph Generator

A C++ application that generates and visualizes intricate spirograph patterns using the SFML (Simple and Fast Multimedia Library).

## Features

*   **Dynamic Spirograph Generation:** Creates various spirograph patterns based on mathematical formulas.
*   **Configurable Patterns:** Reads spirograph parameters from an external input file, allowing for easy definition of multiple patterns.
*   **Interactive Controls:** Adjust drawing speed/detail and switch between predefined spirograph patterns on the fly.
*   **Customizable Appearance:** Define stroke width and color for each spirograph.

## Dependencies

*   **SFML (Simple and Fast Multimedia Library):** Specifically, the Graphics module is required for rendering.
    *   [SFML Website](https://www.sfml-dev.org/)

## How to Build

1.  **Install SFML:** Ensure you have SFML installed on your system. Follow the official SFML documentation for installation instructions specific to your operating system and compiler.

2.  **Compile the Code:** Use a C++ compiler (like g++) to compile the source code. Link against the SFML graphics, window, and system modules.

    ```bash
    g++ main.cpp -o spirograph -I/usr/local/include -L/usr/local/lib -lsfml-graphics -lsfml-window -lsfml-system
    ```
    *(Adjust include and library paths (`-I` and `-L`) according to your SFML installation.)*

## How to Run

To run the application, you need to provide an input file containing the spirograph parameters as a command-line argument.

```bash
./spirograph <input_file.txt>
```

**Example:**

```bash
./spirograph patterns.txt
```

### Controls

*   **`Right Control`**: Increase drawing speed/detail (`dT`).
*   **`Left Control`**: Decrease drawing speed/detail (`dT`).
*   **`Return` (Enter) Key**: Advance to the next spirograph pattern defined in the input file.

## Input File Format

The input file should be a plain text file where each line (starting from the second line) defines a spirograph pattern. The first line of the file is skipped.

Each line must contain 10 space-separated values in the following order:

1.  `r` (float): Radius of the inner circle.
2.  `d` (float): Distance of the pen from the center of the inner circle.
3.  `R` (float): Radius of the outer circle.
4.  `cX` (float): X-coordinate of the center of the drawing area.
5.  `cY` (float): Y-coordinate of the center of the drawing area.
6.  `red` (int): Red component of the drawing color (0-255).
7.  `green` (int): Green component of the drawing color (0-255).
8.  `blue` (int): Blue component of the drawing color (0-255).
9.  `sign` (string): Determines the direction of rotation. Use `"m"` for minus or `"p"` for plus.
10. `width` (int): The stroke width of the drawn line in pixels.

**Example `patterns.txt`:**

```
# This is a comment or header line and will be skipped
100 50 200 400 300 255 0 0 p 2
70 30 150 400 300 0 255 0 m 1
```

See a live-coded walkthrough on YouTube:

https://www.youtube.com/watch?v=s9Qtt3FWofA
