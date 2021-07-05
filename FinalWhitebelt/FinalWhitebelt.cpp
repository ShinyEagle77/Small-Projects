#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <exception>
#include <set>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

class Date {
public:
	Date (const int& new_year, const int& new_month, const int& new_day)
	{
		if (new_month < 1 || new_month > 12)
		{
            throw out_of_range("Month value is invalid: " + to_string(new_month));
		}
        else if (new_day < 1 || new_day > 31)
        {
            throw out_of_range("Day value is invalid: " + to_string(new_day));
        }
        year = abs(new_year);
        month = new_month;
        day = new_day;
	}
	
    int GetYear() const
    {
        return year;
    }
    int GetMonth() const
    {
        return month;
    }
    int GetDay() const
    {
        return day;
    }

private:
    int year, month, day;
};

ostream& operator << (ostream& stream, const Date& date)
{
    stream << setfill('0') << setw(4) << date.GetYear() << '-'
        << setfill('0') << setw(2) << date.GetMonth() << '-'
        << setfill('0') << setw(2) << date.GetDay();
    return stream;
}

bool operator<(const Date& lhs, const Date& rhs)
{
    return (vector<int>{lhs.GetMonth(), lhs.GetYear(), lhs.GetDay()} < 
			vector <int>{rhs.GetMonth(), rhs.GetYear(), rhs.GetDay()});
}

class Database {
public:
    void AddEvent(const Date& date, const string& event)
    {
        events[date].insert(event);
    }
    bool DeleteEvent(const Date& date, const string& event)
    {
	    if (events.count(date) > 0 && events[date].count(event) > 0)
	    {
            events[date].erase(event);
	    	return true;
	    }
        else
        {
            return false;
        	
        }
    }
    int DeleteDate(const Date& date)
    {
    	if (events.count(date) == 0)
    	{
            return 0;
    	}
        else
        {
            const int size = events[date].size();
            events.erase(date);
            return size;
        }
    }

    set<string> Find(const Date& date) const
    {
	    if (events.count(date) > 0)
	    {
            return events.at(date);
	    }
        else
        {
            return {};
        }
    }

    void Print() const 
    {
        for (const auto& item : events) 
        {
            for (const string& event : item.second) 
            {
                cout << item.first << " " << event << endl;
            }
        }
    }
private:
    map<Date, set<string>> events;
};

void EnsureNextCharAndSkip(stringstream& s, const string& date) {
    if (s.peek() != '-') {
        throw logic_error("Wrong date format: " + date);
    }
    s.ignore(1);
}

Date ParseDate(const string& date) {
    stringstream date_stream(date);
    int year, month, day;
    date_stream >> year;
    EnsureNextCharAndSkip(date_stream, date);
    date_stream >> month;
    EnsureNextCharAndSkip(date_stream, date);
    date_stream >> day;
    if (!date_stream.eof() || !date_stream) {
        throw logic_error("Wrong date format: " + date);
    }
    return {year, month, day};
}

int main() {
    try
    {

        Database db;

        string command;
        while (getline(cin, command)) {
            stringstream ss(command);

            string operation;
            ss >> operation;

            if (operation == "Add")
            {
                string _date, event;
                ss >> _date >> event;
                const Date date = ParseDate(_date);
                db.AddEvent(date, event);
            }
            else if (operation == "Del")
            {
                string _date;
                ss >> _date;
                string event;
                if (!ss.eof())
                {
                    ss >> event;
                }

                const Date date = ParseDate(_date);
                if (event.empty())
                {
                    const int count = db.DeleteDate(date);
                    cout << "Deleted " << count << " events" << endl;
                }
                else
                {
                    if (db.DeleteEvent(date, event))
                    {
                        cout << "Deleted successfully" << endl;
                    }
                    else
                    {
                        cout << "Event not found" << endl;
                    }
                }
            }
            else if (operation == "Find")
            {
                string _date;
                ss >> _date;

                const Date date = ParseDate(_date);
                for (const string& event : db.Find(date))
                {
                    cout << event << endl;
                }
            }
            else if (operation == "Print")
            {
                db.Print();
            }
            else if (!operation.empty())
            {
                throw logic_error("Unknown command: " + command);
            }
        }
    } catch (const exception& ex)
	{
        cout << ex.what() << endl;
	}

    return 0;
}