# Computer Science Bookshop Application

This is a simple console-based application developed in C that simulates a bookshop. Users can browse a catalog of computer science books, place orders, and view a summary of their purchases.

## Features

*   **Book Catalog:** Browse books categorized into "Software Engineering" and "Software Development".
*   **Sales Order System:** Add multiple books to an order with specified quantities.
*   **Dynamic Discounts:** Discounts applied based on the subtotal of the order (5% for RM200-RM300, 10% for RM300-RM500, 15% for >RM500).
*   **Order Confirmation:** Confirm or cancel orders before finalization.
*   **Summary Report:** View a detailed summary of all sales orders, including total quantities, amounts, and discounts.

## How to Compile and Run

This project is a C console application. You will need a C compiler (like GCC) to compile and run it.

### Using Visual Studio (Windows)

1.  Open the `programAssignment.sln` file in Visual Studio.
2.  Build the solution (Build > Build Solution).
3.  Run the executable (Debug > Start Without Debugging or Ctrl+F5).

### Using GCC (Linux/macOS/MinGW on Windows)

1.  Navigate to the `programAssignment/` directory in your terminal.
2.  Compile the source code:
    ```bash
    gcc programAssignment.c -o programAssignment
    ```
3.  Run the executable:
    ```bash
    ./programAssignment
    ```

## Book Catalog

### Software Engineering Books

*   **[A] Patterns of Enterprise Application Architecture:** RM100.00
*   **[B] Code Complete:** RM129.00
*   **[C] Clean Code:** RM231.00

### Software Development Books

*   **[D] You Don't Know JS Yet:** RM99.00
*   **[E] Working Effectively With Legacy Code:** RM170.00
*   **[F] Code: The Hidden Language of Computer Hardware and Software:** RM240.00

## Usage

1.  **Main Menu:**
    *   `1`: View Book Menu
    *   `2`: Sales Order
    *   `3`: Exit
2.  **View Book Menu:**
    *   `1`: Software Engineering Books
    *   `2`: Software Development Books
    *   `0`: Back to Main Menu
3.  **Sales Order:**
    *   Enter the letter corresponding to the book (A-F).
    *   Enter the quantity.
    *   `X`: Finish current order.
    *   `0`: Go back to Main Menu (and restart current order).
    *   Confirm your order (Y/N).
    *   Choose if you want to place another order (Y/N).