# Plazza

## About
Plazza is a simulation of a pizzeria that manages orders, kitchens, and cooks using inter-process communication (IPC) and multithreading. This project involves handling load balancing, synchronization, and communication between processes and threads.

## Features
- Command-line interface for order management
- Dynamic kitchen creation and management
- Multithreaded cooks using a thread pool
- Inter-process communication between reception and kitchens
- Ingredient stock management with periodic replenishment
- Logging system to track orders and kitchen statuses

## Installation
### Prerequisites
- C++17 or later
- CMake (version 3.10 or later)
- POSIX-compliant operating system (Linux/macOS recommended)

### Build Instructions
1. Clone the repository:
   ```sh
   git clone https://github.com/yourusername/plazza.git
   cd plazza
   ```
2. Create a build directory and navigate to it:
   ```sh
   mkdir build && cd build
   ```
3. Generate build files with CMake:
   ```sh
   cmake ..
   ```
4. Compile the project:
   ```sh
   cmake --build .
   ```

## Usage
Run the program using the following command:
```sh
./plazza <multiplier> <cooks_per_kitchen> <restock_time_ms>
```
### Example
```sh
./plazza 2 5 2000
```
- `multiplier`: Affects the cooking time of pizzas.
- `cooks_per_kitchen`: Defines the number of cooks in each kitchen.
- `restock_time_ms`: Time interval for restocking ingredients.

## Order Format
Orders must follow this syntax:
```
<TYPE> <SIZE> x<NUMBER>
```
Example:
```
regina XXL x2; fantasia M x3; margarita S x1
```
- `TYPE`: Pizza type (e.g., regina, fantasia, margarita, americana)
- `SIZE`: S, M, L, XL, XXL
- `NUMBER`: Quantity prefixed by `x`

## Project Structure
```
├── include/      # Header files
├── src/          # Source code
├── tests/        # Unit tests
├── CMakeLists.txt  # Build configuration
└── README.md     # Project documentation
```

## License
This project is licensed under the MIT License.

## Contributors
- luciajd

