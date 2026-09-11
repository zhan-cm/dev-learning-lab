package Advanced_Set_Theory;

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

public class Collections_ {
    /*
        Collections:用来操作集合的工具类,只支持List集合

        常用静态方法
        public static <T> boolean addAll(Collection<? super T> c,T... elements)
        给集合批量添加元素

        public static void shuffle(List<?> list)
        打乱List集合中元素顺序

        public static <T> void sort(List<T> list)
        对List集合中的元素进行升序排序

        public static <T> void sort(List<T> list,Comparator<? super T> c)
        对List集合中元素，按照比较器对象指定的规则进行排序
     */
    public static void main(String[] args) {
        List<String> list = new ArrayList<>();

        Collections.addAll(list,"scacca","casc","safav","cwvw","ughbj");
        System.out.println(list);
        System.out.println();

        Collections.shuffle(list);
        System.out.println(list);
        System.out.println();

        Collections.sort(list);
        System.out.println(list);
        System.out.println();

        Collections.sort(list, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return 0;
            }
        });
    }
}
