import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.SortedSet;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Solution {
	
	public static void main(String[] args) throws IOException {
		MyScanner sc = new MyScanner();
		PrintWriter out = new PrintWriter(System.out);
		int numberOfCases = sc.nextInt();
		for (int caze = 1; caze <= numberOfCases; caze++) {
			sc.next();
			int L = sc.nextInt();
			BigInteger[] vals = new BigInteger[L];
			int firsDiff = -1;
			for (int i = 0; i < vals.length; i++) {
				vals[i] = new BigInteger(sc.next());
				if (firsDiff == -1 && i > 0 && !vals[i].equals(vals[i-1])) firsDiff = i-1;
			}
			List<BigInteger> message = new ArrayList<>();
			BigInteger gcd = vals[firsDiff].gcd(vals[firsDiff+1]);
			message.add(vals[firsDiff].divide(gcd));
			for (int i = firsDiff - 1; i >= 0; i--) {
				message.add(vals[i].divide(message.get(message.size() - 1)));
			}
			Collections.reverse(message);
			for (int i = firsDiff; i < vals.length; i++) {
				message.add(vals[i].divide(message.get(message.size() - 1)));
			}
			SortedSet<BigInteger> letters = new TreeSet<>(message);
			Map<BigInteger, Character> encoding = new HashMap<>();
			char id = 'A';
			for (BigInteger letter : letters) {
				encoding.put(letter, id++);
			}
			char[] ans = new char[message.size()];
			for (int i = 0; i < message.size(); i++) {
				ans[i] = encoding.get(message.get(i));
			}
			
			out.println("Case #" + caze + ": " + new String(ans));
		}
		
		out.flush();
	}
	
	static class MyScanner {
		private BufferedReader br;
		private StringTokenizer tokenizer;
		
		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}
		
		public String next() {
			while (tokenizer == null || !tokenizer.hasMoreTokens()) {
				try {
					tokenizer = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					throw new RuntimeException(e);
				}
			}
			return tokenizer.nextToken();
		}
		
		public int nextInt() {
			return Integer.parseInt(next());
		}
		
		public long nextLong() {
			return Long.parseLong(next());
		}
	}
}
