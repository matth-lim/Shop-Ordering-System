# Dosta Coffee Shop Ordering System

A command-line coffee shop ordering system built in C. This project uses text files as a lightweight database to manage customers, menu items, staff, and orders.

## Features

- **Staff Panel** — Login, manage menu items (add/update), create customer accounts, search customer orders
- **New Customer** — Browse menu and register as a new customer
- **Registered Customer** — Login, place orders, make payments, cancel orders, modify personal details, generate receipts
- **Data Persistence** — All data stored in plain-text files
- **Input Validation** — Validates user input for correctness and security

## Built With

- **C** — Compiled with MSVC (Visual Studio)
- Text files as the storage layer

## Getting Started

### Prerequisites

- Windows OS
- Visual Studio (or any C compiler that supports MSVC)

### Building

1. Open the solution file:
   ```
   DOSTA COFFEE SHOP ORDERING SYSTEM.sln
   ```
2. Build the solution (Ctrl+Shift+B) and run.

Or compile from the command line with any C compiler that supports the Windows CRT.

## Project Structure

```
├── Demo/                          # Demo screenshots
├── DOSTA COFFEE SHOP ORDERING SYSTEM/
│   ├── main.c                     # Program entry point
│   ├── staff_func.c / .h          # Staff functions
│   ├── new_cus_func.c / .h        # New customer functions
│   ├── regis_cus_func.c / .h      # Registered customer functions
│   ├── additional_func.c / .h     # Utility functions (string, file I/O)
│   ├── customer.txt               # Customer data store
│   ├── staff.txt                  # Staff data store
│   ├── menu_item.txt              # Menu items data store
│   └── Raiden.txt                 # (Additional data)
├── Demo/                          # Screenshot assets
├── LICENSE.txt
└── README.md
```

## License

Distributed under the MIT License. See `LICENSE.txt` for more information.
