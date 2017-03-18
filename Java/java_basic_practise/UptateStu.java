import java.util.*;

/**
 * Created by Administrator on 2016/10/22.
 */
public class UptateStu {
    public static void main(String[] args){
        Map<String,String> map=new HashMap<>();
        map.put("01","同学1");
        map.put("02","同学2");
        Set<String> set=map.keySet();
        Iterator<String> it=set.iterator();
        System.out.println("key集合中的元素：");
        while(it.hasNext()){
            System.out.println(it.next());
        }
        Collection<String> coll=map.values();
        it=coll.iterator();
        System.out.println("values集合中的元素：");
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}
