package JDK8_New_Features;

import java.util.*;
import java.util.stream.Collectors;

public class Stream_ {
    /*
        Stream流：可以用于操作集合或数组的数据

        优势：Stream流大量结合了Lambda的语法风格来编程，
        提供了一种更加强大，更加简单的方式操作集合或数组中的数据，代码更简洁，可读性更好。
     */
    /*
        1.获取Stream流
            获取集合的Stream流
                Collection提供的如下方法
                default Stream<E> stream() 获取当前集合对象的Stream流

            获取数组的Stream流
                Arrays类提供的如下方法
                public static <T> Stream<T> stream(T[] array) 获取当前数组的Stream流

                Stream类提供的如下方法
                public static<T> Stream<T> of(T... values) 获取当前接收数据的Stream流
     */
    /*
        2.Stream流常见的中间方法
            Stream<T> filter(Predicate<? super T> predicate) 用于对流中的数据进行过滤
            Stream<T> sorted()  对元素进行升序排序
            Stream<T> sorted(Comparator<? super T> comparator)  按照指定规则排序
            Stream<T> limit(long maxSize)   获取前几个元素
            Stream<T> skip(long n)  跳过前几个元素
            Stream<T> distinct()    去除流中重复的元素
            <R> Stream<R> map(Function<? super T,? extends R> mapper) 对元素进行加工，并返回对应的新流
            static <T> Stream<T> concat(Stream a,Stream b)  合并a和b两个流为一个流
     */
    /*
        3.Stream流常见的终结方法
            void forEach(Consumer action)   对此流运算后的元素执行遍历
            long count()    统计此流运算后的元素个数
            Optional<T> max(Comparator<? super T> comparator)   获取此流运算后最大值元素
            Optional<T> min(Comparator<? super T> comparator)   获取此流运算后最小值元素

            收集Stream流：把Stream流操作后的结果转回到集合挥着数组中去返回
            R collect(Collector collector)  把流处理后的结果收集到一个指定的集合中去
            Object[] toArray()  把流处理后的结果收集到一个数组中
     */
    public static void main(String[] args) {
        List<Double> scores = new ArrayList<>();
        Collections.addAll(scores,88.5,100.0,60.0,99.0,9.5,99.6,25.0);
        //需求一：找出成绩大于等于60分的数据，并升序后，再输出
        scores.stream().filter(s->s>=60).sorted().forEach(s-> System.out.println(s));

        List<Student> students = new ArrayList<>();
        Student s1 = new Student("蜘蛛精",26,172.5);
        Student s2 = new Student("蜘蛛精",26,172.5);
        Student s3 = new Student("紫霞",23,167.6);
        Student s4 = new Student("白晶晶",25,169.0);
        Student s5 = new Student("牛魔王",35,183.3);
        Student s6 = new Student("牛夫人",34,168.5);
        Collections.addAll(students,s1,s2,s3,s4,s5,s6);
        //需求二：找出年龄大于等于23，且年龄小于等于30岁的学生，并按照年龄降序输出
        students.stream().filter(s->s.getAge()>=23&&s.getAge()<=30)
                .sorted(((o1, o2) -> o2.getAge()-o1.getAge()))
                .forEach(s-> System.out.println(s));
        //需求三：取出身高最高的前三名学生，并输出
        students.stream()
                .sorted((o1, o2) -> Double.compare(o2.getHeight(),o1.getHeight()))
                .limit(3)
                .forEach(s-> System.out.println(s));
        //需求四：取出身高倒数的两名学生，并输出
        students.stream()
                .sorted()
                .limit(2)
                .forEach(s-> System.out.println(s));
        //需求五：找出身高超过168的学生叫什么名字，要求去除重复名字，并输出
//        students.stream()
//                .filter(s->s.getHeight()>168);students.stream().max((o1, o2) -> Double.compare(o1.getHeight(),o2.getHeight())).get()
//                .map(s->s.getName())
//                .distinct()
//                .forEach(s-> System.out.println(s));
        System.out.println("------------------------------------------------------");
        //需求1：计算身高超过168的学生有几人
        System.out.println(students.stream().filter(s->s.getHeight()>168).count());
        //需求2：找出身高最高的学生对象，并输出
        System.out.println(students.stream().max((o1, o2) -> Double.compare(o1.getHeight(),o2.getHeight())).get());
        //需求3：找出身高最矮的学生，并输出
        System.out.println(students.stream().min((o1, o2) -> Double.compare(o1.getHeight(), o2.getHeight())).get());
        //需求4：找出身高超过170的学生对象，并放到一个新集合中去返回
        List<Student> list = students.stream().filter(a->a.getHeight()>170).collect(Collectors.toList());
        System.out.println(list);
        //需求5：找出身高超过170的学生对象，并把学生对象的名字和身高，存入到一个map集合返回
        Map<String,Double> map = students.stream().filter(c->c.getHeight()>170).distinct().collect(Collectors.toMap(a->a.getName(),a-> a.getHeight()));
        System.out.println(map);

        Student[] arr = students.stream().filter(a->a.getHeight()>170).toArray(len->new Student[len]);
    }
}