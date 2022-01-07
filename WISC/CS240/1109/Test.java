import java.util.ArrayList;

public class Test {
	public static ArrayList<String> used = new ArrayList<String>();
	public static ArrayList<String> used2 = new ArrayList<String>();
	public static int count = 0;
	public static String[] one = {"a", "b", "c", "d"};
	public static String[] two = {"AA", "BB", "CC"};

	public static void solve(int maxLength, int currentLength, String status) {
		if (currentLength > maxLength) return;
		if (currentLength == maxLength) {
			if (!used.contains(status)) {
				count++;
				used.add(status);
			}
			return;
		}
		for (String s : one) {
			solve(maxLength, currentLength + 1, status + s);
		}
		for (String s : two) {
			solve(maxLength, currentLength + 2, status + s);
		}
	}

	public static void main(String[] args) {
		used = new ArrayList<String>();
		used2 = new ArrayList<String>();
		count = 0;
		solve(4, 0, "");
		for (String s : used) {
			System.out.println(s);
		}
	}
}
