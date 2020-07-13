package jump2java.HelloWorld;

/*
  ... iss Crew
  ... Made By Mukho
  ... 2020-07-13 MON
  ... JAVA Practice
 */
import java.io.InputStream;
import java.util.Scanner;

public class HelloWorld {

	public static void main(String[] args) {
		InputStream in = System.in;
		
		int text;
		text = in.read();
		
		System.out.println(text);
	}

	// �ʱ� ����, ���� �� ���� �͵��� C�� �����ϴ�.
	/* String
	 *  String text = "wow"; == String text = new String("wow");
	 	text.equals(str) <- text�� str�� ������ ��
	 	text.indexOf("o") <- o�� ���۵Ǵ� ��ġ�� ��ȯ
	 	text.replaceAll("w", "i") -> wow���� w�� i�� ��ȯ ioi
	 	text.substring(1,2) -> index 1���� 2���� ���
	 	toUpperCase / toLowerCase
	 */
	/* StringBuffer
	 * StringBuffer temp = new StringBuffer(); // ���ڿ� �߰��� ������� �۾��� ���� ��� ��Ʈ������ ��뿡 ����
	 * temp.append("??");
	 * System.out.println(toString(temp)); -> ??
	 * temp.insert(1,"fdzz") ?fdzz?
	 * substring
	 */
	 /* Array
	  * String[] weeks = new String[7];
	  * array's length => weeks.length
	  * 
	  */
	/* List (Array, Linked, ...)
	 * ArrayList speed = new ArrayList(); // ArrayList<String> speed
	 * speed.add("100");
	 * speed.add("135");
	 * speed.add(0, "87");
	 * spped.get(1) -> 100
	 * speed.size() -> 3
	 * speed.contains("70") -> false
	 * speed.remove(0) -> 87 ����
	 * speed.remove("87") -> 87 ����
	 */
	/*
	 *  Generics == C++������ Template
	 *  Map == Python������ Dictionary
	 *  (������ �� �� �ϳ�) HashMap<String, String> map = new HashMap<String, String>();
	 *  map.put("vip","�� ȣ");
	 *  map.put("����","ITX û��");
	 *  map.get("����") -> "ITX û��"
	 *  map.containsKey("vvip") -> false
	 *  map.remove("vip")
	 *  map.size() -> 2
	 *  
	 *  LinkedListMap -> �Էµ� ������� �����Ͱ� ��µ�
	 *  TreeMap -> �Էµ� Key�� ���� ������ �����Ͱ� ��µ�
	 */
	
	/* 
	 * ���̽㿡���� for item in list_ �� ���� for each
	 * 
	 * for (String item: items) { System.out.println(item); }
	 */
	/* Object-Oriented Programming
	 * Class-Object-Method
	 * Call-by-value / Call-by-reference
	 * Interface : setName, getName, show, setName ���� ���� �޼ҵ� �����ε� ���� ���ϰ� ���� �� �ִ�?
	 * public class Lion extend Animal implements Predator{}
	 * public void feed(Predator predator){} -> ���ĵ������� ���� �ش�
	 * 
	 * public interface Predator{
	 * 		public String getFood();
	 * }
	 * public class ZooKeeper {    
       public void feed(Predator predator) {
       System.out.println("feed "+predator.getFood());
    }
}
	 * 
	 * �߻� Ŭ���� : �������̽��� ���ҵ� �ϸ鼭 ����ü�� ������ �ִ� Ŭ����(abstract class)
	 */
	/* Scanner : next(�ܾ�), nextLine(����), nextInt(����)
	 * ���� ����� : import java.io.FileOutputStream; java.io.IOException;
	 * ...
	 * public static void main(String[] args) thorows IOException{
	 * 		FileOutputStream output = new FileOutputStream("c:/out.txt");
	 * 		output.close();
	 * }
	 * public class FileWrite {
		   public static void main(String[] args) throws IOException {
		        FileOutputStream output = new FileOutputStream("c:/out.txt");
		        for(int i=1; i<11; i++) {
		            String data = i+" ��° ���Դϴ�.\r\n";
		            output.write(data.getBytes());
		        }
		        output.close();
		   }
		   
		}
		public class FileWrite {
		    public static void main(String[] args) throws IOException {
		        FileWriter fw = new FileWriter("c:/out.txt");
		        for(int i=1; i<11; i++) {
		            String data = i+" ��° ���Դϴ�.\r\n";
		            fw.write(data);
		        }
		        fw.close();
		    }
		}
		
		
	import java.io.IOException;
	import java.io.PrintWriter;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        PrintWriter pw = new PrintWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" ��° ���Դϴ�.";
	            pw.println(data);
	        }
	        pw.close();
	    }
	}
	
	import java.io.FileWriter;
	import java.io.IOException;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        FileWriter fw = new FileWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" ��° ���Դϴ�.\r\n";
	            fw.write(data);
	        }
	        fw.close();
	
	        FileWriter fw2 = new FileWriter("c:/out.txt", true);
	        for(int i=11; i<21; i++) {
	            String data = i+" ��° ���Դϴ�.\r\n";
	            fw2.write(data);
	        }
	        fw2.close();
	    }
	}
	
	import java.io.FileWriter;
	import java.io.IOException;
	import java.io.PrintWriter;
	
	public class FileWrite {
	    public static void main(String[] args) throws IOException {
	        PrintWriter pw = new PrintWriter("c:/out.txt");
	        for(int i=1; i<11; i++) {
	            String data = i+" ��° ���Դϴ�.";
	            pw.println(data);
	        }
	        pw.close();
	
	
	        PrintWriter pw2 = new PrintWriter(new FileWriter("c:/out.txt", true));
	        for(int i=11; i<21; i++) {
	            String data = i+" ��° ���Դϴ�.";
	            pw2.println(data);
	        }
	        pw2.close();
	    }
	}
	
	import java.io.FileInputStream;
	import java.io.IOException;
	
	public class FileRead {
	    public static void main(String[] args) throws IOException {
	        byte[] b = new byte[1024];
	        FileInputStream input = new FileInputStream("c:/out.txt");
	        input.read(b);
	        System.out.println(new String(b));
	        input.close();
	    }
	}
	
	import java.io.BufferedReader;
	import java.io.FileReader;
	import java.io.IOException;
	
	public class FileRead {
	    public static void main(String[] args) throws IOException {
	        BufferedReader br = new BufferedReader(new FileReader("c:/out.txt"));
	        while(true) {
	            String line = br.readLine();
	            if (line==null) break;
	            System.out.println(line);
	        }
	        br.close();
	    }
	}
	 */
}
