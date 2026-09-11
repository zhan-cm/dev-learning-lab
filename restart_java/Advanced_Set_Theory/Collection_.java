package Advanced_Set_Theory;

import java.util.ArrayList;
import java.util.Collection;
import java.util.Iterator;
import java.util.function.Consumer;

public class Collection_ {
    /*
        Collection集合特点
            List系列集合：添加的元素时有序、可重复、有索引
                ArrayList、LinkedList：有序、可重复、有索引
            Set系列集合：添加的元素时无序的、不重复、无索引
                HashSet：无序、不重复、无索引
                LinkedHashSet：有序、不重复、无索引
                TreeSet：按照大小默认升序排序、不重复、无索引
     */
    /*
        常见方法：
            boolean add(E e)
            void clear()
            boolean isEmpty()
            int size()
            boolean contains(Object obj)判断集合中是否包含某个元素
            boolean remove(E e)
            Object[] toArray()
     */
    public static void main(String[] args) {
        Collection<String> c = new ArrayList<>();
        c.add("zhangsan");
        c.add("lisi");
        c.add("wangwu");
        c.add("zhaoliu");
        System.out.println("-------------------");
        System.out.println("迭代器遍历");
        Iterator<String> it = c.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
        System.out.println("-------------------");
        System.out.println("增强for循环");
        for(String s: c){
            System.out.println(s);
        }
        System.out.println("-------------------");
        System.out.println("Lambda表达式遍历集合");
        c.forEach(new Consumer<String>() {
            @Override
            public void accept(String s) {
                System.out.println(s);
            }
        });
        System.out.println("-------------------");
        System.out.println("Lambda简化");
        c.forEach( s -> System.out.println(s) );
    }

}
