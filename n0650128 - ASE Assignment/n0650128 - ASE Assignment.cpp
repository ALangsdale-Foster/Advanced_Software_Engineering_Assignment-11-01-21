//I am aware of the University’s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University’s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#include <iostream>
#include "Transaction.h"
#include "Debit.h"
#include "Cashpoint.h"
#include "DirectDebit.h"
#include "Transfer.h"
#include "Creditpoint.h"
#include "Interest.h"
#include "List.h"
#include "Link.h"
#include <fstream>
#include <sstream>
#include <time.h>

char charCheck(char);
dateStruct constructDate();
timeStruct constructTime();
int enterInt(std::string input);
float enterFloat(std::string input);
int monthConv(std::string input);


int main()
{
    List* list = new List();
    bool menubreak = false;
    char input = 00;

    while (!menubreak) {
        
        //TESTING CODE -----------------------------------------------------------------
        /*dateStruct date;
        date.day = 1;
        date.month = 1;
        date.year = 1;
        timeStruct time;
        time.hour = 1;
        time.minute = 1;
        float Value = 1.0;
        int card = 1234;
        int id = 43534;
        int acc = 123456789;
        std::string name = "testname";
        std::string location = "testloc";
        std::string auth = "testauth";
        std::string ref = "TestRef";
        std::string sort = "11-22-33";
        std::string pay = "testpay";
        std::string inttype = "monthly";

        Debit* newDebit = new Debit(date, time, Value, card, name, location, auth);
        Debit* debitTwo = new Debit(date, time, 2.0, card, "newname", location, auth);
        Cashpoint* newCashpoint = new Cashpoint(date, time, Value, id, card);
        DirectDebit* newDirectDebit = new DirectDebit(date, time, Value, ref);
        Transfer* newTransfer = new Transfer(date, time, Value, acc, sort);
        CreditPoint* newCreditPoint = new CreditPoint(date, time, Value, pay);
        Interest* newInterest = new Interest(date, time, Value, inttype);*/

        /*std::cout << newDebit->getType() << std::endl;
        testinher(newDebit);
        std::cout << newCashpoint->getType() << std::endl;
        testinher(newCashpoint);
        std::cout << newDirectDebit->getType() << std::endl;
        testinher(newDirectDebit);
        std::cout << newTransfer->getType() << std::endl;
        testinher(newTransfer);
        std::cout << newCreditPoint->getType() << std::endl;
        testinher(newCreditPoint);
        std::cout << newInterest->getType() << std::endl;
        testinher(newInterest);*/

       /* std::cout << "testing list" << std::endl;*/
        /*list->add(newDebit);
        list->add(newCashpoint);
        list->add(newDirectDebit);
        list->add(newTransfer);
        list->add(newCreditPoint);
        list->add(newInterest);
        list->add(debitTwo);*/
        /*list->display();
        list->remove();
        std::cout << "testing list" << std::endl;
        list->display();*/

        //TESTING CODE -----------------------------------------------------------------

        std::cout << "Menu, please enter the corresponding character" << std::endl; //run menu in console
        std::cout << "Q - Quit" << std::endl;
        std::cout << "I - Insert" << std::endl;
        std::cout << "D - Delete" << std::endl;
        std::cout << "C - Contents" << std::endl;
        std::cout << "U - Upper Contents" << std::endl;
        std::cout << "S - Save" << std::endl;
        std::cout << "L - Load" << std::endl;
        std::cout << "N - Linear Search" << std::endl;
        std::cout << "T - Sort" << std::endl;
        std::cin >> input;
        //list->display();
        input = charCheck(input);//take user input
        //this should all be switch statements, but it works
        if (input == 81) { // Q - Quit
            menubreak = true;
        }
        else if (input == 73) {//create new list object
            std::cout << "Please Enter The New Transaction Type: " << std::endl;//this should all be switch statements
            std::string inString;
            std::cin >> inString;
            dateStruct transDate;
            timeStruct transTime;
            transDate = constructDate();
            transTime = constructTime();

            std::cout << "Please Enter Transaction Value: " << std::endl;
            std::string in;
            std::cin >> in;
            float transVal = enterFloat(in);

            if ((inString == "debit") || (inString == "DEBIT")) {
                std::cout << "Please Enter Card Number As Integer: " << std::endl;
                std::cin >> in;
                int cardNo = enterInt(in);

                std::cout << "Please Enter Retailer: " << std::endl;
                std::cin >> in;
                std::string Retailer = in;

                std::cout << "Please Enter Retailer Location: " << std::endl;
                std::cin >> in;
                std::string RetailerLoc = in;

                std::cout << "Please Enter Auth Method: " << std::endl;
                std::cin >> in;
                std::string AuthMeth = in;

                Debit* newDebit = new Debit(transDate, transTime, transVal, cardNo, Retailer, RetailerLoc, AuthMeth);
                list->add(newDebit);
                //list->display();
            }
            else if ((inString == "cashpoint") || (inString == "CASHPOINT")) {
                std::cout << "Please Enter Location ID As Integer: " << std::endl;
                std::cin >> in;
                int locID = enterInt(in);

                std::cout << "Please Enter Card Used As Integer: " << std::endl;
                std::cin >> in;
                int cardUsed = enterInt(in);

                Cashpoint* newCashpoint = new Cashpoint(transDate, transTime, transVal, locID, cardUsed);
                list->add(newCashpoint);
                
            }
            else if ((inString == "creditpoint") || (inString == "CREDITPOINT")) {
                std::cout << "Please Enter Payment Type: " << std::endl;
                std::cin >> in;
                CreditPoint* newCreditpoint = new CreditPoint(transDate, transTime, transVal, in);
                list->add(newCreditpoint);
            }
            else if ((inString == "directdebit") || (inString == "DIRECTDEBIT")) {
                std::cout << "Please Enter Reference: " << std::endl;
                std::cin >> in;
                DirectDebit* newDirectDebit = new DirectDebit(transDate, transTime, transVal, in);
                list->add(newDirectDebit);
            }
            else if ((inString == "interest") || (inString == "INTEREST")) {
                std::cout << "Please Enter Interest Type: " << std::endl;
                std::cin >> in;
                Interest* newInterest = new Interest(transDate, transTime, transVal, in);
                list->add(newInterest);
            }
            else if ((inString == "transfer") || (inString == "TRANSFER")) { 
                std::cout << "Please Enter Account Number: " << std::endl;
                std::cin >> in;
                int accVal = enterInt(in);

                std::cout << "Please Enter Sort Code: " << std::endl;
                std::cin >> in;

                Transfer* newTransfer = new Transfer(transDate, transTime, transVal, accVal, in);
                list->add(newTransfer);
            }
            else {
                std::cout << "Invalid Transaction Type, Returning To Menu" << std::endl;
            }
        }
        else if (input == 68) {//remove top list object
            std::cout << "Removing Top Transaction" << std::endl;
            list->remove();
        }
        else if (input == 67) {//display all list contents
            std::cout << "Displaying Contents" << std::endl;
            list->display();
        }
        else if (input == 85) {//Display list contents with upper bound
            std::cout << "Displaying Upper Contents" << std::endl;
            list->displayUpper();
        }
        else if (input == 83) {//Save list
            std::ofstream outFile("output.txt"); //overwrite with empty file so class functions can simply append to file
            outFile << "";
            outFile.close();
            list->saveList();
        }
        else if (input == 76) {//load data from file
            std::cout << "Please Enter File Name: " << std::endl;
            std::string fileInput;
            std::cin >> fileInput;
            std::ifstream textFile(fileInput);
            std::string entry;
            std::string one;
            std::string two;
            std::string three;
            std::string four;
            std::string five;
            std::string six;
            std::string seven;
            std::string eight;
            std::string nine;
            std::string ten;
            while (textFile) {

            getline(textFile, entry);
            std::istringstream stringStream(entry);


                stringStream >> one >> two >> three >> four >> five >> six >> seven >> eight >> nine >> ten;//read line and assign to temp variables, yet again should all be switch statements but works regardless
                if (one == "DB") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    Debit* newDebit = new Debit(newDate, newTime, stof(six), stoi(seven), eight, nine, ten);
                    list->add(newDebit);
                }
                if (one == "CSP") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    Cashpoint* newCashpoint = new Cashpoint(newDate, newTime, stof(six), stoi(seven), stoi(eight));
                    list->add(newCashpoint);
                }
                if (one == "DD") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    DirectDebit* newDebit = new DirectDebit(newDate, newTime, stof(six), seven);
                    list->add(newDebit);
                }
                if (one == "TR") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    Transfer* newTransfer = new Transfer(newDate, newTime, stof(six), stoi(seven), eight);
                    list->add(newTransfer);
                }
                if (one == "CDP") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    CreditPoint* newCreditpoint = new CreditPoint(newDate, newTime, stof(six), seven);
                    list->add(newCreditpoint);
                }
                if (one == "INT") {//assign variables and add to list based on transaction type
                    dateStruct newDate;
                    newDate.day = stoi(two);
                    newDate.month = monthConv(three);
                    newDate.year = stoi(four);
                    timeStruct newTime;
                    newTime.hour = stoi(five.substr(0, 2));
                    newTime.minute = stoi(five.substr(3, 2));
                    newTime.second = stoi(five.substr(6, 2));

                    Interest* newInterest = new Interest(newDate, newTime, stof(six), seven);
                    list->add(newInterest);
                }
            }
        }
        else if (input == 78) {//measure time taken to search list
            dateStruct searchDate = constructDate();
            clock_t start, finish;
            start = clock();
            list->linearSearch(searchDate);
            finish = clock();
            double duration = (double)(finish - start) / CLOCKS_PER_SEC;
            std::cout << "Time Taken To Search List: " << duration << " seconds" << std::endl;
        }
        else if (input == 84) {//measure time taken to sort list
            clock_t start, finish;

            start = clock();
            list->sortList();
            finish = clock();

            double duration = (double)(finish - start) / CLOCKS_PER_SEC;
            std::cout << "Time Taken To Sort List: " << duration << " seconds" << std::endl;

        }
        else {
            std::cout << "Please enter any value to return to the menu" << std::endl;
            std::cin >> input;
        }

    }

    

}

char charCheck(char input) //used for translating lowercase input to upper case for menu, simply replaces lower case ascii with upper case equivalent
{
    switch (input) {
    case 113:       //Q
        input = 81;
        break;
    case 105:       //I
        input = 73;
        break;
    case 100:       //D
        input = 68;
        break;
    case 99:        //C
        input = 67;
        break;
    case 117:       //U
        input = 85;
        break;
    case 115:       //S
        input = 83;
        break;
    case 108:       //L
        input = 76;
        break;
    case 110:       //N
        input = 78;
        break;
    case 116:       //T
        input = 84;
        break;
    }
    return input;
}

dateStruct constructDate() //create custom date object - reinventing wheel
{
    std::cout << "Please Enter The Year Of The Transaction: " << std::endl;

    std::string year;
    std::cin >> year;

    for (int i = 0; i < year.length(); i++) { //DATE INPUTS ARE STRING, SO CHECK TO SEE IF NON NUMERIC CHARACTERS EXIST BEFORE CONVERTING TO INTEGER
        if (!isdigit(year[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> year;
            i = 0;
        }
    }

    std::cout << "Please Enter The Month Of The Transaction As A Integer: " << std::endl;
    std::string month;
    std::cin >> month;

    for (int i = 0; i < month.length(); i++) {
        if (!isdigit(month[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> month;
            i = 0;
        }
    }

    std::cout << "Please Enter The Day Of The Transaction As A Integer: " << std::endl;
    std::string day;
    std::cin >> day;

    for (int i = 0; i < day.length(); i++) {
        if (!isdigit(day[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> day;
            i = 0;
        }
    }

    dateStruct newDate;
    newDate.year = stoi(year);
    newDate.month = stoi(month);
    newDate.day = stoi(day);

    return newDate;
}

timeStruct constructTime()//create custom time object - reinventing wheel
{
    std::cout << "Please Enter The Hour Of The Transaction: " << std::endl;

    std::string hour;
    std::cin >> hour;

    for (int i = 0; i < hour.length(); i++) { //DATE INPUTS ARE STRING, SO CHECK TO SEE IF NON NUMERIC CHARACTERS EXIST BEFORE CONVERTING TO INTEGER
        if (!isdigit(hour[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> hour;
            i = 0;
        }
    }

    std::cout << "Please Enter The Minute Of The Transaction As A Integer: " << std::endl;
    std::string minute;
    std::cin >> minute;

    for (int i = 0; i < minute.length(); i++) {
        if (!isdigit(minute[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> minute;
            i = 0;
        }
    }

    std::cout << "Please Enter The Minute Of The Transaction As A Integer: " << std::endl;
    std::string second;
    std::cin >> second;

    for (int i = 0; i < second.length(); i++) {
        if (!isdigit(second[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> second;
            i = 0;
        }
    }

    timeStruct newTime;
    newTime.hour = stoi(hour);
    newTime.minute = stoi(minute);
    newTime.second = stoi(second);

    return newTime;
}

int enterInt(std::string input) //check if value entered is integer
{
    for (int i = 0; i < input.length(); i++) { //DATE INPUTS ARE STRING, SO CHECK TO SEE IF NON NUMERIC CHARACTERS EXIST BEFORE CONVERTING TO INTEGER
        if (!isdigit(input[i])) {
            std::cout << "Value entered is not numeric, please try again: " << std::endl;
            std::cin >> input;
            i = 0;
        }
    }
    return stoi(input);
}

float enterFloat(std::string input)//check if value entered is float
{
    bool loopCheck = true;
    
    while (loopCheck) {
        bool floatCheck;
        try {
            stof(input);
            floatCheck = true;
        }
        catch (const std::invalid_argument& e) {
            floatCheck = false;
        }

        if (!floatCheck) {
            std::cout << "Please Enter A Valid Float: " << std::endl;
            std::cin >> input;
        }
        else {
            loopCheck = false;
        }
    }
    return stof(input);
}

int monthConv(std::string input)//convert text month to integer - yet again, should be switch statement but also functions regardless
{
    if (input == "Jan") {
        return 1;
    }
    else if (input == "Feb") {
        return 2;
    }
    else if (input == "Mar") {
        return 3;
    }
    else if (input == "Apr") {
        return 4;
    }
    else if (input == "May") {
        return 5;
    }
    else if (input == "Jun") {
        return 6;
    }
    else if (input == "Jul") {
        return 7;
    }
    else if (input == "Aug") {
        return 8;
    }
    else if (input == "Sep") {
        return 9;
    }
    else if (input == "Oct") {
        return 10;
    }
    else if (input == "Nov") {
        return 11;
    }
    else {
        return 12;
    }
}

