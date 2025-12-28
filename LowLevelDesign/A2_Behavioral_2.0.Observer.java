package LowLevelDesign;

import java.util.ArrayList;
import java.util.List;

/*
 * The Observer Pattern is one of the most widely used behavioral design
 * patterns. It defines a one-to-many dependency between objects so that when
 * one object (the Subject) changes state, all its dependents (Observers) are
 * notified and updated automatically.
 * 
 * It is essentially the foundation of Event-Driven Programming.
 * 
 * 1. The Core Concept: Publisher & Subscriber
 *      Think of a YouTube Channel:
 *          The Channel is the Subject.
 *          The Subscribers are the Observers.
 *          When the channel uploads a video, it doesn't call every subscriber individually; it sends a "broadcast" notification to everyone on the list.
 * 
 * 2. Key Participants
 *      Subject (Publisher): Maintains a list of observers and provides methods to attach, detach, and notify them.
 * 
 *      Observer (Subscriber): Defines an interface with an update() method to be called when the Subject changes.
 * 
 *      Concrete Subject: The actual object being watched (e.g., a News Agency or a Stock Ticker).
 * 
 *      Concrete Observer: The objects reacting to the change (e.g., a News App or a Trader).
 */

// 3. Java Implementation Example: News Agency

// Step 1: The Observer Interface
interface Observer {
    void update(String news);
}

// Step 2: The Subject Interface
interface Subject {
    void subscribe(Observer o);

    void unsubscribe(Observer o);

    void notifyObservers();
}

// Step 3: Concrete Implementation
class NewsAgency implements Subject {
    private List<Observer> observers = new ArrayList<>();
    private String news;

    public void setNews(String news) {
        this.news = news;
        notifyObservers(); // Automatically trigger update
    }

    @Override
    public void subscribe(Observer o) {
        observers.add(o);
    }

    @Override
    public void unsubscribe(Observer o) {
        observers.remove(o);
    }

    @Override
    public void notifyObservers() {
        for (Observer o : observers) {
            o.update(news);
        }
    }
}

class NewsChannel implements Observer {
    private String name;

    public NewsChannel(String name) {
        this.name = name;
    }

    @Override
    public void update(String news) {
        System.out.println(name + " received news: " + news);
    }
}

/*
 * import java.util.ArrayList;
 * import java.util.List;
 * 
 * interface Ovserver {
 * void update(double temp);
 * }
 * 
 * interface Subject {
 * void attachOvserver(Ovserver o);
 * 
 * void detachOvserver(Ovserver o);
 * 
 * void notifyAllOvservers();
 * }
 * 
 * class WeatherStation implements Subject {
 * private double temprature;
 * private List<Ovserver> ovservers;
 * 
 * public WeatherStation() {
 * this.ovservers = new ArrayList<>();
 * }
 * 
 * @Override
 * public void attachOvserver(Ovserver o) {
 * ovservers.add(o);
 * }
 * 
 * @Override
 * public void detachOvserver(Ovserver o) {
 * ovservers.remove(o);
 * }
 * 
 * @Override
 * public void notifyAllOvservers() {
 * for (Ovserver o : this.ovservers) {
 * o.update(this.temprature);
 * }
 * }
 * 
 * public void setTemprature(double temprature) {
 * this.temprature = temprature;
 * this.notifyAllOvservers();
 * }
 * }
 * 
 * class MobileOvserver implements Ovserver {
 * public void update(double temp) {
 * System.out.println("Mobile: Temp: " + temp);
 * }
 * }
 * 
 * class TabletOvserver implements Ovserver {
 * public void update(double temp) {
 * System.out.println("Tab: Temp: " + temp);
 * }
 * }
 * 
 * class testOvservers {
 * static void main() {
 * WeatherStation weatherStation = new WeatherStation();
 * Ovserver mobileOvserver = new MobileOvserver();
 * Ovserver weatherOvserver = new TabletOvserver();
 * weatherStation.attachOvserver(mobileOvserver);
 * weatherStation.attachOvserver(weatherOvserver);
 * 
 * weatherStation.setTemprature(12.42);
 * weatherStation.detachOvserver(weatherOvserver);
 * weatherStation.setTemprature(32.4);
 * }
 * }
 */