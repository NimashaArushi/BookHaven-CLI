#include <iostream>
using namespace std;

int password;
string passname;

bool isLoggedIn = false;
bool isAdmin = false;

struct books {
    int id;
    string bookname;
    string author;
    float price;
    int qty;
};

const int max_book = 100;
int numbooks = 6;
int attempts = 0;
const int MAXLoginAttempts = 3;
int choice;

books arrshop[max_book] = {
    {001,"Gamperaliya","martin wickramasinghe", 550.00,05},
    {002,"Golu Hadawatha","karunasena jayalath ", 400.00,02},
    {003,"Malagiya Aththo","ediriweera sarachandra",380.00,04},
    {004,"hin dos male","sepali mayadunne",600.00,15},
    {005,"Daeniyaya","a.d.a wijesinghe",250.00,25},
    {006,"Viragaya","martin wickramasinghe",610.00,04},
};

bool login() {
    cout << "" << endl;
    while (attempts < MAXLoginAttempts) {
        cout << " *** Login *** " << endl;
        cout << "" << endl;

        cout << "Enter username: ";
        cin >> passname;
        cout << "Enter password: ";
        cin >> password;

        if (passname == "admin" && password == 456) {
            isLoggedIn = true;
            isAdmin = true;
            cout << "Admin login successful!" << endl;
            return true;
        }
        else if (passname == "user" && password == 123) {
            isLoggedIn = true;

            cout << "User login successful!" << endl;
            return true;
        }
        else {
            attempts++;
            cout << "Login failed. " << (MAXLoginAttempts - attempts) << " attempts left." << endl;
        }
    }
    cout << "Too many failed attempts. You are locked out." << endl;
    return false;
}

void viewAvailableBooks() {
    if (!isLoggedIn) {
        cout << "Please log in first." << endl;
        return;
    }

    cout << "\n\t\t* --- Available Books --- *\t\t" << endl;
    cout << " " << endl;

    cout << "ID\tName\t\t\tAuthor\t\t\tPrice(LKR)\tQty" << endl;
    cout << " " << endl;

    for (int i = 0; i < numbooks; i++) {
        cout << arrshop[i].id << "\t" << arrshop[i].bookname << "\t\t"
            << arrshop[i].author << "\t\t" << arrshop[i].price << "\t\t" << arrshop[i].qty << endl;
    }
}

void addBook() {
    cout << "\t\t*--- Add Book ---* \t" << endl;
    cout << " " << endl;

    if (max_book <= numbooks) {
        cout << "Library full! Cannot add more books." << endl;
        return;
    }
    do {
        books newBook;
        cout << "\nAdd New Book" << endl;
        cout << "ID: ";
        cin >> newBook.id;
        cout << "Name: ";
        cin >> newBook.bookname;
        cout << "Author: ";
        cin >> newBook.author;
        cout << "Price: ";
        cin >> newBook.price;
        cout << "Quantity: ";
        cin >> newBook.qty;

        arrshop[numbooks] = newBook;
        numbooks++;
        cout << "Book added successfully!" << endl;
        cout << "\nPress 1 to add books again or 0 to return to the main menu: ";
        cin >> choice;
    } while (choice == 1);
    return;
}
void updateBook() {
    cout << "\t\t*--- Update Book ---* \t" << endl;
    cout << " " << endl;

    do {
        int bookId;
        cout << "Enter Book ID to update: ";
        cin >> bookId;
        bool found = false;

        for (int i = 0; i < numbooks; i++) {
            if (arrshop[i].id == bookId) {
                found = true;
                cout << "Updating: " << arrshop[i].bookname << endl;
                cout << "New Name: ";
                cin >> arrshop[i].bookname;
                cout << "New Author: ";
                cin >> arrshop[i].author;
                cout << "New Price: ";
                cin >> arrshop[i].price;
                cout << "New Qty: ";
                cin >> arrshop[i].qty;
                cout << " " << endl;
                cout << "Book updated successfully" << endl;

            }
        }if (!found) {
            cout << "Book not found." << endl;
        }

        cout << "\nPress 1 to update books again or 0 to return to the main menu: ";
        cin >> choice;
    } while (choice == 1);
    return;

}

void deleteBook() {
    cout << "\t\t*--- Delete Book ---* \t" << endl;
    cout << " " << endl;
    do {
        int bookId;
        cout << "Enter Book ID to delete: ";
        cin >> bookId;

        bool found = false;

        for (int i = 0; i < numbooks; i++) {
            if (arrshop[i].id == bookId) {
                found = true;
                for (int j = i; j < numbooks - 1; j++) {
                    arrshop[j] = arrshop[j + 1];
                }
                numbooks--;
                cout << "Book deleted successfully ." << endl;

            }
        }

        if (!found) {
            cout << "Book not found." << endl;
        }

        cout << "\nPress 1 to delete books again or 0 to return to the main menu: ";
        cin >> choice;

    } while (choice == 1);

}
int bookId;
int quantity;
void manageSales() {
    do {
        cout << "*---Sales management system----*" << endl;
        cout << "\nEnter Book ID to sell: ";
        cin >> bookId;
        cout << "Enter stock Quantity: ";
        cin >> quantity;
        bool bookFound = false;
        for (int i = 0; i < numbooks; i++) {
            if (arrshop[i].id == bookId) {
                bookFound = true;
                if (arrshop[i].qty >= quantity) {
                    float total = arrshop[i].price * quantity;
                    arrshop[i].qty -= quantity;
                    cout << "\nSale Successful !!!" << endl;
                    cout << "Book: " << arrshop[i].bookname << endl;
                    cout << "Quantity: " << quantity << endl;
                    cout << "Total: Rs(LKR). " << total << endl;
                }
                else {
                    cout << "Insufficient stock! Only " << arrshop[i].qty << " available now ---->." << endl;
                }
            }
        } if (!bookFound) {
            cout << "Book ID not found!" << endl;
        }
        cout << "\nPress 1 to delete books again or 0 to return to the main menu: ";
        cin >> choice;

    } while (choice == 1);

}
void viewCompanyDetails() {
    cout << "\n\t*--- Company Details ---*" << endl;
    cout << " " << endl;
    cout << "Genius Bookshop" << endl;
    cout << "______________________" << endl;
    cout << "Address: 74/A Book Street, Colombo 07" << endl;
    cout << "Phone : +94 012345678" << endl;
    cout << "\t:+94 012345678" << endl;
    cout << "email:Genius Bookshop@gmail.com " << endl;
    cout << " " << endl;
    cout << "You can come,and buy your book." << endl;
}

void displayMenu() {

    cout << "\n***** Genius Bookshop Menu *****" << endl;
    cout << "" << endl;
    cout << " " << endl;


    if (isLoggedIn) {
        cout << "0. Logout" << endl;
    }
    else {
        cout << "0. Login" << endl;
    }

    cout << "1. View Books" << endl;

    if (isAdmin) {
        cout << "2. Add Book" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Delete Book" << endl;
        cout << "5. Manage Sales" << endl;
        cout << "6. Company Details" << endl;
        cout << "7. Exit" << endl;
    }
    else {
        cout << "2. Company Details" << endl;
        cout << "3. Exit" << endl;
    }
}

int main() {
    do {
        displayMenu();
        cout << "\nChoose option: ";
        cin >> choice;

        switch (choice) {
        case 0:
            if (isLoggedIn) {
                isLoggedIn = false;
                isAdmin = false;
                cout << "Logged out successfully!" << endl;
            }
            else {
                login();
            }
            break;

        case 1:
            viewAvailableBooks();
            break;

        case 2:
            if (isAdmin) {
                addBook();
            }
            else {
                viewCompanyDetails();
            }
            break;

        case 3:
            if (isAdmin) {
                updateBook();
            }
            else {
                cout << "Goodbye !!! see you later " << endl;
                return 0;
            }
            break;

        case 4:
            if (isAdmin) {
                deleteBook();
            }
            break;

        case 5:
            if (isAdmin) {
                manageSales();
            }
            break;

        case 6:
            if (isAdmin) {
                viewCompanyDetails();
            }
            break;

        case 7:

            cout << "Goodbye !" << endl;
            return 0;

            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (true);

    return 0;
}
