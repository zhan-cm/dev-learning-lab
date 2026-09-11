package Advanced_Set_Theory;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Map_ {
    /*
        Map集合体系的特点：
            注意：Map系列集合特点都是由键决定

        HashMap：无序，不重复，无索引
        LinkedHashMap：有序，不重复，无索引
        TreeMap：按照大小默认升序排序，不重复，无索引
     */
    public static void main(String[] args) {
        Map<String,Integer> map = new HashMap<>();
        map.put("6",6);
        map.put("66",66);
        map.put("666",666);
        map.put("6666",6666);
        map.put("66666",66666);
        System.out.println(map);
        System.out.println(map.size());
        System.out.println(map.isEmpty());
        System.out.println(map.get("666"));
        map.remove("66666");
        System.out.println(map.containsKey("66666"));
        System.out.println(map.containsValue("66666"));
        Set<String> set = map.keySet();
        System.out.println(set);
        Collection<Integer> collection = map.values();
        System.out.println(collection);
        //map.clear();

        System.out.println("---------------------------------------");

        //Map集合的遍历方式
        //键找值---先获取Map集合全部的键，再通过遍历键来找值
        /*
            public Set<K> keySet() 获取所有键的集合
            public V get(Object key) 根据键获取其对应的值0.
         */
        Set<String> keys = map.keySet();
        for(String key: keys){
            System.out.println(key+"====>"+map.get(key));
        }

        //键值对
        /*
            Set<Map.Entry<K,V>> entrySet() 获取所有键值对的集合
         */
        System.out.println("================");
        Set<Map.Entry<String,Integer>> entries = map.entrySet();
        for(Map.Entry<String,Integer> entry: entries){
            String key = entry.getKey();
            int value = entry.getValue();
            System.out.println(key+"===>"+value );
        }

        //Lambda表达式
        /*
            default void forEach(BiConsumer<? super K, ? super V> action)
            结合lambda遍历Map集合
         */
        System.out.println("======================");
        map.forEach((k,v)-> System.out.println(k+"===>"+v));

    }
    /*
        HashMap集合的底层原理：
            HashMap跟HashSet的底层原理是一模一样的，都是基于哈希表实现的
            实际上：原来的Set系列集合的底层就是基于Map实现的，只是Set集合中的元素只要键数据，不要值数据
     */
    /*
        LinkedHashMap集合的底层原理：
            哈希表＋双链表，也是跟LinkedHashSet类似
     */
    /*
        TreeMap集合的底层原理：
            只能对键排序
            原理也和TreeSet一样
            也支持两种方式来指定排序规则
                让类实现Comparable接口，重写比较规则
                TreeMap集合有一个有参构造器，支持创建Comparator比较器对象，以便用来指定比较规则
     */
}
