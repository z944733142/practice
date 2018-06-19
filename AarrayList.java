package app.xupt;

public class AarrayList {
	public static void main(String[] args) {
		AAarrayList aobj = new AAarrayList();
		aobj.add("abc");
		aobj.add(new Human(20, "уек╤"));
		aobj.add("def");
		System.out.println(aobj.get(2));
		System.out.println(((Human) aobj.get(1)).getName());
		System.out.println(aobj.get(0));
	}
}

class Human {
	private String name;
	private int age;
	
	public Human (int age, String name){
		this.age = age;
		this.name = name;
		
	}
	
	public String getName() {
		return this.name;
	}
}
class AAarrayList {
	private Object[] obj;
	
	private int size;
	
	public AAarrayList (int size) {
		obj = new Object[size];
	}
	
	public AAarrayList ()
	{
		this(16);
	}
	
	public void add (Object obj) {
		this.obj[size] = obj;
		size++;
	}
	
	public Object get (int numb) {
		return this.obj[numb];
	}
	
	
}