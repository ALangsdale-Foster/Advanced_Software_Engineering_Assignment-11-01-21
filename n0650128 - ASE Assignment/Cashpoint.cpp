//I am aware of the University?s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University?s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#include "Cashpoint.h"
#include <iostream>
#include <fstream>

Cashpoint::Cashpoint(dateStruct date, timeStruct time, float Value, int id, int card)
{
	transactionDate = date;
	transactionTime = time;
	value = Value;
	locationID = id;
	cardUsed = card;
}

void Cashpoint::display() {
	std::cout << "Date: " << transactionDate.day << "." << transactionDate.month << "." << transactionDate.year << std::endl;
	std::cout << "Time: " << transactionTime.hour << ":" << transactionTime.minute << ":" << transactionTime.second << std::endl;
	std::cout << "Value: " << value << std::endl;
	std::cout << "Location ID: " << locationID << std::endl;
	std::cout << "Card Used: " << cardUsed << std::endl;
}

std::string Cashpoint::getID()
{
	std::string returnval;
	returnval = std::to_string(cardUsed);
	return returnval;
}

float Cashpoint::getValue()
{
	return 0.0f;
}

std::string Cashpoint::getType()
{
	return "cashpoint";
}

void Cashpoint::saveTransaction()
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

    std::string outputString;//construct string to append to file

    outputString = "CSP ";

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
    outputString += std::to_string(locationID);
    outputString += " ";
    outputString += std::to_string(cardUsed);

    outFile << outputString << std::endl;

}

