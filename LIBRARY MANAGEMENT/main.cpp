#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

const int MAX_ITEMS = 100;

class LibraryItem
{
private:
    string title;
    string author;
    string dueDate;

protected:
    bool checkedOut;

public:
    LibraryItem(string t, string a, string d)
        : title(t), author(a), dueDate(d), checkedOut(false) {}

    virtual ~LibraryItem() {}

    string getTitle() const
    {
        return title;
    }
    string getAuthor() const
    {
        return author;
    }
    string getDueDate() const
    {
        return dueDate;
    }

    bool isCheckedOut() const
    {
        return checkedOut;
    }

    void setTitle(string t)
    {
        title = t;
    }
    void setAuthor(string a)
    {
        author = a;
    }
    void setDueDate(string d)
    {
        dueDate = d;
    }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() const = 0;
    virtual string getType() const = 0;
};

class Book : public LibraryItem
{
private:
    string isbn;
    int quantity;

public:
    Book(string t, string a, string d, string i, int q)
        : LibraryItem(t, a, d), isbn(i), quantity(q)
    {
        if (isbn.length() != 13)
            throw invalid_argument("ISBN must be 13 digits.");
        for (char c : isbn)
            if (!isdigit(c))
                throw invalid_argument("ISBN must contain digits only.");
        if (quantity < 0)
            throw invalid_argument("Quantity cannot be negative.");
    }

    string getIsbn() const
    {
        return isbn;
    }
    int getQuantity() const
    {
        return quantity;
    }

    void checkOut() override
    {
        if (checkedOut)
            throw runtime_error("Book is already checked out.");
        if (quantity <= 0)
            throw runtime_error("No copies available.");
        quantity--;
        checkedOut = true;
        cout << "[Book] \"" << getTitle() << "\" checked out.\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "Remaining: " << quantity << "\n";
    }

    void returnItem() override
    {
        if (!checkedOut)
            throw runtime_error("Book was not checked out.");
        quantity++;
        checkedOut = false;
        cout << "[Book] \"" << getTitle() << "\" returned.\n";
        cout << "Available: " << quantity << "\n";
    }

    void displayDetails() const override
    {
        cout << "Type    : Book\n";
        cout << "Title   : " << getTitle() << "\n";
        cout << "Author  : " << getAuthor() << "\n";
        cout << "ISBN    : " << isbn << "\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "Qty     : " << quantity << "\n";
        cout << "Status  : " << (checkedOut ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override
    {
        return "Book";
    }
};

class DVD : public LibraryItem
{
private:
    int durationMinutes;

public:
    DVD(string t, string a, string d, int dur)
        : LibraryItem(t, a, d), durationMinutes(dur)
    {
        if (dur <= 0)
            throw invalid_argument("Duration must be positive.");
    }

    void checkOut() override
    {
        if (checkedOut)
            throw runtime_error("DVD is already checked out.");
        checkedOut = true;
        cout << "[DVD] \"" << getTitle() << "\" checked out.\n";
        cout << "Due Date: " << getDueDate() << "\n";
    }

    void returnItem() override
    {
        if (!checkedOut)
            throw runtime_error("DVD was not checked out.");
        checkedOut = false;
        cout << "[DVD] \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override
    {
        cout << "Type    : DVD\n";
        cout << "Title   : " << getTitle() << "\n";
        cout << "Director: " << getAuthor() << "\n";
        cout << "Duration: " << durationMinutes << " min\n";
        cout << "Due Date: " << getDueDate() << "\n";
        cout << "Status  : " << (checkedOut ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override
    {
        return "DVD";
    }
};

class Magazine : public LibraryItem
{
private:
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue)
        : LibraryItem(t, a, d), issueNumber(issue)
    {
        if (issue <= 0)
            throw invalid_argument("Issue number must be positive.");
    }

    void checkOut() override
    {
        if (checkedOut)
            throw runtime_error("Magazine is already checked out.");
        checkedOut = true;
        cout << "[Magazine] \"" << getTitle() << "\" Issue #" << issueNumber << " checked out.\n";
        cout << "Due Date: " << getDueDate() << "\n";
    }

    void returnItem() override
    {
        if (!checkedOut)
            throw runtime_error("Magazine was not checked out.");
        checkedOut = false;
        cout << "[Magazine] \"" << getTitle() << "\" returned.\n";
    }

    void displayDetails() const override
    {
        cout << "Type     : Magazine\n";
        cout << "Title    : " << getTitle() << "\n";
        cout << "Publisher: " << getAuthor() << "\n";
        cout << "Issue #  : " << issueNumber << "\n";
        cout << "Due Date : " << getDueDate() << "\n";
        cout << "Status   : " << (checkedOut ? "Checked Out" : "Available") << "\n";
    }

    string getType() const override
    {
        return "Magazine";
    }
};

class Library
{
private:
    LibraryItem *items[MAX_ITEMS];
    int count;

public:
    Library() : count(0)
    {
        for (int i = 0; i < MAX_ITEMS; i++)
            items[i] = nullptr;
    }

    ~Library()
    {
        for (int i = 0; i < count; i++)
        {
            delete items[i];
            items[i] = nullptr;
        }
    }

    void addItem(LibraryItem *item)
    {
        if (count >= MAX_ITEMS)
            throw overflow_error("Library is full.");
        items[count++] = item;
        cout << "Added: \"" << item->getTitle() << "\" [" << item->getType() << "]\n";
    }

    void listAll() const
    {
        if (count == 0)
        {
            cout << "No items in library.\n";
            return;
        }
        for (int i = 0; i < count; i++)
        {
            cout << "\n[" << i << "] ";
            items[i]->displayDetails(); // Polymorphism
        }
    }

    void searchItem(string query) const
    {
        bool found = false;
        for (int i = 0; i < count; i++)
        {
            if (items[i]->getTitle() == query)
            {
                cout << "\n[" << i << "] ";
                items[i]->displayDetails();
                found = true;
            }
        }
        if (!found)
            cout << "Item not found.\n";
    }

    void checkOutItem(int index)
    {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index.");
        items[index]->checkOut();
    }

    void returnItem(int index)
    {
        if (index < 0 || index >= count)
            throw out_of_range("Invalid index.");
        items[index]->returnItem();
    }
};

int main()
{
    Library lib;

    try
    {
        lib.addItem(new Book("C++ Programming", "Stroustrup", "2025-07-01", "9780321563842", 3));
        lib.addItem(new DVD("Interstellar", "Nolan", "2025-06-28", 169));
        lib.addItem(new Magazine("National Geographic", "Nat Geo", "2025-07-05", 210));
    }
    catch (exception &e)
    {
        cerr << "Initialization Error: " << e.what() << "\n";
        return 1;
    }

    int choice;
    bool running = true;

    while (running)
    {
        cout << "\n==================================\n";
        cout << "   LIBRARY MANAGEMENT SYSTEM\n";
        cout << "==================================\n";
        cout << "1. List All Items\n";
        cout << "2. Search Item\n";
        cout << "3. Check Out Item\n";
        cout << "4. Return Item\n";
        cout << "5. Add Book\n";
        cout << "6. Add DVD\n";
        cout << "7. Add Magazine\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";

        try
        {
            if (!(cin >> choice))
            {
                cin.clear();
                cin.ignore(1000, '\n');
                throw invalid_argument("Enter a number.");
            }
            cin.ignore();

            switch (choice)
            {

            case 1:
                lib.listAll();
                break;

            case 2:
            {
                string q;
                cout << "Enter title: ";
                getline(cin, q);
                lib.searchItem(q);
                break;
            }

            case 3:
            {
                lib.listAll();
                int idx;
                cout << "Enter index: ";
                cin >> idx;
                cin.ignore();
                lib.checkOutItem(idx);
                break;
            }

            case 4:
            {
                lib.listAll();
                int idx;
                cout << "Enter index: ";
                cin >> idx;
                cin.ignore();
                lib.returnItem(idx);
                break;
            }

            case 5:
            {
                string t, a, d, i;
                int q;
                cout << "Title   : ";
                getline(cin, t);
                cout << "Author  : ";
                getline(cin, a);
                cout << "Due Date: ";
                getline(cin, d);
                cout << "ISBN    : ";
                getline(cin, i);
                cout << "Qty     : ";
                cin >> q;
                cin.ignore();
                lib.addItem(new Book(t, a, d, i, q));
                break;
            }

            case 6:
            {
                string t, a, d;
                int dur;
                cout << "Title   : ";
                getline(cin, t);
                cout << "Director: ";
                getline(cin, a);
                cout << "Due Date: ";
                getline(cin, d);
                cout << "Duration: ";
                cin >> dur;
                cin.ignore();
                lib.addItem(new DVD(t, a, d, dur));
                break;
            }

            case 7:
            {
                string t, a, d;
                int issue;
                cout << "Title    : ";
                getline(cin, t);
                cout << "Publisher: ";
                getline(cin, a);
                cout << "Due Date : ";
                getline(cin, d);
                cout << "Issue #  : ";
                cin >> issue;
                cin.ignore();
                lib.addItem(new Magazine(t, a, d, issue));
                break;
            }

            case 0:
                cout << "Goodbye! Thank you for using the Library Management System. \n";
                running = false;
                break;

            default:
                cout << "Invalid choice.\n";
            }
        }
        catch (const invalid_argument &e)
        {
            cerr << "[Input Error] " << e.what() << "\n";
        }
        catch (const out_of_range &e)
        {
            cerr << "[Range Error] " << e.what() << "\n";
        }
        catch (const overflow_error &e)
        {
            cerr << "[Overflow Error] " << e.what() << "\n";
        }
        catch (const runtime_error &e)
        {
            cerr << "[Runtime Error] " << e.what() << "\n";
        }
        catch (const exception &e)
        {
            cerr << "[Error] " << e.what() << "\n";
        }
    }
}