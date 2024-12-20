#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class account {
    private:
        string userName, userEmail, userPassword;
        string searchName, searchPassword;
        fstream userData;
        bool loginSuccess = false;
        bool loginStatus;
        char yesNo;
    public:
        int accountLoginSignup();
        int login();
        void signup();
}acc;

class trip {
    private:
        double tripBill, total;
        int tripDestination, userLocation, totalMembers;
        string userFeedback;
        fstream fdbk;
        const double fareTable[15][15] = {
            // Islamabad, Lahore, Karachi, Peshawar, Quetta, Multan, Faisalabad, Gujranwala, Hyderabad, Abbottabad, Sawat, Murree, DGK, Chitral, Gilgit
            //I   L    K      P     Q     M     F    G     H     A    S     M     D    C     G
            {0, 2300, 5500, 1000, 3600, 2100, 1350, 1400, 5300, 900, 1100, 700, 2500, 3550, 4000},
            {2300, 0, 5500, 2600, 4000, 1000, 750, 400, 7150, 2300, 2000, 2400, 1800, 5080, 5000},
            {5500, 5500, 0, 5000, 1700, 2600, 5000, 4800, 750, 8100, 6500, 6000, 3500, 5000, 6200},
            {1000, 2600, 5000, 0, 4200, 3170, 2250, 2090, 7800, 950, 850, 1500, 2600, 3700, 4100},
            {3600, 4000, 1700, 4200, 0, 2500, 900, 4400, 6300, 2050, 2300, 2650, 2000, 4700, 4950},
            {2100, 1000, 2600, 3170, 2500, 0, 1500, 1400, 2450, 1900, 1750, 1950, 1200, 4100, 4400},
            {1350, 750, 5000, 2250, 900, 1500, 0, 600, 4700, 1800, 1550, 1800, 1300, 4700, 4800},
            {1400, 400, 4800, 2090, 4400, 1400, 600, 0, 4550, 1750, 1450, 1750, 1100, 4900, 5000},
            {5300, 7150, 750, 7800, 6300, 2450, 4700, 4550, 0, 8600, 6800, 6400, 3700, 5200, 6500},
            {900, 2300, 8100, 950, 2050, 1900, 1800, 1750, 8600, 0, 750, 1000, 2800, 3500, 4000},
            {1100, 2000, 6500, 850, 2300, 1750, 1550, 1450, 6800, 750, 0, 650, 2300, 3600, 4100},
            {700, 2400, 6000, 1500, 2650, 1950, 1800, 1750, 6400, 1000, 650, 0, 2200, 3700, 4100},
            {2500, 1800, 3500, 2600, 2000, 1200, 1300, 1100, 3700, 2800, 2300, 2200, 0, 4300, 4600},
            {3550, 5080, 5000, 3700, 4700, 4100, 4700, 4900, 5200, 3500, 3600, 3700, 4300, 0, 3900},
            {4000, 5000, 6200, 4100, 4950, 4400, 4800, 5000, 6500, 4000, 4100, 4100, 4600, 3900, 0}
        };
        char vehicle, tripTime, feedbk;
    public:
        int transport();
        int timing();
        int destination();
        int starting();
        int billCalculation(int, int);
        int routeBill(int, int);
        int feedback();
}trip;

struct membersOfTrip {
    public:
        int numberOfTotalMembers;
        int femaleMembers, maleMembers;
        int numberOfTravelers, memberGenders;
        int totalMale = 0, totalFemale = 0;
        int totalMembers = 0;
        string membersNames[150];
        int members();
        void displayMembers();
}mot;

int main() {

    int tirpPrice = 0, routeFare = 0, totalInvoice = 0;
    int userLocation, userDestination, conveyance, timeSlot; 
    int totalMembersOfTrip = mot.totalMembers;
    bool userLogin;
    char tryAgain;

    cout << "------------------------- Welcome to Travel Agency -------------------------" << endl << endl << endl;
    userLogin = acc.accountLoginSignup();

    if (userLogin == 1) {

        system("cls");
        cout << "========================= Welcome to Travel Agency =========================" << endl << endl;

    } else {

        while (userLogin == 0) {
            cout << "Login Error... Please Try again." << endl << endl;
            cout << "Do you want to Try Again? (Y/n): ";
            tryAgain = getchar();

            if ((tryAgain == 'y') || (tryAgain == 'Y')) {
                userLogin = acc.accountLoginSignup();

                if (userLogin == 1) {
                    system("cls");

                    cout << "========================= Welcome to Travel Agency =========================" << endl << endl;
                    break;
                }
            } else if ((tryAgain == 'n') || (tryAgain == 'N')) {
                cout << endl << "Good Bye...";
                getchar();
                return 0;
            }
        }
    }
    
    userLocation = trip.starting();

    userDestination = trip.destination();

    conveyance = trip.transport();

    timeSlot = trip.timing();

    mot.members();

    tirpPrice = trip.billCalculation(userLocation, userDestination);

    routeFare = trip.routeBill(tirpPrice, totalMembersOfTrip);

    if (conveyance == 1) {
        totalInvoice = routeFare * 1;
    } else if (conveyance == 2) {
        totalInvoice = routeFare * 1.5;
    } else if (conveyance == 3) {
        totalInvoice = routeFare * 3.5;
    } else {
        cerr << "Error in transport...";
    }

    cout << endl << endl;
    cout << "=================================================================" << endl;
    cout << "                          FINAL INVOICE                          " << endl;
    cout << "=================================================================" << endl;

    cout << endl;

    cout << "Strating Point :: " << userLocation << endl;
    cout << "Destination :: " << userDestination << endl;
    cout << "Total Members Traveling :: " << mot.numberOfTotalMembers << endl;
    cout << endl;
    cout << "Travelers Details.";
    mot.displayMembers();

    cout << endl;

    cout << "=================================================================" << endl;
    cout << "               Grand Total :: " << totalInvoice << endl;
    cout << "=================================================================" << endl;



    return 0;

}

int account :: accountLoginSignup() {

    cout << endl << "Do you have an Account? (Y/n) :: ";
    yesNo = getchar();

    if ((yesNo == 'y') || (yesNo == 'Y')) {
        system("cls");
        loginStatus = acc.login();
    } else if ((yesNo == 'n') || (yesNo == 'N')) {
        acc.signup();
        cout << endl << "Signup successful... Press any key to Login your Account..." << endl;
        getchar();
        system("cls");
        loginStatus = acc.login();
    } else {
        while ((yesNo != 'y') || (yesNo != 'Y') || (yesNo != 'n') || (yesNo != 'N')) {
            cout << endl << "You Entered a wrong chracter...\nPlease Enter (Y/n) :: ";
            yesNo = getchar();

            if ((yesNo == 'y') || (yesNo == 'Y')) {
                acc.login();
                break;
            } else if ((yesNo == 'n') || (yesNo == 'N')) {
                acc.signup();
                cout << endl << "Signup successful... Press any key to Login your Account..." << endl;
                getchar();
                system("cls");
                loginStatus = acc.login();
                break;
            }
        }
    }

    return loginStatus;

}

int account :: login() {

    cin.ignore();

    cout << "=============== LOGIN PAGE ===============" << endl << endl << endl;

    cout << "Enter Your Account Username :: ";
    getline(cin, searchName);

    cout << endl << "Enter Your Account Password :: ";
    getline(cin, searchPassword);

    userData.open("UserInfo.txt", ios::in);

    if (!userData) {
        cerr << "Error Reading file for Reading" << endl;
        return 0;
    }

    while (getline(userData, userName, '*') && getline(userData, userEmail, '*') && getline(userData, userPassword, '\n')) {
        if (searchName == userName) {
            if (searchPassword == userPassword) {
                cout << endl << "Login Successfull...";
                cout << endl << "Press any key to Continue...";
                getchar();
                loginSuccess = true;
                break;
            } else {
                cout << "Invalid Password...";
                loginSuccess = false;
                break;
            }
        }
    }

    userData.close();

    if (!loginSuccess) {
        cout << endl << "Account Login Failed...\nInvalid Username or Password...";

    }

    return (loginSuccess ? 1 : 0);

}

void account :: signup() {

    system("cls");
    cin.ignore();

    cout << "=============== SIGN UP PAGE ===============" << endl << endl << endl;

    cout << "Enter UserName for Your Account :: ";
    getline(cin, userName);

    cout << endl << "Enter Email for Your Account :: ";
    getline(cin, userEmail);

    cout << endl << "Enter Password for Your Account :: ";
    getline(cin, userPassword);

    userData.open("UserInfo.txt", ios::out | ios::app);
    userData << userName << "*" << userEmail << "*" << userPassword << endl;
    userData.close();

}

int trip::starting() {

    cout << "Select your starting point." << endl << endl;
    cout << "1) Islamabad" << endl;
    cout << "2) Lahore" << endl;
    cout << "3) Karachi" << endl;
    cout << "4) Peshawar" << endl;
    cout << "5) Quetta" << endl;
    cout << "6) Multan" << endl;
    cout << "7) Faisalabad" << endl;
    cout << "8) Gujranwala" << endl;
    cout << "9) Hyderabad" << endl;
    cout << "10) Abbottabad" << endl;
    cout << "11) Sawat" << endl;
    cout << "12) Murree" << endl;
    cout << "13) Dera Ghazi-Khan" << endl;
    cout << "14) Chitral" << endl;
    cout << "15) Gilgit" << endl;

    cout << "Select your choice (1-15) :: ";
    cin >> userLocation;

    if ((userLocation >= 1) && (userLocation <= 15)) {
        userLocation--;
        return userLocation;
    } else {
        while ((userLocation < 1) && (userLocation > 15)) {
            cout << "Invalid Location Entered... Please Select again..." << endl << endl;
            cout << "1) Islamabad" << endl;
            cout << "2) Lahore" << endl;
            cout << "3) Karachi" << endl;
            cout << "4) Peshawar" << endl;
            cout << "5) Quetta" << endl;
            cout << "6) Multan" << endl;
            cout << "7) Faisalabad" << endl;
            cout << "8) Gujranwala" << endl;
            cout << "9) Hyderabad" << endl;
            cout << "10) Abbottabad" << endl;
            cout << "11) Sawat" << endl;
            cout << "12) Murree" << endl;
            cout << "13) Dera Ghazi-Khan" << endl;
            cout << "14) Chitral" << endl;
            cout << "15) Gilgit" << endl;

            cout << "Select your choice (1-15) :: ";
            cin >> userLocation;

            if ((userLocation >= 1) && (userLocation <= 15))
                break;
        }
    }

    userLocation--;

    return userLocation;

}

int trip :: destination() {

    cout << "Enter your desired destination." << endl << endl;
    cout << "1) Islamabad" << endl;
    cout << "2) Lahore" << endl;
    cout << "3) Karachi" << endl;
    cout << "4) Peshawar" << endl;
    cout << "5) Quetta" << endl;
    cout << "6) Multan" << endl;
    cout << "7) Faisalabad" << endl;
    cout << "8) Gujranwala" << endl;
    cout << "9) Hyderabad" << endl;
    cout << "10) Abbottabad" << endl;
    cout << "11) Sawat" << endl;
    cout << "12) Murree" << endl;
    cout << "13) Dera Ghazi-Khan" << endl;
    cout << "14) Chitral" << endl;
    cout << "15) Gilgit" << endl;

    cout << "Select your choice :: ";
    cin >> tripDestination;

    if ((tripDestination >= 1) && (tripDestination <= 15)) {
        tripDestination--;
        return tripDestination;
    } else {
        while ((tripDestination < 1) && (tripDestination > 15)) {
            cout << "Invalid Destination Entered... Please Select again..." << endl;
            cout << "1) Islamabad" << endl;
            cout << "2) Lahore" << endl;
            cout << "3) Karachi" << endl;
            cout << "4) Peshawar" << endl;
            cout << "5) Quetta" << endl;
            cout << "6) Multan" << endl;
            cout << "7) Faisalabad" << endl;
            cout << "8) Gujranwala" << endl;
            cout << "9) Hyderabad" << endl;
            cout << "10) Abbottabad" << endl;
            cout << "11) Sawat" << endl;
            cout << "12) Murree" << endl;
            cout << "13) Dera Ghazi-Khan" << endl;
            cout << "14) Chitral" << endl;
            cout << "15) Gilgit" << endl;

            cout << "Select your choice (1-15): ";
            cin >> tripDestination;

            if ((tripDestination >= 1) && (tripDestination <= 15))
                break;
        }
    }

    tripDestination--;

    return tripDestination;

}

int trip :: timing() {

    cout << endl << "Select your departure time" << endl << endl;

    cout << "1) Morning   | 6:00 am." << endl;
    cout << "2) Afternoon | 12:15 pm." << endl;
    cout << "3) Evening   | 7:30 pm." << endl;
    cout << "4) Night     | 11:15 pm." << endl;
    cout << "Pick your choice (1-4) :: ";
    cin >> tripTime;

    if ((tripTime == '1') || (tripTime == '2') || (tripTime == '3') || (tripTime == '4')) {
        return tripTime;
    } else {
        while ((tripTime != '1') || (tripTime != '2') || (tripTime != '3') || (tripTime != '4')) {

            cout << endl << "Invalid Selection || Select Again..." << endl << endl;

            cout << "1) Morning   | 6:00 am." << endl;
            cout << "2) Afternoon | 12:15 pm." << endl;
            cout << "3) Evening   | 7:30 pm." << endl;
            cout << "4) Night     | 11:15 pm." << endl;
            cout << "Pick your choice: ";
            cin >> tripTime;

            if ((tripTime == '1') || (tripTime == '2') || (tripTime == '3') || (tripTime == '4'))
                break;
        }
        return tripTime;
    }

}

int trip :: transport() {

    cout << endl << "How would you like to travel?" << endl << endl;

    cout << "1) Bus" << endl;
    cout << "2) Train" << endl;
    cout << "3) Aeroplane" << endl;
    cout << "Enter Your Choice (1-3) :: ";
    cin >> vehicle;

    if ((vehicle == '1') || (vehicle == '2') || (vehicle == '3')) {
        return vehicle;
    } else {
        while ((vehicle != '1') || (vehicle != '2') || (vehicle != '3')) {

            cout << endl << "Invalid Selection || Select Again..." << endl << endl;

            cout << "1) Bus" << endl;
            cout << "2) Train" << endl;
            cout << "3) Aeroplane" << endl;
            cout << "Enter Your Choice (1-3) :: ";
            cin >> vehicle;

            if ((vehicle == '1') || (vehicle == '2') || (vehicle == '3'))
                break;
        }
        return vehicle;
    }

}

int trip :: feedback() {

    cout << "Could you spare a moment to give us your feedback? (Y/n) :: ";
    cin >> feedbk;

    if ((feedbk == 'y') || (feedbk == 'Y')) {

        cout << endl << "Feedback :: ";
        cin.ignore();
        getline(cin, userFeedback);

        fdbk.open("feedback.txt", ios::out | ios::app);
        fdbk << userFeedback;
        fdbk.close();

        cout << endl << endl << "Thank you for sharing your thoughts with us. We're honored you choose our service.";

    } else if ((feedbk == 'n') || (feedbk == 'N')) {

        cout << endl << "We're honored to serve you. Thanks for choosing our service.";

    } else {

        while ((feedbk != 'y') || (feedbk != 'Y') || (feedbk != 'n') || (feedbk != 'N')) {
            cout << endl << endl << "Invalid Chrachter... Enter (Y/n) :: ";
            cin >> feedbk;

            if ((feedbk == 'y') || (feedbk == 'Y')) {
                cout << endl << endl << "Feedback: ";
                cin.ignore();
                getline(cin, userFeedback);

                fdbk.open("feedback.txt", ios::out | ios::app);
                fdbk << userFeedback << endl;
                fdbk.close();

                cout << endl << endl << "Thank you for sharing your thoughts with us. We're honored you choose our service";
                break;

            } else if ((feedbk == 'n') || (feedbk == 'N')) {
                cout << endl << "We're honored to serve you. Thanks for choosing our service.";
                break;
            }
        }

    }

    return 0;

}

int trip :: billCalculation(int userLocation, int userDestination) {

    if ((userLocation >= 0) && (userLocation < 15) && (userDestination >= 0) && (userDestination < 15)) {
        tripBill = fareTable[userLocation][userDestination];
    } else {
        cout << "Invalid Location Enterd..... Process Failed.....";
    }

    return tripBill;

}

int trip :: routeBill(int tirpPrice, int totalMembersOfTrip) {

    total = tirpPrice * totalMembersOfTrip;

    return total;

}

int membersOfTrip :: members() {

    cout << "How many peoples are traveling. " << endl;
    cout << "1) Just Me" << endl;
    cout << "2) More than One";
    cout << "Enter your selection (1-2) :: ";
    cin >> numberOfTravelers;

    if (numberOfTravelers == '1') {
        cout << endl << "Enter your Name :: ";
        cin.ignore();
        getline(cin, membersNames[0]);

        cout << endl << "What is your Gender." << endl;
        cout << "1) Male" << endl;
        cout << "2) Female" << endl;
        cout << "Select an option (1-2): ";
        cin >> memberGenders;

        if (memberGenders == '1') {
            totalMale += 1;
        } else if (memberGenders == '2') {
            totalFemale += 1;
        } else {
            while ((memberGenders != '1') || (memberGenders != '2')) {
                cout << endl << "Invalid Selection.... Select Again...." << endl << endl;

                cout << "1) Male" << endl;
                cout << "2) Female" << endl;
                cout << "Select an option (1 or 2) :: ";
                cin >> memberGenders;

                if (memberGenders == '1') {
                    totalMale += 1;
                    break;
                } else if (memberGenders == '2') {
                    totalFemale += 1;
                    break;
                }
            }
        }

        totalMembers = 1;
        maleMembers = totalMale;
        femaleMembers = totalFemale;
        numberOfTotalMembers = totalMembers;

    } else if (numberOfTravelers == '2') {
        cout << "How many members are traveling with you including you? :: ";
        cin >> totalMembers;

        while (totalMembers <= 1) {
            cout << "Please enter a valid number (greater than 1) :: ";
            cin >> totalMembers;
        }

        cin.ignore();

        for (int i = 0; i < totalMembers; i++) {
            cout << endl << endl << "Enter the Name of Person " << i + 1 << " :: ";
            getline(cin, membersNames[i]);

            cout << endl << "Enter the Gender of Person " << i + 1 << " :: " << endl;
            cout << "1) Male" << endl;
            cout << "2) Female" << endl;
            cout << "Select an option (1-2) :: ";
            cin >> memberGenders;

            if (memberGenders == '1') {
                totalMale += 1;
            } else if (memberGenders == '2') {
                totalFemale += 1;
            } else {
                while ((memberGenders != '1') || (memberGenders != '2')) {

                    cout << endl << "Invalid Selection || Select Again..." << endl << endl;

                    cout << "1) Male" << endl;
                    cout << "2) Female" << endl;
                    cout << "Input your selection (1 or 2) :: ";
                    cin >> memberGenders;

                    if (memberGenders == '1') {
                        totalMale += 1;
                        break;
                    } else {
                        totalFemale += 1;
                        break;
                    }
                }
            }

            cin.ignore();

        }

        maleMembers = totalMale;
        femaleMembers = totalFemale;
        numberOfTotalMembers = totalMembers;

    }

    return 0;

}

void membersOfTrip :: displayMembers() {

    // cout << endl << "Total Members: " << numberOfTotalMembers;

    for (int j = 0; j < numberOfTotalMembers; j++) {
        cout << endl << "Member " << j + 1 << " Name :: " << membersNames[j];
    }

}

