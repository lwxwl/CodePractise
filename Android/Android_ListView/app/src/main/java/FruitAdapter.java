import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.example.administrator.listviewtest.R;

import java.util.List;

import static android.R.attr.id;


/**
 * Created by Administrator on 2016/11/8.
 */

public class FruitAdapter extends ArrayAdapter<Fruit> {
    private int resourceId;
    public FruitAdapter(Context context,  int textViewResourceId, List<Fruit> objects) {
        super(context, textViewResourceId, objects);
        resourceId=textViewResourceId;
        }
    @Override
    public View getView(int position, View convertView, ViewGroup parent){
        Fruit fruit=getItem(position);
        View view= LayoutInflater.from(getContext()).inflate(resourceId,null);
        TextView fruitname=(TextView) view.findViewById(R.id.fruit_name);
        fruitname.setText(fruit.getName());
        return view;
    }
}
