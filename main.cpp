#include <iostream>
#include <string.h>
#include <fstream>
#include <conio.h>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

class Menu
{
public:
    void display() {
        system("color F1");
        cout << "\n\n";
        for (int i = 0; i < 120; i++)
        {
            cout << "_";
        }

        cout << "\n\n\n\t\t\t\t\t********< Welcome to Peace Bookshop! >********" << endl;
        int k = 120;
        cout << "\n\n";
        for (int i = 0; i < 120; i++)
        {
            cout << (char)5;
        }
        cout << endl;
        cout << "\t\tPlease select an option:" << endl;
        cout << "\n\t\t1. User" << endl;
        cout << "\n\t\t2. Client" << endl;
        cout << "\n\t\t3. Exit" << endl;
    }

    void select(int option) {
        switch (option) {
        case 1:
            cout << "You selected the User option." << endl;
            break;
        case 2:
            cout << "You selected the Client option." << endl;
            break;
        case 3:
            system("cls");
            cout << "Exiting the program..." << "\n\n\n\n\n\n\n\n\n\t\t\t Thank you for using Peace Bookshop \n\n\n\n\n\n\n\n\n\n\n" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
            break;
        }
    }
};

class book :public Menu {
public:
    int book_id;
    char b_name[30];
    float price;
    char author_name[30];
    char category[30];
    int quantity;
    int invoice_number;
    float total_cost;
    char book_purchased[30];

    int password();
    void setdata();
    void admin_function();
    void admin_dash();
    void list_view();
    void less_books();
    void update();
    void show_req();
    void show_clients();
    void print_bill();
    void show_sales();

    void deleteData();
    void bookData();
    void deleteBookData();
    void deleteClientData();
    void deleteRequestData();
    void deleteReceiptData();
};

void book::admin_function()
{
    system("cls");
    int k = 5;
    while (k >= 1)
    {
        int c = password();
        if (c == 1)
        {
            cout << "\n....................Login successfully..............\n";
            cout << "........................Press any key to continue..........\n";
            getch();
            break;
        }
        else
        {
            cout << " \n Invalid Username or password " << endl;
            cout << " \n\n\t\t You can try " << k - 1 << " more times ";
            k--;
            if (k == 1)
            {
                system("cls");
                cout << " \n\nOops! Too many attempts " << endl;
                cout << "\n\n\t\t Please try again later " << endl;
                exit(0);
            }
        }
    }
}

void book::admin_dash()
{

    int ch1;
    do {
        system("cls");
        for (int i = 0; i < 120; i++)
        {
            cout << "_";
        }
        cout << "\n\n\n\t\t\t\t\t\tPeace Bookshop!" << endl;
        int k = 120;
        cout << "\n\n";
        for (int i = 0; i < 120; i++)
        {
            cout << (char)5;
        }
        cout << "\n\n\t 1. Add new                \t   \t         2. View existing " << endl;
        cout << "\n\t 3. Modify existing                \t \t 4. View books less than five  " << endl;
        cout << "\n\t 5. View Request                \t \t 6. Show data of clients  " << endl;
        cout << "\n\t 7. Print Bill                \t  \t         8. Show Sales" << endl;
        cout << "\n\t 9. Delete Records            \t  \t         0. Main Menu" << endl;
        for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
        cout << "\nEnter your choice : ";
        cin >> ch1;
        switch (ch1)
        {
        case 1:
            setdata();
            break;
        case 2:
            list_view();
            break;
        case 3:
            update();
            break;
        case 4:
            less_books();
            break;
        case 5:
            show_req();
            break;
        case 6:
            show_clients();
            break;
        case 7:
            print_bill();
            break;
        case 8:
            show_sales();
            break;
        case 9:
            deleteData();
            break;
        case 0:
            system("cls");
            display();
            break;
        default:
            system("cls");
            cout << "\n\nEnter valid option " << endl;
            exit(0);
        }
        system("cls");
    } while (ch1 != 0);
}

void book::setdata()
{
    ofstream fout;
    fout.open("book.txt", ios::app);
    ifstream next_id_file;
    next_id_file.open("next_id.txt");
    int next_id;
    next_id_file >> next_id;
    book_id = next_id;
    cout << "\nEnter Book ID : " << book_id << endl;
    fout << book_id << "\n";
    cin.ignore(1, '\n');
    cout << "\nEnter Book Name : ";
    cin.getline(b_name, 30);
    fout << b_name << "\n";
    cout << "\nEnter Author Name : ";
    cin.getline(author_name, 30);
    fout << author_name << "\n";
    cout << "\nEnter Category : ";
    cin.getline(category, 30);
    fout << category << "\n";
    cout << "\nEnter Price : ";
    cin >> price;
    fout << price << " ";
    cout << "\nEnter Quantity : ";
    cin >> quantity;
    fout << quantity << " ";
    fout.close();
    next_id++;
    ofstream next_id_file_out;
    next_id_file_out.open("next_id.txt");
    next_id_file_out << next_id;
    next_id_file_out.close();
    next_id_file.close();
    system("pause");
}

void book::list_view()
{
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;
        }
    }
    fin.close();
    system("pause");
}

void book::less_books()
{
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            if (quantity < 5)
            {
                cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;
            }
        }
    }
    fin.close();
    system("pause");
}

void book::show_req()
{
    ifstream requests_file("requests.txt");
    int id;
    string name, book_name, author;
    cout << left << setw(20) << "ID" << setw(20) << "Name" << setw(30) << "Book Name" << setw(20) << "Author" << setw(20) << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    while (requests_file >> id >> name >> book_name >> author) {
        cout << left << setw(20) << id << setw(20) << name << setw(30) << book_name << setw(20) << author << setw(20) << endl;
    }
    requests_file.close();
    system("pause");
}

void book::show_clients()
{
    ifstream clients_file("clients.txt");
    cout << left << setw(20) << "ID" << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "Email" << setw(20) << "Phone Number" << setw(20) << "Age" << endl;
        for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
    string name, address, email, phone_number;
    int age, id;
    while (clients_file >> id >> name >> address >> email >> phone_number >> age) {
        cout << left << setw(20) << id << setw(20) << name << setw(20) << address << setw(20) << email << setw(20) << phone_number << setw(20) << age << endl;
    }
    clients_file.close();
    system("pause");
}

int book::password()
{
    char cname[30], pass[20];
    int ch, i = 0;
    cout << "\n\n\n\n\n\t\t\t\t\tUSER NAME:  ";
    fflush(stdin);
    gets(cname);
    cout << "\n\n\t\t\t\t\tPASSWORD:    ";
    fflush(stdin);
    while ((ch = getch()) != 13)
    {
        cout << "*";
        pass[i] = ch;
        i++;
    }
    pass[i] = '\0';
    if ((strcmp(cname, "admin") == 0) && (strcmp(pass, "admin") == 0))
        return 1;
    else
        return 0;
}

void book::update()
{
    cout << "These are the books avaliable, type in the ID of the book you want to update. " << endl;
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;
        }
    }
    fin.close();

    int id, flag = 0, choice;
    ifstream read_file;
    ofstream update_file;
    read_file.open("book.txt");
    update_file.open("temp.txt");
    cout << "Enter the ID of the book you want to update: ";
    cin >> id;
    while (read_file >> book_id)
    {
        if (book_id == id)
        {
            flag = 1;
            read_file.ignore(1, '\n');
            read_file.getline(b_name, 30);
            cout << "Book Name: " << b_name << endl;
            read_file.getline(author_name, 30);
            cout << "Author Name: " << author_name << endl;
            read_file.getline(category, 30);
            cout << "Category: " << category << endl;
            read_file >> price;
            cout << "Price: " << price << endl;
            read_file >> quantity;
            cout << "Quantity: " << quantity << endl;
            cout << "Enter the new details:" << endl;
            cout << "What do you want to update?\n1. Book Name\n2. Author Name\n3. Category\n4. Price\n5. Quantity\nEnter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Enter Book Name: ";
                cin.ignore(1, '\n');
                cin.getline(b_name, 30);
                break;
            case 2:
                cout << "Enter Author Name: ";
                cin.ignore(1, '\n');
                cin.getline(author_name, 30);
                break;
            case 3:
                cout << "Enter Category: ";
                cin >> category;
                break;
            case 4:
                cout << "Enter Price: ";
                cin >> price;
                break;
            case 5:
                cout << "Enter Quantity: ";
                cin >> quantity;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
            update_file << book_id << "\n" << b_name << "\n" << author_name << "\n" << category << "\n" << price << " " << quantity << " ";
        }
        else
        {
            read_file.ignore(1, '\n');
            update_file << book_id << "\n";
            read_file.getline(b_name, 30);
            update_file << b_name << "\n";
            read_file.getline(author_name, 30);
            update_file << author_name << "\n";
            read_file.getline(category, 30);
            update_file << category << "\n";
            read_file >> price;
            update_file << price << " ";
            read_file >> quantity;
            update_file << quantity << " ";
        }
    }
    if (flag == 0)
    {
        cout << "Book not found!" << endl;
    }
    else
    {
        read_file.close();
        update_file.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
    system("pause");
}

void book::print_bill()
{
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;

        }
    }
    fin.close();

    int book_id;
    char choice;

    ifstream fin_invoice;
    fin_invoice.open("invoice_number.txt", ios::in);
    if (fin_invoice.is_open()) {
        fin_invoice >> invoice_number;
        fin_invoice.close();
    }
    else {
        invoice_number = rand() % 1000 + 1;
    }
    string books_purchased[100];
    int i = 0, book_count;
    do {
        cout << "Enter the book ID: ";
        cin >> book_id;

        ifstream fin;
        ofstream temp;
        fin.open("book.txt", ios::in);
        temp.open("temp.txt", ios::out);

        if (!fin)
        {
            cout << "File not found";
        }
        else
        {
            int id, q;
            float p;
            char b_name[30], author_name[30], category[30];
            while (fin >> id)
            {
                fin.ignore(1, '\n');
                fin.getline(b_name, 30);
                fin.getline(author_name, 30);
                fin.getline(category, 30);
                fin >> p;
                fin >> q;
                if (id == book_id)
                {
                    book_count++;
                    if (q <= 0)
                    {
                        cout << "This book is not available" << endl;
                    }
                    else
                    {
                        q--;
                        total_cost += p;
                        cout << "Book ID: " << book_id << ", Name: " << b_name << ", Quantity: " << q << ", Price: " << p << endl;
                        books_purchased[i] = b_name;
                    }
                }
                temp << id << endl << b_name << endl << author_name << endl << category << endl << p << endl << q << endl;
            }
        }
        fin.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        cout << "Do you want to add more books? (y/n) ";
        cout << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    system("cls");
    cout << setw(70) << "\t\tBILL" << endl;
    cout << setw(70) << "\t\t---------------------------" << endl;
    cout << setw(50) << "\t\tBookshop: Peace Bookshop" << endl;
    cout << setw(50) << "\t\tInvoice number: " << invoice_number << endl;
    cout << setw(50) << "\t\tBooks purchased:  ";
    for (int i = 0; i < 100; i++)
    {
        if (books_purchased[i] != "") {
            cout << setw(50) << books_purchased[i] << endl;
        }
    }
    cout << setw(50) << "\t\tNumber of Books: " << book_count << endl;
    cout << setw(50) << "\t\tTotal cost: " << total_cost << endl;
    cout << setw(70) << "\t\t---------------------------" << endl;
    cout << setw(70) << "\t\tThank you for shopping with us!" << endl;
    ofstream fout_invoice;
    fout_invoice.open("invoice_number.txt");
    if (fout_invoice.is_open()) {
        fout_invoice << invoice_number + 1;
        fout_invoice.close();
    }

    ofstream receipt;
    receipt.open("receipt.txt", ios::app);
    if (receipt.is_open()) {
        receipt << invoice_number << endl;

        for (int i = 0; i < book_count; i++)
        {
            receipt << books_purchased[i] << endl;
        }
        receipt << book_count << endl << total_cost << endl;
        receipt.close();
        cout << "Sales data added to file successfully!" << endl;
        total_cost = 0;
    }
    else {
        cout << "Error opening file!" << endl;
    }
    system("pause");
}

void book::show_sales()
{
    ifstream receiptFile("receipt.txt");
    int invoice, book_count, price, total = 0;
    string name;

    cout << "\t\t\tInvoice\t\tBook Name\t\tNum of Books\t\tTotal Price\n";
    while (receiptFile >> invoice >> name >> book_count >> price) {
        cout << "\t\t\t" << invoice << "\t\t" << name << "\t\t\t" << book_count << "\t\t\t" << price << endl;
        total += price;
    }
    for (int i = 0; i < 120; i++) {
        cout << "_";
    }
    cout << "\n\n\t\t\t\tTotal Sales: " << total << endl;
    for (int i = 0; i < 120; i++) {
        cout << "-";
    }
    receiptFile.close();
    system("pause");
}

void book::deleteData()
{
    int option;
    cout << "What do you want to delete?" << endl;
    cout << "1. Book data" << endl;
    cout << "2. Client data" << endl;
    cout << "3. Request data" << endl;
    cout << "4. Receipt data" << endl;
    cin >> option;

    switch (option) {
    case 1:
        deleteBookData();
        break;
    case 2:
        deleteClientData();
        break;
    case 3:
        deleteRequestData();
        break;
    case 4:
        deleteReceiptData();
        break;
    default:
        cout << "Invalid option" << endl;
    }
}

void book::deleteBookData()
{
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;
        }
    }
    fin.close();

    int id;
    string line, id2;
    cout << "Enter the ID of the Book you want to delete or type 'all' to delete all: ";
    cin >> id2;
    if (id2 == "all") {
        remove("book.txt");
        ofstream requestFile("book.txt");
        requestFile.close();
    } else {
        ifstream bookFile("book.txt");
        ofstream tempFile("temp.txt");

        int book_id;
        string b_name, author_name, category;
        float price;
        int quantity;

        while (bookFile >> book_id >> b_name >> price >> author_name >> category >> quantity) {
            if (book_id == stoi(id2)) {
                // Found the book to delete
                continue;
            }
            tempFile << book_id << " " << b_name << " " << price << " " << author_name << " " << category << " " << quantity << endl;
        }

        bookFile.close();
        tempFile.close();

        remove("book.txt");
        rename("temp.txt", "book.txt");
    }
}


void book::deleteClientData()
{
    ifstream clients_file("clients.txt");
    cout << left << setw(20) << "ID" << setw(20) << "Name" << setw(20) << "Address" << setw(20) << "Email" << setw(20) << "Phone Number" << setw(20) << "Age" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    string name, address, email, phone_number;
    int age, id;
    while (clients_file >> id >> name >> address >> email >> phone_number >> age) {
        cout << left << setw(20) << id << setw(20) << name << setw(20) << address << setw(20) << email << setw(20) << phone_number << setw(20) << age << endl;
    }
    clients_file.close();

    string id2;
    string line;
    cout << "Enter the ID of the client you want to delete: ";
    cin >> id2;

    ifstream clientFile("clients.txt");
    ofstream tempFile("temp.txt");

    while (getline(clientFile, line)) {
        if (line.find(id2) == string::npos) {
            tempFile << line << endl;
        }
    }

    clientFile.close();
    tempFile.close();

    remove("clients.txt");
    rename("temp.txt", "clients.txt");
}

void book::deleteRequestData()
{
    ifstream requests_file("requests.txt");
    int id;
    string name, book_name, author;
    cout << left << setw(20) << "ID" << setw(20) << "Name" << setw(30) << "Book Name" << setw(20) << "Author" << setw(20) << endl;
    cout << "----------------------------------------------------------------------------------------------------" << endl;
    while (requests_file >> id >> name >> book_name >> author) {
        cout << left << setw(20) << id << setw(20) << name << setw(30) << book_name << setw(20) << author << setw(20) << endl;
    }
    requests_file.close();

    string id2;
    string line;
    cout << "Enter the ID of the request you want to delete or type 'all' to delete all: ";
    cin >> id2;
    if (id2 == "all") {
        remove("requests.txt");
        ofstream requestFile("requests.txt");
        requestFile.close();
    }
    else {
        ifstream requestFile("requests.txt");
        ofstream tempFile("temp.txt");
        while (getline(requestFile, line)) {
            if (line.find(id2) == string::npos) {
                tempFile << line << endl;
            }
        }
        requestFile.close();
        tempFile.close();
        remove("requests.txt");
        rename("temp.txt", "requests.txt");
    }
}

void book::deleteReceiptData()
{
    ifstream receiptFile("receipt.txt");
    int invoice, book_count, price, total = 0;
    string name;

    cout << "\t\t\tInvoice\t\tBook Name\t\tNum of Books\t\tTotal Price\n";
    while (receiptFile >> invoice >> name >> book_count >> price) {
        cout << "\t\t\t" << invoice << "\t\t" << name << "\t\t\t" << book_count << "\t\t\t" << price << endl;
        total += price;
    }
    for (int i = 0; i < 120; i++) {
        cout << "_";
    }
    cout << "\n\n\t\t\t\tTotal Sales: " << total << endl;
    for (int i = 0; i < 120; i++) {
        cout << "-";
    }
    receiptFile.close();

    string id;
    string line;
    cout << "Enter the Invoice Number of the receipt you want to delete or type 'all' to delete all: ";
    cin >> id;
    if (id == "all") {
        remove("receipt.txt");
        ofstream receiptFile("receipt.txt");
        receiptFile.close();
    }
    else {
        ifstream receiptFile("receipt.txt");
        ofstream tempFile("temp.txt");
        while (getline(receiptFile, line)) {
            if (line != id) {
                tempFile << line << endl;
                getline(receiptFile, line);
                tempFile << line << endl;
                getline(receiptFile, line);
                tempFile << line << endl;
                getline(receiptFile, line);
                tempFile << line << endl;
            }
            else {
                for (int i = 0; i < 3; i++) {
                    getline(receiptFile, line);
                }
            }
        }

        receiptFile.close();
        tempFile.close();

        remove("receipt.txt");
        rename("temp.txt", "receipt.txt");
    }
}

class client :public book
{
public:
    char name[30];
    char address[50];
    char email[30];
    char phone[15];
    int age;
    void client_function();
    void client_registration();
    void request();
    void bill();

};

void client::client_function()
{
    int ch2;
    while (ch2 != 5) {
        system("cls");
        for (int i = 0; i < 120; i++)
        {
            cout << "_";
        }
        cout << "\n\n\n\t\t\t\t\t\tPeace Bookshop!" << endl;
        int k = 120;
        cout << "\n\n";
        for (int i = 0; i < 120; i++)
        {
            cout << (char)5;
        }
        cout << "\n\n\t 1. Search a book               \t  \t 2. Request a book " << endl;
        cout << "\n\t 3. Register yourself             \t  \t 4. Purchase book(s) " << endl;
        cout << "\n\t 5. Main Menu" << endl;
        cout << "\nEnter your choice : ";
        cin >> ch2;
                for (int i = 0; i < 120; i++)
        {
            cout << "-";
        }
        switch (ch2)
        {
        case 1:
            list_view();
            break;
        case 2:
            request();
            break;
        case 3:
            client_registration();
            break;
        case 4:
            bill();
            break;
        case 5:
            system("cls");
            display();
            break;
        default:
            system("cls");
            cout << "\n\nEnter valid option " << endl;
            exit(0);
        }
        system("cls");
    }
}

void client::request()
{
    int ans, id;
    cout << "Are you registered? " << endl;
    cout << "1. Yes              \t  \t    2. No (Get Regestred) " << endl;;
    cout << "Enter you choice : ";
    cin >> ans;
    if (ans == 1)
    {
        cout << "Enter your name: ";
        cin >> name;
        cout << "Enter the book details you want:" << endl;
        cout << "Book name: ";
        cin >> b_name;
        cout << "Author name: ";
        cin >> author_name;

        ifstream id_file("id.txt");
        id_file >> id;
        id_file.close();

        ofstream request_file("requests.txt", ios::app);
        request_file << id << " " << name << " " << b_name << " " << author_name << " " << endl;
        request_file.close();
        ofstream id_file_out("id.txt");
        id_file_out << id + 1;
        id_file_out.close();

        cout << "Your request has been saved. We will notify you when the book becomes available." << endl;
        system("pause");
        system("cls");
        client_function();
    }
    if (ans == 2)
    {
        client_registration();
    }
}

void client::client_registration()
{
    int id;
    ifstream id_file("id.txt");
    id_file >> id;
    id++;
    id_file.close();
    cin.ignore(1, '\n');
    cout << "Enter your name: ";
    cin.getline(name, 30);
    cout << "Enter your City: ";
    cin.getline(address, 50);
    cout << "Enter your email: ";
    cin.getline(email, 30);
    cout << "Enter your phone number: ";
    cin >> phone;
    cout << "Enter your age: ";
    cin >> age;

    ofstream file;
    file.open("clients.txt", ios::app);
    file << id << " " << name << " " << address << " " << email << " " << phone << " " << age << endl;
    file.close();
    cout << "\nID : " << id;
    cout << "\nName : " << name;
    cout << "\nCity : " << address;
    cout << "\nEmail : " << email;
    cout << "\nPhone : " << phone;
    cout << "\nAge : " << age << endl << endl;

    cout << "Your client account has been created successfully." << endl;
    ofstream id_file_out("id.txt");
    id_file_out << id + 1;
    id_file_out.close();
    system("pause");
    system("cls");
    client_function();
}

void client::bill()
{
    ifstream fin;
    fin.open("book.txt", ios::in);
    if (!fin)
    {
        cout << "File not found";
    }
    else
    {
        cout << "\n\t\t\t\tBook List\n";
        cout << "\n\tBook ID\t\tBook Name\tAuthor\t\tCategory\tPrice\tQuantity" << endl;
        cout << "\t----------------------------------------------------------------------------------------------------" << endl;
        while (fin >> book_id)
        {
            fin.ignore(1, '\n');
            fin.getline(b_name, 30);
            fin.getline(author_name, 30);
            fin.getline(category, 30);
            fin >> price;
            fin >> quantity;
            cout << "\t" << setw(8) << left << book_id << "\t" << setw(10) << left << b_name << "\t" << setw(10) << left << author_name << "\t" << setw(10) << left << category << "\t" << setw(8) << left << price << "\t" << setw(8) << left << quantity << endl;

        }
    }
    fin.close();

    int book_id, invoice_number;
    char choice;
    float total_cost = 0;
    ifstream fin_invoice;
    fin_invoice.open("invoice_number.txt", ios::in);
    if (fin_invoice.is_open()) {
        fin_invoice >> invoice_number;
        fin_invoice.close();
    }
    else {
        invoice_number = rand() % 1000 + 1;
    }
    string books_purchased[100] = { "" };
    int i = 0;
    string name;
    int book_count = 0;
    cout << "Enter your name: ";
    cin >> name;
    do {

        cout << "Enter the book ID: ";
        cin >> book_id;

        ifstream fin;
        ofstream temp;
        fin.open("book.txt", ios::in);
        temp.open("temp.txt", ios::out);

        if (!fin)
        {
            cout << "File not found";
        }
        else
        {
            int id, q;
            float p;
            char b_name[30], author_name[30], category[30];
            while (fin >> id)
            {
                fin.ignore(1, '\n');
                fin.getline(b_name, 30);
                fin.getline(author_name, 30);
                fin.getline(category, 30);
                fin >> p;
                fin >> q;
                if (id == book_id)
                {
                    book_count++;
                    if (q <= 0)
                    {
                        cout << "This book is not available" << endl;
                    }
                    else
                    {
                        q--;
                        total_cost += p;
                        cout << "Book ID: " << book_id << ", Name: " << b_name << ", Quantity: " << q << ", Price: " << p << endl;
                        books_purchased[i] = b_name;
                    }
                }
                temp << id << endl << b_name << endl << author_name << endl << category << endl << p << endl << q << endl;
            }
        }
        fin.close();
        temp.close();
        remove("book.txt");
        rename("temp.txt", "book.txt");
        cout << "Do you want to add more books? (y/n) ";
        cout << endl;
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    system("cls");
    cout << setw(70) << "BILL" << endl;
    cout << setw(70) << "---------------------------" << endl;
    cout << setw(50) << "Bookshop: Peace Bookshop" << endl;
    cout << setw(50) << "Invoice number: " << invoice_number << endl;
    cout << setw(50) << "Name: " << name << endl;
    cout << setw(50) << "Books purchased: " << endl;
    for (int i = 0; i < 100; i++)
    {
        if (books_purchased[i] != "") {
            cout << setw(50) << books_purchased[i] << endl;
        }
    }
    cout << setw(50) << "Number of Books: " << book_count << endl;
    cout << setw(50) << "Total cost: " << total_cost << endl << endl;
    cout << "_______________________________________________" << endl << endl;
    cout << "Please Pay " << total_cost << " at the counter and collect your book(s)." << endl << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Thank you for Shopping with us!" << endl << endl;
    ofstream fout_invoice;
    fout_invoice.open("invoice_number.txt", ios::out);
    if (fout_invoice.is_open()) {
        fout_invoice << invoice_number + 1;
        fout_invoice.close();
    }

    ofstream receipt;
    receipt.open("receipt.txt", ios::app);
    if (receipt.is_open()) {
        receipt << invoice_number << endl;
        for (int i = 0; i < book_count; i++)
        {
            receipt << books_purchased[i] << endl;
        }
        receipt << book_count << endl << total_cost << endl;
        invoice_number++;
        receipt.close();
        cout << "Sales data added to file successfully!" << endl;
        total_cost = 0;
    }
    else {
        cout << "Error opening file!" << endl;
    }
    system("pause");
}

int main()
{
    Menu menu;
    book b;
    client c;
    int option;

    while (true) {
        menu.display();
        cin >> option;
        if (option == 1)
        {
            b.admin_function();
            b.admin_dash();
        }
        else if (option == 2)
        {
            c.client_function();
        }
        menu.select(option);
    }
    return 0;
}
