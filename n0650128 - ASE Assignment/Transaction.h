//I am aware of the University’s rules on plagiarism and collusion and I understand that, if I
//am found to have broken these rules, it will be treated as Academic Misconductand dealt
//with accordingly.I understand that if I lend this piece of work to another studentand they
//copy all or part of it, either with or without my knowledge or permission, I shall be guilty of
//collusion.In submitting this work I confirm that I am aware of, and am abiding by, the
//University’s expectations for proof - reading.
//Name: Anthony Langsdale-Foster ID No : n0650128
#pragma once
#include <string>
struct dateStruct {
	int day;
	int month;
	int year;
};

struct timeStruct {
	int hour;
	int minute;
	int second;
};
class Transaction {
	public:
		virtual void display() {};
		virtual float getValue() { return 1.0; };
		virtual std::string getID() { return "default"; };
		virtual std::string getType() { return "default"; };
		virtual void saveTransaction() {};
		int absoluteDate() { //not actually used, approach changed to manual checking of each component as 
			//					this approach only worked partially - it would sort by month and year, but
			//					the days would not be in order.
			//					not removed function as it is already in class diagram
			int year1 = transactionDate.year;
			int month1 = transactionDate.month;
			int day1 = transactionDate.month;
			int absDate1 = (year1 * 10000) + (month1 * 100) + day1;
			return absDate1;
		}
		dateStruct transactionDate;
		timeStruct transactionTime;
		float value;
};