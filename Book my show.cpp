#include<bits/stdc++.h>
using namespace std;

enum class SeatType
{
    DELUXE,
    VIP,
    ECONOMY,
    OTHER
};

enum class SeatStatus
{
    BOOKED,
    AVAILABLE,
    RESERVED,
    NOT_AVAILABLE
};

class Address
{
public:
    int pinCode;
    string street;
    string city;
    string state;
    string country;
};

class Seat
{
public:
    int seatId;
    SeatType seatType;
    SeatStatus seatStatus;
    double price;
};
class Show;//forward declaration

class Movie
{
public:
    string movieName;
    int movieId;
    int durationInMinutes;
    string language;
    time_t releaseDate;//epoch time
    map<string,vector<Show>>cityShowMap;//city to shows mapping
};

enum class Genre
{
    SCI_FI,
    DRAMA,
    Romantic,
    HORROR
};

class CinemaHall;
class Audi
{
public:
    int audiId;
    string audiName;
    int totalSeats;
    vector<Show>shows;
};

class CinemaHall
{
public:
    int cinemaHallId;
    string cinemaHallName;
    Address address;
    vector<Audi>audiList;
    map<time_t,Movie>getMovies(const vector<time_t>& dateList);//return movies in the cinema hall for the given dates
    map<time_t,Show>getShows(const vector<time_t>& dateList);//return shows in the cinema hall for the given dates
};

class User
{
public:
    class Search
    {
        vector<Movie>SearchMoviesByNames(const string& name);//return movies matching the name
        vector<Movie>SearchMoviesByGenre(const Genre& genre);//sci-fi, drama, romantic, horror
        vector<Movie>SearchMoviesByLanguage(const string& language);//english, hindi, telugu, tamil
        vector<Movie>SearchMoviesByDate(const time_t& date);//return movies released on the given date
    };
    int userId;//unique
    Search searchObj;//search object
};

class Account
{
public:
    string userName;
    string password;
};

class SystemMember : public User
{
public:
    Account account;
    string name;
    string mail;
    Address address;
};

class Booking;

class Payment
{
public:
    double amount;
    time_t paymentDate;
    int transactionId;

    enum class PaymentStatus
    {
        UNPAID,
        PENDING,
        COMPLETED,
        DECLINED,
        CANCELLED,
        REFUNDED
    };
    PaymentStatus paymentStatus;
};

class Show
{
public:
    int showId;
    Movie* movie;
    time_t startTime;
    time_t endTime;
    CinemaHall* cinemaPlayedAt;
    vector<Seat>seats;
};

class Booking
{
public:
    string BookingId;
    time_t bookingDate;
    SystemMember member;
    Audi audi;
    Show show;

    enum class BookingStatus
    {
        REQUESTED,
        PENDING,
        CONFIRMED,
        CANCELLED
    }BookingStatus;
    double totalAmount;
    vector<Seat>seats;
    Payment paymentObj;

    bool makePayment(Payment payment);//make payment for the booking
};

class Member : public SystemMember
{
public:
    Booking makeBooking(Booking booking);//make booking for the show
    vector<Booking>getBooking();//get all the booking of the member
};

class Admin : public SystemMember
{
public:
    bool addMovie(Movie movie);//add movie to the system
    bool addShow(Show show);//add show to the system
};

class TicketCounter
{
public:
    Booking createBooking(Booking booking);//create booking for the show
};

class Guest
{
public:
    vector<Movie>getMovies();//get all the movies in the system
    vector<CinemaHall>getCinemaHalls();//get all the cinema halls in the system
    vector<Show>getShows();//get all the shows in the system
};

class BookMyShow
{
public:
    vector<Member>members;
    vector<Admin>admins;
    vector<CinemaHall>cinemaHalls;
    vector<Guest>guests;
    vector<TicketCounter>ticketCounters;
};

int main()
{
    BookMyShow bms;
    cout<<"\t\t Welcome to Book My Show\n\n";
    cout<<"Enter the details of the movie\n\n\n";
    Movie movie;
    cout<<"Enter the movie name: ";
    cin>>movie.movieName;
    cout<<"Enter the movie id: ";
    cin>>movie.movieId;
    cout<<"Enter the duration of the movie in minutes: ";
    cin>>movie.durationInMinutes;
    cout<<"Enter the language of the movie: ";
    cin>>movie.language;
    cout<<"Enter the release date of the movie: ";
    cin>>movie.releaseDate;
    cout<<"Enter the city in which the movie is being played: ";
    string city;
    cin>>city;
    cout<<"Enter the cinema hall name: ";
    string cinemaHallName;
    cin>>cinemaHallName;
    cout<<"Enter the cinema hall id: ";
    int cinemaHallId;
    cin>>cinemaHallId;
    cout<<"Enter the address of the cinema hall\n\n\n";
    Address address;
    cout<<"Enter the pin code: ";
    cin>>address.pinCode;
    cout<<"Enter the street: ";
    cin>>address.street;
    cout<<"Enter the city: ";
    cin>>address.city;
    cout<<"Enter the state: ";
    cin>>address.state;
    cout<<"Enter the country: ";
    cin>>address.country;
    CinemaHall cinemaHall;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.address=address;
    Audi audi;
    cout<<"Enter the audi id: ";
    cin>>audi.audiId;
    cout<<"Enter the audi name: ";
    cin>>audi.audiName;
    cout<<"Enter the total number of seats in the audi: ";
    cin>>audi.totalSeats;
    cinemaHall.audiList.push_back(audi);
    Show show;
    cout<<"Enter the show id: ";
    cin>>show.showId;
    show.movie=&movie;
    cout<<"Enter the start time of the show: ";
    cin>>show.startTime;
    cout<<"Enter the end time of the show: ";
    cin>>show.endTime;
    show.cinemaPlayedAt=&cinemaHall;
    Seat seat;
    cout<<"Enter the seat id: ";
    cin>>seat.seatId;

    cout<<"\t\t Press 1 for DELUXE \t\t Press 2 for VIP \t\t Press 3 for ECONOMY \t\t Press 4 for OTHER\n\n";

    cout<<"Enter the seat type: ";
    int seatType;
    cin>>seatType;
    if(seatType==1)
    {
        seat.seatType=SeatType::DELUXE;
    }
    else if(seatType==2)
    {
        seat.seatType=SeatType::VIP;
    }
    else if(seatType==3)
    {
        seat.seatType=SeatType::ECONOMY;
    }
    else
    {
        seat.seatType=SeatType::OTHER;
    }
    
    cout<<"\t\t Press 1 for BOOKED \t\t Press 2 for AVAILABLE \t\t Press 3 for RESERVED \t\t Press 4 for NOT_AVAILABLE\n\n";

    cout<<"Enter the seat status: ";
    int seatStatus;
    cin>>seatStatus;
    if(seatStatus==1)
    {
        seat.seatStatus=SeatStatus::BOOKED;
    }
    else if(seatStatus==2)
    {
        seat.seatStatus=SeatStatus::AVAILABLE;
    }
    else if(seatStatus==3)
    {
        seat.seatStatus=SeatStatus::RESERVED;
    }
    else
    {
        seat.seatStatus=SeatStatus::NOT_AVAILABLE;
    }
    cout<<"Enter the price of the seat: ";
    cin>>seat.price;
    show.seats.push_back(seat);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    cinemaHall.cinemaHallName=cinemaHallName;
    cinemaHall.cinemaHallId=cinemaHallId;
    cinemaHall.address=address;
    cinemaHall.audiList.push_back(audi);
    bms.cinemaHalls.push_back(cinemaHall);
    cout<<"Enter the user id: ";
    int userId;
    cin>>userId;
    cout<<"Enter the user name: ";
    string userName;
    cin>>userName;
    cout<<"Enter the password: ";
    string password;
    cin>>password;
    cout<<"Enter the name of the user: ";
    string name;
    cin>>name;
    cout<<"Enter the mail id of the user: ";
    string mail;
    cin>>mail;
    cout<<"Enter the address of the user\n\n\n";
    Address address1;
    cout<<"Enter the pin code: ";
    cin>>address1.pinCode;
    cout<<"Enter the street: ";
    cin>>address1.street;
    cout<<"Enter the city: ";
    cin>>address1.city;
    cout<<"Enter the state: ";
    cin>>address1.state;
    cout<<"Enter the country: ";
    cin>>address1.country;
    Member member;
    member.userId=userId;
    member.account.userName=userName;
    member.account.password=password;
    member.name=name;
    member.mail=mail;
    member.address=address1;
    bms.members.push_back(member);
    cout<<"Enter the user id: ";
    cin>>userId;
    cout<<"Enter the user name: ";
    cin>>userName;
    cout<<"Enter the password: ";
    cin>>password;
    cout<<"Enter the name of the user: ";
    cin>>name;
    cout<<"Enter the mail id of the user: ";
    cin>>mail;
    cout<<"Enter the address of the user\n\n\n";
    Address address2;
    cout<<"Enter the pin code: ";
    cin>>address2.pinCode;
    cout<<"Enter the street: ";
    cin>>address2.street;
    cout<<"Enter the city: ";
    cin>>address2.city;
    cout<<"Enter the state: ";
    cin>>address2.state;
    cout<<"Enter the country: ";
    cin>>address2.country;
    Admin admin;
    admin.userId=userId;
    admin.account.userName=userName;
    admin.account.password=password;
    admin.name=name;
    admin.mail=mail;
    admin.address=address2;
    bms.admins.push_back(admin);
    cout<<"Enter the user id: ";
    cin>>userId;
    cout<<"Enter the user name: ";
    cin>>userName;
    cout<<"Enter the password: ";
    cin>>password;
    cout<<"Enter the name of the user: ";
    cin>>name;
    cout<<"Enter the mail id of the user: ";
    cin>>mail;
    cout<<"Enter the address of the user\n\n\n";
    Address address3;
    cout<<"Enter the pin code: ";
    cin>>address3.pinCode;
    cout<<"Enter the street: ";
    cin>>address3.street;
    cout<<"Enter the city: ";
    cin>>address3.city;
    cout<<"Enter the state: ";
    cin>>address3.state;
    cout<<"Enter the country: ";
    cin>>address3.country;
    
    cout<<"\n\n\n";
    cout<<"\t\t Details of the movie\n\n";
    cout<<"Movie name: "<<movie.movieName<<endl;
    cout<<"Movie id: "<<movie.movieId<<endl;
    cout<<"Duration of the movie in minutes: "<<movie.durationInMinutes<<endl;
    cout<<"Language of the movie: "<<movie.language<<endl;
    cout<<"Release date of the movie: "<<movie.releaseDate<<endl;
    cout<<"City in which the movie is being played: "<<city<<endl;
    cout<<"Cinema hall name: "<<cinemaHallName<<endl;
    cout<<"Cinema hall id: "<<cinemaHallId<<endl;
    cout<<"Address of the cinema hall\n";
    cout<<"Pin code: "<<address.pinCode<<endl;
    cout<<"Street: "<<address.street<<endl;
    cout<<"City: "<<address.city<<endl;
    cout<<"State: "<<address.state<<endl;
    cout<<"Country: "<<address.country<<endl;
    cout<<"Audi id: "<<audi.audiId<<endl;
    cout<<"Audi name: "<<audi.audiName<<endl;
    cout<<"Total number of seats in the audi: "<<audi.totalSeats<<endl;
    cout<<"Show id: "<<show.showId<<endl;
    cout<<"Start time of the show: "<<show.startTime<<endl;
    cout<<"End time of the show: "<<show.endTime<<endl;
    cout<<"Seat id: "<<seat.seatId<<endl;
    cout<<"Seat type: "<<seatType<<endl;
    cout<<"Seat status: "<<seatStatus<<endl;
    cout<<"Price of the seat: "<<seat.price<<endl;
    cout<<"User id: "<<userId<<endl;
    cout<<"User name: "<<userName<<endl;
    cout<<"Password: "<<password<<endl;

    return 0;
}