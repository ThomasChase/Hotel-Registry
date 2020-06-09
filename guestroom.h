#ifndef GUESTROOM_H
#define GUESTROOM_H

#include "hotelroom.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;



class GuestRoom: public HotelRoom
{
    private:
        int capacity = 4;   //max number of occupants
        int status = 0; //number of guest currently in room, default is 0
        int days; //Number of days guest stayed in the room
    public:
        GuestRoom():HotelRoom(){    //default constructor
            this->capacity = capacity;
            this->status = status;
            days = 1;
        }
        GuestRoom(int status, int days,int roomNumber, double dailyRate):HotelRoom(){    //constructor with parameters
            try{    //Exeption handler to ensure status of occupants does not exceed allowed capacity
                if(status > capacity){
                    throw status;
                }
                this->status = status;
            }
            catch (int ex){
                cout << "Amount of guests exceeds rooms capacity." << endl; //Lets the user know they have exceed the capacity limit
            }
            this->days = days;
            this->capacity = capacity;
            setRate(dailyRate);
            setRoom(roomNumber);
        }
        void setCapacity(int capacity){ //sets new capacity limit
            this->capacity = capacity;
        }
        void setStatus(int status){
            try{    //checks if status exceeds capacity
                if(status > capacity){
                    throw status;
                }
                this->status = status;
            }
            catch (int ex){
                cout << "Amount of guests exceeds current rooms capacity." << endl; //Lets the user know they are over capacity
            }
        }
        void setDays(int days){ //Sets new amount of days guest is staying
            this-> days = days;
        }
        int getCapacity()const{ //returns current capacity
            return capacity;
        }
        int getStatus()const{   //returns current number of guests in room
            return status;
        }
        int getDays()const{ //returns number of days guest is staying
            return days;
        }
        double calculateBill()const{    //Calculates the guests bill based on room rate and number if days stayed
            double bill;
            bill = days*getRate();
            return bill;
        }
        string toString()const{
            return "\nRoom: " + std::to_string(getRoom()) + "\nGuests: " + std::to_string(status) + "\nDaily rate:$" + std::to_string(getRate()) + "\nDays stayed: " + std::to_string(days) + "\nFinal bill: $" + std::to_string(calculateBill());
        }


};

#endif // GUESTROOM_H
