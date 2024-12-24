#include<iostream>
#include<fstream>
#include<string>
#include<sstream> // To split input data

using namespace std;



void login();
void registration();
void forgot_password();
bool isemail_registered(string email);
bool username_registered(string username);
void clearscreen();

// main function
int main(){
    cout<<"_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
    cout<<"                       WELCOME TO THE REGISTRATION                  "<<endl;
    cout<<"                                                                    "<<endl;
    cout<<"Enter 1 if you haven't registered yet" << endl;
    cout<<"Enter 2 to login into your account" << endl;
    cout<<"Enter 3 if you have forgotten the password" << endl;
    cout<<"Enter 4 to exit" << endl;
    int choice;
    cout<<"Enter your choice:";
    cin>>choice;
    cout<<endl;
    
    switch (choice)
    {
    case 1:
        registration();
        break;
    case 2:
        login();
        break;
    case 3:
        forgot_password();
        break;
    case 4:
        cout<<"\t\t\t Thanks for visiting the page" <<endl;
        break;
    default:
        cout<<"You haven't chosen the right choice"<<endl;
        break;
    }

    return 0;
}

// Check if email is already registered
bool isemail_registered(string email){
    string rmail, ruserid, rpass;
    ifstream output("user_data.txt");
    while (output >> rmail >> ruserid >> rpass) {
        if (rmail == email) {
            return true;
        }  
    }
    return false;
}

// Registration - Username, email, Password
void registration(){
    string username, ruser, rmail, rpass;
    system("cls");
    cout<<"Enter the username: ";
    cin>>username;
    
    if(username_registered(username)){
        cout<<"Username already taken"<<endl;
        main();
        return;
    }
    
    string email;
    cout<<"Enter the Email:";
    cin>>email;
    
    if (isemail_registered(email)){
        cout<<"Your email is already registered \n" "Select choice 2 to login to your account"<<endl; 
        main();
        return;
    }
    
    string password;
    cout<<"Enter the password (enter without spaces): ";
    cin>>password;
    
    ofstream input("user_data.txt",ios::app);
    input<<email<<" "<<username<<" "<<password<<endl;
    input.close();
    
    cout<<"Your registration is successful"<<endl;
    main();
}

// Check if the username is already taken
bool username_registered(string username){
    string userid, email, pass;
    ifstream output("user_data.txt");
    while (output >> email >> userid >> pass) {
        if (userid == username) {
            return true;
        }
    }
    return false;
}

// Login - Enter username, password
void login(){
    string email, password,rmail, ruser, rpass;
     clearscreen();
    cout<<"Enter Email to login: ";
    cin>>email;
    cout<<"Enter password: ";
    cin>>password;
    
    ifstream input("user_data.txt");
    bool logged_in = false;
    
    while (input >> rmail >> ruser >> rpass) {
        if (rmail == email && rpass == password) {
            logged_in = true;
            break;
        }
    }
    
    if (logged_in) {
        cout<<"You successfully logged in to your account"<<endl;
    } else {
        cout<<"Invalid email id or password. Please try again."<<endl;
    }
    
    main();
}

// Forgot password - Enter the Gmail to recover password
void forgot_password(){
    clearscreen();
    string email;
    cout<<"Enter the mail with which you have registered: ";
    cin>>email;
    
    string rmail, ruser, rpass;
    ifstream input("user_data.txt");
    bool found = false;
    
    while (input >> rmail >> ruser >> rpass) {
        if (rmail == email) {
            cout<<"Your username is: " << ruser << endl;
            cout<<"Your password is: " << rpass << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout<<"Email is not registered yet"<<endl;
    }
    
    main();
}

void clearScreen() {
    #ifdef _WIN32
        system("cls");  // Windows
    #else
        system("clear");  // Linux/macOS
    #endif
}
