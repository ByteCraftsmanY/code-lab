package LowLevelDesign;

import java.util.ArrayList;
import java.util.List;

interface ObservableInterface {
    void add(ObserverInterface observer);

    void remove(ObserverInterface observer);

    void notifyObservers();

    String getData();

    void setData(String data);
}

// Observable is a ObservableInterface

class Observable implements ObservableInterface {

    private List<ObserverInterface> observers;
    private String data;

    public Observable() {
        this.observers = new ArrayList<ObserverInterface>();
        this.data = "";
    }

    @Override
    public void add(ObserverInterface observer) {
        this.observers.remove(observer);
    }

    @Override
    public void remove(ObserverInterface observer) {
        this.observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        for (ObserverInterface observer : this.observers) {
            observer.update();
        }
    }

    @Override
    public String getData() {
        return this.data;
    }

    @Override
    public void setData(String data) {
        this.data = data;
        this.notifyObservers();
    }
}

interface ObserverInterface {
    void update();
}

// Observer has a Observable
class Observer implements ObserverInterface {
    private Observable observable;

    // constructor injection
    public Observer(Observable observable) {
        this.observable = observable;
    }

    @Override
    public void update() {
        System.out.println("Observer updated");
        System.out.println("Data is " + this.observable.getData());
    }
}

public class A3_ObserberDesignPattern {

    public static void main(String[] args) {
        Observable observable = new Observable();
        Observer observer = new Observer(observable);
        observable.add(observer);
        observable.setData("Hello");
    }

}

/*
 * Conclusion:
 * 1. Observable and Observer are decoupled.
 * 2. Observable and Observer are loosely coupled.
 * 3. Observable and Observer are easy to maintain.
 * 4. Observable and Observer are easy to test.
 */

/*
 * Bonus:
 * this question is asked in wallmart interview.
 * there a product page of amazon website
 * you need to implement the notify button
 */

interface StockOvservable {
    void add(StockObserver observer);

    void remove(StockObserver observer);

    void notifySubscribers();

    int getStock();

    void setStock(int quantity);
}

class IphoneOvservable implements StockOvservable {
    private List<StockObserver> observers;

    @Override
    public void add(StockObserver observer);

    @Override
    public void remove(StockObserver observer);

    @Override
    public void notifySubscribers() {
        for (StockObserver observer : this.observers) {
            observer.update(this.getStockName(), this.getStock());
        }
    }

    @Override
    public int getStock(){
        return this.stock;
    }

    @Override
    public void setStock(int quantity){
        this.stock = quantity;
        this.notifySubscribers();
    }
}

interface StockObserver {
    void update(String stockName, double price);
}

class StockObservable implements ObservableInterface {
    private List<StockObserver> observers;
    private String stockName;
    private double price;
}