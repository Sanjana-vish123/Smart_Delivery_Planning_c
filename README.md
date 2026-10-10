# Smart Delivery Planning - Fractional Knapsack

Smart Delivery Planning using Greedy Algorithm (Analysis of Algorithms in C)

## Objective

The objective of this project is to develop a Smart Delivery Planning system using C programming and the Fractional Knapsack problem. The system aims to maximize the total value of packages loaded into a delivery vehicle with a fixed carrying capacity. It uses the Greedy Algorithm to select packages based on their value-to-weight ratios.

## Features

- Enter package details, including value and weight
- Display all package details
- Calculate the value-to-weight ratio of each package
- Sort packages in decreasing order of their ratios
- Select complete packages whenever possible
- Select a fraction of a package when required
- Calculate the maximum achievable value
- Display selected packages and their fractions
- User-friendly menu-driven program

## Technologies Used

- C Programming Language
- GCC Compiler or Dev-C++
- Git and GitHub

## Algorithm Used

This project uses the **Greedy Algorithm** to solve the Fractional Knapsack problem.

The algorithm calculates the value-to-weight ratio for each package and sorts the packages in decreasing order of their ratios. It selects the highest-ratio packages first until the vehicle reaches its carrying capacity.

## Data Structure Used

This project uses an **Array of Structures** to store package details.

Each package record contains:

- Package ID
- Package Value
- Package Weight
- Value-to-Weight Ratio
- Selected Fraction

The array of structures allows package information to be stored and accessed efficiently. Bubble Sort is used to arrange packages according to their value-to-weight ratios.

## How to Run the Code

1. Download or clone the repository from GitHub.
2. Open the `main.c` file in a C compiler or code editor.
3. Compile the program using GCC:

   `gcc main.c -o main`

4. Run the program.

   On Windows:

   `main.exe`

   On Linux or macOS:

   `./main`

5. Select an option from the menu to perform the desired operation.

## Sample Menu Options

1. Enter Package Details
2. Display Package Details
3. Calculate Value/Weight Ratio
4. Sort Packages by Ratio
5. Find Maximum Value
6. Display Selected Packages
7. Exit

## Time Complexity

The overall time complexity of the program is **O(n²)** because Bubble Sort is used to sort the packages by their value-to-weight ratios.

## Author

Sanjana Vishwakarma
