#ifndef MEETINGROOM_H
#define MEETINGROOM_H

#include "hotelroom.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


class MeetingRoom: public HotelRoom
{
    private:
        int seats;  //how many guests the room can hold
        int status = 0; //0 if room is availible and 1 if room is booked
        const double flatFee = 500.00;
        const double seatFee = 10.00;
    public:
        MeetingRoom(int seats, int roomNumber){ //constructor with parameters
            this->seats  = seats;
            this->status = 1;
            setRoom(roomNumber);
        }
        void setSeats(int seats){   //set new amount of seats
            try{    //exeption handler to ensure seats is greater then 0
                if(seats < 0){
                    throw seats;
                }
                this->seats = seats;
            }
            catch (int ex){ //lets the user know they entered a negative number
                cout << "Negative Parameter entered!" << endl;
            }
        }
        void setStatus(int status){ //sets status of room
            try{    //checks to make sure input is in bounds (0-1)
                if(status < 0 || status > 1){
                    throw status;
                }
                this->status = status;
            }
            catch (int ex){ //Lets user know they entered and out of bounds parameter
                cout << "Out of bound paramater entered!" << endl;
            }
        }
        int getSeats()const{    //return rooms amount of seats
            return seats;
        }
        int getStatus()const{   //return current booking status of meeting room
            return status;
        }
        double calculateBill()const{    //calculates the bill based on seats and flat fee rate
            double bill = 0;
            bill = (seats*seatFee) + flatFee;
            return bill;
        }
        string toString()const{
            return "\nRoom " + std::to_string(getRoom()) + " with " + std::to_string(seats) + " seats. \nFlat rate per seat:$" + std::to_string(seatFee) + "\nFlat rate for room:$" + std::to_string(flatFee) + "\nFinal bill is:$" + std::to_string(calculateBill());
        }
};

#endif // MEETINGROOM_H
