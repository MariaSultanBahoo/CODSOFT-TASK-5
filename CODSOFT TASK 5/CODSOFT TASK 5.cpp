// CODSOFT TASK 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<iostream> 
 #include<fstream> 
 #include<cstdlib> 
 #include<ctime> 
 using namespace std; 
  
 class Book { 
 public: 
     int id; 
     float price; 
     string name, author, publisher; 
     bool available; 
  
     Book() { 
         id = 0; 
         price = 0.0; 
         name = ""; 
         author = ""; 
         publisher = ""; 
         available = true; 
     } 
  
     void inputBook() { 
         cout << "\nEnter Book ID: "; 
         cin >> id; 
         cout << "Enter Book Name: "; 
         cin >> name; 
         cout << "Enter Author Name: "; 
         cin >> author; 
         cout << "Enter Publisher Name: "; 
         cin >> publisher; 
         cout << "Enter Book Price: "; 
         cin >> price; 
     } 
  
     void displayBook() { 
         cout << "\nBook ID: " << id; 
         cout << "\nBook Name: " << name; 
         cout << "\nAuthor Name: " << author; 
         cout << "\nPublisher Name: " << publisher; 
         cout << "\nBook Price: " << price << endl; 
         cout << "Availability: " << (available ? "Available" : "Not Available") << endl; 
     } 
  
     void updateAvailability(bool status) { 
         available = status; 
     } 
 }; 
  
 class Library { 
 private: 
     static const int MAX_BOOKS = 25; 
     Book books[MAX_BOOKS]; 
     int numBooks; 
  
 public: 
     Library() { 
         numBooks = 0; 
     } 
  
     void insertBook() { 
         if (numBooks < MAX_BOOKS) { 
             books[numBooks].inputBook(); 
             numBooks++; 
             cout << "Insert New Book Successfully" << endl; 
         } 
         else { 
             cout << "Library is full. Cannot insert more books." << endl; 
         } 
     } 
  
     void searchBook() { 
         int searchId; 
         cout << "\nEnter Book ID for Search: "; 
         cin >> searchId; 
  
         for (int i = 0; i < numBooks; i++) { 
             if (searchId == books[i].id) { 
                 books[i].displayBook(); 
                 return; 
             } 
         } 
  
         cout << "Book is Not Found" << endl; 
     } 
  
     void updateBook() { 
         int updateId; 
         cout << "Enter Book ID for Update: "; 
         cin >> updateId; 
  
         for (int i = 0; i < numBooks; i++) { 
             if (updateId == books[i].id) { 
                 books[i].inputBook(); 
                 cout << "Update Book Successfully" << endl; 
                 return; 
             } 
         } 
  
         cout << "Book is Not Found" << endl; 
     } 
  
  
     void showAllBooks() { 
         if (numBooks == 0) { 
             cout << "Library Is Empty" << endl; 
         } 
         else { 
             for (int i = 0; i < numBooks; i++) { 
                 books[i].displayBook(); 
             } 
         } 
     } 
  
     void checkoutBook() { 
         int checkoutId; 
         cout << "Enter Book ID to Checkout: "; 
         cin >> checkoutId; 
  
         for (int i = 0; i < numBooks; i++) { 
             if (checkoutId == books[i].id) { 
                 if (books[i].available) { 
                     books[i].updateAvailability(false); 
                     cout << "Book Checked Out Successfully" << endl; 
                 } 
                 else { 
                     cout << "Book is Not Available for Checkout" << endl; 
                 } 
                 return; 
             } 
         } 
  
         cout << "Book is Not Found" << endl; 
     } 
  
     void returnBook() { 
         int returnId; 
         cout << "Enter Book ID to Return: "; 
         cin >> returnId; 
  
         for (int i = 0; i < numBooks; i++) { 
             if (returnId == books[i].id) { 
                 books[i].updateAvailability(true); 
                 cout << "Book Returned Successfully" << endl; 
                 return; 
             } 
         } 
  
         cout << "Book is Not Found" << endl; 
     } 
  
     void calculateOverdueBooks() { 
         // Assuming a book is overdue if it's not available (checked out) 
         int overdueCount = 0; 
         for (int i = 0; i < numBooks; i++) { 
             if (!books[i].available) { 
                 overdueCount++; 
             } 
         } 
         cout << "Number of Overdue Books: " << overdueCount << endl; 
     } 
 }; 
  
 int main() { 
     Library library; 
  
     int choice; 
     do { 
         cout << "\t*******WELCOME TO FJWU LIBRARY*******\n";
         cout<<"\n1.Insert Book";
        cout<< "\n2. Search Book";
        cout<< "\n3. Update Book";
         cout<<"\n4. Show All Books";
        cout<< "\n5. Checkout Book";
       cout<< "\n6. Return Book";
       cout<< "\n7. Calculate Overdue Books";
        cout<<"\n8. Exit\n";
           cout<<"\tEnter Your Choice:"; 
         cin >> choice; 
  
         switch (choice) { 
         case 1: 
             library.insertBook(); 
             system("pause");
             system("cls");
             break; 
         case 2: 
             library.searchBook(); 
             system("pause");
             system("cls");
             break; 
         case 3: 
             library.updateBook(); 
             system("pause");
             system("cls");
             break; 
         case 4: 
             library.showAllBooks(); 
             system("pause");
             system("cls");
             break; 
         case 5: 
             library.checkoutBook(); 
             system("pause");
             system("cls");
             break; 
         case 6: 
             library.returnBook(); 
             system("pause");
             system("cls");
             break; 
         case 7: 
             library.calculateOverdueBooks(); 
             system("pause");
             system("cls");
             break; 
         case 8: 
             cout << "Exiting Library Management System" << endl; 
             system("pause");
             system("cls");
             break; 
         default: 
             cout << "Please Select Correct Option" << endl; 
         } 
     } while (choice != 8); 
  
     return 0; 
 }