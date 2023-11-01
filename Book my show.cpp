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