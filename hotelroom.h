#ifndef HOTELROOM_H
#define HOTELROOM_H

#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class HotelRoom
{
    private:
        int roomNumber = 0; //room number
        double dailyRate = 0;   //daily rate as $

    public:
        HotelRoom(){    //default constructor
            this->roomNumber = roomNumber;
            this->dailyRate = dailyRate;
        }
        HotelRoom(int roomNumber, double dailyRate){    //constructor with perameters
            try{    //Checking if inputed room number is negative
                if(roomNumber < 0){
                    throw roomNumber;
                }
                this-> roomNumber = roomNumber;
            }
            catch (int ex){
                cout << "Negative Parameter" << endl;
            }
            try{    //chacks if inputed daily rate is negative
                if(dailyRate < 0){
                    throw dailyRate;
                }
                this->dailyRate = dailyRate;
            }
            catch (double ex){
                cout << "Negative Parameter" << endl;
            }
        }
        double getRate() const{    //returns daily rate
            return dailyRate;
        }
        int getRoom() const{ //returns room number
            return roomNumber;
        }
        void setRate(double dailyRate){    //sets new daily rate
            try{
                if(dailyRate < 0){
                    throw dailyRate;    //throws exception is value is negitive
                }
                this->dailyRate = dailyRate;
            }
            catch (double ex){
                cout << "Negative Parameter" << endl;
            }
        }
        void setRoom(int roomNumber){    //sets new room number
            try{
                if(roomNumber < 0){
                    throw roomNumber;
                }
                this->roomNumber = roomNumber;
            }
            catch(int ex){
                cout << "Negative Parameter" << endl;
            }
        }
        virtual string toString() const{
            return "\nRoom number: " + std::to_string(roomNumber) + "\nDaily Rate: $" + std::to_string(dailyRate);
        }
        virtual double calculateBill()const{
            return 0.00;
        }

};

#endif // HOTELROOM_H
