/**
 * Created by lwxwl on 2017/5/22.
 */
public class ConcreteObserver implements Observer {

    private Subject subject;

    @Override
    public void setSubject() {
        this.subject = subject;
    }
    public void subscribe(String subjectName) {
        SubjectManagement.getInstance().getSubject(subjectName).register(this);
    }
    public void cancelSubscribe(String subjectName) {
        SubjectManagement.getInstance().getSubject(subjectName).remove(this);
    }

    @Override
    public void update() {
        String message = subject.getMessage();
        System.out.println("From Subject " + subject.getClass().getName() + " message: " + message);

    }
}
