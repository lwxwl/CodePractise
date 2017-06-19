import java.util.ArrayList;
import java.util.List;


/**
 * Created by lwxwl on 2017/5/22.
 */
public class MySubject implements Subject {

    private List<Observer> observers;
    private boolean isChanged;
    private String message;
    // 对象锁，用于同步更新观察者列表
    private final Object mutex = new Object();

    public MySubject() {
        observers = new ArrayList<Observer>();
        isChanged = false;
    }

    @Override
    public void register(Observer observer) {
        if (observer == null) {
            throw new NullPointerException();
        }
        //保证不重复
        if (!observers.contains(observer)) {
            observers.add(observer);
        }

    }

    @Override
    public void remove(Observer observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers() {
        List<Observer> tempObservers= null;
        synchronized (mutex) {
            if (!isChanged) {
                return;
            }
            tempObservers = new ArrayList<>(this.observers);
            this.isChanged = false;
        }
        for(Observer obj : tempObservers) {
            obj.update();
        }
    }

    @Override
    public String getMessage() {
        return this.message;
    }
}
