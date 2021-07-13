//I am aware of the University’s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University’s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#include "Transfer.h"
#include <string>
#include <iostream>
#include <fstream>

Transfer::Transfer(dateStruct date, timeStruct time, float Value, int acc, std::string sort)//Constructor for Transfer Transaction object
{
	transactionDate = date;
	transactionTime = time;
	value = Value;
	accNumber = acc;
	sortCode = sort;
}

void Transfer::display() {//Display Transfer Transaction object information
	std::cout << "Date: " << transactionDate.day << "." << transactionDate.month << "." << transactionDate.year << std::endl;
	std::cout << "Time: " << transactionTime.hour << ":" << transactionTime.minute << ":" << transactionTime.second << std::endl;
	std::cout << "Value: " << value << std::endl;
	std::cout << "Account Number: " << accNumber << std::endl;
	std::cout << "Sort Code: " << sortCode << std::endl;
}

std::string Transfer::getID()//ID Getter
{
	return std::to_string(accNumber);
}

std::string Transfer::getType()//Type Getter
{
	return "transfer";
}

float Transfer::getValue()//Value Getter
{
	return value;
}

void Transfer::saveTransaction()//Append transfer transaction information to text file
{
    std::ofstream outFile("output.txt", std::ofstream::app);
    std::string month;
    switch (transactionDate.month) {
    case 1:
    {
        month = "Jan";
        break;
    }
    case 2:
    {
        month = "Feb";
        break;
    }
    case 3:
    {
        month = "Mar";
        break;
    }
    case 4:
    {
        month = "Apr";
        break;
    }
    case 5:
    {
        month = "May";
        break;
    }
    case 6:
    {
        month = "Jun";
        break;
    }
    case 7:
    {
        month = "Jul";
        break;
    }
    case 8:
    {
        month = "Aug";
        break;
    }
    case 9:
    {
        month = "Sep";
        break;
    }
    case 10:
    {
        month = "Oct";
        break;
    }
    case 11:
    {
        month = "Nov";
        break;
    }
    case 12:
    {
        month = "Dec";
        break;
    }
    }
    /*if (transactionDate.month == 1) {  /////////////////switch statement faster/////////////////
        month = "Jan";
    }
    else if (transactionDate.month == 2) {
        month = "Feb";
    }
    else if (transactionDate.month == 3) {
        month = "Mar";
    }
    else if (transactionDate.month == 4) {
        month = "Apr";
    }
    else if (transactionDate.month == 5) {
        month = "May";
    }
    else if (transactionDate.month == 6) {
        month = "Jun";
    }
    else if (transactionDate.month == 7) {
        month = "Jul";
    }
    else if (transactionDate.month == 8) {
        month = "Aug";
    }
    else if (transactionDate.month == 9) {
        month = "Sep";
    }
    else if (transactionDate.month == 10) {
        month = "Oct";
    }
    else if (transactionDate.month == 11) {
        month = "Nov";
    }
    else if (transactionDate.month == 12) {
        month = "Dec";
    }*/

    std::string outputString; //construct string to append to file

    outputString = "TR ";

    if (transactionDate.day < 10) {//add leading zero to sub 10
        outputString += ("0" + std::to_string(transactionDate.day));
    }
    else {
        outputString += std::to_string(transactionDate.day);
    }
    outputString += " ";
    outputString += month;
    outputString += " ";
    outputString += std::to_string(transactionDate.year);
    outputString += " ";

    if (transactionTime.hour < 10) { //add leading zero to sub 10
        outputString += ("0" + std::to_string(transactionTime.hour));
    }
    else {
        outputString += std::to_string(transactionTime.hour);
    }
    outputString += ":";
    if (transactionTime.minute < 10) {//add leading zero to sub 10
        outputString += ("0" + std::to_string(transactionTime.minute));
    }
    else {
        outputString += std::to_string(transactionTime.minute);
    }
    outputString += ":";
    if (transactionTime.second < 10) {//add leading zero to sub 10
        outputString += ("0" + std::to_string(transactionTime.second));
    }
    else {
        outputString += std::to_string(transactionTime.second);
    }
    outputString += " ";
    outputString += std::to_string(value);
    outputString += " ";
    outputString += sortCode;

    outFile << outputString << std::endl;
}


